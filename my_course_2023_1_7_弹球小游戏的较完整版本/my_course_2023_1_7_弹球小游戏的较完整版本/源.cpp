#define _CRT_SECURE_NO_WARNINGS 1
#define NUM_OF_BALLS 100
#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
#include<easyx.h>
typedef struct//小球数据
{
	int x;//小球的坐标x
	int y;//小球的坐标y
	int vx;//小球的x方向速度
	int vy;//小球的y方向速度
	COLORREF color;
}ball;

int main()
{
	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	initgraph(800, 600, EX_SHOWCONSOLE);//创建窗口
	setorigin(400, 300);//设计逻辑坐标原点（400，300）
	setaspectratio(1, -1);//翻转y轴
	setbkcolor(RGB(164, 225, 202));//设置背景颜色属性
	cleardevice();//重新用背景颜色属性来粉刷背景
	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	ball balls[NUM_OF_BALLS];//小球数据数组
	int r = 10;//小球的半径

	return 0;
}