/*******************************************************************************
 * File Name: cycfg_peripherals.c
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

#include "cycfg_peripherals.h"

#define CYCFG_TRC_CTI_OUT_CTI_TR_OUT0 DEBUG_TRC_CTI_OUT_CTI_TR_OUT0
#define CYCFG_TRC_CTI_IN_MAIN_CORE_HALT DEBUG_TRC_CTI_IN_CPU0_HALT
#define TIMER_TASK_INPUT_DISABLED 0x7U
#define PWM_C_U_INPUT_DISABLED 0x7U
#define PWM_C_V_INPUT_DISABLED 0x7U
#define PWM_START_C_INPUT_DISABLED 0x7U
#define PWM_A_U_INPUT_DISABLED 0x7U
#define PWM_A_V_INPUT_DISABLED 0x7U
#define PWM_A_W_INPUT_DISABLED 0x7U
#define PWM_B_U_INPUT_DISABLED 0x7U
#define PWM_B_V_INPUT_DISABLED 0x7U
#define PWM_B_W_INPUT_DISABLED 0x7U
#define PWM_START_A_INPUT_DISABLED 0x7U
#define PWM_START_B_INPUT_DISABLED 0x7U

const cy_stc_hppass_cfg_t pass_0_config =
{
    .ac =
    {
        .sttEntriesNum = 1U,
        .stt = pass_0_ac_0_stt_0_config,
        .gpioOutEnMsk = 0U,
        .startupClkDiv = 24U,
        .startup =
        {
            {
                .count = 200U,
                .sar = true,
                .csgChan = true,
                .csgSlice = false,
                .csgReady = false,
            },
            {
                .count = 50U,
                .sar = false,
                .csgChan = false,
                .csgSlice = true,
                .csgReady = false,
            },
            {
                .count = 0U,
                .sar = false,
                .csgChan = false,
                .csgSlice = false,
                .csgReady = true,
            },
            {
                .count = 0U,
                .sar = false,
                .csgChan = false,
                .csgSlice = false,
                .csgReady = false,
            },
        },
    },
    .csg = NULL,
    .sar = &pass_0_sar_0_config,
    .trigIn =
    {
        {
            .type = CY_HPPASS_TR_HW_A,
            .hwMode = CY_HPPASS_PULSE_ON_POS_DOUBLE_SYNC,
        },
        {
            .type = CY_HPPASS_TR_HW_A,
            .hwMode = CY_HPPASS_PULSE_ON_POS_DOUBLE_SYNC,
        },
        {
            .type = CY_HPPASS_TR_HW_A,
            .hwMode = CY_HPPASS_PULSE_ON_POS_DOUBLE_SYNC,
        },
        {
            .type = CY_HPPASS_TR_DISABLED,
            .hwMode = CY_HPPASS_PULSE_ON_POS_DOUBLE_SYNC,
        },
        {
            .type = CY_HPPASS_TR_DISABLED,
            .hwMode = CY_HPPASS_PULSE_ON_POS_DOUBLE_SYNC,
        },
        {
            .type = CY_HPPASS_TR_DISABLED,
            .hwMode = CY_HPPASS_PULSE_ON_POS_DOUBLE_SYNC,
        },
        {
            .type = CY_HPPASS_TR_DISABLED,
            .hwMode = CY_HPPASS_PULSE_ON_POS_DOUBLE_SYNC,
        },
        {
            .type = CY_HPPASS_TR_DISABLED,
            .hwMode = CY_HPPASS_PULSE_ON_POS_DOUBLE_SYNC,
        },
    },
    .trigPulse =
    {
        CY_HPPASS_DISABLED, 
        CY_HPPASS_DISABLED, 
        CY_HPPASS_DISABLED, 
        CY_HPPASS_DISABLED, 
        CY_HPPASS_DISABLED, 
        CY_HPPASS_DISABLED, 
        CY_HPPASS_DISABLED, 
        CY_HPPASS_DISABLED, 
    },
    .trigLevel =
    {
        {
            .syncBypass = true,
            .compMsk = 0U,
            .limitMsk = 0U,
        },
        {
            .syncBypass = true,
            .compMsk = 0U,
            .limitMsk = 0U,
        },
        {
            .syncBypass = true,
            .compMsk = 0U,
            .limitMsk = 0U,
        },
        {
            .syncBypass = true,
            .compMsk = 0U,
            .limitMsk = 0U,
        },
        {
            .syncBypass = true,
            .compMsk = 0U,
            .limitMsk = 0U,
        },
        {
            .syncBypass = true,
            .compMsk = 0U,
            .limitMsk = 0U,
        },
        {
            .syncBypass = true,
            .compMsk = 0U,
            .limitMsk = 0U,
        },
        {
            .syncBypass = true,
            .compMsk = 0U,
            .limitMsk = 0U,
        },
    },
};

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
const cyhal_resource_inst_t pass_0_adc_hal_obj =
{
    .type = CYHAL_RSC_ADC,
    .block_num = 0U,
    .channel_num = 0U,
};
const cyhal_adc_configurator_t pass_0_adc_hal_config =
{
    .resource = &pass_0_adc_hal_obj,
    .hppass_config = &pass_0_config,
    .clock = NULL,
    .num_channels = 8U,
    .achieved_acquisition_time = NULL,
};
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_ADC)
const mtb_hal_adc_configurator_t pass_0_adc_hal_config =
{
    .base = HPPASS,
    .hppass_config = &pass_0_config,
    .num_channels = 8U,
};
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_ADC) */

const cy_stc_hppass_sar_t pass_0_sar_0_config =
{
    .vref = CY_HPPASS_SAR_VREF_EXT,
    .lowSupply = false,
    .offsetCal = false,
    .linearCal = false,
    .gainCal = false,
    .chanId = false,
    .aroute = true,
    .dirSampEnMsk = 0xFFU,
    .muxSampEnMsk = 0x0U,
    .holdCount = 29U,
    .dirSampGain =
    {
        CY_HPPASS_SAR_SAMP_GAIN_1, 
        CY_HPPASS_SAR_SAMP_GAIN_1, 
        CY_HPPASS_SAR_SAMP_GAIN_1, 
        CY_HPPASS_SAR_SAMP_GAIN_1, 
        CY_HPPASS_SAR_SAMP_GAIN_1, 
        CY_HPPASS_SAR_SAMP_GAIN_1, 
        CY_HPPASS_SAR_SAMP_GAIN_1, 
        CY_HPPASS_SAR_SAMP_GAIN_1, 
        CY_HPPASS_SAR_SAMP_GAIN_1, 
        CY_HPPASS_SAR_SAMP_GAIN_1, 
        CY_HPPASS_SAR_SAMP_GAIN_1, 
        CY_HPPASS_SAR_SAMP_GAIN_1, 
    },
    .muxSampGain =
    {
        CY_HPPASS_SAR_SAMP_GAIN_1, 
        CY_HPPASS_SAR_SAMP_GAIN_1, 
        CY_HPPASS_SAR_SAMP_GAIN_1, 
        CY_HPPASS_SAR_SAMP_GAIN_1, 
    },
    .sampTime =
    {
        1U, 
        1U, 
        1U, 
    },
    .chan =
    {
        &ADC_VBUS_CH_config, 
        &ADC_A_IW_CH_config, 
        &ADC_A_IV_CH_config, 
        &ADC_A_IU_CH_config, 
        &ADC_B_IU_CH_config, 
        &ADC_B_IV_CH_config, 
        &ADC_B_IW_CH_config, 
        &ADC_C_I_CH_config, 
        NULL, 
        NULL, 
        NULL, 
        NULL, 
        NULL, 
        NULL, 
        NULL, 
        NULL, 
        NULL, 
        NULL, 
        NULL, 
        NULL, 
        NULL, 
        NULL, 
        NULL, 
        NULL, 
        NULL, 
        NULL, 
        NULL, 
        NULL, 
    },
    .grp =
    {
        &motor_a_group_config, 
        &motor_b_group_config, 
        &motor_c_group_config, 
        NULL, 
        NULL, 
        NULL, 
        NULL, 
        NULL, 
    },
    .limit =
    {
        NULL, 
        NULL, 
        NULL, 
        NULL, 
        NULL, 
        NULL, 
        NULL, 
        NULL, 
    },
    .muxMode =
    {
        CY_HPPASS_SAR_MUX_SEQ, 
        CY_HPPASS_SAR_MUX_SEQ, 
        CY_HPPASS_SAR_MUX_SEQ, 
        CY_HPPASS_SAR_MUX_SEQ, 
    },
    .fir =
    {
        NULL, 
        NULL, 
    },
    .fifo = NULL,
};
const cy_stc_hppass_ac_stt_t pass_0_ac_0_stt_0_config[] =
{
    {
        .condition = CY_HPPASS_CONDITION_FALSE,
        .action = CY_HPPASS_ACTION_STOP,
        .branchStateIdx = 0U,
        .interrupt = false,
        .count = 1U,
        .gpioOutUnlock = false,
        .gpioOutMsk = 0U,
        .csgUnlock = {false, false, false, false, false},
        .csgEnable = {false, false, false, false, false},
        .csgDacTrig = {false, false, false, false, false},
        .sarUnlock = true,
        .sarEnable = true,
        .sarGrpMsk = 0U,
        .sarMux = {{false, 0U}, {false, 0U}, {false, 0U}, {false, 0U}},
    },
};
const cy_stc_hppass_sar_chan_t ADC_VBUS_CH_config =
{
    .diff = false,
    .sign = false,
    .avg = CY_HPPASS_SAR_AVG_DISABLED,
    .limit = CY_HPPASS_SAR_LIMIT_DISABLED,
    .result = true,
    .fifo = CY_HPPASS_FIFO_DISABLED,
};
const cy_stc_hppass_sar_chan_t ADC_A_IW_CH_config =
{
    .diff = false,
    .sign = false,
    .avg = CY_HPPASS_SAR_AVG_DISABLED,
    .limit = CY_HPPASS_SAR_LIMIT_DISABLED,
    .result = true,
    .fifo = CY_HPPASS_FIFO_DISABLED,
};
const cy_stc_hppass_sar_chan_t ADC_A_IV_CH_config =
{
    .diff = false,
    .sign = false,
    .avg = CY_HPPASS_SAR_AVG_DISABLED,
    .limit = CY_HPPASS_SAR_LIMIT_DISABLED,
    .result = true,
    .fifo = CY_HPPASS_FIFO_DISABLED,
};
const cy_stc_hppass_sar_chan_t ADC_A_IU_CH_config =
{
    .diff = false,
    .sign = false,
    .avg = CY_HPPASS_SAR_AVG_DISABLED,
    .limit = CY_HPPASS_SAR_LIMIT_DISABLED,
    .result = true,
    .fifo = CY_HPPASS_FIFO_DISABLED,
};
const cy_stc_hppass_sar_chan_t ADC_B_IU_CH_config =
{
    .diff = false,
    .sign = false,
    .avg = CY_HPPASS_SAR_AVG_DISABLED,
    .limit = CY_HPPASS_SAR_LIMIT_DISABLED,
    .result = true,
    .fifo = CY_HPPASS_FIFO_DISABLED,
};
const cy_stc_hppass_sar_chan_t ADC_B_IV_CH_config =
{
    .diff = false,
    .sign = false,
    .avg = CY_HPPASS_SAR_AVG_DISABLED,
    .limit = CY_HPPASS_SAR_LIMIT_DISABLED,
    .result = true,
    .fifo = CY_HPPASS_FIFO_DISABLED,
};
const cy_stc_hppass_sar_chan_t ADC_B_IW_CH_config =
{
    .diff = false,
    .sign = false,
    .avg = CY_HPPASS_SAR_AVG_DISABLED,
    .limit = CY_HPPASS_SAR_LIMIT_DISABLED,
    .result = true,
    .fifo = CY_HPPASS_FIFO_DISABLED,
};
const cy_stc_hppass_sar_chan_t ADC_C_I_CH_config =
{
    .diff = false,
    .sign = false,
    .avg = CY_HPPASS_SAR_AVG_DISABLED,
    .limit = CY_HPPASS_SAR_LIMIT_DISABLED,
    .result = true,
    .fifo = CY_HPPASS_FIFO_DISABLED,
};
const cy_stc_hppass_sar_grp_t motor_a_group_config =
{
    .dirSampMsk = 0xFU,
    .muxSampMsk = 0x0U,
    .muxChanIdx =
    {
        0U, 
        0U, 
        0U, 
        0U, 
    },
    .trig = CY_HPPASS_SAR_TRIG_0,
    .sampTime = CY_HPPASS_SAR_SAMP_TIME_DISABLED,
    .priority = true,
    .continuous = false,
};
const cy_stc_hppass_sar_grp_t motor_b_group_config =
{
    .dirSampMsk = 0x71U,
    .muxSampMsk = 0x0U,
    .muxChanIdx =
    {
        0U, 
        0U, 
        0U, 
        0U, 
    },
    .trig = CY_HPPASS_SAR_TRIG_1,
    .sampTime = CY_HPPASS_SAR_SAMP_TIME_DISABLED,
    .priority = false,
    .continuous = false,
};
const cy_stc_hppass_sar_grp_t motor_c_group_config =
{
    .dirSampMsk = 0x81U,
    .muxSampMsk = 0x0U,
    .muxChanIdx =
    {
        0U, 
        0U, 
        0U, 
        0U, 
    },
    .trig = CY_HPPASS_SAR_TRIG_DISABLED,
    .sampTime = CY_HPPASS_SAR_SAMP_TIME_DISABLED,
    .priority = false,
    .continuous = false,
};
const cy_stc_scb_spi_config_t SPI_GD_CFG_config =
{
    .spiMode = CY_SCB_SPI_MASTER,
    .subMode = CY_SCB_SPI_MOTOROLA,
    .sclkMode = CY_SCB_SPI_CPHA0_CPOL1,
    .parity = CY_SCB_SPI_PARITY_NONE,
    .dropOnParityError = false,
    .oversample = 10,
    .rxDataWidth = 16UL,
    .txDataWidth = 16UL,
    .enableMsbFirst = true,
    .enableInputFilter = false,
    .enableFreeRunSclk = false,
    .enableMisoLateSample = true,
    .enableTransferSeperation = false,
    .ssPolarity = ((CY_SCB_SPI_ACTIVE_LOW << CY_SCB_SPI_SLAVE_SELECT0) | \
                                         (CY_SCB_SPI_ACTIVE_LOW << CY_SCB_SPI_SLAVE_SELECT1) | \
                                         (CY_SCB_SPI_ACTIVE_LOW << CY_SCB_SPI_SLAVE_SELECT2) | \
                                         (CY_SCB_SPI_ACTIVE_LOW << CY_SCB_SPI_SLAVE_SELECT3)),
    .ssSetupDelay = false,
    .ssHoldDelay = false,
    .ssInterFrameDelay = false,
    .enableWakeFromSleep = false,
    .rxFifoTriggerLevel = 31UL,
    .rxFifoIntEnableMask = 0UL,
    .txFifoTriggerLevel = 31UL,
    .txFifoIntEnableMask = 0UL,
    .masterSlaveIntEnableMask = 0UL,
};

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
const cyhal_resource_inst_t SPI_GD_CFG_obj =
{
    .type = CYHAL_RSC_SCB,
    .block_num = 0U,
    .channel_num = 0U,
};
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

