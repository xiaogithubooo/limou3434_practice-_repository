#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<math.h>
#include<Windows.h>
//ʵ��Ŀ��
//��1���˽�C���Ա�ʾ�߼����ķ���
//��2��ѧ������ȷʹ���߼���������߼����ʽ
//��3����������if����switch���
//��4����ϳ�������һЩ�򵥵��㷨
//��5��ѧϰ���Գ���
//����һ���ɼ��������⣨���֧if�ṹ��
//int main()
//{
//	int grade = -1;
//	char gradeLeve1 = '0';
//
//	printf("������ɼ���0~100��\n");
//	scanf("%d", &grade);
//
//	if ((grade >= 0) && (grade < 60))
//	{
//		gradeLeve1 = 'E';
//	}
//	else if ((grade >= 60) && (grade < 70))
//	{
//		gradeLeve1 = 'D';
//	}
//	else if ((grade >= 70) && (grade < 80))
//	{
//		gradeLeve1 = 'C';
//	}
//	else if ((grade >= 80) && (grade < 90))
//	{
//		gradeLeve1 = 'B';
//	}
//	else if ((grade >= 90) && (grade <= 100))
//	{
//		gradeLeve1 = 'A';
//	}
//	printf("�ɼ� %d�ĵȼ���%c��\n", grade, gradeLeve1);
//	printf("So Easy!!!!!");
//	return 0;
//}
//��������ɼ��������⣨���֧switch�ṹ��
//int main()
//{
//	int grade = -1;
//	int grande_d10 = -1;
//	char gradeLeve1 = '0';
//	printf("������ɼ���0~100��\n");
//	scanf("%d", &grade);
//	grande_d10 = grade / 10;
//	switch (grande_d10)
//	{
//	case 10:
//	case 9:
//		gradeLeve1 = 'A';
//		break;
//	case 8:
//		gradeLeve1 = 'B';
//		break;
//	case 7:
//		gradeLeve1 = 'C';
//		break;
//	case 6:
//		gradeLeve1 = 'D';
//		break;
//	case 5:
//	case 4:
//	case 3:
//	case 2:
//	case 1:
//	case 0:
//		gradeLeve1 = 'E';
//		break;
//	}
//	printf("�ɼ�%3d�ĵȼ���%c��\n", grade, gradeLeve1);
//
//	printf("So Easy!!!!!\n");
//	return 0;
//}
//���������ۺ�����
//int main()
//{
//	int stuNum = 0;//�洢ѧ��
//	int remainder = -1;//��ѧ�ŵ����һλ
//	int weekNum = 0;//�洢����
//	int i;//�Զ���
//	//����ѧ��
//	printf("������ѧ�ţ� ��ΧΪ[142011001��142015000) ����");
//	for (i = 0; i < 10; i++)
//	{
//		scanf("%d", &stuNum);
//		if ((stuNum >= 142011001) && (stuNum < 142015000))
//		{
//			break;
//		}
//		else
//		{
//			printf("ѧ���������Ӧ����[142011001��142015000)�ڣ�");
//			continue;
//		}
//	}
//	//��������
//	printf("\n");
//	printf("������������ [1,20] ����");
//
//	for (i=0;i<10;i++)
//	{
//		scanf("%d", &weekNum);
//		if ((weekNum >= 1) && (weekNum <= 20))
//		{
//			break;
//		}
//		else
//		{
//			printf("�����������Ӧ����[1��20]�ڣ�");
//			continue;
//		}
//	}
//	
//	remainder = stuNum % 10;
//	if (remainder % 3 == weekNum % 3)//���һλ%3������%3��ȼ���
//	{
//		printf("ѧ��%d�ڵ�%d��Ӧ�ý���ҵ����\n", stuNum, weekNum);
//	}
//	else
//	{
//		printf("ѧ��%d�ڵ�%d��Ӧ�ý���ҵ�𣿷�\n", stuNum, weekNum);
//	}
//	return 0;
//}