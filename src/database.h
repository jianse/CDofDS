/*
 * database.h
 *
 *  Created on: 2018年6月14日
 *      Author: lee
 */

/**
 **本地数据库模型接口
 **/

#include "dbInt.h"
#include "data.h"
#include "rowSet.h"
#include "resultset.h"
#include "field.h"


/**
 *
 */
typedef char* Data;

/**
 **  为数据库连接定义别名，想要使用数据库必须先拿到数据库的连接，
 **  对数据库的所有操作都需要传入一个数据库连接参数
 **/
typedef  struct conn DBConn;
/**
 **对数据库的操作都会返回一个DBSignal枚举，
 **是对操作结果的标识
 **/
typedef enum dbSignal {
	OPT_FAILED = 0, OPT_SUCCEED = 1,
} DBSignal;
/**
 **表示数据库中的一个列
 **/
typedef struct field Field;
/**
 **错误信息，在数据库发生错误时给出信息
 **/
typedef char* ErrMsg;
/**
 ** 要存储的数据
 **/
typedef struct data Data;
/**
 **数据记录的Rid 由系统生成
 **/
typedef int Rid;
/**
 **查询项目的结果集
 **/
//typedef struct resultset ResultSet;
/**
 *
 */
typedef char * String;

/**
 *
 */
typedef String Condition;

/**
 **定义对数据库表 及表结构的操作
 **/

/**
 **得到数据库连接
 **@param path 本地数据库绝对路径
 **@return 数据库连接
 **/
DBConn getConnection(String path);

DBSignal open(DBConn conn,ErrMsg errMsg);

/**
 **创建一个数据表
 **@param conn 通过getConnection获得的数据库连接
 **@param tableName 要创建的数据库表的名称
 **@param fields 数据表中的域
 **@param errMsg 错误信息
 **@return DBSignal 操作结果的标识
 **/
DBSignal createTable(DBConn conn, String tableName, Field fields, ErrMsg errMsg);

/**
 **通过列名得到数据库表的一列的属性
 **@param conn 数据库连接
 **@param tableName 数据表名
 **@param fieldName 列名
 **@param errMsg 错误信息
 **@return 列的一个实例
 **/
DBSignal getFieldByName(DBConn conn, String tableName, String fieldName,Field field,
		ErrMsg errMsg);

/**
 **为数据表添加一个字段
 **@param conn 数据库连接
 **@param tableName 数据表名
 **@param field 要添加的字段
 **@param errMsg  错误信息
 **@return 操作信号
 **/
DBSignal addField(DBConn conn, String tableName, Field field, ErrMsg errMsg);

/**
 **移除数据表的一个字段
 **@param conn 数据库连接
 **@param tableName 数据表名
 **@param field 目标字段
 **@param errMsg 错误信息
 **@return 信号
 **/
DBSignal removeField(DBConn conn, String tableName, Field field, ErrMsg errmsg);

/**
 **删除表操作
 **@param conn 数据库连接
 **@param tableName 目标数据表
 **@param 错误信息
 **@return 信号
 **/
DBSignal dropTable(DBConn conn, String tableName, ErrMsg errMsg);

/**
 **定义对数据的操作
 **/

/**
 **插入记录
 **@param conn 数据库连接
 **@param tableName 数据表名称
 **@param data 实现了data接口的数据
 **@param errMsg 错误信息
 **@return 操作信号
 **/
DBSignal insertRecord(DBConn conn, String tabelName, Data data, ErrMsg errMsg);

/**
 **删除记录
 **@param conn 数据库连接
 **@param tableName 数据表名
 **@param conditions 要删除的数据所满足的条件
 **@param errMsg 错误信息
 **@return 操作信号
 **/
DBSignal RemoveRecord(DBConn conn, String tableName, Condition conditions,
		ErrMsg errMsg);

/**
 **更新记录，每次只能更新一张表的一个字段，如果要更新多个字段，需要多次调用
 **@param conn 数据库连接
 **@param tableName 数据表名
 **@param field 字段
 **@param value 字段对应的值
 **@param errMsg 错误信息
 **@return 信号
 **/
DBSignal UpdateRecord(DBConn conn, String tableName, Field field, Data value,
		ErrMsg errMsg);

/**
 **查询记录，
 **@param conn 数据库连接
 **@param tableName 数据表名
 **@param conditions 条件集合
 **@param resultSet 存放查询结果的结果集
 **@param errMsg 错误信息
 **@return 信号
 **/
DBSignal SelectRecord(DBConn conn, String tableName, Condition conditions,
		ResultSet resultSet, ErrMsg errMsg);

