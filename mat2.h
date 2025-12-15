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

MATHAPI mat2 mat2Zero(void);


MATHAPI mat2 mat2Identity(void);


MATHAPI mat2 mat2Copy(const mat2);


MATHAPI mat2 mat2Add(const mat2, const mat2);


MATHAPI mat2 mat2Sub(const mat2, const mat2);


MATHAPI mat2 mat2Mul(const mat2, const mat2);


MATHAPI mat2 mat2Mulf(const mat2, const float);


MATHAPI int mat2Equals(const mat2, const mat2);


MATHAPI float mat2Det(const mat2);

# if defined (__cplusplus)

}

# endif /* __cplusplus */
#
# if defined (__cplusplus)
#  if !defined (MATH_DISABLE_CPP_OPERATORS)

MATHAPI mat2 operator + (const mat2 &, const mat2 &);


MATHAPI const mat2& operator += (mat2 &, const mat2 &);


MATHAPI mat2 operator - (const mat2 &, const mat2 &);


MATHAPI const mat2& operator -= (mat2 &, const mat2 &);


MATHAPI mat2 operator * (const mat2 &, const mat2 &);


MATHAPI const mat2& operator *= (mat2 &, const mat2 &);


MATHAPI bool operator == (const mat2 &, const mat2 &);


MATHAPI bool operator != (const mat2 &, const mat2 &);

#  endif /* MATH_DISABLE_CPP_OPERATORS */
# endif /* __cplusplus */
#
# if defined (MATHAPI_IMPLEMENTATION)
#
#  if defined (__cplusplus)

extern "C" {

#  endif /* __cplusplus */

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
    mat2 mat = {{ m0.m00, m0.m01,
                  m0.m10, m0.m11  }};

    return (mat);
}


MATHAPI mat2 mat2Add(const mat2 m0, const mat2 m1) {
    mat2 mat;

    mat.m00 = m0.m00 + m1.m00;
    mat.m01 = m0.m01 + m1.m01;

    mat.m10 = m0.m10 + m1.m10;
    mat.m11 = m0.m11 + m1.m11;
    return (mat);
}


MATHAPI mat2 mat2Sub(const mat2 m0, const mat2 m1) {
    mat2 mat;

    mat.m00 = m0.m00 - m1.m00;
    mat.m01 = m0.m01 - m1.m01;

    mat.m10 = m0.m10 - m1.m10;
    mat.m11 = m0.m11 - m1.m11;
    return (mat);
}


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

    mat.m00 = m0.m00 * f;
    mat.m01 = m0.m01 * f;

    mat.m10 = m0.m10 * f;
    mat.m11 = m0.m11 * f;
    return (mat);
}


MATHAPI int mat2Equals(const mat2 m0, const mat2 m1) {
    return (m0.m00 == m1.m00 && m0.m01 == m1.m01 &&
            m0.m10 == m1.m10 && m0.m11 == m1.m11);
}


MATHAPI float mat2Det(const mat2 m0) {
    return (m0.m00 * m0.m11 - m0.m10 * m0.m01);
}

#  if defined (__cplusplus)

}

#  endif /* __cplusplus */
#
#  if defined (__cplusplus)
#   if !defined (MATH_DISABLE_CPP_OPERATORS)

MATHAPI mat2 operator + (const mat2 &v0, const mat2 &v1)   { return (mat2Add(v0, v1)); }


MATHAPI const mat2& operator += (mat2 &v0, const mat2 &v1) { return ((v0 = mat2Add(v0, v1))); }


MATHAPI mat2 operator - (const mat2 &v0, const mat2 &v1)   { return (mat2Sub(v0, v1)); }


MATHAPI const mat2& operator -= (mat2 &v0, const mat2 &v1) { return ((v0 = mat2Sub(v0, v1))); }


MATHAPI mat2 operator * (const mat2 &v0, const mat2 &v1)   { return (mat2Mul(v0, v1)); }


MATHAPI const mat2& operator *= (mat2 &v0, const mat2 &v1) { return ((v0 = mat2Mul(v0, v1))); }


MATHAPI bool operator == (const mat2 &v0, const mat2 &v1)  { return (mat2Equals(v0, v1)); }


MATHAPI bool operator != (const mat2 &v0, const mat2 &v1)  { return (!mat2Equals(v0, v1)); }

#   endif /* MATH_DISABLE_CPP_OPERATORS */
#  endif /* __cplusplus */
# endif /* MATHAPI_IMPLEMENTATION */
#endif /* _mat2_h_ */
