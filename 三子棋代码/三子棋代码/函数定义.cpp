#define _CRT_SECURE_NO_WARNINGS 1
#include<easyx.h>
#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
int my_ui(void)
{
	initgraph(600, 600, EX_DBLCLKS | EX_SHOWCONSOLE);//�򿪴���
	setbkcolor(RGB(164, 225, 202));//���ñ�����ɫ
	cleardevice();//��ˢ������ɫ
	//������������

	IMAGE img;
	loadimage(&img, "../����������ͼƬ.jpg", 200, 200, true);
	putimage(200, 100, &img);//����ͼƬ

	setbkcolor(NULL);//���ñ�����ɫ
	fillrectangle(50, 350, 250, 450);//��ӡ������"�˳���esc��"��ť�������λ�룺VK_ESCAPE
	fillrectangle(350, 350, 550, 450);//��ӡ�����ߡ����棨enter������ť�������λ�룺VK_RETURN
	char word_arr_1[] = "�˳�(esc)";
	char word_arr_2[] = "����(enter)";
	outtextxy(115, 395, word_arr_1);
	outtextxy(415, 395, word_arr_2);

	ExMessage msg;
	msg = getmessage(EX_KEY);//�洢������Ϣ����Ϣ���
	switch (msg.message)//�ж������ּ�����Ϣ
	{
		case WM_KEYDOWN://���¼����¼���Ϣ
			if (msg.vkcode == VK_ESCAPE)
			{
				return 0;
			}
			else if (msg.vkcode == VK_RETURN)
			{
				return 1;
			}
	}
}