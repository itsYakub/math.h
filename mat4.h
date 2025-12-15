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
# include "./struct.h"
#
# if defined (__cplusplus)

extern "C" {

# endif /* __cplusplus */

MATHAPI mat4 mat4Zero(void);


MATHAPI mat4 mat4Identity(void);


MATHAPI mat4 mat4Copy(const mat4);


MATHAPI mat4 mat4Add(const mat4, const mat4);


MATHAPI mat4 mat4Sub(const mat4, const mat4);


MATHAPI mat4 mat4Mul(const mat4, const mat4);


MATHAPI mat4 mat4Mulf(const mat4, const float);


MATHAPI int mat4Equals(const mat4, const mat4);


MATHAPI mat4 mat4Orthographic(const float, const float, const float, const float, const float, const float);


MATHAPI mat4 mat4Frustum(const float, const float, const float, const float, const float, const float);


MATHAPI mat4 mat4Perspective(const float, const float, const float, const float);


MATHAPI mat4 mat4Translate(const vec3);


MATHAPI mat4 mat4Scale(const vec3);


MATHAPI mat4 mat4Rotate(const vec3, const float);


MATHAPI mat4 mat4RotateX(const float);


MATHAPI mat4 mat4RotateY(const float);


MATHAPI mat4 mat4RotateZ(const float);


MATHAPI mat4 mat4RotateV(const vec3);


MATHAPI mat4 mat4LookAt(const vec3, const vec3, const vec3);


MATHAPI float mat4Det(const mat4);

# if defined (__cplusplus)

}

# endif /* __cplusplus */
#
# if defined (__cplusplus)
#  if !defined (MATH_DISABLE_CPP_OPERATORS)

MATHAPI mat4 operator + (const mat4 &, const mat4 &);


MATHAPI const mat4& operator += (mat4 &, const mat4 &);


MATHAPI mat4 operator - (const mat4 &, const mat4 &);


MATHAPI const mat4& operator -= (mat4 &, const mat4 &);


MATHAPI mat4 operator * (const mat4 &, const mat4 &);


MATHAPI const mat4& operator *= (mat4 &, const mat4 &);


MATHAPI bool operator == (const mat4 &, const mat4 &);

#  endif /* MATH_DISABLE_CPP_OPERATORS */
# endif /* __cplusplus */
#
# if defined (MATHAPI_IMPLEMENTATION)
#
#  include "./common.h"
#  include "./mat3.h"
#
#  if defined (__cplusplus)

