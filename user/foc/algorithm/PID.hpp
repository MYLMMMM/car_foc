#include <cstddef>

/**
 * @brief 基础位置式 PID 控制器
 */
template<typename data_type>
class PID {
public:
    data_type &p;       // 输入/可调: 比例系数 Kp
    data_type &i;       // 输入/可调: 积分系数 Ki
    data_type &d;       // 输入/可调: 微分系数 Kd
    data_type &integral_limit;  // 输入/可调: 积分限幅绝对值(<=0 不限幅)
    data_type &target;  // 输入: 目标值
    data_type &input;   // 输入: 反馈值
    data_type &output;  // 输出: 控制量

    data_type integral;    // 内部状态: 积分累加
    data_type last_error;  // 内部状态: 上次误差

    /**
     * @brief 构造 PID 模块
     * @param P 比例系数引用
     * @param I 积分系数引用
     * @param D 微分系数引用
     * @param integral_limit 积分限幅引用(绝对值, <=0 不限幅)
     * @param target 目标值引用
     * @param input 反馈值引用
     * @param output 控制输出引用
     */
    explicit PID(data_type &P, data_type &I, data_type &D,
                 data_type &integral_limit,
                 data_type &target, data_type &input, data_type &output) 
        : p(P), i(I), d(D), integral_limit(integral_limit),
          target(target), input(input), output(output), 
          integral(0), last_error(0) {}

    PID(const PID&) = delete;
    PID& operator=(const PID&) = delete;
    PID(PID&&) = delete;
    PID& operator=(PID&&) = delete;
    void* operator new(size_t) = delete;
    void operator delete(void*) = delete;

    void set_P(data_type P) { p = P; }
    void set_I(data_type I) { i = I; }
    void set_D(data_type D) { d = D; }
    void set_integral_limit(data_type limit) { integral_limit = limit; }

    // 清空内部状态
    void reset() {
        integral = 0;
        last_error = 0;
    }

    /**
     * @brief 触发 PID 计算
     * @details output = Kp*e + Ki*sum(e) + Kd*(e-e_last)
     */
    void trg() {
        // 当前误差
        data_type error = target - input;
        // 积分累加
        integral += error;
        // 可选积分限幅(按绝对值处理，<=0 视为不限幅)
        if (integral_limit != static_cast<data_type>(0)) {
            data_type limit = integral_limit;
            if (integral > limit) {
                integral = limit;
            } else {
                const data_type neg_limit = -limit;
                if (integral < neg_limit) {
                    integral = neg_limit;
                }
            }
        }
        // 位置式 PID 输出
        output = (p * error) + (i * integral) + (d * (error - last_error));
        // 更新历史误差
        last_error = error;
    }
};
