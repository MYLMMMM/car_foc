#pragma once

#include <stdint.h>
#include "hal.hpp"

/**
 * @file drv8876.hpp
 * @brief DRV8876 直流有刷电机驱动芯片（Head-only）。
 *
 * @details
 * - DRV8876 是 TI 的 H 桥直流有刷电机驱动器，通过两个 GPIO（nSLEEP、nFAULT）进行控制与状态检测。
 * - 本驱动不包含 PWM 控制逻辑（IN1/IN2），仅封装芯片级的使能/睡眠与故障检测。
 * - GPIO 采用"构造注入"方式绑定，避免在驱动内部硬编码板级资源。
 * - nFAULT 采用"外部 ISR 转发"模式：应用层在端口中断里调用 handle_nfault_irq()。
 *
 * @note
 * - nSLEEP 引脚内部下拉，高电平使能器件，低电平进入低功耗睡眠模式。
 * - nFAULT 引脚为开漏输出，需外部上拉电阻。故障期间引脚被拉低。
 * - 故障类型（OCP/UVLO/TSD）无法通过 nFAULT 引脚区分，需结合系统上下文判断。
 * - 从睡眠模式唤醒后需等待 tWAKE（约 1ms）才能正常接收 PWM 输入。
 */
class drv8876
{
public:
    /**
     * @brief DRV8876 故障状态结构体。
     *
     * @details
     * nFAULT 引脚只能反映"是否存在故障"，无法区分具体故障类型。
     * 可能触发 nFAULT 的故障包括：
     * - OCP（过流保护）
     * - UVLO（欠压锁定）
     * - TSD（过温关断）
     */
    struct FaultState
    {
        bool nfault_active; /**< true 表示 nFAULT 有效（存在故障） */
    };

    /**
     * @brief nFAULT 事件回调函数签名。
     *
     * @param state 当前故障状态（中断触发后已刷新）
     * @param user_ctx 用户上下文指针
     */
    using Callback = void (*)(const FaultState& state, void* user_ctx);

    /**
     * @brief 构造 DRV8876 驱动对象（仅绑定资源，不做外设初始化）。
     *
     * @param nsleep_gpio nSLEEP 引脚配置（高=使能，低=睡眠，内部下拉）
     * @param nfault_gpio nFAULT 引脚配置（开漏输出，低=故障，外部上拉）
     */
    drv8876(hal_gpio& nsleep_gpio, hal_gpio& nfault_gpio) noexcept
        : nsleep_gpio_(nsleep_gpio)
        , nfault_gpio_(nfault_gpio)
        , initialized_(false)
        , state_{false}
        , nfault_callback_(nullptr)
        , nfault_callback_user_ctx_(nullptr)
    {
    }

    drv8876(const drv8876&) = delete;
    drv8876& operator=(const drv8876&) = delete;
    drv8876(drv8876&&) = delete;
    drv8876& operator=(drv8876&&) = delete;

    /**
     * @brief 初始化驱动内部状态。
     *
     * @details
     * - 将器件置于睡眠模式（nSLEEP = 低电平）。
     * - 初始化故障状态为无故障。
     *
     * @return true 初始化成功
     */
    bool init() noexcept
    {
        if (initialized_)
        {
            return true;
        }

        // 初始状态：睡眠模式（nSLEEP 低电平，内部下拉，无需主动操作）
        nsleep_gpio_.unset();

        // 清除故障状态
        state_.nfault_active = false;

        initialized_ = true;
        return true;
    }

    /**
     * @brief 查询驱动初始化状态。
     *
     * @return true 已完成 init()
     * @return false 未初始化
     */
    bool is_initialized() const noexcept
    {
        return initialized_;
    }

    /**
     * @brief 设置器件使能/睡眠状态。
     *
     * @param en true=使能器件（nSLEEP 高电平），false=进入睡眠（nSLEEP 低电平）
     *
     * @note
     * - 从睡眠模式唤醒后需等待 tWAKE（约 1ms）才能正常接收 IN1/IN2 PWM 输入。
     * - nSLEEP 引脚内部下拉，上电默认进入睡眠模式。
     */
    void set_enable(bool en) noexcept
    {
        if (en)
        {
            nsleep_gpio_.set();
        }
        else
        {
            nsleep_gpio_.unset();
        }
    }

    /**
     * @brief 查询器件是否处于使能状态。
     *
     * @return true 器件使能（nSLEEP = 高）
     * @return false 器件睡眠（nSLEEP = 低）
     */
    bool is_enabled() const noexcept
    {
        return nsleep_gpio_.read();
    }

    /**
     * @brief 读取 nFAULT 当前有效态。
     *
     * @return true nFAULT 有效（故障激活，引脚被拉低）
     * @return false nFAULT 无效（无故障，引脚被外部上拉至高电平）
     */
    bool is_nfault_active() const noexcept
    {
        return !nfault_gpio_.read();
    }

    /**
     * @brief 注册 nFAULT 回调。
     *
     * @param cb 回调函数指针（传 nullptr 可注销）
     * @param user_ctx 用户上下文指针
     */
    void register_nfault_callback(Callback cb, void* user_ctx = nullptr) noexcept
    {
        nfault_callback_ = cb;
        nfault_callback_user_ctx_ = user_ctx;
    }

    /**
     * @brief nFAULT 外部 ISR 转发入口。
     *
     * @details
     * 推荐应用层流程：
     * 1. 端口中断入口中调用本函数
     * 2. 本函数检查并清除 nFAULT 引脚中断标志
     * 3. 读取 nFAULT 状态并刷新内部 FaultState
     * 4. 若已注册回调则触发回调
     */
    void handle_nfault_irq() noexcept
    {
        if (nfault_gpio_.get_interrupt_state() == 0u)
        {
            return;
        }

        nfault_gpio_.clear_interrupt_state();

        // 刷新故障状态
        state_.nfault_active = is_nfault_active();

        if (nfault_callback_ != nullptr)
        {
            nfault_callback_(state_, nfault_callback_user_ctx_);
        }
    }

    /**
     * @brief 获取当前故障状态。
     *
     * @return const FaultState& 故障状态只读引用
     */
    const FaultState& state() const noexcept
    {
        return state_;
    }

private:
    hal_gpio& nsleep_gpio_;
    hal_gpio& nfault_gpio_;
    bool initialized_;
    FaultState state_;
    Callback nfault_callback_;
    void* nfault_callback_user_ctx_;
};
