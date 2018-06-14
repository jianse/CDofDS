/*
 * database.c
 *
 *  Created on: 2018年6月14日
 *      Author: lee
 */
#include <io.h>

#include "database.h"

int CONN_ID = 1;

FILE *fp;

typedef struct ifield Field;
typedef enum vtype {
	Type_Bool, Type_Char, Type_Int, Type_Flout, Type_Double, Type_String
} Type;

typedef struct ifield {
	String name;
	Type type;
	int length;
} Field;

typedef struct conn {
	int connid;
	String path;
	bool isopen;
} DBConn;

Field * getField(String fieldName);
bool findField(String fieldName);
bool findTable(String tableName);
void inner_createTable(String tableName,Field fields);
void inner_addField(String tableName,Field fieldName);
void inner_removeField(String tableName,String  fieldName);
void inner_removeTable(String tableName);
void writeDefaultMatadata();

DBConn getConnection(String path) {
	if (strlen(path) == 0) {
		//TODO: 对给定的path进行必要的验证 ，保证是一个有效的路径
	}
	DBConn *iconn = (DBConn *) malloc(sizeof(DBConn));
	iconn->connid = CONN_ID;
	iconn->path = path;
	return *iconn;
}
bool findField(String fieldName){
	//TODO: 实现寻找域的方法
	return false;
}

DBSignal openDB(DBConn conn, ErrMsg errMsg) {
	if (access(conn.path, 2)) {
		fp = fopen(conn.path, "ab+");
		return OPT_SUCCEED;
	} else {
		fp = fopen(conn.path, "ab+");
		writeDefaultMatadata();
		return OPT_SUCCEED;
	}
	return OPT_SUCCEED;
}
void writeDefaultMatadata() {
	//TODO : 数据库原始信息的写入
}

DBSignal createTable(DBConn conn, String tableName, Field fields, ErrMsg errMsg) {
	if (conn.isopen) {
		if (!findTable(tableName)) {
			if (0) {
				//TODO:对fields内容进行一些健壮性的判断
			}
			inner_createTable(tableName, fields);
			return OPT_SUCCEED;
		} else {
			errMsg = "数据表已存在";
			return OPT_FAILED;
		}
	}
	errMsg = "数据库连接尚未打开";
	return OPT_FAILED;
}

void inner_createTable(String tableName, Field fields) {
	//TODO: 创建表的工作
}
Field * getField(String fieldName) {
	Field *f = malloc(sizeof(Field));
	return f;
}

DBSignal getFieldByName(DBConn conn, String tableName, String fieldName,
		Field * field, ErrMsg errMsg) {
	if (conn.isopen) {
		if (findTable(tableName)) {
			if (findField(fieldName)) {
				field = getField(fieldName);
				return OPT_SUCCEED;
			} else {
				errMsg = "未找到字段";
				return OPT_SUCCEED;
			}
		} else {
			errMsg = "未找到数据表";
			return OPT_FAILED;
		}
	}
	errMsg = "数据库连接尚未打开";
	return OPT_FAILED;
}

bool findTable(String tableName){
	//TODO:实现查询表是否存在
	return false;
}

DBSignal addField(DBConn conn, String tableName, Field field, ErrMsg errMsg) {
	if (conn.isopen) {
		if (findTable(tableName)) {
			if (!findField(field.name)) {
				inner_addField(tableName, field);
				return OPT_SUCCEED;
			} else {
				errMsg = "字段已存在";
				return OPT_FAILED;
			}
		} else {
			errMsg = "数据表不存在";
			return OPT_FAILED;
		}
	}
	errMsg = "数据库连接尚未打开";
	return OPT_FAILED;
}

void inner_addField(String tableName,Field field){
	//TODO:实现添加字段的方法
}
DBSignal removeField(DBConn conn, String tableName, Field field, ErrMsg errMsg) {
	if (conn.isopen) {
		if (findTable(tableName)) {
			if (findField(field.name)) {
				inner_removeField(tableName, field.name);
				return OPT_SUCCEED;
			} else {
				errMsg = "未找到字段";
				return OPT_FAILED;
			}
		}
		errMsg = "未找到数据表";
		return OPT_FAILED;
	}
	errMsg = "数据库连接尚未打开";
	return OPT_FAILED;
}

void inner_removeField(String tableName,  String fieldName){
	//TODO:实现删除字段的方法
}

DBSignal dropTable(DBConn conn, String tableName, ErrMsg errMsg) {
	if (conn.isopen) {
		if (findTable(tableName)) {
			inner_removeTable(tableName);
			return OPT_SUCCEED;
		} else {
			errMsg = "未找到数据表";
			return OPT_FAILED;
		}
	}
	errMsg = "数据库连接尚未打开";
	return OPT_FAILED;
}

void inner_removeTable(String tableName){
	//TODO:实现删除表
}

DBSignal insertRecord(DBConn conn, String tabelName, Data data, ErrMsg errMsg) {
	return OPT_FAILED;
}
