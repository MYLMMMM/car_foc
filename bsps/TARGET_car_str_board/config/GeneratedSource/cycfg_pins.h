/*******************************************************************************
 * File Name: cycfg_pins.h
 *
 * Description:
 * Pin configuration
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

#if !defined(CYCFG_PINS_H)
#define CYCFG_PINS_H

#include "cycfg_notices.h"
#include "cy_gpio.h"
#include "cycfg_routing.h"

#if defined (CY_USING_HAL)
#include "cyhal_hwmgr.h"
#endif /* defined (CY_USING_HAL) */

#if defined (CY_USING_HAL_LITE)
#include "cyhal_hw_types.h"
#endif /* defined (CY_USING_HAL_LITE) */

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

#define ioss_0_port_0_pin_0_ENABLED 1U
#define ioss_0_port_0_pin_0_PORT GPIO_PRT0
#define ioss_0_port_0_pin_0_PORT_NUM 0U
#define ioss_0_port_0_pin_0_PIN 0U
#define ioss_0_port_0_pin_0_NUM 0U
#define ioss_0_port_0_pin_0_DRIVEMODE CY_GPIO_DM_HIGHZ
#define ioss_0_port_0_pin_0_INIT_DRIVESTATE 1
#ifndef ioss_0_port_0_pin_0_HSIOM
    #define ioss_0_port_0_pin_0_HSIOM HSIOM_SEL_GPIO
#endif
#define ioss_0_port_0_pin_0_IRQ ioss_interrupts_sec_gpio_0_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define ioss_0_port_0_pin_0_HAL_PORT_PIN P0_0
#define ioss_0_port_0_pin_0 P0_0
#define ioss_0_port_0_pin_0_HAL_IRQ CYHAL_GPIO_IRQ_FALL
#define ioss_0_port_0_pin_0_HAL_DIR CYHAL_GPIO_DIR_INPUT 
#define ioss_0_port_0_pin_0_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_NONE
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define ioss_0_port_1_pin_0_ENABLED 1U
#define ioss_0_port_1_pin_0_PORT GPIO_PRT1
#define ioss_0_port_1_pin_0_PORT_NUM 1U
#define ioss_0_port_1_pin_0_PIN 0U
#define ioss_0_port_1_pin_0_NUM 0U
#define ioss_0_port_1_pin_0_DRIVEMODE CY_GPIO_DM_ANALOG
#define ioss_0_port_1_pin_0_INIT_DRIVESTATE 0
#ifndef ioss_0_port_1_pin_0_HSIOM
    #define ioss_0_port_1_pin_0_HSIOM HSIOM_SEL_GPIO
#endif
#define ioss_0_port_1_pin_0_IRQ ioss_interrupts_sec_gpio_1_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define ioss_0_port_1_pin_0_HAL_PORT_PIN P1_0
#define ioss_0_port_1_pin_0 P1_0
#define ioss_0_port_1_pin_0_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define ioss_0_port_1_pin_0_HAL_DIR CYHAL_GPIO_DIR_INPUT 
#define ioss_0_port_1_pin_0_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_ANALOG
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define ioss_0_port_1_pin_1_ENABLED 1U
#define ioss_0_port_1_pin_1_PORT GPIO_PRT1
#define ioss_0_port_1_pin_1_PORT_NUM 1U
#define ioss_0_port_1_pin_1_PIN 1U
#define ioss_0_port_1_pin_1_NUM 1U
#define ioss_0_port_1_pin_1_DRIVEMODE CY_GPIO_DM_ANALOG
#define ioss_0_port_1_pin_1_INIT_DRIVESTATE 0
#ifndef ioss_0_port_1_pin_1_HSIOM
    #define ioss_0_port_1_pin_1_HSIOM HSIOM_SEL_GPIO
#endif
#define ioss_0_port_1_pin_1_IRQ ioss_interrupts_sec_gpio_1_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define ioss_0_port_1_pin_1_HAL_PORT_PIN P1_1
#define ioss_0_port_1_pin_1 P1_1
#define ioss_0_port_1_pin_1_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define ioss_0_port_1_pin_1_HAL_DIR CYHAL_GPIO_DIR_INPUT 
#define ioss_0_port_1_pin_1_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_ANALOG
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define ioss_0_port_1_pin_2_ENABLED 1U
#define ioss_0_port_1_pin_2_PORT GPIO_PRT1
#define ioss_0_port_1_pin_2_PORT_NUM 1U
#define ioss_0_port_1_pin_2_PIN 2U
#define ioss_0_port_1_pin_2_NUM 2U
#define ioss_0_port_1_pin_2_DRIVEMODE CY_GPIO_DM_PULLDOWN
#define ioss_0_port_1_pin_2_INIT_DRIVESTATE 1
#ifndef ioss_0_port_1_pin_2_HSIOM
    #define ioss_0_port_1_pin_2_HSIOM HSIOM_SEL_GPIO
#endif
#define ioss_0_port_1_pin_2_IRQ ioss_interrupts_sec_gpio_1_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define ioss_0_port_1_pin_2_HAL_PORT_PIN P1_2
#define ioss_0_port_1_pin_2 P1_2
#define ioss_0_port_1_pin_2_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define ioss_0_port_1_pin_2_HAL_DIR CYHAL_GPIO_DIR_BIDIRECTIONAL 
#define ioss_0_port_1_pin_2_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_PULLDOWN
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define ioss_0_port_1_pin_3_ENABLED 1U
#define ioss_0_port_1_pin_3_PORT GPIO_PRT1
#define ioss_0_port_1_pin_3_PORT_NUM 1U
#define ioss_0_port_1_pin_3_PIN 3U
#define ioss_0_port_1_pin_3_NUM 3U
#define ioss_0_port_1_pin_3_DRIVEMODE CY_GPIO_DM_PULLUP
#define ioss_0_port_1_pin_3_INIT_DRIVESTATE 1
#ifndef ioss_0_port_1_pin_3_HSIOM
    #define ioss_0_port_1_pin_3_HSIOM HSIOM_SEL_GPIO
#endif
#define ioss_0_port_1_pin_3_IRQ ioss_interrupts_sec_gpio_1_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define ioss_0_port_1_pin_3_HAL_PORT_PIN P1_3
#define ioss_0_port_1_pin_3 P1_3
#define ioss_0_port_1_pin_3_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define ioss_0_port_1_pin_3_HAL_DIR CYHAL_GPIO_DIR_BIDIRECTIONAL 
#define ioss_0_port_1_pin_3_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_PULLUP
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define ioss_0_port_2_pin_0_ENABLED 1U
#define ioss_0_port_2_pin_0_PORT GPIO_PRT2
#define ioss_0_port_2_pin_0_PORT_NUM 2U
#define ioss_0_port_2_pin_0_PIN 0U
#define ioss_0_port_2_pin_0_NUM 0U
#define ioss_0_port_2_pin_0_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define ioss_0_port_2_pin_0_INIT_DRIVESTATE 1
#ifndef ioss_0_port_2_pin_0_HSIOM
    #define ioss_0_port_2_pin_0_HSIOM HSIOM_SEL_GPIO
