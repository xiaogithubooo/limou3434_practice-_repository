#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int grad1 = 0;//������1��ѧ���ĳɼ�grad1
	int grad2 = 0;//������2��ѧ���ĳɼ�grad2
	
	printf("�����1��ѧ���ĳɼ���");//��ʾ�����1��ѧ���ĳɼ�
	scanf("%d", &grad1);//�Ӽ��������1��ѧ���ɼ�
	
	printf("�����2��ѧ���ĳɼ���");//��ʾ�����2��ѧ���ĳɼ�
	scanf("%d", &grad2);//�Ӽ��������2��ѧ���ɼ�

	if(grad1 >= 0 && grad1 <= 100)//�ж�grad1�Ƿ���[0,100]��Χ��
	{
		printf("grad1��[0,100]��Χ��\n");
	}
	else
	{
		printf("grad1����[0,100]��Χ��\n");
	}

	if (grad2 >= 0 && grad2 <= 100)//�ж�grad2�Ƿ���[0,100]��Χ��
	{
		printf("grad2��[0,100]��Χ��\n");
	}
	else
	{
		printf("grad2����[0,100]��Χ��\n");
	}

	//�ж�grad1��grad2�Ĺ�ϵ
	if (grad1 == grad2)
	{
		printf("��ѧ���ɼ����\n");
	}
	else if (grad1 > grad2)
	{
		printf("ѧ��1�ɼ�����ѧ��2�ɼ�\n");
	}
	else //grad1 < grad2
	{
		printf("ѧ��1�ɼ�С��ѧ��2�ɼ�\n");
	}
	return 0;
}