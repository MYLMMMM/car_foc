/*******************************************************************************
 * File Name: cycfg_routing.h
 *
 * Description:
 * Establishes all necessary connections between hardware elements.
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

#if !defined(CYCFG_ROUTING_H)
#define CYCFG_ROUTING_H

#include "cycfg_notices.h"

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

#define ioss_0_port_0_pin_0_HSIOM P0_0_SRSS_EXT_CLK
#define ioss_0_port_1_pin_0_HSIOM P1_0_PERI_TR_IO_INPUT2
#define ioss_0_port_1_pin_2_HSIOM P1_2_DEBUG600_CLK_SWJ_SWCLK_TCLK
#define ioss_0_port_1_pin_3_HSIOM P1_3_DEBUG600_SWJ_SWDIO_TMS
#define ioss_0_port_2_pin_0_HSIOM P2_0_SCB1_SPI_SELECT0
#define ioss_0_port_2_pin_1_HSIOM P2_1_SCB1_SPI_CLK
#define ioss_0_port_2_pin_2_HSIOM P2_2_SCB1_SPI_MOSI
#define ioss_0_port_2_pin_3_HSIOM P2_3_SCB1_SPI_MISO
#define ioss_0_port_3_pin_0_HSIOM P3_0_PERI_TR_IO_OUTPUT10
#define ioss_0_port_3_pin_1_HSIOM P3_1_PERI_TR_IO_OUTPUT11
#define ioss_0_port_3_pin_2_HSIOM P3_2_PERI_TR_IO_OUTPUT12
#define ioss_0_port_3_pin_3_HSIOM P3_3_PERI_TR_IO_OUTPUT13
#define ioss_0_port_4_pin_0_HSIOM P4_0_PERI_TR_IO_OUTPUT14
#define ioss_0_port_4_pin_1_HSIOM P4_1_PERI_TR_IO_OUTPUT15
#define ioss_0_port_5_pin_0_HSIOM P5_0_SCB3_SPI_MOSI
#define ioss_0_port_5_pin_1_HSIOM P5_1_SCB3_SPI_MISO
#define ioss_0_port_5_pin_2_HSIOM P5_2_SCB3_SPI_CLK
#define ioss_0_port_5_pin_3_HSIOM P5_3_SCB3_SPI_SELECT0
#define ioss_0_port_6_pin_2_HSIOM P6_2_PERI_TR_IO_OUTPUT28
#define ioss_0_port_7_pin_1_HSIOM P7_1_SCB2_SPI_MOSI
#define ioss_0_port_8_pin_0_HSIOM P8_0_SCB5_SPI_SELECT0
#define ioss_0_port_8_pin_1_HSIOM P8_1_SCB5_SPI_MOSI
#define ioss_0_port_8_pin_2_HSIOM P8_2_SCB5_SPI_MISO
#define ioss_0_port_8_pin_3_HSIOM P8_3_SCB5_SPI_CLK
#define ioss_0_port_9_pin_0_HSIOM P9_0_SCB0_SPI_CLK
#define ioss_0_port_9_pin_1_HSIOM P9_1_SCB0_SPI_SELECT0
#define ioss_0_port_9_pin_2_HSIOM P9_2_SCB0_SPI_MOSI
#define ioss_0_port_9_pin_3_HSIOM P9_3_SCB0_SPI_MISO
#define ioss_0_port_9_pin_4_HSIOM P9_4_SCB0_SPI_SELECT1
#define ioss_0_port_9_pin_5_HSIOM P9_5_SCB0_SPI_SELECT2
#define debug600_0_cti_tr_out_0_TRIGGER_IN TRIG_IN_MUX_8_CTI_TR_OUT0
#define DMA_EC_A_RX_tr_in_0_TRIGGER_OUT TRIG_OUT_MUX_0_PDMA0_TR_IN14
#define DMA_PWM_CC_A_U_1_tr_in_0_TRIGGER_OUT TRIG_OUT_MUX_1_PDMA1_TR_IN0
#define DMA_PWM_CC_A_U_2_tr_in_0_TRIGGER_OUT TRIG_OUT_MUX_1_PDMA1_TR_IN6
#define DMA_PWM_CC_A_V_1_tr_in_0_TRIGGER_OUT TRIG_OUT_MUX_1_PDMA1_TR_IN1
#define DMA_PWM_CC_A_V_2_tr_in_0_TRIGGER_OUT TRIG_OUT_MUX_1_PDMA1_TR_IN7
#define DMA_PWM_CC_A_W_1_tr_in_0_TRIGGER_OUT TRIG_OUT_MUX_1_PDMA1_TR_IN2
#define DMA_PWM_CC_A_W_2_tr_in_0_TRIGGER_OUT TRIG_OUT_MUX_1_PDMA1_TR_IN8
#define GPIO_GD_B_ENABLE_digital_out_0_TRIGGER_OUT TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT15
#define GPIO_GD_B_nFAULT_digital_out_0_TRIGGER_OUT TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT14
#define GPIO_GD_C_ENABLE_digital_out_0_TRIGGER_OUT TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT12
#define GPIO_GD_C_nFAULT_digital_out_0_TRIGGER_OUT TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT13
#define ioss_0_port_1_pin_0_digital_in_0_TRIGGER_IN TRIG_IN_MUX_11_HSIOM_TR_OUT2
#define ioss_0_port_3_pin_0_digital_out_0_TRIGGER_OUT TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT10
#define ioss_0_port_3_pin_1_digital_out_0_TRIGGER_OUT TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT11
#define ioss_0_port_6_pin_2_digital_out_0_TRIGGER_OUT TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT28
#define motor_a_trig_tr_a_in_0_TRIGGER_OUT TRIG_OUT_MUX_14_PASS_TR_A_IN0
#define PWM_A_U_start_0_TRIGGER_OUT TRIG_OUT_MUX_12_TCPWM0_GRP1_CNT0_TR4_IN
#define PWM_A_U_stop_0_TRIGGER_OUT TRIG_OUT_MUX_11_TCPWM0_GRP1_CNT0_TR3_IN
#define PWM_A_U_tr_debug_freeze_0_TRIGGER_OUT TRIG_OUT_MUX_8_TCPWM_DEBUG_FREEZE_TR_IN
#define PWM_A_U_tr_line_0_TRIGGER_IN TRIG_IN_MUX_2_TCPWM0_GRP1_LINE_256
#define PWM_A_U_tr_line_compl_0_TRIGGER_IN TRIG_IN_MUX_2_TCPWM0_GRP1_LINE_COMPL_256
#define PWM_A_U_tr_out0_0_TRIGGER_IN TRIG_IN_MUX_1_TCPWM0_GRP1_OUT0_0
#define PWM_A_U_tr_out1_0_TRIGGER_IN_0 TRIG_IN_MUX_14_TCPWM0_GRP1_OUT1_0
#define PWM_A_U_tr_out1_0_TRIGGER_IN_1 TRIG_IN_MUX_2_TCPWM0_GRP1_OUT1_0
#define PWM_A_V_start_0_TRIGGER_OUT TRIG_OUT_MUX_12_TCPWM0_GRP1_CNT1_TR4_IN
#define PWM_A_V_tr_debug_freeze_0_TRIGGER_OUT TRIG_OUT_MUX_8_TCPWM_DEBUG_FREEZE_TR_IN
#define PWM_A_V_tr_line_0_TRIGGER_IN TRIG_IN_MUX_2_TCPWM0_GRP1_LINE_257
#define PWM_A_V_tr_line_compl_0_TRIGGER_IN TRIG_IN_MUX_2_TCPWM0_GRP1_LINE_COMPL_257
#define PWM_A_W_start_0_TRIGGER_OUT TRIG_OUT_MUX_12_TCPWM0_GRP1_CNT2_TR4_IN
#define PWM_A_W_tr_debug_freeze_0_TRIGGER_OUT TRIG_OUT_MUX_8_TCPWM_DEBUG_FREEZE_TR_IN
#define PWM_A_W_tr_line_0_TRIGGER_IN TRIG_IN_MUX_2_TCPWM0_GRP1_LINE_258
#define PWM_A_W_tr_line_compl_0_TRIGGER_IN TRIG_IN_MUX_2_TCPWM0_GRP1_LINE_COMPL_258
#define PWM_SPEED_LOOP_A_start_0_TRIGGER_OUT TRIG_OUT_MUX_12_TCPWM0_GRP2_CNT0_TR4_IN
#define PWM_START_A_tr_out0_0_TRIGGER_IN TRIG_IN_MUX_12_TCPWM0_GRP1_OUT0_6
#define SPI_EC_A_tr_rx_req_0_TRIGGER_IN TRIG_IN_MUX_0_SCB_RX1
#define TCPWM0_GRP1_CNT0_START_VALUE 0x4
#define TCPWM0_GRP1_CNT0_STOP_VALUE 0x3
#define TCPWM0_GRP1_CNT1_START_VALUE 0x4
#define TCPWM0_GRP1_CNT2_START_VALUE 0x4
#define TCPWM0_GRP2_CNT0_START_VALUE 0x4

void init_cycfg_routing(void);

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* CYCFG_ROUTING_H */
