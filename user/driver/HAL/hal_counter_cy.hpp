#pragma once

#include <cstdint>

#include "cybsp.h"

/**
 * @brief TCPWM Counter 模式 HAL 封装
 * @details 用于速度环等独立定时中断，与 hal_pwm 同层级但使用 counter 专用 PDL 函数。
 */
class hal_counter
{
    TCPWM_Type* base_;
    uint32_t num_;

public:
    explicit hal_counter(TCPWM_Type* base, uint32_t num)
        : base_(base), num_(num)
    {
        CY_ASSERT(base_ != nullptr);
    }
    hal_counter(const hal_counter&) = delete;
    hal_counter& operator=(const hal_counter&) = delete;
    hal_counter(hal_counter&&) = delete;
    hal_counter& operator=(hal_counter&&) = delete;

    void enable();
    void start();
    void stop();
    uint32_t get_count();

    enum interrupt_type : uint32_t
    {
        NONE = 0b0,
        INT_ON_TC  = 0b001,
        INT_ON_CC0 = 0b010,
        INT_ON_CC1 = 0b100,
    };

    void open_interrupt(interrupt_type int_type);
    void close_interrupt(interrupt_type int_type);
    interrupt_type get_interrupt_type();
    void clear_interrupt(interrupt_type int_type);
};

inline void hal_counter::enable()
{
    Cy_TCPWM_Counter_Enable(base_, num_);
}

inline void hal_counter::start()
{
    Cy_TCPWM_TriggerStart_Single(base_, num_);
}

inline void hal_counter::stop()
{
    Cy_TCPWM_TriggerStopOrKill_Single(base_, num_);
}

inline uint32_t hal_counter::get_count()
{
    return Cy_TCPWM_Counter_GetCounter(base_, num_);
}

inline void hal_counter::open_interrupt(interrupt_type int_type)
{
    uint32_t raw = TCPWM_GRP_CNT_INTR_MASK(base_, TCPWM_GRP_CNT_GET_GRP(num_), num_);
    TCPWM_GRP_CNT_INTR_MASK(base_, TCPWM_GRP_CNT_GET_GRP(num_), num_) = raw | int_type;
}

inline void hal_counter::close_interrupt(interrupt_type int_type)
{
    uint32_t raw = TCPWM_GRP_CNT_INTR_MASK(base_, TCPWM_GRP_CNT_GET_GRP(num_), num_);
    TCPWM_GRP_CNT_INTR_MASK(base_, TCPWM_GRP_CNT_GET_GRP(num_), num_) = raw & ~int_type;
}

inline hal_counter::interrupt_type hal_counter::get_interrupt_type()
{
    uint32_t raw = TCPWM_GRP_CNT_INTR_MASKED(base_, TCPWM_GRP_CNT_GET_GRP(num_), num_);
    if ((raw & INT_ON_TC) != 0)
    {
        return INT_ON_TC;
    }
    else if ((raw & INT_ON_CC0) != 0)
    {
        return INT_ON_CC0;
    }
    else if ((raw & INT_ON_CC1) != 0)
    {
        return INT_ON_CC1;
    }
    else
    {
        return NONE;
    }

    return NONE;
}

inline void hal_counter::clear_interrupt(interrupt_type int_type)
{
    TCPWM_GRP_CNT_INTR(base_, TCPWM_GRP_CNT_GET_GRP(num_), num_) = int_type;
}
