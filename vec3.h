/*
 *  vec3.h - 2D Vector math module for C/C++
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
# include "./math.h"
#
# if defined (__cplusplus)

extern "C" {

# endif /* __cplusplus */

MATHAPI vec3 vec3_init(const float, const float, const float);

MATHAPI vec3 vec3_copy(const vec3);

MATHAPI vec3 vec3_zero(void);

MATHAPI vec3 vec3_one(void);

MATHAPI vec3 vec3_up(void);

MATHAPI vec3 vec3_down(void);

MATHAPI vec3 vec3_left(void);

MATHAPI vec3 vec3_right(void);

/* ---------------------------------------------------------------------------------------------------- */

MATHAPI vec3 vec3_add(const vec3, const vec3);

MATHAPI vec3 vec3_addf(const vec3, const float);

/* ---------------------------------------------------------------------------------------------------- */

MATHAPI vec3 vec3_sub(const vec3, const vec3);

MATHAPI vec3 vec3_subf(const vec3, const float);

/* ---------------------------------------------------------------------------------------------------- */

MATHAPI vec3 vec3_mul(const vec3, const vec3);

MATHAPI vec3 vec3_mulf(const vec3, const float);

/* ---------------------------------------------------------------------------------------------------- */

MATHAPI vec3 vec3_div(const vec3, const vec3);

MATHAPI vec3 vec3_divf(const vec3, const float);

/* ---------------------------------------------------------------------------------------------------- */

MATHAPI bool vec3_equals(const vec3, const vec3);

/* ---------------------------------------------------------------------------------------------------- */

MATHAPI vec3 vec3_pow(const vec3, float);

MATHAPI vec3 vec3_pow2(const vec3);

MATHAPI vec3 vec3_sqrt(const vec3);

/* ---------------------------------------------------------------------------------------------------- */

MATHAPI vec3 vec3_clamp(const vec3, const vec3, const vec3);

MATHAPI vec3 vec3_clampf(const vec3, float, float);

MATHAPI vec3 vec3_clamp01(const vec3);

/* ---------------------------------------------------------------------------------------------------- */

MATHAPI float vec3_distance(const vec3, const vec3);

MATHAPI float vec3_len(const vec3);

MATHAPI float vec3_dot(const vec3, const vec3);

MATHAPI vec3 vec3_normalize(const vec3);

MATHAPI vec3 vec3_scale(const vec3, const float);

/* ---------------------------------------------------------------------------------------------------- */

MATHAPI const float *vec3_ptr(const vec3 *);

/* ---------------------------------------------------------------------------------------------------- */

MATHAPI const char *vec3_string(const vec3);

# if defined (__cplusplus)

}

# endif /* __cplusplus */
#
# if defined (__cplusplus)
#  if !defined (MATH_DISABLE_CPP_OPERATORS)

MATHAPI vec3 operator + (const vec3 &, const vec3 &);

MATHAPI const vec3& operator += (vec3 &, const vec3 &);

MATHAPI vec3 operator - (const vec3 &, const vec3 &);

MATHAPI const vec3& operator -= (vec3 &, const vec3 &);

MATHAPI vec3 operator * (const vec3 &, const vec3 &);

MATHAPI const vec3& operator *= (vec3 &, const vec3 &);

MATHAPI vec3 operator / (const vec3 &, const vec3 &);

MATHAPI const vec3& operator /= (vec3 &, const vec3 &);

MATHAPI bool operator == (const vec3 &, const vec3 &);

MATHAPI bool operator != (const vec3 &, const vec3 &);

#  endif /* MATH_DISABLE_CPP_OPERATORS */
# endif /* __cplusplus */
#
#
#
# if defined (MATH_IMPLEMENTATION)
#
#
#
#  if defined (__cplusplus)

