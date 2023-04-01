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
		printf("请选择\n");
		scanf("%d", &input);
		switch(input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏！");
			break;
		default:
			printf("选择错误，请选择\n");
			break;
		}
	} while (input);
	return 0;
}