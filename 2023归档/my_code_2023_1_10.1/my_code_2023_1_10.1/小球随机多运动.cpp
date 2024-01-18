#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>//��׼�������ͷ�ļ�
#include<easyx.h>//easyx���ⲿͷ�ļ�
#include<math.h>//��ѧͷ�ļ�
#include<windows.h>//windowsͷ�ļ�
#include<conio.h>//ˢ�������ͷ�ļ�
#include<stdlib.h>//�������ͷ�ļ�
#include<time.h>//����srand���ɽϺõ������

#define NUM_OF_BALLS 30//С�������
#define PI 3.1415926

typedef struct {//С�������
    int x;
    int y;
    int vx;
    int vy;
    COLORREF color;//С�����ɫ
}ball;

int main()
{
    //���ƻ���
    initgraph(800, 600);
    //���ú��߼�����ԭ��
    setorigin(400, 300);
    //��ת����
    setaspectratio(1, -1);
    //���ñ���ɫ
    setlinecolor(WHITE);
    //���������ɫ
    setlinecolor(BLACK);
    //ʹ�ñ���ɫ��մ���
    cleardevice();
    ball* balls = (ball*)malloc(sizeof(ball) * NUM_OF_BALLS);//�޸����飨�Զ�������Ϊ��̬�ڴ�
    //ball balls[NUM_OF_BALLS];//�洢100��С�������
    int r = 20;//С��İ뾶
    for (int i = 0; i < NUM_OF_BALLS; i++)
    {
        int m, n;
        //x����
        m = -400 + r;
        n = 400 - r;
        balls[i].x = rand() % (n - m + 1) + m;
        //y����
        m = -300 + r;
        n = 300 - r;
        balls[i].y = rand() % (n - m + 1) + m;
        //�����ɫ
        balls[i].color = HSVtoRGB((float)(rand() % 360), 0.8f, 0.9f);
        //����ٶ�
        m = 3;
        n = 8;
        int v = rand() % (n - m + 1) + m;
        //����ٶȽǶ�
        double theta;
        theta = rand() % 360;
        //�ٶȷ���
        balls[i].vx = v * cos(theta * PI / 180);
        balls[i].vy = v * sin(theta * PI / 180);
        //С�����
    }

    BeginBatchDraw();//<����������ͼ>

    while (1)
    {
        cleardevice();//<�����һ��С���״̬>

        for (int i = 0; i < NUM_OF_BALLS; i++)
        {
            setfillcolor(balls[i].color);//<С�������ɫ>
            fillcircle(balls[i].x, balls[i].y, r);//<����С��>
        }

        FlushBatchDraw();//<�ۼƶ��С���ſ�ʼ�滭>

        Sleep(40);

        for (int i = 0; i < NUM_OF_BALLS; i++)//<С�򷴵�>
        {
            if (balls[i].y >= 300 - r || balls[i].y <= -300 + r)
            {
                balls[i].vy = -balls[i].vy;
            }
            if (balls[i].x <= -400 + r || balls[i].x >= 400 - r)
            {
                balls[i].vx = -balls[i].vx;
            }

            balls[i].x += balls[i].vx;//<��С����ٶȷ�����ʹС���ƶ�>
            balls[i].y += balls[i].vy;
        }
    }

    EndBatchDraw();//<�ر������滭>

    closegraph();//�رմ���
    return 0;
}