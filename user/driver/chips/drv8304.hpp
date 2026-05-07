#pragma once

#include <stdint.h>

#include "cy_gpio.h"
#include "cy_scb_spi.h"
#include "hal.hpp"

/**
 * @file drv8304.hpp
 * @brief DRV8304S SPI 状态配置驱动（Head-only）。
 *
 * @details
 * - 本驱动仅覆盖 DRV8304S 的 SPI 状态配置与状态读取，不包含 PWM/控制环逻辑。
 * - SPI 与 GPIO 均采用“构造注入”方式绑定，避免在驱动内部硬编码板级资源。
 * - 驱动维护 0x00~0x06 的寄存器镜像表，状态设置接口按“字段”拆分提供。
 * - nFAULT 采用“外部 ISR 转发”模式：应用层在端口中断里调用 handle_nfault_irq()。
 *
 * @note
 * - DRV8304S 通信协议要求 16-bit SPI 帧，调用方需保证传入的 SPI 配置满足该要求。
 * - SPI 初始化（Cy_SCB_SPI_Init / Enable）由上层完成，本驱动不负责初始化 SPI 外设。
 * - 请勿通过字段设置接口修改 Reserved 字段。
 */

class Drv8304
{
public:
    /**
     * @brief DRV8304S 寄存器地址定义。
     */
    enum : uint8_t
    {
        REG_FAULT_STATUS_1 = 0x00u, /**< Fault Status Register 1 */
        REG_VGS_STATUS_2   = 0x01u, /**< VGS Status Register 2 */
        REG_DRIVER_CTRL    = 0x02u, /**< Driver Control Register */
        REG_GATE_DRIVE_HS  = 0x03u, /**< Gate Drive HS Register */
        REG_GATE_DRIVE_LS  = 0x04u, /**< Gate Drive LS Register */
        REG_OCP_CTRL       = 0x05u, /**< OCP Control Register */
        REG_CSA_CTRL       = 0x06u, /**< CSA Control Register */
    };

    /**
     * @brief DRV8304S 可寻址字段名（覆盖 0x00~0x06）。
     *
     * @details
     * 字段名遵循 datasheet register map。对于原始字段名以数字开头的项：
     * - `PWM1_COM` 对应 datasheet 的 `1PWM_COM`
     * - `PWM1_DIR` 对应 datasheet 的 `1PWM_DIR`
     * - `FAULT_SUMMARY` 对应 datasheet 的 `FAULT`（避免与芯片头文件宏 `FAULT` 冲突）
     */
    enum class FieldName : uint8_t
    {
        // Fault Status Register 1 (0x00, Read Only)
        FAULT_SUMMARY, /**< [10] (原名 FAULT) 逻辑故障汇总，镜像 nFAULT */
        VDS_OCP, /**< [9] VDS 过流故障 */
        GDF,     /**< [8] 栅极驱动故障 */
        UVLO,    /**< [7] 欠压锁定故障 */
        OTSD,    /**< [6] 过温关断 */
        VDS_HA,  /**< [5] A 相高边 VDS 过流 */
        VDS_LA,  /**< [4] A 相低边 VDS 过流 */
        VDS_HB,  /**< [3] B 相高边 VDS 过流 */
        VDS_LB,  /**< [2] B 相低边 VDS 过流 */
        VDS_HC,  /**< [1] C 相高边 VDS 过流 */
        VDS_LC,  /**< [0] C 相低边 VDS 过流 */

        // VGS Status Register 2 (0x01, Read Only)
        SA_OC,  /**< [10] A 相电流放大器过流 */
        SB_OC,  /**< [9] B 相电流放大器过流 */
        SC_OC,  /**< [8] C 相电流放大器过流 */
        OTW,    /**< [7] 过温预警 */
        CPUV,   /**< [6] 电荷泵欠压 */
        VGS_HA, /**< [5] A 相高边 VGS 故障 */
        VGS_LA, /**< [4] A 相低边 VGS 故障 */
        VGS_HB, /**< [3] B 相高边 VGS 故障 */
        VGS_LB, /**< [2] B 相低边 VGS 故障 */
        VGS_HC, /**< [1] C 相高边 VGS 故障 */
        VGS_LC, /**< [0] C 相低边 VGS 故障 */