#endif
#define ioss_0_port_2_pin_0_IRQ ioss_interrupts_sec_gpio_2_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define ioss_0_port_2_pin_0_HAL_PORT_PIN P2_0
#define ioss_0_port_2_pin_0 P2_0
#define ioss_0_port_2_pin_0_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define ioss_0_port_2_pin_0_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#define ioss_0_port_2_pin_0_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define ioss_0_port_2_pin_1_ENABLED 1U
#define ioss_0_port_2_pin_1_PORT GPIO_PRT2
#define ioss_0_port_2_pin_1_PORT_NUM 2U
#define ioss_0_port_2_pin_1_PIN 1U
#define ioss_0_port_2_pin_1_NUM 1U
#define ioss_0_port_2_pin_1_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define ioss_0_port_2_pin_1_INIT_DRIVESTATE 1
#ifndef ioss_0_port_2_pin_1_HSIOM
    #define ioss_0_port_2_pin_1_HSIOM HSIOM_SEL_GPIO
#endif
#define ioss_0_port_2_pin_1_IRQ ioss_interrupts_sec_gpio_2_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define ioss_0_port_2_pin_1_HAL_PORT_PIN P2_1
#define ioss_0_port_2_pin_1 P2_1
#define ioss_0_port_2_pin_1_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define ioss_0_port_2_pin_1_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#define ioss_0_port_2_pin_1_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define ioss_0_port_2_pin_2_ENABLED 1U
#define ioss_0_port_2_pin_2_PORT GPIO_PRT2
#define ioss_0_port_2_pin_2_PORT_NUM 2U
#define ioss_0_port_2_pin_2_PIN 2U
#define ioss_0_port_2_pin_2_NUM 2U
#define ioss_0_port_2_pin_2_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define ioss_0_port_2_pin_2_INIT_DRIVESTATE 1
#ifndef ioss_0_port_2_pin_2_HSIOM
    #define ioss_0_port_2_pin_2_HSIOM HSIOM_SEL_GPIO
#endif
#define ioss_0_port_2_pin_2_IRQ ioss_interrupts_sec_gpio_2_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define ioss_0_port_2_pin_2_HAL_PORT_PIN P2_2
#define ioss_0_port_2_pin_2 P2_2
#define ioss_0_port_2_pin_2_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define ioss_0_port_2_pin_2_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#define ioss_0_port_2_pin_2_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define ioss_0_port_2_pin_3_ENABLED 1U
#define ioss_0_port_2_pin_3_PORT GPIO_PRT2
#define ioss_0_port_2_pin_3_PORT_NUM 2U
#define ioss_0_port_2_pin_3_PIN 3U
#define ioss_0_port_2_pin_3_NUM 3U
#define ioss_0_port_2_pin_3_DRIVEMODE CY_GPIO_DM_HIGHZ
#define ioss_0_port_2_pin_3_INIT_DRIVESTATE 1
#ifndef ioss_0_port_2_pin_3_HSIOM
    #define ioss_0_port_2_pin_3_HSIOM HSIOM_SEL_GPIO
#endif
#define ioss_0_port_2_pin_3_IRQ ioss_interrupts_sec_gpio_2_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define ioss_0_port_2_pin_3_HAL_PORT_PIN P2_3
#define ioss_0_port_2_pin_3 P2_3
#define ioss_0_port_2_pin_3_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define ioss_0_port_2_pin_3_HAL_DIR CYHAL_GPIO_DIR_INPUT 
#define ioss_0_port_2_pin_3_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_NONE
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define ioss_0_port_3_pin_0_ENABLED 1U
#define ioss_0_port_3_pin_0_PORT GPIO_PRT3
#define ioss_0_port_3_pin_0_PORT_NUM 3U
#define ioss_0_port_3_pin_0_PIN 0U
#define ioss_0_port_3_pin_0_NUM 0U
#define ioss_0_port_3_pin_0_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define ioss_0_port_3_pin_0_INIT_DRIVESTATE 1
#ifndef ioss_0_port_3_pin_0_HSIOM
    #define ioss_0_port_3_pin_0_HSIOM HSIOM_SEL_GPIO
#endif
#define ioss_0_port_3_pin_0_IRQ ioss_interrupts_sec_gpio_3_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define ioss_0_port_3_pin_0_HAL_PORT_PIN P3_0
#define ioss_0_port_3_pin_0 P3_0
#define ioss_0_port_3_pin_0_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define ioss_0_port_3_pin_0_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#define ioss_0_port_3_pin_0_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define ioss_0_port_3_pin_1_ENABLED 1U
#define ioss_0_port_3_pin_1_PORT GPIO_PRT3
#define ioss_0_port_3_pin_1_PORT_NUM 3U
#define ioss_0_port_3_pin_1_PIN 1U
#define ioss_0_port_3_pin_1_NUM 1U
#define ioss_0_port_3_pin_1_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define ioss_0_port_3_pin_1_INIT_DRIVESTATE 1
#ifndef ioss_0_port_3_pin_1_HSIOM
    #define ioss_0_port_3_pin_1_HSIOM HSIOM_SEL_GPIO
#endif
#define ioss_0_port_3_pin_1_IRQ ioss_interrupts_sec_gpio_3_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define ioss_0_port_3_pin_1_HAL_PORT_PIN P3_1
#define ioss_0_port_3_pin_1 P3_1
#define ioss_0_port_3_pin_1_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define ioss_0_port_3_pin_1_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#define ioss_0_port_3_pin_1_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define GPIO_GD_C_ENABLE_ENABLED 1U
#define GPIO_GD_C_ENABLE_PORT GPIO_PRT3
#define GPIO_GD_C_ENABLE_PORT_NUM 3U
#define GPIO_GD_C_ENABLE_PIN 2U
#define GPIO_GD_C_ENABLE_NUM 2U
#define GPIO_GD_C_ENABLE_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define GPIO_GD_C_ENABLE_INIT_DRIVESTATE 1
#ifndef ioss_0_port_3_pin_2_HSIOM
    #define ioss_0_port_3_pin_2_HSIOM HSIOM_SEL_GPIO
#endif
#define GPIO_GD_C_ENABLE_HSIOM ioss_0_port_3_pin_2_HSIOM
#define GPIO_GD_C_ENABLE_IRQ ioss_interrupts_sec_gpio_3_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define GPIO_GD_C_ENABLE_HAL_PORT_PIN P3_2
#define GPIO_GD_C_ENABLE P3_2
#define GPIO_GD_C_ENABLE_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define GPIO_GD_C_ENABLE_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#define GPIO_GD_C_ENABLE_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define GPIO_GD_C_nFAULT_ENABLED 1U
#define GPIO_GD_C_nFAULT_PORT GPIO_PRT3
#define GPIO_GD_C_nFAULT_PORT_NUM 3U
#define GPIO_GD_C_nFAULT_PIN 3U
#define GPIO_GD_C_nFAULT_NUM 3U
#define GPIO_GD_C_nFAULT_DRIVEMODE CY_GPIO_DM_HIGHZ
#define GPIO_GD_C_nFAULT_INIT_DRIVESTATE 1
#ifndef ioss_0_port_3_pin_3_HSIOM
    #define ioss_0_port_3_pin_3_HSIOM HSIOM_SEL_GPIO
