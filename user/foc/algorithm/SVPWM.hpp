#include <math.h>
#include <cstddef>

/**
 * @brief 空间矢量 PWM 计算
 */
template<typename data_type>
class SVPWM {
public:
    data_type &v_alpha;  // 输入/输出: alpha 轴电压指令 (可能被限幅)
    data_type &v_beta;   // 输入/输出: beta 轴电压指令 (可能被限幅)
    data_type &v_bus;    // 输入: 母线电压
    data_type &t_a;      // 输出: A 相占空比 [0, 1]
    data_type &t_b;      // 输出: B 相占空比 [0, 1]
    data_type &t_c;      // 输出: C 相占空比 [0, 1]

    const data_type SQRT3_2 = static_cast<data_type>(0.8660254037844386);
    const data_type INV_SQRT3 = static_cast<data_type>(0.5773502691896258);
    const data_type HALF = static_cast<data_type>(0.5);
    const data_type ONE = static_cast<data_type>(1.0);

    /**
     * @brief 构造 SVPWM 模块
     * @param v_alpha alpha 轴电压指令引用
     * @param v_beta beta 轴电压指令引用
     * @param v_bus 母线电压引用
     * @param t_a A 相占空比输出引用
     * @param t_b B 相占空比输出引用
     * @param t_c C 相占空比输出引用
     */
    explicit SVPWM(data_type &v_alpha, data_type &v_beta, data_type &v_bus,
                   data_type &t_a, data_type &t_b, data_type &t_c)
        : v_alpha(v_alpha), v_beta(v_beta), v_bus(v_bus),
          t_a(t_a), t_b(t_b), t_c(t_c){}

    SVPWM(const SVPWM&) = delete;
    SVPWM& operator=(const SVPWM&) = delete;
    SVPWM(SVPWM&&) = delete;
    SVPWM& operator=(SVPWM&&) = delete;
    void* operator new(size_t) = delete;
    void operator delete(void*) = delete;

    /**
     * @brief 触发 SVPWM 计算
     * @details 采用零序注入(中点平移)生成三相占空比
     */
    void trg() {

        if (v_bus <= static_cast<data_type>(0)) {
            // 母线异常时输出 50% 占空比
            t_a = HALF;
            t_b = HALF;
            t_c = HALF;
            return;
        }

        // alpha-beta -> 三相等效电压
        data_type va = v_alpha;
        data_type v_temp = SQRT3_2 * v_beta;
        data_type vb = -HALF * v_alpha + v_temp;
        data_type vc = -HALF * v_alpha - v_temp;

        data_type v_max = va;
        if (vb > v_max) v_max = vb;
        if (vc > v_max) v_max = vc;

        data_type v_min = va;
        if (vb < v_min) v_min = vb;
        if (vc < v_min) v_min = vc;

        data_type v_offset = -HALF * (v_max + v_min);
        data_type inv_vbus = ONE / v_bus; 
        
        // 注入零序偏置后映射到占空比 (raw, 可能超出 [0,1])
        data_type ta_raw = (va + v_offset) * inv_vbus + HALF;
        data_type tb_raw = (vb + v_offset) * inv_vbus + HALF;
        data_type tc_raw = (vc + v_offset) * inv_vbus + HALF;

        // === 过调制处理: 等比缩放使占空比回到 [0,1] (P1-1) ===
        data_type t_max = ta_raw;
        if (tb_raw > t_max) t_max = tb_raw;
        if (tc_raw > t_max) t_max = tc_raw;

        data_type t_min = ta_raw;
        if (tb_raw < t_min) t_min = tb_raw;
        if (tc_raw < t_min) t_min = tc_raw;

        data_type range = t_max - t_min;
        if (range > ONE) {
            // 范围超出 1.0: 等比缩放到 [0,1]
            data_type scale = ONE / range;
            data_type mid = (t_max + t_min) * HALF;
            t_a = (ta_raw - mid) * scale + HALF;
            t_b = (tb_raw - mid) * scale + HALF;
            t_c = (tc_raw - mid) * scale + HALF;
        } else if (t_max > ONE) {
            // 仅超出上限: 整体下移
            data_type excess = t_max - ONE;
            t_a = ta_raw - excess;
            t_b = tb_raw - excess;
            t_c = tc_raw - excess;
        } else if (t_min < static_cast<data_type>(0)) {
            // 仅超出下限: 整体上移
            data_type excess = -t_min;
            t_a = ta_raw + excess;
            t_b = tb_raw + excess;
            t_c = tc_raw + excess;
        } else {
            t_a = ta_raw;
            t_b = tb_raw;
            t_c = tc_raw;
        }
    }

private:
    static data_type fast_sqrt(data_type x) {
        return static_cast<data_type>(::sqrtf(static_cast<float>(x)));
    }


};