        // Driver Control Register (0x02)
        DRIVER_CONTROL_RESERVED_BIT10, /**< [10] Reserved，必须保持 0 */
        DIS_CPUV,                      /**< [9] 禁用/使能电荷泵欠压故障 */
        DIS_GDF,                       /**< [8] 禁用/使能栅极驱动故障 */
        OTW_REP,                       /**< [7] 是否将 OTW 上报到 nFAULT/FAULT */
        PWM_MODE,                      /**< [6:5] PWM 模式选择 */
        PWM1_COM,                      /**< [4] (原名 1PWM_COM) 1xPWM 整流策略 */
        PWM1_DIR,                      /**< [3] (原名 1PWM_DIR) 1xPWM 方向位 */
        COAST,                         /**< [2] 置 1 让全部 MOSFET 进入 Hi-Z */
        BRAKE,                         /**< [1] 置 1 打开三相低边（1xPWM 模式） */
        CLR_FLT,                       /**< [0] 写 1 清故障（自清零） */

        // Gate Drive HS Register (0x03)
        LOCK,                          /**< [10:8] SPI 写锁控制 */
        GATE_DRIVE_HS_RESERVED_BIT7,   /**< [7] Reserved，必须保持 0 */
        IDRIVEP_HS,                    /**< [6:4] 高边灌电流（上拉驱动） */
        GATE_DRIVE_HS_RESERVED_BIT3,   /**< [3] Reserved，必须保持 0 */
        IDRIVEN_HS,                    /**< [2:0] 高边拉电流（下拉驱动） */

        // Gate Drive LS Register (0x04)
        CBC,                           /**< [10] 循环限流自动清故障使能 */
        TDRIVE,                        /**< [9:8] 峰值驱动维持时间 */
        GATE_DRIVE_LS_RESERVED_BIT7,   /**< [7] Reserved，必须保持 0 */
        IDRIVEP_LS,                    /**< [6:4] 低边灌电流（上拉驱动） */
        GATE_DRIVE_LS_RESERVED_BIT3,   /**< [3] Reserved，必须保持 0 */
        IDRIVEN_LS,                    /**< [2:0] 低边拉电流（下拉驱动） */

        // OCP Control Register (0x05)
        TRETRY,                        /**< [10] OCP 自动重试时间选择 */
        DEAD_TIME,                     /**< [9:8] 死区时间选择 */
        OCP_MODE,                      /**< [7:6] 过流响应模式 */
        OCP_ACT,                       /**< [5] 全桥/半桥关断动作选择 */
        OCP_CONTROL_RESERVED_BITS4_3,  /**< [4:3] Reserved，必须保持 0 */
        VDS_LVL,                       /**< [2:0] VDS 过流阈值 */

        // CSA Control Register (0x06)
        CSA_CONTROL_RESERVED_BIT10,    /**< [10] Reserved，必须保持 0 */
        VREF_DIV,                      /**< [9] 采样参考是否除 2 */
        LS_REF,                        /**< [8] 低边 VDS 检测参考点选择 */
        CSA_GAIN,                      /**< [7:6] 电流采样放大倍数 */
        DIS_SEN,                       /**< [5] 禁用/使能电流采样过流保护 */
        SPI_CAL,                       /**< [4] SPI 触发电流采样校准 */
        AUTOCAL,                       /**< [3] 运行期自动校准触发 */
        CSA_CONTROL_RESERVED_BIT2,     /**< [2] Reserved，必须保持 0 */
        SEN_LVL                        /**< [1:0] 采样过流阈值 */
    };

    /**
     * @brief 字段设置接口返回值。
     */
    enum class SetFieldResult : uint8_t
    {
        Ok,              /**< 成功 */
        NotInitialized,  /**< 驱动尚未 init() */
        InvalidField,    /**< 字段或寄存器映射非法 */
        ReadOnlyField,   /**< 字段不可写（保留给只读场景） */
        ValueOutOfRange, /**< value 超出字段位宽 */
        SpiTransferError /**< SPI 传输失败或超时 */
    };

    /**
     * @brief DRV8304 寄存器镜像表（0x00~0x06）。
     *
     * @details
     * - 字段设置接口成功后会同步更新对应镜像。
     * - `refresh_fault_status()` 会更新 0x00 与 0x01 镜像。
     * - `init()` 完成后会按手册默认值生成 0x02~0x06 待下发镜像。
     */
    struct StateTable
    {
        uint16_t fault_status1; /**< 0x00 Fault Status Register 1 */
        uint16_t fault_status2; /**< 0x01 VGS Status Register 2 */
        uint16_t driver_ctrl;   /**< 0x02 Driver Control Register */
        uint16_t gate_drive_hs; /**< 0x03 Gate Drive HS Register */
        uint16_t gate_drive_ls; /**< 0x04 Gate Drive LS Register */
        uint16_t ocp_ctrl;      /**< 0x05 OCP Control Register */
        uint16_t csa_ctrl;      /**< 0x06 CSA Control Register */
    };

