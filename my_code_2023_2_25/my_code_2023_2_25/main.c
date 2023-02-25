#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//1、再次复习数组的两钟存储方式
int main()
{
    char str1[] = "hello word.";
    char str2[] = "hello word.";
    const char* str3 = "hello word.";
    const char* str4 = "hello word.";
    if (str1 == str2)
        printf("str1 and str2 are same\n");
    else
        printf("str1 and str2 are not same\n");

    if (str3 == str4)
        printf("str3 and str4 are same\n");
    else
        printf("str3 and str4 are not same\n");

    return 0;
}
//2、转移表的使用
#include <stdio.h>
int add(int a, int b)
{
    return a + b;
}
int sub(int a, int b)
{
    return a - b;
}
int mul(int a, int b)
{
    return a * b;
}
int div(int a, int b)
{
    return a / b;
}
int main()
{
    int x, y;
    int input = 1;
    int ret = 0;
    int(*p[5])(int x, int y) = { 0, add, sub, mul, div }; //转移表，即函数指针数组，这里的0（或者写NULL）起到占位的作用，理论上放什么都行，只要后续处理好就行…
    while (input)
    {
        printf("*************************\n");
        printf(" 1:add           2:sub \n");
        printf(" 3:mul           4:div \n");
        printf("*************************\n");
        printf("请选择：");
        scanf("%d", &input);
        if ((input <= 4) && (input >= 1))
        {
            printf("输入操作数：");
            scanf("%d %d", &x, &y);
            ret = (*p[input])(x, y);
        }
        else
        {
            printf("输入有误\n");
        }
        printf("ret = %d\n", ret);
    }
    return 0;
}
//当计算器后续需要加入更多的运算函数时，那么使用开关语句就会显得冗长，但是使用函数指针数组就不会有这个问题，这将会大大缩减代码。但是使用函数指针也具有有缺点，它只能存放同样函数签名（函数签名定义了函数的输入和输出，即：函数签名==参数+返回值）的函数