#if defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL)
const cyhal_clock_t SPI_GD_CFG_clock =
{
    .block = CYHAL_CLOCK_BLOCK_PERIPHERAL4_16_5BIT,
    .channel = 0,
#if defined (CY_USING_HAL)
    .reserved = false,
    .funcs = NULL,
#endif /* defined (CY_USING_HAL) */
};
#endif /* defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL) */

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
const cyhal_spi_configurator_t SPI_GD_CFG_hal_config =
{
    .resource = &SPI_GD_CFG_obj,
    .config = &SPI_GD_CFG_config,
    .clock = &SPI_GD_CFG_clock,
    .gpios = {.sclk = P9_0, .ssel = {P9_1, P9_4, P9_5, NC}, .mosi = P9_2, .miso = P9_3},
};
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

#if defined (COMPONENT_MTB_HAL)
const mtb_hal_peri_div_t SPI_GD_CFG_clock_ref =
{
    .clk_dst = (en_clk_dst_t)PCLK_SCB0_CLOCK_SCB_EN,
    .div_type = CY_SYSCLK_DIV_16_5_BIT,
    .div_num = 0,
};
const mtb_hal_clock_t SPI_GD_CFG_hal_clock =
{
    .clock_ref = &SPI_GD_CFG_clock_ref,
    .interface = &mtb_hal_clock_peri_interface,
};
#endif /* defined (COMPONENT_MTB_HAL) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_SPI)
const mtb_hal_spi_configurator_t SPI_GD_CFG_hal_config =
{
    .base = SPI_GD_CFG_HW,
    .clock = &SPI_GD_CFG_hal_clock,
    .config = &SPI_GD_CFG_config,
};
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_SPI) */

const cy_stc_scb_spi_config_t SPI_EC_B_config =
{
    .spiMode = CY_SCB_SPI_MASTER,
    .subMode = CY_SCB_SPI_MOTOROLA,
    .sclkMode = CY_SCB_SPI_CPHA1_CPOL1,
    .parity = CY_SCB_SPI_PARITY_NONE,
    .dropOnParityError = false,
    .oversample = 10,
    .rxDataWidth = 16UL,
    .txDataWidth = 16UL,
    .enableMsbFirst = true,
    .enableInputFilter = false,
    .enableFreeRunSclk = false,
    .enableMisoLateSample = true,
    .enableTransferSeperation = true,
    .ssPolarity = ((CY_SCB_SPI_ACTIVE_LOW << CY_SCB_SPI_SLAVE_SELECT0) | \
                                         (CY_SCB_SPI_ACTIVE_LOW << CY_SCB_SPI_SLAVE_SELECT1) | \
                                         (CY_SCB_SPI_ACTIVE_LOW << CY_SCB_SPI_SLAVE_SELECT2) | \
                                         (CY_SCB_SPI_ACTIVE_LOW << CY_SCB_SPI_SLAVE_SELECT3)),
    .ssSetupDelay = false,
    .ssHoldDelay = false,
    .ssInterFrameDelay = true,
    .enableWakeFromSleep = false,
    .rxFifoTriggerLevel = 1UL,
    .rxFifoIntEnableMask = 0UL,
    .txFifoTriggerLevel = 63UL,
    .txFifoIntEnableMask = 0UL,
    .masterSlaveIntEnableMask = 0UL,
};

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
const cyhal_resource_inst_t SPI_EC_B_obj =
{
    .type = CYHAL_RSC_SCB,
    .block_num = 1U,
    .channel_num = 0U,
};
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

#if defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL)
const cyhal_clock_t SPI_EC_B_clock =
{
    .block = CYHAL_CLOCK_BLOCK_PERIPHERAL4_16_5BIT,
    .channel = 2,
#if defined (CY_USING_HAL)
    .reserved = false,
    .funcs = NULL,
#endif /* defined (CY_USING_HAL) */
};
#endif /* defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL) */

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
const cyhal_spi_configurator_t SPI_EC_B_hal_config =
{
    .resource = &SPI_EC_B_obj,
    .config = &SPI_EC_B_config,
    .clock = &SPI_EC_B_clock,
    .gpios = {.sclk = P2_1, .ssel = {P2_0, NC, NC, NC}, .mosi = P2_2, .miso = P2_3},
};
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

#if defined (COMPONENT_MTB_HAL)
const mtb_hal_peri_div_t SPI_EC_B_clock_ref =
{
    .clk_dst = (en_clk_dst_t)PCLK_SCB1_CLOCK_SCB_EN,
    .div_type = CY_SYSCLK_DIV_16_5_BIT,
    .div_num = 2,
};
const mtb_hal_clock_t SPI_EC_B_hal_clock =
{
    .clock_ref = &SPI_EC_B_clock_ref,
    .interface = &mtb_hal_clock_peri_interface,
};
#endif /* defined (COMPONENT_MTB_HAL) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_SPI)
const mtb_hal_spi_configurator_t SPI_EC_B_hal_config =
{
    .base = SPI_EC_B_HW,
    .clock = &SPI_EC_B_hal_clock,
    .config = &SPI_EC_B_config,
};
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_SPI) */

const cy_stc_scb_spi_config_t SPI_LED_config =
{
    .spiMode = CY_SCB_SPI_MASTER,
    .subMode = CY_SCB_SPI_MOTOROLA,
    .sclkMode = CY_SCB_SPI_CPHA0_CPOL0,
    .parity = CY_SCB_SPI_PARITY_NONE,
    .dropOnParityError = false,
    .oversample = 5,
    .rxDataWidth = 24UL,
    .txDataWidth = 24UL,
    .enableMsbFirst = true,
    .enableInputFilter = false,
    .enableFreeRunSclk = false,
    .enableMisoLateSample = true,
    .enableTransferSeperation = false,
    .ssPolarity = ((CY_SCB_SPI_ACTIVE_LOW << CY_SCB_SPI_SLAVE_SELECT0) | \
                                         (CY_SCB_SPI_ACTIVE_LOW << CY_SCB_SPI_SLAVE_SELECT1) | \
                                         (CY_SCB_SPI_ACTIVE_LOW << CY_SCB_SPI_SLAVE_SELECT2) | \
                                         (CY_SCB_SPI_ACTIVE_LOW << CY_SCB_SPI_SLAVE_SELECT3)),
    .ssSetupDelay = false,
    .ssHoldDelay = false,
    .ssInterFrameDelay = false,
    .enableWakeFromSleep = false,
    .rxFifoTriggerLevel = 31UL,
    .rxFifoIntEnableMask = 0UL,
    .txFifoTriggerLevel = 31UL,
    .txFifoIntEnableMask = 0UL,
    .masterSlaveIntEnableMask = 0UL,
};

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
const cyhal_resource_inst_t SPI_LED_obj =
{
    .type = CYHAL_RSC_SCB,
    .block_num = 2U,
    .channel_num = 0U,
};
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

#if defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL)
const cyhal_clock_t SPI_LED_clock =
{
    .block = CYHAL_CLOCK_BLOCK_PERIPHERAL4_16_5BIT,
    .channel = 1,
#if defined (CY_USING_HAL)
    .reserved = false,
    .funcs = NULL,
#endif /* defined (CY_USING_HAL) */
};
#endif /* defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL) */

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
const cyhal_spi_configurator_t SPI_LED_hal_config =
{
    .resource = &SPI_LED_obj,
    .config = &SPI_LED_config,
    .clock = &SPI_LED_clock,
    .gpios = {.sclk = NC, .ssel = {NC, NC, NC, NC}, .mosi = P7_1, .miso = NC},
};
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

#if defined (COMPONENT_MTB_HAL)
const mtb_hal_peri_div_t SPI_LED_clock_ref =
{
    .clk_dst = (en_clk_dst_t)PCLK_SCB2_CLOCK_SCB_EN,
    .div_type = CY_SYSCLK_DIV_16_5_BIT,
    .div_num = 1,
};
const mtb_hal_clock_t SPI_LED_hal_clock =
{
    .clock_ref = &SPI_LED_clock_ref,
    .interface = &mtb_hal_clock_peri_interface,
};
#endif /* defined (COMPONENT_MTB_HAL) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_SPI)
const mtb_hal_spi_configurator_t SPI_LED_hal_config =
{
    .base = SPI_LED_HW,
    .clock = &SPI_LED_hal_clock,
    .config = &SPI_LED_config,
};
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_SPI) */

const cy_stc_scb_spi_config_t SPI_EC_A_config =
{
    .spiMode = CY_SCB_SPI_MASTER,
    .subMode = CY_SCB_SPI_MOTOROLA,
    .sclkMode = CY_SCB_SPI_CPHA1_CPOL1,
    .parity = CY_SCB_SPI_PARITY_NONE,
    .dropOnParityError = false,
    .oversample = 10,
    .rxDataWidth = 16UL,
    .txDataWidth = 16UL,
    .enableMsbFirst = true,
    .enableInputFilter = false,
    .enableFreeRunSclk = false,
    .enableMisoLateSample = true,
    .enableTransferSeperation = true,
    .ssPolarity = ((CY_SCB_SPI_ACTIVE_LOW << CY_SCB_SPI_SLAVE_SELECT0) | \
                                         (CY_SCB_SPI_ACTIVE_LOW << CY_SCB_SPI_SLAVE_SELECT1) | \
                                         (CY_SCB_SPI_ACTIVE_LOW << CY_SCB_SPI_SLAVE_SELECT2) | \
                                         (CY_SCB_SPI_ACTIVE_LOW << CY_SCB_SPI_SLAVE_SELECT3)),
    .ssSetupDelay = false,
    .ssHoldDelay = false,
    .ssInterFrameDelay = true,
    .enableWakeFromSleep = false,
    .rxFifoTriggerLevel = 0UL,
    .rxFifoIntEnableMask = 0UL,
    .txFifoTriggerLevel = 63UL,
    .txFifoIntEnableMask = 0UL,
    .masterSlaveIntEnableMask = 0UL,
};

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
const cyhal_resource_inst_t SPI_EC_A_obj =
{
    .type = CYHAL_RSC_SCB,
    .block_num = 3U,
    .channel_num = 0U,
};
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

#if defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL)
const cyhal_clock_t SPI_EC_A_clock =
{
    .block = CYHAL_CLOCK_BLOCK_PERIPHERAL4_16_5BIT,
    .channel = 2,
#if defined (CY_USING_HAL)
    .reserved = false,
    .funcs = NULL,
#endif /* defined (CY_USING_HAL) */
};
#endif /* defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL) */

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
const cyhal_spi_configurator_t SPI_EC_A_hal_config =
{
    .resource = &SPI_EC_A_obj,
    .config = &SPI_EC_A_config,
    .clock = &SPI_EC_A_clock,
    .gpios = {.sclk = P5_2, .ssel = {P5_3, NC, NC, NC}, .mosi = P5_0, .miso = P5_1},
};
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

#if defined (COMPONENT_MTB_HAL)
const mtb_hal_peri_div_t SPI_EC_A_clock_ref =
{
    .clk_dst = (en_clk_dst_t)PCLK_SCB3_CLOCK_SCB_EN,
    .div_type = CY_SYSCLK_DIV_16_5_BIT,
    .div_num = 2,
};
const mtb_hal_clock_t SPI_EC_A_hal_clock =
{
    .clock_ref = &SPI_EC_A_clock_ref,
    .interface = &mtb_hal_clock_peri_interface,
};
#endif /* defined (COMPONENT_MTB_HAL) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_SPI)
const mtb_hal_spi_configurator_t SPI_EC_A_hal_config =
{
    .base = SPI_EC_A_HW,
    .clock = &SPI_EC_A_hal_clock,
    .config = &SPI_EC_A_config,
};
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_SPI) */

const cy_stc_scb_spi_config_t SPI_CTR_config =
{
    .spiMode = CY_SCB_SPI_SLAVE,
    .subMode = CY_SCB_SPI_MOTOROLA,
    .sclkMode = CY_SCB_SPI_CPHA0_CPOL0,
    .parity = CY_SCB_SPI_PARITY_NONE,
    .dropOnParityError = false,
    .oversample = 0UL,
    .rxDataWidth = 32UL,
    .txDataWidth = 32UL,
    .enableMsbFirst = true,
    .enableInputFilter = false,
    .enableFreeRunSclk = false,
    .enableMisoLateSample = false,
    .enableTransferSeperation = false,
    .ssPolarity = ((CY_SCB_SPI_ACTIVE_LOW << CY_SCB_SPI_SLAVE_SELECT0) | \
                                         (CY_SCB_SPI_ACTIVE_LOW << CY_SCB_SPI_SLAVE_SELECT1) | \
                                         (CY_SCB_SPI_ACTIVE_LOW << CY_SCB_SPI_SLAVE_SELECT2) | \
                                         (CY_SCB_SPI_ACTIVE_LOW << CY_SCB_SPI_SLAVE_SELECT3)),
    .ssSetupDelay = false,
    .ssHoldDelay = false,
    .ssInterFrameDelay = false,
    .enableWakeFromSleep = false,
    .rxFifoTriggerLevel = 31UL,
    .rxFifoIntEnableMask = 0UL,
    .txFifoTriggerLevel = 31UL,
    .txFifoIntEnableMask = 0UL,
    .masterSlaveIntEnableMask = 0UL,
};

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
const cyhal_resource_inst_t SPI_CTR_obj =
{
    .type = CYHAL_RSC_SCB,
    .block_num = 5U,
    .channel_num = 0U,
};
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

