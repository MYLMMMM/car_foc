#include "command_doer.hpp"
#include "bsp_init.hpp"
#include "cybsp.h"
#include "SEGGER_RTT.h"

void CommandDoer::task_ctl()
{
    // 刷新缓冲区
    spi_ctr_decode.stream_update();
    // 任务状态更新
    task_manager();
}

void CommandDoer::task_manager()
{
    switch (state_.mech_command)
    {
    case Command::Default:
        break;
    case Command::Start:
        motor_a_driver.start();
        motor_b_driver.start();
        state_.mech_command = Command::Default;
        state_.mech_state   = State::Running;
        state_.light_color  = StateColor::ColorStart;
        break;
    case Command::Stop:
        motor_a_driver.stop();
        motor_b_driver.stop();
        state_.mech_command = Command::Default;
        state_.mech_state   = State::Stop;
        state_.light_color  = StateColor::ColorStop;
        break;
    default:
        break;
    }
}