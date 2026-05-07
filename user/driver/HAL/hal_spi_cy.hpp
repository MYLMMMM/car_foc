#pragma once

#include <cstdint>

#include "cybsp.h"

class hal_spi
{
    CySCB_Type* base_;
    cy_en_scb_spi_slave_select_t select_;
public:
    explicit hal_spi(CySCB_Type* base,cy_en_scb_spi_slave_select_t select = CY_SCB_SPI_SLAVE_SELECT0)
        : base_(base),select_(select)
    {
        CY_ASSERT(base_ != nullptr);
    }
    hal_spi(const hal_spi&) = delete;
    hal_spi& operator=(const hal_spi&) = delete;
    hal_spi(hal_spi&&) = delete;
    hal_spi& operator=(hal_spi&&) = delete;

    void select();
    void send(uint32_t msg);
    uint32_t recive();
    uint16_t isnew(); // 返回接收 fifo 待读取消息数量
    uint16_t isunsend();// 返回发送fifo待发送消息数量
    uint16_t get_fifo_size();
    void clear_rx();
    void clear_tx();
    bool isbusy();

    /*--------interrupt--------*/
    enum hal_spi_interrupt_type : uint32_t
    {
        NONE = 0x0UL,
        RX_FIFO_NOT_EMPTY = 0x4UL,
        RX_FIFO_FULL = 0x8UL,
        RX_FIFO_OVERFLOW = 0x20UL,
        RX_FIFO_UNDERFLOW = 0x40UL,
    };
    void open_rx_interrupt(hal_spi_interrupt_type int_type);
    void close_rx_interrupt(hal_spi_interrupt_type int_type);
    hal_spi_interrupt_type get_rx_interrupt_type();
    void clear_rx_interrupt(hal_spi_interrupt_type int_type);
};

inline void hal_spi::select()
{
    Cy_SCB_SPI_SetActiveSlaveSelect(base_,select_);
}
inline void hal_spi::send(uint32_t msg)
{
    (void)Cy_SCB_SPI_Write(base_, msg);
}

inline uint32_t hal_spi::recive()
{
    return Cy_SCB_SPI_Read(base_);
}

inline uint16_t hal_spi::isnew()
{
    return static_cast<uint16_t>(Cy_SCB_SPI_GetNumInRxFifo(base_));
}

inline uint16_t hal_spi::isunsend()
{
    return static_cast<uint16_t>(Cy_SCB_SPI_GetNumInRxFifo(base_));
}

inline uint16_t hal_spi::get_fifo_size()
{
    return static_cast<uint16_t>(Cy_SCB_GetFifoSize(base_));
}
inline void hal_spi::clear_rx()
{
    Cy_SCB_SPI_ClearRxFifo(base_);
}

inline void hal_spi::clear_tx()
{
    Cy_SCB_SPI_ClearTxFifo(base_);
}

inline bool hal_spi::isbusy()
{
    return Cy_SCB_SPI_IsBusBusy(base_);
}

inline void hal_spi::open_rx_interrupt(hal_spi_interrupt_type int_type)
{
    uint32_t int_mask = Cy_SCB_GetRxInterruptMask(base_);
    int_mask = int_mask | int_type;
    Cy_SCB_SetRxInterruptMask(base_,int_mask);
}

inline void hal_spi::close_rx_interrupt(hal_spi_interrupt_type int_type)
{
    uint32_t int_mask = Cy_SCB_GetRxInterruptMask(base_);
    int_mask = int_mask & (~int_type);
    Cy_SCB_SetRxInterruptMask(base_,int_mask);
}
    
inline hal_spi::hal_spi_interrupt_type hal_spi::get_rx_interrupt_type()
{
    return (hal_spi_interrupt_type)Cy_SCB_GetRxInterruptStatusMasked(base_);
}//有bug

inline void hal_spi::clear_rx_interrupt(hal_spi_interrupt_type int_type)
{
    Cy_SCB_ClearRxInterrupt(base_,int_type);
}