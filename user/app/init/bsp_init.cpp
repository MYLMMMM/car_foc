#include "bsp_init_obj.hpp"
#include "cybsp.h"
#include "SEGGER_RTT.h"
#include "valuemap.hpp"

#define __DEBUG_RTT

void motor_a_init();
void motor_b_init();
void motor_c_init();
void ctl_init();
void WS2812_init();
void motor_a_foc_isr();
void motor_b_foc_isr();
void motor_a_ec_isr();
void motor_b_ec_isr();
void motor_a_pwm_isr();
void spi_ctr_isr();
void timer_task_isr();
void task_ctl();
//GPIO global interrupt
void GPIO_6_ISR()
{
    drv8304_a.handle_nfault_irq();
}
void GPIO_4_ISR()
{
    drv8304_b.handle_nfault_irq();
}


//main init
void bsp_init()
{
    SEGGER_RTT_Init();
    WS2812_init();
    motor_a_init();
    motor_b_init();
    motor_c_init();

    Cy_HPPASS_AC_Start(0U,0U);
    Cy_SysInt_Init(&int_adc_motor_a_config,motor_a_foc_isr);
    NVIC_ClearPendingIRQ(int_adc_motor_a_config.intrSrc);
    NVIC_EnableIRQ(int_adc_motor_a_config.intrSrc);
    Cy_SysInt_Init(&int_adc_motor_b_config,motor_b_foc_isr);
    NVIC_ClearPendingIRQ(int_adc_motor_b_config.intrSrc);
    NVIC_EnableIRQ(int_adc_motor_b_config.intrSrc);

    
    ctl_init();
}

