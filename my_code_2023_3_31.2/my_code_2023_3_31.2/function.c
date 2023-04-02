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
	memset(&board[0][0], ' ', row * col * sizeof(board[0][0]));//ͷ�ļ���string.h��ע������ո����н�����
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
//�������
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0, y = 0;
	while (1)
	{
		printf("������塪��");
		printf("��������������(\"��\"��\"��\"):");
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
				printf("�˴��Ѿ�������,��������,����������!!!\n");
			}
		}
	}
}
//��������
void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("�������塪��");
	printf("��������������(\"��\"��\"��\"):");
	srand((unsigned int)time(NULL));
	while (1)
	{
		x = rand() % row;//ע������ı�д
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			printf("%d %d\n", x, y);
			board[x][y] = '#';
			break;
		}
	}
}
//�ж���Ӯ
int IsFull(char board[ROW][COL], int row, int col);//�����������ж��Ƿ�Ʊ��
char Iswin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)//���ж�
	{
		if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != ' ')
		{
			return board[i][0];
		}
	}
	for (i = 0; i < row; i++)//���ж�
	{
		if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != ' ')
		{
			return board[i][0];
		}
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')//���ж�
	{
		return board[1][1];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')//Ʋ�ж�
	{
		return board[1][1];
	}
	if (IsFull(board, row, col))//�ж��Ƿ�ƽ��
	{
		return 'Q';
	}
	return 'C';//��Ϸ����
}
int IsFull(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;//û��ƽ��
			}
		}
	}
	return 1;
}

//��Ϸ����
void game(void)
{
	char board[ROW][COL] = { 0 };
	char ret = 0;
	//��ʼ������
	InitBoard(board, ROW, COL);
	//��ӡ��ʾ����
	DisplayBoard(board, ROW, COL);
	while (1)
	{
		//�������
		PlayerMove(board, ROW, COL);
		//��ӡ����
		DisplayBoard(board, ROW, COL);
		//�ж���Ӯ
		ret = Iswin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		//��������
		ComputerMove(board, ROW, COL);
		//��ӡ����
		DisplayBoard(board, ROW, COL);
		//�ж���Ӯ
		ret = Iswin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("���Ӯ\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ\n");
	}
	else if (ret == 'Q')
	{
		printf("ƽ��\n");
	}
}