/*
 * field.h
 *
 *  Created on: 2018年6月14日
 *      Author: lee
 */
/**
 * 定义数据表中的字段对象
 */
#include "dbInt.h"

/**
 * 数据字段所支持的类型
 * 包括：
 * 		- Bool
 * 		- Char
 * 		- Int
 * 		- Float
 * 		- Double
 * 		- String
 */
typedef enum vtype Type;

typedef struct field Field ;

String getName(Field field);

void setName(Field field);

Type getType(Field field);

void setType(Field field);