#if defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL)
const cyhal_clock_t SPI_CTR_clock =
{
    .block = CYHAL_CLOCK_BLOCK_PERIPHERAL6_16_5BIT,
    .channel = 0,
#if defined (CY_USING_HAL)
    .reserved = false,
    .funcs = NULL,
#endif /* defined (CY_USING_HAL) */
};
#endif /* defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL) */

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
const cyhal_spi_configurator_t SPI_CTR_hal_config =
{
    .resource = &SPI_CTR_obj,
    .config = &SPI_CTR_config,
    .clock = &SPI_CTR_clock,
    .gpios = {.sclk = P8_3, .ssel = {P8_0, NC, NC, NC}, .mosi = P8_1, .miso = P8_2},
};
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

#if defined (COMPONENT_MTB_HAL)
const mtb_hal_peri_div_t SPI_CTR_clock_ref =
{
    .clk_dst = (en_clk_dst_t)PCLK_SCB5_CLOCK_SCB_EN,
    .div_type = CY_SYSCLK_DIV_16_5_BIT,
    .div_num = 0,
};
const mtb_hal_clock_t SPI_CTR_hal_clock =
{
    .clock_ref = &SPI_CTR_clock_ref,
    .interface = &mtb_hal_clock_peri_interface,
};
#endif /* defined (COMPONENT_MTB_HAL) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_SPI)
const mtb_hal_spi_configurator_t SPI_CTR_hal_config =
{
    .base = SPI_CTR_HW,
    .clock = &SPI_CTR_hal_clock,
    .config = &SPI_CTR_config,
};
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_SPI) */

const cy_stc_tcpwm_counter_config_t TIMER_TASK_config =
{
    .period = 480000,
    .clockPrescaler = CY_TCPWM_COUNTER_PRESCALER_DIVBY_1,
    .runMode = CY_TCPWM_COUNTER_CONTINUOUS,
    .countDirection = CY_TCPWM_COUNTER_COUNT_UP,
    .compareOrCapture = CY_TCPWM_COUNTER_MODE_COMPARE,
    .compare0 = 16384,
    .compare1 = 16384,
    .enableCompareSwap = false,
    .interruptSources = (CY_TCPWM_INT_ON_TC ) | (CY_TCPWM_INT_ON_CC0 & 0U) | (CY_TCPWM_INT_ON_CC1 & 0U),
    .captureInputMode = TIMER_TASK_INPUT_DISABLED & 0x3U,
    .captureInput = CY_TCPWM_INPUT_0,
    .reloadInputMode = TIMER_TASK_INPUT_DISABLED & 0x3U,
    .reloadInput = CY_TCPWM_INPUT_0,
    .startInputMode = TIMER_TASK_INPUT_DISABLED & 0x3U,
    .startInput = CY_TCPWM_INPUT_0,
    .stopInputMode = TIMER_TASK_INPUT_DISABLED & 0x3U,
    .stopInput = CY_TCPWM_INPUT_0,
    .countInputMode = TIMER_TASK_INPUT_DISABLED & 0x3U,
    .countInput = CY_TCPWM_INPUT_1,
    .capture1InputMode = TIMER_TASK_INPUT_DISABLED & 0x3U,
    .capture1Input = CY_TCPWM_INPUT_0,
    .compare2 = 16384,
    .compare3 = 16384,
    .enableCompare1Swap = false,
    .trigger0Event = CY_TCPWM_CNT_TRIGGER_ON_DISABLED,
    .trigger1Event = CY_TCPWM_CNT_TRIGGER_ON_DISABLED,
#if defined (CY_IP_MXS40TCPWM)
    .buffer_swap_enable = false,
    .direction_mode = CY_TCPWM_COUNTER_DIRECTION_DISABLE,
    .glitch_filter_enable = false,
    .gf_depth = CY_GLITCH_FILTER_DEPTH_SUPPORT_VALUE_0,
#endif /* defined (CY_IP_MXS40TCPWM) */
};

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
const cyhal_resource_inst_t TIMER_TASK_obj =
{
    .type = CYHAL_RSC_TCPWM,
    .block_num = 0U,
    .channel_num = 0U,
};
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

#if defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL)
const cyhal_clock_t TIMER_TASK_clock =
{
    .block = CYHAL_CLOCK_BLOCK_PERIPHERAL5_8BIT,
    .channel = 0,
#if defined (CY_USING_HAL)
    .reserved = false,
    .funcs = NULL,
#endif /* defined (CY_USING_HAL) */
};
#endif /* defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL) */

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
const cyhal_timer_configurator_t TIMER_TASK_hal_config =
{
    .resource = &TIMER_TASK_obj,
    .config = &TIMER_TASK_config,
    .clock = &TIMER_TASK_clock,
};
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

#if defined (COMPONENT_MTB_HAL)
const mtb_hal_peri_div_t TIMER_TASK_clock_ref =
{
    .clk_dst = (en_clk_dst_t)PCLK_TCPWM0_CLOCK_COUNTER_EN0,
    .div_type = CY_SYSCLK_DIV_8_BIT,
    .div_num = 0,
};
const mtb_hal_clock_t TIMER_TASK_hal_clock =
{
    .clock_ref = &TIMER_TASK_clock_ref,
    .interface = &mtb_hal_clock_peri_interface,
};
#endif /* defined (COMPONENT_MTB_HAL) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_TIMER)
const mtb_hal_timer_configurator_t TIMER_TASK_hal_config =
{
    .tcpwm_base = TIMER_TASK_HW,
    .clock = &TIMER_TASK_hal_clock,
    .tcpwm_cntnum = 0U,
};
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_TIMER) */

const cy_stc_tcpwm_pwm_config_t PWM_C_U_config =
{
    .pwmMode = CY_TCPWM_PWM_MODE_PWM,
    .clockPrescaler = CY_TCPWM_PWM_PRESCALER_DIVBY_1,
    .pwmAlignment = CY_TCPWM_PWM_LEFT_ALIGN,
    .deadTimeClocks = 0,
    .runMode = CY_TCPWM_PWM_CONTINUOUS,
    .period0 = 239999,
    .period1 = 32768,
    .enablePeriodSwap = false,
    .compare0 = 0,
    .compare1 = 16384,
    .enableCompareSwap = false,
    .interruptSources = (CY_TCPWM_INT_ON_TC & 0U) | (CY_TCPWM_INT_ON_CC0 & 0U) | (CY_TCPWM_INT_ON_CC1 & 0U),
    .invertPWMOut = CY_TCPWM_PWM_INVERT_DISABLE,
    .invertPWMOutN = CY_TCPWM_PWM_INVERT_DISABLE,
    .killMode = CY_TCPWM_PWM_STOP_ON_KILL,
    .swapInputMode = PWM_C_U_INPUT_DISABLED & 0x3U,
    .swapInput = CY_TCPWM_INPUT_0,
    .reloadInputMode = PWM_C_U_INPUT_DISABLED & 0x3U,
    .reloadInput = CY_TCPWM_INPUT_0,
    .startInputMode = CY_TCPWM_INPUT_RISINGEDGE,
    .startInput = TCPWM0_GRP0_CNT1_START_VALUE,
    .killInputMode = CY_TCPWM_INPUT_FALLINGEDGE,
    .killInput = TCPWM0_GRP0_CNT1_STOP_VALUE,
    .countInputMode = PWM_C_U_INPUT_DISABLED & 0x3U,
    .countInput = CY_TCPWM_INPUT_1,
    .swapOverflowUnderflow = false,
    .immediateKill = false,
    .tapsEnabled = 45,
    .compare2 = 0,
    .compare3 = 16384,
    .enableCompare1Swap = false,
    .compare0MatchUp = true,
    .compare0MatchDown = false,
    .compare1MatchUp = true,
    .compare1MatchDown = false,
    .kill1InputMode = PWM_C_U_INPUT_DISABLED & 0x3U,
    .kill1Input = CY_TCPWM_INPUT_0,
    .pwmOnDisable = CY_TCPWM_PWM_OUTPUT_HIGHZ,
    .trigger0Event = CY_TCPWM_CNT_TRIGGER_ON_DISABLED,
    .trigger1Event = CY_TCPWM_CNT_TRIGGER_ON_OVERFLOW,
    .reloadLineSelect = false,
    .line_out_sel = CY_TCPWM_OUTPUT_PWM_SIGNAL,
    .linecompl_out_sel = CY_TCPWM_OUTPUT_INVERTED_PWM_SIGNAL,
    .line_out_sel_buff = CY_TCPWM_OUTPUT_PWM_SIGNAL,
    .linecompl_out_sel_buff = CY_TCPWM_OUTPUT_INVERTED_PWM_SIGNAL,
    .deadTimeClocks_linecompl_out = 0,
#if defined (CY_IP_MXS40TCPWM)
    .hrpwm_enable = false,
    .hrpwm_input_freq = CY_TCPWM_HRPWM_FREQ_80MHZ_OR_100MHZ,
    .kill_line_polarity = CY_TCPWM_LINEOUT_AND_LINECMPOUT_IS_LOW,
    .deadTimeClocksBuff = 0,
    .deadTimeClocksBuff_linecompl_out = 0,
    .buffer_swap_enable = false,
    .glitch_filter_enable = false,
    .gf_depth = CY_GLITCH_FILTER_DEPTH_SUPPORT_VALUE_0,
    .dithering_mode = CY_TCPWM_DITHERING_DISABLE,
    .period_dithering_value = 128,
    .duty_dithering_value = 128,
    .limiter = CY_TCPWM_DITHERING_LIMITER_7,
    .pwm_tc_sync_kill_dt = false,
    .pwm_sync_kill_dt = false,
    .debug_freeze_enable = true,
    .debug_suspend_enable = true,
#endif /* defined (CY_IP_MXS40TCPWM) */
};

#if defined (COMPONENT_MTB_HAL)
const mtb_hal_peri_div_t PWM_C_U_clock_ref =
{
    .clk_dst = (en_clk_dst_t)PCLK_TCPWM0_CLOCK_COUNTER_EN1,
    .div_type = CY_SYSCLK_DIV_8_BIT,
    .div_num = 0,
};
const mtb_hal_clock_t PWM_C_U_hal_clock =
{
    .clock_ref = &PWM_C_U_clock_ref,
    .interface = &mtb_hal_clock_peri_interface,
};
#endif /* defined (COMPONENT_MTB_HAL) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM)
const mtb_hal_pwm_configurator_t PWM_C_U_hal_config =
{
    .base = PWM_C_U_HW,
    .clock = &PWM_C_U_hal_clock,
    .group = 0UL,
    .cntnum = 1UL,
    .max_count = 239999,
};
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM) */

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
const cyhal_resource_inst_t PWM_C_U_obj =
{
    .type = CYHAL_RSC_TCPWM,
    .block_num = 0U,
    .channel_num = 1U,
};
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

#if defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL)
const cyhal_clock_t PWM_C_U_clock =
{
    .block = CYHAL_CLOCK_BLOCK_PERIPHERAL5_8BIT,
    .channel = 0,
#if defined (CY_USING_HAL)
    .reserved = false,
    .funcs = NULL,
#endif /* defined (CY_USING_HAL) */
};
#endif /* defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL) */

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
const cyhal_pwm_configurator_t PWM_C_U_hal_config =
{
    .resource = &PWM_C_U_obj,
    .config = &PWM_C_U_config,
    .clock = &PWM_C_U_clock,
};
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

const cy_stc_tcpwm_pwm_config_t PWM_C_V_config =
{
    .pwmMode = CY_TCPWM_PWM_MODE_PWM,
    .clockPrescaler = CY_TCPWM_PWM_PRESCALER_DIVBY_1,
    .pwmAlignment = CY_TCPWM_PWM_LEFT_ALIGN,
    .deadTimeClocks = 0,
    .runMode = CY_TCPWM_PWM_CONTINUOUS,
    .period0 = 239999,
    .period1 = 32768,
    .enablePeriodSwap = false,
    .compare0 = 0,
    .compare1 = 16384,
    .enableCompareSwap = false,
    .interruptSources = (CY_TCPWM_INT_ON_TC & 0U) | (CY_TCPWM_INT_ON_CC0 & 0U) | (CY_TCPWM_INT_ON_CC1 & 0U),
    .invertPWMOut = CY_TCPWM_PWM_INVERT_DISABLE,
    .invertPWMOutN = CY_TCPWM_PWM_INVERT_DISABLE,
    .killMode = CY_TCPWM_PWM_STOP_ON_KILL,
    .swapInputMode = PWM_C_V_INPUT_DISABLED & 0x3U,
    .swapInput = CY_TCPWM_INPUT_0,
    .reloadInputMode = PWM_C_V_INPUT_DISABLED & 0x3U,
    .reloadInput = CY_TCPWM_INPUT_0,
    .startInputMode = CY_TCPWM_INPUT_RISINGEDGE,
    .startInput = TCPWM0_GRP0_CNT2_START_VALUE,
    .killInputMode = CY_TCPWM_INPUT_FALLINGEDGE,
    .killInput = TCPWM0_GRP0_CNT2_STOP_VALUE,
    .countInputMode = PWM_C_V_INPUT_DISABLED & 0x3U,
    .countInput = CY_TCPWM_INPUT_1,
    .swapOverflowUnderflow = false,
    .immediateKill = false,
    .tapsEnabled = 45,
    .compare2 = 0,
    .compare3 = 16384,
    .enableCompare1Swap = false,
    .compare0MatchUp = true,
    .compare0MatchDown = false,
    .compare1MatchUp = true,
    .compare1MatchDown = false,
    .kill1InputMode = PWM_C_V_INPUT_DISABLED & 0x3U,
    .kill1Input = CY_TCPWM_INPUT_0,
    .pwmOnDisable = CY_TCPWM_PWM_OUTPUT_HIGHZ,
    .trigger0Event = CY_TCPWM_CNT_TRIGGER_ON_DISABLED,
    .trigger1Event = CY_TCPWM_CNT_TRIGGER_ON_DISABLED,
    .reloadLineSelect = false,
    .line_out_sel = CY_TCPWM_OUTPUT_PWM_SIGNAL,
    .linecompl_out_sel = CY_TCPWM_OUTPUT_INVERTED_PWM_SIGNAL,
    .line_out_sel_buff = CY_TCPWM_OUTPUT_PWM_SIGNAL,
    .linecompl_out_sel_buff = CY_TCPWM_OUTPUT_INVERTED_PWM_SIGNAL,
    .deadTimeClocks_linecompl_out = 0,
#if defined (CY_IP_MXS40TCPWM)
    .hrpwm_enable = false,
    .hrpwm_input_freq = CY_TCPWM_HRPWM_FREQ_80MHZ_OR_100MHZ,
    .kill_line_polarity = CY_TCPWM_LINEOUT_AND_LINECMPOUT_IS_LOW,
    .deadTimeClocksBuff = 0,
    .deadTimeClocksBuff_linecompl_out = 0,
    .buffer_swap_enable = false,
    .glitch_filter_enable = false,
    .gf_depth = CY_GLITCH_FILTER_DEPTH_SUPPORT_VALUE_0,
    .dithering_mode = CY_TCPWM_DITHERING_DISABLE,
    .period_dithering_value = 128,
    .duty_dithering_value = 128,
    .limiter = CY_TCPWM_DITHERING_LIMITER_7,
    .pwm_tc_sync_kill_dt = false,
    .pwm_sync_kill_dt = false,
    .debug_freeze_enable = false,
    .debug_suspend_enable = false,
#endif /* defined (CY_IP_MXS40TCPWM) */
};

