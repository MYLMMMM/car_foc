# car_foc FOC 算法优化建议报告

<!-- 生成日期: 2026-05-15 -->
<!-- 对比基准: Infineon motor-ctrl-lib v3.2.0 (MOTOR_DEMO) -->
<!-- 目标: 有感 FOC (编码器反馈) 条件下的算法改进 -->

---

## 一、概述

本报告对比 `car_foc` 自定义 FOC 实现与 Infineon 官方 `motor-ctrl-lib v3.2.0`（`MOTOR_DEMO` 工程），列出在有感 FOC 条件下 `car_foc` 需要修复的错误和可改进的设计点。每个条目包含：问题描述、参考实现、建议修改方案。

---

## 二、必须修复的错误 (P0-P1)

### P0-1: 速度环未启用 — `user/foc/foc_soft.hpp`

**问题**: `foc::trg()` 中速度环 PID 调用被整段注释，只有电流环运行，缺少级联速度控制。

**当前代码** (约第 230-240 行):
```cpp
void trg() {
    encoder2mech.trg();
    speed.trg();

    // const uint32_t speed_div = (motor.speed_loop_div == 0u) ? 1u : motor.speed_loop_div;
    // motor.speed_loop_count++;
    // if (motor.speed_loop_count >= speed_div) {
    //     motor.speed_loop_count = 0u;
    //     pid_speed.trg();
    // }

    mech2elec.trg();
    // ... 电流环后续代码
}
```

**修复方案**:
1. 取消注释速度环调用块
2. 速度环输出 `motor.i_q_target` 将自动通过引用传入 `pid_q` 作为 q 轴电流目标
3. 确保 `motor.speed_target` 在外部正确设置为目标机械角速度 (rad/s)
4. `motor.speed_loop_div` 默认为 1，即每个控制周期都执行速度环；如需降采样可设置更大值

**参考**: `MOTOR_DEMO` `StateMachine.c` `SpeedCLISR1()` → `SPEED_CTRL_RunISR1()`

---

### P0-2: PID 控制器缺少反计算 Anti-Windup — `user/foc/algorithm/PID.hpp`

**问题**: 当前 PID 只对积分项做饱和限幅，当输出超出合理范围时积分会持续累加（windup），导致超调大、响应慢。

**当前代码** (约第 70-85 行):
```cpp
void trg() {
    data_type error = target - input;
    integral += error;
    if (integral_limit != static_cast<data_type>(0)) {
        data_type limit = integral_limit;
        if (integral > limit) {
            integral = limit;
        } else {
            const data_type neg_limit = -limit;
            if (integral < neg_limit) {
                integral = neg_limit;
            }
        }
    }
    output = (p * error) + (i * integral) + (d * (error - last_error));
    last_error = error;
}
```

**修复方案**: 参考 `MOTOR_DEMO` `General.c` `PI_Run()` 的反计算逻辑。在积分累加后、计算输出前，先计算原始输出，根据输出是否超出限幅范围反算积分值：

```cpp
void trg() {
    data_type error = target - input;
    data_type prop_d_term = p * error + d * (error - last_error);
    integral += i * error;  // 注意: ki 已经在 integral 累加中体现
                            // 如果 i 是离散积分系数 (= ki_continuous * Ts)，则 integral += i * error
    data_type output_raw = integral + prop_d_term;
    
    if (integral_limit > static_cast<data_type>(0)) {
        if (output_raw > integral_limit) {
            output = integral_limit;
            integral = integral_limit - prop_d_term;  // 反计算
        } else if (output_raw < -integral_limit) {
            output = -integral_limit;
            integral = -integral_limit - prop_d_term;  // 反计算
        } else {
            output = output_raw;
        }
    } else {
        output = output_raw;
    }
    last_error = error;
}
```

**注意**: 需要区分 `i` 的含义。当前 `i` 在 `foc_motor_datastructure_config` 中定义为 `pid_q_ki` 等，应确认是连续域 Ki 还是离散域 Ki*Ts。`MOTOR_DEMO` 在 `PI_UpdateParams` 中传入的是 `ki * Ts`（离散积分系数），在 `PI_Run` 中做 `integ += ki * error`。

