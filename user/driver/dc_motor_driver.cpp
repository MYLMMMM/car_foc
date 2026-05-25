#include "dc_motor_driver.hpp"
#include "bsp_init.hpp"

dc_motor_driver::dc_motor_driver(dc_motor& dc_motor_soft,
                                 hal_pwm& pwm_in1,
                                 hal_pwm& pwm_in2,
                                 hal_pwm& pwm_start,
                                 uint32_t sar_result_group_mask) noexcept
    : dc_motor_soft_(dc_motor_soft)
    , pwm_in1_(pwm_in1)
    , pwm_in2_(pwm_in2)
    , pwm_start_(pwm_start)
    , sar_result_group_mask_(sar_result_group_mask)
{
}

void dc_motor_driver::start() noexcept
{
    drv8701_c.set_enable(true);//这是直流电机没有正确关闭的临时补丁，之后应该修改。
    pwm_start_.start();
    const uint32_t int_mask = Cy_HPPASS_SAR_Result_GetInterruptMask();
    Cy_HPPASS_SAR_Result_SetInterruptMask(int_mask | sar_result_group_mask_);
}

void dc_motor_driver::stop() noexcept
{
    pwm_in1_.stop();
    pwm_in2_.stop();
    drv8701_c.set_enable(false);//这是直流电机没有正确关闭的临时补丁，之后应该修改。
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

    // 8701p 双 PWM 模式：直接写入两路比较寄存器
    pwm_in1_.set_compare(dc_motor_soft_.motor.ccr_p);
    pwm_in2_.set_compare(dc_motor_soft_.motor.ccr_n);
}
