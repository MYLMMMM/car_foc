#pragma once

#include <stdint.h>
#include <cstddef>
#include "algorithm/ADC2Voltage.hpp"
#include "algorithm/Voltage2PWM_PH.hpp"
#include "algorithm/P2C.hpp"
#include "algorithm/SlopeLimit.hpp"
#include "algorithm/UpperLimit.hpp"
#include "algorithm/LowerLimit.hpp"

using adc_reg = volatile int32_t;
using pwm_reg = volatile uint32_t;

/**
 * @brief 直流电机配置结构体(纯值传递, 不含引用)
 * @details 电压模式控制，不含电流环。
 */
struct dc_motor_datastructure_config
{
    /* interface with hardware */
    adc_reg* adc_vbus;

    /* config value */
    float adc_vref;
    int16_t adc_full_scale;
    float vbus_divider_ratio;
    float voltage_limit;        // 电压指令限幅绝对值(V), <=0 不限幅
    float voltage_slope;        // 电压指令斜率限制(V per step, <=0 不限斜率)

    float control_period_s;
    uint32_t pwm_period;
};

/**
 * @brief 直流电机运行数据结构体(含引用, 不可拷贝/移动)
 * @details 电压模式: 外部设置 voltage_cmd → 限幅 → 占空比+方向 → PWM CCR
 */
struct dc_motor_datastructure
{
    /* interface with hardware */
    adc_reg& adc_vbus;      // ADC 母线电压寄存器原始值
    pwm_reg ccr_raw = 0;    // PWM 比较寄存器原始计算值（P2C 输出）
    pwm_reg ccr_p = 0;      // 正向 PWM 比较寄存器值（8701p: IN1 通道）
    pwm_reg ccr_n = 0;      // 反向 PWM 比较寄存器值（8701p: IN2 通道）

    /* config value */
    int32_t adc_full_scale = 0;        // ADC 满量程计数
    float adc_vref = 0.0f;             // ADC 参考电压(V)
    float vbus_divider_ratio = 0.0f;   // 母线分压还原比例
    float voltage_limit = 0.0f;        // 电压指令限幅绝对值(V), <=0 不限幅
    float voltage_limit_neg = 0.0f;    // 负向电压限幅(V), 由 trg() 自动维护为 -voltage_limit
    float voltage_slope = 0.0f;        // 电压指令斜率限制(V per step, <=0 不限斜率)

    float control_period_s = 0.0f;     // 控制周期(s)
    uint32_t pwm_period = 0;           // PWM 周期 ARR

    /* running value */
    float v_bus = 0.0f;          // 母线电压(V)
    float voltage_cmd = 0.0f;    // 电压指令(V), 外部可写, 可正可负
    float voltage_cmd_limited = 0.0f;  // 限幅+限斜率后的电压指令(V)
    float duty = 0.0f;           // PWM 占空比 [0, 1]
    bool direction = true;       // 方向, true=正向, false=反向

    explicit dc_motor_datastructure(const dc_motor_datastructure_config& cfg)
        : adc_vbus(*cfg.adc_vbus)
        , adc_full_scale(cfg.adc_full_scale)
        , adc_vref(cfg.adc_vref)
        , vbus_divider_ratio(cfg.vbus_divider_ratio)
        , voltage_limit(cfg.voltage_limit)
        , voltage_slope(cfg.voltage_slope)
        , control_period_s(cfg.control_period_s)
        , pwm_period(cfg.pwm_period)
    {
    }
};

/**
 * @brief 直流电机控制类（电压模式）
 * @details 组合 ADC2Voltage + Voltage2PWM_PH + P2C 三个子模块，
 *          trg() 按 ADC→母线电压→电压限幅→PWM+PH→CCR 的顺序执行一次控制计算。
 */
class dc_motor {
public:
    dc_motor_datastructure& motor;

private:
    ADC2Voltage<float, adc_reg> adc2voltage_vbus;
    Voltage2PWM_PH<float> v2pwm_ph;
    P2C<float, pwm_reg> p2c;
    UpperLimit<float> upper_limit_voltage;
    LowerLimit<float> lower_limit_voltage;
    SlopeLimit<float> slope_limit_voltage;

public:
    /**
     * @brief 构造直流电机控制器
     * @param motor 外部电机数据对象引用
     */
    explicit dc_motor(dc_motor_datastructure& motor)
        : motor(motor),
          adc2voltage_vbus(motor.adc_vbus, motor.adc_vref, motor.adc_full_scale,
                           motor.vbus_divider_ratio, motor.v_bus),
          v2pwm_ph(motor.voltage_cmd_limited, motor.v_bus, motor.duty, motor.direction),
          p2c(motor.duty, motor.pwm_period, motor.ccr_raw),
          upper_limit_voltage(motor.voltage_cmd, motor.voltage_limit),
          lower_limit_voltage(motor.voltage_cmd, motor.voltage_limit_neg),
          slope_limit_voltage(motor.voltage_cmd, motor.voltage_slope, motor.voltage_cmd_limited)
    {
    }

    dc_motor(const dc_motor&) = delete;
    dc_motor& operator=(const dc_motor&) = delete;
    dc_motor(dc_motor&&) = delete;
    dc_motor& operator=(dc_motor&&) = delete;
    void* operator new(size_t) = delete;
    void operator delete(void*) = delete;

    dc_motor_datastructure& data() { return motor; }
    const dc_motor_datastructure& data() const { return motor; }

    /**
     * @brief 更新母线电压采样比例系数
     * @details 修改参考电压/满量程/分压比后调用
     */
    void update_scale() {
        adc2voltage_vbus.update_scale();
    }

    /**
     * @brief 触发一次直流电机控制计算
     * @details 顺序: ADC→母线电压 → 电压限幅 → V2PWM_PH → P2C
     */
    void trg() {
        adc2voltage_vbus.trg();

        // 电压指令限幅 + 斜率限制（模仿 FOC motor A/B 的 speed_target 处理）
        motor.voltage_limit_neg = -motor.voltage_limit;
        upper_limit_voltage.trg();
        lower_limit_voltage.trg();
        slope_limit_voltage.trg();

        v2pwm_ph.trg();
        p2c.trg();

        // 8701p 双 PWM 模式：根据方向只给一路写占空比，另一路写 0
        if (motor.direction)
        {
            motor.ccr_p = motor.ccr_raw;
            motor.ccr_n = 0;
        }
        else
        {
            motor.ccr_p = 0;
            motor.ccr_n = motor.ccr_raw;
        }
    }
};
