#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
int main()
{
	int number = 0;
	char str[10] = { 0 };
	//scanf("%d %s", &number, str); //������˵�д��
	scanf("%d %s", &number, &str); //ò���ǶԵ�, Ҳ������������
	printf("%d %s", number, str);
	return 0;
}