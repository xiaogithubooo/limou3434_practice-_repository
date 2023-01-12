#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
////day1
////选择题部分
////第一题
//int x = 5, y = 7;
//void swap()
//{
//	int z;
//	z = x;
//	x = y;
//	y = z;
//}
//int main()
//{
//	int x = 3, y = 8;
//	swap();
//	printf("%d,%d\n", x, y);
//	return 0;
//}
////第二题
//int main()
//{
//	int arr[5 + 3] = { 0,1,3,5,7,9 };
//	char c2[] = { '\x10', '\xa', '\8' };
//	double x[5] = { 2.0, 4.0, 6.0, 8.0, 10.0 };
//	double y[5] = { 2.0, 4.0, 6.0, 8.0, 10.0 };
//	printf("\8");
//	return 0;
//}
////第四题
//#define INT_PTR int*
//INT_PTR a, b;
//a = 1;
////第五题
//略
////编程题部分
////第一题
//int main()
//{
//    int n = 0;
//    scanf("%d", &n);
//    int i = 1;
//
//    if (n == 1)
//    {
//        printf("[");
//        for (i = 1; i < 10; i++)
//        {
//            printf("%d", i);
//            if (i != 9)
//            {
//                printf(",");
//            }
//        }
//        printf("]");
//    }
//    else if (n == 2)
//    {
//        printf("[");
//        for (i = 1; i < 100; i++)
//        {
//            printf("%d", i);
//            if (i != 99)
//            {
//                printf(",");
//            }
//        }
//        printf("]");
//    }
//    else if (n == 3)
//    {
//        printf("[");
//        for (i = 1; i < 1000; i++)
//        {
//            printf("%d", i);
//            if (i != 999)
//            {
//                printf(",");
//            }
//        }
//        printf("]");
//    }
//    else if (n == 4)
//    {
//        printf("[");
//        for (i = 1; i < 10000; i++)
//        {
//            printf("%d", i);
//            if (i != 9999)
//            {
//                printf(",");
//            }
//        }
//        printf("]");
//    }
//    else if (n == 5)
//    {
//        printf("[");
//        for (i = 1; i < 100000; i++)
//        {
//            printf("%d", i);
//            if (i != 99999)
//            {
//                printf(",");
//            }
//        }
//        printf("]");
//    }
//    return 0;
//}
////第五题
//int main()
//{
//    int n = 0;//年份
//    int m = 0;//月份
//    int u = 0;//日数
//
//    int num = 0;//总天数
//    scanf("%d %d %d", &n, &m, &u);
//    while (m--)
//    {
//        switch (m)
//        {
//        case 1:case 3:case 5:case 7:case 8:case 10:case 12:
//            num += 31;
//            break;
//        case 4:case 6:case 9:case 11:
//            num += 30;
//            break;
//        case 2:
//            if (((n % 4 == 0) && (n % 100 != 0)) || n % 400 == 0)
//            {
//                num += 29;
//            }
//            else
//            {
//                num += 28;
//            }
//        }
//    }
//    printf("%d", num + u);
//    return 0;
//}