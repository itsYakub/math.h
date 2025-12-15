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
# if !defined (MATHAPI_STATIC) && !defined (MATHAPI_EXTERN)
#  define MATHAPI_EXTERN 1
# endif /* MATHAPI_STATIC, MATHAPI_EXTERN */
# if !defined (MATHAPI)
#  if defined (MATHAPI_STATIC)
#   define MATHAPI static inline
#  endif /* MATHAPI_STATIC */
#  if defined (MATHAPI_EXTERN)
#   define MATHAPI extern
#  endif /* MATHAPI_EXTERN */
# endif /* MATHAPI */
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

MATHAPI vec3 vec3Init(const float x, const float y, const float z) {
    return ((vec3) { .x = x, .y = y, .z = z } );
}

MATHAPI vec3 vec3Copy(const vec3 v0) {
    return ((vec3) { .x = v0.x, .y = v0.y, .z = v0.z } );
}

MATHAPI vec3 vec3Zero(void) {
    return ((vec3) { .x = 0.0, .y = 0.0, .z = 0.0 } );
}

MATHAPI vec3 vec3One(void) {
    return ((vec3) { .x = 1.0, .y = 1.0, .z = 1.0 } );
}

MATHAPI vec3 vec3Up(void) {
    return ((vec3) { .x = 0.0, .y = 1.0, .z = 0.0 } );
}

MATHAPI vec3 vec3Down(void) {
    return ((vec3) { .x = 0.0, .y = -1.0, .z = 0.0 } );
}

MATHAPI vec3 vec3Left(void) {
    return ((vec3) { .x = -1.0, .y = 0.0, .z = 0.0 } );
}

MATHAPI vec3 vec3Right(void) {
    return ((vec3) { .x = 1.0, .y = 0.0, .z = 0.0 } );
}

MATHAPI vec3 vec3Forward(void) {
    return ((vec3) { .x = 0.0, .y = 0.0, .z = 1.0 } );
}

MATHAPI vec3 vec3Backward(void) {
    return ((vec3) { .x = 0.0, .y = 0.0, .z = -1.0 } );
}

/* ---------------------------------------------------------------------------------------------------- */

MATHAPI vec3 vec3Add(const vec3 v0, const vec3 v1) {
    return ((vec3) { .x = v0.x + v1.x, .y = v0.y + v1.y, .z = v0.z + v1.z } );
}

MATHAPI vec3 vec3Addf(const vec3 v0, const float f) {
    return ((vec3) { .x = v0.x + f, .y = v0.y + f, .z = v0.z + f } );
}

/* ---------------------------------------------------------------------------------------------------- */

MATHAPI vec3 vec3Sub(const vec3 v0, const vec3 v1) {
    return ((vec3) { .x = v0.x - v1.x, .y = v0.y - v1.y, .z = v0.z - v1.z } );
}

MATHAPI vec3 vec3Subf(const vec3 v0, const float f) {
    return ((vec3) { .x = v0.x - f, .y = v0.y - f, .z = v0.z - f } );
}

/* ---------------------------------------------------------------------------------------------------- */

MATHAPI vec3 vec3Mul(const vec3 v0, const vec3 v1) {
    return ((vec3) { .x = v0.x * v1.x, .y = v0.y * v1.y, .z = v0.z * v1.z } );
}

MATHAPI vec3 vec3Mulf(const vec3 v0, const float f) {
    return ((vec3) { .x = v0.x * f, .y = v0.y * f, .z = v0.z * f } );
}

/* ---------------------------------------------------------------------------------------------------- */

MATHAPI vec3 vec3Div(const vec3 v0, const vec3 v1) {
    return ((vec3) { .x = v0.x / v1.x, .y = v0.y / v1.y, .z = v0.z / v1.z } );
}

MATHAPI vec3 vec3Divf(const vec3 v0, const float f) {
    return ((vec3) { .x = v0.x / f, .y = v0.y / f, .z = v0.z / f } );
}

/* ---------------------------------------------------------------------------------------------------- */

MATHAPI bool vec3Equals(const vec3 v0, const vec3 v1) {
    return (v0.x == v1.x && v0.y == v1.y && v0.z == v1.z);
}

/* ---------------------------------------------------------------------------------------------------- */

MATHAPI vec3 vec3Pow(const vec3 v0, float f) {
    return ((vec3) { .x = pow(v0.x, f), .y = pow(v0.y, f), .z = pow(v0.y, f) } );
}

MATHAPI vec3 vec3Pow2(const vec3 v0) {
    return ((vec3) { .x = v0.x * v0.x, .y = v0.y * v0.y, .z = v0.z * v0.z });
}

