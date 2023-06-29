#include <graphics.h>
#include <stdio.h>
int main()
{
	initgraph(640, 480, EX_SHOWCONSOLE);
	BeginBatchDraw();

	setlinecolor(WHITE);
	setfillcolor(RED);

	for (int i = 50; i < 600; i++)
	{
		cleardevice();
		circle(i, 100, 40);
		floodfill(i, 100, WHITE);
		//FlushBatchDraw();
		EndBatchDraw();
		BeginBatchDraw();
		Sleep(10);
	}

	EndBatchDraw();
	getchar();
	closegraph();
}
