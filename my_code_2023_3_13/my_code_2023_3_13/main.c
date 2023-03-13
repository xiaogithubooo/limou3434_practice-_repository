#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
//日志：
//实现strstr函数
char* my_strstr(const char* str1,const char* str2)
{
	assert(str1, str2);
	char* s1 = str1;
	char* s2 = str2;
	while (*str1)
	{
		s1 = str1;
		s2 = str2;
		while (*s1 != *s2)//找到第一处相等的地方
		{
			s1++;
			if (*s1 == '\0')//一直都没找到相等的地方，就返回空指针
			{
				return NULL;
			}
		}
		char* t = s1;//记下这个第一处相等的地方
		while (*s1 == *s2)
		{
			s1++;
			s2++;
			if (*s2 == '\0')//直到s2结束都相等，说明找到了
			{
				return t;
			}
		}
		str1++;
	}
	return NULL;
}
int main()
{
	char arr_1[] = "bbbbbbbbbedcbbbbbdebbbcdbbbcdeffffff";
	char arr_2[] = "bcde";
	printf("%s\n",my_strstr(arr_1, arr_2));
	return 0;
}