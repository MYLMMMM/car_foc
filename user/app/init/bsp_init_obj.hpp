/*****
 * @brief this hpp can't be include by cpp except bsp_init.cpp
 */
#pragma once

#include "drv8304.hpp"
#include "kth7823.hpp"
#include "cybsp.h"
#include "foc_soft.hpp"
#include "endecode.hpp"
#include "hal.hpp"
#include "XL2020RGBC.hpp"
#include "motor.hpp"
#include "hal_counter_cy.hpp"
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
    .vbus_divider_ratio = 14.4f,
    .shunt_resistance = 0.050f,
    .current_sense_gain = 20.0f,

    .encoder_cpr = 65535,
    .pole_pairs = 14,
    .theta_elec_offset = 3.1247665451f,

    .pid_d_kp = -6.28f,
    .pid_d_ki = -1.0f,
    .pid_d_kd = 0.0f,
    .pid_d_integral_limit = 12.0f,
    .pid_q_kp = -6.28f,
    .pid_q_ki = -1.0f,
    .pid_q_kd = 0.0f,
    .pid_q_integral_limit = 12.0f,
    .pid_speed_kp = 0.015f,
    .pid_speed_ki = 0.0005f,
    .pid_speed_kd = 0.0f,
    .pid_speed_integral_limit = 0.8,
    .speed_lpf_fc = 50.0f,
    .speed_reverse = true,
    .speed_target_max = 300.0f,
    .speed_target_slope = 2.0f,
    .position_mode = true,
    .pid_position_kp = -30.0f,
    .pid_position_ki = -0.00f,
    .pid_position_kd = 0.0f,
    .pid_position_integral_limit = 25.0f,
    .control_period_s = 0.00005882f,

    .Ld = -0.002f,              
    .Lq = -0.002f,             
    .flux_linkage = -0.002f,   

    .pwm_period = 7000,
};

foc_motor_datastructure foc_motor_datastructure_A(foc_motor_datastructure_A_config);
foc foc_A_soft(foc_motor_datastructure_A);

/*--------------------drv8304_A_config------------------*/

cy_stc_sysint_t gpio_iqr_config = {
    .intrSrc = GPIO_GD_A_nFAULT_IRQ,
    .intrPriority = 0x04
};
hal_spi spi_gd_cfg_a(SPI_GD_CFG_HW,CY_SCB_SPI_SLAVE_SELECT2);
hal_gpio pin_drv8304_a_enable(GPIO_GD_A_ENABLE_PORT,GPIO_GD_A_ENABLE_PIN);
hal_gpio pin_drv8304_a_nfault(GPIO_GD_A_nFAULT_PORT,GPIO_GD_A_nFAULT_PIN);

drv8304 drv8304_a(spi_gd_cfg_a,pin_drv8304_a_enable,pin_drv8304_a_nfault);

 void drv8304_a_nfault_callback(const drv8304::StateTable &statetable,void* userptr);


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

cy_stc_sysint_t motor_a_pwm_iqr_config = {
    .intrSrc = tcpwm_0_interrupts_256_IRQn,
    .intrPriority = 0,
};
hal_pwm pwm_a_u(PWM_A_U_HW, PWM_A_U_NUM);
hal_pwm pwm_a_v(PWM_A_V_HW, PWM_A_V_NUM);
hal_pwm pwm_a_w(PWM_A_W_HW, PWM_A_W_NUM);
hal_pwm pwm_start_a(PWM_START_A_HW, PWM_START_A_NUM);
hal_counter speed_loop_a(PWM_SPEED_LOOP_A_HW, PWM_SPEED_LOOP_A_NUM);
motor_driver motor_a_driver(foc_A_soft, drv8304_a, enc_a, spi_enc_a, pwm_a_u, pwm_a_v, pwm_a_w, pwm_start_a, speed_loop_a, false, CY_HPPASS_INTR_SAR_RESULT_GROUP_0);

/*-----------------SPI decode config----------------------*/
hal_spi spi_ctr(SPI_CTR_HW);
hal_gpio pin_ctr_int1(GPIO_CTR_INT1_PORT,GPIO_CTR_INT1_PIN);
hal_gpio pin_ctr_int2(GPIO_CTR_INT2_PORT,GPIO_CTR_INT2_PIN);
spi_decode spi_ctr_decode(spi_ctr,pin_ctr_int2,pin_ctr_int2);
cy_stc_sysint_t int_spi_ctl = 
{
    .intrSrc = SPI_CTR_IRQ,
    .intrPriority = 0x02 
};

cy_stc_sysint_t int_adc_motor_a_config = 
{
    .intrSrc = pass_interrupt_sar_entry_done_0_IRQn,
    .intrPriority = 0x00
};

/*----------------SPEED_LOOP config----------------------*/
cy_stc_sysint_t int_speed_loop_a_config = 
{
    .intrSrc = PWM_SPEED_LOOP_A_IRQ,
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
