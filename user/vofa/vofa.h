#ifndef VOFA_PLUS_H
#define VOFA_PLUS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <string.h>

#define VOFA_MAX_CHANNELS 10
// 每个 float 4字节 + 4字节帧尾
#define VOFA_BUF_SIZE (VOFA_MAX_CHANNELS * 4 + 4)

typedef struct {
    float *target_vars[VOFA_MAX_CHANNELS];
    uint8_t channel_count;
    uint8_t send_buf[VOFA_BUF_SIZE];
} vofa_t;

// API 定义
void vofa_init(vofa_t *v);
void vofa_bind(vofa_t *v, float *var);
uint16_t vofa_format(vofa_t *v);

#ifdef __cplusplus
}
#endif

#endif // VOFA_PLUS_H