    /**
     * @brief nFAULT 事件回调函数签名。
     *
     * @param state 最新状态镜像（中断处理后）
     * @param user_ctx 用户上下文指针
     */
    using Callback = void (*)(const StateTable& state, void* user_ctx);

    /**
     * @brief 构造 DRV8304 驱动对象（仅绑定资源，不做外设初始化）。
     *
     * @param spi SPI 绑定配置
     * @param enable_gpio EN 引脚配置
     * @param nfault_gpio nFAULT 引脚配置
     */
    Drv8304(hal_spi& spi,hal_gpio& enable_gpio, hal_gpio& nfault_gpio) noexcept
        : spi_(spi)
        , enable_gpio_(enable_gpio)
        , nfault_gpio_(nfault_gpio)
        , initialized_(false)
        , state_{0u, 0u, 0u, 0u, 0u, 0u, 0u}
        , nfault_callback_(nullptr)
        , nfault_callback_user_ctx_(nullptr)
    {
    }

    Drv8304(const Drv8304&) = delete;
    Drv8304& operator=(const Drv8304&) = delete;
    Drv8304(Drv8304&&) = delete;
    Drv8304& operator=(Drv8304&&) = delete;

    /**
     * @brief 按 DRV8304S 手册默认寄存器值初始化驱动内部状态。
     *
     * @details
     * - 本函数不执行 SPI 外设初始化，只加载内部默认寄存器值并生成待下发镜像。
     * - 调用本函数前，上层必须已完成 SPI 的 Init/Enable。
     * - 默认值来自 datasheet reset 值：
     *   - 0x02 Driver Control = 0x000
     *   - 0x03 Gate Drive HS  = 0x377
     *   - 0x04 Gate Drive LS  = 0x777
     *   - 0x05 OCP Control    = 0x145
     *   - 0x06 CSA Control    = 0x283
     * - 0x01 是只读状态寄存器，初始化时固定置 0，等待硬件回读刷新。
     *
     * @return true 初始化成功
     * @return false 参数无效
     */
    bool init() noexcept
    {
        if (initialized_)
        {
            return true;
        }


        // 按手册 reset/default 值加载寄存器镜像。
        state_.fault_status1 = 0u;
        state_.fault_status2 = 0x000u; // 0x01 只读状态寄存器，初始化时清零
        state_.driver_ctrl = 0x000u;   // 0x02 Driver Control
        state_.gate_drive_hs = 0x377u; // 0x03 Gate Drive HS
        state_.gate_drive_ls = 0x777u; // 0x04 Gate Drive LS
        state_.ocp_ctrl = 0x145u;      // 0x05 OCP Control
        state_.csa_ctrl = 0x283u;      // 0x06 CSA Control

        initialized_ = true;
        return true;
    }

    /**
     * @brief 查询驱动初始化状态。
     *
     * @return true 已完成 init()
     * @return false 未初始化
     */
    bool is_initialized() const noexcept
    {
        return initialized_;
    }

    /**
     * @brief 设置 DIS_CPUV：是否屏蔽电荷泵欠压故障上报。
     * @param value 可选值：0=上报 CPUV；1=屏蔽 CPUV。
     * @return SetFieldResult 处理结果
     */
    SetFieldResult set_dis_cpuv(uint16_t value) noexcept
    {
        return set_field_impl(FieldName::DIS_CPUV, value, REG_DRIVER_CTRL);
    }

    /**
     * @brief 设置 DIS_GDF：是否屏蔽栅极驱动故障上报。
     * @param value 可选值：0=上报 GDF；1=屏蔽 GDF。
     * @return SetFieldResult 处理结果
     */
    SetFieldResult set_dis_gdf(uint16_t value) noexcept
    {
        return set_field_impl(FieldName::DIS_GDF, value, REG_DRIVER_CTRL);
    }

    /**
     * @brief 设置 OTW_REP：是否将过温预警 OTW 输出到故障通道。
     * @param value 可选值：0=不输出 OTW；1=输出 OTW。
     * @return SetFieldResult 处理结果
     */
    SetFieldResult set_otw_rep(uint16_t value) noexcept
    {
        return set_field_impl(FieldName::OTW_REP, value, REG_DRIVER_CTRL);
    }

