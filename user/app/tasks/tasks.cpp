#include "tasks.hpp"
#include "bsp_init.hpp"

void task_start()
{
    motor_a_driver.start();
    motor_b_driver.start();
    motor_c_driver.start();
}

void task_stop()
{
    motor_a_driver.stop();
    motor_b_driver.stop();
    motor_c_driver.stop();
}

void task_internal_error()
{
    motor_a_driver.stop();
    motor_b_driver.stop();
    motor_c_driver.stop();
}

void task_direction_calibration()
{
    // TODO: 方向校准逻辑
}

void task_elec_angle_calibration()
{
    // TODO: 电角对齐校准逻辑
}
