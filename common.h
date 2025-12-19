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

MATHAPI float __common_abs(const float);


MATHAPI float __common_trunc(const float);


MATHAPI float __common_mod(const float, const float);


MATHAPI float __common_ceil(const float);


MATHAPI float __common_floor(const float);


MATHAPI float __common_round(const float);


MATHAPI long long int __common_fact(long long int);


MATHAPI float __common_min(const float, const float);


MATHAPI float __common_max(const float, const float);


MATHAPI float __common_exp(const float);


MATHAPI float __common_ln(const float);


MATHAPI float __common_log(const float, const float);


MATHAPI float __common_pow(const float, const float);


MATHAPI float __common_pow2(const float);


MATHAPI float __common_sqrt(const float);


MATHAPI float __common_dot(const float, const float);


MATHAPI float __common_degToRad(const float);


MATHAPI float __common_radToDeg(const float);


MATHAPI float __common_sin(float);


MATHAPI float __common_cos(float);


MATHAPI float __common_tan(float);


MATHAPI float __common_cot(float);


MATHAPI float __common_asin(float);


MATHAPI float __common_acos(float);


MATHAPI float __common_atan(float);


MATHAPI float __common_atan2(float, float);


MATHAPI float __common_acot(float);


MATHAPI float __common_clamp(const float, const float, const float);


MATHAPI float __common_clamp01(const float);


MATHAPI signed int __common_atou(const char *);


MATHAPI signed int __common_atoi(const char *);


MATHAPI float __common_atof(const char *);


MATHAPI double __common_atod(const char *);


MATHAPI int __common_isle(void);


MATHAPI int __common_isbe(void);


MATHAPI short __common_pack16(const char [2]);


MATHAPI short  __common_pack16le(const char [2]);


MATHAPI short __common_pack16be(const char [2]);


MATHAPI int __common_pack32(const char [4]);


MATHAPI int __common_pack32le(const char [4]);


MATHAPI int __common_pack32be(const char [4]);


MATHAPI long long int __common_pack64(const char [8]);


MATHAPI long long int __common_pack64le(const char [8]);


MATHAPI long long int __common_pack64be(const char [8]);

# if !defined (abs)
#  define abs(x)         __common_abs(x)
# endif /* abs */
# if !defined (trunc)
#  define trunc(x)       __common_trunc(x)
# endif /* trunc */
# if !defined (mod)
#  define mod(x)         __common_mod(x)
# endif /* mod */
# if !defined (ceil)
#  define ceil(x)        __common_ceil(x)
# endif /* ceil */
# if !defined (floor)
#  define floor(x)       __common_floor(x)
# endif /* floor */
# if !defined (round)
#  define round(x)       __common_round(x)
# endif /* round */
# if !defined (fact)
#  define fact(x)        __common_fact(x)
# endif /* fact */
# if !defined (min)
#  define min(x, y)      __common_min(x, y)
# endif /* min */
# if !defined (max)
#  define max(x, y)      __common_max(x, y)
# endif /* max */
# if !defined (exp)
#  define exp(x)         __common_exp(x)
# endif /* exp */
# if !defined (logn)
#  define logn(x)        __common_logn(x)
# endif /* logn */
# if !defined (log)
#  define log(x, y)      __common_log(x, y)
# endif /* log */
# if !defined (pow)
#  define pow(x, y)      __common_pow(x, y)
# endif /* logn */
# if !defined (pow2)
#  define pow2(x)        __common_pow2(x)
# endif /* logn */
# if !defined (sqrt)
#  define sqrt(x)        __common_sqrt(x)
# endif /* logn */
# if !defined (dot)
#  define dot(x, y)      __common_dot(x, y)
# endif /* dot */
# if !defined (degToRad)
#  define degToRad(x)    __common_degToRad(x)
# endif /* degToRad */
# if !defined (radToDeg)
#  define radToDeg(x)    __common_radToDeg(x)
# endif /* radToDeg */
# if !defined (sin)
#  define sin(x)         __common_sin(x)
# endif /* sin */
# if !defined (cos)
#  define cos(x)         __common_cos(x)
# endif /* cos */
# if !defined (tan)
#  define tan(x)         __common_tan(x)
# endif /* tan */
# if !defined (cot)
#  define cot(x)         __common_cot(x)
# endif /* cot */
# if !defined (asin)
#  define asin(x)        __common_asin(x)
# endif /* asin */
# if !defined (acos)
#  define acos(x)        __common_acos(x)
# endif /* acos */
# if !defined (atan)
#  define atan(x)        __common_atan(x)
# endif /* atan */
# if !defined (atan2)
#  define atan2(x, y)    __common_atan2(x, y)
# endif /* atan2 */
# if !defined (acot)
#  define acot(x)        __common_acot(x)
# endif /* acot */
# if !defined (clamp)
#  define clamp(x, y, z) __common_clamp(x, y, z)
# endif /* clamp */
# if !defined (clamp01)  
#  define clamp01(x)     __common_clamp01(x)
# endif /* clamp01 */
# if !defined (atoi)
#  define atoi(s)        __common_atoi(s)
# endif /* atoi */
# if !defined (atou)
#  define atou(s)        __common_atou(s)
# endif /* atou */
# if !defined (atod)
#  define atod(s)        __common_atod(s)
# endif /* atod */
# if !defined (atof)
#  define atof(s)        __common_atof(s)
# endif /* atof */
# if !defined (isle)
#  define isle           __common_isle
# endif /* isle */
# if !defined (isbe)
#  define isbe           __common_isbe
# endif /* isbe */
# if !defined (pack16)
#  define pack16(s)      __common_pack16(s)
# endif /* pack16 */
# if !defined (pack16le)
#  define pack16le(s)    __common_pack16le(s)
# endif /* pack16le */
# if !defined (pack16be)
#  define pack16be(s)    __common_pack16be(s)
# endif /* pack16be */
# if !defined (pack32)
#  define pack32(i)      __common_pack32(i)
# endif /* pack32 */
# if !defined (pack32le)
#  define pack32le(i)    __common_pack32le(i)
# endif /* pack32le */
# if !defined (pack32be)
#  define pack32be(i)    __common_pack32be(i)
# endif /* pack32le */
# if !defined (pack64)
#  define pack64(ll)     __common_pack16(ll)
# endif /* pack64 */
# if !defined (pack64le)
#  define pack64le(ll)   __common_pack64le(ll)
# endif /* pack64be */
# if !defined (pack64be)
#  define pack64be(ll)   __common_pack64be(ll)
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


