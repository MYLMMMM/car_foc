#pragma once

#include "hal.hpp"

class XL202RGBC
{
    hal_spi& spi_;
    uint32_t R_;
    uint32_t G_;
    uint32_t B_;

public:
    XL202RGBC(hal_spi& spi):spi_(spi),R_(0),G_(0),B_(0){}
    void set_color(uint8_t R,uint8_t G,uint8_t B)
    {
        R_ = R;
        G_ = G;
        B_ = B;
        const uint8_t grb[3] = {
            static_cast<uint8_t>(G_),
            static_cast<uint8_t>(R_),
            static_cast<uint8_t>(B_)
        };

        uint32_t msg[4] = {0u, 0u, 0u, 0u};
        uint32_t frame = 0u;
        uint8_t bit_count = 0u;
        uint8_t frame_idx = 0u;

        for (uint8_t color_idx = 0u; color_idx < 3u; ++color_idx)
        {
            for (int8_t bit = 7; bit >= 0; --bit)
            {
                const uint32_t bit_value = (grb[color_idx] >> bit) & 0x01u;
                const uint32_t encoded = (bit_value != 0u) ? 0xEu : 0x8u;
                frame = (frame << 4) | encoded;
                bit_count = static_cast<uint8_t>(bit_count + 4u);

                if (bit_count == 24u)
                {
                    msg[frame_idx] = frame;
                    frame = 0u;
                    bit_count = 0u;
                    ++frame_idx;
                }
            }
        }

        for (uint8_t i = 0u; i < 4u; ++i)
        {
            spi_.send(msg[i]);
        }
    }
}; 
