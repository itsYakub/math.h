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
# include "./common.h"
# include "./vec2.h"
#
# if defined (__cplusplus)

extern "C" {

# endif /* __cplusplus */

/* ---------------------------------------------------------------------------------------------------- */

typedef union u_mat2 mat2;
union u_mat2 {
    struct {
        float m00, m01,
              m10, m11;
    };

    struct {
        vec2 m0, m1;
    };
};

/* ---------------------------------------------------------------------------------------------------- */

static inline mat2 mat2_zero(void) {
    mat2 mat = {{ 0.0, 0.0,
                  0.0, 0.0  }};

    return (mat);
}

static inline mat2 mat2_identity(void) {
    mat2 mat = {{ 1.0, 0.0,
                  0.0, 1.0  }};

    return (mat);
}

static inline mat2 mat2_copy(const mat2 m0) {
    mat2 mat;
    
    for (size_t i = 0; i < sizeof(mat2); i++) {
        ((unsigned char *) &mat.m00)[i] = ((unsigned char *) &m0.m00)[i];
    }

    return (mat);
}

/* ---------------------------------------------------------------------------------------------------- */

static inline mat2 mat2_add(const mat2 m0, const mat2 m1) {
    mat2 mat;

    mat.m0 = vec2_add(m0.m0, m1.m0);
    mat.m1 = vec2_add(m0.m1, m1.m1);
    return (mat);
}

/* ---------------------------------------------------------------------------------------------------- */

static inline mat2 mat2_sub(const mat2 m0, const mat2 m1) {
    mat2 mat;

    mat.m0 = vec2_sub(m0.m0, m1.m0);
    mat.m1 = vec2_sub(m0.m1, m1.m1);
    return (mat);
}

/* ---------------------------------------------------------------------------------------------------- */

static inline mat2 mat2_mul(const mat2 m0, const mat2 m1) {
    mat2 mat;

    mat.m00 = m0.m00 * m1.m00 + m0.m01 * m1.m10;
    mat.m01 = m0.m00 * m1.m01 + m0.m01 * m1.m11;
    
    mat.m10 = m0.m10 * m1.m10 + m0.m11 * m1.m10;
    mat.m11 = m0.m10 * m1.m11 + m0.m11 * m1.m11;
    return (mat);
}

static inline mat2 mat2_mulf(const mat2 m0, const float f) {
    mat2 mat;

    mat.m0 = vec2_mulf(m0.m0, f);
    mat.m1 = vec2_mulf(m0.m1, f);
    return (mat);
}

/* ---------------------------------------------------------------------------------------------------- */

static inline bool mat2_equals(const mat2 m0, const mat2 m1) {
    return (vec2_equals(m0.m0, m1.m0) &&
            vec2_equals(m0.m1, m1.m1));
}

/* ---------------------------------------------------------------------------------------------------- */

static inline float mat2_det(const mat2 m0) { return (m0.m00 * m0.m11 - m0.m10 * m0.m01); }

/* ---------------------------------------------------------------------------------------------------- */

static inline const float *mat2_ptr(const mat2 *m0) { return (&m0->m00); }

/* ---------------------------------------------------------------------------------------------------- */

static inline const char *mat2_string(const mat2 m0) {
    static char buf[1024];

    if (!memset(buf, 0, sizeof(buf))) { return (0); }
    strcat(buf, "[ "), strcat(buf, vec2_string(m0.m0)); strcat(buf, " ]\n");
    strcat(buf, "[ "), strcat(buf, vec2_string(m0.m1)); strcat(buf, " ]\n");
    return (buf);
}

/* ---------------------------------------------------------------------------------------------------- */

# if defined (__cplusplus)

}

# endif /* __cplusplus */
#
# if defined (__cplusplus)
#  if !defined (MATH_DISABLE_CPP_OPERATORS)

static inline mat2 operator + (const mat2 &v0, const mat2 &v1) { return (mat2_add(v0, v1)); }

const static inline mat2& operator += (mat2 &v0, const mat2 &v1) { return ((v0 = mat2_add(v0, v1))); }

static inline mat2 operator - (const mat2 &v0, const mat2 &v1)   { return (mat2_sub(v0, v1)); }

const static inline mat2& operator -= (mat2 &v0, const mat2 &v1) { return ((v0 = mat2_sub(v0, v1))); }

static inline mat2 operator * (const mat2 &v0, const mat2 &v1)   { return (mat2_mul(v0, v1)); }

const static inline mat2& operator *= (mat2 &v0, const mat2 &v1) { return ((v0 = mat2_mul(v0, v1))); }

static inline bool operator == (const mat2 &v0, const mat2 &v1) { return (mat2_equals(v0, v1)); }

static inline bool operator != (const mat2 &v0, const mat2 &v1) { return (!mat2_equals(v0, v1)); }

#  endif /* MATH_DISABLE_CPP_OPERATORS */
# endif /* __cplusplus */
#
#endif /* _mat2_h_ */
