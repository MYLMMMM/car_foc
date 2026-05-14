#pragma once

#include <stdint.h>
#include <cstddef>
#include "algorithm/ADC2Current.hpp"
#include "algorithm/ADC2Voltage.hpp"
#include "algorithm/Clark.hpp"
#include "algorithm/Park.hpp"
#include "algorithm/PID.hpp"
#include "algorithm/InversePark.hpp"
#include "algorithm/SVPWM.hpp"
#include "algorithm/P2C.hpp"
#include "algorithm/Encoder2Mech.hpp"
#include "algorithm/KalmanThetaSpeed.hpp"
#include "algorithm/Mech2Elec.hpp"
#include "algorithm/CircularMeanFilter.hpp"

using adc_reg = volatile int32_t;
using pwm_reg = volatile uint32_t;

struct foc_motor_datastructure_config
{
    /* interface with hardware */
    adc_reg* adc_a;
    adc_reg* adc_b;
    adc_reg* adc_c;
    adc_reg* adc_vbus;


    /* config value */
    int16_t adc_zero_a;
    int16_t adc_zero_b;
    int16_t adc_zero_c;
    float adc_vref;
    int16_t adc_full_scale;
    float vbus_divider_ratio;
    float shunt_resistance;
    float current_sense_gain;

    uint32_t encoder_cpr;
    uint32_t pole_pairs;
    float theta_elec_offset;

    float pid_d_kp;
    float pid_d_ki;
    float pid_d_kd;
    float pid_d_integral_limit;
    float pid_q_kp;
    float pid_q_ki;
    float pid_q_kd;
    float pid_q_integral_limit;
    float pid_speed_kp;
    float pid_speed_ki;
    float pid_speed_kd;
    float pid_speed_integral_limit;
    float kf_q_theta;
    float kf_q_speed;
    float kf_r_theta;

    float control_period_s;
    uint32_t speed_loop_div;

    uint32_t pwm_period;
};

struct foc_motor_datastructure
{
    /* interface with hardware */
    adc_reg& adc_a;      // ADC A 相寄存器原始值
    adc_reg& adc_b;      // ADC B 相寄存器原始值
    adc_reg& adc_c;      // ADC C 相寄存器原始值
    adc_reg& adc_vbus;   // ADC 母线电压原始值

    pwm_reg ccr_a = 0;      // PWM A 相比较寄存器值
    pwm_reg ccr_b = 0;      // PWM B 相比较寄存器值
    pwm_reg ccr_c = 0;      // PWM C 相比较寄存器值

    volatile uint32_t enc_a = 0;  // 编码器主计数原始值

    /* config value */
    int32_t adc_zero_a = 0;          // A 相零电流 ADC 偏置
    int32_t adc_zero_b = 0;          // B 相零电流 ADC 偏置
    int32_t adc_zero_c = 0;          // C 相零电流 ADC 偏置
    int32_t adc_full_scale = 0;      // ADC 满量程计数
    float adc_vref = 0.0f;           // ADC 参考电压(V)
    float vbus_divider_ratio = 0.0f; // 母线分压还原比例
    float shunt_resistance = 0.0f;   // 采样电阻(Ohm)
    float current_sense_gain = 0.0f; // 电流采样放大倍数

    uint32_t encoder_cpr = 0;        // 编码器每圈计数(CPR)
    uint32_t pole_pairs = 0;         // 电机极对数
    float theta_elec_offset = 0.0f;  // 电角偏置(rad)

    float pid_d_kp = 0.0f;           // d 轴 PID 比例系数
    float pid_d_ki = 0.0f;           // d 轴 PID 积分系数
    float pid_d_kd = 0.0f;           // d 轴 PID 微分系数
    float pid_d_integral_limit = 0.0f;  // d 轴 PID 积分限幅(绝对值, <=0 不限幅)
    float pid_q_kp = 0.0f;           // q 轴 PID 比例系数
    float pid_q_ki = 0.0f;           // q 轴 PID 积分系数
    float pid_q_kd = 0.0f;           // q 轴 PID 微分系数
    float pid_q_integral_limit = 0.0f;  // q 轴 PID 积分限幅(绝对值, <=0 不限幅)
    float pid_speed_kp = 0.0f;       // 速度环 PID 比例系数
    float pid_speed_ki = 0.0f;       // 速度环 PID 积分系数
    float pid_speed_kd = 0.0f;       // 速度环 PID 微分系数
    float pid_speed_integral_limit = 0.0f;  // 速度环 PID 积分限幅(绝对值, <=0 不限幅)
    float kf_q_theta = 1e-4f;        // 卡尔曼角度状态过程噪声
    float kf_q_speed = 1e-2f;        // 卡尔曼速度状态过程噪声
    float kf_r_theta = 5e-4f;        // 卡尔曼角度观测噪声

