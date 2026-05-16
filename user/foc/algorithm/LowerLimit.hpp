#pragma once

#include <cstddef>

/**
 * @brief 下限限幅模块
 * @details 当 value < limit 时，将 value 钳位到 limit
 */
template<typename data_type>
class LowerLimit {
public:
    data_type &value;  // 输入/输出: 被限幅的变量
    data_type &limit;  // 输入/可调: 下限幅度值

    /**
     * @brief 构造下限限幅模块
     * @param value 被限幅的变量引用
     * @param limit 下限幅度值引用
     */
    explicit LowerLimit(data_type &value, data_type &limit)
        : value(value), limit(limit) {}

    LowerLimit(const LowerLimit&) = delete;
    LowerLimit& operator=(const LowerLimit&) = delete;
    LowerLimit(LowerLimit&&) = delete;
    LowerLimit& operator=(LowerLimit&&) = delete;
    void* operator new(size_t) = delete;
    void operator delete(void*) = delete;

    /**
     * @brief 触发下限限幅
     * @details 若 value < limit，则 value = limit
     */
    void trg() {
        if (value < limit) {
            value = limit;
        }
    }
};
