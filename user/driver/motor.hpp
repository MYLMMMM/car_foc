#pragma once

#include <cstdint>

#include "drv8304.hpp"
#include "foc_soft.hpp"
#include "hal.hpp"
#include "kth7823.hpp"
#include "algorithm/CircularMeanFilter.hpp"

class motor_driver
{
public:
    static const size_t encoder_filter_deep = 1u;
    using encoder_mean_filter_t = CircularMeanFilter<volatile uint32_t, uint16_t, encoder_filter_deep>;

    motor_driver(foc& foc_soft,
                 Drv8304& drv,
                 kth7823& ec,
                 hal_spi& ec_spi,
                 hal_pwm& pwm_u,
                 hal_pwm& pwm_v,
                 hal_pwm& pwm_w,
                 hal_pwm& pwm_start,
                 uint32_t sar_result_group_mask = CY_HPPASS_INTR_SAR_RESULT_GROUP_0) noexcept;

    motor_driver(const motor_driver&) = delete;
    motor_driver& operator=(const motor_driver&) = delete;
    motor_driver(motor_driver&&) = delete;
    motor_driver& operator=(motor_driver&&) = delete;

    void set_cc(uint32_t cc_u, uint32_t cc_v, uint32_t cc_w) noexcept;
    void start() noexcept;
    void stop() noexcept;

    // 放在 ADC 完成中断中，用于触发一次 FOC 计算。
    void foc_trig_isr() noexcept;

    void pwm_chage_trig() noexcept;
    // 预留给编码器 SPI 中断，后续可在这里加滤波等逻辑。
    void ec_isr() noexcept;

// private:
    foc& foc_soft_;
    Drv8304& drv;
    kth7823& ec;
    hal_spi& ec_spi_;
    encoder_mean_filter_t encoder_mean_filter_;
    hal_pwm& pwm_u_;
    hal_pwm& pwm_v_;
    hal_pwm& pwm_w_;
    hal_pwm& pwm_start_;
    uint32_t sar_result_group_mask_;
};
