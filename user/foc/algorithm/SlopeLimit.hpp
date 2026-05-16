#pragma once

#include <cstddef>

/**
 * @brief 斜率限制模块
 * @details 限制输出值每步的变化速率（增减量），使 output 以不超过 ±slope 的步长向 source 逼近
 */
template<typename data_type>
class SlopeLimit {
public:
    data_type &source;  // 输入: 源值（目标值）
    data_type &slope;   // 输入/可调: 每次 trig 允许的最大变化量 (>0)
    data_type &output;  // 输出: 限斜率后的值

    /**
     * @brief 构造斜率限制模块
     * @param source 源值引用（目标值）
     * @param slope 斜率限制值引用（每步最大变化量）
     * @param output 输出值引用
     */
    explicit SlopeLimit(data_type &source, data_type &slope, data_type &output)
        : source(source), slope(slope), output(output) {}

    SlopeLimit(const SlopeLimit&) = delete;
    SlopeLimit& operator=(const SlopeLimit&) = delete;
    SlopeLimit(SlopeLimit&&) = delete;
    SlopeLimit& operator=(SlopeLimit&&) = delete;
    void* operator new(size_t) = delete;
    void operator delete(void*) = delete;

    /**
     * @brief 触发斜率限制
     * @details output 以不超过 ±slope 的步长向 source 逼近
     */
    void trg() {
        if (source > output + slope) {
            output += slope;
        } else if (source < output - slope) {
            output -= slope;
        } else {
            output = source;
        }
    }
};