    float control_period_s = 0.0f;   // 控制周期(s)
    uint32_t speed_loop_div = 1u;    // 速度环降采样分频(每 N 次中断执行 1 次速度环)

    uint32_t pwm_period = 0;         // PWM 周期 ARR

    /* running value */
    float theta_mech = 0.0f;         // 机械角(rad)
    float last_mech = 0.0f;          // 上次机械角(rad)
    float speed_mech = 0.0f;         // 机械角速度(rad/s)
    float theta_elec = 0.0f;         // 电角(rad)
    float sin_theta_elec = 0.0f;     // sin(theta_elec)
    float cos_theta_elec = 1.0f;     // cos(theta_elec)

    float v_bus = 0.0f;              // 母线电压(V)
    float i_a = 0.0f;                // A 相电流(A)
    float i_b = 0.0f;                // B 相电流(A)
    float i_c = 0.0f;                // C 相电流(A)
    float i_alpha = 0.0f;            // alpha 轴电流(A)
    float i_beta = 0.0f;             // beta 轴电流(A)
    float i_d = 0.0f;                // d 轴电流(A)
    float i_q = 0.0f;                // q 轴电流(A)

    float v_d = 0.0f;                // d 轴电压指令(V)
    float v_q = 0.0f;                // q 轴电压指令(V)
    float v_alpha = 0.0f;            // alpha 轴电压指令(V)
    float v_beta = 0.0f;             // beta 轴电压指令(V)

    float t_a = 0.0f;                // A 相占空比
    float t_b = 0.0f;                // B 相占空比
    float t_c = 0.0f;                // C 相占空比

    float i_d_target = 0.0f;         // d 轴目标电流(A)
    float i_q_target = 0.0f;         // q 轴目标电流(A)
    float speed_target = 0.0f;       // 目标机械角速度(rad/s)
    uint32_t speed_loop_count = 0u;  // 速度环计数器(中断计数)

    explicit foc_motor_datastructure(const foc_motor_datastructure_config& cfg)
        : adc_a(*cfg.adc_a)
        , adc_b(*cfg.adc_b)
        , adc_c(*cfg.adc_c)
        , adc_vbus(*cfg.adc_vbus)
        , adc_zero_a(cfg.adc_zero_a)
        , adc_zero_b(cfg.adc_zero_b)
        , adc_zero_c(cfg.adc_zero_c)
        , adc_full_scale(cfg.adc_full_scale)
        , adc_vref(cfg.adc_vref)
        , vbus_divider_ratio(cfg.vbus_divider_ratio)
        , shunt_resistance(cfg.shunt_resistance)
        , current_sense_gain(cfg.current_sense_gain)
        , encoder_cpr(cfg.encoder_cpr)
        , pole_pairs(cfg.pole_pairs)
        , theta_elec_offset(cfg.theta_elec_offset)
        , pid_d_kp(cfg.pid_d_kp)
        , pid_d_ki(cfg.pid_d_ki)
        , pid_d_kd(cfg.pid_d_kd)
        , pid_d_integral_limit(cfg.pid_d_integral_limit)
        , pid_q_kp(cfg.pid_q_kp)
        , pid_q_ki(cfg.pid_q_ki)
        , pid_q_kd(cfg.pid_q_kd)
        , pid_q_integral_limit(cfg.pid_q_integral_limit)
        , pid_speed_kp(cfg.pid_speed_kp)
        , pid_speed_ki(cfg.pid_speed_ki)
        , pid_speed_kd(cfg.pid_speed_kd)
        , pid_speed_integral_limit(cfg.pid_speed_integral_limit)
        , kf_q_theta(cfg.kf_q_theta)
        , kf_q_speed(cfg.kf_q_speed)
        , kf_r_theta(cfg.kf_r_theta)
        , control_period_s(cfg.control_period_s)
        , speed_loop_div(cfg.speed_loop_div)
        , pwm_period(cfg.pwm_period)
    {
    }
};

class foc {
public:
    foc_motor_datastructure& motor;  // 外部注入的电机对象引用
private:
    Encoder2Mech<float, volatile uint32_t> encoder2mech;
    KalmanThetaSpeed<float> speed;
    Mech2Elec<float, uint32_t> mech2elec;
    ADC2Current<float, adc_reg> adc2current_a;
    ADC2Current<float, adc_reg> adc2current_b;
    ADC2Current<float, adc_reg> adc2current_c;
    ADC2Voltage<float, adc_reg> adc2voltage_vbus;
    Clark<float> clark;
    Park<float> park;
    PID<float> pid_speed;
    PID<float> pid_d;
    PID<float> pid_q;
    InversePark<float> inverse_park;
    SVPWM<float> svpwm;
    P2C<float, pwm_reg> p2c_a;
    P2C<float, pwm_reg> p2c_b;
    P2C<float, pwm_reg> p2c_c;
    float test_mech;

public:


