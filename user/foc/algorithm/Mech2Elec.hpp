#include <math.h>
#include <cstddef>

/**
 * @brief 机械角到电角度变换
 */
template<typename data_typef, typename data_typei>
class Mech2Elec {
public:
    data_typef &theta_mech;         // 输入: 机械角(rad)
    data_typei &pole_pairs;         // 输入: 极对数
    data_typef &theta_elec_offset;  // 输入: 电角偏置(rad)
    data_typef &theta_elec;         // 输出: 电角(rad), 归一化到 [0, 2pi)
    data_typef &sin_theta_elec;     // 输出: sin(theta_elec)
    data_typef &cos_theta_elec;     // 输出: cos(theta_elec)

    const data_typef TWO_PI = static_cast<data_typef>(6.2831853071795864769);

    /**
     * @brief 构造机械角到电角度变换模块
     * @param theta_mech 机械角输入引用(rad)
     * @param pole_pairs 极对数输入引用
     * @param theta_elec_offset 电角偏置输入引用(rad)
     * @param theta_elec 电角输出引用(rad)
     * @param sin_theta_elec 电角正弦输出引用
     * @param cos_theta_elec 电角余弦输出引用
     */
    explicit Mech2Elec(data_typef &theta_mech, data_typei &pole_pairs,
                       data_typef &theta_elec_offset, data_typef &theta_elec,
                       data_typef &sin_theta_elec, data_typef &cos_theta_elec)
        : theta_mech(theta_mech), pole_pairs(pole_pairs),
          theta_elec_offset(theta_elec_offset), theta_elec(theta_elec),
          sin_theta_elec(sin_theta_elec), cos_theta_elec(cos_theta_elec) {}

    Mech2Elec(const Mech2Elec&) = delete;
    Mech2Elec& operator=(const Mech2Elec&) = delete;
    Mech2Elec(Mech2Elec&&) = delete;
    Mech2Elec& operator=(Mech2Elec&&) = delete;

    void* operator new(size_t) = delete;
    void operator delete(void*) = delete;

    /**
     * @brief 触发机械角到电角度计算
     * @details theta_elec = pole_pairs * theta_mech + theta_elec_offset，并归一化到 [0, 2pi)
     */
    void trg() {
        // theta_elec = pole_pairs * theta_mech + theta_elec_offset
        const data_typef theta_elec_raw = static_cast<data_typef>(pole_pairs) * theta_mech + theta_elec_offset;
        // 使用 fmod 做周期归一化
        data_typef theta_norm = static_cast<data_typef>(
            ::fmodf(static_cast<float>(theta_elec_raw), static_cast<float>(TWO_PI)));
        if (theta_norm < static_cast<data_typef>(0)) {
            theta_norm += TWO_PI;
        }

        theta_elec = theta_norm;
        compute_sin_cos(theta_elec, sin_theta_elec, cos_theta_elec);
    }

private:
    static void compute_sin_cos(data_typef angle, data_typef &sin_out, data_typef &cos_out) {
        const float angle_f = static_cast<float>(angle);
#if defined(__GNUC__)
        float sin_f = 0.0f;
        float cos_f = 1.0f;
        __builtin_sincosf(angle_f, &sin_f, &cos_f);
        sin_out = static_cast<data_typef>(sin_f);
        cos_out = static_cast<data_typef>(cos_f);
#else
        sin_out = static_cast<data_typef>(::sinf(angle_f));
        cos_out = static_cast<data_typef>(::cosf(angle_f));
#endif
    }
};