#if defined (COMPONENT_MTB_HAL)
const mtb_hal_peri_div_t PWM_C_V_clock_ref =
{
    .clk_dst = (en_clk_dst_t)PCLK_TCPWM0_CLOCK_COUNTER_EN2,
    .div_type = CY_SYSCLK_DIV_8_BIT,
    .div_num = 0,
};
const mtb_hal_clock_t PWM_C_V_hal_clock =
{
    .clock_ref = &PWM_C_V_clock_ref,
    .interface = &mtb_hal_clock_peri_interface,
};
#endif /* defined (COMPONENT_MTB_HAL) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM)
const mtb_hal_pwm_configurator_t PWM_C_V_hal_config =
{
    .base = PWM_C_V_HW,
    .clock = &PWM_C_V_hal_clock,
    .group = 0UL,
    .cntnum = 2UL,
    .max_count = 239999,
};
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM) */

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
const cyhal_resource_inst_t PWM_C_V_obj =
{
    .type = CYHAL_RSC_TCPWM,
    .block_num = 0U,
    .channel_num = 2U,
};
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

#if defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL)
const cyhal_clock_t PWM_C_V_clock =
{
    .block = CYHAL_CLOCK_BLOCK_PERIPHERAL5_8BIT,
    .channel = 0,
#if defined (CY_USING_HAL)
    .reserved = false,
    .funcs = NULL,
#endif /* defined (CY_USING_HAL) */
};
#endif /* defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL) */

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
const cyhal_pwm_configurator_t PWM_C_V_hal_config =
{
    .resource = &PWM_C_V_obj,
    .config = &PWM_C_V_config,
    .clock = &PWM_C_V_clock,
};
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

const cy_stc_tcpwm_pwm_config_t PWM_START_C_config =
{
    .pwmMode = CY_TCPWM_PWM_MODE_PWM,
    .clockPrescaler = CY_TCPWM_PWM_PRESCALER_DIVBY_1,
    .pwmAlignment = CY_TCPWM_PWM_LEFT_ALIGN,
    .deadTimeClocks = 0,
    .runMode = CY_TCPWM_PWM_CONTINUOUS,
    .period0 = 20,
    .period1 = 32768,
    .enablePeriodSwap = false,
    .compare0 = 10,
    .compare1 = 16384,
    .enableCompareSwap = false,
    .interruptSources = (CY_TCPWM_INT_ON_TC & 0U) | (CY_TCPWM_INT_ON_CC0 & 0U) | (CY_TCPWM_INT_ON_CC1 & 0U),
    .invertPWMOut = CY_TCPWM_PWM_INVERT_DISABLE,
    .invertPWMOutN = CY_TCPWM_PWM_INVERT_DISABLE,
    .killMode = CY_TCPWM_PWM_STOP_ON_KILL,
    .swapInputMode = PWM_START_C_INPUT_DISABLED & 0x3U,
    .swapInput = CY_TCPWM_INPUT_0,
    .reloadInputMode = PWM_START_C_INPUT_DISABLED & 0x3U,
    .reloadInput = CY_TCPWM_INPUT_0,
    .startInputMode = PWM_START_C_INPUT_DISABLED & 0x3U,
    .startInput = CY_TCPWM_INPUT_0,
    .killInputMode = PWM_START_C_INPUT_DISABLED & 0x3U,
    .killInput = CY_TCPWM_INPUT_0,
    .countInputMode = PWM_START_C_INPUT_DISABLED & 0x3U,
    .countInput = CY_TCPWM_INPUT_1,
    .swapOverflowUnderflow = false,
    .immediateKill = false,
    .tapsEnabled = 45,
    .compare2 = 10,
    .compare3 = 16384,
    .enableCompare1Swap = false,
    .compare0MatchUp = true,
    .compare0MatchDown = false,
    .compare1MatchUp = true,
    .compare1MatchDown = false,
    .kill1InputMode = PWM_START_C_INPUT_DISABLED & 0x3U,
    .kill1Input = CY_TCPWM_INPUT_0,
    .pwmOnDisable = CY_TCPWM_PWM_OUTPUT_LOW,
    .trigger0Event = CY_TCPWM_CNT_TRIGGER_ON_CC0_MATCH,
    .trigger1Event = CY_TCPWM_CNT_TRIGGER_ON_DISABLED,
    .reloadLineSelect = false,
    .line_out_sel = CY_TCPWM_OUTPUT_PWM_SIGNAL,
    .linecompl_out_sel = CY_TCPWM_OUTPUT_INVERTED_PWM_SIGNAL,
    .line_out_sel_buff = CY_TCPWM_OUTPUT_PWM_SIGNAL,
    .linecompl_out_sel_buff = CY_TCPWM_OUTPUT_INVERTED_PWM_SIGNAL,
    .deadTimeClocks_linecompl_out = 0,
#if defined (CY_IP_MXS40TCPWM)
    .hrpwm_enable = false,
    .hrpwm_input_freq = CY_TCPWM_HRPWM_FREQ_80MHZ_OR_100MHZ,
    .kill_line_polarity = CY_TCPWM_LINEOUT_AND_LINECMPOUT_IS_LOW,
    .deadTimeClocksBuff = 0,
    .deadTimeClocksBuff_linecompl_out = 0,
    .buffer_swap_enable = false,
    .glitch_filter_enable = false,
    .gf_depth = CY_GLITCH_FILTER_DEPTH_SUPPORT_VALUE_0,
    .dithering_mode = CY_TCPWM_DITHERING_DISABLE,
    .period_dithering_value = 128,
    .duty_dithering_value = 128,
    .limiter = CY_TCPWM_DITHERING_LIMITER_7,
    .pwm_tc_sync_kill_dt = false,
    .pwm_sync_kill_dt = false,
    .debug_freeze_enable = false,
    .debug_suspend_enable = false,
#endif /* defined (CY_IP_MXS40TCPWM) */
};

#if defined (COMPONENT_MTB_HAL)
const mtb_hal_peri_div_t PWM_START_C_clock_ref =
{
    .clk_dst = (en_clk_dst_t)PCLK_TCPWM0_CLOCK_COUNTER_EN3,
    .div_type = CY_SYSCLK_DIV_8_BIT,
    .div_num = 0,
};
const mtb_hal_clock_t PWM_START_C_hal_clock =
{
    .clock_ref = &PWM_START_C_clock_ref,
    .interface = &mtb_hal_clock_peri_interface,
};
#endif /* defined (COMPONENT_MTB_HAL) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM)
const mtb_hal_pwm_configurator_t PWM_START_C_hal_config =
{
    .base = PWM_START_C_HW,
    .clock = &PWM_START_C_hal_clock,
    .group = 0UL,
    .cntnum = 3UL,
    .max_count = 20,
};
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM) */

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
const cyhal_resource_inst_t PWM_START_C_obj =
{
    .type = CYHAL_RSC_TCPWM,
    .block_num = 0U,
    .channel_num = 3U,
};
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

#if defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL)
const cyhal_clock_t PWM_START_C_clock =
{
    .block = CYHAL_CLOCK_BLOCK_PERIPHERAL5_8BIT,
    .channel = 0,
#if defined (CY_USING_HAL)
    .reserved = false,
    .funcs = NULL,
#endif /* defined (CY_USING_HAL) */
};
#endif /* defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL) */

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
const cyhal_pwm_configurator_t PWM_START_C_hal_config =
{
    .resource = &PWM_START_C_obj,
    .config = &PWM_START_C_config,
    .clock = &PWM_START_C_clock,
};
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

const cy_stc_tcpwm_pwm_config_t PWM_A_U_config =
{
    .pwmMode = CY_TCPWM_PWM_MODE_PWM,
    .clockPrescaler = CY_TCPWM_PWM_PRESCALER_DIVBY_1,
    .pwmAlignment = CY_TCPWM_PWM_CENTER_ASYMMETRIC_CC0_CC1_ALIGN,
    .deadTimeClocks = 10,
    .runMode = CY_TCPWM_PWM_CONTINUOUS,
    .period0 = 11999,
    .period1 = 32768,
    .enablePeriodSwap = false,
    .compare0 = 0,
    .compare1 = 16384,
    .enableCompareSwap = false,
    .interruptSources = (CY_TCPWM_INT_ON_TC & 0U) | (CY_TCPWM_INT_ON_CC0 & 0U) | (CY_TCPWM_INT_ON_CC1 & 0U),
    .invertPWMOut = CY_TCPWM_PWM_INVERT_ENABLE,
    .invertPWMOutN = CY_TCPWM_PWM_INVERT_ENABLE,
    .killMode = CY_TCPWM_PWM_STOP_ON_KILL,
    .swapInputMode = PWM_A_U_INPUT_DISABLED & 0x3U,
    .swapInput = CY_TCPWM_INPUT_0,
    .reloadInputMode = PWM_A_U_INPUT_DISABLED & 0x3U,
    .reloadInput = CY_TCPWM_INPUT_0,
    .startInputMode = CY_TCPWM_INPUT_RISINGEDGE,
    .startInput = TCPWM0_GRP1_CNT0_START_VALUE,
    .killInputMode = CY_TCPWM_INPUT_FALLINGEDGE,
    .killInput = TCPWM0_GRP1_CNT0_STOP_VALUE,
    .countInputMode = PWM_A_U_INPUT_DISABLED & 0x3U,
    .countInput = CY_TCPWM_INPUT_1,
    .swapOverflowUnderflow = false,
    .immediateKill = false,
    .tapsEnabled = 45,
    .compare2 = 0,
    .compare3 = 16384,
    .enableCompare1Swap = false,
    .compare0MatchUp = false,
    .compare0MatchDown = false,
    .compare1MatchUp = false,
    .compare1MatchDown = false,
    .kill1InputMode = PWM_A_U_INPUT_DISABLED & 0x3U,
    .kill1Input = CY_TCPWM_INPUT_0,
    .pwmOnDisable = CY_TCPWM_PWM_OUTPUT_LOW,
    .trigger0Event = CY_TCPWM_CNT_TRIGGER_ON_DISABLED,
    .trigger1Event = CY_TCPWM_CNT_TRIGGER_ON_OVERFLOW,
    .reloadLineSelect = false,
    .line_out_sel = CY_TCPWM_OUTPUT_PWM_SIGNAL,
    .linecompl_out_sel = CY_TCPWM_OUTPUT_INVERTED_PWM_SIGNAL,
    .line_out_sel_buff = CY_TCPWM_OUTPUT_PWM_SIGNAL,
    .linecompl_out_sel_buff = CY_TCPWM_OUTPUT_INVERTED_PWM_SIGNAL,
    .deadTimeClocks_linecompl_out = 10,
#if defined (CY_IP_MXS40TCPWM)
    .hrpwm_enable = false,
    .hrpwm_input_freq = CY_TCPWM_HRPWM_FREQ_80MHZ_OR_100MHZ,
    .kill_line_polarity = CY_TCPWM_LINEOUT_AND_LINECMPOUT_IS_LOW,
    .deadTimeClocksBuff = 0,
    .deadTimeClocksBuff_linecompl_out = 0,
    .buffer_swap_enable = false,
    .glitch_filter_enable = false,
    .gf_depth = CY_GLITCH_FILTER_DEPTH_SUPPORT_VALUE_0,
    .dithering_mode = CY_TCPWM_DITHERING_DISABLE,
    .period_dithering_value = 128,
    .duty_dithering_value = 128,
    .limiter = CY_TCPWM_DITHERING_LIMITER_7,
    .pwm_tc_sync_kill_dt = false,
    .pwm_sync_kill_dt = false,
    .debug_freeze_enable = true,
    .debug_suspend_enable = true,
#endif /* defined (CY_IP_MXS40TCPWM) */
};

#if defined (COMPONENT_MTB_HAL)
const mtb_hal_peri_div_t PWM_A_U_clock_ref =
{
    .clk_dst = (en_clk_dst_t)PCLK_TCPWM0_CLOCK_COUNTER_EN256,
    .div_type = CY_SYSCLK_DIV_8_BIT,
    .div_num = 0,
};
const mtb_hal_clock_t PWM_A_U_hal_clock =
{
    .clock_ref = &PWM_A_U_clock_ref,
    .interface = &mtb_hal_clock_peri_interface,
};
#endif /* defined (COMPONENT_MTB_HAL) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM)
const mtb_hal_pwm_configurator_t PWM_A_U_hal_config =
{
    .base = PWM_A_U_HW,
    .clock = &PWM_A_U_hal_clock,
    .group = 1UL,
    .cntnum = 256UL,
    .max_count = 11999,
};
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM) */

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
const cyhal_resource_inst_t PWM_A_U_obj =
{
    .type = CYHAL_RSC_TCPWM,
    .block_num = 1U,
    .channel_num = 0U,
};
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

