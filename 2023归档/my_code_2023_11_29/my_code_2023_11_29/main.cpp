#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
double fun(double n)
{
	if (n < 0)//�����������������ú������� -1 ��ʾ����
		return -1;
	double number = 1;
	for (double i = n; i > 0; i--)
	{
		number *= i;
	}
	return number;
}
int main()
{
	for(int e = 0; e < 100; e++)//ѭ����ӡ 10 ��
	{
		printf("%f\n", fun(e));
	}
	return 0;
}

//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//double fun(double n)
//{
//	if (n < 0)//�����������������ú������� -1 ��ʾ����
//		return -1;
//
//	if (n == 1 || n == 0)
//		return 1;
//	return n * fun(n - 1);
//}
//int main()
//{
//	for (int e = 0; e < 100; e++)//ѭ����ӡ 10 ��
//	{
//		printf("%f\n", fun(e));
//	}
//	return 0;
//}