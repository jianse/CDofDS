/*
 * database.c
 *
 *  Created on: 2018年6月14日
 *      Author: lee
 */

/**
 *测试开关
 */
#include "../testSwitch.h"

#include <io.h>

#include "database.h"
#include "../utli/StringUtil.h"


int CONN_ID = 1;

//FILE *fp_stru;
//FILE *fp_data;

typedef struct ifield Field;


typedef struct conn DBconn;

DBSignal getConnection(String path, DBConn ** conn, ErrMsg * errMsg);
Field * getField(String fieldName);
bool findField(DBConn * conn,String tablename,String fieldName);
bool findTable(DBConn * conn,String tableName);
void inner_createTable(DBConn * conn, String tableName,int fieldCount, Field * fields);
void inner_addField(String tableName, Field fieldName);
void inner_removeField(String tableName, String fieldName);
void inner_removeTable(String tableName);
void writeDefaultMatadata();
void mkdirs(String path);
DBSignal openDB(DBConn * conn, ErrMsg * errMsg);
DBSignal loadTableStructure(DBConn *conn,String tName,TableInfo** fields,ErrMsg * errMsg);
DBSignal loadTable(DBConn * conn,String tName,ErrMsg *errMsg);

DBSignal loadTable(DBConn * conn,String tName,ErrMsg *errMsg){
	return false;
}

DBSignal loadTableStructure(DBConn *conn, String tName, TableInfo** fields, ErrMsg * errMsg) {
	String fieldsPath = m_conbine(m_conbine(m_conbine(conn->path, "/"), tName),
			"/.stru");
	log(fieldsPath);
	FILE * fp_stru = fopen(fieldsPath, "a+");
	if (fp_stru == NULL) {
		return false;
	}
	long flen = 0;
	int fieldsCount = 0;
	fseek(fp_stru, 0L, SEEK_END);
	flen = ftell(fp_stru);

	fieldsCount = flen / 42;
	Field * tfields = malloc(sizeof(Field) * fieldsCount);
	for (int i = 0; i < fieldsCount; i++) {
		fseek(fp_stru, i * 42, SEEK_SET);
		(tfields + i)->name = malloc(sizeof(String) * 33);
		fscanf(fp_stru, "%32s", (tfields + i)->name);
		int t;
		fscanf(fp_stru, "%4d", &t);
		((tfields + i)->type) = (Type) t;
		fscanf(fp_stru, "%4d", &((tfields + i)->length));
	}
	TableInfo *f = malloc(sizeof(TableInfo));
	f->fieldCount = fieldsCount;
	f->fields = tfields;
	*fields = f;
	return true;
}

DBSignal getConnection(String path, DBConn **conn, ErrMsg * errMsg) {
	if (strlen(path) == 0) {

		*errMsg = "无效路径";
		return OPT_FAILED;

	} else {
		//TODO: 对给定的path进行必要的验证 ，保证是一个有效的路径
	}
	DBConn *iconn = (DBConn *) malloc(sizeof(DBConn));
	iconn->connid = CONN_ID;
#if Test
	printf("getConnection:%s\n",path);
#endif
	iconn->path = m_strcpy(path);
#if Test
	printf("getConnection:%s\n",iconn->path);
#endif
	iconn->isopen = true;

	String msg="";
	if (!openDB(iconn, &msg)) {
		*errMsg = msg;
		return OPT_FAILED;
	}else{
		*conn =iconn;
	}
	return OPT_SUCCEED;
}

/*DBSignal getConnection(String path) {

 }*/

bool findField(DBConn * conn,String tablename,String fieldName) {

	//TODO: 实现寻找域的方法
	String fieldsPath = m_conbine(m_conbine(m_conbine(conn->path,"/"),tablename),"/.stru");
	FILE * fp_stru = fopen(fieldsPath,"a+");
	if(fp_stru==NULL){
		return false;
	}
	long flen = 0;
	int fieldsCount =0;
	fseek(fp_stru,0L,SEEK_END);
	flen = ftell(fp_stru);
	fieldsCount = flen/42;
	Field * fields = malloc(sizeof(Field)*fieldsCount);
	for(int i =0;i<fieldsCount;i++){
		fseek(fp_stru,i*42,SEEK_SET);
		(fields+i)->name = malloc(sizeof(String)*33);
		 fscanf(fp_stru,"%32s",(fields+i)->name);
		 int t;
		 fscanf(fp_stru,"%4d",&t);
		 ((fields+i)->type)=(Type)t;
		 fscanf(fp_stru,"%4d",&((fields+i)->length));
	}

	return false;
}

DBSignal openDB(DBConn * conn, ErrMsg * errMsg) {
	if (access(conn->path, 0)==0) {
#if Test
		printf("openDB:%s\n",conn->path);
#endif
		//fp_stru = fopen(m_conbine(conn->path,"/.stru"), "a+");
		//fp_data = fopen(m_conbine(conn->path,"/.data"), "a+");
		*errMsg = "";
		return OPT_SUCCEED;
	} else {
		mkdirs(conn->path);
		//fp_stru = fopen(m_conbine(conn->path,"/.stru"), "a+");
		//fp_data = fopen(m_conbine(conn->path,"/.data"), "a+");
		*errMsg = "";
		//writeDefaultMatadata();
		return OPT_SUCCEED;
	}
	*errMsg = "";
	return OPT_SUCCEED;
}

