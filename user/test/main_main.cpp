#include "cybsp.h"
#include "bsp_init.hpp"

void main_entry()
{
    bsp_init();//hardware init


    Cy_TCPWM_TriggerStart_Single(TIMER_TASK_HW, TIMER_TASK_NUM);

    while (1)
    {

    }
}