#pragma once

#include <cstdint>

#include "cybsp.h"

class hal_adc;

class hal_adc_chan
{
    hal_adc* adc_;
    uint32_t channel_idx_;
    uint32_t channel_mask_;

public:
    explicit hal_adc_chan(hal_adc& adc, uint32_t channel_idx)
        : adc_(&adc)
        , channel_idx_(channel_idx)
        , channel_mask_(1UL << channel_idx)
    {
        CY_ASSERT(adc_ != nullptr);
        CY_ASSERT(channel_idx_ < CY_HPPASS_SAR_CHAN_NUM);
    }
    hal_adc_chan(const hal_adc_chan&) = default;
    hal_adc_chan& operator=(const hal_adc_chan&) = default;

    int16_t recive();
    int32_t recive_raw();
    volatile const int32_t* get_result_ptr();
    bool isnew();
    void clear_new();
    uint32_t get_channel_idx();
    uint32_t get_channel_mask();
};

class hal_adc
{
    HPPASS_Type* handle_;

public:
    explicit hal_adc(HPPASS_Type* handle = HPPASS)
        : handle_(handle)
    {
        CY_ASSERT(handle_ != nullptr);
    }
    hal_adc(const hal_adc&) = delete;
    hal_adc& operator=(const hal_adc&) = delete;
    hal_adc(hal_adc&&) = delete;
    hal_adc& operator=(hal_adc&&) = delete;

    HPPASS_Type* get_handle();
    hal_adc_chan chan(uint32_t channel_idx);

    uint32_t get_status();
    void clear_status(uint32_t status_mask);

    cy_en_hppass_status_t start();
    bool isready();
    cy_en_hppass_status_t sw_trigger(uint32_t trigger_mask);

    /*--------interrupt--------*/
    enum hal_adc_interrupt_type : uint32_t
    {
        NONE = 0x0UL,
        RESULT_GROUP_0 = CY_HPPASS_INTR_SAR_RESULT_GROUP_0,
        RESULT_GROUP_1 = CY_HPPASS_INTR_SAR_RESULT_GROUP_1,
        RESULT_GROUP_2 = CY_HPPASS_INTR_SAR_RESULT_GROUP_2,
        RESULT_GROUP_3 = CY_HPPASS_INTR_SAR_RESULT_GROUP_3,
        RESULT_GROUP_4 = CY_HPPASS_INTR_SAR_RESULT_GROUP_4,
        RESULT_GROUP_5 = CY_HPPASS_INTR_SAR_RESULT_GROUP_5,
        RESULT_GROUP_6 = CY_HPPASS_INTR_SAR_RESULT_GROUP_6,
        RESULT_GROUP_7 = CY_HPPASS_INTR_SAR_RESULT_GROUP_7,
        RESULT_GROUP = CY_HPPASS_INTR_SAR_RESULT_GROUP,
        RESULT_FIR_0 = CY_HPPASS_INTR_SAR_RESULT_FIR_0,
        RESULT_FIR_1 = CY_HPPASS_INTR_SAR_RESULT_FIR_1,
        RESULT_FIR = CY_HPPASS_INTR_SAR_RESULT_FIR,
        RESULT_ALL = CY_HPPASS_INTR_SAR_RESULT,
    };
    void open_interrupt(hal_adc_interrupt_type int_type);
    void close_interrupt(hal_adc_interrupt_type int_type);
    hal_adc_interrupt_type get_interrupt_type();
    void clear_interrupt(hal_adc_interrupt_type int_type);
};

inline int16_t hal_adc_chan::recive()
{
    return Cy_HPPASS_SAR_Result_ChannelRead(static_cast<uint8_t>(channel_idx_));
}

inline int32_t hal_adc_chan::recive_raw()
{
    return *reinterpret_cast<volatile const int32_t*>(CY_HPPASS_SAR_CHAN_RSLT_PTR(channel_idx_));
}

inline volatile const int32_t* hal_adc_chan::get_result_ptr()
{
    return reinterpret_cast<volatile const int32_t*>(CY_HPPASS_SAR_CHAN_RSLT_PTR(channel_idx_));
}

inline bool hal_adc_chan::isnew()
{
    return (Cy_HPPASS_SAR_Result_GetStatus() & channel_mask_) != 0UL;
}

inline void hal_adc_chan::clear_new()
{
    Cy_HPPASS_SAR_Result_ClearStatus(channel_mask_);
}

inline uint32_t hal_adc_chan::get_channel_idx()
{
    return channel_idx_;
}

inline uint32_t hal_adc_chan::get_channel_mask()
{
    return channel_mask_;
}

inline HPPASS_Type* hal_adc::get_handle()
{
    return handle_;
}

inline hal_adc_chan hal_adc::chan(uint32_t channel_idx)
{
    return hal_adc_chan(*this, channel_idx);
}

inline uint32_t hal_adc::get_status()
{
    return Cy_HPPASS_SAR_Result_GetStatus();
}

inline void hal_adc::clear_status(uint32_t status_mask)
{
    Cy_HPPASS_SAR_Result_ClearStatus(status_mask);
}

inline cy_en_hppass_status_t hal_adc::start()
{
    return Cy_HPPASS_AC_Start(0U, 0U);
}

inline bool hal_adc::isready()
{
    return Cy_HPPASS_AC_IsBlockReady();
}

inline cy_en_hppass_status_t hal_adc::sw_trigger(uint32_t trigger_mask)
{
    return Cy_HPPASS_SetFwTrigger(trigger_mask);
}

inline void hal_adc::open_interrupt(hal_adc_interrupt_type int_type)
{
    uint32_t int_mask = Cy_HPPASS_SAR_Result_GetInterruptMask();
    int_mask = int_mask | int_type;
    Cy_HPPASS_SAR_Result_SetInterruptMask(int_mask);
}

inline void hal_adc::close_interrupt(hal_adc_interrupt_type int_type)
{
    uint32_t int_mask = Cy_HPPASS_SAR_Result_GetInterruptMask();
    int_mask = int_mask & (~int_type);
    Cy_HPPASS_SAR_Result_SetInterruptMask(int_mask);
}

inline hal_adc::hal_adc_interrupt_type hal_adc::get_interrupt_type()
{
    return static_cast<hal_adc_interrupt_type>(Cy_HPPASS_SAR_Result_GetInterruptStatusMasked());
}

inline void hal_adc::clear_interrupt(hal_adc_interrupt_type int_type)
{
    Cy_HPPASS_SAR_Result_ClearInterrupt(int_type);
}
