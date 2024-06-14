// ͷ�ļ�����ͺ�����
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

#define NODE_WIDTH 50						//����С��ͨ������С�����������Ѷ�)
#define WINDOW_LENGTH 800					//���峤��
#define WINDOW_WIDTH 600					//������

#define SNAKE_LENGTH 5						//�߳�ʼ����
#define SNAKE_MAX_LENGTH 25					//����󳤶�
#define SNAKE_SPEED 500						//�߳�ʼ�ٶ�

#define SNAKE_HEAD_COLOUR RGB(254, 67, 101)			//��ͷ��ɫ
#define SNAKE_BODY_COLOUR RGB(252, 157, 154)		//������ɫ
#define SNAKE_BODY_EDGE_COLOUR RGB(252, 157, 154)	//���������ɫ
#define FOOD_COLOUR RGB(200, 200, 169)				//ʳ����ɫ
#define WINDOW_COLOUR RGB(249, 205, 173)			//������ɫ

#define TEXT_COLOUR RGB(0, 0, 0)					//������ɫ
#define TEXE_STYLE "Consolas"						//���ַ��


// �ṹ����֯
/**
 * @brief �������ṹ��
 */
struct node {
    int x; //< x ����
    int y; //< y ����
};

/**
 * @brief ����ö����
 */
enum direction {
    eUp,    //< ��(0)
    eDown,  //< ��(1)
    eLeft,  //< ��(2)
    eRight  //< ��(3)
};

// ��غ�������
/**
 * @brief �����ʼ������
 */
void InterfaceInit();

/**
 * @brief �߳�ʼ������
 * @param snakeLength �߳���
 * @param dir ���ƶ�����
 */
void SnakeInit(int& snakeLength, direction& dir);

/**
 * @brief ʳ���ʼ������
 * @param snake ����������
 * @param snakeLength �߳���
 * @param food ʳ������
 */
void FoodInit(node* snake, int& snakeLength, node& food);

/**
 * @brief ����������
 */
void PrintGrid();

/**
 * @brief ���������꺯��
 * @param snake ����������
 * @param snakeLength �߳���
 * @param dir ���ƶ�����
 * @return ���º����ͷ����
 */
node SnakeMove(node* snake, int snakeLength, direction dir);

/**
 * @brief �����ߺ���
 * @param snake ����������
 * @param snakeLength �߳���
 */
void PrintSnake(node* snake, int snakeLength);

/**
 * @brief ����¼�����
 * @param d ��⵽�ķ���
 * @return �Ƿ��⵽�¼�
 */
bool DetectionEvent(direction& d);

/**
 * @brief ����ʳ�����꺯��
 * @param snake ����������
 * @param snakeLength �߳���
 * @return ʳ������
 */
node CreateFood(node* snake, const int& snakeLength);

/**
 * @brief ����ʳ�ﺯ��
 * @param food ʳ������
 */
void PaintFood(const node& food);

/**
 * @brief �����Ϸ������������
 * @param snake ����������
 * @param snakeLength �߳���
 * @return �Ƿ���Ϸ����
 */
bool IsGameOver(node* snake, const int& snakeLength);

/**
 * @brief ��λ�����ݺ���
 * @param snake ����������
 * @param pLength �߳���
 * @param dir ���ƶ�����
 */
void Reset(node* snake, int& pLength, direction& dir);

/**
 * @brief ������Ϸ��Ϣ����
 * @param eatingTimes �Ե�ʳ��Ĵ���
 * @param failTimes ʧ�ܴ���
 */
void PrintMessages(const int& eatingTimes, const int& failTimes);

/**
 * @brief ������Ϸ��Դ����
 */
void Destruction();

/**
 * @brief �޸���Ϸ��ɫ
 * @param red ��
 * @param green ��
 * @param blue ��
 */
void ModGameColor(const int& red, const int& green, const int& blue);