#if defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL)
const cyhal_clock_t PWM_A_U_clock =
{
    .block = CYHAL_CLOCK_BLOCK_PERIPHERAL5_8BIT,
    .channel = 0,
#if defined (CY_USING_HAL)
    .reserved = false,
    .funcs = NULL,
#endif /* defined (CY_USING_HAL) */
};
#endif /* defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL) */

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
const cyhal_pwm_configurator_t PWM_A_U_hal_config =
{
    .resource = &PWM_A_U_obj,
    .config = &PWM_A_U_config,
    .clock = &PWM_A_U_clock,
};
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

const cy_stc_tcpwm_pwm_config_t PWM_A_V_config =
{
    .pwmMode = CY_TCPWM_PWM_MODE_PWM,
    .clockPrescaler = CY_TCPWM_PWM_PRESCALER_DIVBY_1,
    .pwmAlignment = CY_TCPWM_PWM_CENTER_ASYMMETRIC_CC0_CC1_ALIGN,
    .deadTimeClocks = 10,
    .runMode = CY_TCPWM_PWM_CONTINUOUS,
    .period0 = 11999,
    .period1 = 32768,
    .enablePeriodSwap = false,
    .compare0 = 0,
    .compare1 = 16384,
    .enableCompareSwap = false,
    .interruptSources = (CY_TCPWM_INT_ON_TC & 0U) | (CY_TCPWM_INT_ON_CC0 & 0U) | (CY_TCPWM_INT_ON_CC1 & 0U),
    .invertPWMOut = CY_TCPWM_PWM_INVERT_ENABLE,
    .invertPWMOutN = CY_TCPWM_PWM_INVERT_ENABLE,
    .killMode = CY_TCPWM_PWM_STOP_ON_KILL,
    .swapInputMode = PWM_A_V_INPUT_DISABLED & 0x3U,
    .swapInput = CY_TCPWM_INPUT_0,
    .reloadInputMode = PWM_A_V_INPUT_DISABLED & 0x3U,
    .reloadInput = CY_TCPWM_INPUT_0,
    .startInputMode = CY_TCPWM_INPUT_RISINGEDGE,
    .startInput = TCPWM0_GRP1_CNT1_START_VALUE,
    .killInputMode = CY_TCPWM_INPUT_FALLINGEDGE,
    .killInput = TCPWM0_GRP1_CNT1_STOP_VALUE,
    .countInputMode = PWM_A_V_INPUT_DISABLED & 0x3U,
    .countInput = CY_TCPWM_INPUT_1,
    .swapOverflowUnderflow = false,
    .immediateKill = false,
    .tapsEnabled = 45,
    .compare2 = 0,
    .compare3 = 16384,
    .enableCompare1Swap = false,
    .compare0MatchUp = false,
    .compare0MatchDown = false,
    .compare1MatchUp = false,
    .compare1MatchDown = false,
    .kill1InputMode = PWM_A_V_INPUT_DISABLED & 0x3U,
    .kill1Input = CY_TCPWM_INPUT_0,
    .pwmOnDisable = CY_TCPWM_PWM_OUTPUT_LOW,
    .trigger0Event = CY_TCPWM_CNT_TRIGGER_ON_DISABLED,
    .trigger1Event = CY_TCPWM_CNT_TRIGGER_ON_DISABLED,
    .reloadLineSelect = false,
    .line_out_sel = CY_TCPWM_OUTPUT_PWM_SIGNAL,
    .linecompl_out_sel = CY_TCPWM_OUTPUT_INVERTED_PWM_SIGNAL,
    .line_out_sel_buff = CY_TCPWM_OUTPUT_PWM_SIGNAL,
    .linecompl_out_sel_buff = CY_TCPWM_OUTPUT_INVERTED_PWM_SIGNAL,
    .deadTimeClocks_linecompl_out = 10,
#if defined (CY_IP_MXS40TCPWM)
    .hrpwm_enable = false,
    .hrpwm_input_freq = CY_TCPWM_HRPWM_FREQ_80MHZ_OR_100MHZ,
    .kill_line_polarity = CY_TCPWM_LINEOUT_AND_LINECMPOUT_IS_LOW,
    .deadTimeClocksBuff = 0,
    .deadTimeClocksBuff_linecompl_out = 0,
    .buffer_swap_enable = false,
    .glitch_filter_enable = false,
    .gf_depth = CY_GLITCH_FILTER_DEPTH_SUPPORT_VALUE_0,
    .dithering_mode = CY_TCPWM_DITHERING_DISABLE,
    .period_dithering_value = 128,
    .duty_dithering_value = 128,
    .limiter = CY_TCPWM_DITHERING_LIMITER_7,
    .pwm_tc_sync_kill_dt = false,
    .pwm_sync_kill_dt = false,
    .debug_freeze_enable = true,
    .debug_suspend_enable = true,
#endif /* defined (CY_IP_MXS40TCPWM) */
};

#if defined (COMPONENT_MTB_HAL)
const mtb_hal_peri_div_t PWM_A_V_clock_ref =
{
    .clk_dst = (en_clk_dst_t)PCLK_TCPWM0_CLOCK_COUNTER_EN257,
    .div_type = CY_SYSCLK_DIV_8_BIT,
    .div_num = 0,
};
const mtb_hal_clock_t PWM_A_V_hal_clock =
{
    .clock_ref = &PWM_A_V_clock_ref,
    .interface = &mtb_hal_clock_peri_interface,
};
#endif /* defined (COMPONENT_MTB_HAL) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM)
const mtb_hal_pwm_configurator_t PWM_A_V_hal_config =
{
    .base = PWM_A_V_HW,
    .clock = &PWM_A_V_hal_clock,
    .group = 1UL,
    .cntnum = 257UL,
    .max_count = 11999,
};
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM) */

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
const cyhal_resource_inst_t PWM_A_V_obj =
{
    .type = CYHAL_RSC_TCPWM,
    .block_num = 1U,
    .channel_num = 1U,
};
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

#if defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL)
const cyhal_clock_t PWM_A_V_clock =
{
    .block = CYHAL_CLOCK_BLOCK_PERIPHERAL5_8BIT,
    .channel = 0,
#if defined (CY_USING_HAL)
    .reserved = false,
    .funcs = NULL,
#endif /* defined (CY_USING_HAL) */
};
#endif /* defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL) */

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
const cyhal_pwm_configurator_t PWM_A_V_hal_config =
{
    .resource = &PWM_A_V_obj,
    .config = &PWM_A_V_config,
    .clock = &PWM_A_V_clock,
};
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

const cy_stc_tcpwm_pwm_config_t PWM_A_W_config =
{
    .pwmMode = CY_TCPWM_PWM_MODE_PWM,
    .clockPrescaler = CY_TCPWM_PWM_PRESCALER_DIVBY_1,
    .pwmAlignment = CY_TCPWM_PWM_CENTER_ASYMMETRIC_CC0_CC1_ALIGN,
    .deadTimeClocks = 100,
    .runMode = CY_TCPWM_PWM_CONTINUOUS,
    .period0 = 11999,
    .period1 = 32768,
    .enablePeriodSwap = false,
    .compare0 = 0,
    .compare1 = 16384,
    .enableCompareSwap = false,
    .interruptSources = (CY_TCPWM_INT_ON_TC & 0U) | (CY_TCPWM_INT_ON_CC0 & 0U) | (CY_TCPWM_INT_ON_CC1 & 0U),
    .invertPWMOut = CY_TCPWM_PWM_INVERT_ENABLE,
    .invertPWMOutN = CY_TCPWM_PWM_INVERT_ENABLE,
    .killMode = CY_TCPWM_PWM_STOP_ON_KILL,
    .swapInputMode = PWM_A_W_INPUT_DISABLED & 0x3U,
    .swapInput = CY_TCPWM_INPUT_0,
    .reloadInputMode = PWM_A_W_INPUT_DISABLED & 0x3U,
    .reloadInput = CY_TCPWM_INPUT_0,
    .startInputMode = CY_TCPWM_INPUT_RISINGEDGE,
    .startInput = TCPWM0_GRP1_CNT2_START_VALUE,
    .killInputMode = CY_TCPWM_INPUT_FALLINGEDGE,
    .killInput = TCPWM0_GRP1_CNT2_STOP_VALUE,
    .countInputMode = PWM_A_W_INPUT_DISABLED & 0x3U,
    .countInput = CY_TCPWM_INPUT_1,
    .swapOverflowUnderflow = false,
    .immediateKill = false,
    .tapsEnabled = 45,
    .compare2 = 0,
    .compare3 = 16384,
    .enableCompare1Swap = false,
    .compare0MatchUp = false,
    .compare0MatchDown = false,
    .compare1MatchUp = false,
    .compare1MatchDown = false,
    .kill1InputMode = PWM_A_W_INPUT_DISABLED & 0x3U,
    .kill1Input = CY_TCPWM_INPUT_0,
    .pwmOnDisable = CY_TCPWM_PWM_OUTPUT_LOW,
    .trigger0Event = CY_TCPWM_CNT_TRIGGER_ON_DISABLED,
    .trigger1Event = CY_TCPWM_CNT_TRIGGER_ON_DISABLED,
    .reloadLineSelect = false,
    .line_out_sel = CY_TCPWM_OUTPUT_PWM_SIGNAL,
    .linecompl_out_sel = CY_TCPWM_OUTPUT_INVERTED_PWM_SIGNAL,
    .line_out_sel_buff = CY_TCPWM_OUTPUT_PWM_SIGNAL,
    .linecompl_out_sel_buff = CY_TCPWM_OUTPUT_INVERTED_PWM_SIGNAL,
    .deadTimeClocks_linecompl_out = 100,
#if defined (CY_IP_MXS40TCPWM)
    .hrpwm_enable = false,
    .hrpwm_input_freq = CY_TCPWM_HRPWM_FREQ_80MHZ_OR_100MHZ,
    .kill_line_polarity = CY_TCPWM_LINEOUT_AND_LINECMPOUT_IS_LOW,
    .deadTimeClocksBuff = 0,
    .deadTimeClocksBuff_linecompl_out = 0,
    .buffer_swap_enable = false,
    .glitch_filter_enable = false,
    .gf_depth = CY_GLITCH_FILTER_DEPTH_SUPPORT_VALUE_0,
    .dithering_mode = CY_TCPWM_DITHERING_DISABLE,
    .period_dithering_value = 128,
    .duty_dithering_value = 128,
    .limiter = CY_TCPWM_DITHERING_LIMITER_7,
    .pwm_tc_sync_kill_dt = false,
    .pwm_sync_kill_dt = false,
    .debug_freeze_enable = true,
    .debug_suspend_enable = true,
#endif /* defined (CY_IP_MXS40TCPWM) */
};

#if defined (COMPONENT_MTB_HAL)
const mtb_hal_peri_div_t PWM_A_W_clock_ref =
{
    .clk_dst = (en_clk_dst_t)PCLK_TCPWM0_CLOCK_COUNTER_EN258,
    .div_type = CY_SYSCLK_DIV_8_BIT,
    .div_num = 0,
};
const mtb_hal_clock_t PWM_A_W_hal_clock =
{
    .clock_ref = &PWM_A_W_clock_ref,
    .interface = &mtb_hal_clock_peri_interface,
};
#endif /* defined (COMPONENT_MTB_HAL) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM)
const mtb_hal_pwm_configurator_t PWM_A_W_hal_config =
{
    .base = PWM_A_W_HW,
    .clock = &PWM_A_W_hal_clock,
    .group = 1UL,
    .cntnum = 258UL,
    .max_count = 11999,
};
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM) */

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
const cyhal_resource_inst_t PWM_A_W_obj =
{
    .type = CYHAL_RSC_TCPWM,
    .block_num = 1U,
    .channel_num = 2U,
};
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

#if defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL)
const cyhal_clock_t PWM_A_W_clock =
{
    .block = CYHAL_CLOCK_BLOCK_PERIPHERAL5_8BIT,
    .channel = 0,
#if defined (CY_USING_HAL)
    .reserved = false,
    .funcs = NULL,
#endif /* defined (CY_USING_HAL) */
};
#endif /* defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL) */

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
const cyhal_pwm_configurator_t PWM_A_W_hal_config =
{
    .resource = &PWM_A_W_obj,
    .config = &PWM_A_W_config,
    .clock = &PWM_A_W_clock,
};
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

