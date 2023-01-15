#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "函数声明.h"
int main() 
{ 
	//循环
	int number = my_ui();
	if (number == 1)//用户选择"界面"函数my_ui
	{
		printf("成功");
		getchar();
	}
	else
	{
		return 0;
	}
	//"初始化"三子棋棋盘my_lnitialize
	//打印三子棋"棋盘"my_chess
	//用户和人机交互过程，并且"判断"输赢my_estimate
	
	//显示本次赢家和两家赢的次数“结果”，并且询问玩家是否继续游玩my_result
}