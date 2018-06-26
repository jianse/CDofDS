/**
*
* 测试用log方法
* TODO: 在正式发布项目前关闭该选项
*/
#ifndef __TESTSWITCH_H__

#define __TESTSWITCH_H__

#define Test 1
#if Test
#define log(str) printf("[LOG]file:%s\t:line%d\tmessage:%s\n",__FILE__,__LINE__,str)
#else
#define log(str)
#endif

#endif
