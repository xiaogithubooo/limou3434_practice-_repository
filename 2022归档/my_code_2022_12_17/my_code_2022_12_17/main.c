#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
//1���й����ַ�������д�ɵ����ַ�������
//int main()
//{
//	char arr[5] = { 'a','b','c'};
//	printf("%d\n", strlen(arr));//���3���˵��,arrȷʵ���汻�Զ���ֵΪ\0��
//	
//	char a[] = { 'a','b','c' };
//	printf("%d\n", strlen(arr));//���������3����������ڲ�ͬ�ı�����֮���ǲ�һ���ģ������������
//	return 0;
//}

//2���йظ�����ȡģ���㣨%��
/*int main()
{
	int i = 5 % -3;
	printf("%d\n", i);
	int j = -5 % -3;
	printf("%d\n", j);

	i = 100 % 7;
	j = -100 % 7;
	printf("%d\n", i);
	printf("%d\n", j);
	return 0;
}*///ò�ƻ���������ģ�����֮���о�

//3����֤ǰ�������������ѭ���е���д�Ƿ�������
/*int main()
{
	int i = 0;
	for(i = 5; i > 0; i--)
	{
		printf("%d\n", i);
	}
	printf("\n");
	for(i = 5; i > 0; --i)
	{
		printf("%d\n", i);
	}
	printf("*****************\n");
	i = 5;
	while (i > 0)
	{
		printf("%d\n", i);
		i--;
	}
	printf("\n");
	i = 5;
	while (i > 0)
	{
		printf("%d\n", i);
		--i;
	}
	printf("*****************\n");
	i = 5;
	do
	{
		printf("%d\n", i);
		i--;
	} while (i > 0);
	printf("\n");
	i = 5;
	do
	{
		printf("%d\n", i);
		--i;
	} while (i > 0);
	return 0;
}*///ò��������ѭ�����ڲ�����û������ģ������Ժ󻹿����о�һ�¡���

//4��������д����


