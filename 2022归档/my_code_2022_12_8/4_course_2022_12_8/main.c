#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
//��ϰʹ��malloc��free�ȶ�̬�ڴ���亯�����Լ�һ����Ŀ����ϰ
//int main()
//{
//	int* p;
//	int i = 0;
//	printf("�����룺%d\n",i);
//	scanf("%d", &i);
//	if (i = 1)
//	{
//		p = (int*)malloc(10 * sizeof(int));//����10�����α����ڴ�
//	}
//	else
//	{
//		p = (int*)malloc(INT_MAX + 1);//�������α����ڴ�
//	}
//
//	if (p == NULL)//����Ƿ���󿪱ٿռ�
//	{
//		printf("%s\n", strerror(errno));//�������Ӧ��ԭ�򱻴�ӡ����
//	}
//	else//����ʹ�ÿռ�
//	{
//		int i = 0;
//		for (i = 0; i < 10; i++)
//		{
//			*(p + i) = i;
//		}
//		for (i = 0; i < 10; i++)
//		{
//			printf("%d ", *(p + i));
//		}
//	}
// /////////////////////////////////////
//	{
//		free(p);//�ѿռ仹��ȥ
//		p = NULL;//һ����һ��ʹ�õ�
//	}
//	return 0;
//}

//int main()
//{
//	int* p = (int*)calloc(10, sizeof(int));
//	if (p == NULL)//����Ƿ���󿪱ٿռ�
//	{
//		printf("%s\n", strerror(errno));//�������Ӧ��ԭ�򱻴�ӡ����
//	}
//	else//����ʹ�ÿռ�
//	{
//		int i = 0;
//		for (i = 0; i < 10; i++)
//		{
//			*(p + i) = i;//���ﲻ��ʼ��Ҳ�ǿ��Եģ�������������ͻ��ʼ��Ϊ0������ע�͵���һ��ѭ����䣬����ͻ��ӡ��һϵ�е�0
//		}
//		for (i = 0; i < 10; i++)
//		{
//			printf("%d ", *(p + i));
//		}
//	}
//	free(p);//�ͷŶ�̬�ռ�
//	p = NULL;
//}

//int main()//��ʾһ����������ڴ棨��վ��������
//{
//	while (1)
//	{
//		malloc(1);
//		//Sleep(500);//������һ������
//	}
//	return 0;
//}//�������ĺ�������ڴ�ᱻ������ĵ�
////��һ����������ڴ�й©�ǽ���ʮ�ֲֿ�������

//һ��������
//void GetMemory(char* p)
//{
//	p = (char*)malloc(100);//1������û���ͷŶ�̬�ڴ�
//}
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(str);
//	strcpy(str, "hello word");
//	printf("%s\n",str);
//}
//int main()
//{
//	Test();
//	return 0;
//}

//�ⷨ1���е�С��
//void Test(void)
//{
//	char* str = NULL;
//	str = (char*)malloc(100);
//	strcpy(str, "hello word");
//	printf("%s\n", str);
//}
//int main()
//{
//	Test();
//	return 0;
//}
//�ⷨ2�������ܹ�ʵ����Ŀ����
//void GetMemory(char** p)
//{
//	*p = (char*)malloc(100);//1������û���ͷŶ�̬�ڴ�
//}
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(&str);
//	strcpy(str, "hello word");
//	printf(str);
//	free(str);
//	str = NULL;
//}
//int main()
//{
//	Test();
//	return 0;
//}
//�ⷨ3
//char* GetMemory(char* p)
//{
//	p = (char*)malloc(100);
//	return p;
//}
//void Test(void)
//{
//	char* str = NULL;
//	str = GetMemory(str);
//	strcpy(str, "hello word");
//	printf("%s\n",str);
//}
//int main()
//{
//	Test();
//	return 0;
//}
