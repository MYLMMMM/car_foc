#include "cybsp.h"
#include "bsp_init.hpp"

void main_entry()
{
    bsp_init();//hardware init

    while (1)
    {
        
        // drv8304_a.refresh_fault_status();
        // drv8304_b.refresh_fault_status();
    }
}