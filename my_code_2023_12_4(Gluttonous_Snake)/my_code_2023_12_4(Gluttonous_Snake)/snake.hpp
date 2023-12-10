//1.头文件导入和宏设置
#pragma once
#pragma warning(disable:4996)

#include <easyx.h>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define _CRT_SECURE_NO_WARNINGS 1			//解决 VS2022 的 scanf() 禁用问题

#define NODE_WIDTH 60						//格点大小（通过格点大小调整格数和难度)
#define WINDOW_LENGTH 800					//窗体长度
#define WINDOW_WIDTH 600					//窗体宽度

#define SNAKE_LENGTH 5						//蛇初始长度
#define SNAKE_MAX_LENGTH 50					//蛇最大长度
#define SNAKE_SPEED 500						//蛇初始速度

#define SNAKE_HEAD_COLOUR RGB(254, 67, 101)			//蛇头颜色
#define SNAKE_BODY_COLOUR RGB(252, 157, 154)		//蛇身颜色
#define SNAKE_BODY_EDGE_COLOUR RGB(252, 157, 154)	//蛇身外边颜色
#define FOOD_COLOUR RGB(200, 200, 169)				//食物颜色
#define WINDOW_COLOUR RGB(249, 205, 173)			//背景颜色

#define TEXT_COLOUR RGB(0, 0, 0)					//文字颜色
#define TEXE_STYLE "Consolas"						//文字风格


//2.结构体组织
//相对坐标结构体
typedef struct
{
	int x;
	int y;
} node;

//方向枚举体
enum direction
{
	eUp,	//上(0)
	eDown,	//下(1)
	eLeft,	//左(2)
	eRight	//右(3)
};

//3.相关函数声明
//初始化窗口
void GameInit();

//绘制网格
void PrintGrid();

//更新蛇坐标
node SnakeMove(node* snake, int snakeLength, direction dir);

//绘制蛇
void PrintSnake(node* snake, int snakeLength);

//检查输入方向
void ChangeDirection(enum direction* pD);

//生成食物坐标
node CreateFood(node* snake, int snakeLength);

//绘制食物
void PaintFood(node food);

//检测游戏结束条件
bool IsGameOver(node* snake, int snakeLength);

//复位蛇数据
void Reset(node* snake, int* pLength, enum direction* dir);

//绘制游戏信息
void PrintMessages(int eatingTimes, int failTimes);