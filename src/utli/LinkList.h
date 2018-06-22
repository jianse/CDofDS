/*
 * LinkList.h
 *
 *  Created on: 2018年6月22日
 *      Author: lee
 */

#ifndef UTLI_LINKLIST_H_
#define UTLI_LINKLIST_H_

#include <malloc.h>

#ifndef _T
#define _T int
#endif

typedef struct linkList LinkList;
typedef struct Node NODE;

struct linkList {
	NODE * head;
	NODE * teal;
//int length;
};

struct Node {
	_T * data;
	struct Node * next;
};

#define getData getData##_T

/*
 * @param len 要进行初始化的链表长度
 * @return 一个指向新建链表的指针
 */
LinkList * init(int len);

/*
 * 初始化一个链表节点，该节点的域都不会初始化，使用时应该注意
 * @return 一个指向新建节点的指针。
 */
NODE * initNode();

/*
 * 向链表的尾部添加数据，数据会被包装成一个NODE对象然后调用
 * @see NODE * addBackNode(LinkList * list,NODE * node)
 * 在添加对象数据到链表的data域里面时并不会对数据类型进行编译期间的验证，
 * 这很可能在实际应用中出现问题.
 * @param list 要添加到末尾的链表对象，对象必须被初始化。
 * @param data 要添加的对象。
 * @return 指向刚添加节点的指针
 */
NODE * addBackData(LinkList * list, _T * data);

/*
 * 向链表的尾部添加一个节点
 * @param list 要添加到末尾的链表对象，对象必须被初始化。
 * @param node 要添加的节点
 * @return 指向刚添加节点的指针
 */
NODE * addBackNode(LinkList * list, NODE * node);

/*
 * 从节点中获取值，该值会被转型成宏定义中 "_T" 的指针（类似泛型）
 * @param node 目标节点
 * @return 目标数据类型的指针
 */
_T * getData(NODE * node);

/*
 * 在指定节点之后插入数据，该方法会新创建并插入一个节点到目标节点之后，
 * 并把数据存储在新建的节点内。
 * @param node 目标节点
 * @param data 数据。
 * @return 指向刚插入节点的指针
 */
NODE * insertData(NODE * node, _T * data);

/*
 * 在指定节点后插入一个节点
 * @param preNode 目标节点。
 * @param node 要插入的节点。
 * @return 返回刚指向插入节点的指针
 */
NODE * insertNode(NODE * preNode, NODE * node);

/*
 * 移除链表中最后一个元素，调用该方法会在链表中寻找最后一个节点的前一个节点，
 * 因为链表的单链接结构所以操作比较耗时。
 * 被删除的节点的内存空间会在函数内释放，但是其数据节并不会释放，如需进行数据操作，
 * 请使用getData取出数据后再进行删除操作。
 * @param list 链表对象。
 * @return 新的尾部节点指针
 */
NODE * removeBack(LinkList * list);

/*
 * 移除链表的头结点，头结点没有前驱节点，所以直接释放头结点内存空间，下一节点变为头结点即可
 * @param list 链表对象；
 * @return 指向新的头结点的指针
 */
NODE * removeHead(LinkList * list);

/*
 * 删除当前节点
 * @param list 链表对象
 * @param node 要删除的节点
 * @return 被删除节点的前驱节点
 * TODO : 还需要确定该节点是不是头结点
 */
NODE * removeNode(LinkList * list, NODE * node);

/*
 * 删除下一节点
 * 该方法假定当前节点有一个直接后继结点，使用时应该注意，
 * 如果当前节点没有后继并不会直接给出提示，或抛出错误
 * TODO : 添加一些判断，判断是否有后继
 * @param node 要删除节点的前驱
 * @return = node
 */
NODE * removeNext(NODE * node);

/*
 * 查找节点的前驱，如果没有找到 或者该节点不在链表内则返回0
 * @param list 链表对象
 * @param node 查找的节点
 * @return 该节点的前驱
 */
NODE * findPreNode(LinkList *list, NODE * node);

#undef _T

#endif /* UTLI_LINKLIST_H_ */
