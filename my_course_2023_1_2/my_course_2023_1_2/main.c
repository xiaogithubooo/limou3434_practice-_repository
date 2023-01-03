#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//1、实验%g和%G的用法
int main()
{
	double a,b;
	a = 123456789;
	printf("%f  %e  %g  %G\n", a, a, a, a);
	b = 123;
	printf("%f  %e  %g  %G\n", b, b, b, b);
	return 0;;
}

//2、K形图案
//int main()
//{
//    int n = 0;
//    while (scanf("%d", &n) == 1)
//    {
//        for (int i = 0; i < n; i++)
//        {
//            for (int j = n; j >= i; j--)
//            {
//                printf("* ");
//            }
//            printf("\n");
//        }
//        for (int i = 0; i <= n; i++)
//        {
//            for (int j = 0; j <= i; j++)
//            {
//                printf("* ");
//            }
//            printf("\n");
//        }
//    }
//    return 0;
//}

//3、棱形图案
//int main()
//{
//	int n = 0;
//	while (scanf("%d", &n) == 1)
//	{
//		for (int i = 0; i <= n; i++)
//		{
//			for (int a = n; a > i; a--)
//			{
//				printf(" ");//打印空格
//			}
//			for (int b = 0; b <= i; b++)
//			{
//				printf("* ");
//			}
//			printf("\n");
//		}
//		for (int i = 0; i < n; i++)
//		{
//			for (int a = 0; a <= i; a++)
//			{
//				printf(" ");//打印空格
//			}
//			for (int b = n; b > i; b--)
//			{
//				printf("* ");
//			}
//			printf("\n");
//		}
//	}
//	return 0;
//}

//4、箭形图案
//int main()
//{
//	int n = 0;
//	while (scanf("%d", &n) == 1)
//	{
//		n++;
//		for (int i = 0; i < n; i++)
//		{
//			for (int a = n - 1; a > i; a--)
//			{
//				printf("  ");
//			}
//			for (int b = 0; b <= i; b++)
//			{
//				printf("*");
//			}
//			printf("\n");
//		}
//
//		for (int i = 0; i < n - 1; i++)
//		{
//			for (int a = 0; a <= i; a++)
//			{
//				printf("  ");
//			}
//			for (int b = n - 1; b > i; b--)
//			{
//				printf("*");
//			}
//			printf("\n");
//		}
//	}
//}

//5、带空格直角三角形图案
//int main()
//{
//	int n = 0;
//	while (scanf("%d", &n) == 1)
//	{
//		for (int i = 0; i < n; i++)
//		{
//			for (int a = n; a > i+1; a--)
//			{
//				printf("  ");
//			}
//			for (int b = 0; b <= i; b++)
//			{
//				printf("* ");
//			}
//			printf("\n");
//		}
//	}
//	return 0;
//}

//6、金字塔图案
//int main()
//{
//	int n = 0;
//	while (scanf("%d", &n) == 1)
//	{
//		for (int i = 0; i < n; i++)
//		{
//			for (int a = n; a > i+1; a--)
//			{
//				printf(" ");
//			}
//			for (int b = 0; b <= i; b++)
//			{
//				printf("* ");
//			}
//			printf("\n");
//		}
//	}
//	return 0;
//}

//7、翻转金字塔
//int main()
//{
//	int n = 0;
//	while (scanf("%d", &n) == 1)
//	{
//		for (int i = 0; i < n; i++)
//		{
//			for (int a = 0; a < i; a++)
//			{
//				printf(" ");
//			}
//			for (int b = n; b > i; b--)
//			{
//				printf("* ");
//			}
//			printf("\n");
//		}
//	}
//	return 0;
//}