#endif
#define GPIO_GD_C_nFAULT_HSIOM ioss_0_port_3_pin_3_HSIOM
#define GPIO_GD_C_nFAULT_IRQ ioss_interrupts_sec_gpio_3_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define GPIO_GD_C_nFAULT_HAL_PORT_PIN P3_3
#define GPIO_GD_C_nFAULT P3_3
#define GPIO_GD_C_nFAULT_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define GPIO_GD_C_nFAULT_HAL_DIR CYHAL_GPIO_DIR_INPUT 
#define GPIO_GD_C_nFAULT_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_NONE
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define GPIO_GD_B_nFAULT_ENABLED 1U
#define GPIO_GD_B_nFAULT_PORT GPIO_PRT4
#define GPIO_GD_B_nFAULT_PORT_NUM 4U
#define GPIO_GD_B_nFAULT_PIN 0U
#define GPIO_GD_B_nFAULT_NUM 0U
#define GPIO_GD_B_nFAULT_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define GPIO_GD_B_nFAULT_INIT_DRIVESTATE 1
#ifndef ioss_0_port_4_pin_0_HSIOM
    #define ioss_0_port_4_pin_0_HSIOM HSIOM_SEL_GPIO
#endif
#define GPIO_GD_B_nFAULT_HSIOM ioss_0_port_4_pin_0_HSIOM
#define GPIO_GD_B_nFAULT_IRQ ioss_interrupts_sec_gpio_4_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define GPIO_GD_B_nFAULT_HAL_PORT_PIN P4_0
#define GPIO_GD_B_nFAULT P4_0
#define GPIO_GD_B_nFAULT_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define GPIO_GD_B_nFAULT_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#define GPIO_GD_B_nFAULT_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define GPIO_GD_B_ENABLE_ENABLED 1U
#define GPIO_GD_B_ENABLE_PORT GPIO_PRT4
#define GPIO_GD_B_ENABLE_PORT_NUM 4U
#define GPIO_GD_B_ENABLE_PIN 1U
#define GPIO_GD_B_ENABLE_NUM 1U
#define GPIO_GD_B_ENABLE_DRIVEMODE CY_GPIO_DM_HIGHZ
#define GPIO_GD_B_ENABLE_INIT_DRIVESTATE 1
#ifndef ioss_0_port_4_pin_1_HSIOM
    #define ioss_0_port_4_pin_1_HSIOM HSIOM_SEL_GPIO
#endif
#define GPIO_GD_B_ENABLE_HSIOM ioss_0_port_4_pin_1_HSIOM
#define GPIO_GD_B_ENABLE_IRQ ioss_interrupts_sec_gpio_4_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define GPIO_GD_B_ENABLE_HAL_PORT_PIN P4_1
#define GPIO_GD_B_ENABLE P4_1
#define GPIO_GD_B_ENABLE_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define GPIO_GD_B_ENABLE_HAL_DIR CYHAL_GPIO_DIR_INPUT 
#define GPIO_GD_B_ENABLE_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_NONE
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define ioss_0_port_4_pin_2_ENABLED 1U
#define ioss_0_port_4_pin_2_PORT GPIO_PRT4
#define ioss_0_port_4_pin_2_PORT_NUM 4U
#define ioss_0_port_4_pin_2_PIN 2U
#define ioss_0_port_4_pin_2_NUM 2U
#define ioss_0_port_4_pin_2_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define ioss_0_port_4_pin_2_INIT_DRIVESTATE 1
#ifndef ioss_0_port_4_pin_2_HSIOM
    #define ioss_0_port_4_pin_2_HSIOM HSIOM_SEL_GPIO
#endif
#define ioss_0_port_4_pin_2_IRQ ioss_interrupts_sec_gpio_4_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define ioss_0_port_4_pin_2_HAL_PORT_PIN P4_2
#define ioss_0_port_4_pin_2 P4_2
#define ioss_0_port_4_pin_2_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define ioss_0_port_4_pin_2_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#define ioss_0_port_4_pin_2_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define ioss_0_port_4_pin_3_ENABLED 1U
#define ioss_0_port_4_pin_3_PORT GPIO_PRT4
#define ioss_0_port_4_pin_3_PORT_NUM 4U
#define ioss_0_port_4_pin_3_PIN 3U
#define ioss_0_port_4_pin_3_NUM 3U
#define ioss_0_port_4_pin_3_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define ioss_0_port_4_pin_3_INIT_DRIVESTATE 1
#ifndef ioss_0_port_4_pin_3_HSIOM
    #define ioss_0_port_4_pin_3_HSIOM HSIOM_SEL_GPIO
#endif
#define ioss_0_port_4_pin_3_IRQ ioss_interrupts_sec_gpio_4_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define ioss_0_port_4_pin_3_HAL_PORT_PIN P4_3
#define ioss_0_port_4_pin_3 P4_3
#define ioss_0_port_4_pin_3_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define ioss_0_port_4_pin_3_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#define ioss_0_port_4_pin_3_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define ioss_0_port_4_pin_4_ENABLED 1U
#define ioss_0_port_4_pin_4_PORT GPIO_PRT4
#define ioss_0_port_4_pin_4_PORT_NUM 4U
#define ioss_0_port_4_pin_4_PIN 4U
#define ioss_0_port_4_pin_4_NUM 4U
#define ioss_0_port_4_pin_4_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define ioss_0_port_4_pin_4_INIT_DRIVESTATE 1
#ifndef ioss_0_port_4_pin_4_HSIOM
    #define ioss_0_port_4_pin_4_HSIOM HSIOM_SEL_GPIO
#endif
#define ioss_0_port_4_pin_4_IRQ ioss_interrupts_sec_gpio_4_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define ioss_0_port_4_pin_4_HAL_PORT_PIN P4_4
#define ioss_0_port_4_pin_4 P4_4
#define ioss_0_port_4_pin_4_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define ioss_0_port_4_pin_4_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#define ioss_0_port_4_pin_4_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define ioss_0_port_4_pin_5_ENABLED 1U
#define ioss_0_port_4_pin_5_PORT GPIO_PRT4
#define ioss_0_port_4_pin_5_PORT_NUM 4U
#define ioss_0_port_4_pin_5_PIN 5U
#define ioss_0_port_4_pin_5_NUM 5U
#define ioss_0_port_4_pin_5_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define ioss_0_port_4_pin_5_INIT_DRIVESTATE 1
#ifndef ioss_0_port_4_pin_5_HSIOM
    #define ioss_0_port_4_pin_5_HSIOM HSIOM_SEL_GPIO
#endif
#define ioss_0_port_4_pin_5_IRQ ioss_interrupts_sec_gpio_4_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define ioss_0_port_4_pin_5_HAL_PORT_PIN P4_5
#define ioss_0_port_4_pin_5 P4_5
#define ioss_0_port_4_pin_5_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define ioss_0_port_4_pin_5_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#define ioss_0_port_4_pin_5_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define ioss_0_port_4_pin_6_ENABLED 1U
#define ioss_0_port_4_pin_6_PORT GPIO_PRT4
#define ioss_0_port_4_pin_6_PORT_NUM 4U
#define ioss_0_port_4_pin_6_PIN 6U
#define ioss_0_port_4_pin_6_NUM 6U
#define ioss_0_port_4_pin_6_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define ioss_0_port_4_pin_6_INIT_DRIVESTATE 1
#ifndef ioss_0_port_4_pin_6_HSIOM
    #define ioss_0_port_4_pin_6_HSIOM HSIOM_SEL_GPIO
