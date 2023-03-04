#define _CRT_SECURE_NO_WARNINGS 1
//日志
//1、测试注释是否在编译前变成一个空格
//2、const的测试
//3、测试define所标记的字符串的解释类型
//4、切换二进制倒数n个位数

#include<stdio.h>
//1、测试注释是否在编译前变成一个空格
int main()
{
	int/*测试注释是否变成空格*/a = 10;
	printf("%d\n", a);
	return 0;
}
//2、const的测试
int main()
{
	const int LIM = 50;
	const int LIM2 = 2 * LIM;
	printf("%d", LIM2);
	return 0;
}
//3、测试define所标记的字符串的解释类型
#define NUM_1 2*3
#define NUM_2 2 * 3
int main()
{
	printf("%d\n", NUM_1);
	printf("%d\n", NUM_2);
	//可以看出都解释成了字符型字符串，而不是记号型字符串
	return 0;
}
//4、切换二进制倒数n个位数
void invert_end(int number, int n)
{
	int mask = 0;
	int bitval = 1;

	while (n-- > 0)
	{
		mask |= bitval;
		bitval <<= 1;
	}
	printf("%d", number ^ mask);
}
int main()
{
	int number = 0;
	int n = 0;
	scanf("数字:%d  后n位数:%d", &number, &n);
	invert_end(number, n);
	return 0;
}