#include "cybsp.h"
#include "bsp_init.hpp"

uint32_t colar_test = 15;
void spi_ctl_test()
{
    bsp_init();//hardware init
    spi_ctr_decode.register_map(0x01u,colar_test,true, true);
    while (1)
    {
        ws2812.set_color(colar_test & 0xFF, (colar_test >> 8) & 0xFF, (colar_test >> 16) & 0xFF);
        CyDelay(100);
    }
}