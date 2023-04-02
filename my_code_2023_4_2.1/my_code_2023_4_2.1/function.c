#define _CRT_SECURE_NO_WARNINGS 1
#include "function.h"
//�˵�����
void menu(void)
{
	printf("------------------------\n");
	printf("-------  1.play  -------\n");
	printf("-------  0.exit  -------\n");
	printf("------------------------\n");
}
//��ʼ������
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
//��ӡ����
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	printf("-------ɨ��--------\n");
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
//�����׺���
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
//�Ų���
int GetMineCount(char mine[ROWS][COLS], int x, int y)//��������
{
	return (mine[x - 1][y] +//��һ���ܾ���
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
		printf("�����Ų�����:");
		int scanf_number = scanf("%d %d", &x, &y);

		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (show[x][y] == '*')//�����֮ǰû���Ų���ͼ���������
			{
				if (mine[x][y] == '1')//����
				{
					printf("�㱻ը����\n");
					DisplayBoard(mine, ROW, COL);
					break;
				}
				else//������
				{
					int count = GetMineCount(mine, x, y);
					show[x][y] = count + '0';//ͬ��
					DisplayBoard(show, ROW, COL);
					win++;
				}
			}
			else//֮ǰ�Ų���ˡ�
			{
				printf("���Ѿ����Ų����!!!\n");//�����������������win�ᱻ��ӣ�����
			}
		}
		else
		{
			printf("����Ƿ�,����������\n");
		}
		if (win == row * col - EASY_COUNT)
		{
			printf("��ϲ��ɨ�׳ɹ�\n");
		}
	}
}
//��������
void game()
{
	srand((unsigned int)time(NULL));//��������������ǰ��ȽϺã���Ȼ��������ʱ�����
	char mine[ROWS][COLS] = { 0 };//��Ų��ú��׵���Ϣ��0/1���֣�
	char show[ROWS][COLS] = { 0 };//����Ų��׺����Ϣ
	//��ʼ������
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	//��ӡ����
	DisplayBoard(show, ROW, COL);
	//������
	SetMine(mine, ROW, COL);//���������׵ĺ�����DisplayBoard(mine, ROW, COL);
	//�Ų���
	FindMine(mine, show, ROW, COL);
}