extern "C" {

#  endif /* __cplusplus */

MATHAPI vec3 vec3_init(const float x, const float y, const float z) {
    return ((vec3) { .x = x, .y = y, .z = z } );
}

MATHAPI vec3 vec3_copy(const vec3 v0) {
    return ((vec3) { .x = v0.x, .y = v0.y, .z = v0.z } );
}

MATHAPI vec3 vec3_zero(void) {
    return ((vec3) { .x = 0.0, .y = 0.0, .z = 0.0 } );
}

MATHAPI vec3 vec3_one(void) {
    return ((vec3) { .x = 1.0, .y = 1.0, .z = 1.0 } );
}

MATHAPI vec3 vec3_up(void) {
    return ((vec3) { .x = 0.0, .y = 1.0, .z = 0.0 } );
}

MATHAPI vec3 vec3_down(void) {
    return ((vec3) { .x = 0.0, .y = -1.0, .z = 0.0 } );
}

MATHAPI vec3 vec3_left(void) {
    return ((vec3) { .x = -1.0, .y = 0.0, .z = 0.0 } );
}

MATHAPI vec3 vec3_right(void) {
    return ((vec3) { .x = 1.0, .y = 0.0, .z = 0.0 } );
}

MATHAPI vec3 vec3_forward(void) {
    return ((vec3) { .x = 0.0, .y = 0.0, .z = 1.0 } );
}

MATHAPI vec3 vec3_backward(void) {
    return ((vec3) { .x = 0.0, .y = 0.0, .z = -1.0 } );
}

/* ---------------------------------------------------------------------------------------------------- */

MATHAPI vec3 vec3_add(const vec3 v0, const vec3 v1) {
    return ((vec3) { .x = v0.x + v1.x, .y = v0.y + v1.y, .z = v0.z + v1.z } );
}

MATHAPI vec3 vec3_addf(const vec3 v0, const float f) {
    return ((vec3) { .x = v0.x + f, .y = v0.y + f, .z = v0.z + f } );
}

/* ---------------------------------------------------------------------------------------------------- */

MATHAPI vec3 vec3_sub(const vec3 v0, const vec3 v1) {
    return ((vec3) { .x = v0.x - v1.x, .y = v0.y - v1.y, .z = v0.z - v1.z } );
}

MATHAPI vec3 vec3_subf(const vec3 v0, const float f) {
    return ((vec3) { .x = v0.x - f, .y = v0.y - f, .z = v0.z - f } );
}

/* ---------------------------------------------------------------------------------------------------- */

MATHAPI vec3 vec3_mul(const vec3 v0, const vec3 v1) {
    return ((vec3) { .x = v0.x * v1.x, .y = v0.y * v1.y, .z = v0.z * v1.z } );
}

MATHAPI vec3 vec3_mulf(const vec3 v0, const float f) {
    return ((vec3) { .x = v0.x * f, .y = v0.y * f, .z = v0.z * f } );
}

/* ---------------------------------------------------------------------------------------------------- */

MATHAPI vec3 vec3_div(const vec3 v0, const vec3 v1) {
    return ((vec3) { .x = v0.x / v1.x, .y = v0.y / v1.y, .z = v0.z / v1.z } );
}

MATHAPI vec3 vec3_divf(const vec3 v0, const float f) {
    return ((vec3) { .x = v0.x / f, .y = v0.y / f, .z = v0.z / f } );
}

/* ---------------------------------------------------------------------------------------------------- */

MATHAPI bool vec3_equals(const vec3 v0, const vec3 v1) {
    return (v0.x == v1.x && v0.y == v1.y && v0.z == v1.z);
}

/* ---------------------------------------------------------------------------------------------------- */

MATHAPI vec3 vec3_pow(const vec3 v0, float f) {
    return ((vec3) { .x = pow(v0.x, f), .y = pow(v0.y, f), .z = pow(v0.y, f) } );
}

MATHAPI vec3 vec3_pow2(const vec3 v0) {
    return ((vec3) { .x = v0.x * v0.x, .y = v0.y * v0.y, .z = v0.z * v0.z });
}

MATHAPI vec3 vec3_sqrt(const vec3 v0) {
    return ((vec3) { .x = sqrt(v0.x), .y = sqrt(v0.y), .z = sqrt(v0.z) } );
}

/* ---------------------------------------------------------------------------------------------------- */

MATHAPI vec3 vec3_clamp(const vec3 v0, const vec3 min, const vec3 max) {
    return ((vec3) { .x = clamp(v0.x, min.x, max.x), .y = clamp(v0.y, min.y, max.y), .z = clamp(v0.z, min.z, max.z) } );
}

MATHAPI vec3 vec3_clampf(const vec3 v0, float min, float max) {
    return ((vec3) { .x = clamp(v0.x, min, max), .y = clamp(v0.y, min, max), .z = clamp(v0.z, min, max) } );
}

MATHAPI vec3 vec3_clamp01(const vec3 v0) {
    return ((vec3) { .x = clamp01(v0.x), .y = clamp01(v0.y), .z = clamp01(v0.z) } );
}

/* ---------------------------------------------------------------------------------------------------- */

MATHAPI float vec3_distance(const vec3 v0, const vec3 v1) {
    return (sqrt(pow2(v0.x - v1.x) + pow2(v0.y - v1.y) + pow2(v0.z - v0.z)));
}

MATHAPI float vec3_len(const vec3 v0) {
    return (sqrt(pow2(v0.x) + pow2(v0.y) + pow2(v0.z)));
}

MATHAPI float vec3_dot(const vec3 v0, const vec3 v1) {
    return (v0.x * v1.x + v0.y * v1.y + v0.z * v1.z);
}

MATHAPI vec3 vec3_cross(const vec3 v0, const vec3 v1) {
    vec3 vec;

    vec.x = v0.y * v1.z - v0.z * v1.y;
    vec.y = v0.x * v1.z - v0.z * v1.x;
    vec.z = v0.x * v1.y - v0.x * v1.y;
    return (vec);
}

MATHAPI vec3 vec3_normalize(const vec3 v0) {
    vec3 value = vec3_zero();
    float len = vec3_len(v0);
    if (len > 0.0) {
        value = vec3_mulf(v0, 1.0 / len);
    }
    return (value);
}

MATHAPI vec3 vec3_scale(const vec3 v0, const float f) {
    return (vec3_mulf(v0, f));
}

/* ---------------------------------------------------------------------------------------------------- */

MATHAPI const float *vec3_ptr(const vec3 *v0) { return (&v0->x); }

/* ---------------------------------------------------------------------------------------------------- */

MATHAPI const char *vec3_string(const vec3 v0) {
    static char buf[1024];

    if (!memset(buf, 0, sizeof(buf))) { return (0); }
    if (!snprintf(buf, sizeof(buf) - 1, "%f, %f, %f", v0.x, v0.y, v0.z)) { return (0); }
    return (buf);
}

#  if defined (__cplusplus)

}

