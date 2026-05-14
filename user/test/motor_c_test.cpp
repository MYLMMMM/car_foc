#include "cybsp.h"
#include "bsp_init.hpp"

void motor_c_test()
{
    bsp_init(); // 硬件初始化

    motor_c_driver.start();

    while (1)
    {
        ws2812.set_color(0, 5, 0);
        CyDelay(5);
    }
}
