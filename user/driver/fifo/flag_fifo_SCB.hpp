#pragma once
#include <cstdint>
#include <cstddef>
#include <cybsp.h>
#include "flag_fifo.hpp"


template <typename data_type>
class hw_flag_fifo : public flag_fifo<data_type> {
private:
    CySCB_Type* base_;

public:
    explicit hw_flag_fifo(CySCB_Type* base)
        : base_(base) {}

    hw_flag_fifo(const hw_flag_fifo&) = delete;
    hw_flag_fifo& operator=(const hw_flag_fifo&) = delete;
    hw_flag_fifo(hw_flag_fifo&&) = delete;
    hw_flag_fifo& operator=(hw_flag_fifo&&) = delete;

    void* operator new(std::size_t) = delete;

    void write(const data_type& value) override {
        Cy_SCB_SPI_Write(base_,(data_type)value);
    }

    data_type read() override {
        return Cy_SCB_SPI_Read(base_);
    }

    void count_add() override {

    }

    void count_sub() override {
        
    }

    void clear() override {
        Cy_SCB_SPI_ClearRxFifo(base_);
    }

    /*****
     * @return none is 0 , or return count of mesg
     */
    uint16_t isNew() const override {
        // 查询硬件 FIFO 当前有效数据数
        // return hw_count(base_);
        return Cy_SCB_SPI_GetNumInRxFifo(base_);
    }
};
