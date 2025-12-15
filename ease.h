/*
 *  ease.h - ease math operations module for C/C++
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#if defined (__cplusplus)
# pragma once
#endif /* __cplusplus */
#if !defined (_ease_h_)
# define _ease_h_ 1
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
#  include <stddef.h>
# else
#  include <cstddef>
# endif /* __cplusplus */
# include "./common.h"
#
# if defined (__cplusplus)

extern "C" {

# endif /* __cplusplus */

/* ---------------------------------------------------------------------------------------------------- */

MATHAPI float easeOutSine(const float t) { return (sin((clamp01(t) * PI) / 2.0)); }

MATHAPI float easeOutQuad(const float t) {
    const float t1 = clamp01(t);
    return (1.0 - (1.0 - t1) * (1.0 - t1));
}

MATHAPI float easeOutCubic(const float t) { return (1.0 - pow(1.0 - clamp01(t), 3)); }

MATHAPI float easeOutBack(const float t) {
    const float c1 = 1.70158;
    const float c3 = c1 + 1;
    const float t1 = clamp01(t);
    return (1.0 + c3 * pow(t1 - 1.0, 3) + c1 * pow(t1 - 1.0, 2));
}

MATHAPI float easeOutElastic(const float t) {
    const float c4 = (2.0 * PI) / 3.0;
    const float t1 = clamp01(t);
    return (t == 0.0
               ? 0.0
               : (t == 1.0
                     ? 1.0
                     : pow(2.0, -10 * t1) * sin((t1 * 10.0 - 0.75) * c4) + 1.0
                )
            );
}

MATHAPI float easeOutBounce(const float t) {
          float t1 = clamp01(t);
    const float t2 = 7.5625;
    const float t3 = 2.75;

    if (t1 < 1.0 / t3) { return (t2 * t1 * t1); }

    float t4, t5;
    if (t1 < 2.0 / t3)      { t4 = 1.5, t5 = 0.75; }
    else if (t1 < 2.5 / t3) { t4 = 2.25, t5 = 0.9375; }
    else                    { t4 = 2.625, t5 = 0.984375; }

    float result = t2;
    result *= t1 - t4 / t3, t1 -= t4 / t3;
    result *= t1;
    result += t5;
    return (result);
}

/* ---------------------------------------------------------------------------------------------------- */

MATHAPI float easeInSine(const float t) { return (1.0 - cos((clamp01(t) * PI) / 2.0)); }

MATHAPI float easeInQuad(const float t) { return (pow(clamp01(t), 2)); }

MATHAPI float easeInCubic(const float t) { return (pow(clamp01(t), 3)); }

MATHAPI float easeInBack(const float t) {
    const float c1 = 1.70158;
    const float c3 = c1 + 1;
    const float t1 = clamp01(t);
    return (c3 * pow(t1, 3) - c1 * pow(t1, 2));
}

MATHAPI float easeInElastic(const float t) {
    const float c4 = (2.0 * PI) / 3.0;
    const float t1 = clamp01(t);
    return (t == 0.0
               ? 0.0
               : (t == 1.0
                     ? 1.0
                     : pow(2.0, 10 * t1 - 10) * sin((t1 * 10.0 - 10.75) * c4)
                )
            );
}

MATHAPI float easeInBounce(const float t) { return (1.0 - easeOutBounce(1.0 - clamp01(t))); }

/* ---------------------------------------------------------------------------------------------------- */

# if defined (__cplusplus)

}

# endif /* __cplusplus */
#endif /* _ease_h_ */
