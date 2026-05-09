/*******************************************************************************
 * File Name: cycfg_peripherals.h
 *
 * Description:
 * Analog configuration
 * This file was automatically generated and should not be modified.
 * Configurator Backend 3.80.0
 * device-db 4.37.0.10260
 * mtb-pdl-cat1 3.20.1.45548
 *
 *******************************************************************************
 * Copyright 2026, Infineon Technologies AG, or an affiliate of Infineon
 * Technologies AG. All rights reserved.
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 ******************************************************************************/

#if !defined(CYCFG_PERIPHERALS_H)
#define CYCFG_PERIPHERALS_H

#include "cycfg_notices.h"
#include "cy_hppass.h"
#include "cy_sysint.h"
#include "cy_device.h"
#include "cy_scb_spi.h"
#include "cy_sysclk.h"
#include "cy_tcpwm_counter.h"
#include "cycfg_routing.h"
#include "cy_tcpwm_pwm.h"

#if defined (CY_USING_HAL)
#include "cyhal.h"
#include "cyhal_hwmgr.h"
#endif /* defined (CY_USING_HAL) */

#if defined (COMPONENT_MTB_HAL)
#include "mtb_hal.h"
#include "mtb_hal_hw_types.h"
#include "cycfg_clocks.h"
#endif /* defined (COMPONENT_MTB_HAL) */

#if defined (CY_USING_HAL_LITE)
#include "cyhal_hw_types.h"
#endif /* defined (CY_USING_HAL_LITE) */

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

