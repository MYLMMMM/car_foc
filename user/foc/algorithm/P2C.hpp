#pragma once

#include <cstddef>

/**
 * @brief 占空比到比较寄存器值转换
 */
template<typename data_typef, typename data_typei>
class P2C {
public:
    data_typef &duty_percent;   // 输入: 占空比，期望范围 [0, 1]
    data_typei &timer_period;   // 输入: 定时器周期 ARR
    data_typei &compare_value;  // 输出: 比较寄存器 CCR

    /**
     * @brief 构造 P2C 模块
     * @param duty_percent 输入占空比引用
     * @param timer_period 输入 ARR 引用
     * @param compare_value 输出 CCR 引用
     */
    explicit P2C(data_typef &duty_percent, data_typei &timer_period, data_typei &compare_value)
        : duty_percent(duty_percent), timer_period(timer_period), compare_value(compare_value) {}

    P2C(const P2C&) = delete;
    P2C& operator=(const P2C&) = delete;
    P2C(P2C&&) = delete;
    P2C& operator=(P2C&&) = delete;
    void* operator new(size_t) = delete;
    void operator delete(void*) = delete;

    /**
     * @brief 触发占空比到比较值转换
     * @details compare_value = clamp(duty_percent * timer_period, 0, timer_period)
     */
    void trg() {
        // 无效 ARR 直接输出 0
        if (timer_period <= static_cast<data_typei>(0)) {
            compare_value = static_cast<data_typei>(0);
            return;
        }

        // 先按浮点计算，再转换为比较值
        const data_typef period_f = static_cast<data_typef>(timer_period);
        const data_typef compare_f = (duty_percent) * (period_f);

        // 输出限幅到 [0, timer_period]
        if (compare_f <= static_cast<data_typef>(0)) {
            compare_value = static_cast<data_typei>(0);
        } else if (compare_f >= period_f) {
            compare_value = timer_period;
        } else {
            compare_value = static_cast<data_typei>(compare_f);
        }
    }
};
