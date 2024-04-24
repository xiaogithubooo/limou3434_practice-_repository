#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
int main()
{
	int number = 0;
	char str[10] = { 0 };
	//scanf("%d %s", &number, str); //大多数人的写法
	scanf("%d %s", &number, &str); //貌似是对的, 也可以正常输入
	printf("%d %s", number, str);
	return 0;
}