/*
 * filed.c
 *
 *  Created on: 2018年6月14日
 *      Author: lee
 */

#include "field.h"

typedef struct field Field;
typedef enum vtype  {
	Type_Bool,
	Type_Char,
	Type_Int,
	Type_Flout,
	Type_Double,
	Type_String
}Type;

struct field {
	String name;

	Type type;
	int length;
};

String getName(Field field){
	return 0;
	//TODO: Finish this
}

void setName(Field field){
	//TODO: Finish this
}

Type getType(Field field){
	//TODO: Finish this
	return Type_Int;
}

void setType(Field field){
	//TODO: Finish this
}

