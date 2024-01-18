#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
////1、逆序输出
//int main()
//{
//    int num[10] = { 0 };
//    for (int i = 0; i < 10; i++)
//    {
//        scanf("%d", &num[i]);
//    }
//    for (int i = 9; i >= 0; i--)
//    {
//        printf("%d ", num[i]);
//    }
//    return 0;
//}
////2、正斜线图案
//int main()
//{
//    int number = 0;
//    while (scanf("%d", &number) == 1)
//    {
//        for (int i = 0; i < number; i++)//打印number行
//        {
//            for (int j = 0; j < number - i - 1; j++)
//            {
//                printf(" ");
//            }
//            printf("*\n");
//        }
//    }
//    return 0;
//}
////3、阶乘求和
//int main()
//{
//	int number = 0;
//	int Add = 1;
//	int num = 1;
//	int a = 1;
//	scanf("%d", &number);
//	if (number == 1)
//	{
//		printf("1");
//		return 0;
//	}
//	for (int i = 0; i < number; i++)
//	{
//		a *= (num++);
//		Add += a;
//	}
//	printf("%d", Add - 1);
//	return 0;
//}
////4、函数计算题
//double max(double a, double b, double c)
//{
//    double t = 0;
//    if (a < b)
//    {
//        t = a;
//        a = b;
//        b = t;
//    }
//    if (b < c)
//    {
//        t = b;
//        b = c;
//        c = t;
//    }
//    if (a < c)
//    {
//        t = a;
//        a = c;
//        c = t;
//    }
//    if (a < b)
//    {
//        t = a;
//        a = b;
//        b = t;
//    }
//    return a;
//
//}
//int main()
//{
//    double a, b, c;
//    double y1, y2, y3;
//    scanf("%lf %lf %lf", &a, &b, &c);
//
//    y1 = max(a + b, b, c);
//    y2 = max(a, b + c, c);
//    y3 = max(a, b, b + c);
//    if (y2 + y3 != 0)
//    {
//        printf("%.2lf", y1 / (y2 + y3));
//    }
//    return 0;
//}
////5、反斜线图案
//int main()
//{
//    int number = 0;
//    while (scanf("%d", &number) == 1)
//    {
//        for (int i = 0; i < number; i++)
//        {
//            for (int j = 0; j < i; j++)
//            {
//                printf(" ");
//            }
//            printf("*\n");
//        }
//    }
//    return 0;
//}