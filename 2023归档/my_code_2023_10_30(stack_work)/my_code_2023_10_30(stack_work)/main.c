#define _CRT_SECURE_NO_WARNINGS 1
#include <math.h>
#include <assert.h>
#include "stack.h"
#define SIZE 10000

//1.����ջ�ĺ�����
void test();
//2.ʮ����ת��ΪN����
void conversion();

int main()
{
	//1.ջ���Խӿ�
	//test();

	//2.����ת��
	conversion();
	return 0;
}


void test()
{
	Stack st1;//����һ��ջ�ṹ��
	StackInit(&st1);//��ʼ�����ջ
	StackPush(&st1, 1);//ѹջ
	StackPush(&st1, 2);//ѹջ
	StackPush(&st1, 3);//ѹջ
	StackPush(&st1, 4);//ѹջ
	StackPush(&st1, 5);//ѹջ

	printf("<ջ��>\n");
	while (!StackEmpty(&st1))//ֻҪջ��Ϊ�վͽ���ѭ��
	{
		printf("%3d\n", StackTop(&st1));//ȡ��ջ��Ԫ�ز��Ҵ�ӡ
		StackPop(&st1);//ɾ��ջ��Ԫ��
	}
	printf("<ջ��>\n");
	//StackPop(&st1);//�Ƿ�ɾ��
	//StackPop(&st1);//�Ƿ�ȡջ��Ԫ��
	StackDestroy(&st1);//����ջ�ṹ��
}

//1.��������
const char arr[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
void conversion()
{
	//2.��������
	int M = 0;
	int N = 0;
	printf("�������ֺͽ��ƣ�");
	int scanfRet = scanf("%d %d", &M, &N);//�������ֺ�����
	if (N <= 0)
	{
		printf("û�иý��ƣ�����Ƿ�\n");
		return 0;
	}
	char* number = (char*)malloc(sizeof(char) * SIZE);//���ս���洢���ַ���
	int flag = 1;
	//3.��ǰ��������������
	if (M < 0)
	{
		flag = -1;
		M = abs(M);
	}
	else if (M == 0)
	{
		printf("%d", 0);
		return 0;
	}

	//4.����ת��
	int i = 0;
	while (M)
	{
		number[i++] = arr[M % N];//ӳ������ַ�
		M /= N;
	}

	//5.�������
	if (flag == -1)
	{
		printf("-");
	}
	for (int j = i - 1; j >= 0; j--)
	{
		printf("%c", number[j]);
	}

	//6.�ͷ��ڴ�
	free(number);
}