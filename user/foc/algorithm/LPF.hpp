#pragma once

#include <cstddef>

/**
 * @brief 一阶低通滤波器，用于速度估计
 * @details
 * 从机械角差分得到原始速度，再经一阶 IIR 低通滤波:
 *   y[n] = alpha * x[n] + (1 - alpha) * y[n-1]
 *   alpha = 2*pi*fc*Ts / (2*pi*fc*Ts + 1)
 */
template<typename data_type>
class LPF {
public:
    data_type &theta_mech;       // 输入: 当前机械角测量(rad), 归一化到 [0, 2pi)
    data_type &last_mech;        // 状态: 上一次机械角测量(rad)
    data_type &control_period_s; // 输入: 控制周期(s)
    data_type &cutoff_freq;      // 输入/可调: 截止频率(Hz)
    data_type &speed_mech;       // 输出: 滤波后机械角速度(rad/s)

    const data_type PI = static_cast<data_type>(3.14159265358979323846);
    const data_type TWO_PI = static_cast<data_type>(6.2831853071795864769);
    const data_type ONE = static_cast<data_type>(1.0);

    explicit LPF(data_type &theta_mech,
                 data_type &last_mech,
                 data_type &control_period_s,
                 data_type &cutoff_freq,
                 data_type &speed_mech)
        : theta_mech(theta_mech),
          last_mech(last_mech),
          control_period_s(control_period_s),
          cutoff_freq(cutoff_freq),
          speed_mech(speed_mech),
          initialized_(false) {}

    LPF(const LPF&) = delete;
    LPF& operator=(const LPF&) = delete;
    LPF(LPF&&) = delete;
    LPF& operator=(LPF&&) = delete;
    void* operator new(size_t) = delete;
    void operator delete(void*) = delete;

    /**
     * @brief 执行一次低通滤波速度估计
     */
    void trg() {
        const data_type dt = control_period_s;
        if (dt <= static_cast<data_type>(0)) {
            speed_mech = static_cast<data_type>(0);
            last_mech = theta_mech;
            return;
        }

        // 1) 机械角解缠绕，计算角度差
        data_type dtheta = theta_mech - last_mech;
        if (dtheta > PI) {
            dtheta -= TWO_PI;
        } else if (dtheta < -PI) {
            dtheta += TWO_PI;
        }
        last_mech = theta_mech;

        // 2) 原始速度 = dtheta / dt
        data_type speed_raw = dtheta / dt;

        // 3) 一阶低通滤波
        // alpha = 2*pi*fc*Ts / (2*pi*fc*Ts + 1)
        data_type alpha = TWO_PI * cutoff_freq * dt;
        alpha = alpha / (alpha + ONE);

        if (!initialized_) {
            speed_mech = speed_raw;
            initialized_ = true;
        } else {
            speed_mech = alpha * speed_raw + (ONE - alpha) * speed_mech;
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
