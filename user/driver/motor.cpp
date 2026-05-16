#include "motor.hpp"

motor_driver::motor_driver(foc& foc_soft,
                           drv8304& drv,
                           kth7823& ec,
                           hal_spi& ec_spi,
                           hal_pwm& pwm_u,
                           hal_pwm& pwm_v,
                           hal_pwm& pwm_w,
                           hal_pwm& pwm_start,
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
    , sar_result_group_mask_(sar_result_group_mask)
{
}

void motor_driver::set_cc(uint32_t cc_u, uint32_t cc_v, uint32_t cc_w) noexcept
{
    pwm_u_.set_compare(cc_u);
    pwm_v_.set_compare(cc_v);
    pwm_w_.set_compare(cc_w);
}

void motor_driver::start() noexcept
{
    foc_soft_.motor.clear_running_values();
    ec.start_yaw_data_transfer();
    for(size_t i = 0;i < encoder_filter_deep;i++)
    {
        ec_spi_.send(0);
    }
    pwm_start_.start();

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
    ec.stop_transfer();
    ec_spi_.close_rx_interrupt(hal_spi::RX_FIFO_NOT_EMPTY);
    foc_soft_.motor.clear_running_values();
}

void motor_driver::pwm_chage_trig()
{
    hal_pwm::hal_pwm_interrupt_type int_type = pwm_u_.get_interrupt_type();
    pwm_u_.clear_interrupt(int_type);
    if(pwm_u_.get_count() < 1000)
    {
    pwm_u_.set_compare(foc_soft_.motor.ccr_a);
    pwm_v_.set_compare(foc_soft_.motor.ccr_b);
    pwm_w_.set_compare(foc_soft_.motor.ccr_c);
    }
}

void motor_driver::foc_trig_isr() noexcept
{
    uint32_t status = Cy_HPPASS_SAR_Result_GetInterruptStatusMasked();
    if ((status & sar_result_group_mask_) == 0u)
    {
        return;
    }
    Cy_HPPASS_SAR_Result_ClearInterrupt(sar_result_group_mask_);

    // encoder_mean_filter_.trig();

    foc_soft_.trg();

    pwm_u_.set_compare(foc_soft_.motor.ccr_a);
    pwm_v_.set_compare(foc_soft_.motor.ccr_b);
    pwm_w_.set_compare(foc_soft_.motor.ccr_c);

    ec_spi_.send(0);
    ec_spi_.send(0);
    ec_spi_.send(0);
    ec_spi_.send(0);
    
}

//之后将它更新为DMA直接传输
void motor_driver::ec_isr() noexcept
{
    hal_spi::hal_spi_interrupt_type int_type = ec_spi_.get_rx_interrupt_type();
    ec_spi_.clear_rx_interrupt(int_type);

    while (ec_spi_.isnew() != 0u) {
        const uint16_t raw = static_cast<uint16_t>(ec_spi_.recive() & 0xFFFFu);
        encoder_mean_filter_.write(raw);
        ec_spi_.send(0);
        ec_spi_.send(0);
        ec_spi_.send(0);
    }

}
