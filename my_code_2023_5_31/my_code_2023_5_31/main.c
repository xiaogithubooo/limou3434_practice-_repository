#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
//int main(int argc, char* argv[])
//{
//    int i = 0;
//    for (i = 1; i < argc; i++)
//    {
//        printf("%s\n", argv[i]);
//    }
//    return 0;
//}
//可以让程序在命令行中表现出不一样的行为
//int main()
//{
//    int n = 10;
//
//    int* f = (int*)malloc(sizeof(int) * (n + 2));
//    if (!f) exit(-1);
//
//    f[1] = 1;
//    f[2] = 1;
//    int i = 3;
//    while (i <= n)
//    {
//        f[i] = f[i - 1] + f[i - 2];
//        i++;
//    }
//    printf("%d", f[n]);
//    free(f);
//    return 0;
//}
int main()
{
	int n = 10;
	int first = 1;
	int second = 1;
	int third = 1;

	while (n >= 3)
	{
		third = second + first;
		first = second;
		second = third;
		n--;
	}
	printf("%d\n", third);
	return 0;
}