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
    mat.m0  = 1.0;
    mat.m5  = 1.0;
    mat.m10 = 1.0;
    mat.m15 = 1.0;
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

static inline const char *mat4_string(const mat4 m0) {
    static char buf[1024];

    if (!memset(buf, 0, sizeof(buf))) { return (0); }
    if (!snprintf(buf, sizeof(buf) - 1, "[ %f, %f, %f, %f ]\n[ %f, %f, %f, %f ]\n[ %f, %f, %f, %f ]\n[ %f, %f, %f, %f ]", m0.m0, m0.m1, m0.m2, m0.m3, m0.m4, m0.m5, m0.m6, m0.m7, m0.m8, m0.m9, m0.m10, m0.m11, m0.m12, m0.m13, m0.m14, m0.m15)) { return (0); }
    return (buf);
}

/* ---------------------------------------------------------------------------------------------------- */

# if defined (__cplusplus)

}

# endif /* __cplusplus */
#endif /* _mat4_h_ */
