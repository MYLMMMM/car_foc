#pragma once

#include <cstdint>

class XL202RGBC;

class CommandDoer {
public:
    enum class State : uint32_t {
        Stop = 0,
        Running = 1,
        FaultHalt = 2
    };

    enum class Command : uint32_t {
        Default = 0,
        Start = 1,
        Stop = 2,
        InternalError = 3,
    };

    enum class StateColor : uint32_t {
        ColorStart = 0x00004400,
        ColorStop  = 0x00000044,
        ColorFault = 0x00440000,
    };

    struct CommandDoerState {
        State      mech_state   = State::Stop;
        Command    mech_command = Command::Stop;
        StateColor light_color  = StateColor::ColorStop;
    };

    explicit CommandDoer(CommandDoerState& state, XL202RGBC& led)
        : state_(state), led_(led) {}

    void task_ctl();
    void low_voltage_check();

    // Getters
    State state() const { return state_.mech_state; }
    Command command() const { return state_.mech_command; }
    StateColor light_color() const { return state_.light_color; }

    // Setters
    void set_command(Command cmd) { state_.mech_command = cmd; }

private:
    void task_manager();

    CommandDoerState& state_;
    XL202RGBC&       led_;

    static constexpr float kLowVoltageThreshold = 3.0f * 3.4f;  // 3S LiPo 最低 10.2V
    static constexpr uint32_t kLowVoltageDebounce = 300;           // 连续 5 次确认
    uint32_t low_voltage_count_ = 0;
};
