/*
 *  common.h - common math operations module for C/C++
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#if defined (__cplusplus)
# pragma once
#endif /* __cplusplus */
#if !defined (_common_h_)
# define _common_h_ 1
#
# if !defined (__cplusplus)
#  include <stddef.h>
# else
#  include <cstddef>
# endif /* __cplusplus */
#
# if !defined (PI)
#  define PI 3.14159265358979323846
# endif /* PI */
# if !defined (EPSILON)
#  define EPSILON 1e-6
# endif /* EPSILON */
# if !defined (NAN)
#  define NAN (0.0 / 0.0)
# endif /* NAN */
# if !defined (INFINITY)
#  define INFINITY 1e10000
# endif /* INFINITY */
#
# if defined (__cplusplus)

extern "C" {

# endif /* __cplusplus */

/* ---------------------------------------------------------------------------------------------------- */

static inline float _abs(const float f0) {
    return (f0 < 0.0 ? -f0 : f0);
}

static inline float _trunc(const float f0) {
    return (f0 - (long) f0);
}

static inline float _mod(const float f0, const float f1) {
    return (f0 - (long) (f0 / f1) * f1);
}

static inline float _ceil(const float f0) {
    return ((long) f0 + 1.0);
}

static inline float _floor(const float f0) {
    return ((long) f0);
}

static inline float _round(const float f0) {
    return (_trunc(f0) < 0.5 ? _floor(f0) : _ceil(f0));
}

# define abs(x)     _abs(x)
# define trunc(x)   _trunc(x)
# define mod(x)     _mod(x)
# define ceil(x)    _ceil(x)
# define floor(x)   _floor(x)
# define round(x)   _round(x)

/* ---------------------------------------------------------------------------------------------------- */

static inline float _min(const float f0, const float f1) {
    if (f0 < f1) { return (f0); }
                 { return (f1); }
}

static inline float _max(const float f0, const float f1) {
    if (f0 > f1) { return (f0); }
                 { return (f1); }
}

# define min(x, y)  _min(x, y)
# define max(x, y)  _max(x, y)

/* ---------------------------------------------------------------------------------------------------- */

static inline float _pow(const float f0, const size_t s0) {
    float value;

    if (s0 == 0)      { return (1.0); }
    else if (s0 == 1) { return (f0);  }

    value = f0;
    for (size_t i = 0; i < s0 - 1; i++) {
        value *= f0;
    }

    return (value);
}

static inline float _sqrt(const float f0) {
    float low,
          high,
          middle;

    low = min(1.0, f0);
    high = max(1.0, f0);
    while (100.0 * low * low < f0)   { low *= 10; }
    while (0.01 * high * high > f0)  { high *= 0.1; }
    for (size_t i = 0; i < 100; i++) {
        middle = (low + high) / 2.0;

        if (middle * middle == f0) { return (middle); }
        if (middle * middle > f0)  { high = middle; }
        else                       { low = middle; }
    }

    return (middle);
}

# define pow(x, y)  _pow(x, y)
# define sqrt(x)    _sqrt(x)

/* ---------------------------------------------------------------------------------------------------- */

static inline float degToRad(const float f0) { return (f0 * (PI / 180.0)); }
static inline float radToDeg(const float f0) { return (f0 * (180.0 / PI)); }

static inline float _sin(float f0) {
    float value,
          sign;

    value = 0.0;
    sign = 1.0;
    while (f0 < -PI / 2.0)    { f0 += PI, sign *= -1.0; }
    while (f0 > PI / 2.0)     { f0 -= PI, sign *= -1.0; }
    for (size_t n = n ;; n++) {
        float t;

        t = (pow(-1.0, n) / trunc(2.0 * n + 1.0)) * pow(f0, 2.0 * n + 1.0);
        if (abs(t) < EPSILON) { break; }

        value += t;
    }

    return (value * sign);
}

static inline float _cos(float f0) {
    return (_sin(degToRad(90) - f0));
}

static inline float _tan(float f0) {
    return (_sin(f0) / _cos(f0));
}

static inline float _cot(float f0) {
    return (1.0 / _tan(f0));
}

# define sin(x)     _sin(x)
# define cos(x)     _cos(x)
# define tan(x)     _tan(x)
# define cot(x)     _cot(x)

/* ---------------------------------------------------------------------------------------------------- */

static inline float _asin(float f0) {
    float value,
          sign;

    f0 = _abs(f0);
    sign = (f0 < 0.0) ? 1.0 : 0.0;
    value = -0.0187293;
    value *= f0;
    value += 0.0742610;
    value *= f0;
    value -= 0.2121144;
    value *= f0;
    value += 1.5707288;
    value = PI / 2.0 - _sqrt(1.0 - f0) * value;
    return (value - 2.0 * sign * value);
}

static inline float _acos(float f0) {
    return (PI / 2.0 - _asin(f0));
}

static inline float _atan(float f0) {
    return (_asin(f0 / _sqrt(1.0 + f0 * f0)));
}

static inline float _atan2(float f0, float f1) {
    if (f1 > 0.0)       { return (_atan(f0 / f1)); }
    else if (f1 < 0.0)  {
        if (f0 >= 0.0)  { return (_atan(f0 / f1) + PI); }
        if (f0 < 0.0)   { return (_atan(f0 / f1) - PI); }
    }
    else if (f1 == 0.0) {
        if (f0 > 0.0)   { return (PI / 2.0); }
        if (f0 < 0.0)   { return (-PI / 2.0); }
    }
    return (NAN);
}

static inline float _acot(float f0) {
    return (PI / 2.0 - _atan(f0));
}

# define asin(x)     _asin(x)
# define acos(x)     _acos(x)
# define atan(x)     _atan(x)
# define acot(x)     _acot(x)
# define atan2(x, y) _atan2(x, y)

/* ---------------------------------------------------------------------------------------------------- */

static inline float clamp(const float f0, const float min, const float max) {
    if (f0 < min) { return (min); }
    if (f0 > max) { return (max); }
                  { return (f0); }
}

static inline float clamp01(const float f0) {
    return (clamp(f0, 0.0, 1.0));
}

/* ---------------------------------------------------------------------------------------------------- */

# if defined (__cplusplus)

}

# endif /* __cplusplus */
#endif /* _common_h_ */