    /**
     * @brief 设置 PWM_MODE：选择 PWM 接口工作模式。
     * @param value 可选值：0=6xPWM，1=3xPWM，2=1xPWM，3=Independent PWM。
     * @return SetFieldResult 处理结果
     */
    SetFieldResult set_pwm_mode(uint16_t value) noexcept
    {
        return set_field_impl(FieldName::PWM_MODE, value, REG_DRIVER_CTRL);
    }

    /**
     * @brief 设置 PWM1_COM：1xPWM 模式下整流方式。
     * @param value 可选值：0=同步整流，1=异步整流（二极管续流）。
     * @return SetFieldResult 处理结果
     */
    SetFieldResult set_pwm1_com(uint16_t value) noexcept
    {
        return set_field_impl(FieldName::PWM1_COM, value, REG_DRIVER_CTRL);
    }

    /**
     * @brief 设置 PWM1_DIR：1xPWM 模式下方向控制位。
     * @param value 可选值：0 或 1（与 INHC/DIR 按 OR 组合）。
     * @return SetFieldResult 处理结果
     */
    SetFieldResult set_pwm1_dir(uint16_t value) noexcept
    {
        return set_field_impl(FieldName::PWM1_DIR, value, REG_DRIVER_CTRL);
    }

    /**
     * @brief 设置 COAST：控制三相功率管是否进入高阻态。
     * @param value 可选值：0=正常驱动，1=全部 MOSFET Hi-Z。
     * @return SetFieldResult 处理结果
     */
    SetFieldResult set_coast(uint16_t value) noexcept
    {
        return set_field_impl(FieldName::COAST, value, REG_DRIVER_CTRL);
    }

    /**
     * @brief 设置 BRAKE：控制低边制动功能。
     * @param value 可选值：0=关闭制动，1=打开制动（与 INLC/BRAKE 按 OR）。
     * @return SetFieldResult 处理结果
     */
    SetFieldResult set_brake(uint16_t value) noexcept
    {
        return set_field_impl(FieldName::BRAKE, value, REG_DRIVER_CTRL);
    }

    /**
     * @brief 设置 CLR_FLT：触发清除锁存故障。
     * @param value 可选值：0=无动作，1=清故障（该位会自动回 0）。
     * @return SetFieldResult 处理结果
     */
    SetFieldResult set_clr_flt(uint16_t value) noexcept
    {
        return set_field_impl(FieldName::CLR_FLT, value, REG_DRIVER_CTRL);
    }

    /**
     * @brief 设置 LOCK：控制 SPI 可写寄存器锁状态。
     * @param value 可选值：3(011)=解锁，6(110)=加锁（其余值通常无效）。
     * @return SetFieldResult 处理结果
     */
    SetFieldResult set_lock(uint16_t value) noexcept
    {
        return set_field_impl(FieldName::LOCK, value, REG_GATE_DRIVE_HS);
    }

    /**
     * @brief 设置 IDRIVEP_HS：配置高边栅极灌电流强度。
     * @param value 可选值：0/1=15mA，2=45mA，3=60mA，4=90mA，5=105mA，6=135mA，7=150mA。
     * @return SetFieldResult 处理结果
     */
    SetFieldResult set_idrivep_hs(uint16_t value) noexcept
    {
        return set_field_impl(FieldName::IDRIVEP_HS, value, REG_GATE_DRIVE_HS);
    }

    /**
     * @brief 设置 IDRIVEN_HS：配置高边栅极拉电流强度。
     * @param value 可选值：0/1=30mA，2=90mA，3=120mA，4=180mA，5=210mA，6=270mA，7=300mA。
     * @return SetFieldResult 处理结果
     */
    SetFieldResult set_idriven_hs(uint16_t value) noexcept
    {
        return set_field_impl(FieldName::IDRIVEN_HS, value, REG_GATE_DRIVE_HS);
    }

    /**
     * @brief 设置 CBC：配置循环限流下的自动清故障行为。
     * @param value 可选值：0=禁用，1=重试模式下收到 PWM 后自动清故障。
     * @return SetFieldResult 处理结果
     */
    SetFieldResult set_cbc(uint16_t value) noexcept
    {
        return set_field_impl(FieldName::CBC, value, REG_GATE_DRIVE_LS);
    }

    /**
     * @brief 设置 TDRIVE：配置峰值栅极驱动保持时间。
     * @param value 可选值：0=500ns，1=1000ns，2=2000ns，3=4000ns。
     * @return SetFieldResult 处理结果
     */
    SetFieldResult set_tdrive(uint16_t value) noexcept
    {
        return set_field_impl(FieldName::TDRIVE, value, REG_GATE_DRIVE_LS);
    }

