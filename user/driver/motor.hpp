#pragma once

#include <cstdint>

#include "drv8304.hpp"
#include "foc_soft.hpp"
#include "hal.hpp"
#include "hal_counter_cy.hpp"
#include "kth7823.hpp"
#include "algorithm/CircularMeanFilter.hpp"

class motor_driver
{
public:
    static const size_t encoder_filter_deep = 1u;
    using encoder_mean_filter_t = CircularMeanFilter<volatile uint32_t, uint16_t, encoder_filter_deep>;

    motor_driver(foc& foc_soft,
                 drv8304& drv,
                 kth7823& ec,
                 hal_spi& ec_spi,
                 hal_pwm& pwm_u,
                 hal_pwm& pwm_v,
                 hal_pwm& pwm_w,
                 hal_pwm& pwm_start,
                 hal_counter& speed_loop_timer,
                 bool auto_start = false,
                 uint32_t sar_result_group_mask = CY_HPPASS_INTR_SAR_RESULT_GROUP_0) noexcept;

    motor_driver(const motor_driver&) = delete;
    motor_driver& operator=(const motor_driver&) = delete;
    motor_driver(motor_driver&&) = delete;
    motor_driver& operator=(motor_driver&&) = delete;

    void start() noexcept;
    void stop() noexcept;

    void foc_trig_isr() noexcept;

    void speed_isr() noexcept;

// private:
    foc& foc_soft_;
    drv8304& drv;
    kth7823& ec;
    hal_spi& ec_spi_;
    encoder_mean_filter_t encoder_mean_filter_;
    hal_pwm& pwm_u_;
    hal_pwm& pwm_v_;
    hal_pwm& pwm_w_;
    hal_pwm& pwm_start_;
    hal_counter& speed_loop_timer_;
    bool auto_start_;
    uint32_t sar_result_group_mask_;
};
