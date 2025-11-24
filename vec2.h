/*
 *  vec2.h - 2D Vector math module for C/C++
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#if defined (__cplusplus)
# pragma once
#endif /* __cplusplus */
#if !defined (_vec2_h_)
# define _vec2_h_ 1
#
# if !defined (__cplusplus)
#  include <stdio.h>
#  include <string.h>
#  include <stdbool.h>
# else 
#  include <cstdio>
#  include <cstring>
# endif /* __cplusplus */
# include "./common.h"
#
# if defined (__cplusplus)

extern "C" {

# endif /* __cplusplus */

/* ---------------------------------------------------------------------------------------------------- */

typedef union u_vec2 vec2;
union u_vec2 {
    struct {
        float x;
        float y;
    };

    struct {
        float w;
        float h;
    };
};

/* ---------------------------------------------------------------------------------------------------- */

static inline vec2 vec2_init(const float x, const float y) { return ((vec2) { .x = x, .y = y } ); }

static inline vec2 vec2_copy(const vec2 v0) { return ((vec2) { .x = v0.x, .y = v0.y } ); }

static inline vec2 vec2_zero(void) { return (vec2_init(0.0, 0.0)); }

static inline vec2 vec2_one(void) { return (vec2_init(1.0, 1.0)); }

static inline vec2 vec2_up(void) { return (vec2_init(0.0, 1.0)); }

static inline vec2 vec2_down(void) { return (vec2_init(0.0, -1.0)); }

static inline vec2 vec2_left(void) { return (vec2_init(-1.0, 0.0)); }

static inline vec2 vec2_right(void) { return (vec2_init(1.0, 0.0)); }

/* ---------------------------------------------------------------------------------------------------- */

static inline vec2 vec2_add(const vec2 v0, const vec2 v1) { return (vec2_init(v0.x + v1.x, v0.y + v1.y)); }

static inline vec2 vec2_addf(const vec2 v0, const float f) { return (vec2_init(v0.x + f, v0.y + f)); }

# if defined (__cplusplus)
#  if !defined (MATH_DISABLE_CPP_OPERATORS)

static inline vec2 operator + (const vec2 &v0, const vec2 &v1) { return (vec2_add(v0, v1)); }

const static inline vec2& operator += (vec2 &v0, const vec2 &v1) { return ((v0 = vec2_add(v0, v1))); }

#  endif /* MATH_DISABLE_CPP_OPERATORS */
# endif /* __cplusplus */

/* ---------------------------------------------------------------------------------------------------- */

static inline vec2 vec2_sub(const vec2 v0, const vec2 v1) { return (vec2_init(v0.x - v1.x, v0.y - v1.y)); }

static inline vec2 vec2_subf(const vec2 v0, const float f) { return (vec2_init(v0.x - f, v0.y - f)); }

# if defined (__cplusplus)
#  if !defined (MATH_DISABLE_CPP_OPERATORS)

static inline vec2 operator - (const vec2 &v0, const vec2 &v1)   { return (vec2_sub(v0, v1)); }
const static inline vec2& operator -= (vec2 &v0, const vec2 &v1) { return ((v0 = vec2_sub(v0, v1))); }

#  endif /* MATH_DISABLE_CPP_OPERATORS */
# endif /* __cplusplus */

/* ---------------------------------------------------------------------------------------------------- */

static inline vec2 vec2_mul(const vec2 v0, const vec2 v1)  { return (vec2_init(v0.x * v1.x, v0.y * v1.y)); }
static inline vec2 vec2_mulf(const vec2 v0, const float f) { return (vec2_init(v0.x * f, v0.y * f)); }

# if defined (__cplusplus)
#  if !defined (MATH_DISABLE_CPP_OPERATORS)

static inline vec2 operator * (const vec2 &v0, const vec2 &v1)   { return (vec2_mul(v0, v1)); }
const static inline vec2& operator *= (vec2 &v0, const vec2 &v1) { return ((v0 = vec2_mul(v0, v1))); }

#  endif /* MATH_DISABLE_CPP_OPERATORS */
# endif /* __cplusplus */

/* ---------------------------------------------------------------------------------------------------- */

static inline vec2 vec2_div(const vec2 v0, const vec2 v1)  { return (vec2_init(v0.x / v1.x, v0.y / v1.y)); }
static inline vec2 vec2_divf(const vec2 v0, const float f) { return (vec2_init(v0.x / f, v0.y / f)); }

# if defined (__cplusplus)
#  if !defined (MATH_DISABLE_CPP_OPERATORS)

static inline vec2 operator / (const vec2 &v0, const vec2 &v1)   { return (vec2_div(v0, v1)); }
const static inline vec2& operator /= (vec2 &v0, const vec2 &v1) { return ((v0 = vec2_div(v0, v1))); }

#  endif /* MATH_DISABLE_CPP_OPERATORS */
# endif /* __cplusplus */

/* ---------------------------------------------------------------------------------------------------- */

static inline bool vec2_equals(const vec2 v0, const vec2 v1) { return (v0.x == v1.x && v0.y == v1.y); }

# if defined (__cplusplus)
#  if !defined (MATH_DISABLE_CPP_OPERATORS)

static inline bool operator == (const vec2 &v0, const vec2 &v1) { return (vec2_equals(v0, v1)); }
static inline bool operator != (const vec2 &v0, const vec2 &v1) { return (!vec2_equals(v0, v1)); }

#  endif /* MATH_DISABLE_CPP_OPERATORS */
# endif /* __cplusplus */

/* ---------------------------------------------------------------------------------------------------- */

static inline vec2 vec2_pow(const vec2 v0, float f) { return (vec2_init(pow(v0.x, f), pow(v0.y, f))); }

static inline vec2 vec2_sqrt(const vec2 v0) { return (vec2_init(sqrt(v0.x), sqrt(v0.y))); }

/* ---------------------------------------------------------------------------------------------------- */

static inline vec2 vec2_clamp(const vec2 v0, const vec2 min, const vec2 max) {
    return (vec2_init(clamp(v0.x, min.x, max.x), clamp(v0.y, min.y, max.y)));
}

static inline vec2 vec2_clampf(const vec2 v0, float min, float max) {
    return (vec2_init(clamp(v0.x, min, max), clamp(v0.y, min, max)));
}

static inline vec2 vec2_clamp01(const vec2 v0) {
    return (vec2_init(clamp01(v0.x), clamp01(v0.y)));
}

/* ---------------------------------------------------------------------------------------------------- */

static inline float vec2_dis(const vec2 v0, const vec2 v1) { return (sqrt(pow(v0.x - v1.x, 2.0) + pow(v0.y - v1.y, 2.0))); }

static inline float vec2_len(const vec2 v0) { return (sqrt(pow(v0.x, 2.0) + pow(v0.y, 2.0))); }

static inline float vec2_dot(const vec2 v0, const vec2 v1) { return (v0.x * v1.x + v0.y * v1.y); }

static inline float vec2_det(const vec2 v0, const vec2 v1) { return (v0.x * v1.y + v0.y * v1.x); }

/* ---------------------------------------------------------------------------------------------------- */

static inline const char *vec2_string(const vec2 v0) {
    static char buf[1024];

    if (!memset(buf, 0, sizeof(buf))) { return (0); }
    if (!snprintf(buf, sizeof(buf) - 1, "%f, %f", v0.x, v0.y)) { return (0); }
    return (buf);
}

/* ---------------------------------------------------------------------------------------------------- */

# if defined (__cplusplus)

}

# endif /* __cplusplus */
#endif /* _vec2_h_ */
