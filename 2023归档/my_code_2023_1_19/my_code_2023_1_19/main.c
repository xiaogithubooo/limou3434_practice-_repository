#define _CRT_SECURE_NO_WARNINGS 1
////1、字符函数isprint的使用
//#include <stdio.h>
//#include <ctype.h>
//
//int main()
//{
//    int var1 = 'k';
//    int var2 = '8';
//    int var3 = '\t';
//    int var4 = ' ';
//
//    if (isprint(var1))
//    {
//        printf("var1 = |%c| 是可打印的\n", var1);
//    }
//    else
//    {
//        printf("var1 = |%c| 是不可打印的\n", var1);
//    }
//
//    if (isprint(var2))
//    {
//        printf("var2 = |%c| 是可打印的\n", var2);
//    }
//    else
//    {
//        printf("var2 = |%c| 是不可打印的\n", var2);
//    }
//
//    if (isprint(var3))
//    {
//        printf("var3 = |%c| 是可打印的\n", var3);
//    }
//    else
//    {
//        printf("var3 = |%c| 是不可打印的\n", var3);
//    }
//
//    if (isprint(var4))
//    {
//        printf("var4 = |%c| 是可打印的\n", var4);
//    }
//    else
//    {
//        printf("var4 = |%c| 是不可打印的\n", var4);
//    }
//
//    return(0);
//}
////2、字符函数ispunct
#include <stdio.h>
#include <ctype.h>

int main()
{
    int var1 = 't';
    int var2 = '1';
    int var3 = '/';
    int var4 = ' ';

    if (ispunct(var1))
    {
        printf("var1 = |%c| 是标点符号字符\n", var1);
    }
    else
    {
        printf("var1 = |%c| 不是标点符号字符\n", var1);
    }
    if (ispunct(var2))
    {
        printf("var2 = |%c| 是标点符号字符\n", var2);
    }
    else
    {
        printf("var2 = |%c| 不是标点符号字符\n", var2);
    }
    if (ispunct(var3))
    {
        printf("var3 = |%c| 是标点符号字符\n", var3);
    }
    else
    {
        printf("var3 = |%c| 不是标点符号字符\n", var3);
    }
    if (ispunct(var4))
    {
        printf("var4 = |%c| 是标点符号字符\n", var4);
    }
    else
    {
        printf("var4 = |%c| 不是标点符号字符\n", var4);
    }

    return(0);
}