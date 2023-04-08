#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
int main()
{
	int N = 0;
	int K = 0;
	scanf("%d %d", &N, &K);
	int* arr = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}
	for (int j = 0; j < K; j++)
	{
		for (int i = 1; i < N - j; i++)
		{
			if (arr[i - 1] > arr[i])
			{
				int tmp = arr[i - 1];
				arr[i - 1] = arr[i];
				arr[i] = tmp;
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		printf("%d", arr[i]);
		if (N != i) printf(" ");
	}
	free(arr);
	return 0;
}