#endif
#define ioss_0_port_4_pin_6_IRQ ioss_interrupts_sec_gpio_4_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define ioss_0_port_4_pin_6_HAL_PORT_PIN P4_6
#define ioss_0_port_4_pin_6 P4_6
#define ioss_0_port_4_pin_6_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define ioss_0_port_4_pin_6_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#define ioss_0_port_4_pin_6_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define ioss_0_port_4_pin_7_ENABLED 1U
#define ioss_0_port_4_pin_7_PORT GPIO_PRT4
#define ioss_0_port_4_pin_7_PORT_NUM 4U
#define ioss_0_port_4_pin_7_PIN 7U
#define ioss_0_port_4_pin_7_NUM 7U
#define ioss_0_port_4_pin_7_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define ioss_0_port_4_pin_7_INIT_DRIVESTATE 1
#ifndef ioss_0_port_4_pin_7_HSIOM
    #define ioss_0_port_4_pin_7_HSIOM HSIOM_SEL_GPIO
#endif
#define ioss_0_port_4_pin_7_IRQ ioss_interrupts_sec_gpio_4_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define ioss_0_port_4_pin_7_HAL_PORT_PIN P4_7
#define ioss_0_port_4_pin_7 P4_7
#define ioss_0_port_4_pin_7_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define ioss_0_port_4_pin_7_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#define ioss_0_port_4_pin_7_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define ioss_0_port_5_pin_0_ENABLED 1U
#define ioss_0_port_5_pin_0_PORT GPIO_PRT5
#define ioss_0_port_5_pin_0_PORT_NUM 5U
#define ioss_0_port_5_pin_0_PIN 0U
#define ioss_0_port_5_pin_0_NUM 0U
#define ioss_0_port_5_pin_0_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define ioss_0_port_5_pin_0_INIT_DRIVESTATE 1
#ifndef ioss_0_port_5_pin_0_HSIOM
    #define ioss_0_port_5_pin_0_HSIOM HSIOM_SEL_GPIO
#endif
#define ioss_0_port_5_pin_0_IRQ ioss_interrupts_sec_gpio_5_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define ioss_0_port_5_pin_0_HAL_PORT_PIN P5_0
#define ioss_0_port_5_pin_0 P5_0
#define ioss_0_port_5_pin_0_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define ioss_0_port_5_pin_0_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#define ioss_0_port_5_pin_0_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define ioss_0_port_5_pin_1_ENABLED 1U
#define ioss_0_port_5_pin_1_PORT GPIO_PRT5
#define ioss_0_port_5_pin_1_PORT_NUM 5U
#define ioss_0_port_5_pin_1_PIN 1U
#define ioss_0_port_5_pin_1_NUM 1U
#define ioss_0_port_5_pin_1_DRIVEMODE CY_GPIO_DM_HIGHZ
#define ioss_0_port_5_pin_1_INIT_DRIVESTATE 1
#ifndef ioss_0_port_5_pin_1_HSIOM
    #define ioss_0_port_5_pin_1_HSIOM HSIOM_SEL_GPIO
#endif
#define ioss_0_port_5_pin_1_IRQ ioss_interrupts_sec_gpio_5_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define ioss_0_port_5_pin_1_HAL_PORT_PIN P5_1
#define ioss_0_port_5_pin_1 P5_1
#define ioss_0_port_5_pin_1_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define ioss_0_port_5_pin_1_HAL_DIR CYHAL_GPIO_DIR_INPUT 
#define ioss_0_port_5_pin_1_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_NONE
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define ioss_0_port_5_pin_2_ENABLED 1U
#define ioss_0_port_5_pin_2_PORT GPIO_PRT5
#define ioss_0_port_5_pin_2_PORT_NUM 5U
#define ioss_0_port_5_pin_2_PIN 2U
#define ioss_0_port_5_pin_2_NUM 2U
#define ioss_0_port_5_pin_2_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define ioss_0_port_5_pin_2_INIT_DRIVESTATE 1
#ifndef ioss_0_port_5_pin_2_HSIOM
    #define ioss_0_port_5_pin_2_HSIOM HSIOM_SEL_GPIO
#endif
#define ioss_0_port_5_pin_2_IRQ ioss_interrupts_sec_gpio_5_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define ioss_0_port_5_pin_2_HAL_PORT_PIN P5_2
#define ioss_0_port_5_pin_2 P5_2
#define ioss_0_port_5_pin_2_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define ioss_0_port_5_pin_2_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#define ioss_0_port_5_pin_2_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define ioss_0_port_5_pin_3_ENABLED 1U
#define ioss_0_port_5_pin_3_PORT GPIO_PRT5
#define ioss_0_port_5_pin_3_PORT_NUM 5U
#define ioss_0_port_5_pin_3_PIN 3U
#define ioss_0_port_5_pin_3_NUM 3U
#define ioss_0_port_5_pin_3_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define ioss_0_port_5_pin_3_INIT_DRIVESTATE 1
#ifndef ioss_0_port_5_pin_3_HSIOM
    #define ioss_0_port_5_pin_3_HSIOM HSIOM_SEL_GPIO
#endif
#define ioss_0_port_5_pin_3_IRQ ioss_interrupts_sec_gpio_5_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define ioss_0_port_5_pin_3_HAL_PORT_PIN P5_3
#define ioss_0_port_5_pin_3 P5_3
#define ioss_0_port_5_pin_3_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define ioss_0_port_5_pin_3_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#define ioss_0_port_5_pin_3_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define GPIO_TEST_ENABLED 1U
#define GPIO_TEST_PORT GPIO_PRT6
#define GPIO_TEST_PORT_NUM 6U
#define GPIO_TEST_PIN 0U
#define GPIO_TEST_NUM 0U
#define GPIO_TEST_DRIVEMODE CY_GPIO_DM_STRONG
#define GPIO_TEST_INIT_DRIVESTATE 0
#ifndef ioss_0_port_6_pin_0_HSIOM
    #define ioss_0_port_6_pin_0_HSIOM HSIOM_SEL_GPIO
#endif
#define GPIO_TEST_HSIOM ioss_0_port_6_pin_0_HSIOM
#define GPIO_TEST_IRQ ioss_interrupts_sec_gpio_6_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define GPIO_TEST_HAL_PORT_PIN P6_0
#define GPIO_TEST P6_0
#define GPIO_TEST_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define GPIO_TEST_HAL_DIR CYHAL_GPIO_DIR_BIDIRECTIONAL 
#define GPIO_TEST_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define ioss_0_port_6_pin_1_ENABLED 1U
#define ioss_0_port_6_pin_1_PORT GPIO_PRT6
#define ioss_0_port_6_pin_1_PORT_NUM 6U
#define ioss_0_port_6_pin_1_PIN 1U
#define ioss_0_port_6_pin_1_NUM 1U
#define ioss_0_port_6_pin_1_DRIVEMODE CY_GPIO_DM_HIGHZ
#define ioss_0_port_6_pin_1_INIT_DRIVESTATE 0
#ifndef ioss_0_port_6_pin_1_HSIOM
    #define ioss_0_port_6_pin_1_HSIOM HSIOM_SEL_GPIO
