/*
 *  mat2.h - 4D Matrix math module for C/C++
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#if defined (__cplusplus)
# pragma once
#endif /* __cplusplus */
#if !defined (_mat2_h_)
# define _mat2_h_ 1
#
# if !defined (__cplusplus)
#  include <stdio.h>
#  include <string.h>
#  include <stdbool.h>
# else 
#  include <cstdio>
#  include <cstring>
# endif /* __cplusplus */
# include "./math.h"
#
# if !defined (MATHAPI)
#  define MATHAPI static inline
# endif /* MATHAPI */
#
# if defined (__cplusplus)

extern "C" {

# endif /* __cplusplus */

MATHAPI mat2 mat2Zero(void) {
    mat2 mat = {{ 0.0, 0.0,
                  0.0, 0.0  }};

    return (mat);
}

MATHAPI mat2 mat2Identity(void) {
    mat2 mat = {{ 1.0, 0.0,
                  0.0, 1.0  }};

    return (mat);
}

MATHAPI mat2 mat2Copy(const mat2 m0) {
    mat2 mat;
    
    for (size_t i = 0; i < sizeof(mat2); i++) {
        ((unsigned char *) &mat.m00)[i] = ((unsigned char *) &m0.m00)[i];
    }

    return (mat);
}

/* ---------------------------------------------------------------------------------------------------- */

MATHAPI mat2 mat2Add(const mat2 m0, const mat2 m1) {
    mat2 mat;

    mat.m0 = vec2Add(m0.m0, m1.m0);
    mat.m1 = vec2Add(m0.m1, m1.m1);
    return (mat);
}

/* ---------------------------------------------------------------------------------------------------- */

MATHAPI mat2 mat2Sub(const mat2 m0, const mat2 m1) {
    mat2 mat;

    mat.m0 = vec2Sub(m0.m0, m1.m0);
    mat.m1 = vec2Sub(m0.m1, m1.m1);
    return (mat);
}

/* ---------------------------------------------------------------------------------------------------- */

MATHAPI mat2 mat2Mul(const mat2 m0, const mat2 m1) {
    mat2 mat;

    mat.m00 = m0.m00 * m1.m00 + m0.m10 * m1.m01;
    mat.m01 = m0.m01 * m1.m00 + m0.m11 * m1.m01;

    mat.m10 = m0.m00 * m1.m10 + m0.m10 * m1.m11;
    mat.m11 = m0.m01 * m1.m10 + m0.m11 * m1.m11;

    return (mat);
}

MATHAPI mat2 mat2Mulf(const mat2 m0, const float f) {
    mat2 mat;

    mat.m0 = vec2Mulf(m0.m0, f);
    mat.m1 = vec2Mulf(m0.m1, f);
    return (mat);
}

/* ---------------------------------------------------------------------------------------------------- */

MATHAPI bool mat2Equals(const mat2 m0, const mat2 m1) {
    return (vec2Equals(m0.m0, m1.m0) &&
            vec2Equals(m0.m1, m1.m1));
}

/* ---------------------------------------------------------------------------------------------------- */

MATHAPI float mat2Det(const mat2 m0) { return (m0.m00 * m0.m11 - m0.m10 * m0.m01); }

/* ---------------------------------------------------------------------------------------------------- */

MATHAPI const float *mat2Ptr(const mat2 *m0) { return (&m0->m00); }

/* ---------------------------------------------------------------------------------------------------- */

MATHAPI const char *mat2String(const mat2 m0) {
    static char buf[1024];

    if (!memset(buf, 0, sizeof(buf))) { return (0); }
    strcat(buf, "[ "), strcat(buf, vec2String(m0.m0)); strcat(buf, " ]\n");
    strcat(buf, "[ "), strcat(buf, vec2String(m0.m1)); strcat(buf, " ]\n");
    return (buf);
}

# if defined (__cplusplus)

}

# endif /* __cplusplus */
#
# if defined (__cplusplus)
#  if !defined (MATH_DISABLE_CPP_OPERATORS)

MATHAPI mat2 operator + (const mat2 &v0, const mat2 &v1) { return (mat2Add(v0, v1)); }

MATHAPI const mat2& operator += (mat2 &v0, const mat2 &v1) { return ((v0 = mat2Add(v0, v1))); }

MATHAPI mat2 operator - (const mat2 &v0, const mat2 &v1)   { return (mat2Sub(v0, v1)); }

MATHAPI const mat2& operator -= (mat2 &v0, const mat2 &v1) { return ((v0 = mat2Sub(v0, v1))); }

MATHAPI mat2 operator * (const mat2 &v0, const mat2 &v1)   { return (mat2Mul(v0, v1)); }

MATHAPI const mat2& operator *= (mat2 &v0, const mat2 &v1) { return ((v0 = mat2Mul(v0, v1))); }

MATHAPI bool operator == (const mat2 &v0, const mat2 &v1) { return (mat2Equals(v0, v1)); }

MATHAPI bool operator != (const mat2 &v0, const mat2 &v1) { return (!mat2Equals(v0, v1)); }

#  endif /* MATH_DISABLE_CPP_OPERATORS */
# endif /* __cplusplus */
#endif /* _mat2_h_ */