void mkdirs(String path) {
	/*int i ,len;
	 int p1 = 0;
	 String tpath;
	 len = strlen(path);
	 while(m_contans(path+p1,"/")){
	 p1+=m_indexOf(path+p1,"/");

	 }*/
	int i, len;
	char str[512];
	strncpy(str, path, 512);
	len = strlen(str);
	for (i = 0; i < len; i++) {
		if (str[i] == '/') {
			str[i] = '\0';
			if (access(str, 0) != 0) {
				mkdir(str);
			}
			str[i] = '/';
		}
	}
	if (len > 0 && access(str, 0) != 0) {
		mkdir(str);
	}
	return;
}

void writeDefaultMatadata() {
	//TODO : 数据库原始信息的写入 COMPLETED
}

DBSignal createTable(DBConn *conn, String tableName,int fieldsCount, Field * fields, ErrMsg * errMsg) {
	if (conn->isopen) {
		if (!findTable(conn,tableName)) {
#if Test
			printf("createTable:Table not find!");
#endif
			if (0) {
				//TODO:对fields内容进行一些健壮性的判断
			}
			inner_createTable(conn, tableName,fieldsCount, fields);
			return OPT_SUCCEED;
		} else {
			*errMsg = "数据表已存在";
			return OPT_FAILED;
		}
	}
	*errMsg = "数据库连接尚未打开";
	return OPT_FAILED;
}

void inner_createTable(DBConn * conn, String tableName,int fieldsCount, Field *fields) {
	//TODO: 创建表的工作 COMPLETED
	String path = m_conbine(m_conbine(conn->path,"/"),tableName);
	printf("%s",path);
	mkdirs(path);
	FILE * fp_stru = fopen(m_conbine(path,"/.stru"),"a+");
	FILE * fp_data = fopen(m_conbine(path,"/.data"),"a+");
	fclose(fp_data);
	for(int i =0 ;i<fieldsCount;i++){
		fprintf(fp_stru,"%32s",(fields+i)->name);
		fprintf(fp_stru,"%4d",(fields+i)->type);
		fprintf(fp_stru,"%4d",(fields+i)->length);
		fprintf(fp_stru,"\n");
	}
	fclose(fp_stru);

}

Field * getField(String fieldName) {
	//TODO : 根据字段名得到字段相关信息
	Field *f = malloc(sizeof(Field));
	return f;
}

DBSignal getFieldByName(DBConn * conn, String tableName, String fieldName,
		Field * field, ErrMsg * errMsg) {
	if (conn->isopen) {
		if (findTable(conn ,tableName)) {
			if (findField(conn,tableName,fieldName)) {
				field = getField(fieldName);
				return OPT_SUCCEED;
			} else {
				*errMsg ="";
				return OPT_SUCCEED;
			}
		} else {
			*errMsg = "未找到数据表";
			return OPT_FAILED;
		}
	}
	*errMsg = "数据库连接尚未打开";
	return OPT_FAILED;
}

bool findTable(DBConn * conn, String tableName) {
	String tablePath =m_conbine(m_conbine(conn->path,"/"),tableName);
	if(access(tablePath,0)==0){
		return true;
	}
	return false;
}

DBSignal addField(DBConn * conn, String tableName, Field field, ErrMsg * errMsg) {
	if (conn->isopen) {
		if (findTable(conn,tableName)) {
			if (!findField(conn,tableName,field.name)) {
				inner_addField(tableName, field);
				return OPT_SUCCEED;
			} else {
				*errMsg = "";
				return OPT_FAILED;
			}
		} else {
			*errMsg = "数据表不存在";
			return OPT_FAILED;
		}
	}
	*errMsg = "数据库连接尚未打开";
	return OPT_FAILED;
}

void inner_addField(String tableName, Field field) {
	//TODO:实现添加字段的方法
}
DBSignal removeField(DBConn * conn, String tableName, Field field, ErrMsg * errMsg) {
	if (conn->isopen) {
		if (findTable(conn,tableName)) {
			if (findField(conn,tableName,field.name)) {
				inner_removeField(tableName, field.name);
				return OPT_SUCCEED;
			} else {
				*errMsg = "";
				return OPT_FAILED;
			}
		}
		*errMsg = "未找到数据表";
		return OPT_FAILED;
	}
	*errMsg = "数据库连接尚未打开";
	return OPT_FAILED;
}

void inner_removeField(String tableName, String fieldName) {
	//TODO:实现删除字段的方法
}

DBSignal dropTable(DBConn * conn, String tableName, ErrMsg * errMsg) {
	if (conn->isopen) {
		if (findTable(conn,tableName)) {
			inner_removeTable(tableName);
			return OPT_SUCCEED;
		} else {
			*errMsg = "未找到数据表";
			return OPT_FAILED;
		}
	}
	*errMsg = "数据库连接尚未打开";
	return OPT_FAILED;
}

void inner_removeTable(String tableName) {
	//TODO:实现删除表
}

DBSignal insertRecord(DBConn * conn, String tabelName, Data data, ErrMsg * errMsg) {
	return OPT_FAILED;
}
