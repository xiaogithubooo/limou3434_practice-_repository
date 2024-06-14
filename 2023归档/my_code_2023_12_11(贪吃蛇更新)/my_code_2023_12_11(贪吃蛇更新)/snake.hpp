// 头文件导入和宏设置
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

#define NODE_WIDTH 50						//格点大小（通过格点大小调整格数和难度)
#define WINDOW_LENGTH 800					//窗体长度
#define WINDOW_WIDTH 600					//窗体宽度

#define SNAKE_LENGTH 5						//蛇初始长度
#define SNAKE_MAX_LENGTH 25					//蛇最大长度
#define SNAKE_SPEED 500						//蛇初始速度

#define SNAKE_HEAD_COLOUR RGB(254, 67, 101)			//蛇头颜色
#define SNAKE_BODY_COLOUR RGB(252, 157, 154)		//蛇身颜色
#define SNAKE_BODY_EDGE_COLOUR RGB(252, 157, 154)	//蛇身外边颜色
#define FOOD_COLOUR RGB(200, 200, 169)				//食物颜色
#define WINDOW_COLOUR RGB(249, 205, 173)			//背景颜色

#define TEXT_COLOUR RGB(0, 0, 0)					//文字颜色
#define TEXE_STYLE "Consolas"						//文字风格


// 结构体组织
/**
 * @brief 相对坐标结构体
 */
struct node {
    int x; //< x 坐标
    int y; //< y 坐标
};

/**
 * @brief 方向枚举体
 */
enum direction {
    eUp,    //< 上(0)
    eDown,  //< 下(1)
    eLeft,  //< 左(2)
    eRight  //< 右(3)
};

// 相关函数声明
/**
 * @brief 界面初始化函数
 */
void InterfaceInit();

/**
 * @brief 蛇初始化函数
 * @param snakeLength 蛇长度
 * @param dir 蛇移动方向
 */
void SnakeInit(int& snakeLength, direction& dir);

/**
 * @brief 食物初始化函数
 * @param snake 蛇坐标数组
 * @param snakeLength 蛇长度
 * @param food 食物坐标
 */
void FoodInit(node* snake, int& snakeLength, node& food);

/**
 * @brief 绘制网格函数
 */
void PrintGrid();

/**
 * @brief 更新蛇坐标函数
 * @param snake 蛇坐标数组
 * @param snakeLength 蛇长度
 * @param dir 蛇移动方向
 * @return 更新后的蛇头坐标
 */
node SnakeMove(node* snake, int snakeLength, direction dir);

/**
 * @brief 绘制蛇函数
 * @param snake 蛇坐标数组
 * @param snakeLength 蛇长度
 */
void PrintSnake(node* snake, int snakeLength);

/**
 * @brief 检查事件函数
 * @param d 检测到的方向
 * @return 是否检测到事件
 */
bool DetectionEvent(direction& d);

/**
 * @brief 生成食物坐标函数
 * @param snake 蛇坐标数组
 * @param snakeLength 蛇长度
 * @return 食物坐标
 */
node CreateFood(node* snake, const int& snakeLength);

/**
 * @brief 绘制食物函数
 * @param food 食物坐标
 */
void PaintFood(const node& food);

/**
 * @brief 检测游戏结束条件函数
 * @param snake 蛇坐标数组
 * @param snakeLength 蛇长度
 * @return 是否游戏结束
 */
bool IsGameOver(node* snake, const int& snakeLength);

/**
 * @brief 复位蛇数据函数
 * @param snake 蛇坐标数组
 * @param pLength 蛇长度
 * @param dir 蛇移动方向
 */
void Reset(node* snake, int& pLength, direction& dir);

/**
 * @brief 绘制游戏信息函数
 * @param eatingTimes 吃到食物的次数
 * @param failTimes 失败次数
 */
void PrintMessages(const int& eatingTimes, const int& failTimes);

/**
 * @brief 销毁游戏资源函数
 */
void Destruction();

/**
 * @brief 修改游戏颜色
 * @param red 红
 * @param green 绿
 * @param blue 蓝
 */
void ModGameColor(const int& red, const int& green, const int& blue);
