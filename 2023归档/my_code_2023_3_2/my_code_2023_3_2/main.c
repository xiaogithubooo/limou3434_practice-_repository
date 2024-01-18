#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <windows.h>
//日志记录：
//1、检验vs代码文本文件生成可执行程序的过程
//2、PTA题目，判断奇偶性：https://pintia.cn/problem-sets/14/exam/problems/744
//3、PTA题目，阶乘函数升级版：https://pintia.cn/problem-sets/14/exam/problems/742

int main()
{
	printf("hello word!\n");
	system("pause");
	return 0;
}//vs中使用清理解决方案可以把新生成的.exe等文件删除掉
//2、PTA题目，判断奇偶性：https://pintia.cn/problem-sets/14/exam/problems/744
#include <stdio.h>
int even(int n);
int main()
{
	int n;

	scanf("%d", &n);
	if (even(n))
		printf("%d is even.\n", n);
	else
		printf("%d is odd.\n", n);

	return 0;
}
int even(int n)
{
	if (n & 1)
	{
		return 0;
	}
	return 1;
}
//3、PTA题目，阶乘函数升级版：https://pintia.cn/problem-sets/14/exam/problems/742
#include <stdio.h>
void Print_Factorial(const int N);
int main()
{
    int N;

    scanf("%d", &N);
    Print_Factorial(N);
    return 0;
}
unsigned long long function(int N)
{
    if (N == 0 || N == 1)
    {
        return 1;
    }
    else
    {
        return function(N - 1) * N;
    }
}
void Print_Factorial(const int N)
{
    if (0 <= N && N <= 1000)
    {
        printf("%lld", function(N));
    }
    else
    {
        printf("Invalid input");
    }
}