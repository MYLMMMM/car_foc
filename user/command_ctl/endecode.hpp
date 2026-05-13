#pragma once

#include <cstdint>
#include <cstring>
#include <type_traits>

#include "SEGGER_RTT.h"

#include "flag_fifo_soft.hpp"
#include "hal.hpp"

class spi_decode
{
private:
    static constexpr uint8_t k_frame_head = 0xAAu;
    static constexpr uint16_t k_sw_buffer_depth = 30u;
    static constexpr uint8_t k_max_register_count = 64u;
    static constexpr uint8_t k_max_write_addr_count = 2u;

    enum class frame_cmd : uint8_t
    {
        empty = 0u,
        write_one = 1u,
        write_two = 2u,
        read_one = 3u,
        read_two = 4u,
        streamtransfer = 5u,
        stop = 6u
    };

    enum class decode_state : uint8_t
    {
        wait_head,
        wait_mid_frame
    };

    enum class value_type : uint8_t
    {
        u8,
        i8,
        u16,
        i16,
        u32,
        i32,
        f32
    };

    struct decoded_frame
    {
        uint8_t head;
        frame_cmd cmd;
        uint8_t data1;
        uint8_t data2;
    };

    struct write_cmd
    {
        uint8_t addr;
        uint32_t value;
    };

    struct register_meta
    {
        uint8_t addr;
        void* value_ptr;
        value_type type;
        bool readable;
        bool writable;
        bool used;
    };

    template <typename T>
    struct is_supported_value_type : std::integral_constant<bool,
        std::is_same<T, uint8_t>::value ||
        std::is_same<T, int8_t>::value ||
        std::is_same<T, uint16_t>::value ||
        std::is_same<T, int16_t>::value ||
        std::is_same<T, uint32_t>::value ||
        std::is_same<T, int32_t>::value ||
        std::is_same<T, float>::value> {};

    hal_spi& scb_fifo;
    hal_gpio& gpio_stream_state;
    hal_gpio& gpio_read_feedback;
    sw_flag_fifo<write_cmd, k_sw_buffer_depth> write_buffer;
    sw_flag_fifo<uint8_t, k_sw_buffer_depth> read_buffer;

    uint8_t pending_addrs[k_max_write_addr_count];
    decode_state state;
    uint8_t pending_addr_count;
    uint8_t pending_value_index;

    bool stream_transfer_on;

    register_meta reg_table[k_max_register_count];

public:
    explicit spi_decode(hal_spi& scb_fifo_, hal_gpio& gpio_stream_state_, hal_gpio& gpio_read_feedback_);

    template <typename T>
    bool register_map(uint8_t addr, T& value_ref, bool readable = true, bool writable = true)
    {
        static_assert(is_supported_value_type<T>::value, "unsupported register value type");
        return register_entry(addr,
                              static_cast<void*>(&value_ref),
                              map_type<T>(),
                              readable,
                              writable);
    }

    bool unregister_map(uint8_t addr);

    void clear_maps();

    void trig();

    void stream_update();

private:
    template <typename T>
    static value_type map_type()
    {
        if (std::is_same<T, uint8_t>::value)
        {
            return value_type::u8;
        }
        if (std::is_same<T, int8_t>::value)
        {
            return value_type::i8;
        }
        if (std::is_same<T, uint16_t>::value)
        {
            return value_type::u16;
        }
        if (std::is_same<T, int16_t>::value)
        {
            return value_type::i16;
        }
        if (std::is_same<T, uint32_t>::value)
        {
            return value_type::u32;
        }
        if (std::is_same<T, int32_t>::value)
        {
            return value_type::i32;
        }
        return value_type::f32;
    }

    static decoded_frame decode_raw_frame(uint32_t raw);

    void handle_head_frame(uint32_t raw);

    void handle_mid_frame_value(uint32_t raw);

    void drain_read_buffer_to_scb();

    void drain_write_buffer_to_registers();

    uint32_t emit_read_value_by_addr(uint8_t addr);

    bool register_entry(uint8_t addr, void* value_ptr, value_type type, bool readable, bool writable);

    register_meta* find_entry(uint8_t addr);
    const register_meta* find_entry(uint8_t addr) const;

    static uint32_t read_register_as_u32(const register_meta& meta);

    static void write_u32_to_register(register_meta& meta, uint32_t raw);

    void clear_pending_write_context();
    void clear_register_table();
};
