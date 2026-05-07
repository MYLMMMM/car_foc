#include "vofa.h"

void vofa_init(vofa_t *v) {
    if (!v) return;
    v->channel_count = 0;
    memset(v->send_buf, 0, VOFA_BUF_SIZE);
}

void vofa_bind(vofa_t *v, float *var) {
    if (v && var && v->channel_count < VOFA_MAX_CHANNELS) {
        v->target_vars[v->channel_count++] = var;
    }
}

uint16_t vofa_format(vofa_t *v) {
    if (!v || v->channel_count == 0) return 0;

    uint8_t *ptr = v->send_buf;

    // 1. 序列化绑定的 float 数据
    for (uint8_t i = 0; i < v->channel_count; i++) {
        memcpy(ptr, v->target_vars[i], 4);
        ptr += 4;
    }

    // 2. 填充 JustFloat 帧尾: 0x00 0x00 0x80 0x7F (Little Endian IEEE754 NAN/INF 变体)
    *ptr++ = 0x00;
    *ptr++ = 0x00;
    *ptr++ = 0x80;
    *ptr++ = 0x7F;

    return (uint16_t)(ptr - v->send_buf);
}