#define _CRT_SECURE_NO_WARNINGS 1
#define NUM_OF_BALLS 100
#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
#include<easyx.h>
typedef struct//С������
{
	int x;//С�������x
	int y;//С�������y
	int vx;//С���x�����ٶ�
	int vy;//С���y�����ٶ�
	COLORREF color;
}ball;

int main()
{
	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	initgraph(800, 600, EX_SHOWCONSOLE);//��������
	setorigin(400, 300);//����߼�����ԭ�㣨400��300��
	setaspectratio(1, -1);//��תy��
	setbkcolor(RGB(164, 225, 202));//���ñ�����ɫ����
	cleardevice();//�����ñ�����ɫ��������ˢ����
	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	ball balls[NUM_OF_BALLS];//С����������
	int r = 10;//С��İ뾶

	return 0;
}