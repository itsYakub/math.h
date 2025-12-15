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

MATHAPI float easeInSine(float t);


MATHAPI float easeOutSine(float t);


MATHAPI float easeInQuad(float t);


MATHAPI float easeOutQuad(float t);


MATHAPI float easeInCubic(float t);


MATHAPI float easeOutCubic(float t);


MATHAPI float easeInBack(float t);


MATHAPI float easeOutBack(float t);


MATHAPI float easeInElastic(float t);


MATHAPI float easeOutElastic(float t);


MATHAPI float easeOutBounce(float t);


MATHAPI float easeInBounce(float t);

# if defined (__cplusplus)

}

# endif /* __cplusplus */
#
# if defined (MATHAPI_IMPLEMENTATION)
#
# include "./common.h"

MATHAPI float easeInSine(float t) { return (1.0 - cos((clamp01(t) * PI) / 2.0)); }


MATHAPI float easeOutSine(float t) { return (sin((clamp01(t) * PI) / 2.0)); }


MATHAPI float easeInQuad(float t) { return (pow(clamp01(t), 2)); }


MATHAPI float easeOutQuad(float t) {
    t = clamp01(t);
    return (1.0 - (1.0 - t) * (1.0 - t));
}


MATHAPI float easeInCubic(float t) { return (pow(clamp01(t), 3)); }


MATHAPI float easeOutCubic(float t) { return (1.0 - pow(1.0 - clamp01(t), 3)); }


MATHAPI float easeInBack(float t) {
    const float c1 = 1.70158;
    const float c2 = c1 + 1;
    
    t = clamp01(t);
    return (c2 * pow(t, 3) - c1 * pow(t, 2));
}


MATHAPI float easeOutBack(float t) {
    const float c1 = 1.70158;
    const float c2 = c1 + 1;
    
    t = clamp01(t);
    return (1.0 + c2 * pow(t - 1.0, 3) + c1 * pow(t - 1.0, 2));
}


MATHAPI float easeOutElastic(float t) {
    const float c1 = (2.0 * PI) / 3.0;
    
    t = clamp01(t);
    return (t == 0.0
               ? 0.0
               : (t == 1.0
                     ? 1.0
                     : pow(2.0, -10 * t) * sin((t * 10.0 - 0.75) * c1) + 1.0
                )
            );
}


MATHAPI float easeInElastic(float t) {
    const float c1 = (2.0 * PI) / 3.0;
    
    t = clamp01(t);
    return (t == 0.0
               ? 0.0
               : (t == 1.0
                     ? 1.0
                     : pow(2.0, 10 * t - 10) * sin((t * 10.0 - 10.75) * c1)
                )
            );
}


MATHAPI float easeOutBounce(float t) {
    const float t1 = 7.5625;
    const float t2 = 2.75;
          
    t = clamp01(t);
    if (t < 1.0 / t2) { return (t1 * t * t); }

    float t3, t4;
    if (t < 2.0 / t2)      { t3 = 1.5,   t4 = 0.75;     }
    else if (t < 2.5 / t2) { t3 = 2.25,  t4 = 0.9375;   }
    else                   { t3 = 2.625, t4 = 0.984375; }

    float result = t1;
    result *= t - t3 / t2, t -= t3 / t2;
    result *= t;
    result += t4;
    return (result);
}


MATHAPI float easeInBounce(float t) { return (1.0 - easeOutBounce(1.0 - clamp01(t))); }

# endif /* MATHAPI_IMPLEMENTATION */
#endif /* _ease_h_ */
