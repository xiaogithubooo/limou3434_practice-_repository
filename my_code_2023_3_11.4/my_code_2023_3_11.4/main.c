#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int a, b, c, n;
	printf("������һ������\n");
	scanf("%d", &n);
	if (n <= 99 || n > 999)//����λ��
	{
		printf("�����ֲ���ˮ�ɻ���");
	}
	else//����λ��
	{
		a = n % 10;//�õ����һλ��
		b = (n / 10) % 10;//�õ��ڶ�λ��
		c = (n / 100);//�õ���һλ��

		if (n = a * a * a + b * b * b + c * c * c)
		{
			printf("������ˮ�ɻ���\n");
		}
		else
		{
			printf("����ˮ�ɻ���\n");
		}
	}
	return 0;
}