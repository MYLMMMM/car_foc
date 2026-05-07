#pragma once
#include <cstdint>
#include <cstddef>

template <typename data_type>
class flag_fifo {
public:
    virtual ~flag_fifo() = default;

    virtual void write(const data_type& value) = 0;
    virtual data_type read() = 0;

    virtual void count_add() = 0;
    virtual void count_sub() = 0;
    virtual void clear() = 0;

    virtual uint16_t isNew() const = 0;
};
