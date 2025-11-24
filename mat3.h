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
# include "./common.h"
# include "./vec3.h"
#
# if defined (__cplusplus)

extern "C" {

# endif /* __cplusplus */

/* ---------------------------------------------------------------------------------------------------- */

typedef union u_mat3 mat3;
union u_mat3 {
    struct {
        float m00, m01, m02,
              m10, m11, m12,
              m20, m21, m22;
    };

    struct {
        vec3 m0, m1, m2;
    };
};

/* ---------------------------------------------------------------------------------------------------- */

static inline mat3 mat3_zero(void) {
    mat3 mat = {{ 0.0,  0.0,  0.0,
                  0.0,  0.0,  0.0,
                  0.0,  0.0,  0.0  }};

    return (mat);
}

static inline mat3 mat3_identity(void) {
    mat3 mat = {{ 1.0, 0.0, 0.0,
                  0.0, 1.0, 0.0,
                  0.0, 0.0, 1.0  }};

    return (mat);
}

static inline mat3 mat3_copy(const mat3 m0) {
    mat3 mat;
    
    for (size_t i = 0; i < sizeof(mat3); i++) {
        ((unsigned char *) &mat.m00)[i] = ((unsigned char *) &m0.m00)[i];
    }

    return (mat);
}

/* ---------------------------------------------------------------------------------------------------- */

static inline mat3 mat3_add(const mat3 m0, const mat3 m1) {
    mat3 mat;

    mat.m0 = vec3_add(m0.m0, m1.m0);
    mat.m1 = vec3_add(m0.m1, m1.m1);
    mat.m2 = vec3_add(m0.m2, m1.m2);
    return (mat);
}

# if defined (__cplusplus)
#  if !defined (MATH_DISABLE_CPP_OPERATORS)

static inline mat3 operator + (const mat3 &v0, const mat3 &v1)   { return (mat3_add(v0, v1)); }
const static inline mat3& operator += (mat3 &v0, const mat3 &v1) { v0 = mat3_add(v0, v1); return (v0); }

#  endif /* MATH_DISABLE_CPP_OPERATORS */
# endif /* __cplusplus */

/* ---------------------------------------------------------------------------------------------------- */

static inline mat3 mat3_sub(const mat3 m0, const mat3 m1) {
    mat3 mat;

    mat.m0 = vec3_sub(m0.m0, m1.m0);
    mat.m1 = vec3_sub(m0.m1, m1.m1);
    mat.m2 = vec3_sub(m0.m2, m1.m2);
    return (mat);
}

# if defined (__cplusplus)
#  if !defined (MATH_DISABLE_CPP_OPERATORS)

static inline mat3 operator - (const mat3 &v0, const mat3 &v1)   { return (mat3_sub(v0, v1)); }
const static inline mat3& operator -= (mat3 &v0, const mat3 &v1) { v0 = mat3_sub(v0, v1); return (v0); }

#  endif /* MATH_DISABLE_CPP_OPERATORS */
# endif /* __cplusplus */

/* ---------------------------------------------------------------------------------------------------- */

static inline mat3 mat3_mul(const mat3 m0, const mat3 m1) {
    mat3 mat;

    mat.m00 = m0.m00 * m1.m00 + m0.m01 * m1.m10 + m0.m02 * m1.m20;
    mat.m01 = m0.m00 * m1.m01 + m0.m01 * m1.m11 + m0.m02 * m1.m21;
    mat.m02 = m0.m00 * m1.m02 + m0.m01 * m1.m12 + m0.m02 * m1.m22;
    
    mat.m10 = m0.m10 * m1.m10 + m0.m11 * m1.m10 + m0.m12 * m1.m20;
    mat.m11 = m0.m10 * m1.m11 + m0.m11 * m1.m11 + m0.m12 * m1.m21;
    mat.m12 = m0.m10 * m1.m12 + m0.m11 * m1.m12 + m0.m12 * m1.m22;
    
    mat.m20 = m0.m20 * m1.m20 + m0.m21 * m1.m10 + m0.m22 * m1.m20;
    mat.m21 = m0.m20 * m1.m21 + m0.m21 * m1.m11 + m0.m22 * m1.m21;
    mat.m22 = m0.m20 * m1.m22 + m0.m21 * m1.m12 + m0.m22 * m1.m22;
    return (mat);
}

static inline mat3 mat3_mulf(const mat3 m0, const float f) {
    mat3 mat;

    mat.m0 = vec3_mulf(m0.m0, f);
    mat.m1 = vec3_mulf(m0.m1, f);
    mat.m2 = vec3_mulf(m0.m2, f);
    return (mat);
}

# if defined (__cplusplus)
#  if !defined (MATH_DISABLE_CPP_OPERATORS)

static inline mat3 operator * (const mat3 &v0, const mat3 &v1)   { return (mat3_mul(v0, v1)); }
const static inline mat3& operator *= (mat3 &v0, const mat3 &v1) { v0 = mat3_mul(v0, v1); return (v0); }

#  endif /* MATH_DISABLE_CPP_OPERATORS */
# endif /* __cplusplus */

/* ---------------------------------------------------------------------------------------------------- */

static inline bool mat3_equals(const mat3 m0, const mat3 m1) {
    return (vec3_equals(m0.m0, m1.m0) &&
            vec3_equals(m0.m1, m1.m1) &&
            vec3_equals(m0.m2, m1.m2));
}

# if defined (__cplusplus)
#  if !defined (MATH_DISABLE_CPP_OPERATORS)

static inline bool operator == (const mat3 &m0, const mat3 &m1) { return (mat3_equals(m0, m1)); }
static inline bool operator != (const mat3 &m0, const mat3 &m1) { return (!mat3_equals(m0, m1)); }

#  endif /* MATH_DISABLE_CPP_OPERATORS */
# endif /* __cplusplus */

/* ---------------------------------------------------------------------------------------------------- */

static inline float mat3_det(const mat3 m0) {
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

static inline const float *mat3_ptr(const mat3 *m0) { return (&m0->m00); }

/* ---------------------------------------------------------------------------------------------------- */

static inline const char *mat3_string(const mat3 m0) {
    static char buf[1024];

    if (!memset(buf, 0, sizeof(buf))) { return (0); }
    strcat(buf, "[ "), strcat(buf, vec3_string(m0.m0)); strcat(buf, " ]\n");
    strcat(buf, "[ "), strcat(buf, vec3_string(m0.m1)); strcat(buf, " ]\n");
    strcat(buf, "[ "), strcat(buf, vec3_string(m0.m2)); strcat(buf, " ]\n");
    return (buf);
}

/* ---------------------------------------------------------------------------------------------------- */

# if defined (__cplusplus)

}

# endif /* __cplusplus */
#endif /* _mat3_h_ */