extern "C" {

#  endif /* __cplusplus */

MATHAPI mat4 mat4Zero(void) {
    mat4 mat = {{ 0.0, 0.0, 0.0, 0.0,
                  0.0, 0.0, 0.0, 0.0,
                  0.0, 0.0, 0.0, 0.0,
                  0.0, 0.0, 0.0, 0.0  }};

    return (mat);
}


MATHAPI mat4 mat4Identity(void) {
    mat4 mat = {{ 1.0, 0.0, 0.0, 0.0,
                  0.0, 1.0, 0.0, 0.0,
                  0.0, 0.0, 1.0, 0.0,
                  0.0, 0.0, 0.0, 1.0  }};

    return (mat);
}


MATHAPI mat4 mat4Copy(const mat4 m0) {
    mat4 mat = {{ m0.m00, m0.m01, m0.m02, m0.m03,
                  m0.m10, m0.m11, m0.m12, m0.m13,
                  m0.m20, m0.m21, m0.m22, m0.m23,
                  m0.m30, m0.m31, m0.m32, m0.m33  }};

    return (mat);
}


MATHAPI mat4 mat4Add(const mat4 m0, const mat4 m1) {
    mat4 mat;

    mat.m00 = m0.m00 + m1.m00;
    mat.m01 = m0.m01 + m1.m01;
    mat.m02 = m0.m02 + m1.m02;
    mat.m03 = m0.m03 + m1.m03;

    mat.m10 = m0.m10 + m1.m10;
    mat.m11 = m0.m11 + m1.m11;
    mat.m12 = m0.m12 + m1.m12;
    mat.m13 = m0.m13 + m1.m13;

    mat.m20 = m0.m20 + m1.m20;
    mat.m21 = m0.m21 + m1.m21;
    mat.m22 = m0.m22 + m1.m22;
    mat.m23 = m0.m23 + m1.m23;

    mat.m30 = m0.m30 + m1.m30;
    mat.m31 = m0.m31 + m1.m31;
    mat.m32 = m0.m32 + m1.m32;
    mat.m33 = m0.m33 + m1.m33;
    return (mat);
}


MATHAPI mat4 mat4Sub(const mat4 m0, const mat4 m1) {
    mat4 mat;

    mat.m00 = m0.m00 - m1.m00;
    mat.m01 = m0.m01 - m1.m01;
    mat.m02 = m0.m02 - m1.m02;
    mat.m03 = m0.m03 - m1.m03;

    mat.m10 = m0.m10 - m1.m10;
    mat.m11 = m0.m11 - m1.m11;
    mat.m12 = m0.m12 - m1.m12;
    mat.m13 = m0.m13 - m1.m13;

    mat.m20 = m0.m20 - m1.m20;
    mat.m21 = m0.m21 - m1.m21;
    mat.m22 = m0.m22 - m1.m22;
    mat.m23 = m0.m23 - m1.m23;

    mat.m30 = m0.m30 - m1.m30;
    mat.m31 = m0.m31 - m1.m31;
    mat.m32 = m0.m32 - m1.m32;
    mat.m33 = m0.m33 - m1.m33;
    return (mat);
}


MATHAPI mat4 mat4Mul(const mat4 m0, const mat4 m1) {
    mat4 mat;

    mat.m00 = m0.m00 * m1.m00 + m0.m10 * m1.m01 + m0.m20 * m1.m02 + m0.m30 * m1.m03;
    mat.m01 = m0.m01 * m1.m00 + m0.m11 * m1.m01 + m0.m21 * m1.m02 + m0.m31 * m1.m03;
    mat.m02 = m0.m02 * m1.m00 + m0.m12 * m1.m01 + m0.m22 * m1.m02 + m0.m32 * m1.m03;
    mat.m03 = m0.m03 * m1.m00 + m0.m13 * m1.m01 + m0.m23 * m1.m02 + m0.m33 * m1.m03;

    mat.m10 = m0.m00 * m1.m10 + m0.m10 * m1.m11 + m0.m20 * m1.m12 + m0.m30 * m1.m13;
    mat.m11 = m0.m01 * m1.m10 + m0.m11 * m1.m11 + m0.m21 * m1.m12 + m0.m31 * m1.m13;
    mat.m12 = m0.m02 * m1.m10 + m0.m12 * m1.m11 + m0.m22 * m1.m12 + m0.m32 * m1.m13;
    mat.m13 = m0.m03 * m1.m10 + m0.m13 * m1.m11 + m0.m23 * m1.m12 + m0.m33 * m1.m13;

    mat.m20 = m0.m00 * m1.m20 + m0.m10 * m1.m21 + m0.m20 * m1.m22 + m0.m30 * m1.m23;
    mat.m21 = m0.m01 * m1.m20 + m0.m11 * m1.m21 + m0.m21 * m1.m22 + m0.m31 * m1.m23;
    mat.m22 = m0.m02 * m1.m20 + m0.m12 * m1.m21 + m0.m22 * m1.m22 + m0.m32 * m1.m23;
    mat.m23 = m0.m03 * m1.m20 + m0.m13 * m1.m21 + m0.m23 * m1.m22 + m0.m33 * m1.m23;

    mat.m30 = m0.m00 * m1.m30 + m0.m10 * m1.m31 + m0.m20 * m1.m32 + m0.m30 * m1.m33;
    mat.m31 = m0.m01 * m1.m30 + m0.m11 * m1.m31 + m0.m21 * m1.m32 + m0.m31 * m1.m33;
    mat.m32 = m0.m02 * m1.m30 + m0.m12 * m1.m31 + m0.m22 * m1.m32 + m0.m32 * m1.m33;
    mat.m33 = m0.m03 * m1.m30 + m0.m13 * m1.m31 + m0.m23 * m1.m32 + m0.m33 * m1.m33;

    return (mat);
}


MATHAPI mat4 mat4Mulf(const mat4 m0, const float f) {
    mat4 mat;

    mat.m00 = m0.m00 * f;
    mat.m01 = m0.m01 * f;
    mat.m02 = m0.m02 * f;
    mat.m03 = m0.m03 * f;

    mat.m10 = m0.m10 * f;
    mat.m11 = m0.m11 * f;
    mat.m12 = m0.m12 * f;
    mat.m13 = m0.m13 * f;

    mat.m20 = m0.m20 * f;
    mat.m21 = m0.m21 * f;
    mat.m22 = m0.m22 * f;
    mat.m23 = m0.m23 * f;

    mat.m30 = m0.m30 * f;
    mat.m31 = m0.m31 * f;
    mat.m32 = m0.m32 * f;
    mat.m33 = m0.m33 * f;
    return (mat);
}

MATHAPI int mat4Equals(const mat4 m0, const mat4 m1) {
    return (m0.m00 == m1.m00 && m0.m01 == m1.m01 && m0.m02 == m1.m02 && m0.m03 == m1.m03 &&
            m0.m10 == m1.m10 && m0.m11 == m1.m11 && m0.m12 == m1.m12 && m0.m13 == m1.m13 &&
            m0.m20 == m1.m20 && m0.m21 == m1.m21 && m0.m22 == m1.m22 && m0.m23 == m1.m23 &&
            m0.m30 == m1.m30 && m0.m31 == m1.m31 && m0.m32 == m1.m32 && m0.m33 == m1.m33);
}

MATHAPI mat4 mat4Orthographic(const float left, const float right, const float top, const float down, const float near, const float far) {
    mat4 mat = mat4Zero();
    mat.m00  = 2.0 / (right - left);
    mat.m11  = 2.0 / (top   - down);
    mat.m22  = 2.0 / (far   - near);
    mat.m30  = -(left + right) / (right - left);
    mat.m31  = -(top + down) / (top - down);
    mat.m32  = -(far + near) / (far - near);
    mat.m33  = 1.0;
    return (mat);
}

MATHAPI mat4 mat4Frustum(const float left, const float right, const float top, const float down, const float near, const float far) {
    mat4 mat = mat4Zero();
    mat.m00  = (near * 2.0) / (right - left);
    mat.m11  = (near * 2.0) / (top   - down);
    mat.m20  = (left + right) / (right - left);
    mat.m21  = (top + down) / (top - down);
    mat.m22  = -(far + near) / (far - near);
    mat.m23  = -1.0;
    mat.m32  = -(far * near * 2.0) / (far - near);
    return (mat);
}

MATHAPI mat4 mat4Perspective(const float fieldOfView, const float aspect, const float near, const float far) {
    float top   = near * tan(fieldOfView * 0.5);
    float right = top * aspect;
    return (mat4Frustum(-right, right, top, -top, near, far));
}

MATHAPI mat4 mat4Translate(const vec3 v0) {
    return ((mat4) {{ 1.0,  0.0,  0.0,  0.0,
                      0.0,  1.0,  0.0,  0.0,
                      0.0,  0.0,  1.0,  0.0,
                      v0.x, v0.y, v0.z, 1.0  }} );
}

MATHAPI mat4 mat4Scale(const vec3 v0) {
    return ((mat4) {{ v0.x, 0.0,  0.0,  0.0,
                      0.0,  v0.y, 0.0,  0.0,
                      0.0,  0.0,  v0.z, 0.0,
                      0.0,  0.0,  0.0,  1.0  }} );
}

MATHAPI mat4 mat4Rotate(const vec3 axis, const float angle) {
    float c = cos(angle);
    float s = sin(angle);
    float t = 1.0f - c;

    vec3 axisn = vec3Normalize(axis);
    float x = axisn.x,
          y = axisn.y,
          z = axisn.z;

    mat4 m = mat4Identity();

    m.m00 = t*x*x + c;
    m.m01 = t*y*x + s*z;
    m.m02 = t*z*x - s*y;

    m.m10 = t*x*y - s*z;
    m.m11 = t*y*y + c;
    m.m12 = t*z*y + s*x;

    m.m20 = t*x*z + s*y;
    m.m21 = t*y*z - s*x;
    m.m22 = t*z*z + c;

    return (m);
}

MATHAPI mat4 mat4RotateX(const float angle) {
    float sinres = sin(angle),
          cosres = cos(angle);

    mat4 value = mat4Identity();
    value.m11 = cosres;
    value.m12 = sinres;
    value.m21 = -sinres;
    value.m22 = cosres;
    return (value);
}

MATHAPI mat4 mat4RotateY(const float angle) {
    float sinres = sin(angle),
          cosres = cos(angle);

    mat4 value = mat4Identity();
    value.m00 = cosres;
    value.m02 = -sinres;
    value.m20 = sinres;
    value.m22 = cosres;
    return (value);
}

MATHAPI mat4 mat4RotateZ(const float angle) {
    float sinres = sin(angle),
          cosres = cos(angle);

    mat4 value = mat4Identity();
    value.m00 = cosres;
    value.m01 = sinres;
    value.m10 = -sinres;
    value.m11 = cosres;
    return (value);
}

MATHAPI mat4 mat4RotateV(const vec3 angle) {
    float sinx = sin(-angle.x), cosx = cos(-angle.x),
          siny = sin(-angle.y), cosy = cos(-angle.y),
          sinz = sin(-angle.z), cosz = cos(-angle.z);

    mat4 value = mat4Identity();
    value.m00 = cosz * siny;
    value.m01 = (cosz * siny * sinx) - (sinz * cosx);
    value.m02 = (cosz * siny * cosx) - (sinz * sinx);
    
    value.m10 = sinz * cosy;
    value.m11 = (sinz * siny * sinx) - (cosz * cosx);
    value.m12 = (sinz * siny * cosx) - (cosz * sinx);
    
    value.m20 = -siny;
    value.m21 = cosz * sinx;
    value.m22 = cosy * cosx;
    return (value);
}

MATHAPI mat4 mat4RotateAt(const vec3 pivot, const vec3 axis, const float angle) {
    mat4 value = mat4Identity();
         value = mat4Mul(value, mat4Translate(pivot));
         value = mat4Mul(value, mat4Rotate(axis, angle));

    return (value);
}

MATHAPI mat4 mat4LookAt(const vec3 eye, const vec3 center, const vec3 up) {
    vec3 f, u, s;
    f = vec3Sub(center, eye);
    f = vec3Normalize(f);

    s = vec3Cross(up, f);
    s = vec3Normalize(s);

    u = vec3Cross(f, s);

    mat4 mat = mat4Zero();
    mat.m0 = vec4Init(s.x, u.x, f.x, 0.0);
    mat.m1 = vec4Init(s.y, u.y, f.y, 0.0);
    mat.m2 = vec4Init(s.z, u.z, f.z, 0.0);
    mat.m3 = vec4Init(-vec3Dot(s, eye), -vec3Dot(u, eye), -vec3Dot(f, eye), 1.0);
    return (mat);
}

MATHAPI float mat4Det(const mat4 m0) {
    float result = 0.0;

    result += m0.m00 * mat3Det((mat3) {{ m0.m11, m0.m12, m0.m13,
                                         m0.m21, m0.m22, m0.m23,
                                         m0.m31, m0.m32, m0.m33  }} );

    result -= m0.m01 * mat3Det((mat3) {{ m0.m10, m0.m12, m0.m13,
                                         m0.m20, m0.m22, m0.m23,
                                         m0.m30, m0.m32, m0.m33  }} );

    result += m0.m02 * mat3Det((mat3) {{ m0.m10, m0.m11, m0.m13,
                                         m0.m20, m0.m21, m0.m23,
                                         m0.m30, m0.m31, m0.m33  }} );

    result -= m0.m03 * mat3Det((mat3) {{ m0.m10, m0.m11, m0.m12,
                                         m0.m20, m0.m21, m0.m22,
                                         m0.m30, m0.m31, m0.m32  }} );

    return (result);
}

#  if defined (__cplusplus)

}

