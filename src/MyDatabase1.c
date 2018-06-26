/*
 ============================================================================
 Name        : MyDatabase1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
/**
 * 测试开关
 */
#include "testSwitch.h"

#include <stdio.h>
#include <stdlib.h>

#include "store/database.h"


/**
 * 测试方法区  该区的方法不对程序产生影响 只做测试用途
 */
#if Test
int TestStringReturn(ErrMsg *errMsg){
	*errMsg = "nihao";
	return 0;
}
#endif



typedef struct conatact {
	int id; /** 联系人的id **/
	String name; /**	联系人的姓名 **/
	String phoneNumber; /** 联系人的电话 **/
	String memo; /** 备注 **/
} Conatact;

#ifdef _T
#undef _T
#define _T Conatact
#else
#define _T Conatact
#include "utli/LinkList.h"
#endif

int main(void) {

	/*NODE *node = (NODE*)malloc(sizeof(NODE));
	Conatact *c = (Conatact *)malloc(sizeof(Conatact));
	c->id = 11;
	node->data = c;


	node->next = malloc(sizeof(NODE));*/
	/*LinkList *list =init(1);
	list->head->data = (Conatact * )malloc(sizeof(Conatact));
	Conatact *c = malloc(sizeof(Conatact));
	c->name = "123";
	insertData(list->head,c);
	DBConn * conn;
	String msg;
	if(getConnection("联系人",conn,msg)){

	}
	String errMsg;
	insertRecord(conn,"contant",getData(c),errMsg);*/

	log("main in ");
	DBConn *conn = NULL;
	String msg  ="";
	if(!getConnection("test.db",&conn,&msg)){
		printf("%s",msg);
	}
	Field * fields = malloc(sizeof(Field)*3);
	fields->name = "id";
	fields->type = Type_Int;
	fields->length = 4;

	(fields+1) ->name = "name";
	(fields+1) ->type = Type_String;
	(fields+1) ->length = 128;

	(fields+2) ->name = "tel";
	(fields+2) ->type = Type_String;
	(fields+2) ->length = 128;
	if(!createTable(conn,"contator",3,fields,&msg)){
		printf("main:line:%d %s\n",__LINE__,msg);
	}
	if(!createTable(conn,"contator",3,fields,&msg)){
			printf("main:line:%d %s\n",__LINE__,msg);
	}

	/*String str ;
	TestStringReturn(&str);
	printf("-%s-",str);*/

	//system("pause");
	return EXIT_SUCCESS;
}