void motor_a_init()
{
    /*----------------- init drv8304 -----------------------*/
        //spi
    cy_en_scb_spi_status_t spi_status = Cy_SCB_SPI_Init(SPI_GD_CFG_HW,&SPI_GD_CFG_config,NULL);

#ifdef __DEBUG_RTT
    if(spi_status != CY_SCB_SPI_SUCCESS)
    {
        SEGGER_RTT_printf(0,"motor_a_spi_drv8304 init fail");
    }
#endif

    Cy_SCB_SPI_Enable(SPI_GD_CFG_HW);

        // gpio regist isr
    Cy_SysInt_Init(&gpio_iqr_config,GPIO_6_ISR);
    NVIC_EnableIRQ(GPIO_GD_A_nFAULT_IRQ);   

        //init and rigist callback
    bool drv8304_init_states = drv8304_a.init();

#ifdef __DEBUG_RTT
    if(drv8304_init_states == false)
    {
        SEGGER_RTT_printf(0,"drv8304_a init fail");
    }
#endif

    Cy_GPIO_Set(GPIO_GD_A_PULLUP_PORT,GPIO_GD_A_PULLUP_PORT_NUM);

    drv8304_a.register_nfault_callback(drv8304_a_nfault_callback,nullptr);
    drv8304_a.set_enable(true);
    CyDelay(20);
    drv8304_a.set_csa_gain(3);
    // drv8304_a.set_ocp_mode(3);
    drv8304_a.set_dis_gdf(1);
    // drv8304_a.set_lock(3);
    // drv8304_a.set_pwm_mode(0);
    // drv8304_a.set_vref_div(0);
    drv8304_a.trigger_spi_update();

    /*------------------------ init kth7823 ----------------------*/ 
        //init spi
    spi_status = Cy_SCB_SPI_Init(SPI_EC_A_HW,&SPI_EC_A_config,NULL); 
#ifdef __DEBUG_RTT
    if(spi_status != CY_SCB_SPI_SUCCESS)
    {
        SEGGER_RTT_printf(0,"motor_a_spi_ec init fail");
    }
#endif
    Cy_SCB_SPI_Enable(SPI_EC_A_HW);
    cy_stc_sysint_t int_spi_ec_a_config =
    {
        .intrSrc = SPI_EC_A_IRQ,
        .intrPriority = 0x02
    };
    Cy_SysInt_Init(&int_spi_ec_a_config, motor_a_ec_isr);
    NVIC_ClearPendingIRQ(int_spi_ec_a_config.intrSrc);
    NVIC_EnableIRQ(int_spi_ec_a_config.intrSrc);
    
    enc_a.set_direction(true);

        //init DMA
    cy_en_dma_status_t dma_init_status;
     /* Initialize descriptor */
    dma_init_status = Cy_DMA_Descriptor_Init(&DMA_EC_A_RX_Descriptor_0, &DMA_EC_A_RX_Descriptor_0_config);
#ifdef __DEBUG_RTT
    if (dma_init_status!=CY_DMA_SUCCESS)
    {
        SEGGER_RTT_printf(0,"dma_descriptor_ec_a init fail");
    }
#endif

    dma_init_status = Cy_DMA_Channel_Init(DMA_EC_A_RX_HW, DMA_EC_A_RX_CHANNEL, &DMA_EC_A_RX_channelConfig);
#ifdef __DEBUG_RTT
    if (dma_init_status!=CY_DMA_SUCCESS)
    {
        SEGGER_RTT_printf(0,"dma_channel_ec_a init fail");
    }
#endif

    Cy_DMA_Descriptor_SetSrcAddress(&DMA_EC_A_RX_Descriptor_0, (void *)&SPI_EC_A_HW->RX_FIFO_RD);
    Cy_DMA_Descriptor_SetDstAddress(&DMA_EC_A_RX_Descriptor_0, (uint16_t *)&foc_motor_datastructure_A.enc_a);

    Cy_DMA_Channel_SetDescriptor(DMA_EC_A_RX_HW, DMA_EC_A_RX_CHANNEL, &DMA_EC_A_RX_Descriptor_0);
    Cy_DMA_Channel_SetPriority(DMA_EC_A_RX_HW, DMA_EC_A_RX_CHANNEL, 3UL);
    Cy_DMA_Channel_Enable(DMA_EC_A_RX_HW, DMA_EC_A_RX_CHANNEL);
    Cy_DMA_Enable(DMA_EC_A_RX_HW); 

    //init tcpwm
    cy_en_tcpwm_status_t tcpwm_status;

    tcpwm_status = Cy_TCPWM_PWM_Init(PWM_START_A_HW, PWM_START_A_NUM, &PWM_START_A_config);
#ifdef __DEBUG_RTT
    if (tcpwm_status != CY_TCPWM_SUCCESS)
    {
        SEGGER_RTT_printf(0, "motor_a_pwm_start init fail\r\n");
    }
#endif

    tcpwm_status = Cy_TCPWM_PWM_Init(PWM_A_U_HW, PWM_A_U_NUM, &PWM_A_U_config);
#ifdef __DEBUG_RTT
    if (tcpwm_status != CY_TCPWM_SUCCESS)
    {
        SEGGER_RTT_printf(0, "motor_a_pwm_u init fail\r\n");
    }
#endif

    tcpwm_status = Cy_TCPWM_PWM_Init(PWM_A_V_HW, PWM_A_V_NUM, &PWM_A_V_config);
#ifdef __DEBUG_RTT
    if (tcpwm_status != CY_TCPWM_SUCCESS)
    {
        SEGGER_RTT_printf(0, "motor_a_pwm_v init fail\r\n");
    }
#endif

    tcpwm_status = Cy_TCPWM_PWM_Init(PWM_A_W_HW, PWM_A_W_NUM, &PWM_A_W_config);
#ifdef __DEBUG_RTT
    if (tcpwm_status != CY_TCPWM_SUCCESS)
    {
        SEGGER_RTT_printf(0, "motor_a_pwm_w init fail\r\n");
    }
#endif

    Cy_TCPWM_PWM_Enable(PWM_A_U_HW, PWM_A_U_NUM);
    Cy_TCPWM_PWM_Enable(PWM_A_V_HW, PWM_A_V_NUM);
    Cy_TCPWM_PWM_Enable(PWM_A_W_HW, PWM_A_W_NUM);
    Cy_TCPWM_PWM_Enable(PWM_START_A_HW, PWM_START_A_NUM);

    //如果将pwm更新单独放在pwmisr中时，取消注释掉这一段
    //并且将adc中断里面的pwmcc更新注释掉
    // Cy_SysInt_Init(&motor_a_pwm_iqr_config,motor_a_pwm_isr);
    // NVIC_ClearPendingIRQ(motor_a_pwm_iqr_config.intrSrc);
    // NVIC_EnableIRQ(motor_a_pwm_iqr_config.intrSrc);

}

