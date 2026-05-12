#include "dc_motor_driver.hpp"

dc_motor_driver::dc_motor_driver(dc_motor& dc_motor_soft,
                                 hal_pwm& pwm_u,
                                 hal_pwm& pwm_v,
                                 hal_pwm& pwm_start,
                                 uint32_t sar_result_group_mask) noexcept
    : dc_motor_soft_(dc_motor_soft)
    , pwm_u_(pwm_u)
    , pwm_v_(pwm_v)
    , pwm_start_(pwm_start)
    , sar_result_group_mask_(sar_result_group_mask)
{
}

void dc_motor_driver::start() noexcept
{
    pwm_start_.start();
    const uint32_t int_mask = Cy_HPPASS_SAR_Result_GetInterruptMask();
    Cy_HPPASS_SAR_Result_SetInterruptMask(int_mask | sar_result_group_mask_);
}

void dc_motor_driver::stop() noexcept
{
    pwm_u_.stop();
    pwm_v_.stop();
}

void dc_motor_driver::dc_trig_isr() noexcept
{
    uint32_t status = Cy_HPPASS_SAR_Result_GetInterruptStatusMasked();
    if ((status & sar_result_group_mask_) == 0u)
    {
        return;
    }
    Cy_HPPASS_SAR_Result_ClearInterrupt(sar_result_group_mask_);

    dc_motor_soft_.trg();

    pwm_u_.set_compare(dc_motor_soft_.motor.ccr_a);
    pwm_v_.set_compare(dc_motor_soft_.motor.ccr_b);
}
