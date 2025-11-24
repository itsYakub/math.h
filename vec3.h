/*
 *  vec3.h - 3D Vector math module for C/C++
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#if defined (__cplusplus)
# pragma once
#endif /* __cplusplus */
#if !defined (_vec3_h_)
# define _vec3_h_ 1
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

typedef union u_vec3 vec3;
union u_vec3 {
    struct {
        float x;
        float y;
        float z;
    };
    
    struct {
        float r;
        float g;
        float b;
    };

    float ptr[3];
};

/* ---------------------------------------------------------------------------------------------------- */

static inline vec3 vec3_init(const float x, const float y, const float z) {
    return ((vec3) { .x = x, .y = y, .z = z } );
}

static inline vec3 vec3_copy(const vec3 v0) {
    return ((vec3) { .x = v0.x, .y = v0.y, .z = v0.z } );
}

static inline vec3 vec3_zero(void) {
    return (vec3_init(0.0, 0.0, 0.0));
}

static inline vec3 vec3_one(void) {
    return (vec3_init(1.0, 1.0, 1.0));
}

static inline vec3 vec3_up(void) {
    return (vec3_init(0.0, 1.0, 0.0));
}

static inline vec3 vec3_down(void) {
    return (vec3_init(0.0, -1.0, 0.0));
}

static inline vec3 vec3_left(void) {
    return (vec3_init(-1.0, 0.0, 0.0));
}

static inline vec3 vec3_right(void) {
    return (vec3_init(1.0, 0.0, 0.0));
}

static inline vec3 vec3_front(void) {
    return (vec3_init(0.0, 0.0, 1.0));
}

static inline vec3 vec3_back(void) {
    return (vec3_init(0.0, 0.0, -1.0));
}

/* ---------------------------------------------------------------------------------------------------- */

static inline vec3 vec3_add(const vec3 v0, const vec3 v1) {
    return (vec3_init(v0.x + v1.x, v0.y + v1.y, v0.z + v1.z));
}

static inline vec3 vec3_addf(const vec3 v0, const float f) {
    return (vec3_init(v0.x + f, v0.y + f, v0.z + f));
}

# if defined (__cplusplus)
#  if !defined (MATH_DISABLE_CPP_OPERATORS)

static inline vec3 operator + (const vec3 &v0, const vec3 &v1) {
    return (vec3_add(v0, v1));
}

const static inline vec3& operator += (vec3 &v0, const vec3 &v1) {
    v0 = vec3_add(v0, v1); return (v0);
}

#  endif /* MATH_DISABLE_CPP_OPERATORS */
# endif /* __cplusplus */

/* ---------------------------------------------------------------------------------------------------- */

static inline vec3 vec3_sub(const vec3 v0, const vec3 v1) {
    return (vec3_init(v0.x - v1.x, v0.y - v1.y, v0.z - v1.z));
}

static inline vec3 vec3_subf(const vec3 v0, const float f) {
    return (vec3_init(v0.x - f, v0.y - f, v0.z - f));
}

# if defined (__cplusplus)
#  if !defined (MATH_DISABLE_CPP_OPERATORS)

static inline vec3 operator - (const vec3 &v0, const vec3 &v1) {
    return (vec3_sub(v0, v1));
}

const static inline vec3& operator -= (vec3 &v0, const vec3 &v1) {
    v0 = vec3_sub(v0, v1); return (v0);
}

#  endif /* MATH_DISABLE_CPP_OPERATORS */
# endif /* __cplusplus */

/* ---------------------------------------------------------------------------------------------------- */

static inline vec3 vec3_mul(const vec3 v0, const vec3 v1) {
    return (vec3_init(v0.x * v1.x, v0.y * v1.y, v0.z * v1.z));
}

static inline vec3 vec3_mulf(const vec3 v0, const float f) {
    return (vec3_init(v0.x * f, v0.y * f, v0.z * f));
}

# if defined (__cplusplus)
#  if !defined (MATH_DISABLE_CPP_OPERATORS)

static inline vec3 operator * (const vec3 &v0, const vec3 &v1) {
    return (vec3_mul(v0, v1));
}

