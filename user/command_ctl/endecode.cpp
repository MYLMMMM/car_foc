#include "endecode.hpp"
#include "bsp_init.hpp"

spi_decode::spi_decode(hal_spi& scb_fifo_, hal_gpio& gpio_stream_state_, hal_gpio& gpio_read_feedback_)
    : scb_fifo(scb_fifo_),
      gpio_stream_state(gpio_stream_state_),
      gpio_read_feedback(gpio_read_feedback_),
      write_buffer(),
      read_buffer(),
      pending_addrs{0u, 0u},
      state(decode_state::wait_head),
      pending_addr_count(0u),
      pending_value_index(0u),
      stream_transfer_on(false),
      reg_table{}
{
    clear_register_table();
}

bool spi_decode::unregister_map(uint8_t addr)
{
    for (uint8_t i = 0u; i < k_max_register_count; ++i)
    {
        if (reg_table[i].used && (reg_table[i].addr == addr))
        {
            reg_table[i].used = false;
            reg_table[i].value_ptr = nullptr;
            reg_table[i].readable = false;
            reg_table[i].writable = false;
            return true;
        }
    }

    return false;
}

void spi_decode::clear_maps()
{
    clear_register_table();
}

void spi_decode::trig()
{
    while (scb_fifo.isnew() != 0u)
    {
        const uint32_t raw = scb_fifo.recive();

        if (state == decode_state::wait_head)
        {
            handle_head_frame(raw);
        }
        else
        {
            handle_mid_frame_value(raw);
        }
    }

    drain_read_buffer_to_scb();
    drain_write_buffer_to_registers();
}

void spi_decode::stream_update()
{
    if (stream_transfer_on)
    {
        uint32_t buffer[10];
        
        buffer[0] = motor_a_driver.foc_soft_.motor.i_q;
        buffer[1] = motor_a_driver.foc_soft_.motor.speed_mech;
        buffer[2] = motor_b_driver.foc_soft_.motor.i_q;
        buffer[3] = motor_b_driver.foc_soft_.motor.speed_mech;
        buffer[4] = (uint32_t)command_doer_state.mech_state;
        scb_fifo.clear_tx();
        scb_fifo.send(buffer[0]);
        scb_fifo.send(buffer[1]);
        scb_fifo.send(buffer[2]);
        scb_fifo.send(buffer[3]);
        scb_fifo.send(buffer[4]);

        gpio_stream_state.toggle();
    }
}

spi_decode::decoded_frame spi_decode::decode_raw_frame(uint32_t raw)
{
    decoded_frame frame{};
    frame.head = static_cast<uint8_t>((raw >> 24) & 0xFFu);
    frame.cmd = static_cast<frame_cmd>((raw >> 16) & 0xFFu);
    frame.data1 = static_cast<uint8_t>((raw >> 8) & 0xFFu);
    frame.data2 = static_cast<uint8_t>((raw >> 0) & 0xFFu);
    return frame;
}

void spi_decode::handle_head_frame(uint32_t raw)
{
    const decoded_frame frame = decode_raw_frame(raw);
    if (frame.head != k_frame_head)
    {
        return;
    }

    switch (frame.cmd)
    {
        case frame_cmd::read_one:
        {
            read_buffer.write(frame.data1);
            break;
        }
        case frame_cmd::read_two:
        {
            read_buffer.write(frame.data1);
            read_buffer.write(frame.data2);
            break;
        }
        case frame_cmd::write_one:
        {
            pending_addrs[0] = frame.data1;
            pending_addr_count = 1u;
            pending_value_index = 0u;
            state = decode_state::wait_mid_frame;
            break;
        }
        case frame_cmd::write_two:
        {
            pending_addrs[0] = frame.data1;
            pending_addrs[1] = frame.data2;
            pending_addr_count = 2u;
            pending_value_index = 0u;
            state = decode_state::wait_mid_frame;
            break;
        }
        case frame_cmd::streamtransfer:
        {
            stream_transfer_on = true;
            break;
        }
        case frame_cmd::stop:
        {
            stream_transfer_on = false;
            break;
        }
        case frame_cmd::empty:
        default:
        {
            break;
        }
    }
}

void spi_decode::handle_mid_frame_value(uint32_t raw)
{
    if (pending_value_index < pending_addr_count)
    {
        write_cmd cmd{};
        cmd.addr = pending_addrs[pending_value_index];
        cmd.value = raw;
        write_buffer.write(cmd);
        ++pending_value_index;
    }

    if (pending_value_index >= pending_addr_count)
    {
        clear_pending_write_context();
    }
}

void spi_decode::drain_read_buffer_to_scb()
{
    bool processed = false;
    while (read_buffer.isNew() != 0u)
    {
        const uint8_t addr = read_buffer.read();
        const register_meta* meta = find_entry(addr);

        if ((meta == nullptr) || (!meta->readable))
        {
            continue;
        }
        uint32_t a = read_register_as_u32(*meta);
        scb_fifo.send(a);
        SEGGER_RTT_printf(0,"%X \n",a);
        processed = true;
    }

    if (processed)
    {
        gpio_read_feedback.toggle();
    }
}

