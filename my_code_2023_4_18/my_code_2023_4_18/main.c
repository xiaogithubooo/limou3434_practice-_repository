#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int a = 10;
	printf("%zd ", sizeof(a));
	printf("%zd ", sizeof(int));
	printf("%zd ", sizeof a);
	//printf("%zd", sizeof int);
	return 0;
}