const cy_stc_tcpwm_pwm_config_t PWM_B_U_config =
{
    .pwmMode = CY_TCPWM_PWM_MODE_PWM,
    .clockPrescaler = CY_TCPWM_PWM_PRESCALER_DIVBY_1,
    .pwmAlignment = CY_TCPWM_PWM_CENTER_ASYMMETRIC_CC0_CC1_ALIGN,
    .deadTimeClocks = 0,
    .runMode = CY_TCPWM_PWM_CONTINUOUS,
    .period0 = 5999,
    .period1 = 32768,
    .enablePeriodSwap = false,
    .compare0 = 0,
    .compare1 = 16384,
    .enableCompareSwap = false,
    .interruptSources = (CY_TCPWM_INT_ON_TC & 0U) | (CY_TCPWM_INT_ON_CC0 & 0U) | (CY_TCPWM_INT_ON_CC1 & 0U),
    .invertPWMOut = CY_TCPWM_PWM_INVERT_DISABLE,
    .invertPWMOutN = CY_TCPWM_PWM_INVERT_DISABLE,
    .killMode = CY_TCPWM_PWM_STOP_ON_KILL,
    .swapInputMode = PWM_B_U_INPUT_DISABLED & 0x3U,
    .swapInput = CY_TCPWM_INPUT_0,
    .reloadInputMode = PWM_B_U_INPUT_DISABLED & 0x3U,
    .reloadInput = CY_TCPWM_INPUT_0,
    .startInputMode = CY_TCPWM_INPUT_RISINGEDGE,
    .startInput = TCPWM0_GRP1_CNT3_START_VALUE,
    .killInputMode = CY_TCPWM_INPUT_FALLINGEDGE,
    .killInput = TCPWM0_GRP1_CNT3_STOP_VALUE,
    .countInputMode = PWM_B_U_INPUT_DISABLED & 0x3U,
    .countInput = CY_TCPWM_INPUT_1,
    .swapOverflowUnderflow = false,
    .immediateKill = false,
    .tapsEnabled = 45,
    .compare2 = 0,
    .compare3 = 16384,
    .enableCompare1Swap = false,
    .compare0MatchUp = true,
    .compare0MatchDown = false,
    .compare1MatchUp = true,
    .compare1MatchDown = false,
    .kill1InputMode = PWM_B_U_INPUT_DISABLED & 0x3U,
    .kill1Input = CY_TCPWM_INPUT_0,
    .pwmOnDisable = CY_TCPWM_PWM_OUTPUT_HIGHZ,
    .trigger0Event = CY_TCPWM_CNT_TRIGGER_ON_DISABLED,
    .trigger1Event = CY_TCPWM_CNT_TRIGGER_ON_OVERFLOW,
    .reloadLineSelect = false,
    .line_out_sel = CY_TCPWM_OUTPUT_PWM_SIGNAL,
    .linecompl_out_sel = CY_TCPWM_OUTPUT_INVERTED_PWM_SIGNAL,
    .line_out_sel_buff = CY_TCPWM_OUTPUT_PWM_SIGNAL,
    .linecompl_out_sel_buff = CY_TCPWM_OUTPUT_INVERTED_PWM_SIGNAL,
    .deadTimeClocks_linecompl_out = 0,
#if defined (CY_IP_MXS40TCPWM)
    .hrpwm_enable = false,
    .hrpwm_input_freq = CY_TCPWM_HRPWM_FREQ_80MHZ_OR_100MHZ,
    .kill_line_polarity = CY_TCPWM_LINEOUT_AND_LINECMPOUT_IS_LOW,
    .deadTimeClocksBuff = 0,
    .deadTimeClocksBuff_linecompl_out = 0,
    .buffer_swap_enable = false,
    .glitch_filter_enable = false,
    .gf_depth = CY_GLITCH_FILTER_DEPTH_SUPPORT_VALUE_0,
    .dithering_mode = CY_TCPWM_DITHERING_DISABLE,
    .period_dithering_value = 128,
    .duty_dithering_value = 128,
    .limiter = CY_TCPWM_DITHERING_LIMITER_7,
    .pwm_tc_sync_kill_dt = false,
    .pwm_sync_kill_dt = false,
    .debug_freeze_enable = true,
    .debug_suspend_enable = true,
#endif /* defined (CY_IP_MXS40TCPWM) */
};

#if defined (COMPONENT_MTB_HAL)
const mtb_hal_peri_div_t PWM_B_U_clock_ref =
{
    .clk_dst = (en_clk_dst_t)PCLK_TCPWM0_CLOCK_COUNTER_EN259,
    .div_type = CY_SYSCLK_DIV_8_BIT,
    .div_num = 0,
};
const mtb_hal_clock_t PWM_B_U_hal_clock =
{
    .clock_ref = &PWM_B_U_clock_ref,
    .interface = &mtb_hal_clock_peri_interface,
};
#endif /* defined (COMPONENT_MTB_HAL) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM)
const mtb_hal_pwm_configurator_t PWM_B_U_hal_config =
{
    .base = PWM_B_U_HW,
    .clock = &PWM_B_U_hal_clock,
    .group = 1UL,
    .cntnum = 259UL,
    .max_count = 5999,
};
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM) */

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
const cyhal_resource_inst_t PWM_B_U_obj =
{
    .type = CYHAL_RSC_TCPWM,
    .block_num = 1U,
    .channel_num = 3U,
};
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

#if defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL)
const cyhal_clock_t PWM_B_U_clock =
{
    .block = CYHAL_CLOCK_BLOCK_PERIPHERAL5_8BIT,
    .channel = 0,
#if defined (CY_USING_HAL)
    .reserved = false,
    .funcs = NULL,
#endif /* defined (CY_USING_HAL) */
};
#endif /* defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL) */

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
const cyhal_pwm_configurator_t PWM_B_U_hal_config =
{
    .resource = &PWM_B_U_obj,
    .config = &PWM_B_U_config,
    .clock = &PWM_B_U_clock,
};
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

const cy_stc_tcpwm_pwm_config_t PWM_B_V_config =
{
    .pwmMode = CY_TCPWM_PWM_MODE_PWM,
    .clockPrescaler = CY_TCPWM_PWM_PRESCALER_DIVBY_1,
    .pwmAlignment = CY_TCPWM_PWM_CENTER_ASYMMETRIC_CC0_CC1_ALIGN,
    .deadTimeClocks = 0,
    .runMode = CY_TCPWM_PWM_CONTINUOUS,
    .period0 = 5999,
    .period1 = 32768,
    .enablePeriodSwap = false,
    .compare0 = 0,
    .compare1 = 16384,
    .enableCompareSwap = false,
    .interruptSources = (CY_TCPWM_INT_ON_TC & 0U) | (CY_TCPWM_INT_ON_CC0 & 0U) | (CY_TCPWM_INT_ON_CC1 & 0U),
    .invertPWMOut = CY_TCPWM_PWM_INVERT_DISABLE,
    .invertPWMOutN = CY_TCPWM_PWM_INVERT_DISABLE,
    .killMode = CY_TCPWM_PWM_STOP_ON_KILL,
    .swapInputMode = PWM_B_V_INPUT_DISABLED & 0x3U,
    .swapInput = CY_TCPWM_INPUT_0,
    .reloadInputMode = PWM_B_V_INPUT_DISABLED & 0x3U,
    .reloadInput = CY_TCPWM_INPUT_0,
    .startInputMode = CY_TCPWM_INPUT_RISINGEDGE,
    .startInput = TCPWM0_GRP1_CNT4_START_VALUE,
    .killInputMode = CY_TCPWM_INPUT_FALLINGEDGE,
    .killInput = TCPWM0_GRP1_CNT4_STOP_VALUE,
    .countInputMode = PWM_B_V_INPUT_DISABLED & 0x3U,
    .countInput = CY_TCPWM_INPUT_1,
    .swapOverflowUnderflow = false,
    .immediateKill = false,
    .tapsEnabled = 45,
    .compare2 = 0,
    .compare3 = 16384,
    .enableCompare1Swap = false,
    .compare0MatchUp = true,
    .compare0MatchDown = false,
    .compare1MatchUp = true,
    .compare1MatchDown = false,
    .kill1InputMode = PWM_B_V_INPUT_DISABLED & 0x3U,
    .kill1Input = CY_TCPWM_INPUT_0,
    .pwmOnDisable = CY_TCPWM_PWM_OUTPUT_HIGHZ,
    .trigger0Event = CY_TCPWM_CNT_TRIGGER_ON_DISABLED,
    .trigger1Event = CY_TCPWM_CNT_TRIGGER_ON_DISABLED,
    .reloadLineSelect = false,
    .line_out_sel = CY_TCPWM_OUTPUT_PWM_SIGNAL,
    .linecompl_out_sel = CY_TCPWM_OUTPUT_INVERTED_PWM_SIGNAL,
    .line_out_sel_buff = CY_TCPWM_OUTPUT_PWM_SIGNAL,
    .linecompl_out_sel_buff = CY_TCPWM_OUTPUT_INVERTED_PWM_SIGNAL,
    .deadTimeClocks_linecompl_out = 0,
#if defined (CY_IP_MXS40TCPWM)
    .hrpwm_enable = false,
    .hrpwm_input_freq = CY_TCPWM_HRPWM_FREQ_80MHZ_OR_100MHZ,
    .kill_line_polarity = CY_TCPWM_LINEOUT_AND_LINECMPOUT_IS_LOW,
    .deadTimeClocksBuff = 0,
    .deadTimeClocksBuff_linecompl_out = 0,
    .buffer_swap_enable = false,
    .glitch_filter_enable = false,
    .gf_depth = CY_GLITCH_FILTER_DEPTH_SUPPORT_VALUE_0,
    .dithering_mode = CY_TCPWM_DITHERING_DISABLE,
    .period_dithering_value = 128,
    .duty_dithering_value = 128,
    .limiter = CY_TCPWM_DITHERING_LIMITER_7,
    .pwm_tc_sync_kill_dt = false,
    .pwm_sync_kill_dt = false,
    .debug_freeze_enable = true,
    .debug_suspend_enable = true,
#endif /* defined (CY_IP_MXS40TCPWM) */
};

#if defined (COMPONENT_MTB_HAL)
const mtb_hal_peri_div_t PWM_B_V_clock_ref =
{
    .clk_dst = (en_clk_dst_t)PCLK_TCPWM0_CLOCK_COUNTER_EN260,
    .div_type = CY_SYSCLK_DIV_8_BIT,
    .div_num = 0,
};
const mtb_hal_clock_t PWM_B_V_hal_clock =
{
    .clock_ref = &PWM_B_V_clock_ref,
    .interface = &mtb_hal_clock_peri_interface,
};
#endif /* defined (COMPONENT_MTB_HAL) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM)
const mtb_hal_pwm_configurator_t PWM_B_V_hal_config =
{
    .base = PWM_B_V_HW,
    .clock = &PWM_B_V_hal_clock,
    .group = 1UL,
    .cntnum = 260UL,
    .max_count = 5999,
};
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM) */

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
const cyhal_resource_inst_t PWM_B_V_obj =
{
    .type = CYHAL_RSC_TCPWM,
    .block_num = 1U,
    .channel_num = 4U,
};
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

#if defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL)
const cyhal_clock_t PWM_B_V_clock =
{
    .block = CYHAL_CLOCK_BLOCK_PERIPHERAL5_8BIT,
    .channel = 0,
#if defined (CY_USING_HAL)
    .reserved = false,
    .funcs = NULL,
#endif /* defined (CY_USING_HAL) */
};
#endif /* defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL) */

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
const cyhal_pwm_configurator_t PWM_B_V_hal_config =
{
    .resource = &PWM_B_V_obj,
    .config = &PWM_B_V_config,
    .clock = &PWM_B_V_clock,
};
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

const cy_stc_tcpwm_pwm_config_t PWM_B_W_config =
{
    .pwmMode = CY_TCPWM_PWM_MODE_PWM,
    .clockPrescaler = CY_TCPWM_PWM_PRESCALER_DIVBY_1,
    .pwmAlignment = CY_TCPWM_PWM_CENTER_ASYMMETRIC_CC0_CC1_ALIGN,
    .deadTimeClocks = 0,
    .runMode = CY_TCPWM_PWM_CONTINUOUS,
    .period0 = 5999,
    .period1 = 32768,
    .enablePeriodSwap = false,
    .compare0 = 0,
    .compare1 = 16384,
    .enableCompareSwap = false,
    .interruptSources = (CY_TCPWM_INT_ON_TC & 0U) | (CY_TCPWM_INT_ON_CC0 & 0U) | (CY_TCPWM_INT_ON_CC1 & 0U),
    .invertPWMOut = CY_TCPWM_PWM_INVERT_DISABLE,
    .invertPWMOutN = CY_TCPWM_PWM_INVERT_DISABLE,
    .killMode = CY_TCPWM_PWM_STOP_ON_KILL,
    .swapInputMode = PWM_B_W_INPUT_DISABLED & 0x3U,
    .swapInput = CY_TCPWM_INPUT_0,
    .reloadInputMode = PWM_B_W_INPUT_DISABLED & 0x3U,
    .reloadInput = CY_TCPWM_INPUT_0,
    .startInputMode = CY_TCPWM_INPUT_RISINGEDGE,
    .startInput = TCPWM0_GRP1_CNT5_START_VALUE,
    .killInputMode = CY_TCPWM_INPUT_FALLINGEDGE,
    .killInput = TCPWM0_GRP1_CNT5_STOP_VALUE,
    .countInputMode = PWM_B_W_INPUT_DISABLED & 0x3U,
    .countInput = CY_TCPWM_INPUT_1,
    .swapOverflowUnderflow = false,
    .immediateKill = false,
    .tapsEnabled = 45,
    .compare2 = 0,
    .compare3 = 16384,
    .enableCompare1Swap = false,
    .compare0MatchUp = true,
    .compare0MatchDown = false,
    .compare1MatchUp = true,
    .compare1MatchDown = false,
    .kill1InputMode = PWM_B_W_INPUT_DISABLED & 0x3U,
    .kill1Input = CY_TCPWM_INPUT_0,
    .pwmOnDisable = CY_TCPWM_PWM_OUTPUT_HIGHZ,
    .trigger0Event = CY_TCPWM_CNT_TRIGGER_ON_DISABLED,
    .trigger1Event = CY_TCPWM_CNT_TRIGGER_ON_DISABLED,
    .reloadLineSelect = false,
    .line_out_sel = CY_TCPWM_OUTPUT_PWM_SIGNAL,
    .linecompl_out_sel = CY_TCPWM_OUTPUT_INVERTED_PWM_SIGNAL,
    .line_out_sel_buff = CY_TCPWM_OUTPUT_PWM_SIGNAL,
    .linecompl_out_sel_buff = CY_TCPWM_OUTPUT_INVERTED_PWM_SIGNAL,
    .deadTimeClocks_linecompl_out = 0,
#if defined (CY_IP_MXS40TCPWM)
    .hrpwm_enable = false,
    .hrpwm_input_freq = CY_TCPWM_HRPWM_FREQ_80MHZ_OR_100MHZ,
    .kill_line_polarity = CY_TCPWM_LINEOUT_AND_LINECMPOUT_IS_LOW,
    .deadTimeClocksBuff = 0,
    .deadTimeClocksBuff_linecompl_out = 0,
    .buffer_swap_enable = false,
    .glitch_filter_enable = false,
    .gf_depth = CY_GLITCH_FILTER_DEPTH_SUPPORT_VALUE_0,
    .dithering_mode = CY_TCPWM_DITHERING_DISABLE,
    .period_dithering_value = 128,
    .duty_dithering_value = 128,
    .limiter = CY_TCPWM_DITHERING_LIMITER_7,
    .pwm_tc_sync_kill_dt = false,
    .pwm_sync_kill_dt = false,
    .debug_freeze_enable = true,
    .debug_suspend_enable = true,
#endif /* defined (CY_IP_MXS40TCPWM) */
};

