#include <cstddef>

/**
 * @brief 编码器计数到机械角变换
 */
template<typename data_typef, typename data_typei>
class Encoder2Mech {
public:
    data_typei &encoder_raw;   // 输入: 编码器原始计数
    data_typei &encoder_cpr;   // 输入: 编码器每圈计数(CPR)
    data_typef &theta_mech;    // 输出: 机械角(rad), 归一化到 [0, 2pi)

    const data_typef TWO_PI = static_cast<data_typef>(6.2831853071795864769);

    /**
     * @brief 构造编码器到机械角模块
     * @param encoder_raw 编码器原始计数输入引用
     * @param encoder_cpr 每圈计数输入引用
     * @param theta_mech 机械角输出引用(rad)
     */
    explicit Encoder2Mech(data_typei &encoder_raw, data_typei &encoder_cpr, data_typef &theta_mech)
        : encoder_raw(encoder_raw), encoder_cpr(encoder_cpr), theta_mech(theta_mech) {}

    Encoder2Mech(const Encoder2Mech&) = delete;
    Encoder2Mech& operator=(const Encoder2Mech&) = delete;
    Encoder2Mech(Encoder2Mech&&) = delete;
    Encoder2Mech& operator=(Encoder2Mech&&) = delete;
    void* operator new(size_t) = delete;
    void operator delete(void*) = delete;

    /**
     * @brief 触发编码器到机械角计算
     * @details theta_mech = (encoder_raw mod encoder_cpr) * 2pi / encoder_cpr
     *          使用位运算优化取模 (CPR 为 2 的幂时) (P3-2)
     */
    void trg() {
        if (encoder_cpr <= static_cast<data_typei>(0)) {
            theta_mech = static_cast<data_typef>(0);
            return;
        }

        // 编译期无法判断, 运行时检测 CPR 是否为 2 的幂并用位运算替代取模
        const bool is_pow2 = (encoder_cpr > 0u) && ((encoder_cpr & (encoder_cpr - 1u)) == 0u);
        data_typei enc_norm;
        if (is_pow2) {
            enc_norm = encoder_raw & (encoder_cpr - static_cast<data_typei>(1));
        } else {
            enc_norm = encoder_raw % encoder_cpr;
        }

        if (enc_norm < static_cast<data_typei>(0)) {
            enc_norm += encoder_cpr;
        }

        theta_mech = static_cast<data_typef>(enc_norm) *
            (TWO_PI / static_cast<data_typef>(encoder_cpr));
    }
};
