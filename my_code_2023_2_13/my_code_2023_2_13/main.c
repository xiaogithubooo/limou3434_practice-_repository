#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//1、牛客题目
int main()
{
    char arr[1000] = { 0 };
    int number = 0;
    scanf("%s", arr);
    scanf("%d", &number);
    for (int i = 0; i < number; i++)
    {
        printf("%c", arr[i]);
    }
    return 0;
}
//2、牛科题目
#include<stdio.h>
int main()
{
	int a[12] = { 1,2,3,4,5,6,7,8,9,10,11,12 }, * p[4], i;
	for (i = 0; i < 4; i++)
		p[i] = &a[i * 3];
	printf("%d\n",p[3][2]);
	return 0;
}