/*
 * dbInt.h
 *
 *  Created on: 2018年6月14日
 *      Author: lee
 */
/*
 * 每个数据库源文件都直接或者间接的引用该头文件
 */
#ifndef SQLITEINT_H
#define SQLITEINT_H

#endif /* DBINT_H */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef true
#define true 1
#endif
#ifndef false
#define false 0
#endif

#ifndef UINT32_TYPE
# ifdef HAVE_UINT32_T
#  define UINT32_TYPE uint32_t
# else
#  define UINT32_TYPE unsigned int
# endif
#endif
#ifndef UINT16_TYPE
# ifdef HAVE_UINT16_T
#  define UINT16_TYPE uint16_t
# else
#  define UINT16_TYPE unsigned short int
# endif
#endif
#ifndef INT16_TYPE
# ifdef HAVE_INT16_T
#  define INT16_TYPE int16_t
# else
#  define INT16_TYPE short int
# endif
#endif
#ifndef UINT8_TYPE
# ifdef HAVE_UINT8_T
#  define UINT8_TYPE uint8_t
# else
#  define UINT8_TYPE unsigned char
# endif
#endif
#ifndef INT8_TYPE
# ifdef HAVE_INT8_T
#  define INT8_TYPE int8_t
# else
#  define INT8_TYPE signed char
# endif
#endif
#ifndef LONGDOUBLE_TYPE
# define LONGDOUBLE_TYPE long double
#endif


typedef long long int i64;
typedef UINT32_TYPE u32;           /* 4-byte unsigned integer */
typedef UINT16_TYPE u16;           /* 2-byte unsigned integer */
typedef INT16_TYPE i16;            /* 2-byte signed integer */
typedef UINT8_TYPE u8;             /* 1-byte unsigned integer */
typedef INT8_TYPE i8;              /* 1-byte signed integer */

typedef struct object Object;

typedef int bool;
typedef char * String;

//typedef struct conn {
//	int connid; /** 分配给数据库连接的id **/
//	String path; /**  **/
//} DBConn;

