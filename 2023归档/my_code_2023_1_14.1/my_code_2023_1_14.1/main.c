#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
////1��һ����Ŀ��ϰ
// int main()
//{
//	int n = 0;
//	int number = 0;//����������
//	int j_1 = 0;//ͳ�Ƹ���
//	double j_2 = 0;//ͳ������
//	double add = 0;//��������������
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
////2��һ����
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
////3��һ����
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
////4��һ���⣨��󹫱�����
//int gcd(char x, char y)
//{
//	int min = x < y ? x : y;//ȡ���������е�
//	for(;min > 0; min--)
//		if (x% min == 0 && y % min == 0)
//			return min;
//}
////5��һ��ѭ��
//int main()
//{
//	int n = 0;
//	int i = 0, j = 0;
//	for (i = 0; i <= n - 1; i++)
//		for (j = n; j > i; j--)
//			//state;
//	return 0;
//}

