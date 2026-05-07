#pragma once

#include <cstddef>

/**
 * @brief 机械角到机械速度估算
 * @details 通过相邻周期机械角差分计算速度，自动处理 0~2pi 周期跳变。
 */
template<typename data_type>
class Mech2Speed {
public:
    data_type &theta_mech;       // 输入: 当前机械角(rad), 范围 [0, 2pi)
    data_type &last_mech;        // 输入/状态: 上次机械角(rad)
    data_type &control_period_s; // 输入: 控制周期(s)
    data_type &speed_mech;       // 输出: 机械角速度(rad/s)

    const data_type PI = static_cast<data_type>(3.14159265358979323846);
    const data_type TWO_PI = static_cast<data_type>(6.2831853071795864769);

    explicit Mech2Speed(data_type &theta_mech,
                        data_type &last_mech,
                        data_type &control_period_s,
                        data_type &speed_mech)
        : theta_mech(theta_mech),
          last_mech(last_mech),
          control_period_s(control_period_s),
          speed_mech(speed_mech) {}

    Mech2Speed(const Mech2Speed&) = delete;
    Mech2Speed& operator=(const Mech2Speed&) = delete;
    Mech2Speed(Mech2Speed&&) = delete;
    Mech2Speed& operator=(Mech2Speed&&) = delete;
    void* operator new(size_t) = delete;
    void operator delete(void*) = delete;

    /**
     * @brief 触发一次机械速度估算
     */
    void trg() {
        data_type dtheta = theta_mech - last_mech;

        // 跨零点时将角差折返到 [-pi, pi]，避免速度突变
        if (dtheta > PI) {
            dtheta -= TWO_PI;
        } else if (dtheta < -PI) {
            dtheta += TWO_PI;
        }

        if (control_period_s > static_cast<data_type>(0)) {
            speed_mech = dtheta / control_period_s;
        } else {
            speed_mech = static_cast<data_type>(0);
        }

        last_mech = theta_mech;
    }

    /**
     * @brief 重置内部状态
     */
    void reset() {
        last_mech = theta_mech;
        speed_mech = static_cast<data_type>(0);
    }
};
