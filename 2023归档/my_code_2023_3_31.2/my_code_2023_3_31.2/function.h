#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define ROW 3
#define COL 3
//��Ϸ�˵�
void menu(void);
//��ʼ������
void InitBoard(char board[ROW][COL], int row, int col);
//��ӡ��ʾ����
void DisplayBoard(char board[ROW][COL], int row, int col);
//�������
void PlayerMove(char board[ROW][COL], int row, int col);
//��������
void ComputerMove(char board[ROW][COL], int row, int col);
//�ж���Ӯ
char Iswin(char board[ROW][COL], int row, int col);
//��Ϸ����
void game(void);
