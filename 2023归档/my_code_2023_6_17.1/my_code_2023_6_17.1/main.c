#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <float.h>
////PTA题目一

//int _function_1(float x)
//{
//	if (x < 0)
//		return -1;
//	return 1;
//}
//float _function_2(float x)
//{
//	return _function_1(x) * ((int)(fabs(x) * 10 + 0.5) / 10.0);
//}
//void MyPrintf(float a1, float b1, float a2, float b2)
//{
//	//特殊情况：纯实数
//	if (b1 == 0 && b2 == 0)
//	{
//		//加法
//		printf("(%.1f%+.1fi) + (%.1f%+.1fi) = %.1f\n",
//			_function_2(a1),
//			_function_2(b1),
//			_function_2(a2),
//			_function_2(b2),
//			a1 + a2
//		);
//		//减法
//		printf("(%.1f%+.1fi) - (%.1f%+.1fi) = %.1f\n",
//			_function_2(a1),
//			_function_2(b1),
//			_function_2(a2),
//			_function_2(b2),
//			a1 - a2
//		);
//		//乘法
//		printf("(%.1f%+.1fi) * (%.1f%+.1fi) = %.1f\n",
//			_function_2(a1),
//			_function_2(b1),
//			_function_2(a2),
//			_function_2(b2),
//			a1 * a2
//		);
//		//除法
//		printf("(%.1f%+.1fi) / (%.1f%+.1fi) = %.1f\n",
//			_function_2(a1),
//			_function_2(b1),
//			_function_2(a2),
//			_function_2(b2),
//			a1 / a2
//		);
//		return;
//	}
//	else if (a1 == 0 && a2 == 0)//特殊情况：存虚数
//	{
//		//加法
//		printf("(%.1f%+.1fi) + (%.1f%+.1fi) = %.1f",
//			_function_2(a1),
//			_function_2(b1),
//			_function_2(a2),
//			_function_2(b2),
//			_function_2(b1 + b2)
//		);
//		if (_function_2(b1 + b2) == 0.0)
//		{
//			printf("\n");
//		}
//		else
//		{
//			printf("i\n");
//		}
//		//减法
//		printf("(%.1f%+.1fi) - (%.1f%+.1fi) = %.1f",
//			_function_2(a1),
//			_function_2(b1),
//			_function_2(a2),
//			_function_2(b2),
//			_function_2(b1 - b2)
//		);
//		if (_function_2(b1 - b2) == 0.0)
//		{
//			printf("\n");
//		}
//		else
//		{
//			printf("i\n");
//		}
//		//乘法
//		printf("(%.1f%+.1fi) * (%.1f%+.1fi) = %.1f\n",
//			_function_2(a1),
//			_function_2(b1),
//			_function_2(a2),
//			_function_2(b2),
//			_function_2 (- 1 * (b1 * b2))
//		);
//		//除法
//		printf("(%.1f%+.1fi) / (%.1f%+.1fi) = %.1f\n",
//			_function_2(a1),
//			_function_2(b1),
//			_function_2(a2),
//			_function_2(b2),
//			_function_2(b1 / b2)
//		);
//		return;
//	}
//	//加法
//	printf("(%.1f%+.1fi) + (%.1f%+.1fi) = ",
//		_function_2(a1), 
//		_function_2(b1), 
//		_function_2(a2),
//		_function_2(b2)
//	);
//	float x = _function_2(a1 + a2);
//	float y = _function_2(b1 + b2);
//	if (x != 0.0)
//	{
//		printf("%.1f", x);
//	}
//	if (y != 0.0)
//	{
//		if (x == 0.0)
//		{
//			printf("%.1fi\n", y);
//		}
//		else
//		{
//			printf("%+.1fi\n", y);
//		}
//	}
//	if (x == 0.0 && y == 0.0)
//	{
//		printf("0.0\n");
//	}
//	//减法
//	printf("(%.1f%+.1fi) - (%.1f%+.1fi) = ",
//		_function_2(a1),
//		_function_2(b1),
//		_function_2(a2),
//		_function_2(b2)
//	);
//	x = _function_2(a1 - a2);
//	y = _function_2(b1 - b2);
//	if (x != 0.0)
//	{
//		printf("%.1f", x);
//	}
//	if (y != 0.0)
//	{
//		
//		if (x == 0.0)
//		{
//			printf("%0.1fi\n", y);
//		}
//		else
//		{
//			printf("%+0.1fi\n", y);
//		}
//	}
//	if (x == 0.0 && y == 0.0)
//	{
//		printf("0.0\n");
//	}
//	//乘法
//	printf("(%.1f%+.1fi) * (%.1f%+.1fi) = ",
//		_function_2(a1),
//		_function_2(b1),
//		_function_2(a2),
//		_function_2(b2)
//	);
//	float i = (a1 * a2) - (b1 * b2);
//	float j = (a1 * b2 + b1 * a2);
//	i = _function_2(i);
//	j = _function_2(j);
//	if (i != 0.0)
//	{
//		printf("%.1f", i);
//	}
//	if (j != 0.0)
//	{
//		if (i == 0.0)
//		{
//			printf("%.1fi\n", j);
//		}
//		else
//		{
//			printf("%+.1fi\n", j);
//		}
//	}
//	if (i == 0 && j == 0)
//	{
//		printf("0.0\n");
//	}
//	//除法
//	printf("(%.1f%+.1fi) / (%.1f%+.1fi) = ",
//		_function_2(a1),
//		_function_2(b1),
//		_function_2(a2),
//		_function_2(b2)
//	);
//	i = (a1 * a2 + b1 * b2) / (a2 * a2 + b2 * b2);
//	j = (b1 * a2 - a1 * b2) / (a2 * a2 + b2 * b2);
//	i = _function_2(i);
//	j = _function_2(j);
//	if (i != 0.0)
//	{
//		printf("%.1f", i);
//	}
//	if (j != 0.0)
//	{
//		if (i == 0.0)
//		{
//			printf("%.1fi\n", j);
//		}
//		else
//		{
//			printf("%+.1fi\n", j);
//		}
//	}
//	if (i == 0.0 && j == 0.0)
//	{
//		printf("0.0\n");
//	}
//}
//int main()
//{
//	float a1 = 0;
//	float b1 = 0;
//	float a2 = 0;
//	float b2 = 0;
//	int scanfReturn = scanf("%f %f %f %f", &a1, &b1, &a2, &b2);
//	MyPrintf(a1, b1, a2, b2);
//	return 0;
//}

