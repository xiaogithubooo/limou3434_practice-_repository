//使用例子
#include <graphics.h>
#include <windows.h>
#include <cstdio>
int main()
{

	//初始化绘图窗口
	initgraph(640, 480, EX_SHOWCONSOLE);

	//获取指向显示缓冲区的指针
	DWORD* pMem = GetImageBuffer();//不写默认为NULL（表示默认的绘图窗口）

	//直接对显示缓冲区赋值
	for (int i = 0; i < 640 * 480; i++)
	{
		pMem[i] = BGR(RGB(0, 0, i * 256 / (640 * 480)));
		if (i % 1000 == 0)
		{
			Sleep(100);
		}
	}

	//使显示缓冲区生效（注：操作指向IMAGE的显示缓冲区不需要这条语句）
	FlushBatchDraw();
	//在计算机图形编程中，
	//我们经常需要将绘制的图形显示在屏幕上。
	//而绘制图形是一个相对耗费资源的操作，
	//如果每次绘制都立即显示在屏幕上，
	//会导致频繁的图形刷新，
	//可能会引起画面闪烁或者卡顿的问题。
	//为了提高绘制的效率和流畅度，
	//就引入了批量绘制的概念。
	//FlushBatchDraw()的作用是将之前批量绘制的图形一次性地刷新到屏幕上。
	//通俗地说，就好比是一个“提交”操作，
	//你之前进行的所有绘制都会在调用FlushBatchDraw()后一起显示在屏幕上

	//按任意键退出
	getchar();
	closegraph();

	return 0;
}



/*
* 	//绘图窗口初始化
	int length = 1000;
	int width = 1000;
	initgraph(length, width, EX_SHOWCONSOLE);

	//读取图片至绘图对象
	IMAGE img1;
	loadimage(
		&img1,
		_T("C:\\Users\\DELL\\Desktop\\SummerHolidaysFile\\GSnakeEasyxProject\\testPicture2.jpg")
	);
	putimage(0, 0, &img1);
	getchar();

	//调整好大小后
	Resize(&img1, 500, 500);
	putimage(100, 100, &img1);
	getchar();
		
	closegraph();

* 	//设置绘图目标为img1对象
	SetWorkingImage(&img1);
	printf("img1\n");
	getchar();
* 	//以下绘图操作都会绘制在img1对象上面
	line(0 + 100, 100, 200 + 100, 100);
	line(100 + 100, 0, 100 + 100, 200);
	circle(100 + 100, 100, 50);
	//设置绘图目标为绘图窗口
	SetWorkingImage();
	line(0, 100, 200, 100);
	line(100, 0, 100, 200);
	circle(100, 100, 50);
	printf("绘图窗口\n");
	getchar();*/
