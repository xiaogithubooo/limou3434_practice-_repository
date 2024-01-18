#define _CRT_SECURE_NO_WARNINGS 1
#include "function.h"
//菜单函数
void menu(void)
{
	printf("------------------------\n");
	printf("-------  1.play  -------\n");
	printf("-------  0.exit  -------\n");
	printf("------------------------\n");
}
//初始化函数
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}
//打印函数
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	printf("-------扫雷--------\n");
	for (int k = 0; k <= row; k++)
	{
		printf("%d ", k);
	}
	printf("\n");
	for (int i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (int j = 1; j <= row; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}
//布置雷函数
void SetMine(char mine[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;
	int x = 0, y = 0;

	while (count)
	{
		x = rand() % row + 1;
		y = rand() % col + 1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}
	}
}
//排查雷
int GetMineCount(char mine[ROWS][COLS], int x, int y)//辅助函数
{
	return (mine[x - 1][y] +//这一步很精髓
		mine[x - 1][y - 1] +
		mine[x][y - 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] +
		mine[x][y + 1] +
		mine[x - 1][y + 1] - 8 * '0');
}
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0, y = 0;
	int win = 0;
	while (win < row*col - EASY_COUNT)
	{
		printf("输入排查坐标:");
		int scanf_number = scanf("%d %d", &x, &y);

		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (show[x][y] == '*')//如果是之前没有排查过就继续往后走
			{
				if (mine[x][y] == '1')//是雷
				{
					printf("你被炸死了\n");
					DisplayBoard(mine, ROW, COL);
					break;
				}
				else//不是雷
				{
					int count = GetMineCount(mine, x, y);
					show[x][y] = count + '0';//同步
					DisplayBoard(show, ROW, COL);
					win++;
				}
			}
			else//之前排查过了…
			{
				printf("该已经被排查过了!!!\n");//如果不加上这个上面的win会被多加！！！
			}
		}
		else
		{
			printf("输入非法,请重新输入\n");
		}
		if (win == row * col - EASY_COUNT)
		{
			printf("恭喜你扫雷成功\n");
		}
	}
}
//函数主体
void game()
{
	srand((unsigned int)time(NULL));//这个随机函数放在前面比较好，不然程序运行时间很慢
	char mine[ROWS][COLS] = { 0 };//存放布置好雷的信息（0/1区分）
	char show[ROWS][COLS] = { 0 };//存放排查雷后的信息
	//初始化数组
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	//打印棋盘
	DisplayBoard(show, ROW, COL);
	//布置雷
	SetMine(mine, ROW, COL);//开发者作弊的函数：DisplayBoard(mine, ROW, COL);
	//排查雷
	FindMine(mine, show, ROW, COL);
}
