#pragma once

#include <cstdint>

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
    };

    enum class StateColor : uint32_t {
        ColorStart = 0x0000FF00,
        ColorStop  = 0x000000FF,
        ColorFault = 0x00FF0000,
    };

    struct CommandDoerState {
        State      mech_state   = State::Stop;
        Command    mech_command = Command::Default;
        StateColor light_color  = StateColor::ColorStop;
    };

    explicit CommandDoer(CommandDoerState& state) : state_(state) {}

    void task_ctl();

    // Getters
    State state() const { return state_.mech_state; }
    Command command() const { return state_.mech_command; }
    StateColor light_color() const { return state_.light_color; }

    // Setters
    void set_command(Command cmd) { state_.mech_command = cmd; }

private:
    void task_manager();

    CommandDoerState& state_;
};
