#define _CRT_SECURE_NO_WARNINGS 1
#include<easyx.h>
#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
int my_ui(void)
{
	initgraph(600, 600, EX_DBLCLKS | EX_SHOWCONSOLE);//打开窗口
	setbkcolor(RGB(164, 225, 202));//设置背景颜色
	cleardevice();//粉刷背景颜色
	//保持物理坐标

	IMAGE img;
	loadimage(&img, "../测试三子棋图片.jpg", 200, 200, true);
	putimage(200, 100, &img);//插入图片

	setbkcolor(NULL);//设置背景颜色
	fillrectangle(50, 350, 250, 450);//打印填充描边"退出（esc）"按钮，虚拟键位码：VK_ESCAPE
	fillrectangle(350, 350, 550, 450);//打印填充描边“游玩（enter）”按钮，虚拟键位码：VK_RETURN
	char word_arr_1[] = "退出(esc)";
	char word_arr_2[] = "游玩(enter)";
	outtextxy(115, 395, word_arr_1);
	outtextxy(415, 395, word_arr_2);

	ExMessage msg;
	msg = getmessage(EX_KEY);//存储按键消息（消息类别）
	switch (msg.message)//判断是哪种键盘消息
	{
		case WM_KEYDOWN://按下键盘事件消息
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