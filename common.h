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
# if !defined (MATHAPI)
#  define MATHAPI static inline
# endif /* MATHAPI */
#
# if !defined (E)
#  define E 2.718281828459
# endif /* E */
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
#  define INFINITY 1e100
# endif /* INFINITY */
#
# if defined (__cplusplus)

extern "C" {

# endif /* __cplusplus */

MATHAPI float _abs(const float f0) { return (f0 < 0.0 ? -f0 : f0); }

MATHAPI float _trunc(const float f0) { return (f0 - (long) f0); }

MATHAPI float _mod(const float f0, const float f1) { return (f0 - (long) (f0 / f1) * f1); }

MATHAPI float _ceil(const float f0) { return ((long) f0 + 1.0); }

MATHAPI float _floor(const float f0) { return ((long) f0); }

MATHAPI float _round(const float f0) { return (_trunc(f0) < 0.5 ? _floor(f0) : _ceil(f0)); }

MATHAPI size_t _fact(size_t v0) {
    if ((long long) v0 < 0) { return (0); }
    else if (!v0) { return (1); }

    size_t value = 1.0;
    while (v0) { value *= v0, v0--; }

    return (value);
}

# if !defined (abs)
#  define abs(x)     _abs(x)
# endif /* abs */
# if !defined (trunc)
#  define trunc(x)   _trunc(x)
# endif /* trunc */
# if !defined (mod)
#  define mod(x)     _mod(x)
# endif /* mod */
# if !defined (ceil)
#  define ceil(x)    _ceil(x)
# endif /* ceil */
# if !defined (floor)
#  define floor(x)   _floor(x)
# endif /* floor */
# if !defined (round)
#  define round(x)   _round(x)
# endif /* round */
# if !defined (fact)
#  define fact(x)    _fact(x)
# endif /* fact */

/* ---------------------------------------------------------------------------------------------------- */

MATHAPI float _min(const float f0, const float f1) {
    if (f0 < f1) { return (f0); }
                 { return (f1); }
}

MATHAPI float _max(const float f0, const float f1) {
    if (f0 > f1) { return (f0); }
                 { return (f1); }
}

# if !defined (min)
#  define min(x, y)  _min(x, y)
# endif /* min */
# if !defined (max)
#  define max(x, y)  _max(x, y)
# endif /* max */

/* ---------------------------------------------------------------------------------------------------- */

MATHAPI float _exp(const float f0) {
    if (f0 == 1.0) { return (E); }

    float result = 1.0;
    float term   = 1.0;
    for (size_t n = 1; n < 256; n++) {
        term *= f0 / n, result += term;
    }

    return (result);
}

# if !defined (exp)
#  define exp(x)     _exp(x)
# endif /* exp */

/* ---------------------------------------------------------------------------------------------------- */

MATHAPI float _logn(const float f0) {
    float f1 = f0 - 1.0,
          f2 = f1;

    do {
        f1 = f2;
        f2 = f1 + 2.0 * (f0 - _exp(f1)) / (f0 + _exp(f1));
    } while (_abs(f1 - f2) > EPSILON);
    return (f2);
}

MATHAPI float _log(const float f0, const float f1) { return (_logn(f0) / _logn(f1)); }

# if !defined (logn)
#  define logn(x)    _logn(x)
# endif /* logn */
# if !defined (log)
#  define log(x, y)  _log(x, y)
# endif /* log */

/* ---------------------------------------------------------------------------------------------------- */

MATHAPI float _pow(const float f0, const float f1) {
    if (f1 < 0.0)  { return (1.0 / _pow(f0, _abs(f1))); }
    if (f1 - (int) f1 == 0.0) {
        float value = 1.0;

        for (size_t n = 0; n < f1; n++) {
            value *= f0;
        }
        return (value);
    }

    return (_exp(f1 * _logn(f0)));
}

MATHAPI float _pow2(const float f0) { return (f0 * f0); }

MATHAPI float _sqrt(const float f0) {
    float low = min(1.0, f0);
    float high = max(1.0, f0);
    while (100.0 * low * low < f0)   { low *= 10; }
    while (0.01 * high * high > f0)  { high *= 0.1; }

    float middle = 0.0;
    for (size_t i = 0; i < 100; i++) {
        middle = (low + high) / 2.0;

        if (middle * middle == f0) { return (middle); }
        if (middle * middle > f0)  { high = middle; }
        else                       { low = middle; }
    }

    return (middle);
}

# if !defined (pow)
#  define pow(x, y)  _pow(x, y)
# endif /* logn */
# if !defined (pow2)
#  define pow2(x)    _pow2(x)
# endif /* logn */
# if !defined (sqrt)
#  define sqrt(x)    _sqrt(x)
# endif /* logn */

/* ---------------------------------------------------------------------------------------------------- */

MATHAPI float _dot(const float f0, const float f1) { return (f0 * f1); }

# if !defined (dot)
#  define dot(x, y) _dot(x, y)
# endif /* dot */

/* ---------------------------------------------------------------------------------------------------- */

MATHAPI float _degToRad(const float f0) { return (f0 * (PI / 180.0)); }

MATHAPI float _radToDeg(const float f0) { return (f0 * (180.0 / PI)); }

# if !defined (degToRad)
#  define degToRad(x)    _degToRad(x)
# endif /* degToRad */
# if !defined (radToDeg)
#  define radToDeg(x)    _radToDeg(x)
# endif /* radToDeg */

/* ---------------------------------------------------------------------------------------------------- */

MATHAPI float _sin(float f0) {
    float sign = 1.0;
    while (f0 < -PI / 2.0)    { f0 += PI, sign *= -1.0; }
    while (f0 > PI / 2.0)     { f0 -= PI, sign *= -1.0; }
    
    float value = 0.0;
    for (size_t n = 0 ;; n++) {
        float t = (_pow(-1.0, n) / _fact(2.0 * n + 1.0)) * _pow(f0, 2.0 * n + 1.0);
        if (_abs(t) < EPSILON) { break; }

        value += t;
    }

    return (value * sign);
}

MATHAPI float _cos(float f0) { return (_sin(_degToRad(90.0) - f0)); }

MATHAPI float _tan(float f0) { return (_sin(f0) / _cos(f0)); }

MATHAPI float _cot(float f0) { return (1.0 / _tan(f0)); }

# if !defined (sin)
#  define sin(x)     _sin(x)
# endif /* sin */
# if !defined (cos)
#  define cos(x)     _cos(x)
# endif /* cos */
# if !defined (tan)
#  define tan(x)     _tan(x)
# endif /* tan */
# if !defined (cot)
#  define cot(x)     _cot(x)
# endif /* cot */

/* ---------------------------------------------------------------------------------------------------- */

MATHAPI float _asin(float f0) {
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

MATHAPI float _acos(float f0) { return (PI / 2.0 - _asin(f0)); }

MATHAPI float _atan(float f0) { return (_asin(f0 / _sqrt(1.0 + f0 * f0))); }

MATHAPI float _atan2(float f0, float f1) {
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

MATHAPI float _acot(float f0) { return (PI / 2.0 - _atan(f0)); }

# if !defined (asin)
#  define asin(x)     _asin(x)
# endif /* asin */
# if !defined (acos)
#  define acos(x)     _acos(x)
# endif /* acos */
# if !defined (atan)
#  define atan(x)     _atan(x)
# endif /* atan */
# if !defined (atan2)
#  define atan2(x, y) _atan2(x, y)
# endif /* atan2 */
# if !defined (acot)
#  define acot(x)     _acot(x)
# endif /* acot */

/* ---------------------------------------------------------------------------------------------------- */

MATHAPI float _clamp(const float f0, const float min, const float max) {
    if (f0 < min) { return (min); }
    if (f0 > max) { return (max); }
                  { return (f0); }
}

MATHAPI float _clamp01(const float f0) { return (_clamp(f0, 0.0, 1.0)); }

# if !defined (clamp)
#  define clamp(x, y, z) _clamp(x, y, z)
# endif /* clamp */
# if !defined (clamp01)
#  define clamp01(x)     _clamp01(x)
# endif /* clamp01 */

/* ---------------------------------------------------------------------------------------------------- */

# if !defined (isspace)
#  define isspace(c) ((c >= '\t' && c <= '\r') || c == ' ')
# endif /* isspace */
# if !defined (isdigit)
#  define isdigit(c) (c >= '0' && c <= '9')
# endif /* isdigit */

MATHAPI signed int _atoi(const char *str) {
    while (isspace(*str)) { str++; }

    int sign = 1;
    if (*str == '+' || *str == '-') {
        if (*str == '-') {
            sign *= -1;
        }
        str++;
    }

    int value = 0;
    while (isdigit(*str)) {
        value *= 10;
        value += (int) (*str - '0');
        str++;
    }

    return (value * sign);
}

MATHAPI signed int _atou(const char *str) { return ((unsigned int) _atoi(str)); }

MATHAPI double _atod(const char *str) {
    while (isspace(*str)) { str++; }

    int sign = 1;
    if (*str == '+' || *str == '-') {
        if (*str == '-') {
            sign *= -1;
        }
        str++;
    }

    float value = 0.0;
    while (isdigit(*str)) {
        value *= 10;
        value += (int) (*str - '0');
        str++;
    }

    if (*str++ != '.') { return (value * sign); }
    
    float fraction = 0.0;
    for (size_t n = 1; isdigit(*str); n++, str++) {
        fraction += (float) (*str - '0') / _pow(10, n);
    }

    return ((value + fraction) * sign);
}

MATHAPI float _atof(const char *str) { return ((float) _atod(str)); }

# undef isspace
# undef isdigit

# if !defined (atoi)
#  define atoi(s)   _atoi(s)
# endif /* atoi */
# if !defined (atou)
#  define atou(s)   _atou(s)
# endif /* atou */
# if !defined (atod)
#  define atod(s)   _atod(s)
# endif /* atod */
# if !defined (atof)
#  define atof(s)   _atof(s)
# endif /* atof */
# undef isspace
# undef isdigit

# if defined (__cplusplus)

}

# endif /* __cplusplus */
#endif /* _common_h_ */
