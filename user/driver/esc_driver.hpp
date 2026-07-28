#pragma once

#include <cstdint>

#include "esc_soft.hpp"
#include "hal.hpp"

/**
 * @brief ESC 电调驱动类(单 PWM 脉宽控制)
 * @details 持有 esc 控制算法 + 1 路 PWM(ESC 信号) + 1 路同步触发 PWM,
 *          通过 SAR ADC 结果中断触发一次控制计算。
 *          无方向控制, 无使能引脚。
 */
class esc_driver
{
public:
    esc_driver(esc& esc_soft,
               hal_pwm& pwm_esc,
               hal_pwm& pwm_start,
               uint32_t sar_result_group_mask = CY_HPPASS_INTR_SAR_RESULT_GROUP_2) noexcept;

    esc_driver(const esc_driver&) = delete;
    esc_driver& operator=(const esc_driver&) = delete;
    esc_driver(esc_driver&&) = delete;
    esc_driver& operator=(esc_driver&&) = delete;

    void start() noexcept;
    void stop() noexcept;

    /// @brief 放在 ADC 完成中断中，触发一次 ESC 控制计算。
    void esc_trig_isr() noexcept;

// private:
    esc& esc_soft_;
    hal_pwm& pwm_esc_;
    hal_pwm& pwm_start_;
    uint32_t sar_result_group_mask_;
};
