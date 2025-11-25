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

static inline float easeOut_sine(const float t) { return (sin((clamp01(t) * PI) / 2.0)); }

static inline float easeOut_quad(const float t) {
    const float t1 = clamp01(t);
    return (1.0 - (1.0 - t1) * (1.0 - t1));
}

static inline float easeOut_cubic(const float t) { return (1.0 - pow(1.0 - clamp01(t), 3)); }

static inline float easeOut_back(const float t) {
    const float c1 = 1.70158;
    const float c3 = c1 + 1;
    const float t1 = clamp01(t);
    return (1.0 + c3 * pow(t1 - 1.0, 3) + c1 * pow(t1 - 1.0, 2));
}

static inline float easeOut_elastic(const float t) {
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

static inline float easeOut_bounce(const float t) {
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

static inline float easeIn_sine(const float t) { return (1.0 - cos((clamp01(t) * PI) / 2.0)); }

static inline float easeIn_quad(const float t) { return (pow(clamp01(t), 2)); }

static inline float easeIn_cubic(const float t) { return (pow(clamp01(t), 3)); }

static inline float easeIn_back(const float t) {
    const float c1 = 1.70158;
    const float c3 = c1 + 1;
    const float t1 = clamp01(t);
    return (c3 * pow(t1, 3) - c1 * pow(t1, 2));
}

static inline float easeIn_elastic(const float t) {
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

static inline float easeIn_bounce(const float t) { return (1.0 - easeOut_bounce(1.0 - clamp01(t))); }

/* ---------------------------------------------------------------------------------------------------- */

# if defined (__cplusplus)

}

# endif /* __cplusplus */
#endif /* _ease_h_ */
