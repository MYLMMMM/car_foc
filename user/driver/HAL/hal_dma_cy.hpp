#pragma once

#include <cstdint>

#include "cybsp.h"

class hal_dma
{
    DW_Type*  base_;
    uint32_t  channel_;

public:
    explicit hal_dma(DW_Type* base, uint32_t channel)
        : base_(base), channel_(channel)
    {
        CY_ASSERT(base_ != nullptr);
    }
    hal_dma(const hal_dma&) = delete;
    hal_dma& operator=(const hal_dma&) = delete;
    hal_dma(hal_dma&&) = delete;
    hal_dma& operator=(hal_dma&&) = delete;

    void enable_block();
    void disable_block();

    void enable();
    void disable();
    bool is_enabled();

    void set_descriptor(cy_stc_dma_descriptor_t const* descriptor);
    void set_priority(uint32_t priority);
    void sw_trigger();
    bool is_active();

    /*--------descriptor helpers--------*/
    static void set_src(cy_stc_dma_descriptor_t* descriptor, void const* src);
    static void set_dst(cy_stc_dma_descriptor_t* descriptor, void* dst);
    static void set_count(cy_stc_dma_descriptor_t* descriptor, uint32_t count);

    /*--------interrupt--------*/
    uint32_t get_interrupt_status();
    void     clear_interrupt();
    void     set_interrupt_mask(uint32_t mask);
    uint32_t get_interrupt_mask();
    uint32_t get_interrupt_status_masked();
};

inline void hal_dma::enable_block()
{
    Cy_DMA_Enable(base_);
}

inline void hal_dma::disable_block()
{
    Cy_DMA_Disable(base_);
}

inline void hal_dma::enable()
{
    Cy_DMA_Channel_Enable(base_, channel_);
}

inline void hal_dma::disable()
{
    Cy_DMA_Channel_Disable(base_, channel_);
}

inline bool hal_dma::is_enabled()
{
    return Cy_DMA_Channel_IsEnabled(base_, channel_);
}

inline void hal_dma::set_descriptor(cy_stc_dma_descriptor_t const* descriptor)
{
    Cy_DMA_Channel_SetDescriptor(base_, channel_, descriptor);
}

inline void hal_dma::set_priority(uint32_t priority)
{
    Cy_DMA_Channel_SetPriority(base_, channel_, priority);
}

inline void hal_dma::sw_trigger()
{
    Cy_DMA_Channel_SetSWTrigger(base_, channel_);
}

inline bool hal_dma::is_active()
{
    return Cy_DMA_Channel_IsEnabled(base_, channel_);
}

inline void hal_dma::set_src(cy_stc_dma_descriptor_t* descriptor, void const* src)
{
    Cy_DMA_Descriptor_SetSrcAddress(descriptor, src);
}

inline void hal_dma::set_dst(cy_stc_dma_descriptor_t* descriptor, void* dst)
{
    Cy_DMA_Descriptor_SetDstAddress(descriptor, dst);
}

inline void hal_dma::set_count(cy_stc_dma_descriptor_t* descriptor, uint32_t count)
{
    Cy_DMA_Descriptor_SetXloopDataCount(descriptor, count);
}

inline uint32_t hal_dma::get_interrupt_status()
{
    return Cy_DMA_Channel_GetInterruptStatus(base_, channel_);
}

inline void hal_dma::clear_interrupt()
{
    Cy_DMA_Channel_ClearInterrupt(base_, channel_);
}

inline void hal_dma::set_interrupt_mask(uint32_t mask)
{
    Cy_DMA_Channel_SetInterruptMask(base_, channel_, mask);
}

inline uint32_t hal_dma::get_interrupt_mask()
{
    return Cy_DMA_Channel_GetInterruptMask(base_, channel_);
}

inline uint32_t hal_dma::get_interrupt_status_masked()
{
    return Cy_DMA_Channel_GetInterruptStatusMasked(base_, channel_);
}