#define pass_0_ENABLED 1U
#define motor_a_trig_ENABLED 1U
#define motor_a_trig_IDX 0U
#define motor_b_trig_ENABLED 1U
#define motor_b_trig_IDX 1U
#define motor_c_trig_ENABLED 1U
#define motor_c_trig_IDX 2U
#define pass_0_sar_0_ENABLED 1U
#define pass_0_sar_0_VREF 3000U
#define ADC_VBUS_CH_ENABLED 1U
#define ADC_VBUS_CH_RSLT_PTR CY_HPPASS_SAR_CHAN_RSLT_PTR(0U)
#define ADC_VBUS_CH_FIR_CHAN_IDX CY_HPPASS_FIR_CHAN_0
#define ADC_VBUS_CH_CHAN_IDX 0U
#define AN_A0_CHAN_IDX 0U
#define ADC_A_IW_CH_ENABLED 1U
#define ADC_A_IW_CH_RSLT_PTR CY_HPPASS_SAR_CHAN_RSLT_PTR(1U)
#define ADC_A_IW_CH_FIR_CHAN_IDX CY_HPPASS_FIR_CHAN_1
#define ADC_A_IW_CH_CHAN_IDX 1U
#define AN_A1_CHAN_IDX 1U
#define ADC_A_IV_CH_ENABLED 1U
#define ADC_A_IV_CH_RSLT_PTR CY_HPPASS_SAR_CHAN_RSLT_PTR(2U)
#define ADC_A_IV_CH_FIR_CHAN_IDX CY_HPPASS_FIR_CHAN_2
#define ADC_A_IV_CH_CHAN_IDX 2U
#define AN_A2_CHAN_IDX 2U
#define ADC_A_IU_CH_ENABLED 1U
#define ADC_A_IU_CH_RSLT_PTR CY_HPPASS_SAR_CHAN_RSLT_PTR(3U)
#define ADC_A_IU_CH_FIR_CHAN_IDX CY_HPPASS_FIR_CHAN_3
#define ADC_A_IU_CH_CHAN_IDX 3U
#define AN_A3_CHAN_IDX 3U
#define ADC_B_IU_CH_ENABLED 1U
#define ADC_B_IU_CH_RSLT_PTR CY_HPPASS_SAR_CHAN_RSLT_PTR(4U)
#define ADC_B_IU_CH_FIR_CHAN_IDX CY_HPPASS_FIR_CHAN_4
#define ADC_B_IU_CH_CHAN_IDX 4U
#define AN_A4_CHAN_IDX 4U
#define ADC_B_IV_CH_ENABLED 1U
#define ADC_B_IV_CH_RSLT_PTR CY_HPPASS_SAR_CHAN_RSLT_PTR(5U)
#define ADC_B_IV_CH_FIR_CHAN_IDX CY_HPPASS_FIR_CHAN_5
#define ADC_B_IV_CH_CHAN_IDX 5U
#define AN_A5_CHAN_IDX 5U
#define ADC_B_IW_CH_ENABLED 1U
#define ADC_B_IW_CH_RSLT_PTR CY_HPPASS_SAR_CHAN_RSLT_PTR(6U)
#define ADC_B_IW_CH_FIR_CHAN_IDX CY_HPPASS_FIR_CHAN_6
#define ADC_B_IW_CH_CHAN_IDX 6U
#define AN_A6_CHAN_IDX 6U
#define ADC_C_I_CH_ENABLED 1U
#define ADC_C_I_CH_RSLT_PTR CY_HPPASS_SAR_CHAN_RSLT_PTR(7U)
#define ADC_C_I_CH_FIR_CHAN_IDX CY_HPPASS_FIR_CHAN_7
#define ADC_C_I_CH_CHAN_IDX 7U
#define AN_A7_CHAN_IDX 7U
#define ADC_VBUS_SAM_ENABLED 1U
#define ADC_A_IW_SAM_ENABLED 1U
#define ADC_A_IV_SAM_ENABLED 1U
#define ADC_A_IU_SAM_ENABLED 1U
#define ADC_B_IU_SAM_ENABLED 1U
#define ADC_B_IV_SAM_ENABLED 1U
#define ADC_B_IW_SA_ENABLED 1U
#define ADC_C_I_SAM_ENABLED 1U
#define pass_0_ac_0_stt_0_vstate_0_ENABLED 1U
#define motor_a_group_ENABLED 1U
#define motor_b_group_ENABLED 1U
#define motor_c_group_ENABLED 1U
#define pass_0_ac_0_ENABLED 1U
#define debug600_0_ENABLED 1U
#define SPI_GD_CFG_ENABLED 1U
#define SPI_GD_CFG_HW SCB0
#define SPI_GD_CFG_IRQ scb_0_interrupt_IRQn
#define SPI_EC_B_ENABLED 1U
#define SPI_EC_B_HW SCB1
#define SPI_EC_B_IRQ scb_1_interrupt_IRQn
#define SPI_LED_ENABLED 1U
#define SPI_LED_HW SCB2
#define SPI_LED_IRQ scb_2_interrupt_IRQn
#define SPI_EC_A_ENABLED 1U
#define SPI_EC_A_HW SCB3
#define SPI_EC_A_IRQ scb_3_interrupt_IRQn
#define SPI_CTR_ENABLED 1U
#define SPI_CTR_HW SCB5
#define SPI_CTR_IRQ scb_5_interrupt_IRQn
#define TIMER_TASK_ENABLED 1U
#define TIMER_TASK_HW TCPWM0
#define TIMER_TASK_NUM 0UL
#define TIMER_TASK_IRQ tcpwm_0_interrupts_0_IRQn
#define PWM_C_U_ENABLED 1U
#define PWM_C_U_HW TCPWM0
#define PWM_C_U_NUM 1UL
#define PWM_C_V_ENABLED 1U
#define PWM_C_V_HW TCPWM0
#define PWM_C_V_NUM 2UL
#define PWM_START_C_ENABLED 1U
#define PWM_START_C_HW TCPWM0
#define PWM_START_C_NUM 3UL
#define PWM_A_U_ENABLED 1U
#define PWM_A_U_HW TCPWM0
#define PWM_A_U_NUM 256UL
#define PWM_A_V_ENABLED 1U
#define PWM_A_V_HW TCPWM0
#define PWM_A_V_NUM 257UL
#define PWM_A_W_ENABLED 1U
#define PWM_A_W_HW TCPWM0
#define PWM_A_W_NUM 258UL
#define PWM_B_U_ENABLED 1U
#define PWM_B_U_HW TCPWM0
#define PWM_B_U_NUM 259UL
#define PWM_B_V_ENABLED 1U
#define PWM_B_V_HW TCPWM0
#define PWM_B_V_NUM 260UL
#define PWM_B_W_ENABLED 1U
#define PWM_B_W_HW TCPWM0
#define PWM_B_W_NUM 261UL
#define PWM_START_A_ENABLED 1U
#define PWM_START_A_HW TCPWM0
#define PWM_START_A_NUM 262UL
#define PWM_START_A_IRQ tcpwm_0_interrupts_262_IRQn
#define PWM_START_B_ENABLED 1U
#define PWM_START_B_HW TCPWM0
#define PWM_START_B_NUM 263UL
#define PWM_START_B_IRQ tcpwm_0_interrupts_263_IRQn

