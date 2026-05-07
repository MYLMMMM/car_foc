#pragma once

#include <cstdint>

#include "cybsp.h"

class hal_pwm
{
    TCPWM_Type* base_;
    uint32_t num_;

public:
    explicit hal_pwm(TCPWM_Type* base, uint32_t num)
        : base_(base), num_(num)
    {
        CY_ASSERT(base_ != nullptr);
    }
    hal_pwm(const hal_pwm&) = delete;
    hal_pwm& operator=(const hal_pwm&) = delete;
    hal_pwm(hal_pwm&&) = delete;
    hal_pwm& operator=(hal_pwm&&) = delete;

    void enable();
    void start();
    void stop();
    void set_period(uint32_t period);
    void set_compare(uint32_t compare);
    void set_comp0(uint32_t compare0);
    void set_comp1(uint32_t compare1);
    uint32_t get_count();

    enum hal_pwm_interrupt_type : uint32_t
    {    
        NONE = 0b0,
        INT_ON_TC  = 0b001,      
        INT_ON_CC0 = 0b010,      
        INT_ON_CC1 = 0b100, 
    };

    void open_interrupt(hal_pwm_interrupt_type int_type);
    void close_interrupt(hal_pwm_interrupt_type int_type);
    hal_pwm_interrupt_type get_interrupt_type();
    void clear_interrupt(hal_pwm_interrupt_type int_type);
};

inline void hal_pwm::enable()
{
    Cy_TCPWM_PWM_Enable(base_, num_);
}

inline void hal_pwm::start()
{
    Cy_TCPWM_TriggerStart_Single(base_, num_);
}

inline void hal_pwm::stop()
{
    Cy_TCPWM_TriggerStopOrKill_Single(base_, num_);
}

inline void hal_pwm::set_period(uint32_t period)
{
    Cy_TCPWM_PWM_SetPeriod0(base_, num_, period);
    Cy_TCPWM_PWM_SetPeriod1(base_, num_, period);
}

inline void hal_pwm::set_compare(uint32_t compare)
{
    Cy_TCPWM_PWM_SetCompare0Val(base_, num_, compare);
    Cy_TCPWM_PWM_SetCompare1Val(base_, num_, compare);
}

inline void hal_pwm::set_comp0(uint32_t compare0)
{
    Cy_TCPWM_PWM_SetCompare0Val(base_, num_, compare0);
}

inline void hal_pwm::set_comp1(uint32_t compare1)
{
    Cy_TCPWM_PWM_SetCompare1Val(base_, num_, compare1);
}

inline uint32_t hal_pwm::get_count()
{
    return Cy_TCPWM_PWM_GetCounter(base_,num_);
}

inline void hal_pwm::open_interrupt(hal_pwm_interrupt_type int_type)
{
    uint32_t raw = TCPWM_GRP_CNT_INTR_MASK(base_, TCPWM_GRP_CNT_GET_GRP(num_), num_);
    TCPWM_GRP_CNT_INTR_MASK(base_, TCPWM_GRP_CNT_GET_GRP(num_), num_) = raw | int_type;
}

inline void hal_pwm::close_interrupt(hal_pwm_interrupt_type int_type)
{
    uint32_t raw = TCPWM_GRP_CNT_INTR_MASK(base_, TCPWM_GRP_CNT_GET_GRP(num_), num_);
    TCPWM_GRP_CNT_INTR_MASK(base_, TCPWM_GRP_CNT_GET_GRP(num_), num_) = raw & ~int_type;
}

inline hal_pwm::hal_pwm_interrupt_type hal_pwm::get_interrupt_type()
{
    uint32_t raw = TCPWM_GRP_CNT_INTR_MASKED(base_, TCPWM_GRP_CNT_GET_GRP(num_), num_);
    if((raw & INT_ON_TC) != 0)
    {
        return INT_ON_TC;
    }
    else if((raw & INT_ON_CC0) != 0)
    {
        return INT_ON_CC0;
    }
    else if((raw & INT_ON_CC1) != 0)
    {
        return INT_ON_CC1;
    }
    else
    {
        return NONE;
    }

    return NONE;
}

inline void hal_pwm::clear_interrupt(hal_pwm_interrupt_type int_type)
{
    uint32_t raw = TCPWM_GRP_CNT_INTR_MASKED(base_, TCPWM_GRP_CNT_GET_GRP(num_), num_);
    TCPWM_GRP_CNT_INTR(base_, TCPWM_GRP_CNT_GET_GRP(num_), num_) = raw  ;
}