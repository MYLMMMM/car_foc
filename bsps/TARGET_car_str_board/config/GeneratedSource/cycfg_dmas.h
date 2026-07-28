/*******************************************************************************
 * File Name: cycfg_dmas.h
 *
 * Description:
 * DMA configuration
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

#if !defined(CYCFG_DMAS_H)
#define CYCFG_DMAS_H

#include "cycfg_notices.h"
#include "cy_dma.h"

#if defined (CY_USING_HAL)
#include "cyhal_hwmgr.h"
#endif /* defined (CY_USING_HAL) */

#if defined (CY_USING_HAL) || defined (CY_USING_HAL_LITE)
#include "cyhal_dma.h"
#endif /* defined (CY_USING_HAL) || defined (CY_USING_HAL_LITE) */

#if defined (COMPONENT_MTB_HAL)
#include "mtb_hal.h"
#endif /* defined (COMPONENT_MTB_HAL) */

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

#define DMA_EC_B_RX_ENABLED 1U
#define DMA_EC_B_RX_HW DW0
#define DMA_EC_B_RX_CHANNEL 14U
#define DMA_EC_B_RX_IRQ cpuss_interrupts_dw0_14_IRQn
#define DMA_EC_A_RX_ENABLED 1U
#define DMA_EC_A_RX_HW DW0
#define DMA_EC_A_RX_CHANNEL 15U
#define DMA_EC_A_RX_IRQ cpuss_interrupts_dw0_15_IRQn
#define DMA_PWM_CC_A_U_1_ENABLED 1U
#define DMA_PWM_CC_A_U_1_HW DW1
#define DMA_PWM_CC_A_U_1_CHANNEL 0U
#define DMA_PWM_CC_A_U_1_IRQ cpuss_interrupts_dw1_0_IRQn
#define DMA_PWM_CC_A_V_1_ENABLED 1U
#define DMA_PWM_CC_A_V_1_HW DW1
#define DMA_PWM_CC_A_V_1_CHANNEL 1U
#define DMA_PWM_CC_A_V_1_IRQ cpuss_interrupts_dw1_1_IRQn
#define DMA_PWM_CC_A_W_1_ENABLED 1U
#define DMA_PWM_CC_A_W_1_HW DW1
#define DMA_PWM_CC_A_W_1_CHANNEL 2U
#define DMA_PWM_CC_A_W_1_IRQ cpuss_interrupts_dw1_2_IRQn
#define DMA_PWM_CC_B_U_1_ENABLED 1U
#define DMA_PWM_CC_B_U_1_HW DW1
#define DMA_PWM_CC_B_U_1_CHANNEL 3U
#define DMA_PWM_CC_B_U_1_IRQ cpuss_interrupts_dw1_3_IRQn
#define DMA_PWM_CC_B_V_1_ENABLED 1U
#define DMA_PWM_CC_B_V_1_HW DW1
#define DMA_PWM_CC_B_V_1_CHANNEL 4U
#define DMA_PWM_CC_B_V_1_IRQ cpuss_interrupts_dw1_4_IRQn
#define DMA_PWM_CC_B_W_1_ENABLED 1U
#define DMA_PWM_CC_B_W_1_HW DW1
#define DMA_PWM_CC_B_W_1_CHANNEL 5U
#define DMA_PWM_CC_B_W_1_IRQ cpuss_interrupts_dw1_5_IRQn
#define DMA_PWM_CC_A_U_2_ENABLED 1U
#define DMA_PWM_CC_A_U_2_HW DW1
#define DMA_PWM_CC_A_U_2_CHANNEL 6U
#define DMA_PWM_CC_A_U_2_IRQ cpuss_interrupts_dw1_6_IRQn
#define DMA_PWM_CC_A_V_2_ENABLED 1U
#define DMA_PWM_CC_A_V_2_HW DW1
#define DMA_PWM_CC_A_V_2_CHANNEL 7U
#define DMA_PWM_CC_A_V_2_IRQ cpuss_interrupts_dw1_7_IRQn
#define DMA_PWM_CC_A_W_2_ENABLED 1U
#define DMA_PWM_CC_A_W_2_HW DW1
#define DMA_PWM_CC_A_W_2_CHANNEL 8U
#define DMA_PWM_CC_A_W_2_IRQ cpuss_interrupts_dw1_8_IRQn
#define DMA_PWM_CC_B_U_2_ENABLED 1U
#define DMA_PWM_CC_B_U_2_HW DW1
#define DMA_PWM_CC_B_U_2_CHANNEL 9U
#define DMA_PWM_CC_B_U_2_IRQ cpuss_interrupts_dw1_9_IRQn
#define DMA_PWM_CC_B_V_2_ENABLED 1U
#define DMA_PWM_CC_B_V_2_HW DW1
#define DMA_PWM_CC_B_V_2_CHANNEL 10U
#define DMA_PWM_CC_B_V_2_IRQ cpuss_interrupts_dw1_10_IRQn
#define DMA_PWM_CC_B_W_2_ENABLED 1U
#define DMA_PWM_CC_B_W_2_HW DW1
#define DMA_PWM_CC_B_W_2_CHANNEL 11U
#define DMA_PWM_CC_B_W_2_IRQ cpuss_interrupts_dw1_11_IRQn