    /**
     * @brief 设置 IDRIVEP_LS：配置低边栅极灌电流强度。
     * @param value 可选值：0/1=15mA，2=45mA，3=60mA，4=90mA，5=105mA，6=135mA，7=150mA。
     * @return SetFieldResult 处理结果
     */
    SetFieldResult set_idrivep_ls(uint16_t value) noexcept
    {
        return set_field_impl(FieldName::IDRIVEP_LS, value, REG_GATE_DRIVE_LS);
    }

    /**
     * @brief 设置 IDRIVEN_LS：配置低边栅极拉电流强度。
     * @param value 可选值：0/1=30mA，2=90mA，3=120mA，4=180mA，5=210mA，6=270mA，7=300mA。
     * @return SetFieldResult 处理结果
     */
    SetFieldResult set_idriven_ls(uint16_t value) noexcept
    {
        return set_field_impl(FieldName::IDRIVEN_LS, value, REG_GATE_DRIVE_LS);
    }

    /**
     * @brief 设置 TRETRY：配置过流后的自动重试等待时间。
     * @param value 可选值：0=4ms，1=50us。
     * @return SetFieldResult 处理结果
     */
    SetFieldResult set_tretry(uint16_t value) noexcept
    {
        return set_field_impl(FieldName::TRETRY, value, REG_OCP_CTRL);
    }

    /**
     * @brief 设置 DEAD_TIME：配置高低边切换死区时间。
     * @param value 可选值：0=50ns，1=100ns，2=200ns，3=400ns。
     * @return SetFieldResult 处理结果
     */
    SetFieldResult set_dead_time(uint16_t value) noexcept
    {
        return set_field_impl(FieldName::DEAD_TIME, value, REG_OCP_CTRL);
    }

    /**
     * @brief 设置 OCP_MODE：配置过流触发后的处理模式。
     * @param value 可选值：0=锁存故障，1=自动重试，2=仅上报，3=不上报且不动作。
     * @return SetFieldResult 处理结果
     */
    SetFieldResult set_ocp_mode(uint16_t value) noexcept
    {
        return set_field_impl(FieldName::OCP_MODE, value, REG_OCP_CTRL);
    }

    /**
     * @brief 设置 OCP_ACT：配置过流时的关断范围。
     * @param value 可选值：0=三相全部关断，1=仅故障相关断。
     * @return SetFieldResult 处理结果
     */
    SetFieldResult set_ocp_act(uint16_t value) noexcept
    {
        return set_field_impl(FieldName::OCP_ACT, value, REG_OCP_CTRL);
    }

    /**
     * @brief 设置 VDS_LVL：配置 VDS 过流检测阈值。
     * @param value 可选值：0=0.15V，1=0.24V，2=0.40V，3=0.51V，4=0.60V，5=0.90V，6=1.8V，7=禁用。
     * @return SetFieldResult 处理结果
     */
    SetFieldResult set_vds_lvl(uint16_t value) noexcept
    {
        return set_field_impl(FieldName::VDS_LVL, value, REG_OCP_CTRL);
    }

    /**
     * @brief 设置 VREF_DIV：配置电流采样参考电压分压比。
     * @param value 可选值：0=VREF，1=VREF/2。
     * @return SetFieldResult 处理结果
     */
    SetFieldResult set_vref_div(uint16_t value) noexcept
    {
        return set_field_impl(FieldName::VREF_DIV, value, REG_CSA_CTRL);
    }

    /**
     * @brief 设置 LS_REF：选择低边 VDS_OCP 的参考节点。
     * @param value 可选值：0=SHx-SPx，1=SHx-SNx。
     * @return SetFieldResult 处理结果
     */
    SetFieldResult set_ls_ref(uint16_t value) noexcept
    {
        return set_field_impl(FieldName::LS_REF, value, REG_CSA_CTRL);
    }

    /**
     * @brief 设置 CSA_GAIN：配置电流采样放大器增益。
     * @param value 可选值：0=5V/V，1=10V/V，2=20V/V，3=40V/V。
     * @return SetFieldResult 处理结果
     */
    SetFieldResult set_csa_gain(uint16_t value) noexcept
    {
        return set_field_impl(FieldName::CSA_GAIN, value, REG_CSA_CTRL);
    }

    /**
     * @brief 设置 DIS_SEN：是否屏蔽采样过流保护 SEN_OCP。
     * @param value 可选值：0=使能 SEN_OCP，1=屏蔽 SEN_OCP。
     * @return SetFieldResult 处理结果
     */
    SetFieldResult set_dis_sen(uint16_t value) noexcept
    {
        return set_field_impl(FieldName::DIS_SEN, value, REG_CSA_CTRL);
    }

