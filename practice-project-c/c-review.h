/* Review of C programming fundamentals */
#pragma once

#include <stdint.h>
/* Use 'standard int' types
 * unsigned char  -> uint8_t (8 bit unsigned)
 * unsigned short -> uint16_t (16 bit unsigned)
 * unsigned int   -> uint32_t (32 bit unsigned integer)
 */

#include <stdbool.h>
 /* Use more intuitive "bool" for Boolean type
  * bool a = true;
  * bool b = false; */

#include "retval.h"
  /* Use standard function return values and types */

  /* A simple arithmetic function that computes y = x! (factorial) and
   * returns RET_SUCCESS if y fits in an unsigned 32 bit value.  The
   * function returns y=0 and RET_FAIL if y does not fit in an unsigned
   * 32 bit value or if y is a null pointer */
ret_val_t factorial(const uint8_t x, uint32_t* y);

/* A vector size 3 of signed integers */
typedef struct vec3_s {
    float x;
    float y;
    float z;
} vec3_t;

/* Initialize the contents of a vec3 type - return RET_SUCCESS if successful
* or RET_FAIL if the vec3_t pointer is null  */
ret_val_t vec3_init(vec3_t* v, const float x, const float y, const float z);

/* Compute the dot product (also called the scalar product) of two vec3 vectors:
 * v3 = v1 dot v2 and return RET_SUCCESS.  If v1, v2, or v3 are null pointers
 * return RET_FAIL */
ret_val_t vec3_dot(const vec3_t v1, const vec3_t v2, float* s);

/* Set the nth bit of the 16-bit bitvector bv and return RET_SUCCESS
 * The least significant bit (LSB) is the n=0 bit.  The most significant
 * bit (MSB) is the n=15 bit.  If n is > 15 return RET_FAIL
 * Example: if bv = 1010 (binary representation)
 * bit_set(&bv, 0) returns bv = 1011
 * bit_set(&bv, 1) returns bv = 1010 */
ret_val_t bit_set(uint16_t* bv, const uint8_t n);

/* Clear the nth bit of the 16-bit bitvector bv and return RET_SUCCESS.
 * If n > 15 return RET_FAIL */
ret_val_t bit_clear(uint16_t* bv, const uint8_t n);

/* Toggle the nth bit of the 16-bit bitvector bv and return RET_SUCCESS.
 * If n > 15 return RET_FAIL */
ret_val_t bit_toggle(uint16_t* bv, const uint8_t n);

/* Initialize Lab0.c's hidden variable 'global_counter' to n if it has not
 * previously been initialized (by a call to counter_init()) and return
 * RET_SUCCESS.  If counter_init() has already been called return RET_FAIL
 * and do not update the internal counter with the argument to counter_init().
 * HINT: declare another 'static' global variable in lab0.c and use this
 * to indicate if counter_init() has been called or not. */
ret_val_t counter_init(const uint32_t n);

/* Set Lab0.c's hidden varilable 'global_counter' to n and
 * return RET_SUCCESS if counter_init() has previously been called.  Otherwise
 * return RET_FAIL.
 */
ret_val_t counter_set(const uint32_t n);

/* If Lab0.c's hidden variable 'global_counter' has been initialized and is
 * currently > 0, decrement the counter by 1 and return RET_SUCCESS.  If
 * the counter is already 0 do not decrement the counter but return RET_SUCCESS.
 * If counter_init() has not previously been called return RET_FAIL */
ret_val_t counter_dec(void);

/* If counter_init() has been called set n to the current global_counter value
 * and return RET_SUCCESS.  Otherwise set n to 0 and return RET_FAIL */
ret_val_t counter_get(uint32_t* n);