const static inline vec3& operator *= (vec3 &v0, const vec3 &v1) {
    v0 = vec3_mul(v0, v1); return (v0);
}

#  endif /* MATH_DISABLE_CPP_OPERATORS */
# endif /* __cplusplus */

/* ---------------------------------------------------------------------------------------------------- */

static inline vec3 vec3_div(const vec3 v0, const vec3 v1) {
    return (vec3_init(v0.x / v1.x, v0.y / v1.y, v0.z / v1.z));
}

static inline vec3 vec3_divf(const vec3 v0, const float f) {
    return (vec3_init(v0.x / f, v0.y / f, v0.z / f));
}

# if defined (__cplusplus)
#  if !defined (MATH_DISABLE_CPP_OPERATORS)

static inline vec3 operator / (const vec3 &v0, const vec3 &v1) {
    return (vec3_div(v0, v1));
}

const static inline vec3& operator /= (vec3 &v0, const vec3 &v1) {
    v0 = vec3_div(v0, v1); return (v0);
}

#  endif /* MATH_DISABLE_CPP_OPERATORS */
# endif /* __cplusplus */

/* ---------------------------------------------------------------------------------------------------- */

static inline bool vec3_equals(const vec3 v0, const vec3 v1) {
    return (v0.x == v1.x && v0.y == v1.y && v0.z == v1.z);
}

# if defined (__cplusplus)
#  if !defined (MATH_DISABLE_CPP_OPERATORS)

static inline bool operator == (const vec3 &v0, const vec3 &v1) {
    return (vec3_equals(v0, v1));
}

static inline bool operator != (const vec3 &v0, const vec3 &v1) {
    return (!vec3_equals(v0, v1));
}

#  endif /* MATH_DISABLE_CPP_OPERATORS */
# endif /* __cplusplus */

/* ---------------------------------------------------------------------------------------------------- */

static inline vec3 vec3_pow(const vec3 v0, float f) {
    return (vec3_init(pow(v0.x, f), pow(v0.y, f), pow(v0.y, f)));
}

static inline vec3 vec3_sqrt(const vec3 v0) {
    return (vec3_init(sqrt(v0.x), sqrt(v0.y), sqrt(v0.z)));
}

/* ---------------------------------------------------------------------------------------------------- */

static inline vec3 vec3_clamp(const vec3 v0, const vec3 min, const vec3 max) {
    return (vec3_init(clamp(v0.x, min.x, max.x), clamp(v0.y, min.y, max.y), clamp(v0.z, min.z, max.z)));
}

static inline vec3 vec3_clampf(const vec3 v0, float min, float max) {
    return (vec3_init(clamp(v0.x, min, max), clamp(v0.y, min, max), clamp(v0.z, min, max)));
}

static inline vec3 vec3_clamp01(const vec3 v0) {
    return (vec3_init(clamp01(v0.x), clamp01(v0.y), clamp01(v0.z)));
}

/* ---------------------------------------------------------------------------------------------------- */

static inline float vec3_dis(const vec3 v0, const vec3 v1) {
    return (sqrt(pow(v0.x - v1.x, 2.0) + pow(v0.y - v1.y, 2.0) + pow(v0.z - v1.z, 2.0)));
}

static inline float vec3_len(const vec3 v0) {
    return (sqrt(pow(v0.x, 2.0) + pow(v0.y, 2.0) + pow(v0.z, 2.0)));
}

static inline float vec3_dot(const vec3 v0, const vec3 v1) {
    return (v0.x * v1.x + v0.y * v1.y + v0.z * v1.z);
}

/* ---------------------------------------------------------------------------------------------------- */

static inline const char *vec3_string(const vec3 v0) {
    static char buf[1024];

    if (!memset(buf, 0, sizeof(buf))) { return (0); }
    if (!snprintf(buf, sizeof(buf) - 1, "%f, %f, %f", v0.x, v0.y, v0.z)) { return (0); }
    return (buf);
}

/* ---------------------------------------------------------------------------------------------------- */

# if defined (__cplusplus)

}

# endif /* __cplusplus */
#endif /* _vec3_h_ */
