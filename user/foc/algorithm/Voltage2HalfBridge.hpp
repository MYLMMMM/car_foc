#pragma once

#include <cstddef>

/**
 * @brief 指令电压到半桥双路占空比转换 (Sign-Magnitude H桥驱动)
 * @details 输入可正可负的指令电压与母线电压，
 *          正电压驱动 duty_a，负电压驱动 duty_b，另一路始终为 0。
 */
template<typename data_type>
class Voltage2HalfBridge {
public:
    data_type &voltage;   // 输入: 指令电压(V), 可正可负
    data_type &v_bus;     // 输入: 母线电压(V)
    data_type &duty_a;    // 输出: 半桥 A 占空比 [0, 1]
    data_type &duty_b;    // 输出: 半桥 B 占空比 [0, 1]

    /**
     * @brief 构造电压到半桥占空比转换模块
     * @param voltage 指令电压输入引用(V)
     * @param v_bus 母线电压输入引用(V)
     * @param duty_a 半桥 A 占空比输出引用 [0, 1]
     * @param duty_b 半桥 B 占空比输出引用 [0, 1]
     */
    explicit Voltage2HalfBridge(data_type &voltage, data_type &v_bus,
                                data_type &duty_a, data_type &duty_b)
        : voltage(voltage), v_bus(v_bus), duty_a(duty_a), duty_b(duty_b) {}

    Voltage2HalfBridge(const Voltage2HalfBridge&) = delete;
    Voltage2HalfBridge& operator=(const Voltage2HalfBridge&) = delete;
    Voltage2HalfBridge(Voltage2HalfBridge&&) = delete;
    Voltage2HalfBridge& operator=(Voltage2HalfBridge&&) = delete;
    void* operator new(size_t) = delete;
    void operator delete(void*) = delete;

    /**
     * @brief 触发电压到半桥占空比转换
     * @details 正电压: duty_a = clamp(|voltage|/v_bus, 0, 1), duty_b = 0
     *          负电压: duty_b = clamp(|voltage|/v_bus, 0, 1), duty_a = 0
     */
    void trg() {
        // 母线电压无效时输出 0
        if (v_bus <= static_cast<data_type>(0)) {
            duty_a = static_cast<data_type>(0);
            duty_b = static_cast<data_type>(0);
            return;
        }

        data_type duty;

        if (voltage >= static_cast<data_type>(0)) {
            // 正电压: 驱动 A 路
            duty = voltage / v_bus;
            if (duty > static_cast<data_type>(1)) {
                duty = static_cast<data_type>(1);
            }
            duty_a = duty;
            duty_b = static_cast<data_type>(0);
        } else {
            // 负电压: 驱动 B 路
            duty = (-voltage) / v_bus;
            if (duty > static_cast<data_type>(1)) {
                duty = static_cast<data_type>(1);
            }
            duty_a = static_cast<data_type>(0);
            duty_b = duty;
        }
    }
};