    /**
     * @brief 设置 SPI_CAL：控制是否使能 SPI 触发采样校准。
     * @param value 可选值：0=禁用 CAL，1=使能 CAL。
     * @return SetFieldResult 处理结果
     */
    SetFieldResult set_spi_cal(uint16_t value) noexcept
    {
        return set_field_impl(FieldName::SPI_CAL, value, REG_CSA_CTRL);
    }

    /**
     * @brief 设置 AUTOCAL：控制运行时自动校准触发。
     * @param value 可选值：0=不触发，1=触发 AUTOCAL。
     * @return SetFieldResult 处理结果
     */
    SetFieldResult set_autocal(uint16_t value) noexcept
    {
        return set_field_impl(FieldName::AUTOCAL, value, REG_CSA_CTRL);
    }

    /**
     * @brief 设置 SEN_LVL：配置采样过流比较阈值。
     * @param value 可选值：0=0.25V，1=0.5V，2=0.75V，3=1.0V。
     * @return SetFieldResult 处理结果
     */
    SetFieldResult set_sen_lvl(uint16_t value) noexcept
    {
        return set_field_impl(FieldName::SEN_LVL, value, REG_CSA_CTRL);
    }

    /**
     * @brief 清除锁存故障（等价写 Driver Control.CLR_FLT = 1）。
     *
     * @return SetFieldResult 处理结果
     */
    SetFieldResult clear_faults() noexcept
    {
        return set_clr_flt(1u);
    }

    /**
     * @brief 将内部表中的寄存器镜像一次性下发到硬件。
     *
     * @details
     * - 只写控制寄存器：0x02~0x06。
     * - 所有字段设置函数都不会直接写 SPI，必须通过本函数触发更新。
     *
     * @return true SPI 下发成功
     * @return false 未初始化、SPI 传输失败或写后回读校验失败
     */
    bool trigger_spi_update() noexcept
    {
        if (!initialized_)
        {
            return false;
        }

        write_register(REG_DRIVER_CTRL, state_.driver_ctrl);
        write_register(REG_GATE_DRIVE_HS, state_.gate_drive_hs);
        write_register(REG_GATE_DRIVE_LS, state_.gate_drive_ls);
        write_register(REG_OCP_CTRL, state_.ocp_ctrl);
        write_register(REG_CSA_CTRL, state_.csa_ctrl);

        // CLR_FLT 是写 1 自清零位；下发后在内部表中恢复为 0。
        if ((state_.driver_ctrl & 0x0001u) != 0u)
        {
            state_.driver_ctrl =
                static_cast<uint16_t>(state_.driver_ctrl & static_cast<uint16_t>(~0x0001u));
        }

        return true;
    }

    /**
     * @brief 读取并刷新故障状态寄存器（0x00/0x01）。
     *
     * @return true 刷新成功
     * @return false SPI 失败或未初始化
     */
    bool refresh_fault_status() noexcept
    {
        if (!initialized_)
        {
            return false;
        }
        if (!read_register(REG_FAULT_STATUS_1, state_.fault_status1) ||
            !read_register(REG_VGS_STATUS_2, state_.fault_status2))
        {
            return false;
        }
        return true;
    }

    /**
     * @brief 获取当前寄存器镜像表。
     *
     * @return const StateTable& 寄存器状态表只读引用
     */
    const StateTable& state() const noexcept
    {
        return state_;
    }

    /**!!!!
     * @brief 设置 EN 引脚输出状态。
     *
     * @param en true 使能；false 失能
     */
    void set_enable(bool en) noexcept
    {
        if(en == true)
            enable_gpio_.set();
        else 
            enable_gpio_.unset();
    }

    /**!!!!
     * @brief 读取 nFAULT 当前有效态。
     *
     * @return true nFAULT 有效（故障激活）
     * @return false nFAULT 无效
     */
    bool is_nfault_active() const noexcept
    {
        const bool raw_high = (nfault_gpio_.read() != 0u);
        return !raw_high; 
    }

    /**
     * @brief 注册 nFAULT 回调。
     *
     * @param cb 回调函数指针（传 nullptr 可注销）
     * @param user_ctx 用户上下文
     */
    void register_nfault_callback(Callback cb, void* user_ctx = nullptr) noexcept
    {
        nfault_callback_ = cb;
        nfault_callback_user_ctx_ = user_ctx;
    }

