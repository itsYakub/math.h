/*
 *  mat4.h - 4D Matrix math module for C/C++
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#if defined (__cplusplus)
# pragma once
#endif /* __cplusplus */
#if !defined (_mat4_h_)
# define _mat4_h_ 1
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
# include "./vec4.h"
#
# if defined (__cplusplus)

extern "C" {

# endif /* __cplusplus */

/* ---------------------------------------------------------------------------------------------------- */

typedef union u_mat4 mat4;
union u_mat4 {
    struct {
        float m0,  m1,  m2,  m3,
              m4,  m5,  m6,  m7,  
              m8,  m9,  m10, m11,  
              m12, m13, m14, m15;
    };

    struct {
        vec4 v0, v1, v2, v3;
    };

    float ptr[4][4];
};

/* ---------------------------------------------------------------------------------------------------- */

static inline mat4 mat4_zero(void) {
    mat4 mat;
    
    for (size_t i = 0; i < sizeof(mat4); i++) {
        ((unsigned char *) mat.ptr)[i] = 0;
    }
    return (mat);
}

static inline mat4 mat4_identity(void) {
    mat4 mat = mat4_zero();
    mat.m0   = 1.0;
    mat.m5   = 1.0;
    mat.m10  = 1.0;
    mat.m15  = 1.0;
    return (mat);
}

static inline mat4 mat4_init(void) {
    return (mat4_zero());
}

static inline mat4 mat4_copy(const mat4 m0) {
    mat4 mat;
    
    for (size_t i = 0; i < sizeof(mat4); i++) {
        ((unsigned char *) mat.ptr)[i] = ((unsigned char *) m0.ptr)[i];
    }
    return (mat);
}

/* ---------------------------------------------------------------------------------------------------- */

static inline mat4 mat4_add(const mat4 m0, const mat4 m1) {
    mat4 mat;

    mat.v0 = vec4_add(m0.v0, m1.v0);
    mat.v1 = vec4_add(m0.v1, m1.v1);
    mat.v2 = vec4_add(m0.v2, m1.v2);
    mat.v3 = vec4_add(m0.v3, m1.v3);
    return (mat);
}

# if defined (__cplusplus)
#  if !defined (MATH_DISABLE_CPP_OPERATORS)

static inline mat4 operator + (const mat4 &v0, const mat4 &v1) {
    return (mat4_add(v0, v1));
}

const static inline mat4& operator += (mat4 &v0, const mat4 &v1) {
    v0 = mat4_add(v0, v1); return (v0);
}

#  endif /* MATH_DISABLE_CPP_OPERATORS */
# endif /* __cplusplus */

/* ---------------------------------------------------------------------------------------------------- */

static inline mat4 mat4_sub(const mat4 m0, const mat4 m1) {
    mat4 mat;

    mat.v0 = vec4_sub(m0.v0, m1.v0);
    mat.v1 = vec4_sub(m0.v1, m1.v1);
    mat.v2 = vec4_sub(m0.v2, m1.v2);
    mat.v3 = vec4_sub(m0.v3, m1.v3);
    return (mat);
}

# if defined (__cplusplus)
#  if !defined (MATH_DISABLE_CPP_OPERATORS)

static inline mat4 operator - (const mat4 &v0, const mat4 &v1) {
    return (mat4_sub(v0, v1));
}

const static inline mat4& operator -= (mat4 &v0, const mat4 &v1) {
    v0 = mat4_sub(v0, v1); return (v0);
}

#  endif /* MATH_DISABLE_CPP_OPERATORS */
# endif /* __cplusplus */

/* ---------------------------------------------------------------------------------------------------- */

static inline mat4 mat4_mul(const mat4 m0, const mat4 m1) {
    mat4 mat;

    mat.m0  = m0.m0  * m1.m0 + m0.m1  * m1.m4 + m0.m2  * m1.m8  + m0.m3  * m1.m12;
    mat.m1  = m0.m0  * m1.m1 + m0.m1  * m1.m5 + m0.m2  * m1.m9  + m0.m3  * m1.m13;
    mat.m2  = m0.m0  * m1.m2 + m0.m1  * m1.m6 + m0.m2  * m1.m10 + m0.m3  * m1.m14;
    mat.m3  = m0.m0  * m1.m3 + m0.m1  * m1.m7 + m0.m2  * m1.m11 + m0.m3  * m1.m15;
    
    mat.m4  = m0.m4  * m1.m0 + m0.m5  * m1.m4 + m0.m6  * m1.m8  + m0.m7  * m1.m12;
    mat.m5  = m0.m4  * m1.m1 + m0.m5  * m1.m5 + m0.m6  * m1.m9  + m0.m7  * m1.m13;
    mat.m6  = m0.m4  * m1.m2 + m0.m5  * m1.m6 + m0.m6  * m1.m10 + m0.m7  * m1.m14;
    mat.m7  = m0.m4  * m1.m3 + m0.m5  * m1.m7 + m0.m6  * m1.m11 + m0.m7  * m1.m15;

    mat.m8  = m0.m8  * m1.m0 + m0.m9  * m1.m4 + m0.m10 * m1.m8  + m0.m11 * m1.m12;
    mat.m9  = m0.m8  * m1.m1 + m0.m9  * m1.m5 + m0.m10 * m1.m9  + m0.m11 * m1.m13;
    mat.m10 = m0.m8  * m1.m2 + m0.m9  * m1.m6 + m0.m10 * m1.m10 + m0.m11 * m1.m14;
    mat.m11 = m0.m8  * m1.m3 + m0.m9  * m1.m7 + m0.m10 * m1.m11 + m0.m11 * m1.m15;
    
    mat.m12 = m0.m12 * m1.m0 + m0.m13 * m1.m4 + m0.m14 * m1.m8  + m0.m15 * m1.m12;
    mat.m13 = m0.m12 * m1.m1 + m0.m13 * m1.m5 + m0.m14 * m1.m9  + m0.m15 * m1.m13;
    mat.m14 = m0.m12 * m1.m2 + m0.m13 * m1.m6 + m0.m14 * m1.m10 + m0.m15 * m1.m14;
    mat.m15 = m0.m12 * m1.m3 + m0.m13 * m1.m7 + m0.m14 * m1.m11 + m0.m15 * m1.m15;
    return (mat);
}

static inline mat4 mat4_mulf(const mat4 m0, const float f) {
    mat4 mat;

    mat.v0 = vec4_mulf(m0.v0, f);
    mat.v1 = vec4_mulf(m0.v1, f);
    mat.v2 = vec4_mulf(m0.v2, f);
    mat.v3 = vec4_mulf(m0.v3, f);
    return (mat);
}

# if defined (__cplusplus)
#  if !defined (MATH_DISABLE_CPP_OPERATORS)

static inline mat4 operator * (const mat4 &v0, const mat4 &v1) {
    return (mat4_mul(v0, v1));
}

const static inline mat4& operator *= (mat4 &v0, const mat4 &v1) {
    v0 = mat4_mul(v0, v1); return (v0);
}

#  endif /* MATH_DISABLE_CPP_OPERATORS */
# endif /* __cplusplus */

/* ---------------------------------------------------------------------------------------------------- */

static inline mat4 mat4_ortho(const float left, const float right, const float top, const float down, const float near, const float far) {
    mat4 mat = mat4_zero();
    mat.m0   = 2.0 / (right - left);
    mat.m5   = 2.0 / (top   - down);
    mat.m10  = 2.0 / (far   - near);
    mat.m12  = -(left + right) / (right - left);
    mat.m13  = -(top + down) / (top - down);
    mat.m14  = -(far + near) / (far - near);
    mat.m15  = 1.0;
    return (mat);
}

static inline mat4 mat4_frust(const float left, const float right, const float top, const float down, const float near, const float far) {
    mat4 mat = mat4_zero();
    mat.m0   = (near * 2.0) / (right - left);
    mat.m5   = (near * 2.0) / (top   - down);
    mat.m8   = (left + right) / (right - left);
    mat.m9   = (top + down) / (top - down);
    mat.m10  = -(far + near) / (far - near);
    mat.m11  = -1.0;
    mat.m14  = -(far * near * 2.0) / (far - near);
    return (mat);
}

static inline mat4 mat4_persp(const float fieldOfView, const float aspect, const float near, const float far) {
    float top   = near * tan(fieldOfView * 0.5);
    float right = top * aspect;
    return (mat4_frust(-right, right, top, -top, near, far));
}

/* ---------------------------------------------------------------------------------------------------- */

static inline bool mat4_equals(const mat4 m0, const mat4 m1) {
    return (vec4_equals(m0.v0, m1.v0) && vec4_equals(m0.v1, m1.v1) && vec4_equals(m0.v2, m1.v2) && vec4_equals(m0.v3, m1.v3));
}

# if defined (__cplusplus)
#  if !defined (MATH_DISABLE_CPP_OPERATORS)

static inline bool operator == (const mat4 &m0, const mat4 &m1) {
    return (mat4_equals(m0, m1));
}

static inline bool operator != (const mat4 &m0, const mat4 &m1) {
    return (!mat4_equals(m0, m1));
}

#  endif /* MATH_DISABLE_CPP_OPERATORS */
# endif /* __cplusplus */

/* ---------------------------------------------------------------------------------------------------- */

static inline const char *mat4_string(const mat4 m0) {
    static char buf[1024];

    if (!memset(buf, 0, sizeof(buf))) { return (0); }
    strcat(buf, "[ "), strcat(buf, vec4_string(m0.v0)); strcat(buf, " ]\n");
    strcat(buf, "[ "), strcat(buf, vec4_string(m0.v1)); strcat(buf, " ]\n");
    strcat(buf, "[ "), strcat(buf, vec4_string(m0.v2)); strcat(buf, " ]\n");
    strcat(buf, "[ "), strcat(buf, vec4_string(m0.v3)); strcat(buf, " ]\n");
    return (buf);
}

/* ---------------------------------------------------------------------------------------------------- */

# if defined (__cplusplus)

}

# endif /* __cplusplus */
#endif /* _mat4_h_ */
