#define _CRT_SECURE_NO_WARNINGS 1
////1���ַ�����isprint��ʹ��
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
//        printf("var1 = |%c| �ǿɴ�ӡ��\n", var1);
//    }
//    else
//    {
//        printf("var1 = |%c| �ǲ��ɴ�ӡ��\n", var1);
//    }
//
//    if (isprint(var2))
//    {
//        printf("var2 = |%c| �ǿɴ�ӡ��\n", var2);
//    }
//    else
//    {
//        printf("var2 = |%c| �ǲ��ɴ�ӡ��\n", var2);
//    }
//
//    if (isprint(var3))
//    {
//        printf("var3 = |%c| �ǿɴ�ӡ��\n", var3);
//    }
//    else
//    {
//        printf("var3 = |%c| �ǲ��ɴ�ӡ��\n", var3);
//    }
//
//    if (isprint(var4))
//    {
//        printf("var4 = |%c| �ǿɴ�ӡ��\n", var4);
//    }
//    else
//    {
//        printf("var4 = |%c| �ǲ��ɴ�ӡ��\n", var4);
//    }
//
//    return(0);
//}
////2���ַ�����ispunct
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
        printf("var1 = |%c| �Ǳ������ַ�\n", var1);
    }
    else
    {
        printf("var1 = |%c| ���Ǳ������ַ�\n", var1);
    }
    if (ispunct(var2))
    {
        printf("var2 = |%c| �Ǳ������ַ�\n", var2);
    }
    else
    {
        printf("var2 = |%c| ���Ǳ������ַ�\n", var2);
    }
    if (ispunct(var3))
    {
        printf("var3 = |%c| �Ǳ������ַ�\n", var3);
    }
    else
    {
        printf("var3 = |%c| ���Ǳ������ַ�\n", var3);
    }
    if (ispunct(var4))
    {
        printf("var4 = |%c| �Ǳ������ַ�\n", var4);
    }
    else
    {
        printf("var4 = |%c| ���Ǳ������ַ�\n", var4);
    }

    return(0);
}