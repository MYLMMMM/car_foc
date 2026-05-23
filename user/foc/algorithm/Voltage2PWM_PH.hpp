#pragma once

#include <cstddef>

/**
 * @brief 指令电压到单路 PWM 占空比 + 方向 (PH/EN H桥驱动)
 * @details 输入可正可负的指令电压与母线电压，
 *          正电压 → direction=正向, duty=|V|/Vbus
 *          负电压 → direction=反向, duty=|V|/Vbus
 *          适用于 DRV8701 等 PH/EN 模式栅极驱动器。
 */
template<typename data_type>
class Voltage2PWM_PH {
public:
    data_type &voltage;     // 输入: 指令电压(V), 可正可负
    data_type &v_bus;       // 输入: 母线电压(V)
    data_type &duty;        // 输出: PWM 占空比 [0, 1]
    bool &direction;        // 输出: 方向, true=正向, false=反向

    /**
     * @brief 构造电压到 PWM+PH 转换模块
     * @param voltage 指令电压输入引用(V)
     * @param v_bus 母线电压输入引用(V)
     * @param duty 占空比输出引用 [0, 1]
     * @param direction 方向输出引用
     */
    explicit Voltage2PWM_PH(data_type &voltage, data_type &v_bus,
                            data_type &duty, bool &direction)
        : voltage(voltage), v_bus(v_bus), duty(duty), direction(direction) {}

    Voltage2PWM_PH(const Voltage2PWM_PH&) = delete;
    Voltage2PWM_PH& operator=(const Voltage2PWM_PH&) = delete;
    Voltage2PWM_PH(Voltage2PWM_PH&&) = delete;
    Voltage2PWM_PH& operator=(Voltage2PWM_PH&&) = delete;
    void* operator new(size_t) = delete;
    void operator delete(void*) = delete;

    /**
     * @brief 触发电压到 PWM+PH 转换
     * @details 正电压: direction=true,  duty=clamp(voltage/v_bus, 0, 1)
     *          负电压: direction=false, duty=clamp(|voltage|/v_bus, 0, 1)
     */
    void trg() {
        // 母线电压无效时输出 0
        if (v_bus <= static_cast<data_type>(0)) {
            duty = static_cast<data_type>(0);
            direction = true;
            return;
        }

        if (voltage >= static_cast<data_type>(0)) {
            // 正电压: 正向
            direction = true;
            data_type d = voltage / v_bus;
            if (d > static_cast<data_type>(1)) {
                d = static_cast<data_type>(1);
            }
            duty = d;
        } else {
            // 负电压: 反向
            direction = false;
            data_type d = (-voltage) / v_bus;
            if (d > static_cast<data_type>(1)) {
                d = static_cast<data_type>(1);
            }
            duty = d;
        }
    }
};
