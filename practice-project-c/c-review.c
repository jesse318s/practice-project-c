#include "c-review.h"

static uint32_t global_counter; // A module-level (this file scope) global variable

ret_val_t factorial(const uint8_t x, uint32_t* y) {
    if (y == NULL) return RET_FAIL;

    *y = 1;

    for (uint8_t i = 2; i <= x; i++) {
        if (*y > UINT32_MAX / i) {
            *y = 0;

            return RET_FAIL;
        }

        *y *= i;
    }

    return RET_SUCCESS;
}

ret_val_t vec3_init(vec3_t* v, const float x, const float y, const float z) {
    if (v == NULL) return RET_FAIL;

    v->x = x;
    v->y = y;
    v->z = z;

    return RET_SUCCESS;
}

ret_val_t vec3_dot(const vec3_t v1, const vec3_t v2, float* s) {
    if (s == NULL) return RET_FAIL;

    *s = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;

    return RET_SUCCESS;
}

ret_val_t bit_set(uint16_t* bv, const uint8_t n) {
    if (n > 15 || bv == NULL) return RET_FAIL;

    *bv |= (1 << n);

    return RET_SUCCESS;
}

ret_val_t bit_clear(uint16_t* bv, const uint8_t n) {
    if (n > 15 || bv == NULL) return RET_FAIL;

    *bv &= ~(1 << n);

    return RET_SUCCESS;
}

ret_val_t bit_toggle(uint16_t* bv, const uint8_t n) {
    if (n > 15 || bv == NULL) return RET_FAIL;

    *bv ^= (1 << n);

    return RET_SUCCESS;
}

static bool is_counter_initialized = false;

ret_val_t counter_init(const uint32_t n) {
    if (is_counter_initialized) return RET_FAIL;

    global_counter = n;
    is_counter_initialized = true;

    return RET_SUCCESS;
}

ret_val_t counter_set(const uint32_t n) {
    if (!is_counter_initialized) return RET_FAIL;

    global_counter = n;

    return RET_SUCCESS;
}

ret_val_t counter_dec(void) {
    if (!is_counter_initialized) return RET_FAIL;

    if (global_counter > 0) global_counter--;

    return RET_SUCCESS;
}

ret_val_t counter_get(uint32_t* n) {
    if (!is_counter_initialized || n == NULL) {
        if (n != NULL) *n = 0;

        return RET_FAIL;
    }

    *n = global_counter;

    return RET_SUCCESS;
}
