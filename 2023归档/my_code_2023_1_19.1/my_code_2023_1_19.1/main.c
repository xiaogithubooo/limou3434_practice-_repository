#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//1���������滻��ʽ���̵Ŀ�
#include <iso646.h>//��������ǿ������滻������
int main()
{
	int a = 1, b = 2;
	if (a == 1 and b == 2)
	{
		printf("��ã�");
	}
	return 0;
}
//2������һ����Ŀ
int main()
{
	int x = -1;
	unsigned int y = 2;
	if (x > y)
	{
		printf("x is greater");
	} 
	else
	{
	printf("y is greater");
	} 
	return 0;
}
//3������һ����Ŀ
int main()
{
	int i = 1;
	sizeof(i++);
	printf("%d\n", i);
	return 0;
}