extern const cy_stc_hppass_cfg_t pass_0_config;

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t pass_0_adc_hal_obj;
extern const cyhal_adc_configurator_t pass_0_adc_hal_config;
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_ADC)
extern const mtb_hal_adc_configurator_t pass_0_adc_hal_config;
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_ADC) */

extern const cy_stc_hppass_sar_t pass_0_sar_0_config;
extern const cy_stc_hppass_ac_stt_t pass_0_ac_0_stt_0_config[];
extern const cy_stc_hppass_sar_chan_t ADC_VBUS_CH_config;
extern const cy_stc_hppass_sar_chan_t ADC_A_IW_CH_config;
extern const cy_stc_hppass_sar_chan_t ADC_A_IV_CH_config;
extern const cy_stc_hppass_sar_chan_t ADC_A_IU_CH_config;
extern const cy_stc_hppass_sar_chan_t ADC_B_IU_CH_config;
extern const cy_stc_hppass_sar_chan_t ADC_B_IV_CH_config;
extern const cy_stc_hppass_sar_chan_t ADC_B_IW_CH_config;
extern const cy_stc_hppass_sar_chan_t ADC_C_I_CH_config;
extern const cy_stc_hppass_sar_grp_t motor_a_group_config;
extern const cy_stc_hppass_sar_grp_t motor_b_group_config;
extern const cy_stc_hppass_sar_grp_t motor_c_group_config;
extern const cy_stc_scb_spi_config_t SPI_GD_CFG_config;

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t SPI_GD_CFG_obj;
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

#if defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL)
extern const cyhal_clock_t SPI_GD_CFG_clock;
#endif /* defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL) */

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
extern const cyhal_spi_configurator_t SPI_GD_CFG_hal_config;
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

#if defined (COMPONENT_MTB_HAL)
extern const mtb_hal_peri_div_t SPI_GD_CFG_clock_ref;
extern const mtb_hal_clock_t SPI_GD_CFG_hal_clock;
#endif /* defined (COMPONENT_MTB_HAL) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_SPI)
extern const mtb_hal_spi_configurator_t SPI_GD_CFG_hal_config;
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_SPI) */

extern const cy_stc_scb_spi_config_t SPI_EC_B_config;

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t SPI_EC_B_obj;
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

#if defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL)
extern const cyhal_clock_t SPI_EC_B_clock;
#endif /* defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL) */

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
extern const cyhal_spi_configurator_t SPI_EC_B_hal_config;
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

#if defined (COMPONENT_MTB_HAL)
extern const mtb_hal_peri_div_t SPI_EC_B_clock_ref;
extern const mtb_hal_clock_t SPI_EC_B_hal_clock;
#endif /* defined (COMPONENT_MTB_HAL) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_SPI)
extern const mtb_hal_spi_configurator_t SPI_EC_B_hal_config;
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_SPI) */

extern const cy_stc_scb_spi_config_t SPI_LED_config;

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t SPI_LED_obj;
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

#if defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL)
extern const cyhal_clock_t SPI_LED_clock;
#endif /* defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL) */

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
extern const cyhal_spi_configurator_t SPI_LED_hal_config;
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

#if defined (COMPONENT_MTB_HAL)
extern const mtb_hal_peri_div_t SPI_LED_clock_ref;
extern const mtb_hal_clock_t SPI_LED_hal_clock;
#endif /* defined (COMPONENT_MTB_HAL) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_SPI)
extern const mtb_hal_spi_configurator_t SPI_LED_hal_config;
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_SPI) */

extern const cy_stc_scb_spi_config_t SPI_EC_A_config;

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t SPI_EC_A_obj;
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

#if defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL)
extern const cyhal_clock_t SPI_EC_A_clock;
#endif /* defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL) */

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
extern const cyhal_spi_configurator_t SPI_EC_A_hal_config;
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

#if defined (COMPONENT_MTB_HAL)
extern const mtb_hal_peri_div_t SPI_EC_A_clock_ref;
extern const mtb_hal_clock_t SPI_EC_A_hal_clock;
#endif /* defined (COMPONENT_MTB_HAL) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_SPI)
extern const mtb_hal_spi_configurator_t SPI_EC_A_hal_config;
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_SPI) */

extern const cy_stc_scb_spi_config_t SPI_CTR_config;

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t SPI_CTR_obj;
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

#if defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL)
extern const cyhal_clock_t SPI_CTR_clock;
#endif /* defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL) */

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
extern const cyhal_spi_configurator_t SPI_CTR_hal_config;
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

