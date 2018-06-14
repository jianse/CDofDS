/*
 * contact.c
 *
 *  Created on: 2018年6月14日
 *      Author: lee
 */

/**
 *实现data接口
 */
#include "dominInt.h"
#include "data.h"


/**
 * 联系人数据实体
 *
 *
 * TODO:  需求：如果一个人有多个电话  或者  两人重名  如何解决？
 */
typedef struct conatact {
	int id;					/** 联系人的id **/
	String name;			/**	联系人的姓名 **/
	String phoneNumber;		/** 联系人的电话 **/
	String memo;  			/** 备注 **/
}Conatact;

#ifdef T
#undef T
#define T Conatact
#else
#define T Conatact
#endif

#ifdef getData
#undef getData
#define getData getDataContact
#else
#define getData getDataContact
#endif
char * getData(T adt_data){
	//TODO:	实现将联系人数据序列化
	return 0;
}
