#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//1、测试指针存字符串
int main()
{
	char* a = "hello word";
	*(a + 1) = 'E';
	printf("%s\n", a);
	printf("%s\n", "hello word");
	return 0;
}
//2、测试char*的大小
int main()
{
	printf("%zd", sizeof(char*));
	return 0;
}
//3、测试录屏程序是否可见
int main()
{
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d\n", i);
	}
	return 0;
}
