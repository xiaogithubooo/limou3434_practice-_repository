#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<Windows.h>
//ʵ��Ŀ��
//��1���˽�ѭ���ĸ���ͷ���
//��2����������for����while���
//��3���ܹ�Ӧ��ѭ�����ʵ������
//����һ����׳����⣨for��䣩
//int main()
//{
//	int a = 1, i, n;
//	printf("������׳��е�n��1~100����");
//	scanf("%d", &n);
//	for (i = 1; i <= n; ++i)
//	{
//		a *= i;
//	}
//	printf("%d�Ľ׳���%d\n", n, a);
//	return 0;
//}
//��������ַ�ͳ������
//int main()
//{
//	char ch;//�洢�ַ�
//	int upperNum = 0;//�洢��д��ĸ����
//	int lowerNum = 0;//�洢Сд��ĸ����
//	int digitNum = 0;//�洢�����ַ��ĸ���
//	printf("������һ���ַ������س�������");
//	ch = getchar();
//	while (ch != '\n')
//	{
//		
//		if (ch >= 'A' && ch <= 'Z')
//		{
//			++upperNum;
//		}
//		else if (ch >= 'a' && ch <= 'z')
//		{
//			++lowerNum;
//		}
//		else if (ch >= '0' && ch <= '9')
//		{
//			++digitNum;
//		}
//		else
//		{
//			printf("���벻�Ϸ���");
//		}
//		ch = getchar();
//	}
//	printf("��д��ĸ����Ϊ%d\n", upperNum);
//	printf("Сд��ĸ����Ϊ%d\n", lowerNum);
//	printf("�����ַ�����Ϊ%d\n", digitNum);
//	printf("So Easy!!!");
//	return 0;
//}
//���������ۺ����񣩣�����ѭ������׳˵�����
//int main()
//{
//	double result = 1.0;
//	int n = 1;
//	while (1)
//	{
//		printf("��������׳��е�n��1~100�������븺�����˳�����");
//		scanf("%d", &n);
//		if (n < 0)
//		{
//			break;
//		}
//		else if (n == 0)
//		{
//			continue;
//		}
//		else if (n >= 1 && n <= 100)
//		{
//			int a = 1, i;
//			for (i = 1; i <= n; ++i)
//			{
//				a *= i;
//			}
//			printf("%d�Ľ׳���%d\n", n, a);
//		}
//		else
//		{
//			break;
//		}
//	}
//	return 0;
//}