void spi_decode::drain_write_buffer_to_registers()
{
    while (write_buffer.isNew() != 0u)
    {
        const write_cmd cmd = write_buffer.read();
        register_meta* meta = find_entry(cmd.addr);

        if ((meta == nullptr) || (!meta->writable))
        {
            continue;
        }

        write_u32_to_register(*meta, cmd.value);
    }
}

uint32_t spi_decode::emit_read_value_by_addr(uint8_t addr)
{
    const register_meta* meta = find_entry(addr);
    if ((meta == nullptr) || (!meta->readable))
    {
        return 0;
    }

    return read_register_as_u32(*meta);
}

bool spi_decode::register_entry(uint8_t addr, void* value_ptr, value_type type, bool readable, bool writable)
{
    if (value_ptr == nullptr)
    {
        return false;
    }

    register_meta* old = find_entry(addr);
    if (old != nullptr)
    {
        old->value_ptr = value_ptr;
        old->type = type;
        old->readable = readable;
        old->writable = writable;
        old->used = true;
        return true;
    }

    for (uint8_t i = 0u; i < k_max_register_count; ++i)
    {
        if (!reg_table[i].used)
        {
            reg_table[i].addr = addr;
            reg_table[i].value_ptr = value_ptr;
            reg_table[i].type = type;
            reg_table[i].readable = readable;
            reg_table[i].writable = writable;
            reg_table[i].used = true;
            return true;
        }
    }

    return false;
}

spi_decode::register_meta* spi_decode::find_entry(uint8_t addr)
{
    for (uint8_t i = 0u; i < k_max_register_count; ++i)
    {
        if (reg_table[i].used && (reg_table[i].addr == addr))
        {
            return &reg_table[i];
        }
    }

    return nullptr;
}

const spi_decode::register_meta* spi_decode::find_entry(uint8_t addr) const
{
    for (uint8_t i = 0u; i < k_max_register_count; ++i)
    {
        if (reg_table[i].used && (reg_table[i].addr == addr))
        {
            return &reg_table[i];
        }
    }

    return nullptr;
}

uint32_t spi_decode::read_register_as_u32(const register_meta& meta)
{
    switch (meta.type)
    {
        case value_type::u8:
        {
            return static_cast<uint32_t>(*static_cast<const uint8_t*>(meta.value_ptr));
        }
        case value_type::i8:
        {
            return static_cast<uint32_t>(static_cast<uint8_t>(*static_cast<const int8_t*>(meta.value_ptr)));
        }
        case value_type::u16:
        {
            return static_cast<uint32_t>(*static_cast<const uint16_t*>(meta.value_ptr));
        }
        case value_type::i16:
        {
            return static_cast<uint32_t>(static_cast<uint16_t>(*static_cast<const int16_t*>(meta.value_ptr)));
        }
        case value_type::u32:
        {
            return *static_cast<const uint32_t*>(meta.value_ptr);
        }
        case value_type::i32:
        {
            return static_cast<uint32_t>(*static_cast<const int32_t*>(meta.value_ptr));
        }
        case value_type::f32:
        {
            uint32_t raw = 0u;
            const float value = *static_cast<const float*>(meta.value_ptr);
            std::memcpy(&raw, &value, sizeof(raw));
            return raw;
        }
        default:
        {
            return 0u;
        }
    }
}

void spi_decode::write_u32_to_register(register_meta& meta, uint32_t raw)
{
    switch (meta.type)
    {
        case value_type::u8:
        {
            *static_cast<uint8_t*>(meta.value_ptr) = static_cast<uint8_t>(raw);
            break;
        }
        case value_type::i8:
        {
            *static_cast<int8_t*>(meta.value_ptr) = static_cast<int8_t>(raw);
            break;
        }
        case value_type::u16:
        {
            *static_cast<uint16_t*>(meta.value_ptr) = static_cast<uint16_t>(raw);
            break;
        }
        case value_type::i16:
        {
            *static_cast<int16_t*>(meta.value_ptr) = static_cast<int16_t>(raw);
            break;
        }
        case value_type::u32:
        {
            *static_cast<uint32_t*>(meta.value_ptr) = raw;
            break;
        }
        case value_type::i32:
        {
            *static_cast<int32_t*>(meta.value_ptr) = static_cast<int32_t>(raw);
            break;
        }
        case value_type::f32:
        {
            float value = 0.0f;
            std::memcpy(&value, &raw, sizeof(value));
            *static_cast<float*>(meta.value_ptr) = value;
            break;
        }
        default:
        {
            break;
        }
    }
}

void spi_decode::clear_pending_write_context()
{
    pending_addrs[0] = 0u;
    pending_addrs[1] = 0u;
    pending_addr_count = 0u;
    pending_value_index = 0u;
    state = decode_state::wait_head;
}

void spi_decode::clear_register_table()
{
    for (uint8_t i = 0u; i < k_max_register_count; ++i)
    {
        reg_table[i].addr = 0u;
        reg_table[i].value_ptr = nullptr;
        reg_table[i].type = value_type::u32;
        reg_table[i].readable = false;
        reg_table[i].writable = false;
        reg_table[i].used = false;
    }
}
