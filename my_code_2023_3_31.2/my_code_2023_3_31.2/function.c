#define _CRT_SECURE_NO_WARNINGS 1
#include "function.h"
//��Ϸ�˵�
void menu(void)
{
	printf("**************************************\n");
	printf("*************** 1.play ***************\n");
	printf("*************** 0.exit ***************\n");
	printf("**************************************\n");
}
//��ʼ������
void InitBoard(char board[ROW][COL], int row, int col)
{
	memset(&board[0][0], ' ', row * col * sizeof(board[0][0]));//ͷ�ļ���string.h
}
//��ӡ��ʾ����
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

//��Ϸ����
void game(void)
{
	char board[ROW][COL] = { 0 };
	//��ʼ������
	InitBoard(board, ROW, COL);
	//��ӡ��ʾ����
	DisplayBoard(board, ROW, COL);
	while (1)
	{
		//�������
		
		//��ӡ����
		
		//�ж���Ӯ
		
		//��������
		
		//��ӡ����
		
		//�ж���Ӯ
	}
}