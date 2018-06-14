/*
 * filed.c
 *
 *  Created on: 2018年6月14日
 *      Author: lee
 */

#include "field.h"

typedef struct ifield Field;
typedef enum vtype  {
	Type_Bool,
	Type_Char,
	Type_Int,
	Type_Flout,
	Type_Double,
	Type_String
}Type;

struct ifield {
	String name;
	Type type;
	int length;
};
