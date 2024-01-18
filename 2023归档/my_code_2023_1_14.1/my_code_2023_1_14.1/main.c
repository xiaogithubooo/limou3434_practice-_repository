#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
////1、一道题目练习
// int main()
//{
//	int n = 0;
//	int number = 0;//待处理数字
//	int j_1 = 0;//统计负数
//	double j_2 = 0;//统计正数
//	double add = 0;//加上所有正整数
//
//	int sznum = scanf("%d", &n);
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d", &number);
//		if (number < 0)
//		{
//			j_1++;
//		}
//		if (number > 0)
//		{
//			j_2++;
//			add += number;
//		}
//	}
//	printf("%d ", j_1);
//	if (j_2 != 0)
//	{
//		printf("%.1f",add / j_2);
//	}
//	else
//	{
//		printf("0.0");
//	}
//		return 0;
//}
////2、一道题
//int main()
//{
//	int m, n;
//	printf("Enter m,n:");
//	scanf("%d%d", &m, &n);
//	while (m != n) //1
//	{
//		while (m > n)
//			m = m - n; //2
//		while (n > m)
//			n = n - m; //3
//	}
//	printf("m=%d\n", m);
//	return 0;
//}
////3、一道题
//int main()
//{
//	char c;
//	int v0 = 0, v1 = 0, v2 = 0;
//	do
//	{
//		switch (c = getchar())
//		{
//			case'a':case'A':
//			case'e':case'E':
//			case'i':case'I':
//			case'o':case'O':
//			case'u':case'U':v1 += 1;
//			default:v0 += 1; v2 += 1;
//		}
//	}while (c != '\n');
//	printf("v0=%d,v1=%d,v2=%d\n", v0, v1, v2);
//	return 0;
//}
////4、一道题（最大公倍数）
//int gcd(char x, char y)
//{
//	int min = x < y ? x : y;//取出两个数中的
//	for(;min > 0; min--)
//		if (x% min == 0 && y % min == 0)
//			return min;
//}
////5、一道循环
//int main()
//{
//	int n = 0;
//	int i = 0, j = 0;
//	for (i = 0; i <= n - 1; i++)
//		for (j = n; j > i; j--)
//			//state;
//	return 0;
//}

