#include "command_doer.hpp"
#include "tasks.hpp"
#include "bsp_init.hpp"
#include "cybsp.h"
#include "SEGGER_RTT.h"

void CommandDoer::task_ctl()
{
    // 刷新缓冲区
    spi_ctr_decode.stream_update();
    // 低压检测
    //low_voltage_check();
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
        if (state_.mech_state == State::Running)
        {
            state_.mech_command = Command::Default;  // 已在运行，忽略
            break;
        }
        task_start();
        state_.mech_command = Command::Default;
        state_.mech_state   = State::Running;
        state_.light_color  = StateColor::ColorStart;
        break;
    case Command::Stop:
        task_stop();
        state_.mech_command = Command::Default;
        state_.mech_state   = State::Stop;
        state_.light_color  = StateColor::ColorStop;
        break;
    case Command::InternalError:
        task_internal_error();
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

void CommandDoer::low_voltage_check()
{
    // 仅 Running 状态下检测，避免停机后误报
    if (state_.mech_state != State::Running)
    {
        low_voltage_count_ = 0;
        return;
    }

    if (foc_motor_datastructure_A.v_bus < kLowVoltageThreshold)
    {
        if (++low_voltage_count_ >= kLowVoltageDebounce)
        {
            set_command(Command::InternalError);
            low_voltage_count_ = 0;
        }
    }
    else
    {
        low_voltage_count_ = 0;
    }
}