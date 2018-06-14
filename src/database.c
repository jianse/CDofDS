/*
 * database.c
 *
 *  Created on: 2018年6月14日
 *      Author: lee
 */
#include <io.h>

#include "database.h"

int CONN_ID = 1;

FILE fp;

typedef struct conn {
	int connid;
	String path;
	bool isopen;
} DBConn;

DBConn getConnection(String path) {
	if (strlen(*path) == 0) {
		//TODO: 待完成
	}
	DBConn iconn = malloc(sizeof(DBConn));
	iconn.connid = CONN_ID;
	iconn.path = path;
	return iconn;
}

DBSignal open(DBConn conn, ErrMsg errMsg) {
	if (access(conn.path, 2))
		fp = fopen(conn.path, "ab+");
	else {
		fp = fopen(conn.path, "ab+");
		writeDefaultMatadata();
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
			createTable(tableName, fields);
			return OPT_SUCCEED;
		} else {
			errMsg = "数据表已存在";
			return OPT_FAILED;
		}
	}
	errMsg = "数据库连接尚未打开";
	return OPT_FAILED;
}

void createTable(String tableName, Field fields) {
	//TODO: 创建表的工作
}

DBSignal getFieldByName(DBConn conn, String tableName, String fieldName,
		Field field, ErrMsg errMsg) {
	if (conn.isopen) {
		if (findTable(tableName)) {
			if (findField(fieldName)) {
				field = getfield();
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

DBSignal addField(DBConn conn, String tableName, Field field, ErrMsg errMsg) {
	if (conn.isopen) {
		if (findTable(tableName)) {
			if (!findField(field.name)) {
				addField(tableName, field);
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

DBSignal removeField(DBConn conn, String tableName, Field field, ErrMsg errmsg){

}

DBSignal dropTable(DBConn conn, String tableName, ErrMsg errMsg){

}
