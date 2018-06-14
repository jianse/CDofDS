/*
 * resultset.h
 *
 *  Created on: 2018年6月14日
 *      Author: lee
 */

/**
 * 数据库查询返回的 结果集
 */

#include "dbInt.h"

typedef struct resultset ResultSet;

/**
 * 让结果集的指针指向下一条记录上，如果结果集的下一条记录为空返回false
 * @param rs 结果集
 * @return 没有下一条记录时返回flase
 */
bool next(ResultSet rs);

/**
 * 根据字段名从结果集中取出相应的字段
 */
bool getBool(ResultSet rs,String name);
char getChar(ResultSet rs,String name);

int getInt(ResultSet rs, String name);
float getFloat(ResultSet rs, String name);
double getDouble(ResultSet rs, String name);

String getString(ResultSet rs,String name);
Object getObject(ResultSet rs,String name);



