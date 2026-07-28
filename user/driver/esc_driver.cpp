#include "esc_driver.hpp"
#include "bsp_init.hpp"

esc_driver::esc_driver(esc& esc_soft,
                       hal_pwm& pwm_esc,
                       hal_pwm& pwm_start,
                       uint32_t sar_result_group_mask) noexcept
    : esc_soft_(esc_soft)
    , pwm_esc_(pwm_esc)
    , pwm_start_(pwm_start)
    , sar_result_group_mask_(sar_result_group_mask)
{
}

void esc_driver::start() noexcept
{
    pwm_esc_.start();
    pwm_start_.start();
    const uint32_t int_mask = Cy_HPPASS_SAR_Result_GetInterruptMask();
    Cy_HPPASS_SAR_Result_SetInterruptMask(int_mask | sar_result_group_mask_);
}

void esc_driver::stop() noexcept
{
    pwm_esc_.stop();
    pwm_start_.stop();
}

void esc_driver::esc_trig_isr() noexcept
{
    uint32_t status = Cy_HPPASS_SAR_Result_GetInterruptStatusMasked();
    if ((status & sar_result_group_mask_) == 0u)
    {
        return;
    }
    Cy_HPPASS_SAR_Result_ClearInterrupt(sar_result_group_mask_);

    esc_soft_.trg();

    // 写入 ESC 比较寄存器
    pwm_esc_.set_compare(esc_soft_.data.ccr_esc);
}
