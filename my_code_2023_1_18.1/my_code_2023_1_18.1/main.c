#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//1����֤�ַ�������
int main()
{
	char c[5] = { 'a', 'b', '\0', 'c', '\0' };
	char a[] = "x+y=5.";
	printf("%s\n", c);
	printf("%s", a);
	return 0;
}
//2�����Գ����Ƿ����
#include<stdio.h>
int main()
{
	int a[12] = { 1,2,3,4,5,6,7,8,9,10,11,12 }, * p[4], i;
	for (i = 0; i < 4; i++)
		p[i] = &a[i * 3];
	printf("%d\n",p[3][2]);
	return 0;
}
//3����֤���ʽ���
int main()
{
	int x;
	int y = ((x = 4 * 5, x * 5),x + 5);
	printf("%d", y);
	return 0;
}
//4�����Դ�ӡ���
int main()
{
	char a = 'a', b;
	printf("%c,", ++a);
	printf("%c\n", b = a++);
	return 0;
}