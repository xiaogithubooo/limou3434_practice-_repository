#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>//标准输出输入头文件
#include<easyx.h>//easyx的外部头文件
#include<math.h>//数学头文件
#include<windows.h>//windows头文件
#include<conio.h>//刷新输入的头文件
#include<stdlib.h>//随机数的头文件
#include<time.h>//辅助rand生成较好的随机数
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
/*直线运动函数*///<其实这里没有用到这个函数呢……>
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
		solidcircle((int)x, (int)y, 25);//画圆

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
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
/*初始化挡板绘制坐标*/
int barLeft = -150, barRight = 150, barTop = -280, barBottom = -300;
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//“反弹的本质就是一个速度分量方向发生了改变（相反）”
int main()
{
	initgraph(800, 600, EX_SHOWCONSOLE);//创建窗口
	setorigin(400, 300);//设计逻辑坐标原点（400，300）
	setaspectratio(1, -1);//翻转y轴
	setbkcolor(RGB(164, 225, 202));//设置背景颜色属性
	cleardevice();//重新用背景颜色属性来粉刷背景
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	int x = 0, y = 0, r = 40;//圆出现在中点（0，0），半径40像素
	int vx = 5, vy = 5;//小球的设定分速度
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	int i = 0;//记录失败次数
	while (1)
	{
		cleardevice();//刷新壁纸
		solidcircle(x, y, r);//画圆
		solidrectangle(barLeft, barTop, barRight, barBottom);//画一个挡板
		Sleep(15);//停顿40毫秒
		if (y >= 300 - 40)//上反弹（下反弹交予玩家）
		{
			vy = -vy;
		}
		if (x >= 400 - 40 || x <= -400 + 40)//左右反弹
		{
			vx = -vx;
		}
		if (barLeft <= x && x <= barRight && y <= barTop + r)//撞击到挡板就反弹
		{
			vy = -vy;
		}
		if (y <= -300)//判断游戏失败
		{
			i++;//累计失败次数
			printf("\a游戏失败%d次\n", i);
			srand((unsigned)time(NULL));//辅助rand生成真随机数
			x = rand() % (400 + 1) - 200;//随机复位圆心坐标
			y = rand() % (300 + 1) - 150;

			vx = 5;//复位速度分量大小 
			vy = 5;

			if (rand() % 2 == 0)//随机速度分量的方向
			{
				vy = -vy;
			}
			if (rand() % 2 == 0)
			{
				vx = -vx;
			}

			barLeft = -150;//复位挡板
			barRight = 150;
			barTop = -280;
			barBottom = -300;
		}//<当然这段代码也可以在第一次就开始执行>

		x += vx;//向右上方移动
		y += vy;

		//获取键盘输入，对挡板进行修改
		if (_kbhit() != 0)
		{
			char c = _getch();
			if (c == 'a')//挡板左移
			{
				if (barLeft > -400)
				{
					barLeft -= 20;
					barRight -= 20;
				}
			}
			else if(c=='d')//挡板右移
			{
				if (barRight < 400)
				{
					barLeft += 20;
					barRight += 20;
				}
			}
			else if (c == 'q')
			{
				break;
			}
		}
	}
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	printf("您已成功退出游戏\n");
	getchar();
	closegraph();//关闭窗体
	return 0;
}
//<可以尝试把所有变量封装为一个结构体，取名my_GameDatd>
//<可以尝试将所有rand的初始化变成一个随机初始化函数reset>
//<游戏分数机制和统计游戏结束分数>
//<将分数利用文件函数储存起来，方便用户打开>
//<增加坚持弹球计时时间>
//<做可消除砖块>
//<做多个小球>
//<逐步提升小球难度>
//<选择关卡难度>