如果当前 `pid_q_ki` 是连续域 Ki，则积分累加应改为 `integral += i * error * control_period_s`。需在实际调参时确认。

---

### P1-1: SVPWM 过调制硬限幅 — `user/foc/algorithm/SVPWM.hpp`

**问题**: 当电压矢量超出六边形边界时，零序注入法产生的占空比会超出 [0,1]，依赖 `P2C` 硬限幅，导致输出电压矢量畸变。

**当前代码** (约第 70-90 行):
```cpp
void trg() {
    // ... 零序注入计算
    t_a = (va + v_offset) * inv_vbus + HALF;
    t_b = (vb + v_offset) * inv_vbus + HALF;
    t_c = (vc + v_offset) * inv_vbus + HALF;
    // 没有过调制处理 — 超出 [0,1] 靠 P2C 硬 clip
}
```

**修复方案**: 在映射到占空比之前，检测是否过调制并等比缩放：

```cpp
void trg() {
    // ... 计算 va, vb, vc, v_offset
    
    data_type ta_raw = (va + v_offset) * inv_vbus + HALF;
    data_type tb_raw = (vb + v_offset) * inv_vbus + HALF;
    data_type tc_raw = (vc + v_offset) * inv_vbus + HALF;
    
    // 过调制模式 I: 等比缩放使占空比回到 [0,1]
    data_type t_max = ta_raw;
    if (tb_raw > t_max) t_max = tb_raw;
    if (tc_raw > t_max) t_max = tc_raw;
    
    data_type t_min = ta_raw;
    if (tb_raw < t_min) t_min = tb_raw;
    if (tc_raw < t_min) t_min = tc_raw;
    
    data_type range = t_max - t_min;
    if (range > ONE) {
        data_type scale = ONE / range;
        data_type mid = (t_max + t_min) * HALF;
        t_a = (ta_raw - mid) * scale + HALF;
        t_b = (tb_raw - mid) * scale + HALF;
        t_c = (tc_raw - mid) * scale + HALF;
    } else if (t_max > ONE) {
        data_type excess = t_max - ONE;
        t_a = ta_raw - excess;
        t_b = tb_raw - excess;
        t_c = tc_raw - excess;
    } else if (t_min < static_cast<data_type>(0)) {
        data_type excess = -t_min;
        t_a = ta_raw + excess;
        t_b = tb_raw + excess;
        t_c = tc_raw + excess;
    } else {
        t_a = ta_raw;
        t_b = tb_raw;
        t_c = tc_raw;
    }
}
```

**参考**: `MOTOR_DEMO` `VoltMod.c` `SVMRunISR0()` — 当 `total_duty > 1.0` 时等比缩放 `duty_first` 和 `duty_second`。

---

## 三、强烈建议改进 (P2)

### P2-1: 添加 dq 轴交叉解耦前馈 — `user/foc/foc_soft.hpp`

**问题**: dq 轴存在交叉耦合（$v_d$ 受 $i_q$ 影响，$v_q$ 受 $i_d$ 和永磁磁链影响），高速时耦合加剧，无前馈补偿时电流环性能下降。

**修复方案**: 在 `foc::trg()` 的电流环 PID 之前插入解耦计算：

```cpp
void trg() {
    // ... encoder, speed, mech2elec, adc, clark, park ...
    
    // === 新增: dq 交叉解耦前馈 ===
    // 需要在 foc_motor_datastructure 和 foc_motor_datastructure_config 中添加:
    //   float Ld;  // d 轴电感 (H)
    //   float Lq;  // q 轴电感 (H)
    //   float flux_linkage; // 永磁磁链 (Wb)
    
    float v_d_ff = -motor.Lq * motor.i_q * motor.speed_mech * motor.pole_pairs;
    float v_q_ff = (motor.Ld * motor.i_d + motor.flux_linkage) * motor.speed_mech * motor.pole_pairs;
    
    // 临时修改 i_d_target / i_q_target 对应的前馈通过 pid 的 set_ff 方法传入
    // 或者在 inverse_park 之前将 v_d/v_q 加上前馈项
    
    pid_d.trg();  // 需要改造支持 feed-forward
    pid_q.trg();
    
    // v_d = pid_d.output + v_d_ff
    // v_q = pid_q.output + v_q_ff
    // ... inverse park, svpwm ...
}
```

