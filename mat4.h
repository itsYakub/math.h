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
# include "./vec3.h"
# include "./vec4.h"
# include "./mat3.h"
#
# if defined (__cplusplus)

extern "C" {

# endif /* __cplusplus */

/* ---------------------------------------------------------------------------------------------------- */

typedef union u_mat4 mat4;
union u_mat4 {
    struct {
        float m00, m01, m02, m03,
              m10, m11, m12, m13,
              m20, m21, m22, m23,
              m30, m31, m32, m33;
    };

    struct {
        vec4 m0, m1, m2, m3;
    };
};

/* ---------------------------------------------------------------------------------------------------- */

static inline mat4 mat4_zero(void) {
    mat4 mat = {{ 0.0, 0.0, 0.0, 0.0,
                  0.0, 0.0, 0.0, 0.0,
                  0.0, 0.0, 0.0, 0.0,
                  0.0, 0.0, 0.0, 0.0  }};

    return (mat);
}

static inline mat4 mat4_identity(void) {
    mat4 mat = {{ 1.0, 0.0, 0.0, 0.0,
                  0.0, 1.0, 0.0, 0.0,
                  0.0, 0.0, 1.0, 0.0,
                  0.0, 0.0, 0.0, 1.0  }};

    return (mat);
}

static inline mat4 mat4_copy(const mat4 m0) {
    mat4 mat;
    
    for (size_t i = 0; i < sizeof(mat4); i++) {
        ((unsigned char *) &mat.m00)[i] = ((unsigned char *) &m0.m00)[i];
    }

    return (mat);
}

/* ---------------------------------------------------------------------------------------------------- */

static inline mat4 mat4_add(const mat4 m0, const mat4 m1) {
    mat4 mat;

    mat.m0 = vec4_add(m0.m0, m1.m0);
    mat.m1 = vec4_add(m0.m1, m1.m1);
    mat.m2 = vec4_add(m0.m2, m1.m2);
    mat.m3 = vec4_add(m0.m3, m1.m3);
    return (mat);
}

/* ---------------------------------------------------------------------------------------------------- */

static inline mat4 mat4_sub(const mat4 m0, const mat4 m1) {
    mat4 mat;

    mat.m0 = vec4_sub(m0.m0, m1.m0);
    mat.m1 = vec4_sub(m0.m1, m1.m1);
    mat.m2 = vec4_sub(m0.m2, m1.m2);
    mat.m3 = vec4_sub(m0.m3, m1.m3);
    return (mat);
}

/* ---------------------------------------------------------------------------------------------------- */

static inline mat4 mat4_mul(const mat4 m0, const mat4 m1) {
    mat4 mat;

    mat.m00 = m0.m00 * m1.m00 + m0.m01 * m1.m10 + m0.m02 * m1.m20 + m0.m03 * m1.m30;
    mat.m01 = m0.m00 * m1.m01 + m0.m01 * m1.m11 + m0.m02 * m1.m21 + m0.m03 * m1.m31;
    mat.m02 = m0.m00 * m1.m02 + m0.m01 * m1.m12 + m0.m02 * m1.m22 + m0.m03 * m1.m32;
    mat.m03 = m0.m00 * m1.m03 + m0.m01 * m1.m13 + m0.m02 * m1.m23 + m0.m03 * m1.m33;
    
    mat.m10 = m0.m10 * m1.m10 + m0.m11 * m1.m10 + m0.m12 * m1.m20 + m0.m13 * m1.m30;
    mat.m11 = m0.m10 * m1.m11 + m0.m11 * m1.m11 + m0.m12 * m1.m21 + m0.m13 * m1.m31;
    mat.m12 = m0.m10 * m1.m12 + m0.m11 * m1.m12 + m0.m12 * m1.m22 + m0.m13 * m1.m32;
    mat.m13 = m0.m10 * m1.m13 + m0.m11 * m1.m13 + m0.m12 * m1.m23 + m0.m13 * m1.m33;
    
    mat.m20 = m0.m20 * m1.m20 + m0.m21 * m1.m10 + m0.m22 * m1.m20 + m0.m23 * m1.m30;
    mat.m21 = m0.m20 * m1.m21 + m0.m21 * m1.m11 + m0.m22 * m1.m21 + m0.m23 * m1.m31;
    mat.m22 = m0.m20 * m1.m22 + m0.m21 * m1.m12 + m0.m22 * m1.m22 + m0.m23 * m1.m32;
    mat.m23 = m0.m20 * m1.m23 + m0.m21 * m1.m13 + m0.m22 * m1.m23 + m0.m23 * m1.m33;
    
    mat.m30 = m0.m30 * m1.m30 + m0.m31 * m1.m10 + m0.m32 * m1.m20 + m0.m33 * m1.m30;
    mat.m31 = m0.m30 * m1.m31 + m0.m31 * m1.m11 + m0.m32 * m1.m21 + m0.m33 * m1.m31;
    mat.m32 = m0.m30 * m1.m32 + m0.m31 * m1.m12 + m0.m32 * m1.m22 + m0.m33 * m1.m32;
    mat.m33 = m0.m30 * m1.m33 + m0.m31 * m1.m13 + m0.m32 * m1.m23 + m0.m33 * m1.m33;
    return (mat);
}

static inline mat4 mat4_mulf(const mat4 m0, const float f) {
    mat4 mat;

    mat.m0 = vec4_mulf(m0.m0, f);
    mat.m1 = vec4_mulf(m0.m1, f);
    mat.m2 = vec4_mulf(m0.m2, f);
    mat.m3 = vec4_mulf(m0.m3, f);
    return (mat);
}

/* ---------------------------------------------------------------------------------------------------- */

static inline bool mat4_equals(const mat4 m0, const mat4 m1) {
    return (vec4_equals(m0.m0, m1.m0) &&
            vec4_equals(m0.m1, m1.m1) &&
            vec4_equals(m0.m2, m1.m2) &&
            vec4_equals(m0.m3, m1.m3));
}

/* ---------------------------------------------------------------------------------------------------- */

static inline mat4 mat4_ortho(const float left, const float right, const float top, const float down, const float near, const float far) {
    float left_right = ( 1.0 / (right - left));
    float top_bottom = ( 1.0 / (top   - down));
    float near_far   = (-1.0 / (far   - near));
    
    mat4 mat = mat4_zero();
    mat.m00  = 2.0 * left_right;
    mat.m11  = 2.0 * top_bottom;
    mat.m22  = 2.0 * near_far;
    mat.m30  = -(left + right) * left_right;
    mat.m31  = -(top + down)   * top_bottom;
    mat.m32  = -(far + near)   * near_far;
    mat.m33  = 1.0;
    return (mat);
}

static inline mat4 mat4_frust(const float left, const float right, const float top, const float down, const float near, const float far) {
    float left_right = ( 1.0 / (right - left));
    float top_bottom = ( 1.0 / (top   - down));
    float near_far   = (-1.0 / (far   - near));
    float near_value =   2.0 * near;

    mat4 mat = mat4_zero();
    mat.m00  = (near * 2.0)   * left_right;
    mat.m11  = (near * 2.0)   * top_bottom;
    mat.m20  = (left + right) * left_right;
    mat.m21  = (top + down)   * top_bottom;
    mat.m22  = (far + near)   * near_far;
    mat.m23  = -1.0;
    mat.m32  = far * near_value * near_far;
    return (mat);
}

static inline mat4 mat4_persp(const float fieldOfView, const float aspect, const float near, const float far) {
    float f0 = 1.0 * tan(fieldOfView * 0.5);
    float f1 = 1.0 / (far - near);
    
    mat4 mat = mat4_zero();
    mat.m00 = f0 / aspect;
    mat.m11 = f0;
    mat.m22 = (far + near) * f1;
    mat.m23 = -1.0;
    mat.m32 = 2.0 * near * far * f1;
    return (mat);
}

static inline mat4 mat4_lookat(const vec3 eye, const vec3 center, const vec3 up) {
    vec3 f, u, s;
    f = vec3_sub(center, eye);
    f = vec3_normalize(f);

    s = vec3_cross(up, f);
    s = vec3_normalize(s);

    u = vec3_cross(f, s);

    mat4 mat = mat4_zero();
    mat.m0 = vec4_init(s.x, u.x, f.x, 0.0);
    mat.m1 = vec4_init(s.y, u.y, f.y, 0.0);
    mat.m2 = vec4_init(s.z, u.z, f.z, 0.0);
    mat.m3 = vec4_init(-vec3_dot(s, eye), -vec3_dot(u, eye), -vec3_dot(f, eye), 1.0);
    return (mat);
}

/* ---------------------------------------------------------------------------------------------------- */

static inline float mat4_det(const mat4 m0) {
    float result = 0.0;

    result += m0.m00 * mat3_det((mat3) {{ m0.m11, m0.m12, m0.m13,
                                          m0.m21, m0.m22, m0.m23,
                                          m0.m31, m0.m32, m0.m33  }});

    result -= m0.m01 * mat3_det((mat3) {{ m0.m10, m0.m12, m0.m13,
                                          m0.m20, m0.m22, m0.m23,
                                          m0.m30, m0.m32, m0.m33  }});

    result += m0.m02 * mat3_det((mat3) {{ m0.m10, m0.m11, m0.m13,
                                          m0.m20, m0.m21, m0.m23,
                                          m0.m30, m0.m31, m0.m33  }});

    result -= m0.m03 * mat3_det((mat3) {{ m0.m10, m0.m11, m0.m12,
                                          m0.m20, m0.m21, m0.m22,
                                          m0.m30, m0.m31, m0.m32  }});

    return (result);
}

/* ---------------------------------------------------------------------------------------------------- */

static inline const float *mat4_ptr(const mat4 *m0) { return (&m0->m00); }

/* ---------------------------------------------------------------------------------------------------- */

static inline const char *mat4_string(const mat4 m0) {
    static char buf[1024];

    if (!memset(buf, 0, sizeof(buf))) { return (0); }
    strcat(buf, "[ "), strcat(buf, vec4_string(m0.m0)); strcat(buf, " ]\n");
    strcat(buf, "[ "), strcat(buf, vec4_string(m0.m1)); strcat(buf, " ]\n");
    strcat(buf, "[ "), strcat(buf, vec4_string(m0.m2)); strcat(buf, " ]\n");
    strcat(buf, "[ "), strcat(buf, vec4_string(m0.m3)); strcat(buf, " ]\n");
    return (buf);
}

/* ---------------------------------------------------------------------------------------------------- */

# if defined (__cplusplus)

}

