/*
 * resultset.c
 *
 *  Created on: 2018年6月14日
 *      Author: lee
 */

/**
 * 数据库查询返回的 结果集
 */

#include "resultset.h"
#include "field.h"

typedef struct resultset ResultSet;

struct resultset {
	Field * fields;

};

/**
 * 让结果集的指针指向下一条记录上，如果结果集的下一条记录为空返回false
 * @param rs 结果集
 * @return 没有下一条记录时返回flase
 */
bool next(ResultSet rs) {
	//TODO: 将结果集中的指针移动到下一条记录上
	return false;
}

/**
 * 根据字段名从结果集中取出相应的字段
 */
bool getBool(ResultSet rs, String name) {
	//TODO: 根据结果集返回布尔值
	return false;
}

char getChar(ResultSet rs, String name) {
	//TODO: 根据结果集返回字符值
	return '0';
}
int getInt(ResultSet rs, String name) {
	//TODO: 根据结果集返回整数值
	return 0;
}
float getFloat(ResultSet rs, String name) {
	//TODO: 根据结果集返回浮点值
	return 0;
}
double getDouble(ResultSet rs, String name) {
	//TODO: 根据结果集返回双精度值
	return 0;
}