**需要的额外改动**:
1. `foc_motor_datastructure` 和 `foc_motor_datastructure_config` 添加 `Ld`, `Lq`, `flux_linkage` 字段
2. `PID` 类添加 `ff` 成员和前馈支持（或直接在外部加法实现）
3. 电频率 = `motor.speed_mech * motor.pole_pairs`（机械角速度 × 极对数）

**参考**: `MOTOR_DEMO` `CurrentCtrl.c` `CURRENT_CTRL_RunISR0()`:
```c
ctrl_ptr->curr.ff.q = vars_ptr->la_qd_r_est.d * vars_ptr->w_final.elec * ff_coef;
ctrl_ptr->curr.ff.d = -vars_ptr->la_qd_r_est.q * vars_ptr->w_final.elec * ff_coef;
```

---

### P2-2: 电流环使用纯 PI（移除微分项）

**问题**: `PID.hpp` 包含微分项，但电机电流环和速度环只用 PI 控制。微分项会放大采样噪声，尤其在电流环中。

**当前配置**: `foc_motor_datastructure_config` 中有 `pid_d_kd`, `pid_q_kd`, `pid_speed_kd` 三个微分系数。

**修复方案**:
1. 将电流环 `pid_d_kd` 和 `pid_q_kd` 默认设为 0，始终使用纯 PI
2. 速度环 `pid_speed_kd` 也建议设为 0
3. （可选）长期可简化 PID 类为 PI 类，移除微分相关代码，减小代码体积

**参考**: `MOTOR_DEMO` 的 `PI_t` 结构体只有 `kp, ki`，没有 `kd`。

---

## 四、建议优化 (P3)

### P3-1: 卡尔曼滤波器 P 矩阵对称化 — `user/foc/algorithm/KalmanThetaSpeed.hpp`

**问题**: P 矩阵更新公式中 $P_{01}$ 和 $P_{10}$ 分别用不同公式计算，长期浮点累积误差可能导致失去对称性。

**当前代码** (约第 160-165 行):
```cpp
p00_ = (static_cast<data_type>(1) - k0) * p00_pred;
p01_ = (static_cast<data_type>(1) - k0) * p01_pred;
p10_ = p10_pred - k1 * p00_pred;
p11_ = p11_pred - k1 * p01_pred;
```

**修复方案**: 在更新后强制对称化，或使用 Joseph 形式：

```cpp
p00_ = (static_cast<data_type>(1) - k0) * p00_pred;
p01_ = (static_cast<data_type>(1) - k0) * p01_pred;
p10_ = p10_pred - k1 * p00_pred;
p11_ = p11_pred - k1 * p01_pred;

// 强制对称化 (每 N 步或每步执行)
p01_ = (p01_ + p10_) * static_cast<data_type>(0.5);
p10_ = p01_;
```

---

### P3-2: 编码器角度计算优化 — `user/foc/algorithm/Encoder2Mech.hpp`

**问题**: 使用 `encoder_raw % encoder_cpr`，当 CPR 不是 2 的幂时，整数取模在 Cortex-M 上较慢。

**当前代码**:
```cpp
data_typei enc_norm = encoder_raw % encoder_cpr;
```

**修复方案**（如果 CPR 通常是 2 的幂如 4096/8192）:
```cpp
data_typei enc_norm;
// 编译时常数优化
if constexpr (/* 如果 encoder_cpr 是 2 的幂 */) {
    enc_norm = encoder_raw & (encoder_cpr - 1);
} else {
    enc_norm = encoder_raw % encoder_cpr;
}
```

