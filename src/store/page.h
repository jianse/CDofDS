/*
 * pager.h
 *
 *  Created on: 2018年6月15日
 *      Author: lee
 */
/**
 * 这个头文件定义了数据库的页面缓存子系统。
 * 缓存子系统一次读取或者写入一个文件的一个页面
 */
#ifndef STORE_PAGE_H_
#define STORE_PAGE_H_

#include "dbInt.h"


/**
 * 这个类型用来描述页面的序号，
 * 文件中的第一页的序号是1
 * 0表示是 “不是一个页面”
 */
typedef u32 Pgno;


/*
 * 每个打开的页面被分成多个Pager来进行组织。
 */
typedef struct Pager Pager;

/*
** Handle type for pages.
*/
typedef struct PgHdr DbPage;


#endif /* STORE_PAGE_H_ */