#endif
#define ioss_0_port_6_pin_1_IRQ ioss_interrupts_sec_gpio_6_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define ioss_0_port_6_pin_1_HAL_PORT_PIN P6_1
#define ioss_0_port_6_pin_1 P6_1
#define ioss_0_port_6_pin_1_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define ioss_0_port_6_pin_1_HAL_DIR CYHAL_GPIO_DIR_INPUT 
#define ioss_0_port_6_pin_1_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_NONE
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define ioss_0_port_6_pin_2_ENABLED 1U
#define ioss_0_port_6_pin_2_PORT GPIO_PRT6
#define ioss_0_port_6_pin_2_PORT_NUM 6U
#define ioss_0_port_6_pin_2_PIN 2U
#define ioss_0_port_6_pin_2_NUM 2U
#define ioss_0_port_6_pin_2_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define ioss_0_port_6_pin_2_INIT_DRIVESTATE 1
#ifndef ioss_0_port_6_pin_2_HSIOM
    #define ioss_0_port_6_pin_2_HSIOM HSIOM_SEL_GPIO
#endif
#define ioss_0_port_6_pin_2_IRQ ioss_interrupts_sec_gpio_6_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define ioss_0_port_6_pin_2_HAL_PORT_PIN P6_2
#define ioss_0_port_6_pin_2 P6_2
#define ioss_0_port_6_pin_2_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define ioss_0_port_6_pin_2_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#define ioss_0_port_6_pin_2_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define ioss_0_port_6_pin_3_ENABLED 1U
#define ioss_0_port_6_pin_3_PORT GPIO_PRT6
#define ioss_0_port_6_pin_3_PORT_NUM 6U
#define ioss_0_port_6_pin_3_PIN 3U
#define ioss_0_port_6_pin_3_NUM 3U
#define ioss_0_port_6_pin_3_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define ioss_0_port_6_pin_3_INIT_DRIVESTATE 1
#ifndef ioss_0_port_6_pin_3_HSIOM
    #define ioss_0_port_6_pin_3_HSIOM HSIOM_SEL_GPIO
#endif
#define ioss_0_port_6_pin_3_IRQ ioss_interrupts_sec_gpio_6_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define ioss_0_port_6_pin_3_HAL_PORT_PIN P6_3
#define ioss_0_port_6_pin_3 P6_3
#define ioss_0_port_6_pin_3_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define ioss_0_port_6_pin_3_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#define ioss_0_port_6_pin_3_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define ioss_0_port_7_pin_0_ENABLED 1U
#define ioss_0_port_7_pin_0_PORT GPIO_PRT7
#define ioss_0_port_7_pin_0_PORT_NUM 7U
#define ioss_0_port_7_pin_0_PIN 0U
#define ioss_0_port_7_pin_0_NUM 0U
#define ioss_0_port_7_pin_0_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define ioss_0_port_7_pin_0_INIT_DRIVESTATE 1
#ifndef ioss_0_port_7_pin_0_HSIOM
    #define ioss_0_port_7_pin_0_HSIOM HSIOM_SEL_GPIO
#endif
#define ioss_0_port_7_pin_0_IRQ ioss_interrupts_sec_gpio_7_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define ioss_0_port_7_pin_0_HAL_PORT_PIN P7_0
#define ioss_0_port_7_pin_0 P7_0
#define ioss_0_port_7_pin_0_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define ioss_0_port_7_pin_0_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#define ioss_0_port_7_pin_0_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define ioss_0_port_7_pin_1_ENABLED 1U
#define ioss_0_port_7_pin_1_PORT GPIO_PRT7
#define ioss_0_port_7_pin_1_PORT_NUM 7U
#define ioss_0_port_7_pin_1_PIN 1U
#define ioss_0_port_7_pin_1_NUM 1U
#define ioss_0_port_7_pin_1_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define ioss_0_port_7_pin_1_INIT_DRIVESTATE 1
#ifndef ioss_0_port_7_pin_1_HSIOM
    #define ioss_0_port_7_pin_1_HSIOM HSIOM_SEL_GPIO
#endif
#define ioss_0_port_7_pin_1_IRQ ioss_interrupts_sec_gpio_7_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define ioss_0_port_7_pin_1_HAL_PORT_PIN P7_1
#define ioss_0_port_7_pin_1 P7_1
#define ioss_0_port_7_pin_1_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define ioss_0_port_7_pin_1_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#define ioss_0_port_7_pin_1_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define ioss_0_port_7_pin_2_ENABLED 1U
#define ioss_0_port_7_pin_2_PORT GPIO_PRT7
#define ioss_0_port_7_pin_2_PORT_NUM 7U
#define ioss_0_port_7_pin_2_PIN 2U
#define ioss_0_port_7_pin_2_NUM 2U
#define ioss_0_port_7_pin_2_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define ioss_0_port_7_pin_2_INIT_DRIVESTATE 1
#ifndef ioss_0_port_7_pin_2_HSIOM
    #define ioss_0_port_7_pin_2_HSIOM HSIOM_SEL_GPIO
#endif
#define ioss_0_port_7_pin_2_IRQ ioss_interrupts_sec_gpio_7_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define ioss_0_port_7_pin_2_HAL_PORT_PIN P7_2
#define ioss_0_port_7_pin_2 P7_2
#define ioss_0_port_7_pin_2_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define ioss_0_port_7_pin_2_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#define ioss_0_port_7_pin_2_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define ioss_0_port_7_pin_3_ENABLED 1U
#define ioss_0_port_7_pin_3_PORT GPIO_PRT7
#define ioss_0_port_7_pin_3_PORT_NUM 7U
#define ioss_0_port_7_pin_3_PIN 3U
#define ioss_0_port_7_pin_3_NUM 3U
#define ioss_0_port_7_pin_3_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define ioss_0_port_7_pin_3_INIT_DRIVESTATE 1
#ifndef ioss_0_port_7_pin_3_HSIOM
    #define ioss_0_port_7_pin_3_HSIOM HSIOM_SEL_GPIO
#endif
#define ioss_0_port_7_pin_3_IRQ ioss_interrupts_sec_gpio_7_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define ioss_0_port_7_pin_3_HAL_PORT_PIN P7_3
#define ioss_0_port_7_pin_3 P7_3
#define ioss_0_port_7_pin_3_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define ioss_0_port_7_pin_3_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#define ioss_0_port_7_pin_3_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define ioss_0_port_7_pin_4_ENABLED 1U
#define ioss_0_port_7_pin_4_PORT GPIO_PRT7
#define ioss_0_port_7_pin_4_PORT_NUM 7U
#define ioss_0_port_7_pin_4_PIN 4U
#define ioss_0_port_7_pin_4_NUM 4U
#define ioss_0_port_7_pin_4_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define ioss_0_port_7_pin_4_INIT_DRIVESTATE 1
#ifndef ioss_0_port_7_pin_4_HSIOM
    #define ioss_0_port_7_pin_4_HSIOM HSIOM_SEL_GPIO
