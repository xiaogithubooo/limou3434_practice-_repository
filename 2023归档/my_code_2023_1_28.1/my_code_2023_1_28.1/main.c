#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int function(int x)
{
	if (x == 1)
	{
		return 1;
	}
	return x * function(x - 1);
}
int main()
{
	int x = 0;
	int sc_number = scanf("%d", &x);
	printf("%d\n", function(x));

	return 0;
}
//���Եݹ�����ȱ��˳�㸴ϰ�׳˴������д