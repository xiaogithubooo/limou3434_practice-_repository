#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int a = 10;
	printf("%p", &a);//��ַ�ᷢ���仯�������������ջ�����
	return 0;
}
//int a = 13358;//0011 0100|0010 1110
//printf("%d\n", (char*)a);
//*(double*)0 = 3.14;
//long long a = 10;
//long long* pa = &a;
//pa = NULL;