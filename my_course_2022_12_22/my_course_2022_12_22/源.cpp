#define _CRT_SECURE_NO_WARNINGS 1
#include<easyx.h>
#include<stdio.h>
void my_DLAM()
{
	setlinecolor(BLACK);//大脸
	setfillcolor(BLUE);
	fillellipse(-250, 240, 250, -240);

	setlinecolor(BLACK);//小脸
	setfillcolor(WHITE);
	fillellipse(-200, 150, 200, -240);

	setlinecolor(BLACK);//左右两眼
	setfillcolor(WHITE);
	fillellipse(-80, 200, 0, 90);

	setlinecolor(BLACK);
	setfillcolor(WHITE);
	fillellipse(0, 200, 80, 90);

	setlinecolor(BLACK);//左右眼球
	setfillcolor(BLACK);
	fillcircle(-40,120,10);

	setlinecolor(BLACK);
	setfillcolor(BLACK);
	fillcircle(40, 120, 10);

	setlinecolor(BLACK);//鼻子
	setfillcolor(RED);
	fillcircle(0, 80, 20);

	//鼻线
	line(0, 60, 0, -200);

	//嘴巴
	arc(-100, -80, 100, -200, 0, 3.14);

	//猫须
	line(-250, 150, -130, 80);
	line(-280, 80, -140, 50);
	line(-280, 10, -150, 20);

	line(250, 150, 130, 80);
	line(280, 80, 140, 50);
	line(280, 10, 150, 20);
}
int main()
{
	//初始化绘图窗口（并且显示控制台）, 中心点是（512，512）
	initgraph(1000, 1000, EX_SHOWCONSOLE);

	//设置背景颜色
	setbkcolor(WHITE);
	cleardevice();//用背景色清屏

	//设置逻辑坐标原点，并且翻转坐标
	setorigin(512, 512);//设置逻辑中心原点
	setaspectratio(1, -1);//翻转y轴

	//绘制哆啦A梦函数
	my_DLAM();

	//设置任意键退出，防止闪屏
	getchar();//接收任意按键
	closegraph();//关闭绘图窗口函数
	return 0;
}