#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	printf("你好！\n");
	return 0;
}
//牛客网-线段图案
int main()
{
    int a = 0;
    while (scanf("%d", &a) == 1)
    {
        for (int i = 0; i < a; i++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}