#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>//标准输出输入头文件
#include<easyx.h>//easyx的外部头文件
#include<math.h>//数学头文件
#include<windows.h>//windows头文件
#include<conio.h>//刷新输入的头文件
#include<stdlib.h>//随机数的头文件
#include<time.h>//辅助srand生成较好的随机数
void putTransparentImage(int x, int y, const IMAGE* mask, const IMAGE* img)
{//（绘制位置的xy坐标，掩码指针，黑底本体指针）
	putimage(x, y, mask, SRCAND);
	putimage(x, y, img, SRCPAINT);
}
int main()
{
	initgraph(800, 600);//绘制窗口

	setbkcolor(WHITE);//设置白色背景
	cleardevice();//清空屏幕

	setbkmode(TRANSPARENT);
	settextcolor(RED);//设置字体颜色
	settextstyle(40, 0, "微软雅黑");//设置字体风格

	const char* pText = "Hellow phigros|你好，phigros";
	outtextxy(180, 280, pText);
	int o = getchar();
	

	initgraph(700, 400);
	//设置好逻辑坐标原点
	setorigin(350, 200);
	//无翻转坐标
	setaspectratio(1, 1);

	IMAGE imgBackground;
	loadimage(&imgBackground, "./背景.jpg", 700, 400, true);

	IMAGE imgshort;
	loadimage(&imgshort, "./短键.png", 90, 10, true);

	IMAGE imgshortMask;
	loadimage(&imgshortMask, "./短键掩码.png", 90, 10, true);

	BeginBatchDraw();
	for (int i = -200; i < 0; i += 5)
	{
		putimage(-350, -200, &imgBackground);//背景图片
		putTransparentImage(-60, i, &imgshortMask, &imgshort);
		FlushBatchDraw();
		Sleep(5);
		putimage(-350, -200, &imgBackground);//背景图片
	}
	for (int i = -200; i < 0; i += 5)
	{
		putimage(-350, -200, &imgBackground);//背景图片
		putTransparentImage(0, i, &imgshortMask, &imgshort);
		FlushBatchDraw();
		Sleep(5);
		putimage(-350, -200, &imgBackground);//背景图片
	}
	for (int i = -200; i < 0; i += 5)
	{
		putimage(-350, -200, &imgBackground);//背景图片
		putTransparentImage(-120, i, &imgshortMask, &imgshort);
		FlushBatchDraw();
		Sleep(10);
		putimage(-350, -200, &imgBackground);//背景图片
	}
	for (int i = -200; i < 0; i += 5)
	{
		putimage(-350, -200, &imgBackground);//背景图片
		putTransparentImage(-120, i, &imgshortMask, &imgshort);
		FlushBatchDraw();
		Sleep(10);
		putimage(-350, -200, &imgBackground);//背景图片
	}
	for (int i = -200; i < 0; i += 5)
	{
		putimage(-350, -200, &imgBackground);//背景图片
		putTransparentImage(-120, i, &imgshortMask, &imgshort);
		FlushBatchDraw();
		Sleep(10);
		putimage(-350, -200, &imgBackground);//背景图片
	}
	for (int i = -200; i < 0; i += 5)
	{
		putimage(-350, -200, &imgBackground);//背景图片
		putTransparentImage(0, i, &imgshortMask, &imgshort);
		FlushBatchDraw();
		Sleep(10);
		putimage(-350, -200, &imgBackground);//背景图片
	}

	for (int i = -200; i < 0; i += 5)
	{
		putimage(-350, -200, &imgBackground);//背景图片
		putTransparentImage(100, i, &imgshortMask, &imgshort);
		FlushBatchDraw();
		Sleep(10);
		putimage(-350, -200, &imgBackground);//背景图片
	}
	EndBatchDraw();//<以后可以尝试封装好这个函数>

	o = getchar();
	closegraph();
	return 0;
}