#endif
#define ioss_0_port_7_pin_4_IRQ ioss_interrupts_sec_gpio_7_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define ioss_0_port_7_pin_4_HAL_PORT_PIN P7_4
#define ioss_0_port_7_pin_4 P7_4
#define ioss_0_port_7_pin_4_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define ioss_0_port_7_pin_4_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#define ioss_0_port_7_pin_4_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define GPIO_GD_A_ENABLE_ENABLED 1U
#define GPIO_GD_A_ENABLE_PORT GPIO_PRT7
#define GPIO_GD_A_ENABLE_PORT_NUM 7U
#define GPIO_GD_A_ENABLE_PIN 5U
#define GPIO_GD_A_ENABLE_NUM 5U
#define GPIO_GD_A_ENABLE_DRIVEMODE CY_GPIO_DM_STRONG
#define GPIO_GD_A_ENABLE_INIT_DRIVESTATE 1
#ifndef ioss_0_port_7_pin_5_HSIOM
    #define ioss_0_port_7_pin_5_HSIOM HSIOM_SEL_GPIO
#endif
#define GPIO_GD_A_ENABLE_HSIOM ioss_0_port_7_pin_5_HSIOM
#define GPIO_GD_A_ENABLE_IRQ ioss_interrupts_sec_gpio_7_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define GPIO_GD_A_ENABLE_HAL_PORT_PIN P7_5
#define GPIO_GD_A_ENABLE P7_5
#define GPIO_GD_A_ENABLE_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define GPIO_GD_A_ENABLE_HAL_DIR CYHAL_GPIO_DIR_BIDIRECTIONAL 
#define GPIO_GD_A_ENABLE_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define GPIO_GD_A_nFAULT_ENABLED 1U
#define GPIO_GD_A_nFAULT_PORT GPIO_PRT7
#define GPIO_GD_A_nFAULT_PORT_NUM 7U
#define GPIO_GD_A_nFAULT_PIN 6U
#define GPIO_GD_A_nFAULT_NUM 6U
#define GPIO_GD_A_nFAULT_DRIVEMODE CY_GPIO_DM_HIGHZ
#define GPIO_GD_A_nFAULT_INIT_DRIVESTATE 1
#ifndef ioss_0_port_7_pin_6_HSIOM
    #define ioss_0_port_7_pin_6_HSIOM HSIOM_SEL_GPIO
#endif
#define GPIO_GD_A_nFAULT_HSIOM ioss_0_port_7_pin_6_HSIOM
#define GPIO_GD_A_nFAULT_IRQ ioss_interrupts_sec_gpio_7_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define GPIO_GD_A_nFAULT_HAL_PORT_PIN P7_6
#define GPIO_GD_A_nFAULT P7_6
#define GPIO_GD_A_nFAULT_HAL_IRQ CYHAL_GPIO_IRQ_FALL
#define GPIO_GD_A_nFAULT_HAL_DIR CYHAL_GPIO_DIR_INPUT 
#define GPIO_GD_A_nFAULT_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_NONE
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define GPIO_GD_A_PULLUP_ENABLED 1U
#define GPIO_GD_A_PULLUP_PORT GPIO_PRT7
#define GPIO_GD_A_PULLUP_PORT_NUM 7U
#define GPIO_GD_A_PULLUP_PIN 7U
#define GPIO_GD_A_PULLUP_NUM 7U
#define GPIO_GD_A_PULLUP_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define GPIO_GD_A_PULLUP_INIT_DRIVESTATE 1
#ifndef ioss_0_port_7_pin_7_HSIOM
    #define ioss_0_port_7_pin_7_HSIOM HSIOM_SEL_GPIO
#endif
#define GPIO_GD_A_PULLUP_HSIOM ioss_0_port_7_pin_7_HSIOM
#define GPIO_GD_A_PULLUP_IRQ ioss_interrupts_sec_gpio_7_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define GPIO_GD_A_PULLUP_HAL_PORT_PIN P7_7
#define GPIO_GD_A_PULLUP P7_7
#define GPIO_GD_A_PULLUP_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define GPIO_GD_A_PULLUP_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#define GPIO_GD_A_PULLUP_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define ioss_0_port_8_pin_0_ENABLED 1U
#define ioss_0_port_8_pin_0_PORT GPIO_PRT8
#define ioss_0_port_8_pin_0_PORT_NUM 8U
#define ioss_0_port_8_pin_0_PIN 0U
#define ioss_0_port_8_pin_0_NUM 0U
#define ioss_0_port_8_pin_0_DRIVEMODE CY_GPIO_DM_HIGHZ
#define ioss_0_port_8_pin_0_INIT_DRIVESTATE 1
#ifndef ioss_0_port_8_pin_0_HSIOM
    #define ioss_0_port_8_pin_0_HSIOM HSIOM_SEL_GPIO
#endif
#define ioss_0_port_8_pin_0_IRQ ioss_interrupts_sec_gpio_8_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define ioss_0_port_8_pin_0_HAL_PORT_PIN P8_0
#define ioss_0_port_8_pin_0 P8_0
#define ioss_0_port_8_pin_0_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define ioss_0_port_8_pin_0_HAL_DIR CYHAL_GPIO_DIR_INPUT 
#define ioss_0_port_8_pin_0_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_NONE
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define ioss_0_port_8_pin_1_ENABLED 1U
#define ioss_0_port_8_pin_1_PORT GPIO_PRT8
#define ioss_0_port_8_pin_1_PORT_NUM 8U
#define ioss_0_port_8_pin_1_PIN 1U
#define ioss_0_port_8_pin_1_NUM 1U
#define ioss_0_port_8_pin_1_DRIVEMODE CY_GPIO_DM_HIGHZ
#define ioss_0_port_8_pin_1_INIT_DRIVESTATE 1
#ifndef ioss_0_port_8_pin_1_HSIOM
    #define ioss_0_port_8_pin_1_HSIOM HSIOM_SEL_GPIO
#endif
#define ioss_0_port_8_pin_1_IRQ ioss_interrupts_sec_gpio_8_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define ioss_0_port_8_pin_1_HAL_PORT_PIN P8_1
#define ioss_0_port_8_pin_1 P8_1
#define ioss_0_port_8_pin_1_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define ioss_0_port_8_pin_1_HAL_DIR CYHAL_GPIO_DIR_INPUT 
#define ioss_0_port_8_pin_1_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_NONE
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define ioss_0_port_8_pin_2_ENABLED 1U
#define ioss_0_port_8_pin_2_PORT GPIO_PRT8
#define ioss_0_port_8_pin_2_PORT_NUM 8U
#define ioss_0_port_8_pin_2_PIN 2U
#define ioss_0_port_8_pin_2_NUM 2U
#define ioss_0_port_8_pin_2_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define ioss_0_port_8_pin_2_INIT_DRIVESTATE 1
#ifndef ioss_0_port_8_pin_2_HSIOM
    #define ioss_0_port_8_pin_2_HSIOM HSIOM_SEL_GPIO
