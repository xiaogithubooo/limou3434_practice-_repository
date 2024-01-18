#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int main()
//{
//	int i = 10;
//	printf("%d\n", i);
//	return 0;
//}
////2、测试Debug和Release模式的区别
//int main()
//{
//	int i = 0;
//	int arr[10] = { 0 };
//	for (i = 0; i <= 12; i++)
//	{
//		arr[i] = 0;
//		printf("hehe\n");
//	}
//	return 0;
//}
////3、1！+2！+3！+4!+……+10！的计算
//int main()
//{
//	int i = 0;
//	int add = 1;
//	int addx = 0;
//	int number = 0;
//	for (i = 1; i <= 10; i++)
//	{
//		add = 1;
//		number = i;
//		while(number)
//		{
//			add *= number;
//			number--; 
//		}
//		addx += add;
//	}
//	printf("%d", addx);
//	return 0;
//}
////4、常属性关键字const的测试
//int main()
//{
//	const int m = 100;
//	const int * p = &m;
//	const int ** pp = &p;
//	int *** ppp = &pp;
//	***ppp = 200;
//	printf("%d\n", m);
//	return 0;
//}