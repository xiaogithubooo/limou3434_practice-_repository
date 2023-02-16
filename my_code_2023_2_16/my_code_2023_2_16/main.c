#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
////1、检验静态无链接变量
//void trystat(void)
//{
//    int fade = 1;
//    static int stay = 1;
//
//    printf("fade = %d and stay = %d\n", fade++, stay++);
//}
//int main()
//{
//    int count;
//    for (count = 1; count <= 3; count++)
//    {
//        printf("Here comes iteration %d:\n", count);
//        trystat();
//    }
//    return 0;
//}
////2、初始化静态无链接变量
//int main()
//{
//	int c = 200;
//	int d = 300;
//	static int a = 100;
//	static int b;
//	printf("%d %d", a, b);
//	return 0;
//}
////3、静态外部链接类别
//int main()
//{
//	extern int a;
//	printf("%d", a);
//
//	{
//		extern int a;
//		printf("%d\n", a);
//	}
//		return 0;
//}
//int x = 10;
//int y = 10 * x;
//
//int Errupt = 200;//在本文件的外部变量
//double Up[100] = { 1.2, 2,0, 3.7};//在本文件的外部变量数组
//
//extern char Coal;//在其他文件的外部变量
//extern char arr[];//在其他文件的外部变量数组
//
//void next(void)
//{
//	//代码
//}
//int main()
//{
//	extern int Errupt;//可写可不写
//	printf("%d", Errupt);
//	extern double Up[];//可写可不写
//
//	//使用Errupt和Up的代码
//
//	//使用Coal和arr的代码
//
//	return 0;
//}
//int main()
//{
//	extern int a = 200;
//	a = 200;
//}
//int a = 1;
//static int b = 2;
//int main()
//{
//	printf("%d %d\n", a, b);
//	{
//		extern int a;
//		extern int b;
//		printf("%d %d", a, b);
//	}
//	return 0;
//}