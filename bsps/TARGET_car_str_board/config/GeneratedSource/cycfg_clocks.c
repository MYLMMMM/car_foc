/*******************************************************************************
 * File Name: cycfg_clocks.c
 *
 * Description:
 * Peripheral clock divider configuration
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

#include "cycfg_clocks.h"

#if defined (CY_USING_HAL)
const cyhal_resource_inst_t CLK_SPI_GD_CFG_obj =
{
    .type = CYHAL_RSC_CLOCK,
    .block_num = CLK_SPI_GD_CFG_HW,
    .channel_num = CLK_SPI_GD_CFG_NUM,
};
const cyhal_resource_inst_t CLK_SPI_LED_obj =
{
    .type = CYHAL_RSC_CLOCK,
    .block_num = CLK_SPI_LED_HW,
    .channel_num = CLK_SPI_LED_NUM,
};
const cyhal_resource_inst_t CLK_SPI_EC_obj =
{
    .type = CYHAL_RSC_CLOCK,
    .block_num = CLK_SPI_EC_HW,
    .channel_num = CLK_SPI_EC_NUM,
};
const cyhal_resource_inst_t peri_0_group_5_div_8_0_obj =
{
    .type = CYHAL_RSC_CLOCK,
    .block_num = peri_0_group_5_div_8_0_HW,
    .channel_num = peri_0_group_5_div_8_0_NUM,
};
const cyhal_resource_inst_t peri_0_group_5_div_8_1_obj =
{
    .type = CYHAL_RSC_CLOCK,
    .block_num = peri_0_group_5_div_8_1_HW,
    .channel_num = peri_0_group_5_div_8_1_NUM,
};
const cyhal_resource_inst_t peri_0_group_6_div_16_5_0_obj =
{
    .type = CYHAL_RSC_CLOCK,
    .block_num = peri_0_group_6_div_16_5_0_HW,
    .channel_num = peri_0_group_6_div_16_5_0_NUM,
};
#endif /* defined (CY_USING_HAL) */

void init_cycfg_clocks(void)
{
    Cy_SysClk_PeriPclkDisableDivider((en_clk_dst_t)CLK_SPI_GD_CFG_GRP_NUM, CY_SYSCLK_DIV_16_5_BIT, 0U);
    Cy_SysClk_PeriPclkSetFracDivider((en_clk_dst_t)CLK_SPI_GD_CFG_GRP_NUM, CY_SYSCLK_DIV_16_5_BIT, 0U, 4U, 0U);
    Cy_SysClk_PeriPclkEnableDivider((en_clk_dst_t)CLK_SPI_GD_CFG_GRP_NUM, CY_SYSCLK_DIV_16_5_BIT, 0U);
    Cy_SysClk_PeriPclkDisableDivider((en_clk_dst_t)CLK_SPI_LED_GRP_NUM, CY_SYSCLK_DIV_16_5_BIT, 1U);
    Cy_SysClk_PeriPclkSetFracDivider((en_clk_dst_t)CLK_SPI_LED_GRP_NUM, CY_SYSCLK_DIV_16_5_BIT, 1U, 4U, 0U);
    Cy_SysClk_PeriPclkEnableDivider((en_clk_dst_t)CLK_SPI_LED_GRP_NUM, CY_SYSCLK_DIV_16_5_BIT, 1U);
    Cy_SysClk_PeriPclkDisableDivider((en_clk_dst_t)CLK_SPI_EC_GRP_NUM, CY_SYSCLK_DIV_16_5_BIT, 2U);
    Cy_SysClk_PeriPclkSetFracDivider((en_clk_dst_t)CLK_SPI_EC_GRP_NUM, CY_SYSCLK_DIV_16_5_BIT, 2U, 0U, 0U);
    Cy_SysClk_PeriPclkEnableDivider((en_clk_dst_t)CLK_SPI_EC_GRP_NUM, CY_SYSCLK_DIV_16_5_BIT, 2U);
    Cy_SysClk_PeriPclkDisableDivider((en_clk_dst_t)PERI_0_GROUP_5_DIV_8_0_GRP_NUM, CY_SYSCLK_DIV_8_BIT, 0U);
    Cy_SysClk_PeriPclkSetDivider((en_clk_dst_t)PERI_0_GROUP_5_DIV_8_0_GRP_NUM, CY_SYSCLK_DIV_8_BIT, 0U, 0U);
    Cy_SysClk_PeriPclkEnableDivider((en_clk_dst_t)PERI_0_GROUP_5_DIV_8_0_GRP_NUM, CY_SYSCLK_DIV_8_BIT, 0U);
    Cy_SysClk_PeriPclkDisableDivider((en_clk_dst_t)PERI_0_GROUP_5_DIV_8_1_GRP_NUM, CY_SYSCLK_DIV_8_BIT, 1U);
    Cy_SysClk_PeriPclkSetDivider((en_clk_dst_t)PERI_0_GROUP_5_DIV_8_1_GRP_NUM, CY_SYSCLK_DIV_8_BIT, 1U, 0U);
    Cy_SysClk_PeriPclkEnableDivider((en_clk_dst_t)PERI_0_GROUP_5_DIV_8_1_GRP_NUM, CY_SYSCLK_DIV_8_BIT, 1U);
    Cy_SysClk_PeriPclkDisableDivider((en_clk_dst_t)PERI_0_GROUP_6_DIV_16_5_0_GRP_NUM, CY_SYSCLK_DIV_16_5_BIT, 0U);
    Cy_SysClk_PeriPclkSetFracDivider((en_clk_dst_t)PERI_0_GROUP_6_DIV_16_5_0_GRP_NUM, CY_SYSCLK_DIV_16_5_BIT, 0U, 0U, 0U);
    Cy_SysClk_PeriPclkEnableDivider((en_clk_dst_t)PERI_0_GROUP_6_DIV_16_5_0_GRP_NUM, CY_SYSCLK_DIV_16_5_BIT, 0U);
}
void reserve_cycfg_clocks(void)
{
#if defined (CY_USING_HAL)
    cyhal_hwmgr_reserve(&CLK_SPI_GD_CFG_obj);
    cyhal_hwmgr_reserve(&CLK_SPI_LED_obj);
    cyhal_hwmgr_reserve(&CLK_SPI_EC_obj);
    cyhal_hwmgr_reserve(&peri_0_group_5_div_8_0_obj);
    cyhal_hwmgr_reserve(&peri_0_group_5_div_8_1_obj);
    cyhal_hwmgr_reserve(&peri_0_group_6_div_16_5_0_obj);
#endif /* defined (CY_USING_HAL) */
}
