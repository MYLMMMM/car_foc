#pragma once

#include <cstddef>

/**
 * @brief 基于机械角测量的一维角度-速度二状态卡尔曼滤波器
 * @details
 * 状态: x = [theta_unwrap, omega]^T
 * 观测: z = theta_unwrap
 */
template<typename data_type>
class KalmanThetaSpeed {
public:
    data_type &theta_mech;       // 输入: 当前机械角测量(rad), 归一化到 [0, 2pi)
    data_type &last_mech;        // 状态: 上一次机械角测量(rad), 归一化到 [0, 2pi)
    data_type &control_period_s; // 输入: 控制周期(s)
    data_type &q_theta;          // 输入/可调: 角度状态过程噪声
    data_type &q_speed;          // 输入/可调: 速度状态过程噪声
    data_type &r_theta;          // 输入/可调: 角度观测噪声
    data_type &speed_mech;       // 输出: 机械角速度估计(rad/s)

    const data_type PI = static_cast<data_type>(3.14159265358979323846);
    const data_type TWO_PI = static_cast<data_type>(6.2831853071795864769);

    explicit KalmanThetaSpeed(data_type &theta_mech,
                              data_type &last_mech,
                              data_type &control_period_s,
                              data_type &q_theta,
                              data_type &q_speed,
                              data_type &r_theta,
                              data_type &speed_mech)
        : theta_mech(theta_mech),
          last_mech(last_mech),
          control_period_s(control_period_s),
          q_theta(q_theta),
          q_speed(q_speed),
          r_theta(r_theta),
          speed_mech(speed_mech),
          initialized_(false),
          x_theta_(0),
          x_speed_(0),
          meas_theta_unwrap_(0),
          p00_(1),
          p01_(0),
          p10_(0),
          p11_(1) {}

    KalmanThetaSpeed(const KalmanThetaSpeed&) = delete;
    KalmanThetaSpeed& operator=(const KalmanThetaSpeed&) = delete;
    KalmanThetaSpeed(KalmanThetaSpeed&&) = delete;
    KalmanThetaSpeed& operator=(KalmanThetaSpeed&&) = delete;
    void* operator new(size_t) = delete;
    void operator delete(void*) = delete;

    /**
     * @brief 执行一次卡尔曼滤波更新
     */
    void trg() {
        if (!initialized_) {
            init_state_();
            return;
        }

        const data_type dt = control_period_s;
        if (dt <= static_cast<data_type>(0)) {
            speed_mech = static_cast<data_type>(0);
            last_mech = theta_mech;
            return;
        }

        // 1) 机械角观测解缠绕，得到连续角度 z
        data_type dtheta = theta_mech - last_mech;
        if (dtheta > PI) {
            dtheta -= TWO_PI;
        } else if (dtheta < -PI) {
            dtheta += TWO_PI;
        }
        meas_theta_unwrap_ += dtheta;
        const data_type z = meas_theta_unwrap_;
        last_mech = theta_mech;

        // 2) 预测 x^- = A x, 其中 A = [[1, dt], [0, 1]]
        const data_type x_theta_pred = x_theta_ + dt * x_speed_;
        const data_type x_speed_pred = x_speed_;

        // P^- = A P A^T + Q
        const data_type p00_pred = p00_ + dt * (p01_ + p10_) + dt * dt * p11_ + q_theta;
        const data_type p01_pred = p01_ + dt * p11_;
        const data_type p10_pred = p10_ + dt * p11_;
        const data_type p11_pred = p11_ + q_speed;

        // 3) 更新, H = [1, 0]
        const data_type s = p00_pred + r_theta;
        if (s <= static_cast<data_type>(1e-9f)) {
            x_theta_ = x_theta_pred;
            x_speed_ = x_speed_pred;
            p00_ = p00_pred;
            p01_ = p01_pred;
            p10_ = p10_pred;
            p11_ = p11_pred;
            speed_mech = x_speed_;
            return;
        }

        const data_type k0 = p00_pred / s;
        const data_type k1 = p10_pred / s;
        const data_type y = z - x_theta_pred;  // innovation

        x_theta_ = x_theta_pred + k0 * y;
        x_speed_ = x_speed_pred + k1 * y;

        p00_ = (static_cast<data_type>(1) - k0) * p00_pred;
        p01_ = (static_cast<data_type>(1) - k0) * p01_pred;
        p10_ = p10_pred - k1 * p00_pred;
        p11_ = p11_pred - k1 * p01_pred;

        speed_mech = x_speed_;
    }

    /**
     * @brief 重置滤波器状态
     */
    void reset() {
        initialized_ = false;
        init_state_();
    }

private:
    bool initialized_;
    data_type x_theta_;
    data_type x_speed_;
    data_type meas_theta_unwrap_;
    data_type p00_;
    data_type p01_;
    data_type p10_;
    data_type p11_;

    void init_state_() {
        x_theta_ = theta_mech;
        x_speed_ = static_cast<data_type>(0);
        meas_theta_unwrap_ = theta_mech;
        p00_ = static_cast<data_type>(1);
        p01_ = static_cast<data_type>(0);
        p10_ = static_cast<data_type>(0);
        p11_ = static_cast<data_type>(1);
        speed_mech = static_cast<data_type>(0);
        last_mech = theta_mech;
        initialized_ = true;
    }
};
