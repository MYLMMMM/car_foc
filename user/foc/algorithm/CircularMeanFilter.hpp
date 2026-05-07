#pragma once

#include <stdint.h>
#include <stddef.h>

/**
 * @brief 编码器原始值圆平均滤波器（环形缓冲）
 * @tparam data_typef 输出数据类型（平均值类型）
 * @tparam data_typei 输入数据类型（原始样本类型）
 * @tparam deep 滤波深度（环形缓冲区长度）
 */
template<typename data_typef, typename data_typei, size_t deep>
class CircularMeanFilter {
public:
    data_typef &output;  // 输出: 平均后的编码器原始值

    /**
     * @brief 构造圆平均滤波器
     * @param output 平均值输出引用
     */
    explicit CircularMeanFilter(data_typef &output)
        : output(output),
          buffer_{},
          write_index_(0) {
        static_assert(deep > 0, "CircularMeanFilter deep must be greater than 0");
    }

    CircularMeanFilter(const CircularMeanFilter&) = delete;
    CircularMeanFilter& operator=(const CircularMeanFilter&) = delete;
    CircularMeanFilter(CircularMeanFilter&&) = delete;
    CircularMeanFilter& operator=(CircularMeanFilter&&) = delete;
    void* operator new(size_t) = delete;
    void operator delete(void*) = delete;

    /**
     * @brief 写入一个编码器原始样本
     * @details 将原始样本写入环形缓冲
     * @param value 编码器原始值
     */
    void write(data_typei value) {
        buffer_[write_index_] = value;
        write_index_ = (write_index_ + 1u) % deep;
    }

    /**
     * @brief 触发一次平均计算
     * @details 对环形缓冲全部元素求和，并写入绑定输出变量
     */
    void trig() {
        uint64_t sum = 0u;
        for (size_t i = 0; i < deep; ++i) {
            sum += static_cast<uint64_t>(buffer_[i]);
        }
        output = static_cast<data_typef>(sum) / static_cast<data_typef>(deep);
    }


    /**
     * @brief 清空滤波器内部状态
     */
    void clear() {
        write_index_ = 0u;
        for (size_t i = 0; i < deep; ++i) {
            buffer_[i] = static_cast<data_typei>(0);
        }
        output = static_cast<data_typef>(0);
    }

private:
    data_typei buffer_[deep];  // 环形缓冲（原始输入样本）
    size_t write_index_;       // 下次写入位置
};
