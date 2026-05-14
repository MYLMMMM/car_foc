/*****
 * @brief this hpp can't be include by cpp except bsp_init.cpp
 */
#pragma once

#include "drv8304.hpp"
#include "drv8876.hpp"
#include "kth7823.hpp"
#include "cybsp.h"
#include "foc_soft.hpp"
#include "endecode.hpp"
#include "hal.hpp"
#include "XL2020RGBC.hpp"
#include "motor.hpp"
#include "dc_motor_soft.hpp"
#include "dc_motor_driver.hpp"
#include "command_doer.hpp"

// motor A structure
foc_motor_datastructure_config foc_motor_datastructure_A_config =
{
    .adc_a = (volatile int32_t*)CY_HPPASS_SAR_CHAN_RSLT_PTR(ADC_A_IU_CH_CHAN_IDX),
    .adc_b = (volatile int32_t*)CY_HPPASS_SAR_CHAN_RSLT_PTR(ADC_A_IV_CH_CHAN_IDX),
    .adc_c = (volatile int32_t*)CY_HPPASS_SAR_CHAN_RSLT_PTR(ADC_A_IW_CH_CHAN_IDX),
    .adc_vbus = (volatile int32_t*)CY_HPPASS_SAR_CHAN_RSLT_PTR(ADC_VBUS_CH_CHAN_IDX),

    .adc_zero_a = 2250*1,
    .adc_zero_b = 2250*1,
    .adc_zero_c = 2250*1,
    .adc_vref = 3.0f,
    .adc_full_scale = 4095*1,
    .vbus_divider_ratio = 10.0f,
    .shunt_resistance = 0.010f,
    .current_sense_gain = 40.0f,

    .encoder_cpr = 65535,
    .pole_pairs = 7,
    .theta_elec_offset = -4.7022140870f,

    .pid_d_kp = 1.2f,
    .pid_d_ki = 0.25f,
    .pid_d_kd = 0.0f,
    .pid_d_integral_limit = 4.0f,
    .pid_q_kp = 1.2f,
    .pid_q_ki = 0.25f,
    .pid_q_kd = 0.0f,
    .pid_q_integral_limit = 4.0f,
    .pid_speed_kp = 0.00045f,
    .pid_speed_ki = 0.0f,
    .pid_speed_kd = 0.0f,
    .pid_speed_integral_limit = 4.0f,
    .kf_q_theta = 1e-5f,
    .kf_q_speed = 3e-3f,
    .kf_r_theta = 8e-3f,

    .control_period_s = 0.0001f,
    .speed_loop_div = 20u,

    .pwm_period = 11999,
};

foc_motor_datastructure foc_motor_datastructure_A(foc_motor_datastructure_A_config);
foc foc_A_soft(foc_motor_datastructure_A);

// motor B structuer
foc_motor_datastructure_config foc_motor_datastructure_B_config =
{
    .adc_a = (volatile int32_t*)CY_HPPASS_SAR_CHAN_RSLT_PTR(ADC_B_IU_CH_CHAN_IDX),
    .adc_b = (volatile int32_t*)CY_HPPASS_SAR_CHAN_RSLT_PTR(ADC_B_IV_CH_CHAN_IDX),
    .adc_c = (volatile int32_t*)CY_HPPASS_SAR_CHAN_RSLT_PTR(ADC_B_IW_CH_CHAN_IDX),
    .adc_vbus = (volatile int32_t*)CY_HPPASS_SAR_CHAN_RSLT_PTR(ADC_VBUS_CH_CHAN_IDX),

    .adc_zero_a = 2260*1,
    .adc_zero_b = 2250*1,
    .adc_zero_c = 2250*1,
    .adc_vref = 3.0f,
    .adc_full_scale = 4095*1,
    .vbus_divider_ratio = 10.0f,
    .shunt_resistance = 0.005f,
    .current_sense_gain = 40.0f,

    .encoder_cpr = 65535,
    .pole_pairs = 7,
    .theta_elec_offset = -4.588851148f,

    .pid_d_kp = 1.2f,
    .pid_d_ki = 0.25f,
    .pid_d_kd = 0.0f,
    .pid_d_integral_limit = 4.0f,
    .pid_q_kp = 1.2f,
    .pid_q_ki = 0.25f,
    .pid_q_kd = 0.0f,
    .pid_q_integral_limit = 4.0f,
    .pid_speed_kp = 0.00045f,
    .pid_speed_ki = 0.0f,
    .pid_speed_kd = 0.0f,
    .pid_speed_integral_limit = 4.0f,
    .kf_q_theta = 1e-5f,
    .kf_q_speed = 3e-3f,
    .kf_r_theta = 8e-3f,

    .control_period_s = 0.0001f,
    .speed_loop_div = 20u,

    .pwm_period = 11999,
};

