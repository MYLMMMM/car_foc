#pragma once

#include <cstddef>

/**
 * @brief 一阶低通滤波器(纯滤波)
 * @details
 *   y[n] = alpha * x[n] + (1 - alpha) * y[n-1]
 *   alpha = 2*pi*fc*Ts / (2*pi*fc*Ts + 1)
 */
template<typename data_type>
class LPF {
public:
    data_type &input;            // 输入: 待滤波原始值
    data_type &control_period_s; // 输入: 控制周期(s)
    data_type &cutoff_freq;      // 输入/可调: 截止频率(Hz)
    data_type &output;           // 输出: 滤波后值

    const data_type TWO_PI = static_cast<data_type>(6.2831853071795864769);
    const data_type ONE = static_cast<data_type>(1.0);

    explicit LPF(data_type &input,
                 data_type &control_period_s,
                 data_type &cutoff_freq,
                 data_type &output)
        : input(input),
          control_period_s(control_period_s),
          cutoff_freq(cutoff_freq),
          output(output),
          initialized_(false) {}

    LPF(const LPF&) = delete;
    LPF& operator=(const LPF&) = delete;
    LPF(LPF&&) = delete;
    LPF& operator=(LPF&&) = delete;
    void* operator new(size_t) = delete;
    void operator delete(void*) = delete;

    /**
     * @brief 执行一次一阶低通滤波
     */
    void trg() {
        const data_type dt = control_period_s;
        if (dt <= static_cast<data_type>(0)) {
            output = static_cast<data_type>(0);
            return;
        }

        // alpha = 2*pi*fc*Ts / (2*pi*fc*Ts + 1)
        data_type alpha = TWO_PI * cutoff_freq * dt;
        alpha = alpha / (alpha + ONE);

        if (!initialized_) {
            output = input;
            initialized_ = true;
        } else {
            output = alpha * input + (ONE - alpha) * output;
        }
    }

    /**
     * @brief 重置滤波器状态
     */
    void reset() {
        initialized_ = false;
    }

private:
    bool initialized_;
};
