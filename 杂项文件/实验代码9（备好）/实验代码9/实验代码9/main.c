#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<math.h>
#include<Windows.h>
//ʵ��Ŀ�ģ�
//��1����������Ķ��巽��
//��2�������������鸳ֵ�ķ���
//��3�����������������롢����ķ���
//��4����������������Ϊ���������ĵ��÷���
//
//����һ��
//int main(void)
//{
//	double results[10];
//	int i = 0;
//	printf("�ɼ��Ǽǣ�\n");
//	for (i = 0; i < 10; i++)
//	{
//		printf("�������%d��ѧ���ĳɼ���",i+1);
//		scanf("%Lf", &(results[i]));
//	}
//	printf("�ɼ����£�\n");
//	for (i = 0; i < 10; i++)
//	{
//		printf("��%d��ѧ���ĳɼ���%.0Lf\n", i + 1, *(results+i));
//	}
//	return 0;
//}
//�������
//int main(void)
//{
//	double results[10];
//	int i = 0;
//	double max = 0, min = 100, sum = 0, average;
//	printf("�ɼ��Ǽǣ�\n");
//	for (; i < 10; i++)
//	{
//		printf("�������%d��ѧ���ĳɼ���", i + 1);
//		scanf("%Lf", &results[i]);
//		if (max < results[i])
//		{
//			max = results[i];
//		}
//		if (min > results[i])
//		{
//			min = results[i];
//		}
//		sum += results[i];
//	}
//	average = sum / (sizeof(results) / sizeof(results[0]));//����֣�
//	printf("ͳ�����£�\n");
//	printf("����ѧ������߷�Ϊ��%Lf\n", max);
//	printf("����ѧ������ͷ�Ϊ��%Lf\n", min);
//	printf("����ѧ����ƽ��ֵΪ��%Lf\n", average);
//	return 0;
//}
//��������
//int main(void)
//{
//	char a[20] = { 'H','e','l','l','o',' ','W','o','r','l','d' };
//	int i;
//	printf("����ǰ��");//����ǰ
//	for (i = 0; i < 20; i++)
//	{
//		printf("%c", a[i]);
//	}
///////////////////////////////////////////////////////////////////
//	printf("\n");//���ܿ�ʼ
//	for (i = 0; i < 20; i++)
//	{
//		if (a[i] >= 'a' && a[i] <= 'z')
//		{
//			a[i] += 5;
//			if (a[i] >= 'z')
//			{
//				a[i] = 'a' + (a[i] - 'z' - 1);
//			}
//		}
//		else if (a[i] >= 'A' && a[i] <= 'Z')
//		{
//			a[i] += 5;
//			if (a[i] >= 'Z')
//			{
//				a[i] = 'A' + (a[i] - 'Z' - 1);
//			}
//		}
//	}
///////////////////////////////////////////////////////////////////
//	printf("���ܺ�");
//	for (i = 0; i < 20; i++)//���ܺ�
//	{
//		printf("%c", a[i]);
//	}
//	return 0;
//}