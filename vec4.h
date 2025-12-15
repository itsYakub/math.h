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
# if !defined (MATHAPI_STATIC) && !defined (MATHAPI_EXTERN)
#  define MATHAPI_EXTERN 1
# endif /* MATHAPI_STATIC, MATHAPI_EXTERN */
# if !defined (MATHAPI)
#  if defined (MATHAPI_STATIC)
#   define MATHAPI static inline
#   define MATHAPI_IMPLEMENTATION 1
#  endif /* MATHAPI_STATIC */
#  if defined (MATHAPI_EXTERN)
#   define MATHAPI extern
#  endif /* MATHAPI_EXTERN */
# endif /* MATHAPI */
#
# include "./struct.h"
#
# if defined (__cplusplus)

extern "C" {

# endif /* __cplusplus */

MATHAPI vec4 vec4Init(const float, const float, const float, const float);


MATHAPI vec4 vec4Copy(const vec4);


MATHAPI vec4 vec4Zero(void);


MATHAPI vec4 vec4One(void);


MATHAPI vec4 vec4Add(const vec4, const vec4);


MATHAPI vec4 vec4Addf(const vec4, const float);


MATHAPI vec4 vec4Sub(const vec4, const vec4);


MATHAPI vec4 vec4Subf(const vec4, const float);


MATHAPI vec4 vec4Mul(const vec4, const vec4);


MATHAPI vec4 vec4Mulf(const vec4, const float);


MATHAPI vec4 vec4Div(const vec4, const vec4);


MATHAPI vec4 vec4Divf(const vec4, const float);


MATHAPI int vec4Equals(const vec4, const vec4);


MATHAPI vec4 vec4Pow(const vec4, float);


MATHAPI vec4 vec4Pow2(const vec4);


MATHAPI vec4 vec4Sqrt(const vec4);


MATHAPI vec4 vec4Clamp(const vec4, const vec4, const vec4);


MATHAPI vec4 vec4Clampf(const vec4, float, float);


MATHAPI vec4 vec4Clamp01(const vec4);


MATHAPI float vec4Distance(const vec4, const vec4);


MATHAPI float vec4Length(const vec4);


MATHAPI float vec4Dot(const vec4, const vec4);


MATHAPI vec4 vec4Normalize(const vec4);


MATHAPI vec4 vec4Scale(const vec4, const float);

# if defined (__cplusplus)

}

# endif /* __cplusplus */
#
# if defined (__cplusplus)
#  if !defined (MATH_DISABLE_CPP_OPERATORS)

MATHAPI vec4 operator + (const vec4 &v0, const vec4 &v1);


MATHAPI const vec4& operator += (vec4 &v0, const vec4 &v1);


MATHAPI vec4 operator - (const vec4 &v0, const vec4 &v1);


MATHAPI const vec4& operator -= (vec4 &v0, const vec4 &v1);


MATHAPI vec4 operator * (const vec4 &v0, const vec4 &v1);


MATHAPI const vec4& operator *= (vec4 &v0, const vec4 &v1);


MATHAPI vec4 operator / (const vec4 &v0, const vec4 &v1);


MATHAPI const vec4& operator /= (vec4 &v0, const vec4 &v1);


MATHAPI bool operator == (const vec4 &v0, const vec4 &v1);


MATHAPI bool operator != (const vec4 &v0, const vec4 &v1);

#  endif /* MATH_DISABLE_CPP_OPERATORS */
# endif /* __cplusplus */
#
# if defined (MATHAPI_IMPLEMENTATION)
#
#  include "./common.h"
#
#  if defined (__cplusplus)

