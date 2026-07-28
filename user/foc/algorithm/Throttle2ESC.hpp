#pragma once

#include <cstddef>

/**
 * @brief 油门到 ESC 脉宽转换模块
 * @details 将油门 [0, 1] 转换为 ESC 脉宽比较寄存器值。
 *          ESC 信号: 50Hz(10ms 周期), 1ms=0%油门, 2ms=100%油门.
 *          PWM 时钟 240MHz DIVBY_1 → 1ms=240000 ticks, 2ms=480000 ticks.
 *          公式: ccr = 240000 * (1 + throttle), clamp 在 [240000, 480000].
 */
template<typename data_typef, typename data_typei>
class Throttle2ESC {
public:
    data_typef &throttle;       // 输入: 油门 [0, 1]
    data_typei &ccr_esc;        // 输出: ESC 比较寄存器值

    // 使用非 volatile 类型定义常量，避免 volatile 算术错误
    using raw_type = uint32_t;
    static constexpr raw_type kMinPulse = 240000;   // 1ms 脉宽对应 tick
    static constexpr raw_type kMaxPulse = 480000;   // 2ms 脉宽对应 tick
    static constexpr raw_type kPulseRange = kMaxPulse - kMinPulse;  // 240000

    /**
     * @brief 构造油门到 ESC 转换模块
     * @param throttle 油门输入引用 [0, 1]
     * @param ccr_esc ESC 比较寄存器输出引用
     */
    explicit Throttle2ESC(data_typef &throttle, data_typei &ccr_esc)
        : throttle(throttle), ccr_esc(ccr_esc) {}

    Throttle2ESC(const Throttle2ESC&) = delete;
    Throttle2ESC& operator=(const Throttle2ESC&) = delete;
    Throttle2ESC(Throttle2ESC&&) = delete;
    Throttle2ESC& operator=(Throttle2ESC&&) = delete;
    void* operator new(size_t) = delete;
    void operator delete(void*) = delete;

    /**
     * @brief 触发油门到 ESC CCR 转换
     * @details ccr_esc = clamp(240000 * (1 + throttle), 240000, 480000)
     */
    void trg() {
        if (throttle <= static_cast<data_typef>(0)) {
            ccr_esc = static_cast<data_typei>(kMinPulse);
            return;
        }
        if (throttle >= static_cast<data_typef>(1)) {
            ccr_esc = static_cast<data_typei>(kMaxPulse);
            return;
        }
        ccr_esc = static_cast<data_typei>(
            static_cast<data_typef>(kMinPulse) +
            throttle * static_cast<data_typef>(kPulseRange)
        );
    }
};