MATHAPI float __common_abs(const float f0) {
    return (f0 < 0.0 ? -f0 : f0);
}


MATHAPI float __common_trunc(const float f0) {
    return (f0 - (long) f0);
}


MATHAPI float __common_mod(const float f0, const float f1) {
    return (f0 - (long) (f0 / f1) * f1);
}


MATHAPI float __common_ceil(const float f0) {
    return ((long) f0 + 1.0);
}


MATHAPI float __common_floor(const float f0) {
    return ((long) f0);
}


MATHAPI float __common_round(const float f0) {
    return (__common_trunc(f0) < 0.5 ? __common_floor(f0) : __common_ceil(f0));
}


MATHAPI long long int __common_fact(long long int v0) {
    if ((long long int) v0 < 0) { return (0); }
    else if (!v0) { return (1); }

    long long int value = 1.0;
    while (v0) { value *= v0, v0--; }

    return (value);
}


MATHAPI float __common_min(const float f0, const float f1) {
    if (f0 < f1) { return (f0); }
                 { return (f1); }
}


MATHAPI float __common_max(const float f0, const float f1) {
    if (f0 > f1) { return (f0); }
                 { return (f1); }
}


MATHAPI float __common_exp(const float f0) {
    if (f0 == 1.0) { return (E); }

    float result = 1.0;
    float term   = 1.0;
    for (size_t n = 1; n < 256; n++) {
        term *= f0 / n, result += term;
    }

    return (result);
}


MATHAPI float __common_ln(const float f0) {
    float f1 = f0 - 1.0,
          f2 = f1;

    do {
        f1 = f2;
        f2 = f1 + 2.0 * (f0 - __common_exp(f1)) / (f0 + __common_exp(f1));
    } while (__common_abs(f1 - f2) > EPSILON);
    return (f2);
}


MATHAPI float __common_log(const float f0, const float f1) {
    return (__common_ln(f0) / __common_ln(f1));
}


MATHAPI float __common_pow(const float f0, const float f1) {
    if (f1 < 0.0)  { return (1.0 / __common_pow(f0, __common_abs(f1))); }
    if (f1 - (int) f1 == 0.0) {
        float value = 1.0;

        for (size_t n = 0; n < f1; n++) {
            value *= f0;
        }
        return (value);
    }

    return (__common_exp(f1 * __common_ln(f0)));
}


MATHAPI float __common_pow2(const float f0) {
    return (f0 * f0);
}


