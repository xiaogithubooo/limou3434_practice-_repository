#include <graphics.h>

int main()
{
	//1.��ʼ��ͼ�δ���
	initgraph(640, 480, EX_SHOWCONSOLE);

	//2.������Ϣ����
	ExMessage m;		

	while (true)
	{
		//3.��ȡһ�����򰴼���Ϣ
		m = getmessage(EX_MOUSE | EX_KEY);

		switch (m.message)
		{
		case WM_MOUSEMOVE:
			//3.1.����ƶ���ʱ�򻭺�ɫ��С��
			putpixel(m.x, m.y, WHITE);
			break;

		case WM_LBUTTONDOWN:
			//3.2.����������ͬʱ������Ctrl��
			if (m.ctrl)
				//3.2.1��һ���󷽿�
				rectangle(m.x - 10, m.y - 10, m.x + 10, m.y + 10);
			else
				//3.2.2.��һ��С����
				rectangle(m.x - 5, m.y - 5, m.x + 5, m.y + 5);
			break;

		case WM_KEYDOWN:
			//4.����ESC���˳�����
			if (m.vkcode == VK_ESCAPE)
				return 0;	
		}
	}

	//5.�ر�ͼ�δ���
	closegraph();
	return 0;
}
