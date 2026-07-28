#pragma once

#include <stdint.h>
#include <cstddef>
#include "algorithm/ADC2Current.hpp"
#include "algorithm/Throttle2ESC.hpp"
#include "algorithm/UpperLimit.hpp"
#include "algorithm/SlopeLimit.hpp"

using adc_reg = volatile int32_t;
using pwm_reg = volatile uint32_t;

/**
 * @brief ESC 电调配置结构体(纯值传递, 不含引用)
 * @details 脉宽控制模式: 上位机直接输入油门 [0, 1],
 *          内部做上限幅 + 斜率限制后转换为 ESC CCR.
 *          同时采集电流做监测(不参与闭环).
 */
struct esc_datastructure_config
{
    /* interface with hardware */
    adc_reg* adc_current;       // ADC 电流通道结果寄存器指针

    /* ADC 电流转换参数 */
    float adc_vref;             // ADC 参考电压(V)
    int16_t adc_full_scale;     // ADC 满量程计数
    int16_t adc_zero_current;   // 零电流 ADC 偏置(计数), 0偏=0
    float shunt_resistance;     // 采样电阻(Ohm)
    float current_sense_gain;   // 电流采样放大倍数(V/V)

    /* 油门限幅参数 */
    float throttle_max;         // 油门上限制 [0, 1], 默认 0.9
    float throttle_slope;       // 油门斜率限制(per second), 默认 0.3

    float control_period_s;     // 控制周期(s)
    uint32_t pwm_period;        // PWM 周期 ARR (2399999)
};

/**
 * @brief ESC 电调运行数据结构体(含引用, 不可拷贝/移动)
 * @details 上位机写 throttle_cmd → 限幅 → 斜率限制 → Throttle2ESC → ccr_esc
 */
struct esc_datastructure
{
    /* interface with hardware */
    adc_reg& adc_current;       // ADC 电流寄存器原始值引用
    pwm_reg ccr_esc = 0;        // ESC PWM 比较寄存器值

    /* ADC 电流转换参数 */
    int32_t adc_zero_current = 0;
    int32_t adc_full_scale = 0;
    float adc_vref = 0.0f;
    float shunt_resistance = 0.0f;
    float current_sense_gain = 0.0f;

    /* 油门限幅参数 */
    float throttle_max = 0.9f;
    float throttle_slope_per_s = 0.3f;       // 每秒油门变化率上限
    float throttle_slope_per_step = 0.0f;    // 每步油门变化率上限 (= slope_per_s * control_period_s)

    float control_period_s = 0.0f;
    uint32_t pwm_period = 0;

    /* running value */
    float i_motor = 0.0f;               // 电机电流(A), 仅监测
    float throttle_cmd = 0.0f;          // 油门指令 [0, 1], 上位机直写
    float throttle_limited = 0.0f;      // 限幅 + 限斜率后的油门值

    explicit esc_datastructure(const esc_datastructure_config& cfg)
        : adc_current(*cfg.adc_current)
        , adc_zero_current(cfg.adc_zero_current)
        , adc_full_scale(cfg.adc_full_scale)
        , adc_vref(cfg.adc_vref)
        , shunt_resistance(cfg.shunt_resistance)
        , current_sense_gain(cfg.current_sense_gain)
        , throttle_max(cfg.throttle_max)
        , throttle_slope_per_s(cfg.throttle_slope)
        , throttle_slope_per_step(cfg.throttle_slope * cfg.control_period_s)
        , control_period_s(cfg.control_period_s)
        , pwm_period(cfg.pwm_period)
    {
    }
};

/**
 * @brief ESC 电调控制类
 * @details 组合 ADC2Current + UpperLimit + SlopeLimit + Throttle2ESC 四个子模块,
 *          trg() 按 ADC→电流 → 油门上限幅 → 斜率限制 → ESC CCR 的顺序执行.
 */
class esc {
public:
    esc_datastructure& data;

private:
    ADC2Current<float, adc_reg> adc2current;
    UpperLimit<float> upper_limit_throttle;
    SlopeLimit<float> slope_limit_throttle;
    Throttle2ESC<float, pwm_reg> throttle2esc;

public:
    /**
     * @brief 构造 ESC 控制器
     * @param data 外部 ESC 数据对象引用
     */
    explicit esc(esc_datastructure& data)
        : data(data),
          adc2current(data.adc_current, data.adc_zero_current,
                      data.adc_vref, data.adc_full_scale,
                      data.shunt_resistance, data.current_sense_gain,
                      data.i_motor),
          upper_limit_throttle(data.throttle_cmd, data.throttle_max),
          slope_limit_throttle(data.throttle_cmd, data.throttle_slope_per_step, data.throttle_limited),
          throttle2esc(data.throttle_limited, data.ccr_esc)
    {
    }

    esc(const esc&) = delete;
    esc& operator=(const esc&) = delete;
    esc(esc&&) = delete;
    esc& operator=(esc&&) = delete;
    void* operator new(size_t) = delete;
    void operator delete(void*) = delete;

    /**
     * @brief 更新 ADC 电流转换比例系数
     */
    void update_scale() {
        adc2current.update_scale();
    }

    /**
     * @brief 触发一次 ESC 控制计算
     * @details 顺序: ADC→电流 → 油门上限制 → 斜率限制 → Throttle2ESC
     */
    void trg() {
        // 1. ADC → 电流 (仅监测)
        adc2current.trg();

        // 2. 油门上限制 (throttle_cmd 钳位到 throttle_max)
        upper_limit_throttle.trg();

        // 3. 斜率限制 (缓启动保护, per-step slope 在构造时已算好)
        slope_limit_throttle.trg();

        // 4. 油门 → ESC CCR
        throttle2esc.trg();
    }
};
