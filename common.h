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

MATHAPI float __abs(const float);


MATHAPI float __trunc(const float);


MATHAPI float __mod(const float, const float);


MATHAPI float __ceil(const float);


MATHAPI float __floor(const float);


MATHAPI float __round(const float);


MATHAPI long long int __fact(long long int);


MATHAPI float __min(const float, const float);


MATHAPI float __max(const float, const float);


MATHAPI float __exp(const float);


MATHAPI float __ln(const float);


MATHAPI float __log(const float, const float);


MATHAPI float __pow(const float, const float);


MATHAPI float __pow2(const float);


MATHAPI float __sqrt(const float);


MATHAPI float __dot(const float, const float);


MATHAPI float __degToRad(const float);


MATHAPI float __radToDeg(const float);


MATHAPI float __sin(float);


MATHAPI float __cos(float);


MATHAPI float __tan(float);


MATHAPI float __cot(float);


MATHAPI float __asin(float);


MATHAPI float __acos(float);


MATHAPI float __atan(float);


MATHAPI float __atan2(float, float);


MATHAPI float __acot(float);


MATHAPI float __clamp(const float, const float, const float);


MATHAPI float __clamp01(const float);


MATHAPI signed int __atou(const char *);


MATHAPI signed int __atoi(const char *);


MATHAPI float __atof(const char *);


MATHAPI double __atod(const char *);


MATHAPI int __isle(void);


MATHAPI int __isbe(void);


MATHAPI short __pack16(const char [2]);


MATHAPI short  __pack16le(const char [2]);


MATHAPI short __pack16be(const char [2]);


MATHAPI int __pack32(const char [4]);


MATHAPI int __pack32le(const char [4]);


MATHAPI int __pack32be(const char [4]);


MATHAPI long long int __pack64(const char [8]);


MATHAPI long long int __pack64le(const char [8]);


MATHAPI long long int __pack64be(const char [8]);

# if !defined (abs)
#  define abs(x)         __abs(x)
# endif /* abs */
# if !defined (trunc)
#  define trunc(x)       __trunc(x)
# endif /* trunc */
# if !defined (mod)
#  define mod(x)         __mod(x)
# endif /* mod */
# if !defined (ceil)
#  define ceil(x)        __ceil(x)
# endif /* ceil */
# if !defined (floor)
#  define floor(x)       __floor(x)
# endif /* floor */
# if !defined (round)
#  define round(x)       __round(x)
# endif /* round */
# if !defined (fact)
#  define fact(x)        __fact(x)
# endif /* fact */
# if !defined (min)
#  define min(x, y)      __min(x, y)
# endif /* min */
# if !defined (max)
#  define max(x, y)      __max(x, y)
# endif /* max */
# if !defined (exp)
#  define exp(x)         __exp(x)
# endif /* exp */
# if !defined (logn)
#  define logn(x)        __logn(x)
# endif /* logn */
# if !defined (log)
#  define log(x, y)      __log(x, y)
# endif /* log */
# if !defined (pow)
#  define pow(x, y)      __pow(x, y)
# endif /* logn */
# if !defined (pow2)
#  define pow2(x)        __pow2(x)
# endif /* logn */
# if !defined (sqrt)
#  define sqrt(x)        __sqrt(x)
# endif /* logn */
# if !defined (dot)
#  define dot(x, y)      __dot(x, y)
# endif /* dot */
# if !defined (degToRad)
#  define degToRad(x)    __degToRad(x)
# endif /* degToRad */
# if !defined (radToDeg)
#  define radToDeg(x)    __radToDeg(x)
# endif /* radToDeg */
# if !defined (sin)
#  define sin(x)         __sin(x)
# endif /* sin */
# if !defined (cos)
#  define cos(x)         __cos(x)
# endif /* cos */
# if !defined (tan)
#  define tan(x)         __tan(x)
# endif /* tan */
# if !defined (cot)
#  define cot(x)         __cot(x)
# endif /* cot */
# if !defined (asin)
#  define asin(x)        __asin(x)
# endif /* asin */
# if !defined (acos)
#  define acos(x)        __acos(x)
# endif /* acos */
# if !defined (atan)
#  define atan(x)        __atan(x)
# endif /* atan */
# if !defined (atan2)
#  define atan2(x, y)    __atan2(x, y)
# endif /* atan2 */
# if !defined (acot)
#  define acot(x)        __acot(x)
# endif /* acot */
# if !defined (clamp)
#  define clamp(x, y, z) __clamp(x, y, z)
# endif /* clamp */
# if !defined (clamp01)  
#  define clamp01(x)     __clamp01(x)
# endif /* clamp01 */
# if !defined (atoi)
#  define atoi(s)        __atoi(s)
# endif /* atoi */
# if !defined (atou)
#  define atou(s)        __atou(s)
# endif /* atou */
# if !defined (atod)
#  define atod(s)        __atod(s)
# endif /* atod */
# if !defined (atof)
#  define atof(s)        __atof(s)
# endif /* atof */
# if !defined (isle)
#  define isle           __isle
# endif /* isle */
# if !defined (isbe)
#  define isbe           __isbe
# endif /* isbe */
# if !defined (pack16)
#  define pack16(s)      __pack16(s)
# endif /* pack16 */
# if !defined (pack16le)
#  define pack16le(s)    __pack16le(s)
# endif /* pack16le */
# if !defined (pack16be)
#  define pack16be(s)    __pack16be(s)
# endif /* pack16be */
# if !defined (pack32)
#  define pack32(i)      __pack32(i)
# endif /* pack32 */
# if !defined (pack32le)
#  define pack32le(i)    __pack32le(i)
# endif /* pack32le */
# if !defined (pack32be)
#  define pack32be(i)    __pack32be(i)
# endif /* pack32le */
# if !defined (pack64)
#  define pack64(ll)     __pack16(ll)
# endif /* pack64 */
# if !defined (pack64le)
#  define pack64le(ll)   __pack64le(ll)
# endif /* pack64be */
# if !defined (pack64be)
#  define pack64be(ll)   __pack64be(ll)
# endif /* pack64be */
#
# if defined (__cplusplus)

}

