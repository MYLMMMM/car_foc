#include <cstddef>

/**
 * @brief D-Q 到 Alpha-Beta 的逆 Park 变换
 */
template<typename data_type>
class InversePark {
public:
    data_type &v_q;             // 输入: q 轴电压
    data_type &v_d;             // 输入: d 轴电压
    data_type &sin_theta_elec;  // 输入: sin(theta_elec)
    data_type &cos_theta_elec;  // 输入: cos(theta_elec)
    data_type &v_alpha;         // 输出: alpha 轴电压
    data_type &v_beta;          // 输出: beta 轴电压

    /**
     * @brief 构造逆 Park 变换模块
     * @param v_q q 轴电压输入引用
     * @param v_d d 轴电压输入引用
     * @param sin_theta_elec 电角正弦输入引用
     * @param cos_theta_elec 电角余弦输入引用
     * @param v_alpha alpha 轴电压输出引用
     * @param v_beta beta 轴电压输出引用
     */
    explicit InversePark(data_type &v_q, data_type &v_d,
                         data_type &sin_theta_elec, data_type &cos_theta_elec,
                         data_type &v_alpha, data_type &v_beta)
        : v_q(v_q), v_d(v_d),
          sin_theta_elec(sin_theta_elec), cos_theta_elec(cos_theta_elec),
          v_alpha(v_alpha), v_beta(v_beta) {}

    InversePark(const InversePark&) = delete;
    InversePark& operator=(const InversePark&) = delete;
    InversePark(InversePark&&) = delete;
    InversePark& operator=(InversePark&&) = delete;

    void* operator new(size_t) = delete;
    void operator delete(void*) = delete;

    /**
     * @brief 触发逆 Park 变换
     * @details 输入 v_d/v_q，输出 v_alpha/v_beta
     */
    void trg() {
        // 同步旋转坐标系 -> 静止坐标系
        v_alpha = v_d * cos_theta_elec - v_q * sin_theta_elec;
        v_beta = v_d * sin_theta_elec + v_q * cos_theta_elec;
    }
};
