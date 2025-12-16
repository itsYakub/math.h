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
# include "./common.h"
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
