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

#define ioss_0_port_0_pin_0_HSIOM P0_0_PERI_TR_IO_INPUT0
#define ioss_0_port_1_pin_2_HSIOM P1_2_DEBUG600_CLK_SWJ_SWCLK_TCLK
#define ioss_0_port_1_pin_3_HSIOM P1_3_DEBUG600_SWJ_SWDIO_TMS
#define ioss_0_port_2_pin_0_HSIOM P2_0_SCB1_SPI_SELECT0
#define ioss_0_port_2_pin_1_HSIOM P2_1_SCB1_SPI_CLK
#define ioss_0_port_2_pin_2_HSIOM P2_2_SCB1_SPI_MOSI
#define ioss_0_port_2_pin_3_HSIOM P2_3_SCB1_SPI_MISO
#define ioss_0_port_3_pin_0_HSIOM P3_0_PERI_TR_IO_OUTPUT10
#define ioss_0_port_3_pin_1_HSIOM P3_1_PERI_TR_IO_OUTPUT11
#define ioss_0_port_4_pin_2_HSIOM P4_2_PERI_TR_IO_OUTPUT16
#define ioss_0_port_4_pin_3_HSIOM P4_3_PERI_TR_IO_OUTPUT17
#define ioss_0_port_4_pin_4_HSIOM P4_4_PERI_TR_IO_OUTPUT18
#define ioss_0_port_4_pin_5_HSIOM P4_5_PERI_TR_IO_OUTPUT19
#define ioss_0_port_4_pin_6_HSIOM P4_6_PERI_TR_IO_OUTPUT20
#define ioss_0_port_4_pin_7_HSIOM P4_7_PERI_TR_IO_OUTPUT21
#define ioss_0_port_5_pin_0_HSIOM P5_0_SCB3_SPI_MOSI
#define ioss_0_port_5_pin_1_HSIOM P5_1_SCB3_SPI_MISO
#define ioss_0_port_5_pin_2_HSIOM P5_2_SCB3_SPI_CLK
#define ioss_0_port_5_pin_3_HSIOM P5_3_SCB3_SPI_SELECT0
#define ioss_0_port_6_pin_2_HSIOM P6_2_PERI_TR_IO_OUTPUT28
#define ioss_0_port_6_pin_3_HSIOM P6_3_PERI_TR_IO_OUTPUT29
#define ioss_0_port_7_pin_0_HSIOM P7_0_PERI_TR_IO_OUTPUT30
#define ioss_0_port_7_pin_1_HSIOM P7_1_SCB2_SPI_MOSI
#define ioss_0_port_7_pin_2_HSIOM P7_2_PERI_TR_IO_OUTPUT32
#define ioss_0_port_7_pin_3_HSIOM P7_3_PERI_TR_IO_OUTPUT33
#define ioss_0_port_7_pin_4_HSIOM P7_4_PERI_TR_IO_OUTPUT34
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
#define DMA_EC_B_RX_tr_in_0_TRIGGER_OUT TRIG_OUT_MUX_0_PDMA0_TR_IN15
#define ioss_0_port_0_pin_0_digital_in_0_TRIGGER_IN TRIG_IN_MUX_11_HSIOM_TR_OUT0
#define ioss_0_port_3_pin_0_digital_out_0_TRIGGER_OUT TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT10
#define ioss_0_port_3_pin_1_digital_out_0_TRIGGER_OUT TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT11
#define ioss_0_port_4_pin_2_digital_out_0_TRIGGER_OUT TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT16
#define ioss_0_port_4_pin_3_digital_out_0_TRIGGER_OUT TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT17
#define ioss_0_port_4_pin_4_digital_out_0_TRIGGER_OUT TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT18
#define ioss_0_port_4_pin_5_digital_out_0_TRIGGER_OUT TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT19
#define ioss_0_port_4_pin_6_digital_out_0_TRIGGER_OUT TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT20
#define ioss_0_port_4_pin_7_digital_out_0_TRIGGER_OUT TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT21
#define ioss_0_port_6_pin_2_digital_out_0_TRIGGER_OUT TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT28
#define ioss_0_port_6_pin_3_digital_out_0_TRIGGER_OUT TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT29
#define ioss_0_port_7_pin_0_digital_out_0_TRIGGER_OUT TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT30
#define ioss_0_port_7_pin_2_digital_out_0_TRIGGER_OUT TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT32
#define ioss_0_port_7_pin_3_digital_out_0_TRIGGER_OUT TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT33
#define ioss_0_port_7_pin_4_digital_out_0_TRIGGER_OUT TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT34
#define motor_a_trig_tr_a_in_0_TRIGGER_OUT TRIG_OUT_MUX_14_PASS_TR_A_IN0
#define motor_b_trig_tr_a_in_0_TRIGGER_OUT TRIG_OUT_MUX_14_PASS_TR_A_IN1
#define motor_c_trig_tr_a_in_0_TRIGGER_OUT TRIG_OUT_MUX_14_PASS_TR_A_IN2
#define PWM_A_U_start_0_TRIGGER_OUT TRIG_OUT_MUX_12_TCPWM0_GRP1_CNT0_TR4_IN
#define PWM_A_U_stop_0_TRIGGER_OUT TRIG_OUT_MUX_11_TCPWM0_GRP1_CNT0_TR3_IN
#define PWM_A_U_tr_debug_freeze_0_TRIGGER_OUT TRIG_OUT_MUX_8_TCPWM_DEBUG_FREEZE_TR_IN
#define PWM_A_U_tr_line_0_TRIGGER_IN TRIG_IN_MUX_2_TCPWM0_GRP1_LINE_256
#define PWM_A_U_tr_line_compl_0_TRIGGER_IN TRIG_IN_MUX_2_TCPWM0_GRP1_LINE_COMPL_256
#define PWM_A_U_tr_out1_0_TRIGGER_IN TRIG_IN_MUX_14_TCPWM0_GRP1_OUT1_0
#define PWM_A_V_start_0_TRIGGER_OUT TRIG_OUT_MUX_12_TCPWM0_GRP1_CNT1_TR4_IN
#define PWM_A_V_stop_0_TRIGGER_OUT TRIG_OUT_MUX_11_TCPWM0_GRP1_CNT1_TR3_IN
#define PWM_A_V_tr_debug_freeze_0_TRIGGER_OUT TRIG_OUT_MUX_8_TCPWM_DEBUG_FREEZE_TR_IN
#define PWM_A_V_tr_line_0_TRIGGER_IN TRIG_IN_MUX_2_TCPWM0_GRP1_LINE_257
#define PWM_A_V_tr_line_compl_0_TRIGGER_IN TRIG_IN_MUX_2_TCPWM0_GRP1_LINE_COMPL_257
#define PWM_A_W_start_0_TRIGGER_OUT TRIG_OUT_MUX_12_TCPWM0_GRP1_CNT2_TR4_IN
#define PWM_A_W_stop_0_TRIGGER_OUT TRIG_OUT_MUX_11_TCPWM0_GRP1_CNT2_TR3_IN
#define PWM_A_W_tr_debug_freeze_0_TRIGGER_OUT TRIG_OUT_MUX_8_TCPWM_DEBUG_FREEZE_TR_IN
#define PWM_A_W_tr_line_0_TRIGGER_IN TRIG_IN_MUX_2_TCPWM0_GRP1_LINE_258
#define PWM_A_W_tr_line_compl_0_TRIGGER_IN TRIG_IN_MUX_2_TCPWM0_GRP1_LINE_COMPL_258
#define PWM_B_U_start_0_TRIGGER_OUT TRIG_OUT_MUX_12_TCPWM0_GRP1_CNT3_TR4_IN
#define PWM_B_U_stop_0_TRIGGER_OUT TRIG_OUT_MUX_11_TCPWM0_GRP1_CNT3_TR3_IN
#define PWM_B_U_tr_debug_freeze_0_TRIGGER_OUT TRIG_OUT_MUX_8_TCPWM_DEBUG_FREEZE_TR_IN
#define PWM_B_U_tr_line_0_TRIGGER_IN TRIG_IN_MUX_2_TCPWM0_GRP1_LINE_259
#define PWM_B_U_tr_line_compl_0_TRIGGER_IN TRIG_IN_MUX_2_TCPWM0_GRP1_LINE_COMPL_259
#define PWM_B_U_tr_out1_0_TRIGGER_IN TRIG_IN_MUX_14_TCPWM0_GRP1_OUT1_3
#define PWM_B_V_start_0_TRIGGER_OUT TRIG_OUT_MUX_12_TCPWM0_GRP1_CNT4_TR4_IN
#define PWM_B_V_stop_0_TRIGGER_OUT TRIG_OUT_MUX_11_TCPWM0_GRP1_CNT4_TR3_IN
#define PWM_B_V_tr_debug_freeze_0_TRIGGER_OUT TRIG_OUT_MUX_8_TCPWM_DEBUG_FREEZE_TR_IN
#define PWM_B_V_tr_line_0_TRIGGER_IN TRIG_IN_MUX_2_TCPWM0_GRP1_LINE_260
#define PWM_B_V_tr_line_compl_0_TRIGGER_IN TRIG_IN_MUX_2_TCPWM0_GRP1_LINE_COMPL_260
#define PWM_B_W_start_0_TRIGGER_OUT TRIG_OUT_MUX_12_TCPWM0_GRP1_CNT5_TR4_IN
#define PWM_B_W_stop_0_TRIGGER_OUT TRIG_OUT_MUX_11_TCPWM0_GRP1_CNT5_TR3_IN
#define PWM_B_W_tr_debug_freeze_0_TRIGGER_OUT TRIG_OUT_MUX_8_TCPWM_DEBUG_FREEZE_TR_IN
#define PWM_B_W_tr_line_0_TRIGGER_IN TRIG_IN_MUX_2_TCPWM0_GRP1_LINE_261
#define PWM_B_W_tr_line_compl_0_TRIGGER_IN TRIG_IN_MUX_2_TCPWM0_GRP1_LINE_COMPL_261
#define PWM_C_U_start_0_TRIGGER_OUT TRIG_OUT_MUX_12_TCPWM0_GRP0_CNT1_TR4_IN
#define PWM_C_U_stop_0_TRIGGER_OUT TRIG_OUT_MUX_11_TCPWM0_GRP0_CNT1_TR3_IN
#define PWM_C_U_tr_debug_freeze_0_TRIGGER_OUT TRIG_OUT_MUX_8_TCPWM_DEBUG_FREEZE_TR_IN
#define PWM_C_U_tr_line_0_TRIGGER_IN TRIG_IN_MUX_2_TCPWM0_GRP0_LINE_1
#define PWM_C_U_tr_out1_0_TRIGGER_IN TRIG_IN_MUX_14_TCPWM0_GRP0_OUT1_1
#define PWM_C_V_start_0_TRIGGER_OUT TRIG_OUT_MUX_12_TCPWM0_GRP0_CNT2_TR4_IN
#define PWM_C_V_stop_0_TRIGGER_OUT TRIG_OUT_MUX_11_TCPWM0_GRP0_CNT2_TR3_IN
#define PWM_C_V_tr_debug_freeze_0_TRIGGER_OUT TRIG_OUT_MUX_8_TCPWM_DEBUG_FREEZE_TR_IN
#define PWM_C_V_tr_line_0_TRIGGER_IN TRIG_IN_MUX_2_TCPWM0_GRP0_LINE_2
#define PWM_START_A_tr_out0_0_TRIGGER_IN TRIG_IN_MUX_12_TCPWM0_GRP1_OUT0_6
#define PWM_START_B_tr_out0_0_TRIGGER_IN TRIG_IN_MUX_12_TCPWM0_GRP1_OUT0_7
#define PWM_START_C_tr_out0_0_TRIGGER_IN TRIG_IN_MUX_12_TCPWM0_GRP0_OUT0_3
#define SPI_EC_A_tr_rx_req_0_TRIGGER_IN TRIG_IN_MUX_0_SCB_RX3
#define SPI_EC_B_tr_rx_req_0_TRIGGER_IN TRIG_IN_MUX_0_SCB_RX1
#define TCPWM0_GRP0_CNT1_START_VALUE 0x4
#define TCPWM0_GRP0_CNT1_STOP_VALUE 0x3
#define TCPWM0_GRP0_CNT2_START_VALUE 0x4
#define TCPWM0_GRP0_CNT2_STOP_VALUE 0x3
#define TCPWM0_GRP1_CNT0_START_VALUE 0x4
#define TCPWM0_GRP1_CNT0_STOP_VALUE 0x3
#define TCPWM0_GRP1_CNT1_START_VALUE 0x4
#define TCPWM0_GRP1_CNT1_STOP_VALUE 0x3
#define TCPWM0_GRP1_CNT2_START_VALUE 0x4
#define TCPWM0_GRP1_CNT2_STOP_VALUE 0x3
#define TCPWM0_GRP1_CNT3_START_VALUE 0x4
#define TCPWM0_GRP1_CNT3_STOP_VALUE 0x3
#define TCPWM0_GRP1_CNT4_START_VALUE 0x4
#define TCPWM0_GRP1_CNT4_STOP_VALUE 0x3
#define TCPWM0_GRP1_CNT5_START_VALUE 0x4
#define TCPWM0_GRP1_CNT5_STOP_VALUE 0x3

void init_cycfg_routing(void);

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* CYCFG_ROUTING_H */
