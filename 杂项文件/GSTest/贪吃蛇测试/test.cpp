//使用例子
#include <graphics.h>
#include <cstdio>
int main()
{
	//绘图窗口初始化
	int length = 1000;
	int width = 1000;
	initgraph(length, width, EX_SHOWCONSOLE);

	//坐标轴修正
	setaspectratio(1, -1);
	setorigin(length / 2, width / 2);

	//读取图片至绘图对象
	IMAGE img1;
	loadimage(
		&img1,
		_T("C:\\Users\\DELL\\Desktop\\SummerHolidaysFile\\GSnakeEasyxProject\\testPicture2.jpg")
	);
	putimage(0, 0, &img1);
	getchar();

	//旋转后
	IMAGE img2;
	rotateimage(&img2, &img1, 3.14/2);
	putimage(-500, -500, &img2);
	getchar();

	//复制区域的图像并且输出
	IMAGE img3;
	getimage(&img3, 200, 200, 300, 300);
	putimage(0, 0, &img3);
	getchar();

	closegraph();
	return 0;
}
