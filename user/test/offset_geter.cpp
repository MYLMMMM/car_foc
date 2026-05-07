// #include "cybsp.h"
// #include "bsp_init.hpp"
// #include "endecode.hpp"

// uint16_t val = 50;
// uint8_t state = 0;
// uint16_t adc = 0;
// void step_test();

// void offset_get()
// {
//     bsp_init();//hardware init

//     Cy_TCPWM_TriggerStart_Single(PWM_START_A_HW,PWM_START_A_NUM);
//     enc_a.start_yaw_data_transfer();
//     while (1)
//     {
//         // step_test();

//         Cy_TCPWM_PWM_SetCompare0(PWM_A_U_HW,PWM_A_U_NUM,val);
//         Cy_TCPWM_PWM_SetCompare1(PWM_A_U_HW,PWM_A_U_NUM,val);
//         Cy_TCPWM_PWM_SetCompare0(PWM_A_U_HW,PWM_A_V_NUM,val);
//         Cy_TCPWM_PWM_SetCompare1(PWM_A_U_HW,PWM_A_V_NUM,val);
//         drv8304_a.refresh_fault_status();
//         drv8304_a.clear_faults();
//         ws2812.set_color(5,0,0); 
//         motor_a_driver.ec_isr();
//         motor_a_driver.encoder_mean_filter_.trig();
//         // adc = *motor_a_driver.foc_soft_.motor.adc_a;
//         // adc = *(volatile int32_t*)CY_HPPASS_SAR_CHAN_RSLT_PTR(ADC_A_IU_CH_CHAN_IDX);
//         CyDelay(5);
//     }

// }

// void step_test()
// {
//     switch (state)
//             {
//             case 0:
//                 Cy_TCPWM_PWM_SetCompare0(PWM_A_U_HW,PWM_A_U_NUM,val);
//                 Cy_TCPWM_PWM_SetCompare1(PWM_A_U_HW,PWM_A_U_NUM,val);
//                 Cy_TCPWM_PWM_SetCompare0(PWM_A_U_HW,PWM_A_V_NUM,0);
//                 Cy_TCPWM_PWM_SetCompare1(PWM_A_U_HW,PWM_A_V_NUM,0);
//                 Cy_TCPWM_PWM_SetCompare0(PWM_A_U_HW,PWM_A_W_NUM,0);
//                 Cy_TCPWM_PWM_SetCompare1(PWM_A_U_HW,PWM_A_W_NUM,0);
//                 state = 1;
//                 break;
//             case 1:
//                 Cy_TCPWM_PWM_SetCompare0(PWM_A_U_HW,PWM_A_U_NUM,val);
//                 Cy_TCPWM_PWM_SetCompare1(PWM_A_U_HW,PWM_A_U_NUM,val);
//                 Cy_TCPWM_PWM_SetCompare0(PWM_A_U_HW,PWM_A_V_NUM,val);
//                 Cy_TCPWM_PWM_SetCompare1(PWM_A_U_HW,PWM_A_V_NUM,val);
//                 Cy_TCPWM_PWM_SetCompare0(PWM_A_U_HW,PWM_A_W_NUM,0);
//                 Cy_TCPWM_PWM_SetCompare1(PWM_A_U_HW,PWM_A_W_NUM,0);
//                 state = 2;
//                 break;
//             case 2:
//                 Cy_TCPWM_PWM_SetCompare0(PWM_A_U_HW,PWM_A_U_NUM,0);
//                 Cy_TCPWM_PWM_SetCompare1(PWM_A_U_HW,PWM_A_U_NUM,0);
//                 Cy_TCPWM_PWM_SetCompare0(PWM_A_U_HW,PWM_A_V_NUM,val);
//                 Cy_TCPWM_PWM_SetCompare1(PWM_A_U_HW,PWM_A_V_NUM,val);
//                 Cy_TCPWM_PWM_SetCompare0(PWM_A_U_HW,PWM_A_W_NUM,0);
//                 Cy_TCPWM_PWM_SetCompare1(PWM_A_U_HW,PWM_A_W_NUM,0);
//                 state = 3;
//                 break;
//             case 3:
//                 Cy_TCPWM_PWM_SetCompare0(PWM_A_U_HW,PWM_A_U_NUM,0);
//                 Cy_TCPWM_PWM_SetCompare1(PWM_A_U_HW,PWM_A_U_NUM,0);
//                 Cy_TCPWM_PWM_SetCompare0(PWM_A_U_HW,PWM_A_V_NUM,val);
//                 Cy_TCPWM_PWM_SetCompare1(PWM_A_U_HW,PWM_A_V_NUM,val);
//                 Cy_TCPWM_PWM_SetCompare0(PWM_A_U_HW,PWM_A_W_NUM,val);
//                 Cy_TCPWM_PWM_SetCompare1(PWM_A_U_HW,PWM_A_W_NUM,val);
//                 state = 4;
//                 break;
//             case 4:
//                 Cy_TCPWM_PWM_SetCompare0(PWM_A_U_HW,PWM_A_U_NUM,0);
//                 Cy_TCPWM_PWM_SetCompare1(PWM_A_U_HW,PWM_A_U_NUM,0);
//                 Cy_TCPWM_PWM_SetCompare0(PWM_A_U_HW,PWM_A_V_NUM,0);
//                 Cy_TCPWM_PWM_SetCompare1(PWM_A_U_HW,PWM_A_V_NUM,0);
//                 Cy_TCPWM_PWM_SetCompare0(PWM_A_U_HW,PWM_A_W_NUM,val);
//                 Cy_TCPWM_PWM_SetCompare1(PWM_A_U_HW,PWM_A_W_NUM,val);
//                 state = 5;
//                 break;
//             case 5:
//                 Cy_TCPWM_PWM_SetCompare0(PWM_A_U_HW,PWM_A_U_NUM,val);
//                 Cy_TCPWM_PWM_SetCompare1(PWM_A_U_HW,PWM_A_U_NUM,val);
//                 Cy_TCPWM_PWM_SetCompare0(PWM_A_U_HW,PWM_A_V_NUM,0);
//                 Cy_TCPWM_PWM_SetCompare1(PWM_A_U_HW,PWM_A_V_NUM,0);
//                 Cy_TCPWM_PWM_SetCompare0(PWM_A_U_HW,PWM_A_W_NUM,val);
//                 Cy_TCPWM_PWM_SetCompare1(PWM_A_U_HW,PWM_A_W_NUM,val);
//                 state = 0;
//                 break;

//             default:
//                 break;
//             }
// }