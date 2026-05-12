#include "cybsp.h"
#include "bsp_init.hpp"
static int msg = 0 ;

void encoder_test()
{
    bsp_init();

    // enc_a.start_yaw_data_transfer();
    motor_a_driver.start();
    while (1)
    {
        // enc_a.spi_.send(0);

        CyDelay(1);
    }
}