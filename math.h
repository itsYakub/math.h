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

/* TODO:
 *  Fix the problem with C++ operators that happens with a name-mangling fix
 *  (common problem with C++ where 'extern "C" { ... }' converts all the c++
 *   definitions to c-style definitions (and C++ doesn't like that)).
 * */
