#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//1、验证字符串代码
int main()
{
	char c[5] = { 'a', 'b', '\0', 'c', '\0' };
	char a[] = "x+y=5.";
	printf("%s\n", c);
	printf("%s", a);
	return 0;
}
//2、测试程序是否出错
#include<stdio.h>
int main()
{
	int a[12] = { 1,2,3,4,5,6,7,8,9,10,11,12 }, * p[4], i;
	for (i = 0; i < 4; i++)
		p[i] = &a[i * 3];
	printf("%d\n",p[3][2]);
	return 0;
}
//3、验证表达式结果
int main()
{
	int x;
	int y = ((x = 4 * 5, x * 5),x + 5);
	printf("%d", y);
	return 0;
}
//4、测试打印结果
int main()
{
	char a = 'a', b;
	printf("%c,", ++a);
	printf("%c\n", b = a++);
	return 0;
}