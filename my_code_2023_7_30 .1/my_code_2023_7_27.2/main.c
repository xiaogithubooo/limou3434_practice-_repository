#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
//PTA��һ��
/*
һ�����ַ���������ԭ��Ϊ�������������f(x)������[a, b]�������˵�ȡֵ��ţ���f(a)f(b) < 0��������������������ٴ���1����r����f(r) = 0��
�������ַ��Ĳ���Ϊ��
1.������䳤�ȣ����С�ڸ�����ֵ����ֹͣ����������е�(a + b) / 2������
2.���f(a)f(b) < 0��������е��ֵf((a + b) / 2)��
3.���f((a + b) / 2)����Ϊ0����(a + b) / 2����Ҫ��ĸ�������
	���f((a + b) / 2)��f(a)ͬ�ţ���˵����������[(a + b) / 2, b]����a = (a + b) / 2���ظ�ѭ����
	���f((a + b) / 2)��f(b)ͬ�ţ���˵����������[a, (a + b) / 2]����b = (a + b) / 2���ظ�ѭ����
��������ĿҪ���д���򣬼������3�׶���ʽf(x)�������ʽ����һ��������ö���ʽ�ڸ������ڵĸ�����ȷ��С�����2λ��
*/
/*
//1.���������ϵ��������
double a3 = 0, a2 = 0, a1 = 0, a0 = 0;//���׺�����ϵ��
double a = 0, b = 0;//����ϵ��

//2.f(x)���׺����Ķ���
double Function(double x)
{
	return a3 * (x * x * x) + a2 * (x * x) + a1 * (x) + a0;
}

//3.���ַ���������main()
int main()
{
	//4.��ȡ������ϵ��������
	int scanfReturn = scanf("%lf %lf %lf %lf", &a3, &a2, &a1, &a0);
	scanfReturn = scanf("%lf %lf", &a, &b);

	double begin = a;
	double end = b;
	double mind = 0;
	int i = 1;
	//5.���в���ϵĶ��ַ�������i��Ϊ�˷��������Ƶ�
	while (i)
	{
		mind = (begin + end) / 2;
		double beginValue = Function(begin);
		double endValue = Function(end);
		double mindValue = Function(mind);
		if (fabs(beginValue) < DBL_EPSILON)//˵������0
		{
			printf("%.2lf", begin);
			return 0;
		}
		else if (fabs(endValue) < DBL_EPSILON)//˵������0
		{
			printf("%.2lf", end);
			return 0;
		}
		else//˵����������0
		{
			if (fabs(mindValue) < 0)//˵������0
			{
				printf("%.2lf", mind);
				return 0;
			}
			else if (mindValue > 0)
			{
				if (beginValue < 0)
				{
					end = mind;
				}
				else
				{
					begin = mind;
				}
			}
			else//mindValue < 0
			{
				if (beginValue < 0)
				{
					begin = mind;
				}
				else
				{
					end = mind;
				}
			}
		}
		i++;
	}
	return 0;
}
*/

//PTA�ڶ���
/*
�ڹ������ӽ������ܣ��ܳ���һ�������ܵ����ܵ��߿�����ؽ�����Ϣ��
1.�ڹ�ÿ���ӿ���ǰ��3�ף�����ÿ����ǰ��9�ף�
2.�������ڹ��ܵ��������ÿ϶�����Ӯ�ڹ꣺
	2.1.ÿ��10���ӻ�ͷ��һ���ڹ꣬�������Լ������ڹ꣬����·����Ϣ30����
	2.2.���������10����
3.�ڹ�ǳ�Ŭ����һֱ�ܣ�����Ϣ��
4.�ٶ��ڹ���������ͬһ���ͬһʱ�̿�ʼ���ܣ�����T���Ӻ��ڹ������˭�ܵÿ죿
5.��һ������������Ľ����
	�ڹ�Ӯ���@_@��
	����Ӯ���^_^��
	ƽ�������-_-��
	���1�ո������ʤ��������ľ��롣
*/
//int main()
//{
//	int T = 0;//�������е�min��
//	int scanfReturn = scanf("%d", &T);
//	int	rabbitS = 0;//���ӵ���·��
//	int tortoiseS = 0;//�ڹ����·��
//	int timer = 10;//��ʱ��
//	while (T)
//	{
//		if (timer == 0)
//		{
//			timer = 10;
//			if (T > 10)
//			{
//				tortoiseS += (3 * 10);
//				T -= 10;
//			}
//			else
//			{
//				tortoiseS += (3 * T);
//				T = 0;
//			}
//		}
//		rabbitS += 9;
//		tortoiseS += 3;
//		timer--;
//		T--;
//	}
//	if (rabbitS > tortoiseS)
//	{
//		printf("^_^ %d", rabbitS);
//	}
//	else if (rabbitS < tortoiseS)
//	{
//		printf("@_@ %d", tortoiseS);
//	}
//	else
//	{
//		printf("-_- %d", rabbitS);
//	}
//	return 0;
//}

//PTA������
int GetNumber(int x, int y)
{
	if (y == 0)//���û��ʣ���
		return x;
	int r = x % y;//�൱��x - n * y��ʣ��Ĳ���r
	return GetNumber(y, r);//�ݹ��˾ͱ��y - n * r
}
int main()
{
	int N = 0;
	scanf("%d", &N);
	int tmp = N;

	int fenz = 0;
	int fenm = 0;
	scanf("%d/%d", &fenz, &fenm);
	while (N - 1)
	{
		int a = 0;
		int b = 0;
		scanf("%d/%d", &a, &b);
		fenz = fenz * b + a * fenm;
		fenm = b * fenm;
		int number = GetNumber(fenz, fenm);
		fenz /= number;
		fenm /= number;

		N--;
	}
	fenm *= tmp;
	int number = GetNumber(fenz, fenm);
	fenz /= number;
	fenm /= number;
	if (fenm == 1)
	{
		printf("%d\n", fenz);
	}
	else
	{
		printf("%d/%d", fenz, fenm);
	}
	return 0;
}