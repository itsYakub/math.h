/*
 *  vec4.h - 4D Vector math module for C/C++
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#if defined (__cplusplus)
# pragma once
#endif /* __cplusplus */
#if !defined (_vec4_h_)
# define _vec4_h_ 1
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

MATHAPI vec4 vec4_init(const float, const float, const float, const float);

MATHAPI vec4 vec4_copy(const vec4);

MATHAPI vec4 vec4_zero(void);

MATHAPI vec4 vec4_one(void);

/* ---------------------------------------------------------------------------------------------------- */

MATHAPI vec4 vec4_add(const vec4, const vec4);

MATHAPI vec4 vec4_addf(const vec4, const float);

/* ---------------------------------------------------------------------------------------------------- */

MATHAPI vec4 vec4_sub(const vec4, const vec4);

MATHAPI vec4 vec4_subf(const vec4, const float);

/* ---------------------------------------------------------------------------------------------------- */

MATHAPI vec4 vec4_mul(const vec4, const vec4);

MATHAPI vec4 vec4_mulf(const vec4, const float);

/* ---------------------------------------------------------------------------------------------------- */

MATHAPI vec4 vec4_div(const vec4, const vec4);

MATHAPI vec4 vec4_divf(const vec4, const float);

/* ---------------------------------------------------------------------------------------------------- */

MATHAPI bool vec4_equals(const vec4, const vec4);

/* ---------------------------------------------------------------------------------------------------- */

MATHAPI vec4 vec4_pow(const vec4, float);

MATHAPI vec4 vec4_pow2(const vec4);

MATHAPI vec4 vec4_sqrt(const vec4);

/* ---------------------------------------------------------------------------------------------------- */

MATHAPI vec4 vec4_clamp(const vec4, const vec4, const vec4);

MATHAPI vec4 vec4_clampf(const vec4, float, float);

MATHAPI vec4 vec4_clamp01(const vec4);

/* ---------------------------------------------------------------------------------------------------- */

MATHAPI float vec4_distance(const vec4, const vec4);

MATHAPI float vec4_len(const vec4);

MATHAPI float vec4_dot(const vec4, const vec4);

MATHAPI vec4 vec4_normalize(const vec4);

MATHAPI vec4 vec4_scale(const vec4, const float);

/* ---------------------------------------------------------------------------------------------------- */

MATHAPI const float *vec4_ptr(const vec4 *);

/* ---------------------------------------------------------------------------------------------------- */

MATHAPI const char *vec4_string(const vec4);

# if defined (__cplusplus)

}

# endif /* __cplusplus */
#
# if defined (__cplusplus)
#  if !defined (MATH_DISABLE_CPP_OPERATORS)

MATHAPI vec4 operator + (const vec4 &, const vec4 &);

MATHAPI const vec4& operator += (vec4 &, const vec4 &);

MATHAPI vec4 operator - (const vec4 &, const vec4 &);

MATHAPI const vec4& operator -= (vec4 &, const vec4 &);

MATHAPI vec4 operator * (const vec4 &, const vec4 &);

MATHAPI const vec4& operator *= (vec4 &, const vec4 &);

MATHAPI vec4 operator / (const vec4 &, const vec4 &);

MATHAPI const vec4& operator /= (vec4 &, const vec4 &);

MATHAPI bool operator == (const vec4 &, const vec4 &);

MATHAPI bool operator != (const vec4 &, const vec4 &);

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

MATHAPI vec4 vec4_init(const float x, const float y, const float z, const float w) { return ((vec4) { .x = x, .y = y, .z = z, .w = w } ); }

MATHAPI vec4 vec4_copy(const vec4 v0) { return ((vec4) { .x = v0.x, .y = v0.y, .z = v0.z, .w = v0.w } ); }

MATHAPI vec4 vec4_zero(void) { return (vec4_init(0.0, 0.0, 0.0, 0.0)); }

MATHAPI vec4 vec4_one(void) { return (vec4_init(1.0, 1.0, 1.0, 1.0)); }

/* ---------------------------------------------------------------------------------------------------- */

MATHAPI vec4 vec4_add(const vec4 v0, const vec4 v1) { return (vec4_init(v0.x + v1.x, v0.y + v1.y, v0.z + v1.z, v0.w + v1.w)); }

MATHAPI vec4 vec4_addf(const vec4 v0, const float f) { return (vec4_init(v0.x + f, v0.y + f, v0.z + f, v0.w + f)); }

/* ---------------------------------------------------------------------------------------------------- */

MATHAPI vec4 vec4_sub(const vec4 v0, const vec4 v1) { return (vec4_init(v0.x - v1.x, v0.y - v1.y, v0.z - v1.z, v0.w - v1.w)); }

MATHAPI vec4 vec4_subf(const vec4 v0, const float f) { return (vec4_init(v0.x - f, v0.y - f, v0.z - f, v0.w - f)); }

/* ---------------------------------------------------------------------------------------------------- */

MATHAPI vec4 vec4_mul(const vec4 v0, const vec4 v1) { return (vec4_init(v0.x * v1.x, v0.y * v1.y, v0.z * v1.z, v0.w * v1.w)); }

MATHAPI vec4 vec4_mulf(const vec4 v0, const float f) { return (vec4_init(v0.x * f, v0.y * f, v0.z * f, v0.w * f)); }

/* ---------------------------------------------------------------------------------------------------- */

