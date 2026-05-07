#include <cstddef>

/**
 * @brief ADC 寄存器值到相电流转换
 */
template<typename data_typef, typename data_typei>
class ADC2Current {
public:
    data_typei &adc_raw;            // 输入: ADC 原始寄存器值
    data_typei &adc_zero_raw;       // 输入: 零电流时 ADC 偏置值(计数)
    data_typef &vref;               // 输入: ADC 参考电压(V)
    data_typei &adc_full_scale;     // 输入: ADC 满量程计数(如 12bit 为 4095)
    data_typef &shunt_resistance;   // 输入: 采样电阻(Ohm)
    data_typef &amplifier_gain;     // 输入: 电流采样放大倍数
    data_typef &current;            // 输出: 电流(A)
    data_typef scale;               // 内部: 计数到电流转换系数(A/count)

    /**
     * @brief 构造 ADC 到电流转换模块
     * @param adc_raw ADC 原始值输入引用
     * @param adc_zero_raw ADC 零偏值输入引用(计数)
     * @param vref ADC 参考电压输入引用(V)
     * @param adc_full_scale ADC 满量程输入引用
     * @param shunt_resistance 采样电阻输入引用(Ohm)
     * @param amplifier_gain 放大倍数输入引用
     * @param current 电流输出引用(A)
     */
    explicit ADC2Current(data_typei &adc_raw, data_typei &adc_zero_raw,
                         data_typef &vref, data_typei &adc_full_scale,
                         data_typef &shunt_resistance, data_typef &amplifier_gain,
                         data_typef &current)
        : adc_raw(adc_raw), adc_zero_raw(adc_zero_raw), vref(vref),
          adc_full_scale(adc_full_scale), shunt_resistance(shunt_resistance),
          amplifier_gain(amplifier_gain), current(current), scale(static_cast<data_typef>(0)) {
        update_scale();
    }

    ADC2Current(const ADC2Current&) = delete;
    ADC2Current& operator=(const ADC2Current&) = delete;
    ADC2Current(ADC2Current&&) = delete;
    ADC2Current& operator=(ADC2Current&&) = delete;
    void* operator new(size_t) = delete;
    void operator delete(void*) = delete;

    /**
     * @brief 更新 ADC 计数到电流的比例系数
     * @details scale = vref / (adc_full_scale * shunt_resistance * amplifier_gain)
     */
    void update_scale() {
        if (adc_full_scale <= static_cast<data_typei>(0) ||
            shunt_resistance <= static_cast<data_typef>(0) ||
            amplifier_gain <= static_cast<data_typef>(0) ||
            vref <= static_cast<data_typef>(0)) {
            scale = static_cast<data_typef>(0);
            return;
        }

        const data_typef denominator =
            static_cast<data_typef>(adc_full_scale) * shunt_resistance * amplifier_gain;
        scale = vref / denominator;
    }

    /**
     * @brief 触发 ADC 到电流转换
     * @details current = (adc_raw - adc_zero_raw) * scale
     */
    void trg() {
        // 运行时只保留减法与乘法
        const data_typei raw_delta = adc_raw - adc_zero_raw;
        current = static_cast<data_typef>(raw_delta) * scale;
    }
};