MATHAPI float __common_sqrt(const float f0) {
    float low = __common_min(1.0, f0);
    float high = __common_max(1.0, f0);
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


MATHAPI float __common_dot(const float f0, const float f1) {
    return (f0 * f1);
}


MATHAPI float __common_degToRad(const float f0) {
    return (f0 * (PI / 180.0));
}


MATHAPI float __common_radToDeg(const float f0) {
    return (f0 * (180.0 / PI));
}


MATHAPI float __common_sin(float f0) {
    float sign = 1.0;
    while (f0 < -PI / 2.0)    { f0 += PI, sign *= -1.0; }
    while (f0 > PI / 2.0)     { f0 -= PI, sign *= -1.0; }
    
    float value = 0.0;
    for (size_t n = 0 ;; n++) {
        float t = (__common_pow(-1.0, n) / __common_fact(2.0 * n + 1.0)) * __common_pow(f0, 2.0 * n + 1.0);
        if (__common_abs(t) < EPSILON) { break; }

        value += t;
    }

    return (value * sign);
}


MATHAPI float __common_cos(float f0) {
    return (__common_sin(__common_degToRad(90.0) - f0));
}


MATHAPI float __common_tan(float f0) {
    return (__common_sin(f0) / __common_cos(f0));
}


MATHAPI float __common_cot(float f0) {
    return (1.0 / __common_tan(f0));
}


MATHAPI float __common_asin(float f0) {
    float value,
          sign;

    f0 = __common_abs(f0);
    sign = (f0 < 0.0) ? 1.0 : 0.0;
    value = -0.0187293;
    value *= f0;
    value += 0.0742610;
    value *= f0;
    value -= 0.2121144;
    value *= f0;
    value += 1.5707288;
    value = PI / 2.0 - __common_sqrt(1.0 - f0) * value;
    return (value - 2.0 * sign * value);
}


MATHAPI float __common_acos(float f0) {
    return (PI / 2.0 - __common_asin(f0));
}


MATHAPI float __common_atan(float f0) {
    return (__common_asin(f0 / __common_sqrt(1.0 + f0 * f0)));
}


MATHAPI float __common_atan2(float f0, float f1) {
    if (f1 > 0.0)       { return (__common_atan(f0 / f1)); }
    else if (f1 < 0.0)  {
        if (f0 >= 0.0)  { return (__common_atan(f0 / f1) + PI); }
        if (f0 < 0.0)   { return (__common_atan(f0 / f1) - PI); }
    }
    else if (f1 == 0.0) {
        if (f0 > 0.0)   { return (PI / 2.0); }
        if (f0 < 0.0)   { return (-PI / 2.0); }
    }
    return (NAN);
}


MATHAPI float __common_acot(float f0) {
    return (PI / 2.0 - __common_atan(f0));
}


MATHAPI float __common_clamp(const float f0, const float min, const float max) {
    if (f0 < min) { return (min); }
    if (f0 > max) { return (max); }
                  { return (f0); }
}


MATHAPI float __common_clamp01(const float f0) { return (__common_clamp(f0, 0.0, 1.0)); }


#  if !defined (isspace)
#   define isspace(c) ((c >= '\t' && c <= '\r') || c == ' ')
#  endif /* isspace */
#  if !defined (isdigit)
#   define isdigit(c) (c >= '0' && c <= '9')
#  endif /* isdigit */


MATHAPI signed int __common_atou(const char *str) {
    return ((unsigned int) __common_atoi(str));
}


MATHAPI signed int __common_atoi(const char *str) {
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


MATHAPI float __common_atof(const char *str) {
    return ((float) __common_atod(str));
}


MATHAPI double __common_atod(const char *str) {
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
        fraction += (float) (*str - '0') / __common_pow(10, n);
    }

    return ((value + fraction) * sign);
}


MATHAPI int __common_isle(void) {
    union { uint32_t i; uint8_t c[4]; } e = { 0x01000000 };

    return (e.c[0] == 0);
}


MATHAPI int __common_isbe(void) {
    union { uint32_t i; uint8_t c[4]; } e = { 0x01000000 };

    return (e.c[0] == 1);
}


MATHAPI short __common_pack16(const char s[2]) {
    if (__common_isle()) { return (__common_pack16le(s)); }
            else { return (__common_pack16le(s)); }
}


MATHAPI short  __common_pack16le(const char s[2]) {
    short value  = 0;
          value |= s[1] << 0;
          value |= s[0] << 8;

    return (value);
}


MATHAPI short __common_pack16be(const char s[2]) {
    short value  = 0;
          value |= s[0] << 0;
          value |= s[1] << 8;

    return (value);
}


MATHAPI int __common_pack32(const char i[4]) {
    if (__common_isle()) { return (__common_pack32le(i)); }
            else { return (__common_pack32be(i)); }
}


MATHAPI int __common_pack32le(const char i[4]) {
    int value  = 0;
        value |= i[3] << 0;
        value |= i[2] << 8;
        value |= i[1] << 16;
        value |= i[0] << 24;

    return (value);
}


MATHAPI int __common_pack32be(const char i[4]) {
    int value  = 0;
        value |= i[0] << 0;
        value |= i[1] << 8;
        value |= i[2] << 16;
        value |= i[3] << 24;

    return (value);
}


MATHAPI long long int __common_pack64(const char ll[8]) {
    if (__common_isle()) { return (__common_pack64le(ll)); }
            else { return (__common_pack64be(ll)); }
}


MATHAPI long long int __common_pack64le(const char ll[8]) {
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


MATHAPI long long int __common_pack64be(const char ll[8]) {
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
