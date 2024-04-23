//在 main_2.c 中
#include <stdio.h>

//extern int Add(int x, int y);

int main()
{
    int a = 10, b = 20, sum;
    sum = Add(a, b); //无法调用
    printf("%d\n", sum);
    return 0;
}