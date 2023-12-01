#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
    int i = 0;
    int j = 2;
    int z = 0;
    z = ((++i) && (j += 2));
    printf("%d\n", j);//Êä³ö 4
    return 0;
}