extern const cy_stc_dma_descriptor_config_t DMA_EC_B_RX_Descriptor_0_config;
extern cy_stc_dma_descriptor_t DMA_EC_B_RX_Descriptor_0;
extern const cy_stc_dma_channel_config_t DMA_EC_B_RX_channelConfig;
extern const cy_stc_dma_crc_config_t DMA_EC_B_RX_crcConfig;

#if defined (CY_USING_HAL) || defined (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t DMA_EC_B_RX_obj;
extern const cyhal_dma_configurator_t DMA_EC_B_RX_hal_config;
#endif /* defined (CY_USING_HAL) || defined (CY_USING_HAL_LITE) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_DMA)
extern const mtb_hal_dma_configurator_t DMA_EC_B_RX_hal_config;
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_DMA) */

extern const cy_stc_dma_descriptor_config_t DMA_EC_A_RX_Descriptor_0_config;
extern cy_stc_dma_descriptor_t DMA_EC_A_RX_Descriptor_0;
extern const cy_stc_dma_channel_config_t DMA_EC_A_RX_channelConfig;
extern const cy_stc_dma_crc_config_t DMA_EC_A_RX_crcConfig;

#if defined (CY_USING_HAL) || defined (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t DMA_EC_A_RX_obj;
extern const cyhal_dma_configurator_t DMA_EC_A_RX_hal_config;
#endif /* defined (CY_USING_HAL) || defined (CY_USING_HAL_LITE) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_DMA)
extern const mtb_hal_dma_configurator_t DMA_EC_A_RX_hal_config;
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_DMA) */

extern const cy_stc_dma_descriptor_config_t DMA_PWM_CC_A_U_1_Descriptor_0_config;
extern cy_stc_dma_descriptor_t DMA_PWM_CC_A_U_1_Descriptor_0;
extern const cy_stc_dma_channel_config_t DMA_PWM_CC_A_U_1_channelConfig;
extern const cy_stc_dma_crc_config_t DMA_PWM_CC_A_U_1_crcConfig;

#if defined (CY_USING_HAL) || defined (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t DMA_PWM_CC_A_U_1_obj;
extern const cyhal_dma_configurator_t DMA_PWM_CC_A_U_1_hal_config;
#endif /* defined (CY_USING_HAL) || defined (CY_USING_HAL_LITE) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_DMA)
extern const mtb_hal_dma_configurator_t DMA_PWM_CC_A_U_1_hal_config;
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_DMA) */

extern const cy_stc_dma_descriptor_config_t DMA_PWM_CC_A_V_1_Descriptor_0_config;
extern cy_stc_dma_descriptor_t DMA_PWM_CC_A_V_1_Descriptor_0;
extern const cy_stc_dma_channel_config_t DMA_PWM_CC_A_V_1_channelConfig;
extern const cy_stc_dma_crc_config_t DMA_PWM_CC_A_V_1_crcConfig;

#if defined (CY_USING_HAL) || defined (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t DMA_PWM_CC_A_V_1_obj;
extern const cyhal_dma_configurator_t DMA_PWM_CC_A_V_1_hal_config;
#endif /* defined (CY_USING_HAL) || defined (CY_USING_HAL_LITE) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_DMA)
extern const mtb_hal_dma_configurator_t DMA_PWM_CC_A_V_1_hal_config;
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_DMA) */