#endif
#define ioss_0_port_8_pin_2_IRQ ioss_interrupts_sec_gpio_8_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define ioss_0_port_8_pin_2_HAL_PORT_PIN P8_2
#define ioss_0_port_8_pin_2 P8_2
#define ioss_0_port_8_pin_2_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define ioss_0_port_8_pin_2_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#define ioss_0_port_8_pin_2_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define ioss_0_port_8_pin_3_ENABLED 1U
#define ioss_0_port_8_pin_3_PORT GPIO_PRT8
#define ioss_0_port_8_pin_3_PORT_NUM 8U
#define ioss_0_port_8_pin_3_PIN 3U
#define ioss_0_port_8_pin_3_NUM 3U
#define ioss_0_port_8_pin_3_DRIVEMODE CY_GPIO_DM_HIGHZ
#define ioss_0_port_8_pin_3_INIT_DRIVESTATE 1
#ifndef ioss_0_port_8_pin_3_HSIOM
    #define ioss_0_port_8_pin_3_HSIOM HSIOM_SEL_GPIO
#endif
#define ioss_0_port_8_pin_3_IRQ ioss_interrupts_sec_gpio_8_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define ioss_0_port_8_pin_3_HAL_PORT_PIN P8_3
#define ioss_0_port_8_pin_3 P8_3
#define ioss_0_port_8_pin_3_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define ioss_0_port_8_pin_3_HAL_DIR CYHAL_GPIO_DIR_INPUT 
#define ioss_0_port_8_pin_3_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_NONE
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define GPIO_CTR_INT1_ENABLED 1U
#define GPIO_CTR_INT1_PORT GPIO_PRT8
#define GPIO_CTR_INT1_PORT_NUM 8U
#define GPIO_CTR_INT1_PIN 4U
#define GPIO_CTR_INT1_NUM 4U
#define GPIO_CTR_INT1_DRIVEMODE CY_GPIO_DM_HIGHZ
#define GPIO_CTR_INT1_INIT_DRIVESTATE 0
#ifndef ioss_0_port_8_pin_4_HSIOM
    #define ioss_0_port_8_pin_4_HSIOM HSIOM_SEL_GPIO
#endif
#define GPIO_CTR_INT1_HSIOM ioss_0_port_8_pin_4_HSIOM
#define GPIO_CTR_INT1_IRQ ioss_interrupts_gpio_8_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define GPIO_CTR_INT1_HAL_PORT_PIN P8_4
#define GPIO_CTR_INT1 P8_4
#define GPIO_CTR_INT1_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define GPIO_CTR_INT1_HAL_DIR CYHAL_GPIO_DIR_INPUT 
#define GPIO_CTR_INT1_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_NONE
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define GPIO_CTR_INT2_ENABLED 1U
#define GPIO_CTR_INT2_PORT GPIO_PRT8
#define GPIO_CTR_INT2_PORT_NUM 8U
#define GPIO_CTR_INT2_PIN 5U
#define GPIO_CTR_INT2_NUM 5U
#define GPIO_CTR_INT2_DRIVEMODE CY_GPIO_DM_STRONG
#define GPIO_CTR_INT2_INIT_DRIVESTATE 0
#ifndef ioss_0_port_8_pin_5_HSIOM
    #define ioss_0_port_8_pin_5_HSIOM HSIOM_SEL_GPIO
#endif
#define GPIO_CTR_INT2_HSIOM ioss_0_port_8_pin_5_HSIOM
#define GPIO_CTR_INT2_IRQ ioss_interrupts_sec_gpio_8_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define GPIO_CTR_INT2_HAL_PORT_PIN P8_5
#define GPIO_CTR_INT2 P8_5
#define GPIO_CTR_INT2_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define GPIO_CTR_INT2_HAL_DIR CYHAL_GPIO_DIR_BIDIRECTIONAL 
#define GPIO_CTR_INT2_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define ioss_0_port_9_pin_0_ENABLED 1U
#define ioss_0_port_9_pin_0_PORT GPIO_PRT9
#define ioss_0_port_9_pin_0_PORT_NUM 9U
#define ioss_0_port_9_pin_0_PIN 0U
#define ioss_0_port_9_pin_0_NUM 0U
#define ioss_0_port_9_pin_0_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define ioss_0_port_9_pin_0_INIT_DRIVESTATE 1
#ifndef ioss_0_port_9_pin_0_HSIOM
    #define ioss_0_port_9_pin_0_HSIOM HSIOM_SEL_GPIO
#endif
#define ioss_0_port_9_pin_0_IRQ ioss_interrupts_sec_gpio_9_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define ioss_0_port_9_pin_0_HAL_PORT_PIN P9_0
#define ioss_0_port_9_pin_0 P9_0
#define ioss_0_port_9_pin_0_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define ioss_0_port_9_pin_0_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#define ioss_0_port_9_pin_0_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define ioss_0_port_9_pin_1_ENABLED 1U
#define ioss_0_port_9_pin_1_PORT GPIO_PRT9
#define ioss_0_port_9_pin_1_PORT_NUM 9U
#define ioss_0_port_9_pin_1_PIN 1U
#define ioss_0_port_9_pin_1_NUM 1U
#define ioss_0_port_9_pin_1_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define ioss_0_port_9_pin_1_INIT_DRIVESTATE 1
#ifndef ioss_0_port_9_pin_1_HSIOM
    #define ioss_0_port_9_pin_1_HSIOM HSIOM_SEL_GPIO
#endif
#define ioss_0_port_9_pin_1_IRQ ioss_interrupts_sec_gpio_9_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define ioss_0_port_9_pin_1_HAL_PORT_PIN P9_1
#define ioss_0_port_9_pin_1 P9_1
#define ioss_0_port_9_pin_1_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define ioss_0_port_9_pin_1_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#define ioss_0_port_9_pin_1_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define ioss_0_port_9_pin_2_ENABLED 1U
#define ioss_0_port_9_pin_2_PORT GPIO_PRT9
#define ioss_0_port_9_pin_2_PORT_NUM 9U
#define ioss_0_port_9_pin_2_PIN 2U
#define ioss_0_port_9_pin_2_NUM 2U
#define ioss_0_port_9_pin_2_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define ioss_0_port_9_pin_2_INIT_DRIVESTATE 1
#ifndef ioss_0_port_9_pin_2_HSIOM
    #define ioss_0_port_9_pin_2_HSIOM HSIOM_SEL_GPIO
#endif
#define ioss_0_port_9_pin_2_IRQ ioss_interrupts_sec_gpio_9_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define ioss_0_port_9_pin_2_HAL_PORT_PIN P9_2
#define ioss_0_port_9_pin_2 P9_2
#define ioss_0_port_9_pin_2_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define ioss_0_port_9_pin_2_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#define ioss_0_port_9_pin_2_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define ioss_0_port_9_pin_3_ENABLED 1U
#define ioss_0_port_9_pin_3_PORT GPIO_PRT9
#define ioss_0_port_9_pin_3_PORT_NUM 9U
#define ioss_0_port_9_pin_3_PIN 3U
#define ioss_0_port_9_pin_3_NUM 3U
#define ioss_0_port_9_pin_3_DRIVEMODE CY_GPIO_DM_HIGHZ
#define ioss_0_port_9_pin_3_INIT_DRIVESTATE 1
#ifndef ioss_0_port_9_pin_3_HSIOM
    #define ioss_0_port_9_pin_3_HSIOM HSIOM_SEL_GPIO