    /**
     * @brief 构造 FOC 控制器
     * @param motor 外部电机对象引用
     */
    explicit foc(foc_motor_datastructure& motor)
        : motor(motor),
          encoder2mech(motor.enc_a, motor.encoder_cpr, motor.theta_mech),
          speed(motor.theta_mech, motor.last_mech, motor.control_period_s,
                motor.kf_q_theta, motor.kf_q_speed, motor.kf_r_theta, motor.speed_mech),
          mech2elec(motor.theta_mech, motor.pole_pairs, motor.theta_elec_offset,
                    motor.theta_elec, motor.sin_theta_elec, motor.cos_theta_elec),
          adc2current_a(motor.adc_a, motor.adc_zero_a, motor.adc_vref, motor.adc_full_scale,
                        motor.shunt_resistance, motor.current_sense_gain, motor.i_a),
          adc2current_b(motor.adc_b, motor.adc_zero_b, motor.adc_vref, motor.adc_full_scale,
                        motor.shunt_resistance, motor.current_sense_gain, motor.i_b),
          adc2current_c(motor.adc_c, motor.adc_zero_c, motor.adc_vref, motor.adc_full_scale,
                        motor.shunt_resistance, motor.current_sense_gain, motor.i_c),
          adc2voltage_vbus(motor.adc_vbus, motor.adc_vref, motor.adc_full_scale,
                           motor.vbus_divider_ratio, motor.v_bus),
          clark(motor.i_a, motor.i_b, motor.i_c, motor.i_alpha, motor.i_beta),
          park(motor.i_alpha, motor.i_beta, motor.sin_theta_elec, motor.cos_theta_elec, motor.i_d, motor.i_q),
          pid_speed(motor.pid_speed_kp, motor.pid_speed_ki, motor.pid_speed_kd,
                    motor.pid_speed_integral_limit, motor.speed_target, motor.speed_mech, motor.i_q_target),
          pid_d(motor.pid_d_kp, motor.pid_d_ki, motor.pid_d_kd, motor.pid_d_integral_limit,
                motor.i_d_target, motor.i_d, motor.v_d),
          pid_q(motor.pid_q_kp, motor.pid_q_ki, motor.pid_q_kd, motor.pid_q_integral_limit,
                motor.i_q_target, motor.i_q, motor.v_q),
          inverse_park(motor.v_q, motor.v_d, motor.sin_theta_elec, motor.cos_theta_elec, motor.v_alpha, motor.v_beta),
          svpwm(motor.v_alpha, motor.v_beta, motor.v_bus, motor.t_a, motor.t_b, motor.t_c),
          p2c_a(motor.t_a, motor.pwm_period, motor.ccr_a),
          p2c_b(motor.t_b, motor.pwm_period, motor.ccr_b),
          p2c_c(motor.t_c, motor.pwm_period, motor.ccr_c),
          test_mech(0) {}

    foc(const foc&) = delete;
    foc& operator=(const foc&) = delete;
    foc(foc&&) = delete;
    foc& operator=(foc&&) = delete;
    void* operator new(size_t) = delete;
    void operator delete(void*) = delete;

    foc_motor_datastructure& data() { return motor; }
    const foc_motor_datastructure& data() const { return motor; }

    /**
     * @brief 更新采样比例系数(电流 + 母线电压)
     * @details 修改采样电阻/增益/参考电压/满量程/分压比后调用
     */
    void update_current_scale() {
        adc2current_a.update_scale();
        adc2current_b.update_scale();
        adc2current_c.update_scale();
        adc2voltage_vbus.update_scale();
    }

    /**
     * @brief 清零速度环与 d/q 电流环 PID 内部积分状态
     */
    void reset_pid() {
        speed.reset();
        pid_speed.reset();
        pid_d.reset();
        pid_q.reset();
        motor.speed_loop_count = 0u;
    }

    /**
     * @brief 按标准顺序触发一次 FOC 计算
     */
    void trg() {
        // encoder2mech.trg();
        speed.trg();

        // const uint32_t speed_div = (motor.speed_loop_div == 0u) ? 1u : motor.speed_loop_div;
        // motor.speed_loop_count++;
        // if (motor.speed_loop_count >= speed_div) {
        //     motor.speed_loop_count = 0u;
        //     pid_speed.trg();
        // }

        // mech2elec.trg();

        adc2current_a.trg();
        adc2current_b.trg();
        adc2current_c.trg();

        // clark.trg();
        // park.trg();

        // pid_d.trg();
        // pid_q.trg();

        inverse_park.trg();
        adc2voltage_vbus.trg();
        svpwm.trg();

        p2c_a.trg();
        p2c_b.trg();
        p2c_c.trg();
    }
};