# endif /* __cplusplus */
#
# if defined (__cplusplus)
#  if !defined (MATH_DISABLE_CPP_OPERATORS)

static inline mat4 operator + (const mat4 &v0, const mat4 &v1) { return (mat4_add(v0, v1)); }

const static inline mat4& operator += (mat4 &v0, const mat4 &v1) { return ((v0 = mat4_add(v0, v1))); }

static inline mat4 operator - (const mat4 &v0, const mat4 &v1)   { return (mat4_sub(v0, v1)); }

const static inline mat4& operator -= (mat4 &v0, const mat4 &v1) { return ((v0 = mat4_sub(v0, v1))); }

static inline mat4 operator * (const mat4 &v0, const mat4 &v1)   { return (mat4_mul(v0, v1)); }

const static inline mat4& operator *= (mat4 &v0, const mat4 &v1) { return ((v0 = mat4_mul(v0, v1))); }

static inline bool operator == (const mat4 &v0, const mat4 &v1) { return (mat4_equals(v0, v1)); }

static inline bool operator != (const mat4 &v0, const mat4 &v1) { return (!mat4_equals(v0, v1)); }

#  endif /* MATH_DISABLE_CPP_OPERATORS */
# endif /* __cplusplus */
#
#endif /* _mat4_h_ */
