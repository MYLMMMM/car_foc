#include "bsp_init.hpp"
#include "cybsp.h"
#include "SEGGER_RTT.h"
#include "cstdint"

enum class state : uint32_t 
{
    stop = 0,
    running = 1,
    fault_halt = 2
};
state mech_state = state::stop;

enum class command : uint32_t
{
    default_command = 0,
    start = 1,
    stop = 2,
};
command mech_command = command::default_command;

enum class state_color : uint32_t
{
    color_start = 0x0000FF00,
    colar_stop = 0x000000FF,
    color_fault = 0x00FF0000,
};
state_color light_color = state_color::colar_stop;

void task_maneger();

void task_ctl()
{
    //刷新缓冲区
    spi_ctr_decode.stream_update();
    //任务状态更新
    task_maneger();
}

void task_maneger()
{
    switch (mech_command)
    {
    case command::default_command:
        break;
    case command::start:
        motor_a_driver.start();
        motor_b_driver.start();
        mech_command = command::default_command;
        mech_state = state::running;
        light_color = state_color::color_start;
        break;
    case command::stop:
        motor_a_driver.stop();
        motor_b_driver.stop();
        mech_command = command::default_command;
        mech_state = state::stop;
        light_color = state_color::colar_stop;
        break;
    default:
        break;
    }
}