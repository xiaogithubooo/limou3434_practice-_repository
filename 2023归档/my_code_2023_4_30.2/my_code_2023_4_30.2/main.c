#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#define INT_1 int
typedef int INT_2;
int main()
{
	unsigned INT_1 a = 10;//合法
	//unsigned INT_2 b = 10;//不合法，typedef重新定义的变量类型无法这么做

	const INT_2 c = 10;//合法
	printf("%d %d", a, c);
	return 0;
}