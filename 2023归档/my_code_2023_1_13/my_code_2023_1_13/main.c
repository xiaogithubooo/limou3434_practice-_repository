#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
////1、数组初始化的问题
//int main()
//{
//
//	char a[14] = "Hello,world!";
//	char b[14];
//	b = "Hello,world!";
//	printf("%s\n", b);
//	return 0;
//}
////2、验证尼科彻斯定理
//int main()
//{
//	int n = 0;
//	int number = 0;//临时存储n的数
//	int end_number = 0;//存储奇数的总个数
//	int P_j = 0, F_j = 0;//开始的奇数，结束的奇数
//	int j = 1;//奇数
//	while (scanf("%d", &n) == 1)
//	{
//		for (number = n; number != 0; number--)
//		{
//			end_number += number;
//		}
//		for (j = 1; end_number != 0; end_number--)
//		{
//			j += 2;
//		}
//		F_j = j;//得到最后奇数
//		P_j = j - ((n) * 2);//得到开始奇数
//		for (P_j; P_j < F_j; P_j += 2)
//		{
//			printf("%d", P_j);
//			if (P_j != F_j - 2)
//			{
//				printf("+");
//			}
//		}
//	}
//	return 0;
//}1
//
////3、等差数列
//int main()
//{
//	int d = 3;//公差
//	int a_1 = 2;//首项
//	int S = 0;
//	int n = 0;
//	scanf("%d", &n);
//	S = ((d * (n * n) + (2 * a_1 * n) - d * n)) / 2;
//	printf("%d", S);
//	return 0;
//}
////4、九九乘法口诀表
//int main()
//{
//	for (int i = 1; i <= 9; i++)
//	{
//		for (int j = 1; j <= i; j++)
//		{
//			printf("%d*%d=%d ", j, i, i * j);
//		}
//		printf("\n");
//	}
//	return 0;
//}
////5、递归的使用
//my_printf(unsigned int x)
//{
//    if (x > 9)
//    {
//        my_printf(x / 10);
//        printf("%u ", x % 10);
//    }
//    else
//    {
//        printf("%d ", x);
//    }
//}
////my_printf(1234)
////my_printf(123)4
////my_printf(12)34
////my_printf(1)234
//int main()
//{
//    unsigned int number = 0;
//    scanf("%u", &number);
//    my_printf(number);
//    return 0;
//}
////6、交换两个数
//function(int *x, int *y)
//{
//	int t = 0;
//	t = *x;
//	*x = *y;
//	*y = t;
//}
//int main()
//{
//	int a = 10, b = 20;
//	printf("交换前：%d %d\n", a, b);
//	function(&a, &b);
//	printf("交换后：%d %d\n", a, b);
//	return 0;
//}
////7、闰年地寻找
//int is_leap_year(int y)
//{
//	return ((y % 4 == 0) && (y % 100 != 0)) || y % 400 == 0;
//}
//int main()
//{
//	int y = 0;
//	scanf("%d", &y);
//	if (is_leap_year(y))
//	{
//		printf("%d是闰年\n", y);
//	}
//	else
//	{
//		printf("不是闰年\n");
//	}
//	return 0;
//}
////8、打印100到200之间的素数
//int function(int n)
//{
//	double k = 0; 
//	int i = 0;
//	k = sqrt(n);
//	for (i = 2; i <= k; i++)
//	{
//		if (n % i == 0)
//			break;
//	}
//	if (i <= k)
//	{
//		return 0;//不是质数
//	}
//	else//是质数
//	{
//		return 1;
//	}
//}
//int main()
//{
//	int n = 0;
//	for (n = 99; n <= 200; n+=2)
//	{
//		if (function(n))
//		{
//			printf("%d ", n);
//		}
//	}
//	return 0;
//}
////9、阶乘代码
//int fun(int n)
//{
//	if (n <= 1)
//	{
//		return 1;
//	}
//	else
//		return n * fun(n - 1);
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	printf("%d", fun(n));
//	return 0;
//}
////10、斐波那契数列
//int fun(int n)
//{
//	if (n <= 2)
//		return 1;
//	else
//		return fun(n - 1) + fun(n - 2);
//}
//int main()
//{
//	int n = 0;
//	while (scanf("%d", &n) == 1)
//	{
//		printf("第%d个斐波那契数列为%d\n", n, fun(n));
//	}
//	return 0;
//}
