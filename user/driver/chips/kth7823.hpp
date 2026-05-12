#pragma once

#include <cstdint>

#include "hal.hpp"

class kth7823
{
public:
    struct regist_map
    {
        uint8_t ZERO_low;//0x00
        uint8_t ZERO_high;
        uint8_t GAINtirm;
        uint8_t trim;
        uint8_t ABZ_config;
        uint8_t PPT;
        uint8_t MGHL;
        uint8_t NPP_cfg;
        uint8_t ABZ_LIMIT;
        uint8_t RD;//0x09
    } internel_map;

    enum command : uint16_t
    {
        write = (0b10 << 14),
        read  = (0b01 << 14)
    };

    enum addr : uint16_t
    {
        ZERO_low   = (0u << 8),
        ZERO_high  = (1u << 8),
        GAINtirm   = (2u << 8),
        trim       = (3u << 8),
        ABZ_config = (4u << 8),
        PPT        = (5u << 8),
        MGHL       = (6u << 8),
        NPP_cfg    = (7u << 8),
        ABZ_LIMIT  = (8u << 8),
        RD         = (9u << 8)
    };

    bool DMA_state;//0 is dma poit to read_cfg_buffer and cfg mode.1 is dma poit to data buffer ,running mode.handle by hand.

    kth7823(const regist_map init_map, hal_spi& spi)
        : internel_map(init_map),
          DMA_state(false),
          spi_(spi)
    {
    }

    uint16_t msg_pack(command com, addr addr_, uint8_t value)
    {
       return static_cast<uint16_t>(static_cast<uint16_t>(com) |
                                    static_cast<uint16_t>(addr_) |
                                    static_cast<uint16_t>(value));
    }

    uint8_t msg_unpack(uint16_t msg)
    {
        return static_cast<uint8_t>(msg >> 8);
    }

    void init()
    {
        spi_.clear_rx();

        for (int a = 0; a <= 9; ++a)
        {
            spi_.send(msg_pack(read, static_cast<addr>(a << 8), 0u));
        }
        spi_.send(255u);

        int send_msg_count = 0;
        for (int a = 0; a <= 9; ++a)
        {
            while (spi_.isnew() == 0u) {}

            const uint8_t msg = msg_unpack(static_cast<uint16_t>(spi_.recive()));
            if (*(((uint8_t*)&internel_map) + a) != msg)
            {
                spi_.send(msg_pack(write,
                                   static_cast<addr>(a << 8),
                                   *(((uint8_t*)&internel_map) + a)));
                ++send_msg_count;
            }
        }

        spi_.send(255u);

        while (static_cast<int>(spi_.isnew()) < send_msg_count) {}
        while (spi_.isnew() != 0u)
        {
            (void)spi_.recive();
        }
    }

    void set_zero_position(uint16_t zero_position)
    {
        spi_.send(msg_pack(write, ZERO_high, static_cast<uint8_t>(zero_position >> 8)));
        spi_.send(msg_pack(write, ZERO_low, static_cast<uint8_t>(zero_position)));
        spi_.send(65535u);

        //wait transfer done and clean rxbuffer
        while (spi_.isnew() < 3u) {}
        while (spi_.isnew() != 0u)
        {
            (void)spi_.recive();
        }
    }

    void set_direction(bool dir)
    {
        if(dir == true)spi_.send(msg_pack(write,RD,0b10000000));
        else          spi_.send(msg_pack(write,RD,0b0));
    }

    void start_yaw_data_transfer()
    {
        spi_.send(0u);
    }

    void stop_transfer()
    {
        spi_.send(65535u);
    }

    hal_spi& spi_;
};
