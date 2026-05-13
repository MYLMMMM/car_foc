#pragma once
#include "drv8304.hpp"
#include "kth7823.hpp"
#include "endecode.hpp"
#include "XL2020RGBC.hpp"
#include "motor.hpp"
#include "dc_motor_driver.hpp"
#include "command_doer.hpp"

void bsp_init();


extern drv8304 drv8304_a;
extern drv8304 drv8304_b;
extern kth7823 enc_a;
extern kth7823 enc_b;
extern motor_driver motor_a_driver;
extern motor_driver motor_b_driver;
extern dc_motor_driver motor_c_driver;
extern spi_decode spi_ctr_decode;
extern XL202RGBC ws2812;
extern CommandDoer command_doer;
extern CommandDoer::CommandDoerState command_doer_state;

