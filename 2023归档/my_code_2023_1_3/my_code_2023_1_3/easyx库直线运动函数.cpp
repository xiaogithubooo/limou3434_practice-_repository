#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<easyx.h>
#include<math.h>
#include<windows.h>
void LinearMotion(int x1, int y1, int x2, int y2, int v)
{
	double vy, vx;
	if (y2 == y1)
	{
		vx = v;
		vy = 0;
	}
	else if (x2 == x1)
	{
		vx = 0;
		vy = v;
	}
	else
	{
		double tanTheta = (double)abs(y2 - y1) / (double)abs(x2 - x1);
		double theta = atan(tanTheta);//求出角度

		vy = sin(theta) * v;
		vx = cos(theta) * v;//求出x、y分速度
	}

	

	int vxFlag = 0;
	int vyFlag = 0;
	if (x2 - x1 > 0)
	{
		vxFlag = 1;
	}
	else if (x2 - x1 < 0)
	{
		vxFlag = -1;
	}
	if (y2 - y1 > 0)
	{
		vyFlag = 1;
	}
	else if (y2 - y1 < 0)
	{
		vyFlag = -1;
	}
	if (vxFlag == 0 && vyFlag == 0)
	{
		return;
	}

	vx = vx * vxFlag;
	vy = vy * vyFlag;//赋予速度方向

	double x, y;
	x = x1;
	y = y1;//起始点坐标

	while (1)
	{
		cleardevice();
		solidcircle(x, y, 25);//画圆
		Sleep(10);
		x += vx;
		y += vy;//将速度赋予给坐标，使得形状动起来

		if (vxFlag == 1)
		{
			if (x >= x2)
				break;
		}
		else if (vxFlag == -1)
		{
			if (x <= x2)
				break;
		}
		if (vyFlag == 1)
		{
			if (y >= y2)
				break;
		}
		else if (vyFlag == -1)
		{
			if (y <= y2)
				break;
		}//设定结束运动
	}
}

int main()
{
	initgraph(800, 600);
	setorigin(400, 300);
	setaspectratio(1, -1);//翻转坐标轴

	setbkcolor(RGB(164, 225, 202));
	cleardevice();

	
	{
		LinearMotion(0, 200, 200, -200, 5);
		LinearMotion(200, -200, -200, -200, 5);
		LinearMotion(-200, -200, 0, 200, 5);

		LinearMotion(0, 200, 0, -200, 5);

		LinearMotion(0, -200, -200, 200, 5);
		LinearMotion(-200, 200, 200, 200, 5);
		LinearMotion(200, 200, 0, -200, 5);

		LinearMotion(0, -200, -200, 200, 5);

		LinearMotion(-200, 200, 200, 200, 5);
		LinearMotion(200, 200, 200, -200, 5);
		LinearMotion(200, -200, -200, -200, 5);
		LinearMotion(-200, -200, -200, 200, 5);
	}

	getchar();
	closegraph();
	return 0;
}