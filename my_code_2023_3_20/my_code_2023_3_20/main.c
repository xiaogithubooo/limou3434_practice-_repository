#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
    union Un1
    {
        char c[5];
        int i;
    };

    union Un2
    {
        short c[7];
        int i;
    };

    //下面输出的结果是什么？
    printf("%d\n", sizeof(union Un1));
    printf("%d\n", sizeof(union Un2));
	return 0;
}