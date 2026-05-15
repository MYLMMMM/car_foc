#include "valuemap.hpp"

#include <cstdint>

#include "foc_soft.hpp"
#include "bsp_init.hpp"

extern foc_motor_datastructure foc_motor_datastructure_A;
extern foc_motor_datastructure foc_motor_datastructure_B;

namespace
{
enum value_addr : uint8_t
{
    cmd_command = 0x01u,
    mech_state = 0x02u,
    light_color = 0x03u,

    A_speed_target = 0x31u,
    A_pid_speed_kp = 0x1Du,
    A_pid_speed_ki = 0x1Eu,
    A_pid_speed_kd = 0x1Fu,
    A_pid_speed_integral_limit = 0x30u,

    B_speed_target = 0x41u,
    B_pid_speed_kp = 0x2Du,
    B_pid_speed_ki = 0x2Eu,
    B_pid_speed_kd = 0x2Fu,
    B_pid_speed_integral_limit = 0x40u
};

template <typename T>
bool register_rw(spi_decode& decoder, uint8_t addr, T& ref)
{
    return decoder.register_map(addr, ref, true, true);
}
} // namespace

bool valuemap_register(spi_decode& decoder)
{
    bool ok = true;

    ok &= register_rw(decoder, cmd_command, reinterpret_cast<uint32_t&>(command_doer_state.mech_command));
    ok &= register_rw(decoder, mech_state, reinterpret_cast<uint32_t&>(command_doer_state.mech_state));
    ok &= register_rw(decoder, light_color, reinterpret_cast<uint32_t&>(command_doer_state.light_color));

    ok &= register_rw(decoder, A_speed_target, foc_motor_datastructure_A.speed_target);
    ok &= register_rw(decoder, A_pid_speed_kp, foc_motor_datastructure_A.pid_speed_kp);
    ok &= register_rw(decoder, A_pid_speed_ki, foc_motor_datastructure_A.pid_speed_ki);
    ok &= register_rw(decoder, A_pid_speed_kd, foc_motor_datastructure_A.pid_speed_kd);
    ok &= register_rw(decoder, A_pid_speed_integral_limit, foc_motor_datastructure_A.pid_speed_integral_limit);

    ok &= register_rw(decoder, B_speed_target, foc_motor_datastructure_B.speed_target);
    ok &= register_rw(decoder, B_pid_speed_kp, foc_motor_datastructure_B.pid_speed_kp);
    ok &= register_rw(decoder, B_pid_speed_ki, foc_motor_datastructure_B.pid_speed_ki);
    ok &= register_rw(decoder, B_pid_speed_kd, foc_motor_datastructure_B.pid_speed_kd);
    ok &= register_rw(decoder, B_pid_speed_integral_limit, foc_motor_datastructure_B.pid_speed_integral_limit);

    return ok;
}
