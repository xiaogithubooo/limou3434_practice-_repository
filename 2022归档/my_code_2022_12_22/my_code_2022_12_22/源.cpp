#define _CRT_SECURE_NO_WARNINGS 1
#include<easyx.h>
#include<stdio.h>
void my_DLAM()
{
	setlinecolor(BLACK);//����
	setfillcolor(BLUE);
	fillellipse(-250, 240, 250, -240);

	setlinecolor(BLACK);//С��
	setfillcolor(WHITE);
	fillellipse(-200, 150, 200, -240);

	setlinecolor(BLACK);//��������
	setfillcolor(WHITE);
	fillellipse(-80, 200, 0, 90);

	setlinecolor(BLACK);
	setfillcolor(WHITE);
	fillellipse(0, 200, 80, 90);

	setlinecolor(BLACK);//��������
	setfillcolor(BLACK);
	fillcircle(-40,120,10);

	setlinecolor(BLACK);
	setfillcolor(BLACK);
	fillcircle(40, 120, 10);

	setlinecolor(BLACK);//����
	setfillcolor(RED);
	fillcircle(0, 80, 20);

	//����
	line(0, 60, 0, -200);

	//���
	arc(-100, -80, 100, -200, 0, 3.14);

	//è��
	line(-250, 150, -130, 80);
	line(-280, 80, -140, 50);
	line(-280, 10, -150, 20);

	line(250, 150, 130, 80);
	line(280, 80, 140, 50);
	line(280, 10, 150, 20);
}
int main()
{
	//��ʼ����ͼ���ڣ�������ʾ����̨��, ���ĵ��ǣ�512��512��
	initgraph(1000, 1000, EX_SHOWCONSOLE);

	//���ñ�����ɫ
	setbkcolor(WHITE);
	cleardevice();//�ñ���ɫ����

	//�����߼�����ԭ�㣬���ҷ�ת����
	setorigin(512, 512);//�����߼�����ԭ��
	setaspectratio(1, -1);//��תy��

	//���ƶ���A�κ���
	my_DLAM();

	//����������˳�����ֹ����
	getchar();//�������ⰴ��
	closegraph();//�رջ�ͼ���ں���
	return 0;
}