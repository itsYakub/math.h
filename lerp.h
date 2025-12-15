/*
 *  lerp.h - linear interpolation module for C/C++
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#if defined (__cplusplus)
# pragma once
#endif /* __cplusplus */
#if !defined (_lerp_h_)
# define _lerp_h_ 1
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
# if defined (__cplusplus)

extern "C" {

# endif /* __cplusplus */

MATHAPI float _lerp(const float, const float, const float);

/* NOTE: this function is using approximation and some results may be incorrect.
 * */
MATHAPI float _slerp(const float, const float, const float);

# if !defined (lerp)
#  define lerp(a, b, t)  _lerp(a, b, t)
# endif /* lerp */
# if !defined (slerp)
#  define slerp(a, b, t) _slerp(a, b, t)
# endif /* slerp */
#
# if defined (__cplusplus)

}

# endif /* __cplusplus */
#
# if defined (MATHAPI_IMPLEMENTATION)
#
#  include "./common.h"
#
#  if defined (__cplusplus)

extern "C" {

#  endif /* __cplusplus */

MATHAPI float _lerp(const float f0, const float f1, const float t0) {
    return (f1 - f0) * t0 + f0;
}

/* NOTE: this function is using approximation and some results may be incorrect.
 * */
MATHAPI float _slerp(const float f0, const float f1, const float t0) {
    const float f2 = acos(clamp01(f0 * f1));

    if (f2 < EPSILON) {
        return (_lerp(f0, f1, t0));
    }
    return ((sin((1.0 - t0) * f2) + (sin(t0 * f2) * f1)) / sin(f2));
} 

#  if defined (__cplusplus)

}

#  endif /* __cplusplus */
# endif /* MATHAPI_IMPLEMENTATION */
#endif /* _lerp_h_ */
