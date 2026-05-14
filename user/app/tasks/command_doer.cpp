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
        motor_c_driver.start();
        state_.mech_command = Command::Default;
        state_.mech_state   = State::Running;
        state_.light_color  = StateColor::ColorStart;
        break;
    case Command::Stop:
        motor_a_driver.stop();
        motor_b_driver.stop();
        motor_c_driver.stop();
        state_.mech_command = Command::Default;
        state_.mech_state   = State::Stop;
        state_.light_color  = StateColor::ColorStop;
        break;
    case Command::InternalError:
        motor_a_driver.stop();
        motor_b_driver.stop();
        state_.mech_command = Command::Default;
        state_.mech_state   = State::FaultHalt;
        state_.light_color  = StateColor::ColorFault;
        break;
    default:
        break;
    }

    uint32_t color_val = static_cast<uint32_t>(state_.light_color);
    led_.set_color(
        static_cast<uint8_t>((color_val >> 16) & 0xFF),
        static_cast<uint8_t>((color_val >> 8) & 0xFF),
        static_cast<uint8_t>((color_val >> 0) & 0xFF));
}