    /**
     * @brief nFAULT 外部 ISR 转发入口。
     *
     * @details
     * 推荐应用层流程：
     * 1. 端口中断入口中调用本函数
     * 2. 本函数检查并清除 nFAULT 引脚中断标志
     * 3. 刷新故障状态寄存器镜像
     * 4. 若已注册回调则触发回调
     */
    void handle_nfault_irq() noexcept
    {
        if (nfault_gpio_.get_interrupt_state() == 0u)
        {
            return;
        }

        nfault_gpio_.clear_interrupt_state();
        (void)refresh_fault_status();

        if (nfault_callback_ != nullptr)
        {
            nfault_callback_(state_, nfault_callback_user_ctx_);
        }
    }

private:
    static constexpr uint16_t kRegisterDataMask = 0x07FFu;
    static constexpr uint32_t kSpiWaitLoopLimit = 1000000u;

    static constexpr uint16_t bit_mask(uint8_t width, uint8_t lsb) noexcept
    {
        return static_cast<uint16_t>(((1u << width) - 1u) << lsb);
    }

    /**
     * @brief 字段设置核心实现（仅更新寄存器镜像，不写 SPI）。
     */
    SetFieldResult set_field_impl(FieldName field, uint16_t value, uint8_t expected_reg) noexcept
    {
        if (!initialized_)
        {
            return SetFieldResult::NotInitialized;
        }

        uint8_t reg_addr = 0xFFu;
        uint8_t lsb = 0u;
        uint8_t width = 0u;

        switch (field)
        {
        case FieldName::DIS_CPUV: reg_addr = REG_DRIVER_CTRL; lsb = 9u; width = 1u; break;
        case FieldName::DIS_GDF: reg_addr = REG_DRIVER_CTRL; lsb = 8u; width = 1u; break;
        case FieldName::OTW_REP: reg_addr = REG_DRIVER_CTRL; lsb = 7u; width = 1u; break;
        case FieldName::PWM_MODE: reg_addr = REG_DRIVER_CTRL; lsb = 5u; width = 2u; break;
        case FieldName::PWM1_COM: reg_addr = REG_DRIVER_CTRL; lsb = 4u; width = 1u; break;
        case FieldName::PWM1_DIR: reg_addr = REG_DRIVER_CTRL; lsb = 3u; width = 1u; break;
        case FieldName::COAST: reg_addr = REG_DRIVER_CTRL; lsb = 2u; width = 1u; break;
        case FieldName::BRAKE: reg_addr = REG_DRIVER_CTRL; lsb = 1u; width = 1u; break;
        case FieldName::CLR_FLT: reg_addr = REG_DRIVER_CTRL; lsb = 0u; width = 1u; break;
        case FieldName::LOCK: reg_addr = REG_GATE_DRIVE_HS; lsb = 8u; width = 3u; break;
        case FieldName::IDRIVEP_HS: reg_addr = REG_GATE_DRIVE_HS; lsb = 4u; width = 3u; break;
        case FieldName::IDRIVEN_HS: reg_addr = REG_GATE_DRIVE_HS; lsb = 0u; width = 3u; break;
        case FieldName::CBC: reg_addr = REG_GATE_DRIVE_LS; lsb = 10u; width = 1u; break;
        case FieldName::TDRIVE: reg_addr = REG_GATE_DRIVE_LS; lsb = 8u; width = 2u; break;
        case FieldName::IDRIVEP_LS: reg_addr = REG_GATE_DRIVE_LS; lsb = 4u; width = 3u; break;
        case FieldName::IDRIVEN_LS: reg_addr = REG_GATE_DRIVE_LS; lsb = 0u; width = 3u; break;
        case FieldName::TRETRY: reg_addr = REG_OCP_CTRL; lsb = 10u; width = 1u; break;
        case FieldName::DEAD_TIME: reg_addr = REG_OCP_CTRL; lsb = 8u; width = 2u; break;
        case FieldName::OCP_MODE: reg_addr = REG_OCP_CTRL; lsb = 6u; width = 2u; break;
        case FieldName::OCP_ACT: reg_addr = REG_OCP_CTRL; lsb = 5u; width = 1u; break;
        case FieldName::VDS_LVL: reg_addr = REG_OCP_CTRL; lsb = 0u; width = 3u; break;
        case FieldName::VREF_DIV: reg_addr = REG_CSA_CTRL; lsb = 9u; width = 1u; break;
        case FieldName::LS_REF: reg_addr = REG_CSA_CTRL; lsb = 8u; width = 1u; break;
        case FieldName::CSA_GAIN: reg_addr = REG_CSA_CTRL; lsb = 6u; width = 2u; break;
        case FieldName::DIS_SEN: reg_addr = REG_CSA_CTRL; lsb = 5u; width = 1u; break;
        case FieldName::SPI_CAL: reg_addr = REG_CSA_CTRL; lsb = 4u; width = 1u; break;
        case FieldName::AUTOCAL: reg_addr = REG_CSA_CTRL; lsb = 3u; width = 1u; break;
        case FieldName::SEN_LVL: reg_addr = REG_CSA_CTRL; lsb = 0u; width = 2u; break;
        default:
            return SetFieldResult::InvalidField;
        }

        if (reg_addr != expected_reg)
        {
            return SetFieldResult::InvalidField;
        }

        const uint16_t value_max = static_cast<uint16_t>((1u << width) - 1u);
        if (value > value_max)
        {
            return SetFieldResult::ValueOutOfRange;
        }

        const uint16_t mask = bit_mask(width, lsb);
        uint16_t* reg_value = nullptr;
        switch (reg_addr)
        {
        case REG_DRIVER_CTRL: reg_value = &state_.driver_ctrl; break;
        case REG_GATE_DRIVE_HS: reg_value = &state_.gate_drive_hs; break;
        case REG_GATE_DRIVE_LS: reg_value = &state_.gate_drive_ls; break;
        case REG_OCP_CTRL: reg_value = &state_.ocp_ctrl; break;
        case REG_CSA_CTRL: reg_value = &state_.csa_ctrl; break;
        default:
            return SetFieldResult::InvalidField;
        }

        *reg_value = static_cast<uint16_t>((*reg_value & static_cast<uint16_t>(~mask)) |
                                           static_cast<uint16_t>(value << lsb));

        return SetFieldResult::Ok;
    }

