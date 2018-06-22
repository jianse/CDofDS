/*
 * StringUtil.h
 *
 *  Created on: 2018Äê6ÔÂ22ÈÕ
 *      Author: lee
 */

#ifndef STRINGUTIL_H_
#define STRINGUTIL_H_

typedef char * String;
String m_strcpy(const String s2);
int m_indexOf(String s1,String s2);
int m_lastIndexOf(String s1,String s2);
String m_subString(String s1,int start,int len);

#endif /* STRINGUTIL_H_ */