MATHAPI vec4 vec4_div(const vec4 v0, const vec4 v1) { return (vec4_init(v0.x / v1.x, v0.y / v1.y, v0.z / v1.z, v0.w / v1.w)); }

MATHAPI vec4 vec4_divf(const vec4 v0, const float f) { return (vec4_init(v0.x / f, v0.y / f, v0.z / f, v0.w / f)); }

/* ---------------------------------------------------------------------------------------------------- */

MATHAPI bool vec4_equals(const vec4 v0, const vec4 v1) { return (v0.x == v1.x && v0.y == v1.y && v0.z == v1.z && v0.w == v1.w); }

/* ---------------------------------------------------------------------------------------------------- */

MATHAPI vec4 vec4_pow(const vec4 v0, float f) { return (vec4_init(pow(v0.x, f), pow(v0.y, f), pow(v0.z, f), pow(v0.w, f))); }

MATHAPI vec4 vec4_pow2(const vec4 v0) { return (vec4_init(v0.x * v0.x, v0.y * v0.y, v0.z * v0.z, v0.w * v0.w)); }

MATHAPI vec4 vec4_sqrt(const vec4 v0) { return (vec4_init(sqrt(v0.x), sqrt(v0.y), sqrt(v0.z), sqrt(v0.w))); }

/* ---------------------------------------------------------------------------------------------------- */

MATHAPI vec4 vec4_clamp(const vec4 v0, const vec4 min, const vec4 max) {
    return (vec4_init(clamp(v0.x, min.x, max.x), clamp(v0.y, min.y, max.y), clamp(v0.z, min.z, max.z), clamp(v0.w, min.w, max.w)));
}

MATHAPI vec4 vec4_clampf(const vec4 v0, float min, float max) {
    return (vec4_init(clamp(v0.x, min, max), clamp(v0.y, min, max), clamp(v0.z, min, max), clamp(v0.w, min, max)));
}

MATHAPI vec4 vec4_clamp01(const vec4 v0) {
    return (vec4_init(clamp01(v0.x), clamp01(v0.y), clamp01(v0.z), clamp01(v0.w)));
}

/* ---------------------------------------------------------------------------------------------------- */

MATHAPI float vec4_distance(const vec4 v0, const vec4 v1) {
    return (sqrt(pow(v0.x - v1.x, 2.0) + pow(v0.y - v1.y, 2.0) + pow(v0.z - v1.z, 2.0) + pow(v0.w - v1.w, 2.0)));
}

MATHAPI float vec4_len(const vec4 v0) {
    return (sqrt(pow(v0.x, 2.0) + pow(v0.y, 2.0) + pow(v0.z, 2.0) + pow(v0.w, 2.0)));
}

MATHAPI float vec4_dot(const vec4 v0, const vec4 v1) {
    return (v0.x * v1.x + v0.y * v1.y + v0.z * v1.z + v0.w * v1.w);
}

MATHAPI vec4 vec4_normalize(const vec4 v0) {
    vec4 value = vec4_zero();
    float len = vec4_len(v0);
    if (len > 0.0) {
        value = vec4_mulf(v0, 1.0 / len);
    }
    return (value);
}

MATHAPI vec4 vec4_scale(const vec4 v0, const float f0) {
    return (vec4_mulf(v0, f0));
}

/* ---------------------------------------------------------------------------------------------------- */

MATHAPI const float *vec4_ptr(const vec4 *v0) { return (&v0->x); }

/* ---------------------------------------------------------------------------------------------------- */

MATHAPI const char *vec4_string(const vec4 v0) {
    static char buf[1024];

    if (!memset(buf, 0, sizeof(buf))) { return (0); }
    if (!snprintf(buf, sizeof(buf) - 1, "%f, %f, %f, %f", v0.x, v0.y, v0.z, v0.w)) { return (0); }
    return (buf);
}

# if defined (__cplusplus)

}

# endif /* __cplusplus */
#
# if defined (__cplusplus)
#  if !defined (MATH_DISABLE_CPP_OPERATORS)

MATHAPI vec4 operator + (const vec4 &v0, const vec4 &v1)   { return (vec4_add(v0, v1)); }

MATHAPI const vec4& operator += (vec4 &v0, const vec4 &v1) { return ((v0 = vec4_add(v0, v1))); }

MATHAPI vec4 operator - (const vec4 &v0, const vec4 &v1)   { return (vec4_sub(v0, v1)); }

MATHAPI const vec4& operator -= (vec4 &v0, const vec4 &v1) { return ((v0 = vec4_sub(v0, v1))); }

MATHAPI vec4 operator * (const vec4 &v0, const vec4 &v1)   { return (vec4_mul(v0, v1)); }

MATHAPI const vec4& operator *= (vec4 &v0, const vec4 &v1) { return ((v0 = vec4_mul(v0, v1))); }

MATHAPI vec4 operator / (const vec4 &v0, const vec4 &v1)   { return (vec4_div(v0, v1)); }

MATHAPI const vec4& operator /= (vec4 &v0, const vec4 &v1) { return ((v0 = vec4_div(v0, v1))); }

MATHAPI bool operator == (const vec4 &v0, const vec4 &v1)  { return (vec4_equals(v0, v1)); }

MATHAPI bool operator != (const vec4 &v0, const vec4 &v1)  { return (!vec4_equals(v0, v1)); }

#   endif /* MATH_DISABLE_CPP_OPERATORS */
#  endif /* __cplusplus */
# endif /* MATH_IMPLEMENTATION */
#endif /* _vec4_h_ */
