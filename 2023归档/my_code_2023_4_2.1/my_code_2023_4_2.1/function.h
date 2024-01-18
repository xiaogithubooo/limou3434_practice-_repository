#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 9
#define COL 9
#define ROWS ROW + 2
#define COLS COL + 2
#define EASY_COUNT 10//雷数
//菜单函数
void menu(void);
//初始化函数
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);
//打印函数
void DisplayBoard(char board[ROWS][COLS], int row, int col);
//布置雷函数
void SetMine(char mine[ROWS][COLS], int row, int col);
//排查雷
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
//函数主体
void game();