#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int a = 10;
	int b = 100;
	int c = 50;
	printf("%p\n", &a);
	printf("%p\n", &b);
	printf("%p\n", &c);

	printf("\n");

	int number[4] = { 0 };
	for (int i = 0; i < 4; i++)
	{
		printf("&number[%d] = %p\n", i, &number[i]);
	}

	char* str1 = "hello word"; int len1 = strlen(str1); for (int i = 0; i < len1; i++) 
	{
		printf("%d", *(str1 + i));//�ӷ��ʽǶ��������������ҵ�ջ��ı���str1��ʹ��str1����ֵ+i���õ�һ���µĵ�ַ�������������ַ���ҵ��ַ��������hello word����i+1���ַ�
	} 
	char str2[] = "hello word"; 
	int len2 = strlen(str2); 
	for(int j = 0 ; j < len2; j++) 
	{
		printf("%d", *(str2+j));//�ӷ��ʽǶ��������������ҵ�ջ���str2ָ����ַ�'h'��Ȼ��ͨ��+i�����ʴ洢��ջ�ڵ����ַ����ɵ��ַ��� 
	}
	return 0;
} 