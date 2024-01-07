#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

bool IsEqual(const char* s, const char* subS)
{
	//避免一开始就传过来空的模式串
	assert(*subS != '\0');

	//一一比较每一个字符
	while ((*subS != '\0') && (*s == *subS))
	{
		s++;
		subS++;

		//处理模式字符长度大于主串子串的情况
		if ((*subS != '\0') && (*s == '\0'))
			return false;
	}

	//相等说明匹配完
	return *subS == '\0';
}

int BF(const char* mainS, const char* subS)
{
	int mainSSize = strlen(mainS);
	int subSSize = strlen(subS);
	int size = mainSSize - subSSize + 1;
	for (int i = 0; i < size; i++)
	{
		if (IsEqual(mainS + i, subS))
		{
			return i;
		}
	}
	return -1;
}

int main()
{
	const char* mainS= "aaabcd"; //主串
	const char* subS = "abcd"; //模式串
	int index = BF(mainS, subS); //暴力匹配
	printf("%d\n", index); //得出主串中对于的索引值 
	return 0;
}