#  endif /* __cplusplus */
#
#  if defined (__cplusplus)
#   if !defined (MATH_DISABLE_CPP_OPERATORS)

MATHAPI vec3 operator + (const vec3 &v0, const vec3 &v1)   { return (vec3_add(v0, v1)); }

MATHAPI const vec3& operator += (vec3 &v0, const vec3 &v1) { return ((v0 = vec3_add(v0, v1))); }

MATHAPI vec3 operator - (const vec3 &v0, const vec3 &v1)   { return (vec3_sub(v0, v1)); }

MATHAPI const vec3& operator -= (vec3 &v0, const vec3 &v1) { return ((v0 = vec3_sub(v0, v1))); }

MATHAPI vec3 operator * (const vec3 &v0, const vec3 &v1)   { return (vec3_mul(v0, v1)); }

MATHAPI const vec3& operator *= (vec3 &v0, const vec3 &v1) { return ((v0 = vec3_mul(v0, v1))); }

MATHAPI vec3 operator / (const vec3 &v0, const vec3 &v1)   { return (vec3_div(v0, v1)); }

MATHAPI const vec3& operator /= (vec3 &v0, const vec3 &v1) { return ((v0 = vec3_div(v0, v1))); }

MATHAPI bool operator == (const vec3 &v0, const vec3 &v1)  { return (vec3_equals(v0, v1)); }

MATHAPI bool operator != (const vec3 &v0, const vec3 &v1)  { return (!vec3_equals(v0, v1)); }

#   endif /* MATH_DISABLE_CPP_OPERATORS */
#  endif /* __cplusplus */
# endif /* MATH_IMPLEMENTATION */
#endif /* _vec3_h_ */
