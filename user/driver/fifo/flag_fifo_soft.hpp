#pragma once
#include <cstdint>
#include <cstddef>
#include "flag_fifo.hpp"

template <typename data_type, uint16_t fifo_deep>
class sw_flag_fifo : public flag_fifo<data_type> {
private:
    data_type data_[fifo_deep];
   uint16_t write_index_;
    uint16_t read_index_;
    uint16_t count_;

public:
    sw_flag_fifo()
        : data_{}, write_index_(0), read_index_(0), count_(0) {}

    sw_flag_fifo(const sw_flag_fifo&) = delete;
    sw_flag_fifo& operator=(const sw_flag_fifo&) = delete;
    sw_flag_fifo(sw_flag_fifo&&) = delete;
    sw_flag_fifo& operator=(sw_flag_fifo&&) = delete;

    void* operator new(std::size_t) = delete;

    void write(const data_type& value) override {
        data_[write_index_] = value;

        if (count_ < fifo_deep) {
            ++count_;
        } else {
            read_index_ = static_cast<uint16_t>((read_index_ + 1u) % fifo_deep);
        }

        write_index_ = static_cast<uint16_t>((write_index_ + 1u) % fifo_deep);
    }

    data_type read() override {
        data_type value = data_[read_index_];

        if (count_ > 0u) {
            --count_;
            read_index_ = static_cast<uint16_t>((read_index_ + 1u) % fifo_deep);
        }

        return value;
    }

    void count_add() override {
        if (count_ < fifo_deep) {
            ++count_;
        } else {
            read_index_ = static_cast<uint16_t>((read_index_ + 1u) % fifo_deep);
        }

        write_index_ = static_cast<uint16_t>((write_index_ + 1u) % fifo_deep);
    }

    void count_sub() override {
        if (count_ > 0u) {
            --count_;
            read_index_ = static_cast<uint16_t>((read_index_ + 1u) % fifo_deep);
        }
    }

    void clear() override {
        write_index_ = 0u;
        read_index_ = 0u;
        count_ = 0u;
    }

    uint16_t isNew() const override {
        return count_;
    }
};