#if defined (COMPONENT_MTB_HAL)
extern const mtb_hal_peri_div_t SPI_CTR_clock_ref;
extern const mtb_hal_clock_t SPI_CTR_hal_clock;
#endif /* defined (COMPONENT_MTB_HAL) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_SPI)
extern const mtb_hal_spi_configurator_t SPI_CTR_hal_config;
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_SPI) */

extern const cy_stc_tcpwm_counter_config_t TIMER_TASK_config;

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t TIMER_TASK_obj;
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

#if defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL)
extern const cyhal_clock_t TIMER_TASK_clock;
#endif /* defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL) */

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
extern const cyhal_timer_configurator_t TIMER_TASK_hal_config;
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

#if defined (COMPONENT_MTB_HAL)
extern const mtb_hal_peri_div_t TIMER_TASK_clock_ref;
extern const mtb_hal_clock_t TIMER_TASK_hal_clock;
#endif /* defined (COMPONENT_MTB_HAL) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_TIMER)
extern const mtb_hal_timer_configurator_t TIMER_TASK_hal_config;
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_TIMER) */

extern const cy_stc_tcpwm_pwm_config_t PWM_C_U_config;

#if defined (COMPONENT_MTB_HAL)
extern const mtb_hal_peri_div_t PWM_C_U_clock_ref;
extern const mtb_hal_clock_t PWM_C_U_hal_clock;
#endif /* defined (COMPONENT_MTB_HAL) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM)
extern const mtb_hal_pwm_configurator_t PWM_C_U_hal_config;
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM) */

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t PWM_C_U_obj;
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

#if defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL)
extern const cyhal_clock_t PWM_C_U_clock;
#endif /* defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL) */

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
extern const cyhal_pwm_configurator_t PWM_C_U_hal_config;
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

extern const cy_stc_tcpwm_pwm_config_t PWM_C_V_config;

#if defined (COMPONENT_MTB_HAL)
extern const mtb_hal_peri_div_t PWM_C_V_clock_ref;
extern const mtb_hal_clock_t PWM_C_V_hal_clock;
#endif /* defined (COMPONENT_MTB_HAL) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM)
extern const mtb_hal_pwm_configurator_t PWM_C_V_hal_config;
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM) */

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t PWM_C_V_obj;
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

#if defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL)
extern const cyhal_clock_t PWM_C_V_clock;
#endif /* defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL) */

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
extern const cyhal_pwm_configurator_t PWM_C_V_hal_config;
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

extern const cy_stc_tcpwm_pwm_config_t PWM_START_C_config;

#if defined (COMPONENT_MTB_HAL)
extern const mtb_hal_peri_div_t PWM_START_C_clock_ref;
extern const mtb_hal_clock_t PWM_START_C_hal_clock;
#endif /* defined (COMPONENT_MTB_HAL) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM)
extern const mtb_hal_pwm_configurator_t PWM_START_C_hal_config;
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM) */

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t PWM_START_C_obj;
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

#if defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL)
extern const cyhal_clock_t PWM_START_C_clock;
#endif /* defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL) */

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
extern const cyhal_pwm_configurator_t PWM_START_C_hal_config;
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

extern const cy_stc_tcpwm_pwm_config_t PWM_A_U_config;

#if defined (COMPONENT_MTB_HAL)
extern const mtb_hal_peri_div_t PWM_A_U_clock_ref;
extern const mtb_hal_clock_t PWM_A_U_hal_clock;
#endif /* defined (COMPONENT_MTB_HAL) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM)
extern const mtb_hal_pwm_configurator_t PWM_A_U_hal_config;
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM) */

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t PWM_A_U_obj;
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

#if defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL)
extern const cyhal_clock_t PWM_A_U_clock;
#endif /* defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL) */

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
extern const cyhal_pwm_configurator_t PWM_A_U_hal_config;
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

extern const cy_stc_tcpwm_pwm_config_t PWM_A_V_config;

#if defined (COMPONENT_MTB_HAL)
extern const mtb_hal_peri_div_t PWM_A_V_clock_ref;
extern const mtb_hal_clock_t PWM_A_V_hal_clock;
#endif /* defined (COMPONENT_MTB_HAL) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM)
extern const mtb_hal_pwm_configurator_t PWM_A_V_hal_config;
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM) */

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t PWM_A_V_obj;
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