void motor_b_init()
{
    /*----------------- init drv8304 -----------------------*/
    Cy_SysInt_Init(&gpio_b_iqr_config,GPIO_4_ISR);
    NVIC_EnableIRQ(GPIO_GD_B_nFAULT_IRQ);

    bool drv8304_init_states = drv8304_b.init();
#ifdef __DEBUG_RTT
    if(drv8304_init_states == false)
    {
        SEGGER_RTT_printf(0,"drv8304_b init fail");
    }
#endif

    drv8304_b.register_nfault_callback(drv8304_b_nfault_callback,nullptr);
    drv8304_b.set_enable(true);
    CyDelay(20);
    drv8304_b.set_csa_gain(3);
    drv8304_b.set_dis_gdf(1);
    drv8304_b.trigger_spi_update();

    /*------------------------ init kth7823 ----------------------*/
    cy_en_scb_spi_status_t spi_status = Cy_SCB_SPI_Init(SPI_EC_B_HW,&SPI_EC_B_config,NULL);
#ifdef __DEBUG_RTT
    if(spi_status != CY_SCB_SPI_SUCCESS)
    {
        SEGGER_RTT_printf(0,"motor_b_spi_ec init fail");
    }
#endif
    Cy_SCB_SPI_Enable(SPI_EC_B_HW);
    cy_stc_sysint_t int_spi_ec_b_config =
    {
        .intrSrc = SPI_EC_B_IRQ,
        .intrPriority = 0x02
    };
    Cy_SysInt_Init(&int_spi_ec_b_config, motor_b_ec_isr);
    NVIC_ClearPendingIRQ(int_spi_ec_b_config.intrSrc);
    NVIC_EnableIRQ(int_spi_ec_b_config.intrSrc);

    enc_b.set_direction(true);

    cy_en_dma_status_t dma_init_status;
    dma_init_status = Cy_DMA_Descriptor_Init(&DMA_EC_B_RX_Descriptor_0, &DMA_EC_B_RX_Descriptor_0_config);
#ifdef __DEBUG_RTT
    if (dma_init_status!=CY_DMA_SUCCESS)
    {
        SEGGER_RTT_printf(0,"dma_descriptor_ec_b init fail");
    }
#endif

    dma_init_status = Cy_DMA_Channel_Init(DMA_EC_B_RX_HW, DMA_EC_B_RX_CHANNEL, &DMA_EC_B_RX_channelConfig);
#ifdef __DEBUG_RTT
    if (dma_init_status!=CY_DMA_SUCCESS)
    {
        SEGGER_RTT_printf(0,"dma_channel_ec_b init fail");
    }
#endif

    Cy_DMA_Descriptor_SetSrcAddress(&DMA_EC_B_RX_Descriptor_0, (void *)&SPI_EC_B_HW->RX_FIFO_RD);
    Cy_DMA_Descriptor_SetDstAddress(&DMA_EC_B_RX_Descriptor_0, (uint16_t *)&foc_motor_datastructure_B.enc_a);

    Cy_DMA_Channel_SetDescriptor(DMA_EC_B_RX_HW, DMA_EC_B_RX_CHANNEL, &DMA_EC_B_RX_Descriptor_0);
    Cy_DMA_Channel_SetPriority(DMA_EC_B_RX_HW, DMA_EC_B_RX_CHANNEL, 3UL);
    Cy_DMA_Channel_Enable(DMA_EC_B_RX_HW, DMA_EC_B_RX_CHANNEL);
    Cy_DMA_Enable(DMA_EC_B_RX_HW);

    cy_en_tcpwm_status_t tcpwm_status;

    tcpwm_status = Cy_TCPWM_PWM_Init(PWM_START_B_HW, PWM_START_B_NUM, &PWM_START_B_config);
#ifdef __DEBUG_RTT
    if (tcpwm_status != CY_TCPWM_SUCCESS)
    {
        SEGGER_RTT_printf(0, "motor_b_pwm_start init fail\r\n");
    }
#endif

    tcpwm_status = Cy_TCPWM_PWM_Init(PWM_B_U_HW, PWM_B_U_NUM, &PWM_B_U_config);
#ifdef __DEBUG_RTT
    if (tcpwm_status != CY_TCPWM_SUCCESS)
    {
        SEGGER_RTT_printf(0, "motor_b_pwm_u init fail\r\n");
    }
#endif

    tcpwm_status = Cy_TCPWM_PWM_Init(PWM_B_V_HW, PWM_B_V_NUM, &PWM_B_V_config);
#ifdef __DEBUG_RTT
    if (tcpwm_status != CY_TCPWM_SUCCESS)
    {
        SEGGER_RTT_printf(0, "motor_b_pwm_v init fail\r\n");
    }
#endif

    tcpwm_status = Cy_TCPWM_PWM_Init(PWM_B_W_HW, PWM_B_W_NUM, &PWM_B_W_config);
#ifdef __DEBUG_RTT
    if (tcpwm_status != CY_TCPWM_SUCCESS)
    {
        SEGGER_RTT_printf(0, "motor_b_pwm_w init fail\r\n");
    }
#endif

    Cy_TCPWM_PWM_Enable(PWM_B_U_HW, PWM_B_U_NUM);
    Cy_TCPWM_PWM_Enable(PWM_B_V_HW, PWM_B_V_NUM);
    Cy_TCPWM_PWM_Enable(PWM_B_W_HW, PWM_B_W_NUM);
    Cy_TCPWM_PWM_Enable(PWM_START_B_HW, PWM_START_B_NUM);


}

