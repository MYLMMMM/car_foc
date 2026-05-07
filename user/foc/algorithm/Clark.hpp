#include <cstddef>

/**
 * @brief 三相电流 Clarke 变换
 */
template<typename data_type>
class Clark {
public:
    data_type &i_a;      // 输入: A 相电流
    data_type &i_b;      // 输入: B 相电流
    data_type &i_c;      // 输入: C 相电流
    data_type &i_alpha;  // 输出: alpha 轴电流
    data_type &i_beta;   // 输出: beta 轴电流

    const data_type HALF = static_cast<data_type>(0.5);
    const data_type TWO_THIRDS = static_cast<data_type>(0.6666666666666666);
    const data_type SQRT3_2 = static_cast<data_type>(0.8660254037844386);

    /**
     * @brief 构造 Clarke 变换模块
     * @param i_a A 相电流输入引用
     * @param i_b B 相电流输入引用
     * @param i_c C 相电流输入引用
     * @param i_alpha alpha 轴电流输出引用
     * @param i_beta beta 轴电流输出引用
     */
    explicit Clark(data_type &i_a, data_type &i_b, data_type &i_c,
                   data_type &i_alpha, data_type &i_beta)
        : i_a(i_a), i_b(i_b), i_c(i_c), i_alpha(i_alpha), i_beta(i_beta) {}

    Clark(const Clark&) = delete;
    Clark& operator=(const Clark&) = delete;
    Clark(Clark&&) = delete;
    Clark& operator=(Clark&&) = delete;

    void* operator new(size_t) = delete;
    void operator delete(void*) = delete;

    /**
     * @brief 触发 Clarke 变换
     * @details 输入三相电流，输出静止坐标系 i_alpha 与 i_beta
     */
    void trg() {
        // 幅值不变 Clarke 变换
        i_alpha = TWO_THIRDS * (i_a - HALF * i_b - HALF * i_c);
        i_beta = TWO_THIRDS * SQRT3_2 * (i_b - i_c);
    }
};
