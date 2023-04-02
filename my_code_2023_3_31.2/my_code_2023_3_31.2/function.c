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
	memset(&board[0][0], ' ', row * col * sizeof(board[0][0]));//头文件是string.h，注意这个空格是有讲究的
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
//玩家下棋
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0, y = 0;
	while (1)
	{
		printf("玩家下棋——");
		printf("其输入下棋坐标(\"行\"和\"列\"):");
		int scanf_num = scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("此次已经有棋子,不能再下,请重新输入!!!\n");
			}
		}
	}
}
//电脑下棋
void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("电脑下棋——");
	printf("其输入下棋坐标(\"行\"和\"列\"):");
	srand((unsigned int)time(NULL));
	while (1)
	{
		x = rand() % row;//注意这里的编写
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			printf("%d %d\n", x, y);
			board[x][y] = '#';
			break;
		}
	}
}
//判断输赢
int IsFull(char board[ROW][COL], int row, int col);//辅助函数，判断是否票据
char Iswin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)//行判断
	{
		if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != ' ')
		{
			return board[i][0];
		}
	}
	for (i = 0; i < row; i++)//列判断
	{
		if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != ' ')
		{
			return board[i][0];
		}
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')//捺判断
	{
		return board[1][1];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')//撇判断
	{
		return board[1][1];
	}
	if (IsFull(board, row, col))//判断是否平局
	{
		return 'Q';
	}
	return 'C';//游戏继续
}
int IsFull(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;//没有平局
			}
		}
	}
	return 1;
}

//游戏主体
void game(void)
{
	char board[ROW][COL] = { 0 };
	char ret = 0;
	//初始化棋盘
	InitBoard(board, ROW, COL);
	//打印显示棋盘
	DisplayBoard(board, ROW, COL);
	while (1)
	{
		//玩家下棋
		PlayerMove(board, ROW, COL);
		//打印棋盘
		DisplayBoard(board, ROW, COL);
		//判断输赢
		ret = Iswin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		//电脑下棋
		ComputerMove(board, ROW, COL);
		//打印棋盘
		DisplayBoard(board, ROW, COL);
		//判断输赢
		ret = Iswin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("玩家赢\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢\n");
	}
	else if (ret == 'Q')
	{
		printf("平局\n");
	}
}