#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>//��׼�������ͷ�ļ�
#include<easyx.h>//easyx���ⲿͷ�ļ�
#include<math.h>//��ѧͷ�ļ�
#include<windows.h>//windowsͷ�ļ�
#include<conio.h>//ˢ�������ͷ�ļ�
#include<stdlib.h>//�������ͷ�ļ�
#include<time.h>//����srand���ɽϺõ������
void putTransparentImage(int x, int y, const IMAGE* mask, const IMAGE* img)
{//������λ�õ�xy���꣬����ָ�룬�ڵױ���ָ�룩
	putimage(x, y, mask, SRCAND);
	putimage(x, y, img, SRCPAINT);
}
int main()
{
	initgraph(800, 600);//���ƴ���

	setbkcolor(WHITE);//���ð�ɫ����
	cleardevice();//�����Ļ

	setbkmode(TRANSPARENT);
	settextcolor(RED);//����������ɫ
	settextstyle(40, 0, "΢���ź�");//����������

	const char* pText = "Hellow phigros|��ã�phigros";
	outtextxy(180, 280, pText);
	int o = getchar();
	

	initgraph(700, 400);
	//���ú��߼�����ԭ��
	setorigin(350, 200);
	//�޷�ת����
	setaspectratio(1, 1);

	IMAGE imgBackground;
	loadimage(&imgBackground, "./����.jpg", 700, 400, true);

	IMAGE imgshort;
	loadimage(&imgshort, "./�̼�.png", 90, 10, true);

	IMAGE imgshortMask;
	loadimage(&imgshortMask, "./�̼�����.png", 90, 10, true);

	BeginBatchDraw();
	for (int i = -200; i < 0; i += 5)
	{
		putimage(-350, -200, &imgBackground);//����ͼƬ
		putTransparentImage(-60, i, &imgshortMask, &imgshort);
		FlushBatchDraw();
		Sleep(5);
		putimage(-350, -200, &imgBackground);//����ͼƬ
	}
	for (int i = -200; i < 0; i += 5)
	{
		putimage(-350, -200, &imgBackground);//����ͼƬ
		putTransparentImage(0, i, &imgshortMask, &imgshort);
		FlushBatchDraw();
		Sleep(5);
		putimage(-350, -200, &imgBackground);//����ͼƬ
	}
	for (int i = -200; i < 0; i += 5)
	{
		putimage(-350, -200, &imgBackground);//����ͼƬ
		putTransparentImage(-120, i, &imgshortMask, &imgshort);
		FlushBatchDraw();
		Sleep(10);
		putimage(-350, -200, &imgBackground);//����ͼƬ
	}
	for (int i = -200; i < 0; i += 5)
	{
		putimage(-350, -200, &imgBackground);//����ͼƬ
		putTransparentImage(-120, i, &imgshortMask, &imgshort);
		FlushBatchDraw();
		Sleep(10);
		putimage(-350, -200, &imgBackground);//����ͼƬ
	}
	for (int i = -200; i < 0; i += 5)
	{
		putimage(-350, -200, &imgBackground);//����ͼƬ
		putTransparentImage(-120, i, &imgshortMask, &imgshort);
		FlushBatchDraw();
		Sleep(10);
		putimage(-350, -200, &imgBackground);//����ͼƬ
	}
	for (int i = -200; i < 0; i += 5)
	{
		putimage(-350, -200, &imgBackground);//����ͼƬ
		putTransparentImage(0, i, &imgshortMask, &imgshort);
		FlushBatchDraw();
		Sleep(10);
		putimage(-350, -200, &imgBackground);//����ͼƬ
	}

	for (int i = -200; i < 0; i += 5)
	{
		putimage(-350, -200, &imgBackground);//����ͼƬ
		putTransparentImage(100, i, &imgshortMask, &imgshort);
		FlushBatchDraw();
		Sleep(10);
		putimage(-350, -200, &imgBackground);//����ͼƬ
	}
	EndBatchDraw();//<�Ժ���Գ��Է�װ���������>

	o = getchar();
	closegraph();
	return 0;
}