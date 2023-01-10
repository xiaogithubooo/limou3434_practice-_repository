#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>//标准输出输入头文件
#include<easyx.h>//easyx的外部头文件
#include<math.h>//数学头文件
#include<windows.h>//windows头文件
#include<conio.h>//刷新输入的头文件
#include<stdlib.h>//随机数的头文件
#include<time.h>//辅助srand生成较好的随机数

#define NUM_OF_BALLS 30//小球的数量
#define PI 3.1415926

typedef struct {//小球的数据
    int x;
    int y;
    int vx;
    int vy;
    COLORREF color;//小球的颜色
}ball;

int main()
{
    //绘制画布
    initgraph(800, 600);
    //设置好逻辑坐标原点
    setorigin(400, 300);
    //翻转坐标
    setaspectratio(1, -1);
    //设置背景色
    setlinecolor(WHITE);
    //设置描边颜色
    setlinecolor(BLACK);
    //使用背景色清空窗体
    cleardevice();
    ball* balls = (ball*)malloc(sizeof(ball) * NUM_OF_BALLS);//修改数组（自动变量）为动态内存
    //ball balls[NUM_OF_BALLS];//存储100个小球的数据
    int r = 20;//小球的半径
    for (int i = 0; i < NUM_OF_BALLS; i++)
    {
        int m, n;
        //x坐标
        m = -400 + r;
        n = 400 - r;
        balls[i].x = rand() % (n - m + 1) + m;
        //y坐标
        m = -300 + r;
        n = 300 - r;
        balls[i].y = rand() % (n - m + 1) + m;
        //随机颜色
        balls[i].color = HSVtoRGB((float)(rand() % 360), 0.8f, 0.9f);
        //随机速度
        m = 3;
        n = 8;
        int v = rand() % (n - m + 1) + m;
        //随机速度角度
        double theta;
        theta = rand() % 360;
        //速度分量
        balls[i].vx = v * cos(theta * PI / 180);
        balls[i].vy = v * sin(theta * PI / 180);
        //小球机制
    }

    BeginBatchDraw();//<开启批量绘图>

    while (1)
    {
        cleardevice();//<清除上一个小球的状态>

        for (int i = 0; i < NUM_OF_BALLS; i++)
        {
            setfillcolor(balls[i].color);//<小球填充颜色>
            fillcircle(balls[i].x, balls[i].y, r);//<生成小球>
        }

        FlushBatchDraw();//<累计多个小球后才开始绘画>

        Sleep(40);

        for (int i = 0; i < NUM_OF_BALLS; i++)//<小球反弹>
        {
            if (balls[i].y >= 300 - r || balls[i].y <= -300 + r)
            {
                balls[i].vy = -balls[i].vy;
            }
            if (balls[i].x <= -400 + r || balls[i].x >= 400 - r)
            {
                balls[i].vx = -balls[i].vx;
            }

            balls[i].x += balls[i].vx;//<给小球加速度分量，使小球移动>
            balls[i].y += balls[i].vy;
        }
    }

    EndBatchDraw();//<关闭批量绘画>

    closegraph();//关闭窗体
    return 0;
}