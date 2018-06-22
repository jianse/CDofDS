/*
 * LinkList.c
 *
 *  Created on: 2018年6月22日
 *      Author: lee
 */

#include "LinkList.h"

#ifndef _T
#define _T int
#endif

LinkList * init(int len);
NODE * initNode();
NODE * addBackData(LinkList * list,_T * data);
NODE * addBackNode(LinkList * list,NODE * node) ;
_T * getData(NODE * node);
NODE * insertData(NODE * node, _T * data);
NODE * insertNode(NODE * preNode, NODE * node);
NODE * removeBack(LinkList * list);
NODE * removeHead(LinkList * list);
NODE * removeNode(LinkList * list,NODE * node);
NODE * removeNext(NODE * node);
NODE * findPreNode(LinkList  *list, NODE * node) ;


LinkList * init(int len){
	LinkList * list = (LinkList *)malloc(sizeof(list));
	//list->length = len;
	NODE * pnode =initNode();
	list ->head = pnode;
	list ->teal = pnode;
	for(int i= 1;i<len ;i++){
		NODE * node = initNode();
		addBackNode(list,node);
	}
	return list;
}
NODE * initNode(){
	return (NODE *)malloc(sizeof(NODE));
}

NODE * addBackData(LinkList * list,_T * data){
	NODE * node = initNode();
	node->data =data;
	return addBackNode(list,node);
}

NODE * addBackNode(LinkList * list,NODE * node) {
	NODE * preNode = list->teal;
	list->teal = node;
	preNode->next = node;
	return node;
}

_T * getData(NODE * node){
	return (_T *)node->data;
}

NODE * insertData(NODE * PreNode, _T * data){
	NODE * node = initNode();
	node->data =data;
	return insertNode(PreNode,node);
}

NODE * insertNode(NODE * preNode, NODE * node){
	node->next = preNode->next;
	preNode ->next =node;
	return node;
}

NODE * removeBack(LinkList * list){
	NODE * preNode = findPreNode(list,list->teal);
	list->teal = preNode;
	return removeNext(preNode);
}

NODE * removeHead(LinkList * list){
	NODE  * node = list->head;
	list->head = list->head->next;
	free(node);
	NODE ** ppnode = &node;
	*ppnode = 0;
	return list->head;
}

NODE * removeNode(LinkList * list,NODE * node){
	NODE * preNode = findPreNode(list,node);
	return removeNext(preNode);
}

NODE * removeNext(NODE * node){
	NODE * next = node ->next;
	node->next =0;
	free(next);
	NODE ** ppnext = &next;
	*ppnext =0;
	return node;
}

NODE * findPreNode(LinkList  *list, NODE * node) {
	NODE * currentNode = list->head;
	while(currentNode!= list->teal){
		if(currentNode->next == node){
			return currentNode;
		}else{
			currentNode = currentNode->next;
		}
	}
	return (NODE *)0;
}

