#include "bsp_init.hpp"
#include "cybsp.h"
#include "SEGGER_RTT.h"


void task()
{
    //刷新缓冲区
    spi_ctr_decode.stream_update();

    //任务状态更新
}