#endif
#define ioss_0_port_9_pin_3_IRQ ioss_interrupts_sec_gpio_9_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define ioss_0_port_9_pin_3_HAL_PORT_PIN P9_3
#define ioss_0_port_9_pin_3 P9_3
#define ioss_0_port_9_pin_3_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define ioss_0_port_9_pin_3_HAL_DIR CYHAL_GPIO_DIR_INPUT 
#define ioss_0_port_9_pin_3_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_NONE
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define ioss_0_port_9_pin_4_ENABLED 1U
#define ioss_0_port_9_pin_4_PORT GPIO_PRT9
#define ioss_0_port_9_pin_4_PORT_NUM 9U
#define ioss_0_port_9_pin_4_PIN 4U
#define ioss_0_port_9_pin_4_NUM 4U
#define ioss_0_port_9_pin_4_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define ioss_0_port_9_pin_4_INIT_DRIVESTATE 1
#ifndef ioss_0_port_9_pin_4_HSIOM
    #define ioss_0_port_9_pin_4_HSIOM HSIOM_SEL_GPIO
#endif
#define ioss_0_port_9_pin_4_IRQ ioss_interrupts_sec_gpio_9_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define ioss_0_port_9_pin_4_HAL_PORT_PIN P9_4
#define ioss_0_port_9_pin_4 P9_4
#define ioss_0_port_9_pin_4_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define ioss_0_port_9_pin_4_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#define ioss_0_port_9_pin_4_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define ioss_0_port_9_pin_5_ENABLED 1U
#define ioss_0_port_9_pin_5_PORT GPIO_PRT9
#define ioss_0_port_9_pin_5_PORT_NUM 9U
#define ioss_0_port_9_pin_5_PIN 5U
#define ioss_0_port_9_pin_5_NUM 5U
#define ioss_0_port_9_pin_5_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define ioss_0_port_9_pin_5_INIT_DRIVESTATE 1
#ifndef ioss_0_port_9_pin_5_HSIOM
    #define ioss_0_port_9_pin_5_HSIOM HSIOM_SEL_GPIO
#endif
#define ioss_0_port_9_pin_5_IRQ ioss_interrupts_sec_gpio_9_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define ioss_0_port_9_pin_5_HAL_PORT_PIN P9_5
#define ioss_0_port_9_pin_5 P9_5
#define ioss_0_port_9_pin_5_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define ioss_0_port_9_pin_5_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#define ioss_0_port_9_pin_5_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t ioss_0_port_0_pin_0_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t ioss_0_port_0_pin_0_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t ioss_0_port_1_pin_0_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t ioss_0_port_1_pin_0_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t ioss_0_port_1_pin_1_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t ioss_0_port_1_pin_1_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t ioss_0_port_1_pin_2_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t ioss_0_port_1_pin_2_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t ioss_0_port_1_pin_3_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t ioss_0_port_1_pin_3_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t ioss_0_port_2_pin_0_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t ioss_0_port_2_pin_0_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t ioss_0_port_2_pin_1_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t ioss_0_port_2_pin_1_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t ioss_0_port_2_pin_2_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t ioss_0_port_2_pin_2_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t ioss_0_port_2_pin_3_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t ioss_0_port_2_pin_3_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t ioss_0_port_3_pin_0_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t ioss_0_port_3_pin_0_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t ioss_0_port_3_pin_1_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t ioss_0_port_3_pin_1_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t GPIO_GD_C_ENABLE_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t GPIO_GD_C_ENABLE_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t GPIO_GD_C_nFAULT_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t GPIO_GD_C_nFAULT_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t GPIO_GD_B_nFAULT_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t GPIO_GD_B_nFAULT_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t GPIO_GD_B_ENABLE_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t GPIO_GD_B_ENABLE_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t ioss_0_port_4_pin_2_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t ioss_0_port_4_pin_2_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t ioss_0_port_4_pin_3_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t ioss_0_port_4_pin_3_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t ioss_0_port_4_pin_4_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t ioss_0_port_4_pin_4_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t ioss_0_port_4_pin_5_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t ioss_0_port_4_pin_5_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t ioss_0_port_4_pin_6_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t ioss_0_port_4_pin_6_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t ioss_0_port_4_pin_7_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t ioss_0_port_4_pin_7_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t ioss_0_port_5_pin_0_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t ioss_0_port_5_pin_0_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t ioss_0_port_5_pin_1_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t ioss_0_port_5_pin_1_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t ioss_0_port_5_pin_2_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t ioss_0_port_5_pin_2_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t ioss_0_port_5_pin_3_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t ioss_0_port_5_pin_3_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t GPIO_TEST_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t GPIO_TEST_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t ioss_0_port_6_pin_1_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t ioss_0_port_6_pin_1_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t ioss_0_port_6_pin_2_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t ioss_0_port_6_pin_2_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t ioss_0_port_6_pin_3_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t ioss_0_port_6_pin_3_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t ioss_0_port_7_pin_0_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t ioss_0_port_7_pin_0_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t ioss_0_port_7_pin_1_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t ioss_0_port_7_pin_1_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t ioss_0_port_7_pin_2_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t ioss_0_port_7_pin_2_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t ioss_0_port_7_pin_3_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t ioss_0_port_7_pin_3_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t ioss_0_port_7_pin_4_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t ioss_0_port_7_pin_4_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t GPIO_GD_A_ENABLE_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t GPIO_GD_A_ENABLE_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t GPIO_GD_A_nFAULT_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t GPIO_GD_A_nFAULT_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t GPIO_GD_A_PULLUP_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t GPIO_GD_A_PULLUP_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t ioss_0_port_8_pin_0_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t ioss_0_port_8_pin_0_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t ioss_0_port_8_pin_1_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t ioss_0_port_8_pin_1_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t ioss_0_port_8_pin_2_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t ioss_0_port_8_pin_2_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t ioss_0_port_8_pin_3_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t ioss_0_port_8_pin_3_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t GPIO_CTR_INT1_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t GPIO_CTR_INT1_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t GPIO_CTR_INT2_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t GPIO_CTR_INT2_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t ioss_0_port_9_pin_0_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t ioss_0_port_9_pin_0_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t ioss_0_port_9_pin_1_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t ioss_0_port_9_pin_1_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t ioss_0_port_9_pin_2_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t ioss_0_port_9_pin_2_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t ioss_0_port_9_pin_3_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t ioss_0_port_9_pin_3_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t ioss_0_port_9_pin_4_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t ioss_0_port_9_pin_4_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t ioss_0_port_9_pin_5_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t ioss_0_port_9_pin_5_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

void init_cycfg_pins(void);
void reserve_cycfg_pins(void);

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* CYCFG_PINS_H */
