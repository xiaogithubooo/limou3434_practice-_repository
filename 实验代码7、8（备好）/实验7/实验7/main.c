#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<Windows.h>
#include "ͷ�ļ�.h"
//ʵ��Ŀ��
//��1�����յ�����
//��2���������պ����Ĵ���
//��3����������return���
//��4���������պ����ĵ���

//����һ��ʹ�ú�����׳�
//����1
//int main(void)
//{
//	double result = 1.0;//�洢�׳˽��
//	int n = 1;//�洢����n
//	int fun(int n);//����fun����
//	printf("��������׳��е�n��1~100����");
//	scanf("%d", &n);
//	result = fun(n);
//	printf("%.0f", result);
//	return 0;
//}
//����2
int main()
{
	while (1)
	{
		double result = 1;//�洢�׳˽��
		int n = 1;//�洢����n
		int jieCheng(int n);//�����׳˺���
		printf("������һ��������");
		scanf("%d", &n);
		result = jieCheng(n);                                //ֲ��ʵ��8������
		if (n < 0)
		{
			printf("���벻�Ϸ�");
			break;
		}
		printf("%d�Ľ׳�Ϊ��%f\n\n", n, result);
	}
	return 0;
}


////�����������������������
int main(void)
{
	float length = 0, width = 0, height = 0, area = 0, volume = 0;
	float getRectArea(float length, float width);//�����������
	float getCuboidVolume(float length, float width, float height);//�����������
	while (1)
	{                                                                                                          //ʵ��8��ѭ������Ҳֲ����
		printf("���������볤�ȡ���Ⱥ͸߶ȣ���1.0��2.0��3.0����");
		scanf("%f��%f��%f", &length, &width, &height);
		area = getRectArea(length, width);
		volume = getCuboidVolume(length, width, height);
	
		printf("���Σ�����%f����%f�������Ϊ��%f\n", length, width, area);
		printf("�����壨����%f����%f���ߣ�%f�������Ϊ��%f\n\n", length, width, height, volume);
		if (area < 0)
		{
			break;
		}
	}
	return 0;
}


//���������ɼ���������
int main()
{		
	int grade = -1;
	char gradeLeve1 = 'A';
	char getGradeLevel(int grade);//�����ȼ�����
	while (1)
	{
		printf("������ɼ���0~100��\n");
		scanf("%d", &grade);

		gradeLeve1 = getGradeLevel(grade);
		printf("�ɼ� %d�ĵȼ��ǣ�%c\n", grade, gradeLeve1);
		
		if (gradeLeve1=='0')                                                    //ֲ����ʵ��8
		{
			printf("So Easy!!!!!");
			break;
		}
	}
	return 0;
}
