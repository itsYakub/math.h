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
# include "./math.h"
#
# if !defined (MATHAPI)
#  define MATHAPI static inline
# endif /* MATHAPI */
#
# if defined (__cplusplus)

extern "C" {

# endif /* __cplusplus */

MATHAPI vec2 vec2Init(const float x, const float y) {
    return ((vec2) { .x = x, .y = y } );
}

MATHAPI vec2 vec2Copy(const vec2 v0) {
    return ((vec2) { .x = v0.x, .y = v0.y } );
}

MATHAPI vec2 vec2Zero(void) {
    return ((vec2) { .x = 0.0, .y = 0.0 } );
}

MATHAPI vec2 vec2One(void) {
    return ((vec2) { .x = 1.0, .y = 1.0 } );
}

MATHAPI vec2 vec2Up(void) {
    return ((vec2) { .x = 0.0, .y = 1.0 } );
}

MATHAPI vec2 vec2Down(void) {
    return ((vec2) { .x = 0.0, .y = -1.0 } );
}

MATHAPI vec2 vec2Left(void) {
    return ((vec2) { .x = -1.0, .y = 0.0 } );
}

MATHAPI vec2 vec2Right(void) {
    return ((vec2) { .x = 1.0, .y = 0.0 } );
}

/* ---------------------------------------------------------------------------------------------------- */

MATHAPI vec2 vec2Add(const vec2 v0, const vec2 v1) {
    return ((vec2) { .x = v0.x + v1.x, .y = v0.y + v1.y } );
}

MATHAPI vec2 vec2Addf(const vec2 v0, const float f) {
    return ((vec2) { .x = v0.x + f, .y = v0.y + f } );
}

/* ---------------------------------------------------------------------------------------------------- */

MATHAPI vec2 vec2Sub(const vec2 v0, const vec2 v1) {
    return ((vec2) { .x = v0.x - v1.x, .y = v0.y - v1.y } );
}

MATHAPI vec2 vec2Subf(const vec2 v0, const float f) {
    return ((vec2) { .x = v0.x - f, .y = v0.y - f } );
}

/* ---------------------------------------------------------------------------------------------------- */

MATHAPI vec2 vec2Mul(const vec2 v0, const vec2 v1) {
    return ((vec2) { .x = v0.x * v1.x, .y = v0.y * v1.y } );
}

MATHAPI vec2 vec2Mulf(const vec2 v0, const float f) {
    return ((vec2) { .x = v0.x * f, .y = v0.y * f } );
}

/* ---------------------------------------------------------------------------------------------------- */

MATHAPI vec2 vec2Div(const vec2 v0, const vec2 v1) {
    return ((vec2) { .x = v0.x / v1.x, .y = v0.y / v1.y } );
}

MATHAPI vec2 vec2Divf(const vec2 v0, const float f) {
    return ((vec2) { .x = v0.x / f, .y = v0.y / f } );
}

/* ---------------------------------------------------------------------------------------------------- */

MATHAPI bool vec2Equals(const vec2 v0, const vec2 v1) {
    return (v0.x == v1.x && v0.y == v1.y);
}

/* ---------------------------------------------------------------------------------------------------- */

MATHAPI vec2 vec2Pow(const vec2 v0, float f) {
    return ((vec2) { .x = pow(v0.x, f), .y = pow(v0.y, f) } );
}

MATHAPI vec2 vec2Pow2(const vec2 v0) {
    return ((vec2) { .x = v0.x * v0.x, .y = v0.y * v0.y });
}

MATHAPI vec2 vec2Sqrt(const vec2 v0) {
    return ((vec2) { .x = sqrt(v0.x), .y = sqrt(v0.y) } );
}

/* ---------------------------------------------------------------------------------------------------- */

MATHAPI vec2 vec2Clamp(const vec2 v0, const vec2 min, const vec2 max) {
    return ((vec2) { .x = clamp(v0.x, min.x, max.x), .y = clamp(v0.y, min.y, max.y) } );
}

MATHAPI vec2 vec2Clampf(const vec2 v0, float min, float max) {
    return ((vec2) { .x = clamp(v0.x, min, max), .y = clamp(v0.y, min, max) } );
}

MATHAPI vec2 vec2Clamp01(const vec2 v0) {
    return ((vec2) { .x = clamp01(v0.x), .y = clamp01(v0.y) } );
}

/* ---------------------------------------------------------------------------------------------------- */

MATHAPI float vec2Distance(const vec2 v0, const vec2 v1) {
    return (sqrt(pow2(v0.x - v1.x) + pow2(v0.y - v1.y)));
}

MATHAPI float vec2Length(const vec2 v0) {
    return (sqrt(pow2(v0.x) + pow2(v0.y)));
}

MATHAPI float vec2Dot(const vec2 v0, const vec2 v1) {
    return (v0.x * v1.x + v0.y * v1.y);
}

MATHAPI vec2 vec2Normalize(const vec2 v0) {
    vec2 value = vec2Zero();
    float len = vec2Length(v0);
    if (len > 0.0) {
        value = vec2Mulf(v0, 1.0 / len);
    }
    return (value);
}

MATHAPI vec2 vec2Scale(const vec2 v0, const float f) {
    return (vec2Mulf(v0, f));
}

/* ---------------------------------------------------------------------------------------------------- */

MATHAPI const float *vec2Ptr(const vec2 *v0) { return (&v0->x); }

/* ---------------------------------------------------------------------------------------------------- */

MATHAPI const char *vec2String(const vec2 v0) {
    static char buf[1024];

    if (!memset(buf, 0, sizeof(buf))) { return (0); }
    if (!snprintf(buf, sizeof(buf) - 1, "%f, %f", v0.x, v0.y)) { return (0); }
    return (buf);
}

# if defined (__cplusplus)

}

# endif /* __cplusplus */
#
# if defined (__cplusplus)
#  if !defined (MATH_DISABLE_CPP_OPERATORS)

MATHAPI vec2 operator + (const vec2 &v0, const vec2 &v1)   { return (vec2Add(v0, v1)); }

MATHAPI const vec2& operator += (vec2 &v0, const vec2 &v1) { return ((v0 = vec2Add(v0, v1))); }

MATHAPI vec2 operator - (const vec2 &v0, const vec2 &v1)   { return (vec2Sub(v0, v1)); }

MATHAPI const vec2& operator -= (vec2 &v0, const vec2 &v1) { return ((v0 = vec2Sub(v0, v1))); }

MATHAPI vec2 operator * (const vec2 &v0, const vec2 &v1)   { return (vec2Mul(v0, v1)); }

MATHAPI const vec2& operator *= (vec2 &v0, const vec2 &v1) { return ((v0 = vec2Mul(v0, v1))); }

MATHAPI vec2 operator / (const vec2 &v0, const vec2 &v1)   { return (vec2Div(v0, v1)); }

MATHAPI const vec2& operator /= (vec2 &v0, const vec2 &v1) { return ((v0 = vec2Div(v0, v1))); }

MATHAPI bool operator == (const vec2 &v0, const vec2 &v1)  { return (vec2Equals(v0, v1)); }

MATHAPI bool operator != (const vec2 &v0, const vec2 &v1)  { return (!vec2Equals(v0, v1)); }

#  endif /* MATH_DISABLE_CPP_OPERATORS */
# endif /* __cplusplus */
#endif /* _vec2_h_ */
