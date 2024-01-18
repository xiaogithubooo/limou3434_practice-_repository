#define _CRT_SECURE_NO_WARNINGS 1
#include "function.h"
int main()
{
	int input = 0;
	do
	{
		menu();
		printf("请选择选项:");
		int scanf_num = scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏！");
			break;
		default:
			printf("选择错误，请再次选择\n");
			break;
		}
	} while (input);
	return 0;
}