extern "C" {

#  endif /* __cplusplus */

MATHAPI vec4 vec4Init(const float x, const float y, const float z, const float w) {
    return ((vec4) { .x = x, .y = y, .z = z, .w = w } );
}


MATHAPI vec4 vec4Copy(const vec4 v0) {
    return ((vec4) { .x = v0.x, .y = v0.y, .z = v0.z, .w = v0.w } );
}


MATHAPI vec4 vec4Zero(void) {
    return ((vec4) { 0.0, 0.0, 0.0, 0.0 } );
}


MATHAPI vec4 vec4One(void) {
    return ((vec4) { 1.0, 1.0, 1.0, 1.0 } );
}


MATHAPI vec4 vec4Add(const vec4 v0, const vec4 v1) {
    return ((vec4) { v0.x + v1.x, v0.y + v1.y, v0.z + v1.z, v0.w + v1.w } );
}


MATHAPI vec4 vec4Addf(const vec4 v0, const float f) {
    return ((vec4) { v0.x + f, v0.y + f, v0.z + f, v0.w + f } );
}


MATHAPI vec4 vec4Sub(const vec4 v0, const vec4 v1) {
    return ((vec4) { v0.x - v1.x, v0.y - v1.y, v0.z - v1.z, v0.w - v1.w } );
}


MATHAPI vec4 vec4Subf(const vec4 v0, const float f) {
    return ((vec4) { v0.x - f, v0.y - f, v0.z - f, v0.w - f } );
}


MATHAPI vec4 vec4Mul(const vec4 v0, const vec4 v1) {
    return ((vec4) { v0.x * v1.x, v0.y * v1.y, v0.z * v1.z, v0.w * v1.w } );
}


MATHAPI vec4 vec4Mulf(const vec4 v0, const float f) {
    return ((vec4) { v0.x * f, v0.y * f, v0.z * f, v0.w * f } );
}


MATHAPI vec4 vec4Div(const vec4 v0, const vec4 v1) {
    return ((vec4) { v0.x / v1.x, v0.y / v1.y, v0.z / v1.z, v0.w / v1.w } );
}


MATHAPI vec4 vec4Divf(const vec4 v0, const float f) {
    return ((vec4) { v0.x / f, v0.y / f, v0.z / f, v0.w / f } );
}


MATHAPI int vec4Equals(const vec4 v0, const vec4 v1) {
    return (v0.x == v1.x && v0.y == v1.y && v0.z == v1.z && v0.w == v1.w);
}


MATHAPI vec4 vec4Pow(const vec4 v0, float f) {
    return ((vec4) { pow(v0.x, f), pow(v0.y, f), pow(v0.z, f), pow(v0.w, f) } );
}


MATHAPI vec4 vec4Pow2(const vec4 v0) {
    return ((vec4) { v0.x * v0.x, v0.y * v0.y, v0.z * v0.z, v0.w * v0.w } );
}


MATHAPI vec4 vec4Sqrt(const vec4 v0) {
    return ((vec4) { sqrt(v0.x), sqrt(v0.y), sqrt(v0.z), sqrt(v0.w) } );
}


MATHAPI vec4 vec4Clamp(const vec4 v0, const vec4 min, const vec4 max) {
    return ((vec4) { clamp(v0.x, min.x, max.x), clamp(v0.y, min.y, max.y), clamp(v0.z, min.z, max.z), clamp(v0.w, min.w, max.w) } );
}


MATHAPI vec4 vec4Clampf(const vec4 v0, float min, float max) {
    return ((vec4) { clamp(v0.x, min, max), clamp(v0.y, min, max), clamp(v0.z, min, max), clamp(v0.w, min, max) } );
}


MATHAPI vec4 vec4Clamp01(const vec4 v0) {
    return ((vec4) { clamp01(v0.x), clamp01(v0.y), clamp01(v0.z), clamp01(v0.w) } );
}


MATHAPI float vec4Distance(const vec4 v0, const vec4 v1) {
    return (sqrt(pow(v0.x - v1.x, 2.0) + pow(v0.y - v1.y, 2.0) + pow(v0.z - v1.z, 2.0) + pow(v0.w - v1.w, 2.0)));
}


MATHAPI float vec4Length(const vec4 v0) {
    return (sqrt(pow(v0.x, 2.0) + pow(v0.y, 2.0) + pow(v0.z, 2.0) + pow(v0.w, 2.0)));
}


MATHAPI float vec4Dot(const vec4 v0, const vec4 v1) {
    return (v0.x * v1.x + v0.y * v1.y + v0.z * v1.z + v0.w * v1.w);
}


MATHAPI vec4 vec4Normalize(const vec4 v0) {
    vec4 value = vec4Zero();
    float len  = vec4Length(v0);
    if (len > 0.0) {
        value = vec4Mulf(v0, 1.0 / len);
    }
    return (value);
}


MATHAPI vec4 vec4Scale(const vec4 v0, const float f) {
    return (vec4Mulf(v0, f0));
}

#  if defined (__cplusplus)

}

#  endif /* __cplusplus */
#
#  if defined (__cplusplus)
#   if !defined (MATH_DISABLE_CPP_OPERATORS)

MATHAPI vec4 operator + (const vec4 &v0, const vec4 &v1)   { return (vec4Add(v0, v1)); }


MATHAPI const vec4& operator += (vec4 &v0, const vec4 &v1) { return ((v0 = vec4Add(v0, v1))); }


MATHAPI vec4 operator - (const vec4 &v0, const vec4 &v1)   { return (vec4Sub(v0, v1)); }


MATHAPI const vec4& operator -= (vec4 &v0, const vec4 &v1) { return ((v0 = vec4Sub(v0, v1))); }


MATHAPI vec4 operator * (const vec4 &v0, const vec4 &v1)   { return (vec4Mul(v0, v1)); }


MATHAPI const vec4& operator *= (vec4 &v0, const vec4 &v1) { return ((v0 = vec4Mul(v0, v1))); }


MATHAPI vec4 operator / (const vec4 &v0, const vec4 &v1)   { return (vec4Div(v0, v1)); }


MATHAPI const vec4& operator /= (vec4 &v0, const vec4 &v1) { return ((v0 = vec4Div(v0, v1))); }


MATHAPI bool operator == (const vec4 &v0, const vec4 &v1)  { return (vec4Equals(v0, v1)); }


MATHAPI bool operator != (const vec4 &v0, const vec4 &v1)  { return (!vec4Equals(v0, v1)); }

#   endif /* MATH_DISABLE_CPP_OPERATORS */
#  endif /* __cplusplus */
# endif /* MATHAPI_IMPLEMENTATION */
#endif /* _vec4_h_ */