# endif /* __cplusplus */
#
# if defined (MATHAPI_IMPLEMENTATION)
#
# if !defined (__cplusplus)
#  include <stddef.h>
#  include <stdint.h>
# else
#  include <cstddef>
#  include <cstdint>
# endif /* __cplusplus */
#
# if defined (__cplusplus)

extern "C" {

# endif /* __cplusplus */


MATHAPI float __abs(const float f0) {
    return (f0 < 0.0 ? -f0 : f0);
}


MATHAPI float __trunc(const float f0) {
    return (f0 - (long) f0);
}


MATHAPI float __mod(const float f0, const float f1) {
    return (f0 - (long) (f0 / f1) * f1);
}


MATHAPI float __ceil(const float f0) {
    return ((long) f0 + 1.0);
}


MATHAPI float __floor(const float f0) {
    return ((long) f0);
}


MATHAPI float __round(const float f0) {
    return (_trunc(f0) < 0.5 ? __floor(f0) : __ceil(f0));
}


MATHAPI long long int __fact(long long int v0) {
    if ((long long int) v0 < 0) { return (0); }
    else if (!v0) { return (1); }

    long long int value = 1.0;
    while (v0) { value *= v0, v0--; }

    return (value);
}


MATHAPI float __min(const float f0, const float f1) {
    if (f0 < f1) { return (f0); }
                 { return (f1); }
}


MATHAPI float __max(const float f0, const float f1) {
    if (f0 > f1) { return (f0); }
                 { return (f1); }
}


MATHAPI float __exp(const float f0) {
    if (f0 == 1.0) { return (E); }

    float result = 1.0;
    float term   = 1.0;
    for (size_t n = 1; n < 256; n++) {
        term *= f0 / n, result += term;
    }

    return (result);
}


MATHAPI float __ln(const float f0) {
    float f1 = f0 - 1.0,
          f2 = f1;

    do {
        f1 = f2;
        f2 = f1 + 2.0 * (f0 - __exp(f1)) / (f0 + __exp(f1));
    } while (_abs(f1 - f2) > EPSILON);
    return (f2);
}


MATHAPI float __log(const float f0, const float f1) {
    return (_ln(f0) / __ln(f1));
}


MATHAPI float __pow(const float f0, const float f1) {
    if (f1 < 0.0)  { return (1.0 / __pow(f0, __abs(f1))); }
    if (f1 - (int) f1 == 0.0) {
        float value = 1.0;

        for (size_t n = 0; n < f1; n++) {
            value *= f0;
        }
        return (value);
    }

    return (_exp(f1 * __ln(f0)));
}


MATHAPI float __pow2(const float f0) {
    return (f0 * f0);
}


MATHAPI float __sqrt(const float f0) {
    float low = __min(1.0, f0);
    float high = __max(1.0, f0);
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


MATHAPI float __dot(const float f0, const float f1) {
    return (f0 * f1);
}


MATHAPI float __degToRad(const float f0) {
    return (f0 * (PI / 180.0));
}


MATHAPI float __radToDeg(const float f0) {
    return (f0 * (180.0 / PI));
}


MATHAPI float __sin(float f0) {
    float sign = 1.0;
    while (f0 < -PI / 2.0)    { f0 += PI, sign *= -1.0; }
    while (f0 > PI / 2.0)     { f0 -= PI, sign *= -1.0; }
    
    float value = 0.0;
    for (size_t n = 0 ;; n++) {
        float t = (_pow(-1.0, n) / __fact(2.0 * n + 1.0)) * __pow(f0, 2.0 * n + 1.0);
        if (_abs(t) < EPSILON) { break; }

        value += t;
    }

    return (value * sign);
}


MATHAPI float __cos(float f0) {
    return (_sin(_degToRad(90.0) - f0));
}


MATHAPI float __tan(float f0) {
    return (_sin(f0) / __cos(f0));
}


MATHAPI float __cot(float f0) {
    return (1.0 / __tan(f0));
}


MATHAPI float __asin(float f0) {
    float value,
          sign;

    f0 = __abs(f0);
    sign = (f0 < 0.0) ? 1.0 : 0.0;
    value = -0.0187293;
    value *= f0;
    value += 0.0742610;
    value *= f0;
    value -= 0.2121144;
    value *= f0;
    value += 1.5707288;
    value = PI / 2.0 - __sqrt(1.0 - f0) * value;
    return (value - 2.0 * sign * value);
}


MATHAPI float __acos(float f0) {
    return (PI / 2.0 - __asin(f0));
}


MATHAPI float __atan(float f0) {
    return (_asin(f0 / __sqrt(1.0 + f0 * f0)));
}


MATHAPI float __atan2(float f0, float f1) {
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


MATHAPI float __acot(float f0) {
    return (PI / 2.0 - __atan(f0));
}


MATHAPI float __clamp(const float f0, const float min, const float max) {
    if (f0 < min) { return (min); }
    if (f0 > max) { return (max); }
                  { return (f0); }
}


MATHAPI float __clamp01(const float f0) { return (_clamp(f0, 0.0, 1.0)); }


#  if !defined (isspace)
#   define isspace(c) ((c >= '\t' && c <= '\r') || c == ' ')
#  endif /* isspace */
#  if !defined (isdigit)
#   define isdigit(c) (c >= '0' && c <= '9')
#  endif /* isdigit */


MATHAPI signed int __atou(const char *str) {
    return ((unsigned int) __atoi(str));
}


MATHAPI signed int __atoi(const char *str) {
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


MATHAPI float __atof(const char *str) {
    return ((float) __atod(str));
}


MATHAPI double __atod(const char *str) {
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
        fraction += (float) (*str - '0') / __pow(10, n);
    }

    return ((value + fraction) * sign);
}


MATHAPI int __isle(void) {
    union { uint32_t i; uint8_t c[4]; } e = { 0x01000000 };

    return (e.c[0] == 0);
}


MATHAPI int __isbe(void) {
    union { uint32_t i; uint8_t c[4]; } e = { 0x01000000 };

    return (e.c[0] == 1);
}


MATHAPI short __pack16(const char s[2]) {
    if (_isle()) { return (_pack16le(s)); }
            else { return (_pack16le(s)); }
}


MATHAPI short  __pack16le(const char s[2]) {
    short value  = 0;
          value |= s[1] << 0;
          value |= s[0] << 8;

    return (value);
}


MATHAPI short __pack16be(const char s[2]) {
    short value  = 0;
          value |= s[0] << 0;
          value |= s[1] << 8;

    return (value);
}


MATHAPI int __pack32(const char i[4]) {
    if (_isle()) { return (_pack32le(i)); }
            else { return (_pack32be(i)); }
}


MATHAPI int __pack32le(const char i[4]) {
    int value  = 0;
        value |= i[3] << 0;
        value |= i[2] << 8;
        value |= i[1] << 16;
        value |= i[0] << 24;

    return (value);
}


MATHAPI int __pack32be(const char i[4]) {
    int value  = 0;
        value |= i[0] << 0;
        value |= i[1] << 8;
        value |= i[2] << 16;
        value |= i[3] << 24;

    return (value);
}


MATHAPI long long int __pack64(const char ll[8]) {
    if (_isle()) { return (_pack64le(ll)); }
            else { return (_pack64be(ll)); }
}


MATHAPI long long int __pack64le(const char ll[8]) {
    long long int value  = 0L;
                  value |= (uint64_t) (uint8_t) ll[7] << 0;
                  value |= (uint64_t) (uint8_t) ll[6] << 8;
                  value |= (uint64_t) (uint8_t) ll[5] << 16;
                  value |= (uint64_t) (uint8_t) ll[4] << 24;
                  value |= (uint64_t) (uint8_t) ll[3] << 32;
                  value |= (uint64_t) (uint8_t) ll[2] << 40;
                  value |= (uint64_t) (uint8_t) ll[1] << 48;
                  value |= (uint64_t) (uint8_t) ll[0] << 56;

    return (value);
}


MATHAPI long long int __pack64be(const char ll[8]) {
    long long int value  = 0L;
                  value |= (uint64_t) (uint8_t) ll[0] << 0;
                  value |= (uint64_t) (uint8_t) ll[1] << 8;
                  value |= (uint64_t) (uint8_t) ll[2] << 16;
                  value |= (uint64_t) (uint8_t) ll[3] << 24;
                  value |= (uint64_t) (uint8_t) ll[4] << 32;
                  value |= (uint64_t) (uint8_t) ll[5] << 40;
                  value |= (uint64_t) (uint8_t) ll[6] << 48;
                  value |= (uint64_t) (uint8_t) ll[7] << 56;

    return (value);
}

#  undef isspace
#  undef isdigit
#
#  if defined (__cplusplus)

}

#  endif /* __cplusplus */
# endif /* MATHAPI_IMPLEMENTATION */
#endif /* _common_h_ */
