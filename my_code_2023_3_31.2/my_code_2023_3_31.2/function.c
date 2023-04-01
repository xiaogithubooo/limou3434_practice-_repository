#define _CRT_SECURE_NO_WARNINGS 1
#include "function.h"
//游戏菜单
void menu(void)
{
	printf("**************************************\n");
	printf("*************** 1.play ***************\n");
	printf("*************** 0.exit ***************\n");
	printf("**************************************\n");
}
//初始化棋盘
void InitBoard(char board[ROW][COL], int row, int col)
{
	memset(&board[0][0], ' ', row * col * sizeof(board[0][0]));//头文件是string.h
}
//打印显示棋盘
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i < row - 1)
		{
			for (int j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
				{
					printf("|");
				}
			}
		}
		printf("\n");
	}
}

//游戏主体
void game(void)
{
	char board[ROW][COL] = { 0 };
	//初始化棋盘
	InitBoard(board, ROW, COL);
	//打印显示棋盘
	DisplayBoard(board, ROW, COL);
	while (1)
	{
		//玩家下棋
		
		//打印棋盘
		
		//判断输赢
		
		//电脑下棋
		
		//打印棋盘
		
		//判断输赢
	}
}