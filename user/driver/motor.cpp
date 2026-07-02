#include "motor.hpp"
#include "cy_gpio.h"

motor_driver::motor_driver(foc& foc_soft,
                           drv8304& drv,
                           kth7823& ec,
                           hal_spi& ec_spi,
                           hal_pwm& pwm_u,
                           hal_pwm& pwm_v,
                           hal_pwm& pwm_w,
                           hal_pwm& pwm_start,
                           hal_counter& speed_loop_timer,
                           bool auto_start,
                           uint32_t sar_result_group_mask) noexcept
    : foc_soft_(foc_soft)
    , drv(drv)
    , ec(ec)
    , ec_spi_(ec_spi)
    , encoder_mean_filter_(foc_soft_.motor.enc_a)
    , pwm_u_(pwm_u)
    , pwm_v_(pwm_v)
    , pwm_w_(pwm_w)
    , pwm_start_(pwm_start)
    , speed_loop_timer_(speed_loop_timer)
    , auto_start_(auto_start)
    , sar_result_group_mask_(sar_result_group_mask)
{
}



void motor_driver::start() noexcept
{
    foc_soft_.clear_running_values();
    ec.start_yaw_data_transfer();
    for(size_t i = 0;i < 12;i++)
    {
        ec_spi_.send(0);
    }
    for (size_t i = 0; i < 100; i++)
    {
        foc_soft_.trg_speed();
    }
    
    if (!auto_start_)
    {
        pwm_start_.start();
    }

    // ec_spi_.open_rx_interrupt(hal_spi::RX_FIFO_NOT_EMPTY);
    const uint32_t int_mask = Cy_HPPASS_SAR_Result_GetInterruptMask();
    Cy_HPPASS_SAR_Result_SetInterruptMask(int_mask | sar_result_group_mask_);
    // pwm_u_.open_interrupt(hal_pwm::INT_ON_TC);
}

void motor_driver::stop() noexcept
{
    pwm_u_.stop();
    pwm_v_.stop();
    pwm_w_.stop();
    pwm_start_.stop();
    speed_loop_timer_.stop();
    ec.stop_transfer();
    ec_spi_.close_rx_interrupt(hal_spi::RX_FIFO_NOT_EMPTY);
    foc_soft_.clear_running_values();
}



void motor_driver::foc_trig_isr() noexcept
{
    uint32_t status = Cy_HPPASS_SAR_Result_GetInterruptStatusMasked();
    if ((status & sar_result_group_mask_) == 0u)
    {
        return;
    }
    Cy_HPPASS_SAR_Result_ClearInterrupt(sar_result_group_mask_);

    foc_soft_.trg();

    ec_spi_.send(0);
    ec_spi_.send(0);
    ec_spi_.send(0);
    ec_spi_.send(0);
}

void motor_driver::speed_isr() noexcept
{
    hal_counter::interrupt_type int_type = speed_loop_timer_.get_interrupt_type();
    speed_loop_timer_.clear_interrupt(int_type);
    foc_soft_.trg_speed();
}


