#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <math.h>
////分子函数
//double _Function_1(int x)
//{
//	int val = 1;
//	while (x)
//	{
//		val *= x;
//		x--;
//	}
//	return val;
//}
////分母函数
//double _Function_2(int x)
//{
//	int val = 1;
//	int i = x + 1;
//	for (i; 2 * i - 1 >= 0; i--)
//	{
//		val *= 2 * i - 1;
//	}
//	return val;
//}
//int main()
//{
//	double k = 0;
//	int scanfReturn = scanf("%lf", &k);
//	double K = 0;
//	double value = 0;
//	int i = 0;
//	while(1)
//	{
//		K = _Function_1(i) / _Function_2(i);
//		value += K;
//		if (K < k)
//		{
//			break;
//		}
//		i++;
//	}
//	printf("%f", value * 2);
//	return 0;
//}
#include <stdio.h>
int main()
{
	double sum = 1.0;
	double val = 1.0;
	double k = 0;
	int scanfReturn = scanf("%lf", &k);
	for (int i = 1; val > k; i++)
	{
		val *= (double)i / (2 * i + 1);
		sum += val;
	}
	printf("%.6f", sum * 2);
	return 0;
}