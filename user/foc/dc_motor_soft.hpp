#pragma once

#include <stdint.h>
#include <cstddef>
#include "algorithm/ADC2Current.hpp"
#include "algorithm/ADC2Voltage.hpp"
#include "algorithm/PID.hpp"
#include "algorithm/Voltage2HalfBridge.hpp"
#include "algorithm/P2C.hpp"

using adc_reg = volatile int32_t;
using pwm_reg = volatile uint32_t;

/**
 * @brief 直流电机配置结构体(纯值传递, 不含引用)
 */
struct dc_motor_datastructure_config
{
    /* interface with hardware */
    adc_reg* adc_current;
    adc_reg* adc_vbus;

    /* config value */
    int16_t adc_zero;
    float adc_vref;
    int16_t adc_full_scale;
    float shunt_resistance;
    float current_sense_gain;
    float vbus_divider_ratio;

    float pid_kp;
    float pid_ki;
    float pid_kd;
    float pid_integral_limit;

    float control_period_s;
    uint32_t pwm_period;
};

/**
 * @brief 直流电机运行数据结构体(含引用, 不可拷贝/移动)
 */
struct dc_motor_datastructure
{
    /* interface with hardware */
    adc_reg& adc_current;   // ADC 电流通道寄存器原始值
    adc_reg& adc_vbus;      // ADC 母线电压寄存器原始值
    pwm_reg ccr_a = 0;      // PWM 半桥 A 比较寄存器值
    pwm_reg ccr_b = 0;      // PWM 半桥 B 比较寄存器值

    /* config value */
    int32_t adc_zero = 0;              // 零电流 ADC 偏置
    int32_t adc_full_scale = 0;        // ADC 满量程计数
    float adc_vref = 0.0f;             // ADC 参考电压(V)
    float shunt_resistance = 0.0f;     // 采样电阻(Ohm)
    float current_sense_gain = 0.0f;   // 电流采样放大倍数
    float vbus_divider_ratio = 0.0f;   // 母线分压还原比例

    float pid_kp = 0.0f;               // PID 比例系数
    float pid_ki = 0.0f;               // PID 积分系数
    float pid_kd = 0.0f;               // PID 微分系数
    float pid_integral_limit = 0.0f;   // PID 积分限幅(绝对值, <=0 不限幅)

    float control_period_s = 0.0f;     // 控制周期(s)
    uint32_t pwm_period = 0;           // PWM 周期 ARR

    /* running value */
    float current = 0.0f;        // 电流(A)
    float voltage_cmd = 0.0f;    // PID 输出电压指令(V)
    float v_bus = 0.0f;          // 母线电压(V)
    float duty_a = 0.0f;         // 半桥 A 占空比 [0, 1]
    float duty_b = 0.0f;         // 半桥 B 占空比 [0, 1]
    float target_current = 0.0f; // 目标电流(A)

    explicit dc_motor_datastructure(const dc_motor_datastructure_config& cfg)
        : adc_current(*cfg.adc_current)
        , adc_vbus(*cfg.adc_vbus)
        , adc_zero(cfg.adc_zero)
        , adc_full_scale(cfg.adc_full_scale)
        , adc_vref(cfg.adc_vref)
        , shunt_resistance(cfg.shunt_resistance)
        , current_sense_gain(cfg.current_sense_gain)
        , vbus_divider_ratio(cfg.vbus_divider_ratio)
        , pid_kp(cfg.pid_kp)
        , pid_ki(cfg.pid_ki)
        , pid_kd(cfg.pid_kd)
        , pid_integral_limit(cfg.pid_integral_limit)
        , control_period_s(cfg.control_period_s)
        , pwm_period(cfg.pwm_period)
    {
    }
};

/**
 * @brief 直流电机控制类
 * @details 组合 ADC2Current + PID + Voltage2HalfBridge + P2C×2 四个子模块，
 *          trg() 按 ADC→电流→PID→电压→双路占空比→双路 CCR 的顺序执行一次控制计算。
 */
class dc_motor {
public:
    dc_motor_datastructure& motor;

private:
    ADC2Current<float, adc_reg> adc2current;
    ADC2Voltage<float, adc_reg> adc2voltage_vbus;
    PID<float> pid_current;
    Voltage2HalfBridge<float> v2hb;
    P2C<float, pwm_reg> p2c_a;
    P2C<float, pwm_reg> p2c_b;

public:
    /**
     * @brief 构造直流电机控制器
     * @param motor 外部电机数据对象引用
     */
    explicit dc_motor(dc_motor_datastructure& motor)
        : motor(motor),
          adc2current(motor.adc_current, motor.adc_zero, motor.adc_vref,
                      motor.adc_full_scale, motor.shunt_resistance,
                      motor.current_sense_gain, motor.current),
          adc2voltage_vbus(motor.adc_vbus, motor.adc_vref, motor.adc_full_scale,
                           motor.vbus_divider_ratio, motor.v_bus),
          pid_current(motor.pid_kp, motor.pid_ki, motor.pid_kd,
                      motor.pid_integral_limit,
                      motor.target_current, motor.current, motor.voltage_cmd),
          v2hb(motor.voltage_cmd, motor.v_bus, motor.duty_a, motor.duty_b),
          p2c_a(motor.duty_a, motor.pwm_period, motor.ccr_a),
          p2c_b(motor.duty_b, motor.pwm_period, motor.ccr_b)
    {
    }

    dc_motor(const dc_motor&) = delete;
    dc_motor& operator=(const dc_motor&) = delete;
    dc_motor(dc_motor&&) = delete;
    dc_motor& operator=(dc_motor&&) = delete;
    void* operator new(size_t) = delete;
    void operator delete(void*) = delete;

    dc_motor_datastructure& data() { return motor; }
    const dc_motor_datastructure& data() const { return motor; }

    /**
     * @brief 更新采样比例系数(电流 + 母线电压)
     * @details 修改采样电阻/增益/参考电压/满量程/分压比后调用
     */
    void update_current_scale() {
        adc2current.update_scale();
        adc2voltage_vbus.update_scale();
    }

    /**
     * @brief 清零电流环 PID 内部积分状态
     */
    void reset_pid() {
        pid_current.reset();
    }

    /**
     * @brief 触发一次直流电机控制计算
     * @details 顺序: ADC→电流 → ADC→母线电压 → PID → V2HB → P2C_A + P2C_B
     */
    void trg() {
        adc2current.trg();
        adc2voltage_vbus.trg();

        if(motor.target_current <= 0.0f)
        {
            motor.current = -motor.current;
        }

        if(motor.target_current == 0.0f) 
        {
            pid_current.reset(); // 目标电流为零时重置 PID，防止积分风up
        }

        pid_current.trg();
        v2hb.trg();
        p2c_a.trg();
        p2c_b.trg();
    }
};
