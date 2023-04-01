#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#define ROW 3
#define COL 3
//游戏菜单
void menu(void);
//初始化棋盘
void InitBoard(char board[ROW][COL], int row, int col);
//打印显示棋盘
void DisplayBoard(char board[ROW][COL], int row, int col);

//游戏主体
void game(void);
