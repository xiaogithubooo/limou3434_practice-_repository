#define _CRT_SECURE_NO_WARNINGS 1
#include "stdio.h"
int main()
{
	int A = 0, N = 0;
	scanf("%d %d", &A, &N);
	int add = 0;
	while (N)
	{
		add += N * A;
		A *= 10;
		N--;
	}
	printf("%d", add);
	return 0;
}