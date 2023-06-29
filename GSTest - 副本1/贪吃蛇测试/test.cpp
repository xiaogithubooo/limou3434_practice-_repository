#include <graphics.h>

int main()
{
	//1.初始化图形窗口
	initgraph(640, 480, EX_SHOWCONSOLE);

	//2.定义消息变量
	ExMessage m;		

	while (true)
	{
		//3.获取一条鼠标或按键消息
		m = getmessage(EX_MOUSE | EX_KEY);

		switch (m.message)
		{
		case WM_MOUSEMOVE:
			//3.1.鼠标移动的时候画红色的小点
			putpixel(m.x, m.y, WHITE);
			break;

		case WM_LBUTTONDOWN:
			//3.2.如果点左键的同时按下了Ctrl键
			if (m.ctrl)
				//3.2.1画一个大方块
				rectangle(m.x - 10, m.y - 10, m.x + 10, m.y + 10);
			else
				//3.2.2.画一个小方块
				rectangle(m.x - 5, m.y - 5, m.x + 5, m.y + 5);
			break;

		case WM_KEYDOWN:
			//4.按下ESC键退出程序
			if (m.vkcode == VK_ESCAPE)
				return 0;	
		}
	}

	//5.关闭图形窗口
	closegraph();
	return 0;
}
