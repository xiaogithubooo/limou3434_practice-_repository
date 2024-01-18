#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
//1、二次函数的实现
//int pd1(float x) //判断函数1，判断a是否为零
//{
//	if (x == 0)
//	{
//		return 0;
//	}
//	else
//	{
//		return 1;
//	}
//}
//int pd2(float y) //判断函数2，判断b是否为零
//{
//	if (y == 0)
//	{
//		return 0;
//	}
//	else
//	{
//		return 1;
//	}
//}
//int pd3(float a, float b, float c) //判断函数3，判断Dit是否合法
//{
//	float Dit;
//	float e = b * b;
//	float f = a * c;
//	float g = 4 * f;
//	Dit = e - g;
//
//	if (Dit < 0)//Dit<0的情况
//	{
//		return 0;
//	}
//	else//Dit>=0的情况
//	{
//		return 1;
//	}
//}
////*****************************************
//int main()
//{
//	float a, b, c, t;
//	while (scanf("%f %f %f", &a, &b, &c) == 3)//用户输入系数
//	{
//		if (pd1(a) == 0)//判断a是否为零
//		{
//			printf("Not quadratic equation");
//		}
//		else
//		{
//			if (pd3(a, b, c) == 0)//判断Dit合法性
//			{
//				float Dit, t, h, i, j1, j2, J1, J2;
//				float e = b * b;
//				float f = a * c;
//				float g = 4 * f;
//				Dit = g - e;
//				t = sqrt(Dit);
//
//				printf("x1=%.2f-%0.2fi;x2=%.2f+%.2fi\n", (-b / (2 * a)), (t / (2 * a)), (-b / (2 * a)), (t / (2 * a)));
//			}
//			else//判断Dit合法
//			{
//				float Dit, t, h, i, j1, j2, J1, J2;
//				float e = b * b;
//				float f = a * c;
//				float g = 4 * f;
//				Dit = e - g;
//				t = sqrt(Dit);
//				h = -b + t;
//				i = -b - t;
//				j1 = h / 2;
//				j2 = i / 2;
//				J1 = j1 / a;
//				J2 = j2 / a;
//				if (J1 == J2)
//				{
//					if (J1 == 0)
//					{
//						printf("x1=x2=%0.2f\n", fabs(J1));
//					}
//					else
//					{
//						printf("x1=x2=%0.2f\n", J1);
//					}
//				}
//				else
//				{
//					printf("x1=%.2f;x2=%.2f\n", J2, J1);
//				}
//			}
//		}
//	}
//
//	return 0;
//}
//2、获取月份天数
//int main()
//{
//    int n = 0, m = 0;
//    while (scanf("%d", &n) == 1)
//    {
//        scanf("%d", &m);
//        switch (m)
//        {
//        case 1:case 3:case 5:case 7:case 8:case 10:case 12:
//            printf("31\n");
//            break;
//        case 4:case 6:case 9:case 11:
//            printf("30\n");
//            break;
//        case 2:
//            if (n % 4 == 0 || n % 400 == 0)
//            {
//                printf("29\n");
//            }
//            else
//            {
//                printf("28\n");
//            }
//        }
//    }
//    return 0;
//}