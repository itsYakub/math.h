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

MATHAPI mat3 mat3Zero(void);


MATHAPI mat3 mat3Identity(void);


MATHAPI mat3 mat3Copy(const mat3);


MATHAPI mat3 mat3Add(const mat3, const mat3);


MATHAPI mat3 mat3Sub(const mat3, const mat3);


MATHAPI mat3 mat3Mul(const mat3, const mat3);


MATHAPI mat3 mat3Mulf(const mat3, const float);


MATHAPI int mat3Equals(const mat3, const mat3);


MATHAPI float mat3Det(const mat3);

# if defined (__cplusplus)

}

# endif /* __cplusplus */
#
# if defined (__cplusplus)
#  if !defined (MATH_DISABLE_CPP_OPERATORS)

MATHAPI mat3 operator + (const mat3 &, const mat3 &);


MATHAPI const mat3& operator += (mat3 &, const mat3 &);


MATHAPI mat3 operator - (const mat3 &, const mat3 &);


MATHAPI const mat3& operator -= (mat3 &, const mat3 &);


MATHAPI mat3 operator * (const mat3 &, const mat3 &);


MATHAPI const mat3& operator *= (mat3 &, const mat3 &);


MATHAPI bool operator == (const mat3 &, const mat3 &);


MATHAPI bool operator != (const mat3 &, const mat3 &);

#  endif /* MATH_DISABLE_CPP_OPERATORS */
# endif /* __cplusplus */
#
# if defined (MATHAPI_IMPLEMENTATION)
#
#  if defined (__cplusplus)

extern "C" {

#  endif /* __cplusplus */

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
    mat3 mat = {{ m0.m00, m0.m01, m0.m02,
                  m0.m10, m0.m11, m0.m12,
                  m0.m20, m0.m21, m0.m22  }};

    return (mat);
}


MATHAPI mat3 mat3Add(const mat3 m0, const mat3 m1) {
    mat3 mat;

    mat.m00 = m0.m00 + m1.m00;
    mat.m01 = m0.m01 + m1.m01;
    mat.m02 = m0.m02 + m1.m02;

    mat.m10 = m0.m10 + m1.m10;
    mat.m11 = m0.m11 + m1.m11;
    mat.m12 = m0.m12 + m1.m12;
    
    mat.m20 = m0.m20 + m1.m20;
    mat.m21 = m0.m21 + m1.m21;
    mat.m22 = m0.m22 + m1.m22;
    return (mat);
}


MATHAPI mat3 mat3Sub(const mat3 m0, const mat3 m1) {
    mat3 mat;

    mat.m00 = m0.m00 - m1.m00;
    mat.m01 = m0.m01 - m1.m01;
    mat.m02 = m0.m02 - m1.m02;

    mat.m10 = m0.m10 - m1.m10;
    mat.m11 = m0.m11 - m1.m11;
    mat.m12 = m0.m12 - m1.m12;
    
    mat.m20 = m0.m20 - m1.m20;
    mat.m21 = m0.m21 - m1.m21;
    mat.m22 = m0.m22 - m1.m22;
    return (mat);
}


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

    mat.m00 = m0.m00 * f; 
    mat.m01 = m0.m01 * f;
    mat.m02 = m0.m02 * f;

    mat.m10 = m0.m10 * f;
    mat.m11 = m0.m11 * f;
    mat.m12 = m0.m12 * f;
    
    mat.m20 = m0.m20 * f;
    mat.m21 = m0.m21 * f;
    mat.m22 = m0.m22 * f;
    return (mat);
}


MATHAPI int mat3Equals(const mat3 m0, const mat3 m1) {
    return (m0.m00 == m1.m00 && m0.m01 == m1.m01 && m0.m02 == m1.m02 &&
            m0.m10 == m1.m10 && m0.m11 == m1.m11 && m0.m12 == m1.m12 &&
            m0.m20 == m1.m20 && m0.m21 == m1.m21 && m0.m22 == m1.m22);
}


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

#  if defined (__cplusplus)

}

#  endif /* __cplusplus */
#
#  if defined (__cplusplus)
#   if !defined (MATH_DISABLE_CPP_OPERATORS)

MATHAPI mat3 operator + (const mat3 &v0, const mat3 &v1) { return (mat3Add(v0, v1)); }


MATHAPI const mat3& operator += (mat3 &v0, const mat3 &v1) { return ((v0 = mat3Add(v0, v1))); }


MATHAPI mat3 operator - (const mat3 &v0, const mat3 &v1)   { return (mat3Sub(v0, v1)); }


MATHAPI const mat3& operator -= (mat3 &v0, const mat3 &v1) { return ((v0 = mat3Sub(v0, v1))); }


MATHAPI mat3 operator * (const mat3 &v0, const mat3 &v1)   { return (mat3Mul(v0, v1)); }


MATHAPI const mat3& operator *= (mat3 &v0, const mat3 &v1) { return ((v0 = mat3Mul(v0, v1))); }


MATHAPI bool operator == (const mat3 &v0, const mat3 &v1) { return (mat3Equals(v0, v1)); }


MATHAPI bool operator != (const mat3 &v0, const mat3 &v1) { return (!mat3Equals(v0, v1)); }

#   endif /* MATH_DISABLE_CPP_OPERATORS */
#  endif /* __cplusplus */
# endif /* MATHAPI_IMPLEMENTATION */
#endif /* _mat3_h_ */
