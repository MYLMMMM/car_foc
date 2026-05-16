#pragma once

#include <cstddef>

/**
 * @brief d-q 轴交叉解耦前馈
 * @details 计算旋转坐标系下的交叉耦合项并叠加到 d/q 轴电压指令上，
 *          抵消 d-q 轴之间的耦合影响，适用于内置式/表贴式永磁同步电机。
 *
 *          解耦公式:
 *            v_d_ff = -Lq * i_q * w_elec
 *            v_q_ff =  (Ld * i_d + flux_linkage) * w_elec
 *
 *          最终叠加:
 *            v_d += v_d_ff
 *            v_q += v_q_ff
 *
 *          应在电流环 PID 计算之后调用，将前馈电压加到 PID 输出上。
 */
template<typename data_type, typename int_type>
class CrossFeedforward {
public:
    data_type &i_d;              // 输入: d 轴电流 (A)
    data_type &i_q;              // 输入: q 轴电流 (A)
    data_type &speed_mech;       // 输入: 机械角速度 (rad/s)
    int_type  &pole_pairs;       // 输入: 电机极对数
    data_type &Ld;               // 输入: d 轴电感 (H)
    data_type &Lq;               // 输入: q 轴电感 (H)
    data_type &flux_linkage;     // 输入: 永磁磁链 (Wb)
    data_type &v_d;              // 输入/输出: d 轴电压指令 (V), 叠加前馈后更新
    data_type &v_q;              // 输入/输出: q 轴电压指令 (V), 叠加前馈后更新

    /**
     * @brief 构造交叉解耦前馈模块
     * @param i_d d 轴电流引用
     * @param i_q q 轴电流引用
     * @param speed_mech 机械角速度引用
     * @param pole_pairs 极对数引用
     * @param Ld d 轴电感引用
     * @param Lq q 轴电感引用
     * @param flux_linkage 永磁磁链引用
     * @param v_d d 轴电压指令引用 (叠加输出)
     * @param v_q q 轴电压指令引用 (叠加输出)
     */
    explicit CrossFeedforward(data_type &i_d, data_type &i_q,
                              data_type &speed_mech, int_type &pole_pairs,
                              data_type &Ld, data_type &Lq,
                              data_type &flux_linkage,
                              data_type &v_d, data_type &v_q)
        : i_d(i_d), i_q(i_q),
          speed_mech(speed_mech), pole_pairs(pole_pairs),
          Ld(Ld), Lq(Lq), flux_linkage(flux_linkage),
          v_d(v_d), v_q(v_q) {}

    CrossFeedforward(const CrossFeedforward&) = delete;
    CrossFeedforward& operator=(const CrossFeedforward&) = delete;
    CrossFeedforward(CrossFeedforward&&) = delete;
    CrossFeedforward& operator=(CrossFeedforward&&) = delete;

    void* operator new(size_t) = delete;
    void operator delete(void*) = delete;

    /**
     * @brief 触发交叉解耦前馈计算
     * @details 先计算电角速度 w_elec = speed_mech * pole_pairs，
     *          再计算前馈项并叠加到 v_d / v_q 上。
     *          应在电流环 PID 之后、逆 Park 变换之前调用。
     */
    void trg() {
        const data_type w_elec = speed_mech * static_cast<data_type>(pole_pairs);
        v_d += -Lq * i_q * w_elec;
        v_q += (Ld * i_d + flux_linkage) * w_elec;
    }
};
