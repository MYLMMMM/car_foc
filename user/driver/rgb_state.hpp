#pragma once

#include <array>
#include <cstdint>
#include "chips/XL2020RGBC.hpp"

struct StateColor {
    uint16_t state;
    uint8_t  r;
    uint8_t  g;
    uint8_t  b;
};

template <size_t N>
class RGB_State {
    XL202RGBC&                        led_;
    const std::array<StateColor, N>&  map_;

public:
    constexpr RGB_State(XL202RGBC& led, const std::array<StateColor, N>& map)
        : led_(led), map_(map) {}

    void set_state(uint16_t state) {
        for (const auto& entry : map_) {
            if (entry.state == state) {
                led_.set_color(entry.r, entry.g, entry.b);
                return;
            }
        }
    }
};
