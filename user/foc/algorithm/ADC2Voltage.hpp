#include <cstddef>

/**
 * @brief ADC 寄存器值到母线电压转换
 */
template<typename data_typef, typename data_typei>
class ADC2Voltage {
public:
    data_typei &adc_raw;         // 输入: ADC 原始寄存器值
    data_typef &vref;            // 输入: ADC 参考电压(V)
    data_typei &adc_full_scale;  // 输入: ADC 满量程计数(如 12bit 为 4095)
    data_typef &divider_ratio;   // 输入: 母线分压还原比例(母线电压/ADC 引脚电压)
    data_typef &voltage;         // 输出: 母线电压(V)
    data_typef scale;            // 内部: 计数到母线电压转换系数(V/count)

    /**
     * @brief 构造 ADC 到母线电压转换模块
     * @param adc_raw ADC 原始值输入引用
     * @param vref ADC 参考电压输入引用(V)
     * @param adc_full_scale ADC 满量程输入引用
     * @param divider_ratio 分压还原比例输入引用
     * @param voltage 母线电压输出引用(V)
     */
    explicit ADC2Voltage(data_typei &adc_raw, data_typef &vref,
                         data_typei &adc_full_scale, data_typef &divider_ratio,
                         data_typef &voltage)
        : adc_raw(adc_raw), vref(vref), adc_full_scale(adc_full_scale),
          divider_ratio(divider_ratio), voltage(voltage), scale(static_cast<data_typef>(0)) {
        update_scale();
    }

    ADC2Voltage(const ADC2Voltage&) = delete;
    ADC2Voltage& operator=(const ADC2Voltage&) = delete;
    ADC2Voltage(ADC2Voltage&&) = delete;
    ADC2Voltage& operator=(ADC2Voltage&&) = delete;
    void* operator new(size_t) = delete;
    void operator delete(void*) = delete;

    /**
     * @brief 更新 ADC 计数到母线电压的比例系数
     * @details scale = (vref * divider_ratio) / adc_full_scale
     */
    void update_scale() {
        if (adc_full_scale <= static_cast<data_typei>(0) ||
            divider_ratio <= static_cast<data_typef>(0) ||
            vref <= static_cast<data_typef>(0)) {
            scale = static_cast<data_typef>(0);
            return;
        }

        const data_typef numerator = vref * divider_ratio;
        scale = numerator / static_cast<data_typef>(adc_full_scale);
    }

    /**
     * @brief 触发 ADC 到母线电压转换
     * @details voltage = adc_raw * scale
     */
    void trg() {
        voltage = static_cast<data_typef>(adc_raw) * scale;
    }
};
