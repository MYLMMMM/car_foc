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
        
        // 注入零序偏置后映射到 [0,1]
        t_a = (va + v_offset) * inv_vbus + HALF;
        t_b = (vb + v_offset) * inv_vbus + HALF;
        t_c = (vc + v_offset) * inv_vbus + HALF;
    }

private:
    static data_type fast_sqrt(data_type x) {
        return static_cast<data_type>(::sqrtf(static_cast<float>(x)));
    }


};
