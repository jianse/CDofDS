/*
 * pager.c
 *
 *  Created on: 2018年6月15日
 *      Author: lee
 */

#include "page.h"



/***************************************************
 * 数据页面的结构
 * 		 _____________________
 * 		|  Page header 		  |
 * 		|_____________________|
 * 		|  Cell pointer array |
 * 		|_____________________|
 * 		|  Unallocated space  |
 * 		|_____________________|
 * 		|  Cell content       |
 * 		|_____________________|
 *
 * Page header:
 * offset	size	description
 * 0		1		Flags.  1:intkey 2:zerodata 4:leafdata 8:leaf
 * 1		2		第一个空闲块的地址
 * 3		2		该页面包含的单元数
 * 5		2		单元内容起始地址
 * 7		1		碎片块数   指的是空闲块大小小于3个字节的数目
 * 8		4		最右孩子页号,只有内部页有，叶子页没有
 *
 * Flags:
 * 	如果leaf位被设置，则该页面是一个叶子节点，没有孩子；
 * 	如果zerodata位被设置，则该页面只有关键字，而没有数据；
 * 	如果intkey位设置，则关键字是整型；
 * 	如果leafdata位设置，则tree只存储数据在叶子节点。
 * 	另外，对于内部页面(internal page)，header在第8个字节处包含指向最右边子节点的指针。
 *
 * Cell pointer array :
 * 	Ptr(n)
 *	由改页包含单元数个指针组成 ，每个指针的长度为2字节
 *
 * Cell (单元)
 * 	单元是变长的字节串。一个单元存储一个负载(payload)，它的结构如下：
 * 		size		description
 *	  4			 	左子页的页码。如果设置了"leaf"标志位, 则省略。
 *	  var(1-9)		数据字节数。如果设置了 "zerodata" 标志位, 则省略。
 *	  var(1-9)		key的字节数。如果设置了 "intkey" 标志位则是key本身, 。
 *	  *				payload : 实际的数据域。
 *	  4				溢出链的第一页。如果没有溢出, 则省略。
 *
 *****************************************************
 * 溢出页面：
 * 当一个单元比较大一个页面可能不足够时就将这个单元存储在额外的溢出页面上，
 * 对于一个溢出页面， 他的前4个字节存储着下一个溢出页面的页码
 *  	 ___________________________________________________________
 * 		|  next overflow Page no.(4bytes) | Record Data
 * 		|_________________________________|_________________________
 *
 ******************************************************
 *
 * 为了方便识别是否是一个可用的数据库文件，
 * 数据库文件的第一个页面应该提供一个文件头，
 * 写出一些有用的信息：
 *  	 _____________________
 * 		|  File header 		  |
 * 		|_____________________|
 * 		|  Page header 		  |
 * 		|_____________________|
 * 		|  Cell pointer array |
 * 		|_____________________|
 * 		|  Unallocated space  |
 * 		|_____________________|
 * 		|  Cell content       |
 * 		|_____________________|
 *
 * File header:
 * 数据库文件头的规定，该头写在第一个数据库文件页面上
 *
 * 	偏移		长度		描述
 *
 *  0		16		标记字串
 *	16		2		页面大小 （字节）	0x1000
 * 	18		1		写入版本（通常为1）
 *	19		1		读取版本（通常为1）
 *	20		1		每个页面的末尾保留字节数（通常为0）
 *	21		1		最大嵌入负载分数（0-255）
 *	22		1		最小嵌入负载分数（0-255）
 *	23		1		最小叶节点负载分数
 *	24		4		修改次数计数器（用于支持事务 现在阶段用不到）
 *	28		4		保留空间，以为后用
 *	32		4		第一个freelist的指针
 *	36		4		freelist的长度
 *	40		60		15 4-byte meta values //现阶段不用
 *
 *
 */

#define DEFAULT_FILE_HEAD_SIZE 100
#define DEFAULT_PAGE_SIZE 0x1000

struct Pager {
	String zFilename;
	Pgno dbSize; /* 页面的 */
};
