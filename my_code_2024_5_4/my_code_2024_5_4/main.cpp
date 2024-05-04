#include <stdio.h>

int main()
{
	int n = 0;
	int ret = 1;
	int sum = 0;

	int manN = 0;
	scanf("%d", &manN);

	for (int j = 1; j <= manN; j++)
	{
		ret *= j;
		sum += ret; //这里循环第一次就可以计算到 1!  循环第二次可以计算 1!+2!  ...  一直循环第 manN 次可以计算 1!+2!+...+n!
	}

	printf("%d\n", sum);
	return 0;
}