#  endif /* __cplusplus */
#
#  if defined (__cplusplus)
#   if !defined (MATH_DISABLE_CPP_OPERATORS)
MATHAPI mat4 operator + (const mat4 &v0, const mat4 &v1) { return (mat4Add(v0, v1)); }

MATHAPI const mat4& operator += (mat4 &v0, const mat4 &v1) { return ((v0 = mat4Add(v0, v1))); }

MATHAPI mat4 operator - (const mat4 &v0, const mat4 &v1)   { return (mat4Sub(v0, v1)); }

MATHAPI const mat4& operator -= (mat4 &v0, const mat4 &v1) { return ((v0 = mat4Sub(v0, v1))); }

MATHAPI mat4 operator * (const mat4 &v0, const mat4 &v1)   { return (mat4Mul(v0, v1)); }

MATHAPI const mat4& operator *= (mat4 &v0, const mat4 &v1) { return ((v0 = mat4Mul(v0, v1))); }

MATHAPI bool operator == (const mat4 &v0, const mat4 &v1) { return (mat4Equals(v0, v1)); }

#   endif /* MATH_DISABLE_CPP_OPERATORS */
#  endif /* __cplusplus */
# endif /* MATHAPI_IMPLEMENTATION */
#endif /* _mat4_h_ */