或者：保持编码器计数为自由累加值，用乘法缩放替代取模（如 MOTOR_DEMO 的做法）。

---

### P3-3: SVPWM 中 v_bus 除法优化 — `user/foc/algorithm/SVPWM.hpp`

**问题**: 每周期执行 `inv_vbus = ONE / v_bus` 和三次乘加。可预存 `inv_vbus` 减少除法次数。当前实现已经只除一次，可接受。

**建议**: 在 `adc2voltage_vbus.trg()` 之后存储 `inv_vbus` 到 `motor` 结构体中，供 SVPWM 直接使用，避免在 SVPWM 中重复计算倒数。

---

## 五、缺少但与基本功能不直接相关的功能

以下功能在 `MOTOR_DEMO` 中存在，但对基础有感 FOC 运行非必须，可按需后续添加：

| 功能 | 文件 | 优先级 | 说明 |
|------|------|--------|------|
| 弱磁控制 (Flux Weakening) | 需新建 | P4 | 高速运行需要，可后期添加 |
| 相位超前补偿 | 需新建 | P4 | 改善高速电流环相位滞后 |
| 速度环前馈 (惯性/摩擦/粘滞) | `foc_soft.hpp` | P4 | 改善速度环动态响应，可加在 `pid_speed` 前 |
| 5/7 段 SVM 切换 | `SVPWM.hpp` | P4 | 效率优化，高调制比时减少开关损耗 |
| 状态机 | 需新建 | P4 | 启动/停止/故障状态管理 |
| 故障保护 (过流/过压/过温) | 需新建 | P4 | 安全相关 |
| I²T 电流限幅 | 需新建 | P4 | 热保护 |
| ADC 偏置自动校准 | `ADC2Current.hpp` | P4 | 上电时自动计算零电流偏置 |

---

## 六、需要增加的数据结构字段

为支持上述 P0-P2 修复，需要在以下文件中添加字段：

### `user/foc/foc_soft.hpp` — `foc_motor_datastructure_config` 和 `foc_motor_datastructure`

```cpp
// 新增 (P2-1 解耦需要)
float Ld;              // d 轴电感 (H)
float Lq;              // q 轴电感 (H)
float flux_linkage;    // 永磁磁链 (Wb)

// 新增 (P3-3 优化)
float inv_vbus;        // 1/v_bus 缓存
```

---

## 七、实施顺序建议

1. **先修 P0-2 (Anti-Windup)** — 影响电流环稳定性，是最基础的修复
2. **再修 P0-1 (启用速度环)** — 需要先有稳定的电流环，再接入速度外环
3. **接着修 P1-1 (过调制)** — 高负载/高转速时需要
4. **再加 P2-1 (交叉解耦)** — 提升高速性能
5. **最后 P2-2、P3 各项** — 锦上添花

---

## 八、参考文件索引

| car_foc 文件 | 对应 MOTOR_DEMO 参考 |
|-------------|---------------------|
| `user/foc/foc_soft.hpp` | `OperationalCode/Controller.h`, `StateMachine.c` |
| `user/foc/algorithm/PID.hpp` | `OperationalCode/General.c` `PI_Run()` |
| `user/foc/algorithm/Clark.hpp` | `OperationalCode/General.c` `ClarkeTransform()` |
| `user/foc/algorithm/Park.hpp` | `OperationalCode/General.c` `ParkTransform()` |
| `user/foc/algorithm/InversePark.hpp` | `OperationalCode/General.c` `ParkTransformInv()` |
| `user/foc/algorithm/SVPWM.hpp` | `OperationalCode/VoltMod.c` `SVMRunISR0()` |
| `user/foc/algorithm/KalmanThetaSpeed.hpp` | `OperationalCode/IncEncoder.h`, `AdapTrackLoop.h` |
| `user/foc/algorithm/Encoder2Mech.hpp` | `OperationalCode/IncEncoder.h` |

MOTOR_DEMO 库路径: `/home/zhuizhai/Program/PSC3M5/mtb_shared/motor-ctrl-lib/release-v3.2.0/OperationalCode/`
