#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//1���ٴθ�ϰ��������Ӵ洢��ʽ
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
//2��ת�Ʊ��ʹ��
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
    int(*p[5])(int x, int y) = { 0, add, sub, mul, div }; //ת�Ʊ�������ָ�����飬�����0������дNULL����ռλ�����ã������Ϸ�ʲô���У�ֻҪ��������þ��С�
    while (input)
    {
        printf("*************************\n");
        printf(" 1:add           2:sub \n");
        printf(" 3:mul           4:div \n");
        printf("*************************\n");
        printf("��ѡ��");
        scanf("%d", &input);
        if ((input <= 4) && (input >= 1))
        {
            printf("�����������");
            scanf("%d %d", &x, &y);
            ret = (*p[input])(x, y);
        }
        else
        {
            printf("��������\n");
        }
        printf("ret = %d\n", ret);
    }
    return 0;
}
//��������������Ҫ�����������㺯��ʱ����ôʹ�ÿ������ͻ��Ե��߳�������ʹ�ú���ָ������Ͳ�����������⣬�⽫�����������롣����ʹ�ú���ָ��Ҳ������ȱ�㣬��ֻ�ܴ��ͬ������ǩ��������ǩ�������˺�����������������������ǩ��==����+����ֵ���ĺ���