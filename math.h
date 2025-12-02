/*
 *  math.h - C/C++ header-only math API
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#if defined (__cplusplus)
# pragma once
#endif /* __cplusplus */
#if !defined (_math_h_)
# define _math_h_ 1
#
#
# if !defined (MATH_STATIC_INLINE) && !defined (MATH_EXTERN)
#  define MATH_EXTERN 1
# endif /* MATH_STATIC_INLINE, MATH_EXTERN */
#
#
# if defined (MATH_STATIC_INLINE)
#  define MATHAPI static inline
#  define MATH_IMPLEMENTATION 1
# endif /* MATH_STATIC_INLINE */
#
# if defined (MATH_EXTERN)
#  if defined (__cplusplus)
#   define MATHAPI extern "C"
#  else
#   define MATHAPI extern
#  endif /* __cplusplus */
# endif /* MATH_EXTERN */
#
#
# include "./common.h"
# include "./struct.h"
# include "./vec2.h"
# include "./vec3.h"
# include "./vec4.h"
# include "./mat2.h"
# include "./mat3.h"
# include "./mat4.h"
# include "./ease.h"
# include "./lerp.h"
#
#endif /* _math_h_ */