#if defined (COMPONENT_MTB_HAL)
const mtb_hal_peri_div_t PWM_B_W_clock_ref =
{
    .clk_dst = (en_clk_dst_t)PCLK_TCPWM0_CLOCK_COUNTER_EN261,
    .div_type = CY_SYSCLK_DIV_8_BIT,
    .div_num = 0,
};
const mtb_hal_clock_t PWM_B_W_hal_clock =
{
    .clock_ref = &PWM_B_W_clock_ref,
    .interface = &mtb_hal_clock_peri_interface,
};
#endif /* defined (COMPONENT_MTB_HAL) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM)
const mtb_hal_pwm_configurator_t PWM_B_W_hal_config =
{
    .base = PWM_B_W_HW,
    .clock = &PWM_B_W_hal_clock,
    .group = 1UL,
    .cntnum = 261UL,
    .max_count = 5999,
};
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM) */

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
const cyhal_resource_inst_t PWM_B_W_obj =
{
    .type = CYHAL_RSC_TCPWM,
    .block_num = 1U,
    .channel_num = 5U,
};
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

#if defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL)
const cyhal_clock_t PWM_B_W_clock =
{
    .block = CYHAL_CLOCK_BLOCK_PERIPHERAL5_8BIT,
    .channel = 0,
#if defined (CY_USING_HAL)
    .reserved = false,
    .funcs = NULL,
#endif /* defined (CY_USING_HAL) */
};
#endif /* defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL) */

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
const cyhal_pwm_configurator_t PWM_B_W_hal_config =
{
    .resource = &PWM_B_W_obj,
    .config = &PWM_B_W_config,
    .clock = &PWM_B_W_clock,
};
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

const cy_stc_tcpwm_pwm_config_t PWM_START_A_config =
{
    .pwmMode = CY_TCPWM_PWM_MODE_PWM,
    .clockPrescaler = CY_TCPWM_PWM_PRESCALER_DIVBY_1,
    .pwmAlignment = CY_TCPWM_PWM_LEFT_ALIGN,
    .deadTimeClocks = 0,
    .runMode = CY_TCPWM_PWM_CONTINUOUS,
    .period0 = 20,
    .period1 = 32768,
    .enablePeriodSwap = false,
    .compare0 = 10,
    .compare1 = 16384,
    .enableCompareSwap = false,
    .interruptSources = (CY_TCPWM_INT_ON_TC & 0U) | (CY_TCPWM_INT_ON_CC0 ) | (CY_TCPWM_INT_ON_CC1 & 0U),
    .invertPWMOut = CY_TCPWM_PWM_INVERT_DISABLE,
    .invertPWMOutN = CY_TCPWM_PWM_INVERT_DISABLE,
    .killMode = CY_TCPWM_PWM_STOP_ON_KILL,
    .swapInputMode = PWM_START_A_INPUT_DISABLED & 0x3U,
    .swapInput = CY_TCPWM_INPUT_0,
    .reloadInputMode = PWM_START_A_INPUT_DISABLED & 0x3U,
    .reloadInput = CY_TCPWM_INPUT_0,
    .startInputMode = PWM_START_A_INPUT_DISABLED & 0x3U,
    .startInput = CY_TCPWM_INPUT_0,
    .killInputMode = PWM_START_A_INPUT_DISABLED & 0x3U,
    .killInput = CY_TCPWM_INPUT_0,
    .countInputMode = PWM_START_A_INPUT_DISABLED & 0x3U,
    .countInput = CY_TCPWM_INPUT_1,
    .swapOverflowUnderflow = false,
    .immediateKill = false,
    .tapsEnabled = 45,
    .compare2 = 10,
    .compare3 = 16384,
    .enableCompare1Swap = false,
    .compare0MatchUp = true,
    .compare0MatchDown = false,
    .compare1MatchUp = true,
    .compare1MatchDown = false,
    .kill1InputMode = PWM_START_A_INPUT_DISABLED & 0x3U,
    .kill1Input = CY_TCPWM_INPUT_0,
    .pwmOnDisable = CY_TCPWM_PWM_OUTPUT_HIGHZ,
    .trigger0Event = CY_TCPWM_CNT_TRIGGER_ON_CC0_MATCH,
    .trigger1Event = CY_TCPWM_CNT_TRIGGER_ON_DISABLED,
    .reloadLineSelect = false,
    .line_out_sel = CY_TCPWM_OUTPUT_PWM_SIGNAL,
    .linecompl_out_sel = CY_TCPWM_OUTPUT_INVERTED_PWM_SIGNAL,
    .line_out_sel_buff = CY_TCPWM_OUTPUT_PWM_SIGNAL,
    .linecompl_out_sel_buff = CY_TCPWM_OUTPUT_INVERTED_PWM_SIGNAL,
    .deadTimeClocks_linecompl_out = 0,
#if defined (CY_IP_MXS40TCPWM)
    .hrpwm_enable = false,
    .hrpwm_input_freq = CY_TCPWM_HRPWM_FREQ_80MHZ_OR_100MHZ,
    .kill_line_polarity = CY_TCPWM_LINEOUT_AND_LINECMPOUT_IS_LOW,
    .deadTimeClocksBuff = 0,
    .deadTimeClocksBuff_linecompl_out = 0,
    .buffer_swap_enable = false,
    .glitch_filter_enable = false,
    .gf_depth = CY_GLITCH_FILTER_DEPTH_SUPPORT_VALUE_0,
    .dithering_mode = CY_TCPWM_DITHERING_DISABLE,
    .period_dithering_value = 128,
    .duty_dithering_value = 128,
    .limiter = CY_TCPWM_DITHERING_LIMITER_7,
    .pwm_tc_sync_kill_dt = false,
    .pwm_sync_kill_dt = false,
    .debug_freeze_enable = false,
    .debug_suspend_enable = false,
#endif /* defined (CY_IP_MXS40TCPWM) */
};

#if defined (COMPONENT_MTB_HAL)
const mtb_hal_peri_div_t PWM_START_A_clock_ref =
{
    .clk_dst = (en_clk_dst_t)PCLK_TCPWM0_CLOCK_COUNTER_EN262,
    .div_type = CY_SYSCLK_DIV_8_BIT,
    .div_num = 0,
};
const mtb_hal_clock_t PWM_START_A_hal_clock =
{
    .clock_ref = &PWM_START_A_clock_ref,
    .interface = &mtb_hal_clock_peri_interface,
};
#endif /* defined (COMPONENT_MTB_HAL) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM)
const mtb_hal_pwm_configurator_t PWM_START_A_hal_config =
{
    .base = PWM_START_A_HW,
    .clock = &PWM_START_A_hal_clock,
    .group = 1UL,
    .cntnum = 262UL,
    .max_count = 20,
};
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM) */

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
const cyhal_resource_inst_t PWM_START_A_obj =
{
    .type = CYHAL_RSC_TCPWM,
    .block_num = 1U,
    .channel_num = 6U,
};
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

#if defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL)
const cyhal_clock_t PWM_START_A_clock =
{
    .block = CYHAL_CLOCK_BLOCK_PERIPHERAL5_8BIT,
    .channel = 0,
#if defined (CY_USING_HAL)
    .reserved = false,
    .funcs = NULL,
#endif /* defined (CY_USING_HAL) */
};
#endif /* defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL) */

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
const cyhal_pwm_configurator_t PWM_START_A_hal_config =
{
    .resource = &PWM_START_A_obj,
    .config = &PWM_START_A_config,
    .clock = &PWM_START_A_clock,
};
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

const cy_stc_tcpwm_pwm_config_t PWM_START_B_config =
{
    .pwmMode = CY_TCPWM_PWM_MODE_PWM,
    .clockPrescaler = CY_TCPWM_PWM_PRESCALER_DIVBY_1,
    .pwmAlignment = CY_TCPWM_PWM_LEFT_ALIGN,
    .deadTimeClocks = 0,
    .runMode = CY_TCPWM_PWM_CONTINUOUS,
    .period0 = 20,
    .period1 = 32768,
    .enablePeriodSwap = false,
    .compare0 = 10,
    .compare1 = 16384,
    .enableCompareSwap = false,
    .interruptSources = (CY_TCPWM_INT_ON_TC & 0U) | (CY_TCPWM_INT_ON_CC0 ) | (CY_TCPWM_INT_ON_CC1 & 0U),
    .invertPWMOut = CY_TCPWM_PWM_INVERT_DISABLE,
    .invertPWMOutN = CY_TCPWM_PWM_INVERT_DISABLE,
    .killMode = CY_TCPWM_PWM_STOP_ON_KILL,
    .swapInputMode = PWM_START_B_INPUT_DISABLED & 0x3U,
    .swapInput = CY_TCPWM_INPUT_0,
    .reloadInputMode = PWM_START_B_INPUT_DISABLED & 0x3U,
    .reloadInput = CY_TCPWM_INPUT_0,
    .startInputMode = PWM_START_B_INPUT_DISABLED & 0x3U,
    .startInput = CY_TCPWM_INPUT_0,
    .killInputMode = PWM_START_B_INPUT_DISABLED & 0x3U,
    .killInput = CY_TCPWM_INPUT_0,
    .countInputMode = PWM_START_B_INPUT_DISABLED & 0x3U,
    .countInput = CY_TCPWM_INPUT_1,
    .swapOverflowUnderflow = false,
    .immediateKill = false,
    .tapsEnabled = 45,
    .compare2 = 10,
    .compare3 = 16384,
    .enableCompare1Swap = false,
    .compare0MatchUp = true,
    .compare0MatchDown = false,
    .compare1MatchUp = true,
    .compare1MatchDown = false,
    .kill1InputMode = PWM_START_B_INPUT_DISABLED & 0x3U,
    .kill1Input = CY_TCPWM_INPUT_0,
    .pwmOnDisable = CY_TCPWM_PWM_OUTPUT_HIGHZ,
    .trigger0Event = CY_TCPWM_CNT_TRIGGER_ON_CC0_MATCH,
    .trigger1Event = CY_TCPWM_CNT_TRIGGER_ON_DISABLED,
    .reloadLineSelect = false,
    .line_out_sel = CY_TCPWM_OUTPUT_PWM_SIGNAL,
    .linecompl_out_sel = CY_TCPWM_OUTPUT_INVERTED_PWM_SIGNAL,
    .line_out_sel_buff = CY_TCPWM_OUTPUT_PWM_SIGNAL,
    .linecompl_out_sel_buff = CY_TCPWM_OUTPUT_INVERTED_PWM_SIGNAL,
    .deadTimeClocks_linecompl_out = 0,
#if defined (CY_IP_MXS40TCPWM)
    .hrpwm_enable = false,
    .hrpwm_input_freq = CY_TCPWM_HRPWM_FREQ_80MHZ_OR_100MHZ,
    .kill_line_polarity = CY_TCPWM_LINEOUT_AND_LINECMPOUT_IS_LOW,
    .deadTimeClocksBuff = 0,
    .deadTimeClocksBuff_linecompl_out = 0,
    .buffer_swap_enable = false,
    .glitch_filter_enable = false,
    .gf_depth = CY_GLITCH_FILTER_DEPTH_SUPPORT_VALUE_0,
    .dithering_mode = CY_TCPWM_DITHERING_DISABLE,
    .period_dithering_value = 128,
    .duty_dithering_value = 128,
    .limiter = CY_TCPWM_DITHERING_LIMITER_7,
    .pwm_tc_sync_kill_dt = false,
    .pwm_sync_kill_dt = false,
    .debug_freeze_enable = false,
    .debug_suspend_enable = false,
#endif /* defined (CY_IP_MXS40TCPWM) */
};

#if defined (COMPONENT_MTB_HAL)
const mtb_hal_peri_div_t PWM_START_B_clock_ref =
{
    .clk_dst = (en_clk_dst_t)PCLK_TCPWM0_CLOCK_COUNTER_EN263,
    .div_type = CY_SYSCLK_DIV_8_BIT,
    .div_num = 0,
};
const mtb_hal_clock_t PWM_START_B_hal_clock =
{
    .clock_ref = &PWM_START_B_clock_ref,
    .interface = &mtb_hal_clock_peri_interface,
};
#endif /* defined (COMPONENT_MTB_HAL) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM)
const mtb_hal_pwm_configurator_t PWM_START_B_hal_config =
{
    .base = PWM_START_B_HW,
    .clock = &PWM_START_B_hal_clock,
    .group = 1UL,
    .cntnum = 263UL,
    .max_count = 20,
};
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM) */

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
const cyhal_resource_inst_t PWM_START_B_obj =
{
    .type = CYHAL_RSC_TCPWM,
    .block_num = 1U,
    .channel_num = 7U,
};
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

#if defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL)
const cyhal_clock_t PWM_START_B_clock =
{
    .block = CYHAL_CLOCK_BLOCK_PERIPHERAL5_8BIT,
    .channel = 0,
#if defined (CY_USING_HAL)
    .reserved = false,
    .funcs = NULL,
#endif /* defined (CY_USING_HAL) */
};
#endif /* defined(CY_USING_HAL_LITE) || defined (CY_USING_HAL) */

#if defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE)
const cyhal_pwm_configurator_t PWM_START_B_hal_config =
{
    .resource = &PWM_START_B_obj,
    .config = &PWM_START_B_config,
    .clock = &PWM_START_B_clock,
};
#endif /* defined (CY_USING_HAL) || defined(CY_USING_HAL_LITE) */

__WEAK void __NO_RETURN pass_0_error(cy_rslt_t error);

#if defined(CORE_NAME_CM33_0) && defined(CY_IP_MXS40SSRSS)
__STATIC_INLINE void Cy_Debug_TrcCtiCpuHaltConnect(void);
#endif /* defined(CORE_NAME_CM33_0) && defined(CY_IP_MXS40SSRSS) */

