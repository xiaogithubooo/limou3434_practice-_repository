#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
    char str1[] = "hello bit.";
    char str2[] = "hello bit.";
    char* str3 = "hello bit.";
    char* str4 = "hello bit.";//������ͬһ��ռ�
    if (str1 == str2)
        printf("str1 and str2 are same\n");
    else
        printf("str1 and str2 are not same\n");

    if (str3 == str4)
        printf("str3 and str4 are same\n");
    else
        printf("str3 and str4 are not same\n");

    printf("%p\n", str1);
    printf("%p\n", str2);
    printf("%p\n", str3);
    printf("%p\n", str4);

    return 0;
}