#define _CRT_SECURE_NO_WARNINGS 1
#include "function.h"
int main()
{
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��ѡ��:");
		int scanf_num = scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ��");
			break;
		default:
			printf("ѡ��������ٴ�ѡ��\n");
			break;
		}
	} while (input);
	return 0;
}