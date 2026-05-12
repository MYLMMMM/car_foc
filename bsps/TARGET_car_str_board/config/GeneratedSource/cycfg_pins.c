/*******************************************************************************
 * File Name: cycfg_pins.c
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

#include "cycfg_pins.h"

const cy_stc_gpio_pin_config_t ioss_0_port_0_pin_0_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_HIGHZ,
    .hsiom = ioss_0_port_0_pin_0_HSIOM,
    .intEdge = CY_GPIO_INTR_FALLING,
    .intMask = 1UL,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
    .driveSel = CY_GPIO_DRIVE_1_2,
    .vregEn = 0UL,
    .ibufMode = 0UL,
    .vtripSel = 0UL,
    .vrefSel = 0UL,
    .vohSel = 0UL,
    .nonSec = 0,
};

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
const cyhal_resource_inst_t ioss_0_port_0_pin_0_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = ioss_0_port_0_pin_0_PORT_NUM,
    .channel_num = ioss_0_port_0_pin_0_PIN,
};
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

const cy_stc_gpio_pin_config_t ioss_0_port_1_pin_0_config =
{
    .outVal = 0,
    .driveMode = CY_GPIO_DM_ANALOG,
    .hsiom = ioss_0_port_1_pin_0_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .intMask = 0UL,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
    .driveSel = CY_GPIO_DRIVE_1_2,
    .vregEn = 0UL,
    .ibufMode = 0UL,
    .vtripSel = 0UL,
    .vrefSel = 0UL,
    .vohSel = 0UL,
    .nonSec = 0,
};

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
const cyhal_resource_inst_t ioss_0_port_1_pin_0_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = ioss_0_port_1_pin_0_PORT_NUM,
    .channel_num = ioss_0_port_1_pin_0_PIN,
};
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

const cy_stc_gpio_pin_config_t ioss_0_port_1_pin_1_config =
{
    .outVal = 0,
    .driveMode = CY_GPIO_DM_ANALOG,
    .hsiom = ioss_0_port_1_pin_1_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .intMask = 0UL,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
    .driveSel = CY_GPIO_DRIVE_1_2,
    .vregEn = 0UL,
    .ibufMode = 0UL,
    .vtripSel = 0UL,
    .vrefSel = 0UL,
    .vohSel = 0UL,
    .nonSec = 0,
};

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
const cyhal_resource_inst_t ioss_0_port_1_pin_1_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = ioss_0_port_1_pin_1_PORT_NUM,
    .channel_num = ioss_0_port_1_pin_1_PIN,
};
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

const cy_stc_gpio_pin_config_t ioss_0_port_1_pin_2_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_PULLDOWN,
    .hsiom = ioss_0_port_1_pin_2_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .intMask = 0UL,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
    .driveSel = CY_GPIO_DRIVE_1_2,
    .vregEn = 0UL,
    .ibufMode = 0UL,
    .vtripSel = 0UL,
    .vrefSel = 0UL,
    .vohSel = 0UL,
    .nonSec = 0,
};

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
const cyhal_resource_inst_t ioss_0_port_1_pin_2_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = ioss_0_port_1_pin_2_PORT_NUM,
    .channel_num = ioss_0_port_1_pin_2_PIN,
};
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

const cy_stc_gpio_pin_config_t ioss_0_port_1_pin_3_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_PULLUP,
    .hsiom = ioss_0_port_1_pin_3_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .intMask = 0UL,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
    .driveSel = CY_GPIO_DRIVE_1_2,
    .vregEn = 0UL,
    .ibufMode = 0UL,
    .vtripSel = 0UL,
    .vrefSel = 0UL,
    .vohSel = 0UL,
    .nonSec = 0,
};

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
const cyhal_resource_inst_t ioss_0_port_1_pin_3_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = ioss_0_port_1_pin_3_PORT_NUM,
    .channel_num = ioss_0_port_1_pin_3_PIN,
};
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

const cy_stc_gpio_pin_config_t ioss_0_port_2_pin_0_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,
    .hsiom = ioss_0_port_2_pin_0_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .intMask = 0UL,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
    .driveSel = CY_GPIO_DRIVE_1_2,
    .vregEn = 0UL,
    .ibufMode = 0UL,
    .vtripSel = 0UL,
    .vrefSel = 0UL,
    .vohSel = 0UL,
    .nonSec = 0,
};

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
const cyhal_resource_inst_t ioss_0_port_2_pin_0_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = ioss_0_port_2_pin_0_PORT_NUM,
    .channel_num = ioss_0_port_2_pin_0_PIN,
};
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

const cy_stc_gpio_pin_config_t ioss_0_port_2_pin_1_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,
    .hsiom = ioss_0_port_2_pin_1_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .intMask = 0UL,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
    .driveSel = CY_GPIO_DRIVE_1_2,
    .vregEn = 0UL,
    .ibufMode = 0UL,
    .vtripSel = 0UL,
    .vrefSel = 0UL,
    .vohSel = 0UL,
    .nonSec = 0,
};

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
const cyhal_resource_inst_t ioss_0_port_2_pin_1_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = ioss_0_port_2_pin_1_PORT_NUM,
    .channel_num = ioss_0_port_2_pin_1_PIN,
};
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

const cy_stc_gpio_pin_config_t ioss_0_port_2_pin_2_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,
    .hsiom = ioss_0_port_2_pin_2_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .intMask = 0UL,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
    .driveSel = CY_GPIO_DRIVE_1_2,
    .vregEn = 0UL,
    .ibufMode = 0UL,
    .vtripSel = 0UL,
    .vrefSel = 0UL,
    .vohSel = 0UL,
    .nonSec = 0,
};

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
const cyhal_resource_inst_t ioss_0_port_2_pin_2_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = ioss_0_port_2_pin_2_PORT_NUM,
    .channel_num = ioss_0_port_2_pin_2_PIN,
};
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

const cy_stc_gpio_pin_config_t ioss_0_port_2_pin_3_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_HIGHZ,
    .hsiom = ioss_0_port_2_pin_3_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .intMask = 0UL,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
    .driveSel = CY_GPIO_DRIVE_1_2,
    .vregEn = 0UL,
    .ibufMode = 0UL,
    .vtripSel = 0UL,
    .vrefSel = 0UL,
    .vohSel = 0UL,
    .nonSec = 0,
};

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
const cyhal_resource_inst_t ioss_0_port_2_pin_3_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = ioss_0_port_2_pin_3_PORT_NUM,
    .channel_num = ioss_0_port_2_pin_3_PIN,
};
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

const cy_stc_gpio_pin_config_t ioss_0_port_3_pin_0_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,
    .hsiom = ioss_0_port_3_pin_0_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .intMask = 0UL,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
    .driveSel = CY_GPIO_DRIVE_1_2,
    .vregEn = 0UL,
    .ibufMode = 0UL,
    .vtripSel = 0UL,
    .vrefSel = 0UL,
    .vohSel = 0UL,
    .nonSec = 0,
};

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
const cyhal_resource_inst_t ioss_0_port_3_pin_0_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = ioss_0_port_3_pin_0_PORT_NUM,
    .channel_num = ioss_0_port_3_pin_0_PIN,
};
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

const cy_stc_gpio_pin_config_t ioss_0_port_3_pin_1_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,
    .hsiom = ioss_0_port_3_pin_1_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .intMask = 0UL,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
    .driveSel = CY_GPIO_DRIVE_1_2,
    .vregEn = 0UL,
    .ibufMode = 0UL,
    .vtripSel = 0UL,
    .vrefSel = 0UL,
    .vohSel = 0UL,
    .nonSec = 0,
};

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
const cyhal_resource_inst_t ioss_0_port_3_pin_1_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = ioss_0_port_3_pin_1_PORT_NUM,
    .channel_num = ioss_0_port_3_pin_1_PIN,
};
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

const cy_stc_gpio_pin_config_t GPIO_GD_C_ENABLE_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,
    .hsiom = GPIO_GD_C_ENABLE_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .intMask = 0UL,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
    .driveSel = CY_GPIO_DRIVE_1_2,
    .vregEn = 0UL,
    .ibufMode = 0UL,
    .vtripSel = 0UL,
    .vrefSel = 0UL,
    .vohSel = 0UL,
    .nonSec = 0,
};

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
const cyhal_resource_inst_t GPIO_GD_C_ENABLE_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = GPIO_GD_C_ENABLE_PORT_NUM,
    .channel_num = GPIO_GD_C_ENABLE_PIN,
};
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

const cy_stc_gpio_pin_config_t GPIO_GD_C_nFAULT_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_HIGHZ,
    .hsiom = GPIO_GD_C_nFAULT_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .intMask = 0UL,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
    .driveSel = CY_GPIO_DRIVE_1_2,
    .vregEn = 0UL,
    .ibufMode = 0UL,
    .vtripSel = 0UL,
    .vrefSel = 0UL,
    .vohSel = 0UL,
    .nonSec = 0,
};

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
const cyhal_resource_inst_t GPIO_GD_C_nFAULT_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = GPIO_GD_C_nFAULT_PORT_NUM,
    .channel_num = GPIO_GD_C_nFAULT_PIN,
};
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

const cy_stc_gpio_pin_config_t GPIO_GD_B_nFAULT_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,
    .hsiom = GPIO_GD_B_nFAULT_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .intMask = 0UL,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
    .driveSel = CY_GPIO_DRIVE_1_2,
    .vregEn = 0UL,
    .ibufMode = 0UL,
    .vtripSel = 0UL,
    .vrefSel = 0UL,
    .vohSel = 0UL,
    .nonSec = 0,
};

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
const cyhal_resource_inst_t GPIO_GD_B_nFAULT_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = GPIO_GD_B_nFAULT_PORT_NUM,
    .channel_num = GPIO_GD_B_nFAULT_PIN,
};
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

const cy_stc_gpio_pin_config_t GPIO_GD_B_ENABLE_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_HIGHZ,
    .hsiom = GPIO_GD_B_ENABLE_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .intMask = 0UL,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
    .driveSel = CY_GPIO_DRIVE_1_2,
    .vregEn = 0UL,
    .ibufMode = 0UL,
    .vtripSel = 0UL,
    .vrefSel = 0UL,
    .vohSel = 0UL,
    .nonSec = 0,
};

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
const cyhal_resource_inst_t GPIO_GD_B_ENABLE_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = GPIO_GD_B_ENABLE_PORT_NUM,
    .channel_num = GPIO_GD_B_ENABLE_PIN,
};
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

const cy_stc_gpio_pin_config_t ioss_0_port_4_pin_2_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,
    .hsiom = ioss_0_port_4_pin_2_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .intMask = 0UL,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
    .driveSel = CY_GPIO_DRIVE_1_2,
    .vregEn = 0UL,
    .ibufMode = 0UL,
    .vtripSel = 0UL,
    .vrefSel = 0UL,
    .vohSel = 0UL,
    .nonSec = 0,
};

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
const cyhal_resource_inst_t ioss_0_port_4_pin_2_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = ioss_0_port_4_pin_2_PORT_NUM,
    .channel_num = ioss_0_port_4_pin_2_PIN,
};
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

const cy_stc_gpio_pin_config_t ioss_0_port_4_pin_3_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,
    .hsiom = ioss_0_port_4_pin_3_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .intMask = 0UL,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
    .driveSel = CY_GPIO_DRIVE_1_2,
    .vregEn = 0UL,
    .ibufMode = 0UL,
    .vtripSel = 0UL,
    .vrefSel = 0UL,
    .vohSel = 0UL,
    .nonSec = 0,
};

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
const cyhal_resource_inst_t ioss_0_port_4_pin_3_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = ioss_0_port_4_pin_3_PORT_NUM,
    .channel_num = ioss_0_port_4_pin_3_PIN,
};
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

const cy_stc_gpio_pin_config_t ioss_0_port_4_pin_4_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,
    .hsiom = ioss_0_port_4_pin_4_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .intMask = 0UL,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
    .driveSel = CY_GPIO_DRIVE_1_2,
    .vregEn = 0UL,
    .ibufMode = 0UL,
    .vtripSel = 0UL,
    .vrefSel = 0UL,
    .vohSel = 0UL,
    .nonSec = 0,
};

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
const cyhal_resource_inst_t ioss_0_port_4_pin_4_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = ioss_0_port_4_pin_4_PORT_NUM,
    .channel_num = ioss_0_port_4_pin_4_PIN,
};
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

const cy_stc_gpio_pin_config_t ioss_0_port_4_pin_5_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,
    .hsiom = ioss_0_port_4_pin_5_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .intMask = 0UL,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
    .driveSel = CY_GPIO_DRIVE_1_2,
    .vregEn = 0UL,
    .ibufMode = 0UL,
    .vtripSel = 0UL,
    .vrefSel = 0UL,
    .vohSel = 0UL,
    .nonSec = 0,
};

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
const cyhal_resource_inst_t ioss_0_port_4_pin_5_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = ioss_0_port_4_pin_5_PORT_NUM,
    .channel_num = ioss_0_port_4_pin_5_PIN,
};
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

const cy_stc_gpio_pin_config_t ioss_0_port_4_pin_6_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,
    .hsiom = ioss_0_port_4_pin_6_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .intMask = 0UL,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
    .driveSel = CY_GPIO_DRIVE_1_2,
    .vregEn = 0UL,
    .ibufMode = 0UL,
    .vtripSel = 0UL,
    .vrefSel = 0UL,
    .vohSel = 0UL,
    .nonSec = 0,
};

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
const cyhal_resource_inst_t ioss_0_port_4_pin_6_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = ioss_0_port_4_pin_6_PORT_NUM,
    .channel_num = ioss_0_port_4_pin_6_PIN,
};
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

const cy_stc_gpio_pin_config_t ioss_0_port_4_pin_7_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,
    .hsiom = ioss_0_port_4_pin_7_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .intMask = 0UL,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
    .driveSel = CY_GPIO_DRIVE_1_2,
    .vregEn = 0UL,
    .ibufMode = 0UL,
    .vtripSel = 0UL,
    .vrefSel = 0UL,
    .vohSel = 0UL,
    .nonSec = 0,
};

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
const cyhal_resource_inst_t ioss_0_port_4_pin_7_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = ioss_0_port_4_pin_7_PORT_NUM,
    .channel_num = ioss_0_port_4_pin_7_PIN,
};
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

const cy_stc_gpio_pin_config_t ioss_0_port_5_pin_0_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,
    .hsiom = ioss_0_port_5_pin_0_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .intMask = 0UL,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
    .driveSel = CY_GPIO_DRIVE_1_2,
    .vregEn = 0UL,
    .ibufMode = 0UL,
    .vtripSel = 0UL,
    .vrefSel = 0UL,
    .vohSel = 0UL,
    .nonSec = 0,
};

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
const cyhal_resource_inst_t ioss_0_port_5_pin_0_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = ioss_0_port_5_pin_0_PORT_NUM,
    .channel_num = ioss_0_port_5_pin_0_PIN,
};
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

const cy_stc_gpio_pin_config_t ioss_0_port_5_pin_1_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_HIGHZ,
    .hsiom = ioss_0_port_5_pin_1_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .intMask = 0UL,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
    .driveSel = CY_GPIO_DRIVE_1_2,
    .vregEn = 0UL,
    .ibufMode = 0UL,
    .vtripSel = 0UL,
    .vrefSel = 0UL,
    .vohSel = 0UL,
    .nonSec = 0,
};

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
const cyhal_resource_inst_t ioss_0_port_5_pin_1_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = ioss_0_port_5_pin_1_PORT_NUM,
    .channel_num = ioss_0_port_5_pin_1_PIN,
};
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

const cy_stc_gpio_pin_config_t ioss_0_port_5_pin_2_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,
    .hsiom = ioss_0_port_5_pin_2_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .intMask = 0UL,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
    .driveSel = CY_GPIO_DRIVE_1_2,
    .vregEn = 0UL,
    .ibufMode = 0UL,
    .vtripSel = 0UL,
    .vrefSel = 0UL,
    .vohSel = 0UL,
    .nonSec = 0,
};

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
const cyhal_resource_inst_t ioss_0_port_5_pin_2_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = ioss_0_port_5_pin_2_PORT_NUM,
    .channel_num = ioss_0_port_5_pin_2_PIN,
};
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

const cy_stc_gpio_pin_config_t ioss_0_port_5_pin_3_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,
    .hsiom = ioss_0_port_5_pin_3_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .intMask = 0UL,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
    .driveSel = CY_GPIO_DRIVE_1_2,
    .vregEn = 0UL,
    .ibufMode = 0UL,
    .vtripSel = 0UL,
    .vrefSel = 0UL,
    .vohSel = 0UL,
    .nonSec = 0,
};

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
const cyhal_resource_inst_t ioss_0_port_5_pin_3_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = ioss_0_port_5_pin_3_PORT_NUM,
    .channel_num = ioss_0_port_5_pin_3_PIN,
};
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

const cy_stc_gpio_pin_config_t ioss_0_port_6_pin_0_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_STRONG,
    .hsiom = ioss_0_port_6_pin_0_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .intMask = 0UL,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
    .driveSel = CY_GPIO_DRIVE_1_2,
    .vregEn = 0UL,
    .ibufMode = 0UL,
    .vtripSel = 0UL,
    .vrefSel = 0UL,
    .vohSel = 0UL,
    .nonSec = 0,
};

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
const cyhal_resource_inst_t ioss_0_port_6_pin_0_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = ioss_0_port_6_pin_0_PORT_NUM,
    .channel_num = ioss_0_port_6_pin_0_PIN,
};
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

const cy_stc_gpio_pin_config_t ioss_0_port_6_pin_1_config =
{
    .outVal = 0,
    .driveMode = CY_GPIO_DM_HIGHZ,
    .hsiom = ioss_0_port_6_pin_1_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .intMask = 0UL,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
    .driveSel = CY_GPIO_DRIVE_1_2,
    .vregEn = 0UL,
    .ibufMode = 0UL,
    .vtripSel = 0UL,
    .vrefSel = 0UL,
    .vohSel = 0UL,
    .nonSec = 0,
};

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
const cyhal_resource_inst_t ioss_0_port_6_pin_1_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = ioss_0_port_6_pin_1_PORT_NUM,
    .channel_num = ioss_0_port_6_pin_1_PIN,
};
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

const cy_stc_gpio_pin_config_t ioss_0_port_6_pin_2_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,
    .hsiom = ioss_0_port_6_pin_2_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .intMask = 0UL,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
    .driveSel = CY_GPIO_DRIVE_1_2,
    .vregEn = 0UL,
    .ibufMode = 0UL,
    .vtripSel = 0UL,
    .vrefSel = 0UL,
    .vohSel = 0UL,
    .nonSec = 0,
};

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
const cyhal_resource_inst_t ioss_0_port_6_pin_2_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = ioss_0_port_6_pin_2_PORT_NUM,
    .channel_num = ioss_0_port_6_pin_2_PIN,
};
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

const cy_stc_gpio_pin_config_t ioss_0_port_6_pin_3_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,
    .hsiom = ioss_0_port_6_pin_3_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .intMask = 0UL,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
    .driveSel = CY_GPIO_DRIVE_1_2,
    .vregEn = 0UL,
    .ibufMode = 0UL,
    .vtripSel = 0UL,
    .vrefSel = 0UL,
    .vohSel = 0UL,
    .nonSec = 0,
};

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
const cyhal_resource_inst_t ioss_0_port_6_pin_3_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = ioss_0_port_6_pin_3_PORT_NUM,
    .channel_num = ioss_0_port_6_pin_3_PIN,
};
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

const cy_stc_gpio_pin_config_t ioss_0_port_7_pin_0_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,
    .hsiom = ioss_0_port_7_pin_0_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .intMask = 0UL,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
    .driveSel = CY_GPIO_DRIVE_1_2,
    .vregEn = 0UL,
    .ibufMode = 0UL,
    .vtripSel = 0UL,
    .vrefSel = 0UL,
    .vohSel = 0UL,
    .nonSec = 0,
};

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
const cyhal_resource_inst_t ioss_0_port_7_pin_0_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = ioss_0_port_7_pin_0_PORT_NUM,
    .channel_num = ioss_0_port_7_pin_0_PIN,
};
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

const cy_stc_gpio_pin_config_t ioss_0_port_7_pin_1_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,
    .hsiom = ioss_0_port_7_pin_1_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .intMask = 0UL,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
    .driveSel = CY_GPIO_DRIVE_1_2,
    .vregEn = 0UL,
    .ibufMode = 0UL,
    .vtripSel = 0UL,
    .vrefSel = 0UL,
    .vohSel = 0UL,
    .nonSec = 0,
};

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
const cyhal_resource_inst_t ioss_0_port_7_pin_1_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = ioss_0_port_7_pin_1_PORT_NUM,
    .channel_num = ioss_0_port_7_pin_1_PIN,
};
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

const cy_stc_gpio_pin_config_t ioss_0_port_7_pin_2_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,
    .hsiom = ioss_0_port_7_pin_2_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .intMask = 0UL,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
    .driveSel = CY_GPIO_DRIVE_1_2,
    .vregEn = 0UL,
    .ibufMode = 0UL,
    .vtripSel = 0UL,
    .vrefSel = 0UL,
    .vohSel = 0UL,
    .nonSec = 0,
};

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
const cyhal_resource_inst_t ioss_0_port_7_pin_2_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = ioss_0_port_7_pin_2_PORT_NUM,
    .channel_num = ioss_0_port_7_pin_2_PIN,
};
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

const cy_stc_gpio_pin_config_t ioss_0_port_7_pin_3_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,
    .hsiom = ioss_0_port_7_pin_3_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .intMask = 0UL,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
    .driveSel = CY_GPIO_DRIVE_1_2,
    .vregEn = 0UL,
    .ibufMode = 0UL,
    .vtripSel = 0UL,
    .vrefSel = 0UL,
    .vohSel = 0UL,
    .nonSec = 0,
};

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
const cyhal_resource_inst_t ioss_0_port_7_pin_3_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = ioss_0_port_7_pin_3_PORT_NUM,
    .channel_num = ioss_0_port_7_pin_3_PIN,
};
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

const cy_stc_gpio_pin_config_t ioss_0_port_7_pin_4_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,
    .hsiom = ioss_0_port_7_pin_4_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .intMask = 0UL,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
    .driveSel = CY_GPIO_DRIVE_1_2,
    .vregEn = 0UL,
    .ibufMode = 0UL,
    .vtripSel = 0UL,
    .vrefSel = 0UL,
    .vohSel = 0UL,
    .nonSec = 0,
};

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
const cyhal_resource_inst_t ioss_0_port_7_pin_4_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = ioss_0_port_7_pin_4_PORT_NUM,
    .channel_num = ioss_0_port_7_pin_4_PIN,
};
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

const cy_stc_gpio_pin_config_t GPIO_GD_A_ENABLE_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_STRONG,
    .hsiom = GPIO_GD_A_ENABLE_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .intMask = 0UL,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
    .driveSel = CY_GPIO_DRIVE_1_2,
    .vregEn = 0UL,
    .ibufMode = 0UL,
    .vtripSel = 0UL,
    .vrefSel = 0UL,
    .vohSel = 0UL,
    .nonSec = 0,
};

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
const cyhal_resource_inst_t GPIO_GD_A_ENABLE_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = GPIO_GD_A_ENABLE_PORT_NUM,
    .channel_num = GPIO_GD_A_ENABLE_PIN,
};
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

const cy_stc_gpio_pin_config_t GPIO_GD_A_nFAULT_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_HIGHZ,
    .hsiom = GPIO_GD_A_nFAULT_HSIOM,
    .intEdge = CY_GPIO_INTR_FALLING,
    .intMask = 1UL,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
    .driveSel = CY_GPIO_DRIVE_1_2,
    .vregEn = 0UL,
    .ibufMode = 0UL,
    .vtripSel = 0UL,
    .vrefSel = 0UL,
    .vohSel = 0UL,
    .nonSec = 0,
};

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
const cyhal_resource_inst_t GPIO_GD_A_nFAULT_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = GPIO_GD_A_nFAULT_PORT_NUM,
    .channel_num = GPIO_GD_A_nFAULT_PIN,
};
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

const cy_stc_gpio_pin_config_t GPIO_GD_A_PULLUP_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,
    .hsiom = GPIO_GD_A_PULLUP_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .intMask = 0UL,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
    .driveSel = CY_GPIO_DRIVE_1_2,
    .vregEn = 0UL,
    .ibufMode = 0UL,
    .vtripSel = 0UL,
    .vrefSel = 0UL,
    .vohSel = 0UL,
    .nonSec = 0,
};

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
const cyhal_resource_inst_t GPIO_GD_A_PULLUP_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = GPIO_GD_A_PULLUP_PORT_NUM,
    .channel_num = GPIO_GD_A_PULLUP_PIN,
};
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

const cy_stc_gpio_pin_config_t ioss_0_port_8_pin_0_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_HIGHZ,
    .hsiom = ioss_0_port_8_pin_0_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .intMask = 0UL,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
    .driveSel = CY_GPIO_DRIVE_1_2,
    .vregEn = 0UL,
    .ibufMode = 0UL,
    .vtripSel = 0UL,
    .vrefSel = 0UL,
    .vohSel = 0UL,
    .nonSec = 0,
};

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
const cyhal_resource_inst_t ioss_0_port_8_pin_0_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = ioss_0_port_8_pin_0_PORT_NUM,
    .channel_num = ioss_0_port_8_pin_0_PIN,
};
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

const cy_stc_gpio_pin_config_t ioss_0_port_8_pin_1_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_HIGHZ,
    .hsiom = ioss_0_port_8_pin_1_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .intMask = 0UL,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
    .driveSel = CY_GPIO_DRIVE_1_2,
    .vregEn = 0UL,
    .ibufMode = 0UL,
    .vtripSel = 0UL,
    .vrefSel = 0UL,
    .vohSel = 0UL,
    .nonSec = 0,
};

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
const cyhal_resource_inst_t ioss_0_port_8_pin_1_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = ioss_0_port_8_pin_1_PORT_NUM,
    .channel_num = ioss_0_port_8_pin_1_PIN,
};
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

const cy_stc_gpio_pin_config_t ioss_0_port_8_pin_2_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,
    .hsiom = ioss_0_port_8_pin_2_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .intMask = 0UL,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
    .driveSel = CY_GPIO_DRIVE_1_2,
    .vregEn = 0UL,
    .ibufMode = 0UL,
    .vtripSel = 0UL,
    .vrefSel = 0UL,
    .vohSel = 0UL,
    .nonSec = 0,
};

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
const cyhal_resource_inst_t ioss_0_port_8_pin_2_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = ioss_0_port_8_pin_2_PORT_NUM,
    .channel_num = ioss_0_port_8_pin_2_PIN,
};
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

const cy_stc_gpio_pin_config_t ioss_0_port_8_pin_3_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_HIGHZ,
    .hsiom = ioss_0_port_8_pin_3_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .intMask = 0UL,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
    .driveSel = CY_GPIO_DRIVE_1_2,
    .vregEn = 0UL,
    .ibufMode = 0UL,
    .vtripSel = 0UL,
    .vrefSel = 0UL,
    .vohSel = 0UL,
    .nonSec = 0,
};

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
const cyhal_resource_inst_t ioss_0_port_8_pin_3_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = ioss_0_port_8_pin_3_PORT_NUM,
    .channel_num = ioss_0_port_8_pin_3_PIN,
};
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

const cy_stc_gpio_pin_config_t GPIO_CTR_INT1_config =
{
    .outVal = 0,
    .driveMode = CY_GPIO_DM_STRONG,
    .hsiom = GPIO_CTR_INT1_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .intMask = 0UL,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
    .driveSel = CY_GPIO_DRIVE_1_2,
    .vregEn = 0UL,
    .ibufMode = 0UL,
    .vtripSel = 0UL,
    .vrefSel = 0UL,
    .vohSel = 0UL,
    .nonSec = 1,
};

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
const cyhal_resource_inst_t GPIO_CTR_INT1_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = GPIO_CTR_INT1_PORT_NUM,
    .channel_num = GPIO_CTR_INT1_PIN,
};
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

const cy_stc_gpio_pin_config_t GPIO_CTR_INT2_config =
{
    .outVal = 0,
    .driveMode = CY_GPIO_DM_STRONG,
    .hsiom = GPIO_CTR_INT2_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .intMask = 0UL,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
    .driveSel = CY_GPIO_DRIVE_1_2,
    .vregEn = 0UL,
    .ibufMode = 0UL,
    .vtripSel = 0UL,
    .vrefSel = 0UL,
    .vohSel = 0UL,
    .nonSec = 0,
};

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
const cyhal_resource_inst_t GPIO_CTR_INT2_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = GPIO_CTR_INT2_PORT_NUM,
    .channel_num = GPIO_CTR_INT2_PIN,
};
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

const cy_stc_gpio_pin_config_t ioss_0_port_9_pin_0_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,
    .hsiom = ioss_0_port_9_pin_0_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .intMask = 0UL,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
    .driveSel = CY_GPIO_DRIVE_1_2,
    .vregEn = 0UL,
    .ibufMode = 0UL,
    .vtripSel = 0UL,
    .vrefSel = 0UL,
    .vohSel = 0UL,
    .nonSec = 0,
};

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
const cyhal_resource_inst_t ioss_0_port_9_pin_0_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = ioss_0_port_9_pin_0_PORT_NUM,
    .channel_num = ioss_0_port_9_pin_0_PIN,
};
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

const cy_stc_gpio_pin_config_t ioss_0_port_9_pin_1_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,
    .hsiom = ioss_0_port_9_pin_1_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .intMask = 0UL,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
    .driveSel = CY_GPIO_DRIVE_1_2,
    .vregEn = 0UL,
    .ibufMode = 0UL,
    .vtripSel = 0UL,
    .vrefSel = 0UL,
    .vohSel = 0UL,
    .nonSec = 0,
};

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
const cyhal_resource_inst_t ioss_0_port_9_pin_1_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = ioss_0_port_9_pin_1_PORT_NUM,
    .channel_num = ioss_0_port_9_pin_1_PIN,
};
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

const cy_stc_gpio_pin_config_t ioss_0_port_9_pin_2_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,
    .hsiom = ioss_0_port_9_pin_2_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .intMask = 0UL,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
    .driveSel = CY_GPIO_DRIVE_1_2,
    .vregEn = 0UL,
    .ibufMode = 0UL,
    .vtripSel = 0UL,
    .vrefSel = 0UL,
    .vohSel = 0UL,
    .nonSec = 0,
};

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
const cyhal_resource_inst_t ioss_0_port_9_pin_2_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = ioss_0_port_9_pin_2_PORT_NUM,
    .channel_num = ioss_0_port_9_pin_2_PIN,
};
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

const cy_stc_gpio_pin_config_t ioss_0_port_9_pin_3_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_HIGHZ,
    .hsiom = ioss_0_port_9_pin_3_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .intMask = 0UL,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
    .driveSel = CY_GPIO_DRIVE_1_2,
    .vregEn = 0UL,
    .ibufMode = 0UL,
    .vtripSel = 0UL,
    .vrefSel = 0UL,
    .vohSel = 0UL,
    .nonSec = 0,
};

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
const cyhal_resource_inst_t ioss_0_port_9_pin_3_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = ioss_0_port_9_pin_3_PORT_NUM,
    .channel_num = ioss_0_port_9_pin_3_PIN,
};
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

const cy_stc_gpio_pin_config_t ioss_0_port_9_pin_4_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,
    .hsiom = ioss_0_port_9_pin_4_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .intMask = 0UL,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
    .driveSel = CY_GPIO_DRIVE_1_2,
    .vregEn = 0UL,
    .ibufMode = 0UL,
    .vtripSel = 0UL,
    .vrefSel = 0UL,
    .vohSel = 0UL,
    .nonSec = 0,
};

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
const cyhal_resource_inst_t ioss_0_port_9_pin_4_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = ioss_0_port_9_pin_4_PORT_NUM,
    .channel_num = ioss_0_port_9_pin_4_PIN,
};
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

const cy_stc_gpio_pin_config_t ioss_0_port_9_pin_5_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,
    .hsiom = ioss_0_port_9_pin_5_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .intMask = 0UL,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
    .driveSel = CY_GPIO_DRIVE_1_2,
    .vregEn = 0UL,
    .ibufMode = 0UL,
    .vtripSel = 0UL,
    .vrefSel = 0UL,
    .vohSel = 0UL,
    .nonSec = 0,
};

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
const cyhal_resource_inst_t ioss_0_port_9_pin_5_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = ioss_0_port_9_pin_5_PORT_NUM,
    .channel_num = ioss_0_port_9_pin_5_PIN,
};
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

void init_cycfg_pins(void)
{
    Cy_GPIO_Pin_Init(ioss_0_port_0_pin_0_PORT, ioss_0_port_0_pin_0_PIN, &ioss_0_port_0_pin_0_config);
    Cy_GPIO_Pin_Init(ioss_0_port_1_pin_2_PORT, ioss_0_port_1_pin_2_PIN, &ioss_0_port_1_pin_2_config);
    Cy_GPIO_Pin_Init(ioss_0_port_1_pin_3_PORT, ioss_0_port_1_pin_3_PIN, &ioss_0_port_1_pin_3_config);
    Cy_GPIO_Pin_Init(ioss_0_port_2_pin_0_PORT, ioss_0_port_2_pin_0_PIN, &ioss_0_port_2_pin_0_config);
    Cy_GPIO_Pin_Init(ioss_0_port_2_pin_1_PORT, ioss_0_port_2_pin_1_PIN, &ioss_0_port_2_pin_1_config);
    Cy_GPIO_Pin_Init(ioss_0_port_2_pin_2_PORT, ioss_0_port_2_pin_2_PIN, &ioss_0_port_2_pin_2_config);
    Cy_GPIO_Pin_Init(ioss_0_port_2_pin_3_PORT, ioss_0_port_2_pin_3_PIN, &ioss_0_port_2_pin_3_config);
    Cy_GPIO_Pin_Init(ioss_0_port_3_pin_0_PORT, ioss_0_port_3_pin_0_PIN, &ioss_0_port_3_pin_0_config);
    Cy_GPIO_Pin_Init(ioss_0_port_3_pin_1_PORT, ioss_0_port_3_pin_1_PIN, &ioss_0_port_3_pin_1_config);
    Cy_GPIO_Pin_Init(GPIO_GD_C_ENABLE_PORT, GPIO_GD_C_ENABLE_PIN, &GPIO_GD_C_ENABLE_config);
    Cy_GPIO_Pin_Init(GPIO_GD_C_nFAULT_PORT, GPIO_GD_C_nFAULT_PIN, &GPIO_GD_C_nFAULT_config);
    Cy_GPIO_Pin_Init(GPIO_GD_B_nFAULT_PORT, GPIO_GD_B_nFAULT_PIN, &GPIO_GD_B_nFAULT_config);
    Cy_GPIO_Pin_Init(GPIO_GD_B_ENABLE_PORT, GPIO_GD_B_ENABLE_PIN, &GPIO_GD_B_ENABLE_config);
    Cy_GPIO_Pin_Init(ioss_0_port_4_pin_2_PORT, ioss_0_port_4_pin_2_PIN, &ioss_0_port_4_pin_2_config);
    Cy_GPIO_Pin_Init(ioss_0_port_4_pin_3_PORT, ioss_0_port_4_pin_3_PIN, &ioss_0_port_4_pin_3_config);
    Cy_GPIO_Pin_Init(ioss_0_port_4_pin_4_PORT, ioss_0_port_4_pin_4_PIN, &ioss_0_port_4_pin_4_config);
    Cy_GPIO_Pin_Init(ioss_0_port_4_pin_5_PORT, ioss_0_port_4_pin_5_PIN, &ioss_0_port_4_pin_5_config);
    Cy_GPIO_Pin_Init(ioss_0_port_4_pin_6_PORT, ioss_0_port_4_pin_6_PIN, &ioss_0_port_4_pin_6_config);
    Cy_GPIO_Pin_Init(ioss_0_port_4_pin_7_PORT, ioss_0_port_4_pin_7_PIN, &ioss_0_port_4_pin_7_config);
    Cy_GPIO_Pin_Init(ioss_0_port_5_pin_0_PORT, ioss_0_port_5_pin_0_PIN, &ioss_0_port_5_pin_0_config);
    Cy_GPIO_Pin_Init(ioss_0_port_5_pin_1_PORT, ioss_0_port_5_pin_1_PIN, &ioss_0_port_5_pin_1_config);
    Cy_GPIO_Pin_Init(ioss_0_port_5_pin_2_PORT, ioss_0_port_5_pin_2_PIN, &ioss_0_port_5_pin_2_config);
    Cy_GPIO_Pin_Init(ioss_0_port_5_pin_3_PORT, ioss_0_port_5_pin_3_PIN, &ioss_0_port_5_pin_3_config);
    Cy_GPIO_Pin_Init(ioss_0_port_6_pin_0_PORT, ioss_0_port_6_pin_0_PIN, &ioss_0_port_6_pin_0_config);
    Cy_GPIO_Pin_Init(ioss_0_port_6_pin_1_PORT, ioss_0_port_6_pin_1_PIN, &ioss_0_port_6_pin_1_config);
    Cy_GPIO_Pin_Init(ioss_0_port_6_pin_2_PORT, ioss_0_port_6_pin_2_PIN, &ioss_0_port_6_pin_2_config);
    Cy_GPIO_Pin_Init(ioss_0_port_6_pin_3_PORT, ioss_0_port_6_pin_3_PIN, &ioss_0_port_6_pin_3_config);
    Cy_GPIO_Pin_Init(ioss_0_port_7_pin_0_PORT, ioss_0_port_7_pin_0_PIN, &ioss_0_port_7_pin_0_config);
    Cy_GPIO_Pin_Init(ioss_0_port_7_pin_1_PORT, ioss_0_port_7_pin_1_PIN, &ioss_0_port_7_pin_1_config);
    Cy_GPIO_Pin_Init(ioss_0_port_7_pin_2_PORT, ioss_0_port_7_pin_2_PIN, &ioss_0_port_7_pin_2_config);
    Cy_GPIO_Pin_Init(ioss_0_port_7_pin_3_PORT, ioss_0_port_7_pin_3_PIN, &ioss_0_port_7_pin_3_config);
    Cy_GPIO_Pin_Init(ioss_0_port_7_pin_4_PORT, ioss_0_port_7_pin_4_PIN, &ioss_0_port_7_pin_4_config);
    Cy_GPIO_Pin_Init(GPIO_GD_A_ENABLE_PORT, GPIO_GD_A_ENABLE_PIN, &GPIO_GD_A_ENABLE_config);
    Cy_GPIO_Pin_Init(GPIO_GD_A_nFAULT_PORT, GPIO_GD_A_nFAULT_PIN, &GPIO_GD_A_nFAULT_config);
    Cy_GPIO_Pin_Init(GPIO_GD_A_PULLUP_PORT, GPIO_GD_A_PULLUP_PIN, &GPIO_GD_A_PULLUP_config);
    Cy_GPIO_Pin_Init(ioss_0_port_8_pin_0_PORT, ioss_0_port_8_pin_0_PIN, &ioss_0_port_8_pin_0_config);
    Cy_GPIO_Pin_Init(ioss_0_port_8_pin_1_PORT, ioss_0_port_8_pin_1_PIN, &ioss_0_port_8_pin_1_config);
    Cy_GPIO_Pin_Init(ioss_0_port_8_pin_2_PORT, ioss_0_port_8_pin_2_PIN, &ioss_0_port_8_pin_2_config);
    Cy_GPIO_Pin_Init(ioss_0_port_8_pin_3_PORT, ioss_0_port_8_pin_3_PIN, &ioss_0_port_8_pin_3_config);
    Cy_GPIO_Pin_Init(GPIO_CTR_INT1_PORT, GPIO_CTR_INT1_PIN, &GPIO_CTR_INT1_config);
    Cy_GPIO_Pin_Init(GPIO_CTR_INT2_PORT, GPIO_CTR_INT2_PIN, &GPIO_CTR_INT2_config);
    Cy_GPIO_Pin_Init(ioss_0_port_9_pin_0_PORT, ioss_0_port_9_pin_0_PIN, &ioss_0_port_9_pin_0_config);
    Cy_GPIO_Pin_Init(ioss_0_port_9_pin_1_PORT, ioss_0_port_9_pin_1_PIN, &ioss_0_port_9_pin_1_config);
    Cy_GPIO_Pin_Init(ioss_0_port_9_pin_2_PORT, ioss_0_port_9_pin_2_PIN, &ioss_0_port_9_pin_2_config);
    Cy_GPIO_Pin_Init(ioss_0_port_9_pin_3_PORT, ioss_0_port_9_pin_3_PIN, &ioss_0_port_9_pin_3_config);
    Cy_GPIO_Pin_Init(ioss_0_port_9_pin_4_PORT, ioss_0_port_9_pin_4_PIN, &ioss_0_port_9_pin_4_config);
    Cy_GPIO_Pin_Init(ioss_0_port_9_pin_5_PORT, ioss_0_port_9_pin_5_PIN, &ioss_0_port_9_pin_5_config);
}
void reserve_cycfg_pins(void)
{
#if defined (CY_USING_HAL)
    cyhal_hwmgr_reserve(&ioss_0_port_0_pin_0_obj);
    cyhal_hwmgr_reserve(&ioss_0_port_1_pin_0_obj);
    cyhal_hwmgr_reserve(&ioss_0_port_1_pin_1_obj);
    cyhal_hwmgr_reserve(&ioss_0_port_1_pin_2_obj);
    cyhal_hwmgr_reserve(&ioss_0_port_1_pin_3_obj);
    cyhal_hwmgr_reserve(&ioss_0_port_2_pin_0_obj);
    cyhal_hwmgr_reserve(&ioss_0_port_2_pin_1_obj);
    cyhal_hwmgr_reserve(&ioss_0_port_2_pin_2_obj);
    cyhal_hwmgr_reserve(&ioss_0_port_2_pin_3_obj);
    cyhal_hwmgr_reserve(&ioss_0_port_3_pin_0_obj);
    cyhal_hwmgr_reserve(&ioss_0_port_3_pin_1_obj);
    cyhal_hwmgr_reserve(&GPIO_GD_C_ENABLE_obj);
    cyhal_hwmgr_reserve(&GPIO_GD_C_nFAULT_obj);
    cyhal_hwmgr_reserve(&GPIO_GD_B_nFAULT_obj);
    cyhal_hwmgr_reserve(&GPIO_GD_B_ENABLE_obj);
    cyhal_hwmgr_reserve(&ioss_0_port_4_pin_2_obj);
    cyhal_hwmgr_reserve(&ioss_0_port_4_pin_3_obj);
    cyhal_hwmgr_reserve(&ioss_0_port_4_pin_4_obj);
    cyhal_hwmgr_reserve(&ioss_0_port_4_pin_5_obj);
    cyhal_hwmgr_reserve(&ioss_0_port_4_pin_6_obj);
    cyhal_hwmgr_reserve(&ioss_0_port_4_pin_7_obj);
    cyhal_hwmgr_reserve(&ioss_0_port_5_pin_0_obj);
    cyhal_hwmgr_reserve(&ioss_0_port_5_pin_1_obj);
    cyhal_hwmgr_reserve(&ioss_0_port_5_pin_2_obj);
    cyhal_hwmgr_reserve(&ioss_0_port_5_pin_3_obj);
    cyhal_hwmgr_reserve(&ioss_0_port_6_pin_0_obj);
    cyhal_hwmgr_reserve(&ioss_0_port_6_pin_1_obj);
    cyhal_hwmgr_reserve(&ioss_0_port_6_pin_2_obj);
    cyhal_hwmgr_reserve(&ioss_0_port_6_pin_3_obj);
    cyhal_hwmgr_reserve(&ioss_0_port_7_pin_0_obj);
    cyhal_hwmgr_reserve(&ioss_0_port_7_pin_1_obj);
    cyhal_hwmgr_reserve(&ioss_0_port_7_pin_2_obj);
    cyhal_hwmgr_reserve(&ioss_0_port_7_pin_3_obj);
    cyhal_hwmgr_reserve(&ioss_0_port_7_pin_4_obj);
    cyhal_hwmgr_reserve(&GPIO_GD_A_ENABLE_obj);
    cyhal_hwmgr_reserve(&GPIO_GD_A_nFAULT_obj);
    cyhal_hwmgr_reserve(&GPIO_GD_A_PULLUP_obj);
    cyhal_hwmgr_reserve(&ioss_0_port_8_pin_0_obj);
    cyhal_hwmgr_reserve(&ioss_0_port_8_pin_1_obj);
    cyhal_hwmgr_reserve(&ioss_0_port_8_pin_2_obj);
    cyhal_hwmgr_reserve(&ioss_0_port_8_pin_3_obj);
    cyhal_hwmgr_reserve(&GPIO_CTR_INT1_obj);
    cyhal_hwmgr_reserve(&GPIO_CTR_INT2_obj);
    cyhal_hwmgr_reserve(&ioss_0_port_9_pin_0_obj);
    cyhal_hwmgr_reserve(&ioss_0_port_9_pin_1_obj);
    cyhal_hwmgr_reserve(&ioss_0_port_9_pin_2_obj);
    cyhal_hwmgr_reserve(&ioss_0_port_9_pin_3_obj);
    cyhal_hwmgr_reserve(&ioss_0_port_9_pin_4_obj);
    cyhal_hwmgr_reserve(&ioss_0_port_9_pin_5_obj);
#endif /* defined (CY_USING_HAL) */
}
