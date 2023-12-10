//1.ͷ�ļ�����ͺ�����
#pragma once
#pragma warning(disable:4996)

#include <easyx.h>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define _CRT_SECURE_NO_WARNINGS 1			//��� VS2022 �� scanf() ��������

#define NODE_WIDTH 60						//����С��ͨ������С�����������Ѷ�)
#define WINDOW_LENGTH 800					//���峤��
#define WINDOW_WIDTH 600					//������

#define SNAKE_LENGTH 5						//�߳�ʼ����
#define SNAKE_MAX_LENGTH 50					//����󳤶�
#define SNAKE_SPEED 500						//�߳�ʼ�ٶ�

#define SNAKE_HEAD_COLOUR RGB(254, 67, 101)			//��ͷ��ɫ
#define SNAKE_BODY_COLOUR RGB(252, 157, 154)		//������ɫ
#define SNAKE_BODY_EDGE_COLOUR RGB(252, 157, 154)	//���������ɫ
#define FOOD_COLOUR RGB(200, 200, 169)				//ʳ����ɫ
#define WINDOW_COLOUR RGB(249, 205, 173)			//������ɫ

#define TEXT_COLOUR RGB(0, 0, 0)					//������ɫ
#define TEXE_STYLE "Consolas"						//���ַ��


//2.�ṹ����֯
//�������ṹ��
typedef struct
{
	int x;
	int y;
} node;

//����ö����
enum direction
{
	eUp,	//��(0)
	eDown,	//��(1)
	eLeft,	//��(2)
	eRight	//��(3)
};

//3.��غ�������
//��ʼ������
void GameInit();

//��������
void PrintGrid();

//����������
node SnakeMove(node* snake, int snakeLength, direction dir);

//������
void PrintSnake(node* snake, int snakeLength);

//������뷽��
void ChangeDirection(enum direction* pD);

//����ʳ������
node CreateFood(node* snake, int snakeLength);

//����ʳ��
void PaintFood(node food);

//�����Ϸ��������
bool IsGameOver(node* snake, int snakeLength);

//��λ������
void Reset(node* snake, int* pLength, enum direction* dir);

//������Ϸ��Ϣ
void PrintMessages(int eatingTimes, int failTimes);