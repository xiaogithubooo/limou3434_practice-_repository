#include <stdio.h>

int main()
{
	int n = 0;
	int ret = 1;
	int sum = 0;

	int manN = 0;
	scanf("%d", &manN);

	for (int j = 1; j <= manN; j++)
	{
		ret *= j;
		sum += ret; //����ѭ����һ�ξͿ��Լ��㵽 1!  ѭ���ڶ��ο��Լ��� 1!+2!  ...  һֱѭ���� manN �ο��Լ��� 1!+2!+...+n!
	}

	printf("%d\n", sum);
	return 0;
}