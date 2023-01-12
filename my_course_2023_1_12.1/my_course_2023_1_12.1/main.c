#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/////1、关机代码
//int main()
//{
//    char arr[20] = { 0 };
//    system("shutdown -s -t 60");
//again:
//    printf("你的电脑60s后关机了，输入：“我是sb”，就取消关机\n");
//        scanf("%s", arr);
//    if (strcmp(arr, "我是sb") == 0)
//    {
//        printf("取消关机");
//        system("shutdown -a");
//    }
//    else
//    {
//        goto again;
//    }
//    return 0;
//}
////2、函数的复习
//int MAX(int x, int y)
//{
//    return (x > y) ? (x) : (y);
//}
//int main()
//{
//    int num_1 = 10;
//    int num_2 = 100;
//    int max = MAX(num_1, num_2);
//    printf("max = %d\n", max);
//    return 0;
//}
////3、交换函数的复习
//void function(int* pa, int* pb)
//{
//    int t = 0;
//    t = *pa;
//    *pa = *pb;
//    *pb = t;
//}
//int main()
//{
//    int num_1 = 1;
//    int num_2 = 2;
//    printf("%d %d\n", num_1, num_2);
//
//    function(&num_1, &num_2);//使用交换函数
//    printf("%d %d\n", num_1, num_2);
//    return 0;
//}
//void function(int a, int b)
//{
//    int t = 0;
//    t = a;
//    a = b;
//    b = t;
//}
//int main()
//{
//    int num_1 = 1;
//    int num_2 = 2;
//    printf("%d %d\n", num_1, num_2);
//
//    function(num_1, num_2);//使用交换函数
//    printf("%d %d\n", num_1, num_2);
//    return 0;
//}
////4、简化查找润年的方法
//int is_leap_year(int y)
//{
//	return ((y % 4 == 0) && (y % 100 != 0)) || y % 400 == 0;
//
//}
//int main()
//{
//	int y = 0;
//	for (y = 1000; y <= 2000; y++)
//	{
//		//判断y是否为闰年
//		//如果是闰年返回1
//		//不是闰年返回0
//		if (is_leap_year(y))
//		{
//			printf("%d ", y);
//		}
//	}
//	return 0;
//}
////5、