MATHAPI vec3 vec3Sqrt(const vec3 v0) {
    return ((vec3) { .x = sqrt(v0.x), .y = sqrt(v0.y), .z = sqrt(v0.z) } );
}

/* ---------------------------------------------------------------------------------------------------- */

MATHAPI vec3 vec3Clamp(const vec3 v0, const vec3 min, const vec3 max) {
    return ((vec3) { .x = clamp(v0.x, min.x, max.x), .y = clamp(v0.y, min.y, max.y), .z = clamp(v0.z, min.z, max.z) } );
}

MATHAPI vec3 vec3Clampf(const vec3 v0, float min, float max) {
    return ((vec3) { .x = clamp(v0.x, min, max), .y = clamp(v0.y, min, max), .z = clamp(v0.z, min, max) } );
}

MATHAPI vec3 vec3Clamp01(const vec3 v0) {
    return ((vec3) { .x = clamp01(v0.x), .y = clamp01(v0.y), .z = clamp01(v0.z) } );
}

/* ---------------------------------------------------------------------------------------------------- */

MATHAPI float vec3Distance(const vec3 v0, const vec3 v1) {
    return (sqrt(pow2(v0.x - v1.x) + pow2(v0.y - v1.y) + pow2(v0.z - v0.z)));
}

MATHAPI float vec3Length(const vec3 v0) {
    return (sqrt(pow2(v0.x) + pow2(v0.y) + pow2(v0.z)));
}

MATHAPI float vec3Dot(const vec3 v0, const vec3 v1) {
    return (v0.x * v1.x + v0.y * v1.y + v0.z * v1.z);
}

MATHAPI vec3 vec3Cross(const vec3 v0, const vec3 v1) {
    vec3 vec;

    vec.x = v0.y * v1.z - v0.z * v1.y;
    vec.y = v0.x * v1.z - v0.z * v1.x;
    vec.z = v0.x * v1.y - v0.x * v1.y;
    return (vec);
}

MATHAPI vec3 vec3Normalize(const vec3 v0) {
    vec3 value = vec3Zero();
    float len = vec3Length(v0);
    if (len > 0.0) {
        value = vec3Mulf(v0, 1.0 / len);
    }
    return (value);
}

MATHAPI vec3 vec3Scale(const vec3 v0, const float f) {
    return (vec3Mulf(v0, f));
}

MATHAPI vec3 vec3Negate(const vec3 v0) {
    return ((vec3) { .x = -v0.x, .y = -v0.y, .z = -v0.z } );
}

/* ---------------------------------------------------------------------------------------------------- */

MATHAPI const float *vec3Ptr(const vec3 *v0) { return (&v0->x); }

/* ---------------------------------------------------------------------------------------------------- */

MATHAPI const char *vec3String(const vec3 v0) {
    static char buf[1024];

    if (!memset(buf, 0, sizeof(buf))) { return (0); }
    if (!snprintf(buf, sizeof(buf) - 1, "%f, %f, %f", v0.x, v0.y, v0.z)) { return (0); }
    return (buf);
}

# if defined (__cplusplus)

}

# endif /* __cplusplus */
#
# if defined (__cplusplus)
#  if !defined (MATH_DISABLE_CPP_OPERATORS)

MATHAPI vec3 operator + (const vec3 &v0, const vec3 &v1)   { return (vec3Add(v0, v1)); }

MATHAPI const vec3& operator += (vec3 &v0, const vec3 &v1) { return ((v0 = vec3Add(v0, v1))); }

MATHAPI vec3 operator - (const vec3 &v0, const vec3 &v1)   { return (vec3Sub(v0, v1)); }

MATHAPI const vec3& operator -= (vec3 &v0, const vec3 &v1) { return ((v0 = vec3Sub(v0, v1))); }

MATHAPI vec3 operator * (const vec3 &v0, const vec3 &v1)   { return (vec3Mul(v0, v1)); }

MATHAPI const vec3& operator *= (vec3 &v0, const vec3 &v1) { return ((v0 = vec3Mul(v0, v1))); }

MATHAPI vec3 operator / (const vec3 &v0, const vec3 &v1)   { return (vec3Div(v0, v1)); }

MATHAPI const vec3& operator /= (vec3 &v0, const vec3 &v1) { return ((v0 = vec3Div(v0, v1))); }

MATHAPI bool operator == (const vec3 &v0, const vec3 &v1)  { return (vec3Equals(v0, v1)); }

MATHAPI bool operator != (const vec3 &v0, const vec3 &v1)  { return (!vec3Equals(v0, v1)); }

#  endif /* MATH_DISABLE_CPP_OPERATORS */
# endif /* __cplusplus */
#endif /* _vec3_h_ */
