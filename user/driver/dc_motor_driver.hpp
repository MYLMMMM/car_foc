#pragma once

#include <cstdint>

#include "dc_motor_soft.hpp"
#include "hal.hpp"

/**
 * @brief 直流电机驱动类(精简版, 无编码器/DRV8304)
 * @details 持有 dc_motor 控制算法 + 2 路半桥 PWM + 1 路同步触发 PWM,
 *          通过 SAR ADC 结果中断触发一次控制计算。
 */
class dc_motor_driver
{
public:
    dc_motor_driver(dc_motor& dc_motor_soft,
                    hal_pwm& pwm_u,
                    hal_pwm& pwm_v,
                    hal_pwm& pwm_start,
                    uint32_t sar_result_group_mask = CY_HPPASS_INTR_SAR_RESULT_GROUP_2) noexcept;

    dc_motor_driver(const dc_motor_driver&) = delete;
    dc_motor_driver& operator=(const dc_motor_driver&) = delete;
    dc_motor_driver(dc_motor_driver&&) = delete;
    dc_motor_driver& operator=(dc_motor_driver&&) = delete;

    void start() noexcept;
    void stop() noexcept;

    /// @brief 放在 ADC 完成中断中，触发一次直流电机控制计算。
    void dc_trig_isr() noexcept;

// private:
    dc_motor& dc_motor_soft_;
    hal_pwm& pwm_u_;
    hal_pwm& pwm_v_;
    hal_pwm& pwm_start_;
    uint32_t sar_result_group_mask_;
};
