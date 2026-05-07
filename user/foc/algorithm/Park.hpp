#include <cstddef>

/**
 * @brief Alpha-Beta 到 D-Q 的 Park 变换
 */
template<typename data_type>
class Park {
public:
    data_type &i_alpha;         // 输入: alpha 轴电流
    data_type &i_beta;          // 输入: beta 轴电流
    data_type &sin_theta_elec;  // 输入: sin(theta_elec)
    data_type &cos_theta_elec;  // 输入: cos(theta_elec)
    data_type &i_d;             // 输出: d 轴电流
    data_type &i_q;             // 输出: q 轴电流

    /**
     * @brief 构造 Park 变换模块
     * @param i_alpha alpha 轴电流输入引用
     * @param i_beta beta 轴电流输入引用
     * @param sin_theta_elec 电角正弦输入引用
     * @param cos_theta_elec 电角余弦输入引用
     * @param i_d d 轴电流输出引用
     * @param i_q q 轴电流输出引用
     */
    explicit Park(data_type &i_alpha, data_type &i_beta,
                  data_type &sin_theta_elec, data_type &cos_theta_elec,
                  data_type &i_d, data_type &i_q)
        : i_alpha(i_alpha), i_beta(i_beta),
          sin_theta_elec(sin_theta_elec), cos_theta_elec(cos_theta_elec),
          i_d(i_d), i_q(i_q) {}

    Park(const Park&) = delete;
    Park& operator=(const Park&) = delete;
    Park(Park&&) = delete;
    Park& operator=(Park&&) = delete;

    void* operator new(size_t) = delete;
    void operator delete(void*) = delete;

    /**
     * @brief 触发 Park 变换
     * @details 输入 i_alpha/i_beta，输出 i_d/i_q
     */
    void trg() {
        // 静止坐标系 -> 同步旋转坐标系
        i_d = i_alpha * cos_theta_elec + i_beta * sin_theta_elec;
        i_q = -i_alpha * sin_theta_elec + i_beta * cos_theta_elec;
    }
};
