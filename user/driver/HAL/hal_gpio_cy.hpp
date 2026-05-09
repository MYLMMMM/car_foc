#pragma once

#include "cybsp.h"

class hal_gpio 
{
    GPIO_PRT_Type* port_;
    uint32_t pin_;
public:
    hal_gpio(GPIO_PRT_Type* port,uint32_t pin):port_(port),pin_(pin){};
    hal_gpio(const hal_gpio&) = delete;
    hal_gpio& operator=(const hal_gpio&) = delete;
    hal_gpio(hal_gpio&&) = delete;
    hal_gpio& operator=(hal_gpio&&) = delete;

    void set();
    void unset();
    void toggle();
    bool read();
    bool get_interrupt_state();
    void clear_interrupt_state();
};

inline void hal_gpio::set()
{
    Cy_GPIO_Set(port_,pin_);
}

inline void hal_gpio::unset()
{
    Cy_GPIO_Clr(port_,pin_);
}

inline void hal_gpio::toggle()
{
    Cy_GPIO_Inv(port_,pin_);
}

inline bool hal_gpio::read()
{
    return static_cast<bool>(Cy_GPIO_Read(port_,pin_));
}

inline bool hal_gpio::get_interrupt_state()
{
    return Cy_GPIO_GetInterruptStatusMasked(port_,pin_);
}

inline void hal_gpio::clear_interrupt_state()
{
    Cy_GPIO_ClearInterrupt(port_,pin_);
}
