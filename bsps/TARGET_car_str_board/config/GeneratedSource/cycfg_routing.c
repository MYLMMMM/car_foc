/*******************************************************************************
 * File Name: cycfg_routing.c
 *
 * Description:
 * Establishes all necessary connections between hardware elements.
 * This file was automatically generated and should not be modified.
 * Configurator Backend 3.70.0
 * device-db 4.37.0.10260
 * mtb-pdl-cat1 3.20.1.45548
 *
 *******************************************************************************
 * Copyright 2026 Cypress Semiconductor Corporation (an Infineon company) or
 * an affiliate of Cypress Semiconductor Corporation.
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

#include "cycfg_routing.h"
#include "cy_trigmux.h"
#include "stdbool.h"
#include "cy_device_headers.h"

void init_cycfg_routing(void)
{
    Cy_TrigMux_Connect(TRIG_IN_MUX_0_SCB_RX1, TRIG_OUT_MUX_0_PDMA0_TR_IN14, false, TRIGGER_TYPE_LEVEL);
    Cy_TrigMux_Connect(TRIG_IN_MUX_0_SCB_RX3, TRIG_OUT_MUX_0_PDMA0_TR_IN15, false, TRIGGER_TYPE_LEVEL);
    Cy_TrigMux_Connect(TRIG_IN_MUX_11_HSIOM_TR_OUT0, TRIG_OUT_MUX_11_TCPWM0_GRP1_CNT0_TR3_IN, false, TRIGGER_TYPE_LEVEL);
    Cy_TrigMux_Connect(TRIG_IN_MUX_11_HSIOM_TR_OUT0, TRIG_OUT_MUX_11_TCPWM0_GRP1_CNT1_TR3_IN, false, TRIGGER_TYPE_LEVEL);
    Cy_TrigMux_Connect(TRIG_IN_MUX_11_HSIOM_TR_OUT0, TRIG_OUT_MUX_11_TCPWM0_GRP1_CNT2_TR3_IN, false, TRIGGER_TYPE_LEVEL);
    Cy_TrigMux_Connect(TRIG_IN_MUX_11_HSIOM_TR_OUT0, TRIG_OUT_MUX_11_TCPWM0_GRP1_CNT3_TR3_IN, false, TRIGGER_TYPE_LEVEL);
    Cy_TrigMux_Connect(TRIG_IN_MUX_11_HSIOM_TR_OUT0, TRIG_OUT_MUX_11_TCPWM0_GRP1_CNT4_TR3_IN, false, TRIGGER_TYPE_LEVEL);
    Cy_TrigMux_Connect(TRIG_IN_MUX_11_HSIOM_TR_OUT0, TRIG_OUT_MUX_11_TCPWM0_GRP1_CNT5_TR3_IN, false, TRIGGER_TYPE_LEVEL);
    Cy_TrigMux_Connect(TRIG_IN_MUX_12_TCPWM0_GRP1_OUT0_6, TRIG_OUT_MUX_12_TCPWM0_GRP1_CNT0_TR4_IN, false, TRIGGER_TYPE_LEVEL);
    Cy_TrigMux_Connect(TRIG_IN_MUX_12_TCPWM0_GRP1_OUT0_6, TRIG_OUT_MUX_12_TCPWM0_GRP1_CNT1_TR4_IN, false, TRIGGER_TYPE_LEVEL);
    Cy_TrigMux_Connect(TRIG_IN_MUX_12_TCPWM0_GRP1_OUT0_6, TRIG_OUT_MUX_12_TCPWM0_GRP1_CNT2_TR4_IN, false, TRIGGER_TYPE_LEVEL);
    Cy_TrigMux_Connect(TRIG_IN_MUX_12_TCPWM0_GRP1_OUT0_7, TRIG_OUT_MUX_12_TCPWM0_GRP1_CNT3_TR4_IN, false, TRIGGER_TYPE_LEVEL);
    Cy_TrigMux_Connect(TRIG_IN_MUX_12_TCPWM0_GRP1_OUT0_7, TRIG_OUT_MUX_12_TCPWM0_GRP1_CNT4_TR4_IN, false, TRIGGER_TYPE_LEVEL);
    Cy_TrigMux_Connect(TRIG_IN_MUX_12_TCPWM0_GRP1_OUT0_7, TRIG_OUT_MUX_12_TCPWM0_GRP1_CNT5_TR4_IN, false, TRIGGER_TYPE_LEVEL);
    Cy_TrigMux_Connect(TRIG_IN_MUX_14_TCPWM0_GRP1_OUT1_0, TRIG_OUT_MUX_14_PASS_TR_A_IN0, false, TRIGGER_TYPE_LEVEL);
    Cy_TrigMux_Connect(TRIG_IN_MUX_14_TCPWM0_GRP1_OUT1_3, TRIG_OUT_MUX_14_PASS_TR_A_IN1, false, TRIGGER_TYPE_LEVEL);
    Cy_TrigMux_Connect(TRIG_IN_MUX_14_TCPWM0_GRP2_OUT1_0, TRIG_OUT_MUX_14_PASS_TR_A_IN2, false, TRIGGER_TYPE_LEVEL);
    Cy_TrigMux_Connect(TRIG_IN_MUX_2_TCPWM0_GRP1_LINE_256, TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT34, false, TRIGGER_TYPE_LEVEL);
    Cy_TrigMux_Connect(TRIG_IN_MUX_2_TCPWM0_GRP1_LINE_257, TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT32, false, TRIGGER_TYPE_LEVEL);
    Cy_TrigMux_Connect(TRIG_IN_MUX_2_TCPWM0_GRP1_LINE_258, TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT29, false, TRIGGER_TYPE_LEVEL);
    Cy_TrigMux_Connect(TRIG_IN_MUX_2_TCPWM0_GRP1_LINE_259, TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT16, false, TRIGGER_TYPE_LEVEL);
    Cy_TrigMux_Connect(TRIG_IN_MUX_2_TCPWM0_GRP1_LINE_260, TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT18, false, TRIGGER_TYPE_LEVEL);
    Cy_TrigMux_Connect(TRIG_IN_MUX_2_TCPWM0_GRP1_LINE_261, TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT20, false, TRIGGER_TYPE_LEVEL);
    Cy_TrigMux_Connect(TRIG_IN_MUX_2_TCPWM0_GRP1_LINE_COMPL_256, TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT33, false, TRIGGER_TYPE_LEVEL);
    Cy_TrigMux_Connect(TRIG_IN_MUX_2_TCPWM0_GRP1_LINE_COMPL_257, TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT30, false, TRIGGER_TYPE_LEVEL);
    Cy_TrigMux_Connect(TRIG_IN_MUX_2_TCPWM0_GRP1_LINE_COMPL_258, TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT28, false, TRIGGER_TYPE_LEVEL);
    Cy_TrigMux_Connect(TRIG_IN_MUX_2_TCPWM0_GRP1_LINE_COMPL_259, TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT17, false, TRIGGER_TYPE_LEVEL);
    Cy_TrigMux_Connect(TRIG_IN_MUX_2_TCPWM0_GRP1_LINE_COMPL_260, TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT19, false, TRIGGER_TYPE_LEVEL);
    Cy_TrigMux_Connect(TRIG_IN_MUX_2_TCPWM0_GRP1_LINE_COMPL_261, TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT21, false, TRIGGER_TYPE_LEVEL);
    Cy_TrigMux_Connect(TRIG_IN_MUX_2_TCPWM0_GRP2_LINE_512, TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT11, false, TRIGGER_TYPE_LEVEL);
    Cy_TrigMux_Connect(TRIG_IN_MUX_2_TCPWM0_GRP2_LINE_COMPL_512, TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT10, false, TRIGGER_TYPE_LEVEL);
    Cy_TrigMux_Connect(TRIG_IN_MUX_8_CTI_TR_OUT0, TRIG_OUT_MUX_8_TCPWM_DEBUG_FREEZE_TR_IN, false, TRIGGER_TYPE_LEVEL);
}
