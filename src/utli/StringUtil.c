/*
 * StringUtil.c
 *
 *  Created on: 2018年6月22日
 *      Author: lee
 */

/*
 * 测试开关
 */
#include "../testSwitch.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

typedef char * String;

String m_strcpy(const String s2) {
#if Test
	printf("m_strcpy:%s\n", s2);
#endif
	String str;
	str = malloc(sizeof(char) * (strlen(s2) + 1));
	strcpy(str, s2);
	return str;
}

int m_indexOf(String s1, String s2) {
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	for (int i = 1; i < len1 - len2; i++) {
		if (*(s1 + i) == *s2) {
			int flag = 1;
			for (int j = 0; j < len2; j++) {
				if (*(s1 + i + j) == *(s2 + j)) {
					continue;
				} else {
					flag = 0;
					break;
				}
			}
			if (flag) {
				return i;
			}
		}
	}
	return -1;
}

int m_lastIndexOf(String s1, String s2) {

	int index = 0;
	int i = 0;
	while (i != -1) {
		i = m_indexOf(s1 + index, s2);
		if (i == -1) {
			return index;
		} else {
			index += i;
		}
	}
	return -1;
}

String m_subString(String s1, int start, int len) {
	String str;
	str = malloc(sizeof(char) * (len + 1));
	for (int i = 0; i <= len; i++) {
		if (i == len) {
			*(str + i) = '\0';
		} else {
			*(str + i) = *(s1 + start + i);
		}
	}
	return str;
}
char m_charAt(String s1, int index) {
	if (strlen(s1) <= index) {
		return -1;
	} else {
		return *(s1 + index);
	}
}

int m_contans(String str, String s2) {
	if (m_indexOf(str, s2) != -1) {
		return 1;
	} else {
		return 0;
	}
}

String m_conbine(String s1, String s2) {
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	String str = malloc(sizeof(char) * (len1 + len2 + 1));

	for (int i = 0; i < len1; i++) {
		*(str + i) = *(s1 + i);
	}
	for (int i = 0; i < len2; i++) {
		*(str + len1 + i) = *(s2 + i);
	}
	*(str + len1 + len2) = '\0';
	return str;
}
