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
# if !defined (__cplusplus)
#  include <stddef.h>
# else
#  include <cstddef>
# endif /* __cplusplus */
# include "./common.h"
#
# if !defined (MATHAPI)
#  define MATHAPI static inline
# endif /* MATHAPI */
#
# if defined (__cplusplus)

extern "C" {

# endif /* __cplusplus */

/* ---------------------------------------------------------------------------------------------------- */

MATHAPI float _lerp(const float f0, const float f1, const float t0) { return (f1 - f0) * t0 + f0; }

/* NOTE: this function is using approximation and some results may be incorrect.
 * */
MATHAPI float _slerp(const float f0, const float f1, const float t0) {
    const float f2 = acos(clamp01(f0 * f1));

    if (f2 < EPSILON) {
        return (_lerp(f0, f1, t0));
    }
    return ((sin((1.0 - t0) * f2) + (sin(t0 * f2) * f1)) / sin(f2));
} 

# if !defined (lerp)
#  define lerp(a, b, t)     _lerp(a, b, t)
# endif /* lerp */
# if !defined (slerp)
#  define slerp(a, b, t)    _slerp(a, b, t)
# endif /* slerp */

/* ---------------------------------------------------------------------------------------------------- */

# if defined (__cplusplus)

}

# endif /* __cplusplus */
#endif /* _lerp_h_ */
