/*
 * data.h
 *
 *  Created on: 2018年6月14日
 *      Author: lee
 *
 * 定义存入数据库的数据类型
 */

/**
 * 这接口规定了数据实体对象的序列化方式
 * 实现这个就扣规定的规则，可以让数据以一致的形式写入到磁盘上
 *
 */
#include "dominInt.h"
#ifdef getData
#undef getData
#define getData getDataInt
#else
#define getData getDataInt
#endif


#ifdef T
#undef T
#define T int
#else
#define T int
#endif
char * getData(T adt_data);