////PTA题目二

//int main()
//{
//	int N = 0;
//	int flag = 0;
//	scanf("%d", &N);
//	for (int Y = N; Y >= 1; Y--)
//	{
//		for (int X = 1; X <= Y; X++)
//		{
//			if (X * X + Y * Y == N)
//			{
//				printf("%d %d\n", X, Y);
//				flag = 1;
//			}
//		}
//	}
//	if (flag == 0)
//	{
//		printf("No Solution");
//	}
//	return 0;
//}

////PTA题目三

//int main()
//{
//	int T = 0;
//	scanf("%d", &T);
//	int T_number = 0;
//	int G_number = 0;
//	while (T >= 10)
//	{
//		T -= 10;
//		T_number += 10 * 9;
//		G_number += 10 * 3;
//		if (T_number > G_number)
//		{
//			G_number += 30 * 3;
//			T -= 30;
//		}
//	}
//	T_number += T * 9;
//	G_number += T * 3;
//	if (T_number > G_number)
//	{
//		printf("^_^ %d", T_number);
//	}
//	else if (T_number < G_number)
//	{
//		printf("@_@ %d", G_number);
//	}
//	else
//	{
//		printf("-_- %d", T_number);
//	}
//	return 0;
//}

////PTA题目四
int main()
{
	char** cache = (char**)malloc(sizeof(char**) * 100);
	if (!cache) exit(-1);
	int N = 0;//N行字符串
	int K = 0;//第K次冒泡
	scanf("%d %d", &N, &K);
	int i = 0;
	while (N)
	{
		scanf("%s", cache[i]);
		N--;
		i++;
	}
	//3 2 1 0;
	//2 3 1 0; 2 1 3 0; 2 1 0 3;
	//1 2 0 3; 1 0 2 3;
	//0 1 2 3;
	N = 4;
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = 0; j + 1 < N - i ; j++)
		{
			if (*(cache[j]) > *(cache[j + 1]))
			{
				char* tmp = cache[j];
				cache[j] = cache[j + 1];
				cache[j + 1] = tmp;
			}
		}
	}
	N = 4;
	i = 0;
	while (N)
	{
		printf("%s ", cache[i]);
		N--;
		i++;
	}
	return 0;
}