foc_motor_datastructure foc_motor_datastructure_B(foc_motor_datastructure_B_config);
foc foc_B_soft(foc_motor_datastructure_B);

// motor C structure (DC motor)
dc_motor_datastructure_config motor_c_config =
{
    .adc_current = (volatile int32_t*)CY_HPPASS_SAR_CHAN_RSLT_PTR(ADC_C_I_CH_CHAN_IDX),
    .adc_vbus = (volatile int32_t*)CY_HPPASS_SAR_CHAN_RSLT_PTR(ADC_VBUS_CH_CHAN_IDX),

    .adc_zero = 0,
    .adc_vref = 3.0f,
    .adc_full_scale = 4095,
    .shunt_resistance = 0.010f,
    .current_sense_gain = 40.0f,
    .vbus_divider_ratio = 10.0f,

    .pid_kp = 1.2f,
    .pid_ki = 0.25f,
    .pid_kd = 0.0f,
    .pid_integral_limit = 4.0f,

    .control_period_s = 0.001f,
    .pwm_period = 4799,
};

dc_motor_datastructure motor_c_data(motor_c_config);
dc_motor motor_c_soft(motor_c_data);



/*--------------------drv8304_A_config------------------*/

cy_stc_sysint_t gpio_iqr_config = {
    .intrSrc = GPIO_GD_A_nFAULT_IRQ,
    .intrPriority = 1
};
cy_stc_sysint_t gpio_b_iqr_config = {
    .intrSrc = GPIO_GD_B_nFAULT_IRQ,
    .intrPriority = 1
};
hal_spi spi_gd_cfg_a(SPI_GD_CFG_HW,CY_SCB_SPI_SLAVE_SELECT2);
hal_spi spi_gd_cfg_b(SPI_GD_CFG_HW,CY_SCB_SPI_SLAVE_SELECT0);
hal_gpio pin_drv8304_a_enable(GPIO_GD_A_ENABLE_PORT,GPIO_GD_A_ENABLE_PIN);
hal_gpio pin_drv8304_a_nfault(GPIO_GD_A_nFAULT_PORT,GPIO_GD_A_nFAULT_PIN);
hal_gpio pin_drv8304_b_enable(GPIO_GD_B_ENABLE_PORT,GPIO_GD_B_ENABLE_PIN);
hal_gpio pin_drv8304_b_nfault(GPIO_GD_B_nFAULT_PORT,GPIO_GD_B_nFAULT_PIN);

drv8304 drv8304_a(spi_gd_cfg_a,pin_drv8304_a_enable,pin_drv8304_a_nfault);
drv8304 drv8304_b(spi_gd_cfg_b,pin_drv8304_b_enable,pin_drv8304_b_nfault);

 void drv8304_a_nfault_callback(const drv8304::StateTable &statetable,void* userptr);
 void drv8304_b_nfault_callback(const drv8304::StateTable &statetable,void* userptr);

/*--------------------drv8876_C_config------------------*/
cy_stc_sysint_t gpio_c_iqr_config = {
    .intrSrc = GPIO_GD_C_nFAULT_IRQ,
    .intrPriority = 1
};
hal_gpio pin_drv8876_c_nsleep(GPIO_GD_C_ENABLE_PORT,GPIO_GD_C_ENABLE_PIN);
hal_gpio pin_drv8876_c_nfault(GPIO_GD_C_nFAULT_PORT,GPIO_GD_C_nFAULT_PIN);

drv8876 drv8876_c(pin_drv8876_c_nsleep,pin_drv8876_c_nfault);

 void drv8876_c_nfault_callback(const drv8876::FaultState &state,void* userptr);

/*-----------------KTH7823_A_config----------------------*/
kth7823::regist_map enc_a_init_map =
{
    .ZERO_low = 0,
    .ZERO_high = 0,
    .GAINtirm = 0,
    .trim = 1u ,
    .ABZ_config = 0b01000000,
    .PPT = 0,
    .MGHL = 0b11001000,
    .NPP_cfg = 0,
    .ABZ_LIMIT = 0,
    .RD = 0b00000000,
};

hal_spi spi_enc_a(SPI_EC_A_HW);
kth7823 enc_a(enc_a_init_map,spi_enc_a);