void motor_c_init()
{
}

void ctl_init()
{
    cy_en_scb_spi_status_t spi_status = Cy_SCB_SPI_Init(SPI_CTR_HW,&SPI_CTR_config,NULL);
#ifdef __DEBUG_RTT
    if(spi_status != CY_SCB_SPI_SUCCESS)
    {
        SEGGER_RTT_printf(0,"ctl_spi_ctr init fail");
    }
#endif
    Cy_SCB_SPI_Enable(SPI_CTR_HW);

    Cy_SysInt_Init(&int_spi_ctl,spi_ctr_isr);
    NVIC_ClearPendingIRQ(int_spi_ctl.intrSrc);
    NVIC_EnableIRQ(int_spi_ctl.intrSrc);

    spi_ctr_decode.clear_maps();
    bool map_init_ok = valuemap_register(spi_ctr_decode);
#ifdef __DEBUG_RTT
    if(map_init_ok == false)
    {
        SEGGER_RTT_printf(0,"spi valuemap register fail");
    }
#endif

    /*----------------TIMER_TASK init----------------------*/
    cy_en_tcpwm_status_t timer_status = Cy_TCPWM_Counter_Init(TIMER_TASK_HW, TIMER_TASK_NUM, &TIMER_TASK_config);
#ifdef __DEBUG_RTT
    if(timer_status != CY_TCPWM_SUCCESS)
    {
        SEGGER_RTT_printf(0,"timer_task init fail");
    }
#endif

    Cy_SysInt_Init(&int_timer_task_config, timer_task_isr);
    NVIC_ClearPendingIRQ(int_timer_task_config.intrSrc);
    NVIC_EnableIRQ(int_timer_task_config.intrSrc);

    Cy_TCPWM_Counter_Enable(TIMER_TASK_HW, TIMER_TASK_NUM);
    Cy_TCPWM_TriggerStart_Single(TIMER_TASK_HW, TIMER_TASK_NUM);

}

void WS2812_init()
{
    cy_en_scb_spi_status_t spi_status = Cy_SCB_SPI_Init(SPI_LED_HW,&SPI_LED_config,NULL);
#ifdef __DEBUG_RTT
    if(spi_status != CY_SCB_SPI_SUCCESS)
    {
        SEGGER_RTT_printf(0,"WS2812_spi init fail");
    }
#endif
    Cy_SCB_SPI_Enable(SPI_LED_HW);
}

__WEAK void drv8304_a_nfault_callback(const drv8304::StateTable &statetable,void* userptr)
{

}
__WEAK void drv8304_b_nfault_callback(const drv8304::StateTable &statetable,void* userptr)
{

}

__WEAK void motor_a_foc_isr()
{
    motor_a_driver.foc_trig_isr();
}

__WEAK void motor_b_foc_isr()
{
    motor_b_driver.foc_trig_isr();
}

__WEAK void motor_a_ec_isr()
{
    motor_a_driver.ec_isr();
}
__WEAK void motor_b_ec_isr()
{
    motor_b_driver.ec_isr();
}

__WEAK void spi_ctr_isr()
{
    spi_ctr_decode.trig();
}

__WEAK void timer_task_isr()
{
    Cy_TCPWM_ClearInterrupt(TIMER_TASK_HW, TIMER_TASK_NUM, CY_TCPWM_INT_ON_TC);
    task_ctl();
}

__WEAK void motor_a_pwm_isr()
{
    motor_a_driver.pwm_chage_trig();
}

__WEAK void task_ctl()
{
}   