/*
 *  mat3.h - 4D Matrix math module for C/C++
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#if defined (__cplusplus)
# pragma once
#endif /* __cplusplus */
#if !defined (_mat3_h_)
# define _mat3_h_ 1
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

MATHAPI mat3 mat3Zero(void) {
    mat3 mat = {{ 0.0,  0.0,  0.0,
                  0.0,  0.0,  0.0,
                  0.0,  0.0,  0.0  }};

    return (mat);
}

MATHAPI mat3 mat3Identity(void) {
    mat3 mat = {{ 1.0, 0.0, 0.0,
                  0.0, 1.0, 0.0,
                  0.0, 0.0, 1.0  }};

    return (mat);
}

MATHAPI mat3 mat3Copy(const mat3 m0) {
    mat3 mat;
    
    for (size_t i = 0; i < sizeof(mat3); i++) {
        ((unsigned char *) &mat.m00)[i] = ((unsigned char *) &m0.m00)[i];
    }

    return (mat);
}

/* ---------------------------------------------------------------------------------------------------- */

MATHAPI mat3 mat3Add(const mat3 m0, const mat3 m1) {
    mat3 mat;

    mat.m0 = vec3Add(m0.m0, m1.m0);
    mat.m1 = vec3Add(m0.m1, m1.m1);
    mat.m2 = vec3Add(m0.m2, m1.m2);
    return (mat);
}

/* ---------------------------------------------------------------------------------------------------- */

MATHAPI mat3 mat3Sub(const mat3 m0, const mat3 m1) {
    mat3 mat;

    mat.m0 = vec3Sub(m0.m0, m1.m0);
    mat.m1 = vec3Sub(m0.m1, m1.m1);
    mat.m2 = vec3Sub(m0.m2, m1.m2);
    return (mat);
}

/* ---------------------------------------------------------------------------------------------------- */

MATHAPI mat3 mat3Mul(const mat3 m0, const mat3 m1) {
    mat3 mat;

    mat.m00 = m0.m00 * m1.m00 + m0.m10 * m1.m01 + m0.m20 * m1.m02;
    mat.m01 = m0.m01 * m1.m00 + m0.m11 * m1.m01 + m0.m21 * m1.m02;
    mat.m02 = m0.m02 * m1.m00 + m0.m12 * m1.m01 + m0.m22 * m1.m02;

    mat.m10 = m0.m00 * m1.m10 + m0.m10 * m1.m11 + m0.m20 * m1.m12;
    mat.m11 = m0.m01 * m1.m10 + m0.m11 * m1.m11 + m0.m21 * m1.m12;
    mat.m12 = m0.m02 * m1.m10 + m0.m12 * m1.m11 + m0.m22 * m1.m12;

    mat.m20 = m0.m00 * m1.m20 + m0.m10 * m1.m21 + m0.m20 * m1.m22;
    mat.m21 = m0.m01 * m1.m20 + m0.m11 * m1.m21 + m0.m21 * m1.m22;
    mat.m22 = m0.m02 * m1.m20 + m0.m12 * m1.m21 + m0.m22 * m1.m22;

    return (mat);
}

MATHAPI mat3 mat3Mulf(const mat3 m0, const float f) {
    mat3 mat;

    mat.m0 = vec3Mulf(m0.m0, f);
    mat.m1 = vec3Mulf(m0.m1, f);
    mat.m2 = vec3Mulf(m0.m2, f);
    return (mat);
}

/* ---------------------------------------------------------------------------------------------------- */

MATHAPI bool mat3Equals(const mat3 m0, const mat3 m1) {
    return (vec3Equals(m0.m0, m1.m0) &&
            vec3Equals(m0.m1, m1.m1) &&
            vec3Equals(m0.m2, m1.m2));
}

/* ---------------------------------------------------------------------------------------------------- */

MATHAPI float mat3Det(const mat3 m0) {
    float result = 0.0;

    result += m0.m00 * m0.m11 * m0.m22;
    result += m0.m01 * m0.m12 * m0.m20;
    result += m0.m02 * m0.m10 * m0.m21;
    
    result -= m0.m20 * m0.m11 * m0.m02;
    result -= m0.m21 * m0.m12 * m0.m00;
    result -= m0.m22 * m0.m10 * m0.m01;
    
    return (result);
}

/* ---------------------------------------------------------------------------------------------------- */

MATHAPI const float *mat3Ptr(const mat3 *m0) { return (&m0->m00); }

/* ---------------------------------------------------------------------------------------------------- */

MATHAPI const char *mat3String(const mat3 m0) {
    static char buf[1024];

    if (!memset(buf, 0, sizeof(buf))) { return (0); }
    strcat(buf, "[ "), strcat(buf, vec3String(m0.m0)); strcat(buf, " ]\n");
    strcat(buf, "[ "), strcat(buf, vec3String(m0.m1)); strcat(buf, " ]\n");
    strcat(buf, "[ "), strcat(buf, vec3String(m0.m2)); strcat(buf, " ]\n");
    return (buf);
}

# if defined (__cplusplus)

}

# endif /* __cplusplus */
#
# if defined (__cplusplus)
#  if !defined (MATH_DISABLE_CPP_OPERATORS)

MATHAPI mat3 operator + (const mat3 &v0, const mat3 &v1) { return (mat3Add(v0, v1)); }

MATHAPI const mat3& operator += (mat3 &v0, const mat3 &v1) { return ((v0 = mat3Add(v0, v1))); }

MATHAPI mat3 operator - (const mat3 &v0, const mat3 &v1)   { return (mat3Sub(v0, v1)); }

MATHAPI const mat3& operator -= (mat3 &v0, const mat3 &v1) { return ((v0 = mat3Sub(v0, v1))); }

MATHAPI mat3 operator * (const mat3 &v0, const mat3 &v1)   { return (mat3Mul(v0, v1)); }

MATHAPI const mat3& operator *= (mat3 &v0, const mat3 &v1) { return ((v0 = mat3Mul(v0, v1))); }

MATHAPI bool operator == (const mat3 &v0, const mat3 &v1) { return (mat3Equals(v0, v1)); }

MATHAPI bool operator != (const mat3 &v0, const mat3 &v1) { return (!mat3Equals(v0, v1)); }

#  endif /* MATH_DISABLE_CPP_OPERATORS */
# endif /* __cplusplus */
#endif /* _mat3_h_ */