/*-----------------KTH7823_B_config----------------------*/
kth7823::regist_map enc_b_init_map =
{
    .ZERO_low = 0,
    .ZERO_high = 0,
    .GAINtirm = 0,
    .trim = 1u ,
    .ABZ_config = 0b01000000,
    .PPT = 0,
    .MGHL = 0b11001000,
    .NPP_cfg = 0,
    .ABZ_LIMIT = 0,
    .RD = 0b00000000,
};

hal_spi spi_enc_b(SPI_EC_B_HW);
kth7823 enc_b(enc_b_init_map,spi_enc_b);

cy_stc_sysint_t motor_a_pwm_iqr_config = {
    .intrSrc = tcpwm_0_interrupts_256_IRQn,
    .intrPriority = 0,
};
hal_pwm pwm_a_u(PWM_A_U_HW, PWM_A_U_NUM);
hal_pwm pwm_a_v(PWM_A_V_HW, PWM_A_V_NUM);
hal_pwm pwm_a_w(PWM_A_W_HW, PWM_A_W_NUM);
hal_pwm pwm_start_a(PWM_START_A_HW, PWM_START_A_NUM);
motor_driver motor_a_driver(foc_A_soft, drv8304_a, enc_a, spi_enc_a, pwm_a_u, pwm_a_v, pwm_a_w, pwm_start_a, CY_HPPASS_INTR_SAR_RESULT_GROUP_0);
hal_pwm pwm_b_u(PWM_B_U_HW, PWM_B_U_NUM);
hal_pwm pwm_b_v(PWM_B_V_HW, PWM_B_V_NUM);
hal_pwm pwm_b_w(PWM_B_W_HW, PWM_B_W_NUM);
hal_pwm pwm_start_b(PWM_START_B_HW, PWM_START_B_NUM);
motor_driver motor_b_driver(foc_B_soft, drv8304_b, enc_b, spi_enc_b, pwm_b_u, pwm_b_v, pwm_b_w, pwm_start_b, CY_HPPASS_INTR_SAR_RESULT_GROUP_1);
hal_pwm pwm_c_u(PWM_C_U_HW, PWM_C_U_NUM);
hal_pwm pwm_c_v(PWM_C_V_HW, PWM_C_V_NUM);
hal_pwm pwm_start_c(PWM_START_C_HW, PWM_START_C_NUM);
dc_motor_driver motor_c_driver(motor_c_soft, pwm_c_u, pwm_c_v, pwm_start_c, CY_HPPASS_INTR_SAR_RESULT_GROUP_2);

/*-----------------SPI decode config----------------------*/
hal_spi spi_ctr(SPI_CTR_HW);
hal_gpio pin_ctr_int1(GPIO_CTR_INT1_PORT,GPIO_CTR_INT1_PIN);
hal_gpio pin_ctr_int2(GPIO_CTR_INT2_PORT,GPIO_CTR_INT2_PIN);
spi_decode spi_ctr_decode(spi_ctr,pin_ctr_int2,pin_ctr_int2);
cy_stc_sysint_t int_spi_ctl = 
{
    .intrSrc = SPI_CTR_IRQ,
    .intrPriority = 0x04 
};

cy_stc_sysint_t int_adc_motor_a_config = 
{
    .intrSrc = pass_interrupt_sar_entry_done_0_IRQn,
    .intrPriority = 0x01
};

cy_stc_sysint_t int_adc_motor_b_config = 
{
    .intrSrc = pass_interrupt_sar_entry_done_1_IRQn,
    .intrPriority = 0x01
};

cy_stc_sysint_t int_adc_motor_c_config = 
{
    .intrSrc = pass_interrupt_sar_entry_done_2_IRQn,
    .intrPriority = 0x01
};

/*----------------TIMER_TASK config----------------------*/
cy_stc_sysint_t int_timer_task_config = 
{
    .intrSrc = TIMER_TASK_IRQ,
    .intrPriority = 0x03
};

/*----------------ws2812--------------------------------*/
hal_spi spi_ws2812(SPI_LED_HW);

struct RGB
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
}RGB_light_color;

XL202RGBC ws2812(spi_ws2812);

/*----------------CommandDoer----------------------------*/
CommandDoer::CommandDoerState command_doer_state;
CommandDoer command_doer(command_doer_state, ws2812);

//test

hal_gpio gpio_for_test(GPIO_TEST_PORT,GPIO_TEST_PIN);
