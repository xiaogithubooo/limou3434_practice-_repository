#define _CRT_SECURE_NO_WARNINGS 1
#include "function.h"
void menu()
{
	printf("**************************************\n");
	printf("*************** 1.play ***************\n");
	printf("*************** 2.exit ***************\n");
	printf("**************************************\n");
}
int main()
{
	int input = 0;
	do 
	{
		menu();
		printf("��ѡ��\n");
		scanf("%d", &input);
		switch(input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ��");
			break;
		default:
			printf("ѡ�������ѡ��\n");
			break;
		}
	} while (input);
	return 0;
}