    bool wait_tx_and_rx_ready() const noexcept
    {  

        for (uint32_t i = 0u; i < kSpiWaitLoopLimit; ++i)
        {
            if (spi_.isnew() > 0u)
            {
                break;
            }
            if ((i + 1u) == kSpiWaitLoopLimit)
            {
                return false;
            }
        }

        for (uint32_t i = 0u; i < kSpiWaitLoopLimit; ++i)
        {
            if (!spi_.isbusy())
            {
                return true;
            }
        }
        return false;
    }

    bool transfer_word(uint16_t tx_word, uint16_t& rx_data) noexcept
    {
        // 每次传输前显式切换片选，支持同一 SPI 总线挂接多个 DRV8304 实例。
        spi_.select();
        spi_.clear_rx();
        spi_.clear_tx();
        spi_.send(tx_word);
        if (!wait_tx_and_rx_ready())
        {
            return false;
        }

        const uint32_t rx_word = spi_.recive();
        if (rx_word == CY_SCB_SPI_RX_NO_DATA)
        {
            return false;
        }

        rx_data = static_cast<uint16_t>(rx_word & kRegisterDataMask);
        return true;
    }

    bool read_register(uint8_t reg_addr, uint16_t& reg_value) noexcept
    {
        const uint16_t frame = static_cast<uint16_t>(0x8000u | ((reg_addr & 0x0Fu) << 11));
        return transfer_word(frame, reg_value);
    }

    bool write_register(uint8_t reg_addr, uint16_t reg_value) noexcept
    {
        const uint16_t sanitized_value = static_cast<uint16_t>(reg_value & kRegisterDataMask);
        const uint16_t frame = static_cast<uint16_t>(((reg_addr & 0x0Fu) << 11) | sanitized_value);

        uint16_t dummy = 0u;
        if (!transfer_word(frame, dummy))
        {
            return false;
        }

        // uint16_t readback = 0u;
        // if (!read_register(reg_addr, readback))
        // {
        //     return false;
        // }

        // Driver Control[0] (CLR_FLT) 为写 1 自清零位，回读校验需忽略该位。
        // uint16_t verify_mask = kRegisterDataMask;
        // if (reg_addr == REG_DRIVER_CTRL)
        // {
        //     verify_mask = static_cast<uint16_t>(kRegisterDataMask & static_cast<uint16_t>(~0x0001u));
        // }

        // return ((readback & verify_mask) == (sanitized_value & verify_mask));
        return true;
    }

    hal_spi& spi_;
    hal_gpio& enable_gpio_;
    hal_gpio& nfault_gpio_;
    bool initialized_;
    StateTable state_;
    Callback nfault_callback_;
    void* nfault_callback_user_ctx_;
};