extern const cy_stc_dma_descriptor_config_t DMA_PWM_CC_A_W_1_Descriptor_0_config;
extern cy_stc_dma_descriptor_t DMA_PWM_CC_A_W_1_Descriptor_0;
extern const cy_stc_dma_channel_config_t DMA_PWM_CC_A_W_1_channelConfig;
extern const cy_stc_dma_crc_config_t DMA_PWM_CC_A_W_1_crcConfig;

#if defined (CY_USING_HAL) || defined (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t DMA_PWM_CC_A_W_1_obj;
extern const cyhal_dma_configurator_t DMA_PWM_CC_A_W_1_hal_config;
#endif /* defined (CY_USING_HAL) || defined (CY_USING_HAL_LITE) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_DMA)
extern const mtb_hal_dma_configurator_t DMA_PWM_CC_A_W_1_hal_config;
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_DMA) */

extern const cy_stc_dma_descriptor_config_t DMA_PWM_CC_B_U_1_Descriptor_0_config;
extern cy_stc_dma_descriptor_t DMA_PWM_CC_B_U_1_Descriptor_0;
extern const cy_stc_dma_channel_config_t DMA_PWM_CC_B_U_1_channelConfig;
extern const cy_stc_dma_crc_config_t DMA_PWM_CC_B_U_1_crcConfig;

#if defined (CY_USING_HAL) || defined (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t DMA_PWM_CC_B_U_1_obj;
extern const cyhal_dma_configurator_t DMA_PWM_CC_B_U_1_hal_config;
#endif /* defined (CY_USING_HAL) || defined (CY_USING_HAL_LITE) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_DMA)
extern const mtb_hal_dma_configurator_t DMA_PWM_CC_B_U_1_hal_config;
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_DMA) */

extern const cy_stc_dma_descriptor_config_t DMA_PWM_CC_B_V_1_Descriptor_0_config;
extern cy_stc_dma_descriptor_t DMA_PWM_CC_B_V_1_Descriptor_0;
extern const cy_stc_dma_channel_config_t DMA_PWM_CC_B_V_1_channelConfig;
extern const cy_stc_dma_crc_config_t DMA_PWM_CC_B_V_1_crcConfig;

#if defined (CY_USING_HAL) || defined (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t DMA_PWM_CC_B_V_1_obj;
extern const cyhal_dma_configurator_t DMA_PWM_CC_B_V_1_hal_config;
#endif /* defined (CY_USING_HAL) || defined (CY_USING_HAL_LITE) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_DMA)
extern const mtb_hal_dma_configurator_t DMA_PWM_CC_B_V_1_hal_config;
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_DMA) */

extern const cy_stc_dma_descriptor_config_t DMA_PWM_CC_B_W_1_Descriptor_0_config;
extern cy_stc_dma_descriptor_t DMA_PWM_CC_B_W_1_Descriptor_0;
extern const cy_stc_dma_channel_config_t DMA_PWM_CC_B_W_1_channelConfig;
extern const cy_stc_dma_crc_config_t DMA_PWM_CC_B_W_1_crcConfig;

#if defined (CY_USING_HAL) || defined (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t DMA_PWM_CC_B_W_1_obj;
extern const cyhal_dma_configurator_t DMA_PWM_CC_B_W_1_hal_config;
#endif /* defined (CY_USING_HAL) || defined (CY_USING_HAL_LITE) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_DMA)
extern const mtb_hal_dma_configurator_t DMA_PWM_CC_B_W_1_hal_config;
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_DMA) */

extern const cy_stc_dma_descriptor_config_t DMA_PWM_CC_A_U_2_Descriptor_0_config;
extern cy_stc_dma_descriptor_t DMA_PWM_CC_A_U_2_Descriptor_0;
extern const cy_stc_dma_channel_config_t DMA_PWM_CC_A_U_2_channelConfig;
extern const cy_stc_dma_crc_config_t DMA_PWM_CC_A_U_2_crcConfig;

#if defined (CY_USING_HAL) || defined (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t DMA_PWM_CC_A_U_2_obj;
extern const cyhal_dma_configurator_t DMA_PWM_CC_A_U_2_hal_config;
#endif /* defined (CY_USING_HAL) || defined (CY_USING_HAL_LITE) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_DMA)
extern const mtb_hal_dma_configurator_t DMA_PWM_CC_A_U_2_hal_config;
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_DMA) */

