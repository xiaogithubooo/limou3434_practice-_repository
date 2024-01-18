#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void Print_Factorial(const int N);

int main()
{
    int N;

    scanf("%d", &N);
    Print_Factorial(N);
    return 0;
}

/* 你的代码将被嵌在这里 */

#define MAXLEN 10000
void Print_Factorial(const int N)
{
    int n = N;
    if (n < 0)//处理负数的情况
    {
        printf("Invalid input\n");
        return;
    }
    //当N>=0的时候，开始计算大数阶乘
    //1.先创建一个字符数组
    char arr[MAXLEN] = { 1 };//存放数值1作为阶乘的基数

    //2.计算大数阶乘
    int i = 0;//循环数
    int k = 2;//乘数
    int tmp = 0;//进位数
    for (k = 2; k <= N; k++)//计算
    {
        /*这里还可以优化！！！*/
        for (i = 0, tmp = 0; i < MAXLEN; i++)
        {
            int a = (arr[i] * k) + tmp;
            arr[i] = a % 10;
            tmp = a / 10;
            //if (arr[i] == 0)
            //{
            //    break;
            //}
        }
    }
    //3.逆序打印结果
    int j = 0;
    for (j = MAXLEN - 1; j >= 0; j--)
    {
        if (arr[j] != 0)
        {
            for (j; j >= 0; j--)
            {
                printf("%d", arr[j]);
            }
        }
    }
}
//
//#define MAXLEN 1000
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//    char buffer[MAXLEN + 1] = { 0 };
//    char a[MAXLEN + 1] = { 0 };
//    char b[MAXLEN + 1] = { 0 };
//    //1.存储
//    int tmp = 0;//a或b数组循环数
//    int i = 0;//buffer数组循环数
//    scanf("%s", buffer);//先处理一个数
//    for (tmp = 0, i = strlen(buffer) - 1; i >= 0; i--)
//    {
//        a[tmp++] = buffer[i] - '0';
//    }
//    scanf("%s", buffer);//先处理一个数
//    for (tmp = 0, i = strlen(buffer) - 1; i >= 0; i--)
//    {
//        b[tmp++] = buffer[i] - '0';
//    }
//    //2.计算
//    int up = 0;//进位数
//    for (up = 0, i = 0; i < MAXLEN; i++)
//    {
//        tmp = a[i] + b[i] + up;
//        a[i] = tmp % 10;
//        up = tmp / 10;
//    }
//    //3.得出结果
//    for (i = MAXLEN; i >= 0; i--)
//    {
//        if (a[i] != 0)
//        {
//            for (i; i >= 0; i--)
//            {
//                printf("%d", a[i]);
//            }
//        }
//    }
//    return 0;
//}

