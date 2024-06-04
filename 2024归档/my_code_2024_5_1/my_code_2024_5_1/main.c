#define _CRT_SECURE_NO_WARNINGS

//双循环
#include <stdio.h>
int main()
{
	int ret = 1;
	int sum = 0;

	//输入最大的 n
	int maxN = 0;
	scanf("%d", &maxN);
	for (int i = 1; i <= maxN; i++) //计算从 1! 到 n! 中每一项 i!(其中 i∈[1, n])
	{
		ret = 1; //每次加入循环先把 ret 都置为 0
		for (int j = 1; j <= i; j++) //计算 i! 的值
		{
			ret *= j;
		}
		//i! 的最终值最后都存储在 ret 中

		sum += ret; //sum
	}

	printf("%d\n", sum);
	return 0;
}