extern const cy_stc_dma_descriptor_config_t DMA_PWM_CC_A_V_2_Descriptor_0_config;
extern cy_stc_dma_descriptor_t DMA_PWM_CC_A_V_2_Descriptor_0;
extern const cy_stc_dma_channel_config_t DMA_PWM_CC_A_V_2_channelConfig;
extern const cy_stc_dma_crc_config_t DMA_PWM_CC_A_V_2_crcConfig;

#if defined (CY_USING_HAL) || defined (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t DMA_PWM_CC_A_V_2_obj;
extern const cyhal_dma_configurator_t DMA_PWM_CC_A_V_2_hal_config;
#endif /* defined (CY_USING_HAL) || defined (CY_USING_HAL_LITE) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_DMA)
extern const mtb_hal_dma_configurator_t DMA_PWM_CC_A_V_2_hal_config;
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_DMA) */

extern const cy_stc_dma_descriptor_config_t DMA_PWM_CC_A_W_2_Descriptor_0_config;
extern cy_stc_dma_descriptor_t DMA_PWM_CC_A_W_2_Descriptor_0;
extern const cy_stc_dma_channel_config_t DMA_PWM_CC_A_W_2_channelConfig;
extern const cy_stc_dma_crc_config_t DMA_PWM_CC_A_W_2_crcConfig;

#if defined (CY_USING_HAL) || defined (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t DMA_PWM_CC_A_W_2_obj;
extern const cyhal_dma_configurator_t DMA_PWM_CC_A_W_2_hal_config;
#endif /* defined (CY_USING_HAL) || defined (CY_USING_HAL_LITE) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_DMA)
extern const mtb_hal_dma_configurator_t DMA_PWM_CC_A_W_2_hal_config;
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_DMA) */

extern const cy_stc_dma_descriptor_config_t DMA_PWM_CC_B_U_2_Descriptor_0_config;
extern cy_stc_dma_descriptor_t DMA_PWM_CC_B_U_2_Descriptor_0;
extern const cy_stc_dma_channel_config_t DMA_PWM_CC_B_U_2_channelConfig;
extern const cy_stc_dma_crc_config_t DMA_PWM_CC_B_U_2_crcConfig;

#if defined (CY_USING_HAL) || defined (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t DMA_PWM_CC_B_U_2_obj;
extern const cyhal_dma_configurator_t DMA_PWM_CC_B_U_2_hal_config;
#endif /* defined (CY_USING_HAL) || defined (CY_USING_HAL_LITE) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_DMA)
extern const mtb_hal_dma_configurator_t DMA_PWM_CC_B_U_2_hal_config;
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_DMA) */

extern const cy_stc_dma_descriptor_config_t DMA_PWM_CC_B_V_2_Descriptor_0_config;
extern cy_stc_dma_descriptor_t DMA_PWM_CC_B_V_2_Descriptor_0;
extern const cy_stc_dma_channel_config_t DMA_PWM_CC_B_V_2_channelConfig;
extern const cy_stc_dma_crc_config_t DMA_PWM_CC_B_V_2_crcConfig;

#if defined (CY_USING_HAL) || defined (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t DMA_PWM_CC_B_V_2_obj;
extern const cyhal_dma_configurator_t DMA_PWM_CC_B_V_2_hal_config;
#endif /* defined (CY_USING_HAL) || defined (CY_USING_HAL_LITE) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_DMA)
extern const mtb_hal_dma_configurator_t DMA_PWM_CC_B_V_2_hal_config;
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_DMA) */

extern const cy_stc_dma_descriptor_config_t DMA_PWM_CC_B_W_2_Descriptor_0_config;
extern cy_stc_dma_descriptor_t DMA_PWM_CC_B_W_2_Descriptor_0;
extern const cy_stc_dma_channel_config_t DMA_PWM_CC_B_W_2_channelConfig;
extern const cy_stc_dma_crc_config_t DMA_PWM_CC_B_W_2_crcConfig;

#if defined (CY_USING_HAL) || defined (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t DMA_PWM_CC_B_W_2_obj;
extern const cyhal_dma_configurator_t DMA_PWM_CC_B_W_2_hal_config;
#endif /* defined (CY_USING_HAL) || defined (CY_USING_HAL_LITE) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_DMA)
extern const mtb_hal_dma_configurator_t DMA_PWM_CC_B_W_2_hal_config;
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_DMA) */

void reserve_cycfg_dmas(void);

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* CYCFG_DMAS_H */