__WEAK void __NO_RETURN pass_0_error(cy_rslt_t error)
{
    (void)error; /* Suppress the compiler warning */
    while(true);
}
void pass_0_start(void)
{
    if (!Cy_HPPASS_AC_IsBlockReady())
    {
        cy_rslt_t hppassStatus = (cy_rslt_t)Cy_HPPASS_AC_Start(0U, 1000U);
        if (CY_RSLT_SUCCESS != hppassStatus)
        {
            pass_0_error(hppassStatus);
        }
    }
}

#if defined(CORE_NAME_CM33_0) && defined(CY_IP_MXS40SSRSS)
__STATIC_INLINE void Cy_Debug_TrcCtiCpuHaltConnect(void)
{
    if (Cy_SysLib_DebugSessionActive(SRSS))
    {
       #ifdef CYCFG_TRC_CTI_OUT_CTI_TR_OUT0
          Cy_SysLib_DebugCtiMuxConnect(CM33_TRC_CTI, CYCFG_TRC_CTI_IN_MAIN_CORE_HALT, CYCFG_TRC_CTI_OUT_CTI_TR_OUT0, 0u, 1u);
       #endif /* CYCFG_TRC_CTI_OUT_CTI_TR_OUT0 */
       #ifdef CYCFG_TRC_CTI_OUT_CTI_TR_OUT1
          Cy_SysLib_DebugCtiMuxConnect(CM33_TRC_CTI, CYCFG_TRC_CTI_IN_MAIN_CORE_HALT, CYCFG_TRC_CTI_OUT_CTI_TR_OUT1, 0u, 1u);
       #endif /* CYCFG_TRC_CTI_OUT_CTI_TR_OUT1 */
    }
}
#endif /* defined(CORE_NAME_CM33_0) && defined(CY_IP_MXS40SSRSS) */

void init_cycfg_peripherals(void)
{
    cy_rslt_t hppassStatus = 0UL;
    hppassStatus = Cy_HPPASS_Init(&pass_0_config);
    if (CY_RSLT_SUCCESS != hppassStatus)
    {
        pass_0_error(hppassStatus);
    }
    Cy_HPPASS_SAR_CrossTalkAdjust((uint8_t)1U << 0U);
    Cy_HPPASS_SAR_CrossTalkAdjust((uint8_t)1U << 1U);
    Cy_HPPASS_SAR_CrossTalkAdjust((uint8_t)1U << 2U);
#if defined(CORE_NAME_CM33_0) && defined(CY_IP_MXS40SSRSS)
    Cy_Debug_TrcCtiCpuHaltConnect();
#endif /* defined(CORE_NAME_CM33_0) && defined(CY_IP_MXS40SSRSS) */
    Cy_SysClk_PeriPclkAssignDivider(PCLK_SCB0_CLOCK_SCB_EN, CY_SYSCLK_DIV_16_5_BIT, 0U);
    Cy_SysClk_PeriPclkAssignDivider(PCLK_SCB1_CLOCK_SCB_EN, CY_SYSCLK_DIV_16_5_BIT, 2U);
    Cy_SysClk_PeriPclkAssignDivider(PCLK_SCB2_CLOCK_SCB_EN, CY_SYSCLK_DIV_16_5_BIT, 1U);
    Cy_SysClk_PeriPclkAssignDivider(PCLK_SCB3_CLOCK_SCB_EN, CY_SYSCLK_DIV_16_5_BIT, 2U);
    Cy_SysClk_PeriPclkAssignDivider(PCLK_SCB5_CLOCK_SCB_EN, CY_SYSCLK_DIV_16_5_BIT, 0U);
#if defined (CY_DEVICE_CONFIGURATOR_IP_ENABLE_FEATURE)
    Cy_SysClk_PeriGroupSlaveInit(CY_MMIO_TCPWM0_PERI_NR, CY_MMIO_TCPWM0_GROUP_NR, CY_MMIO_TCPWM0_SLAVE_NR, CY_MMIO_TCPWM0_CLK_HF_NR);
#endif /* defined (CY_DEVICE_CONFIGURATOR_IP_ENABLE_FEATURE) */
    Cy_SysClk_PeriphAssignDivider(PCLK_TCPWM0_CLOCK_COUNTER_EN0, CY_SYSCLK_DIV_8_BIT, 0U);
#if defined (CY_DEVICE_CONFIGURATOR_IP_ENABLE_FEATURE)
    Cy_SysClk_PeriGroupSlaveInit(CY_MMIO_TCPWM0_PERI_NR, CY_MMIO_TCPWM0_GROUP_NR, CY_MMIO_TCPWM0_SLAVE_NR, CY_MMIO_TCPWM0_CLK_HF_NR);
#endif /* defined (CY_DEVICE_CONFIGURATOR_IP_ENABLE_FEATURE) */
    Cy_SysClk_PeriphAssignDivider(PCLK_TCPWM0_CLOCK_COUNTER_EN1, CY_SYSCLK_DIV_8_BIT, 0U);
#if defined (CY_IP_MXS40TCPWM) && defined (CY_DEVICE_PSC3)
    /* Workaround for TCPWM on PSOC C3 device: Enable HRPWM block if it exists. */
    (*((volatile uint32_t *)(GET_ALIAS_ADDRESS(CY_SYSTEM_TCPWM_DISABLE_ADDR))) = 0UL);
#endif /* defined (CY_IP_MXS40TCPWM) && defined (CY_DEVICE_PSC3) */
#if defined (CY_DEVICE_CONFIGURATOR_IP_ENABLE_FEATURE)
    Cy_SysClk_PeriGroupSlaveInit(CY_MMIO_TCPWM0_PERI_NR, CY_MMIO_TCPWM0_GROUP_NR, CY_MMIO_TCPWM0_SLAVE_NR, CY_MMIO_TCPWM0_CLK_HF_NR);
#endif /* defined (CY_DEVICE_CONFIGURATOR_IP_ENABLE_FEATURE) */
    Cy_SysClk_PeriphAssignDivider(PCLK_TCPWM0_CLOCK_COUNTER_EN2, CY_SYSCLK_DIV_8_BIT, 0U);
#if defined (CY_IP_MXS40TCPWM) && defined (CY_DEVICE_PSC3)
    /* Workaround for TCPWM on PSOC C3 device: Enable HRPWM block if it exists. */
    (*((volatile uint32_t *)(GET_ALIAS_ADDRESS(CY_SYSTEM_TCPWM_DISABLE_ADDR))) = 0UL);
#endif /* defined (CY_IP_MXS40TCPWM) && defined (CY_DEVICE_PSC3) */
#if defined (CY_DEVICE_CONFIGURATOR_IP_ENABLE_FEATURE)
    Cy_SysClk_PeriGroupSlaveInit(CY_MMIO_TCPWM0_PERI_NR, CY_MMIO_TCPWM0_GROUP_NR, CY_MMIO_TCPWM0_SLAVE_NR, CY_MMIO_TCPWM0_CLK_HF_NR);
#endif /* defined (CY_DEVICE_CONFIGURATOR_IP_ENABLE_FEATURE) */
    Cy_SysClk_PeriphAssignDivider(PCLK_TCPWM0_CLOCK_COUNTER_EN3, CY_SYSCLK_DIV_8_BIT, 0U);
#if defined (CY_IP_MXS40TCPWM) && defined (CY_DEVICE_PSC3)
    /* Workaround for TCPWM on PSOC C3 device: Enable HRPWM block if it exists. */
    (*((volatile uint32_t *)(GET_ALIAS_ADDRESS(CY_SYSTEM_TCPWM_DISABLE_ADDR))) = 0UL);
#endif /* defined (CY_IP_MXS40TCPWM) && defined (CY_DEVICE_PSC3) */
#if defined (CY_DEVICE_CONFIGURATOR_IP_ENABLE_FEATURE)
    Cy_SysClk_PeriGroupSlaveInit(CY_MMIO_TCPWM0_PERI_NR, CY_MMIO_TCPWM0_GROUP_NR, CY_MMIO_TCPWM0_SLAVE_NR, CY_MMIO_TCPWM0_CLK_HF_NR);
#endif /* defined (CY_DEVICE_CONFIGURATOR_IP_ENABLE_FEATURE) */
    Cy_SysClk_PeriphAssignDivider(PCLK_TCPWM0_CLOCK_COUNTER_EN256, CY_SYSCLK_DIV_8_BIT, 0U);
#if defined (CY_DEVICE_CONFIGURATOR_IP_ENABLE_FEATURE)
    Cy_SysClk_PeriGroupSlaveInit(CY_MMIO_TCPWM0_PERI_NR, CY_MMIO_TCPWM0_GROUP_NR, CY_MMIO_TCPWM0_SLAVE_NR, CY_MMIO_TCPWM0_CLK_HF_NR);
#endif /* defined (CY_DEVICE_CONFIGURATOR_IP_ENABLE_FEATURE) */
    Cy_SysClk_PeriphAssignDivider(PCLK_TCPWM0_CLOCK_COUNTER_EN257, CY_SYSCLK_DIV_8_BIT, 0U);
#if defined (CY_DEVICE_CONFIGURATOR_IP_ENABLE_FEATURE)
    Cy_SysClk_PeriGroupSlaveInit(CY_MMIO_TCPWM0_PERI_NR, CY_MMIO_TCPWM0_GROUP_NR, CY_MMIO_TCPWM0_SLAVE_NR, CY_MMIO_TCPWM0_CLK_HF_NR);
#endif /* defined (CY_DEVICE_CONFIGURATOR_IP_ENABLE_FEATURE) */
    Cy_SysClk_PeriphAssignDivider(PCLK_TCPWM0_CLOCK_COUNTER_EN258, CY_SYSCLK_DIV_8_BIT, 0U);
#if defined (CY_DEVICE_CONFIGURATOR_IP_ENABLE_FEATURE)
    Cy_SysClk_PeriGroupSlaveInit(CY_MMIO_TCPWM0_PERI_NR, CY_MMIO_TCPWM0_GROUP_NR, CY_MMIO_TCPWM0_SLAVE_NR, CY_MMIO_TCPWM0_CLK_HF_NR);
#endif /* defined (CY_DEVICE_CONFIGURATOR_IP_ENABLE_FEATURE) */
    Cy_SysClk_PeriphAssignDivider(PCLK_TCPWM0_CLOCK_COUNTER_EN259, CY_SYSCLK_DIV_8_BIT, 0U);
#if defined (CY_DEVICE_CONFIGURATOR_IP_ENABLE_FEATURE)
    Cy_SysClk_PeriGroupSlaveInit(CY_MMIO_TCPWM0_PERI_NR, CY_MMIO_TCPWM0_GROUP_NR, CY_MMIO_TCPWM0_SLAVE_NR, CY_MMIO_TCPWM0_CLK_HF_NR);
#endif /* defined (CY_DEVICE_CONFIGURATOR_IP_ENABLE_FEATURE) */
    Cy_SysClk_PeriphAssignDivider(PCLK_TCPWM0_CLOCK_COUNTER_EN260, CY_SYSCLK_DIV_8_BIT, 0U);
#if defined (CY_DEVICE_CONFIGURATOR_IP_ENABLE_FEATURE)
    Cy_SysClk_PeriGroupSlaveInit(CY_MMIO_TCPWM0_PERI_NR, CY_MMIO_TCPWM0_GROUP_NR, CY_MMIO_TCPWM0_SLAVE_NR, CY_MMIO_TCPWM0_CLK_HF_NR);
#endif /* defined (CY_DEVICE_CONFIGURATOR_IP_ENABLE_FEATURE) */
    Cy_SysClk_PeriphAssignDivider(PCLK_TCPWM0_CLOCK_COUNTER_EN261, CY_SYSCLK_DIV_8_BIT, 0U);
#if defined (CY_DEVICE_CONFIGURATOR_IP_ENABLE_FEATURE)
    Cy_SysClk_PeriGroupSlaveInit(CY_MMIO_TCPWM0_PERI_NR, CY_MMIO_TCPWM0_GROUP_NR, CY_MMIO_TCPWM0_SLAVE_NR, CY_MMIO_TCPWM0_CLK_HF_NR);
#endif /* defined (CY_DEVICE_CONFIGURATOR_IP_ENABLE_FEATURE) */
    Cy_SysClk_PeriphAssignDivider(PCLK_TCPWM0_CLOCK_COUNTER_EN262, CY_SYSCLK_DIV_8_BIT, 0U);
#if defined (CY_DEVICE_CONFIGURATOR_IP_ENABLE_FEATURE)
    Cy_SysClk_PeriGroupSlaveInit(CY_MMIO_TCPWM0_PERI_NR, CY_MMIO_TCPWM0_GROUP_NR, CY_MMIO_TCPWM0_SLAVE_NR, CY_MMIO_TCPWM0_CLK_HF_NR);
#endif /* defined (CY_DEVICE_CONFIGURATOR_IP_ENABLE_FEATURE) */
    Cy_SysClk_PeriphAssignDivider(PCLK_TCPWM0_CLOCK_COUNTER_EN263, CY_SYSCLK_DIV_8_BIT, 0U);
}
void reserve_cycfg_peripherals(void)
{
#if defined (CY_USING_HAL)
    cyhal_hwmgr_reserve(&SPI_GD_CFG_obj);
    cyhal_hwmgr_reserve(&SPI_EC_B_obj);
    cyhal_hwmgr_reserve(&SPI_LED_obj);
    cyhal_hwmgr_reserve(&SPI_EC_A_obj);
    cyhal_hwmgr_reserve(&SPI_CTR_obj);
    cyhal_hwmgr_reserve(&TIMER_TASK_obj);
    cyhal_hwmgr_reserve(&PWM_C_U_obj);
    cyhal_hwmgr_reserve(&PWM_C_V_obj);
    cyhal_hwmgr_reserve(&PWM_START_C_obj);
    cyhal_hwmgr_reserve(&PWM_A_U_obj);
    cyhal_hwmgr_reserve(&PWM_A_V_obj);
    cyhal_hwmgr_reserve(&PWM_A_W_obj);
    cyhal_hwmgr_reserve(&PWM_B_U_obj);
    cyhal_hwmgr_reserve(&PWM_B_V_obj);
    cyhal_hwmgr_reserve(&PWM_B_W_obj);
    cyhal_hwmgr_reserve(&PWM_START_A_obj);
    cyhal_hwmgr_reserve(&PWM_START_B_obj);
#endif /* defined (CY_USING_HAL) */
}
