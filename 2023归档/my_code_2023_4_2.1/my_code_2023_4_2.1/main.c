#define _CRT_SECURE_NO_WARNINGS 1
#include "function.h"
int main()
{
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��:");
		int scanf_num = scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�ɹ��˳�����\n");
			break;
		default:
			printf("ѡ�����,���ٴ�ѡ��\n");
			break;
		}
	} while (input);
	return 0;
}

//ע����չ����
//1.��ҿ���չ����������
// ��1�������겻����
// ��2����������Χû����
// ��3��������û�б��Ų�����������ݹ飩
//2.��ҿ��Զ��Լ���Ϊ���������
//3.����ɨ�׼�ʱ��