#if defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL)
extern const cyhal_clock_t PWM_A_V_clock;
#endif /* defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL) */

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
extern const cyhal_pwm_configurator_t PWM_A_V_hal_config;
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

extern const cy_stc_tcpwm_pwm_config_t PWM_A_W_config;

#if defined (COMPONENT_MTB_HAL)
extern const mtb_hal_peri_div_t PWM_A_W_clock_ref;
extern const mtb_hal_clock_t PWM_A_W_hal_clock;
#endif /* defined (COMPONENT_MTB_HAL) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM)
extern const mtb_hal_pwm_configurator_t PWM_A_W_hal_config;
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM) */

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t PWM_A_W_obj;
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

#if defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL)
extern const cyhal_clock_t PWM_A_W_clock;
#endif /* defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL) */

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
extern const cyhal_pwm_configurator_t PWM_A_W_hal_config;
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

extern const cy_stc_tcpwm_pwm_config_t PWM_B_U_config;

#if defined (COMPONENT_MTB_HAL)
extern const mtb_hal_peri_div_t PWM_B_U_clock_ref;
extern const mtb_hal_clock_t PWM_B_U_hal_clock;
#endif /* defined (COMPONENT_MTB_HAL) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM)
extern const mtb_hal_pwm_configurator_t PWM_B_U_hal_config;
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM) */

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t PWM_B_U_obj;
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

#if defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL)
extern const cyhal_clock_t PWM_B_U_clock;
#endif /* defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL) */

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
extern const cyhal_pwm_configurator_t PWM_B_U_hal_config;
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

extern const cy_stc_tcpwm_pwm_config_t PWM_B_V_config;

#if defined (COMPONENT_MTB_HAL)
extern const mtb_hal_peri_div_t PWM_B_V_clock_ref;
extern const mtb_hal_clock_t PWM_B_V_hal_clock;
#endif /* defined (COMPONENT_MTB_HAL) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM)
extern const mtb_hal_pwm_configurator_t PWM_B_V_hal_config;
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM) */

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t PWM_B_V_obj;
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

#if defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL)
extern const cyhal_clock_t PWM_B_V_clock;
#endif /* defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL) */

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
extern const cyhal_pwm_configurator_t PWM_B_V_hal_config;
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

extern const cy_stc_tcpwm_pwm_config_t PWM_B_W_config;

#if defined (COMPONENT_MTB_HAL)
extern const mtb_hal_peri_div_t PWM_B_W_clock_ref;
extern const mtb_hal_clock_t PWM_B_W_hal_clock;
#endif /* defined (COMPONENT_MTB_HAL) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM)
extern const mtb_hal_pwm_configurator_t PWM_B_W_hal_config;
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM) */

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t PWM_B_W_obj;
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

#if defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL)
extern const cyhal_clock_t PWM_B_W_clock;
#endif /* defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL) */

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
extern const cyhal_pwm_configurator_t PWM_B_W_hal_config;
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

extern const cy_stc_tcpwm_pwm_config_t PWM_START_A_config;

#if defined (COMPONENT_MTB_HAL)
extern const mtb_hal_peri_div_t PWM_START_A_clock_ref;
extern const mtb_hal_clock_t PWM_START_A_hal_clock;
#endif /* defined (COMPONENT_MTB_HAL) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM)
extern const mtb_hal_pwm_configurator_t PWM_START_A_hal_config;
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM) */

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t PWM_START_A_obj;
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

#if defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL)
extern const cyhal_clock_t PWM_START_A_clock;
#endif /* defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL) */

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
extern const cyhal_pwm_configurator_t PWM_START_A_hal_config;
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

extern const cy_stc_tcpwm_pwm_config_t PWM_START_B_config;

#if defined (COMPONENT_MTB_HAL)
extern const mtb_hal_peri_div_t PWM_START_B_clock_ref;
extern const mtb_hal_clock_t PWM_START_B_hal_clock;
#endif /* defined (COMPONENT_MTB_HAL) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM)
extern const mtb_hal_pwm_configurator_t PWM_START_B_hal_config;
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM) */

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t PWM_START_B_obj;
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

#if defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL)
extern const cyhal_clock_t PWM_START_B_clock;
#endif /* defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL) */

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
extern const cyhal_pwm_configurator_t PWM_START_B_hal_config;
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

void pass_0_start(void);
void init_cycfg_peripherals(void);
void reserve_cycfg_peripherals(void);

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* CYCFG_PERIPHERALS_H */
