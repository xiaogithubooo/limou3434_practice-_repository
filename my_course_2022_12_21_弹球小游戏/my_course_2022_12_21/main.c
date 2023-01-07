#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
#include<windows.h>
//一、尝试粗略求出极限
//int main()
//{
//	double x = 1.00, y = 0;
//	for (x = 1.0; x != 0; x /= 2)
//	{
//		y = sin(x);
//		printf("%lf\n", x / y);
//		Sleep(500);
//	}
//	return 0;
//}
//二、使用一点easy库的函数
// 1、初始化窗口函数
//【HWND initgraoh(int width, int height, int flag = NULL)】后面的flag可以不填
//2、关闭绘图窗体函数
//【void closeraph()】
//3、物理坐标和逻辑坐标（坐标）相关函数
//（1）修改坐标原点
//void setorigin(int x, int y);//其中x、y坐标参数用的是物理坐标表示的
//（2）修改坐标轴方向（修改坐标轴缩放比例）
//void setaspectratio(
//	float xasp,
//	float yasp
//);
////绘制100*30的矩形（长*宽）
////其中执行Setaspectratio(1，-1)可以让y轴向上
//4、“设备”，是指绘图表面
//在 EasyX 中，设备分两种，一种是默认的绘图窗口，另一种是 IMAGE 对象。通过SetWorkinglmage函数可以设置当前用于绘图的设备。
//void SetWorkingImage(IMAGE * pImg = NULL);//参数plmg绘画设备指针。如果为NULL，表示绘图设备为默认绘图窗口。
//// 创建 200x200 的 img 对象IMAGE img(200, 200);
//SetWorkingImage(&img);
//所有的绘图函数都会绘制在设备img上。
//5、绘图设备相关函数
//（1）清屏函数
//void cleardevice();
//（2）“初始化绘图窗口”与“关闭窗口”
//HWND initgraph(
//	int width,
//	int height,
//	int flag = NULL);
////返回新建绘图窗口的句柄
////绘图窗口的样式，默认为 NULL。可为以下值：
//EX_DBLCLKS
//在绘图窗口中支持鼠标双击事件。
//EX_NOCLOSE
//禁用绘图窗口的关闭按钮。
//EX_NOMINIMIZE
//禁用绘图窗口的最小化按钮。
//EX_SHOWCONSOLE
//显示控制台窗口。
//
//（3）“获取当前缩放因子”与“设置缩放因子”
//void getaspectratio(
//	float* pxasp,
//	float* pyasp
//);
//void setaspectratio(
//	float xasp,
//	float yasp
//);
//（4）恢复绘画窗口为默认值（ 这个函数用于重置视图、当前点、绘图色、背景色、线形、填充样式、字体为默认值。）
//void graphdefaults();
//（5）设置坐标原点
//void setorigin(int x, int y);
//（6）设置当前绘图设备的裁剪区
//void setcliprgn(HRGN hrgn);
//int main()
//{
//	// 初始化绘图窗口
//	initgraph(640, 480);
//
//	// 创建一个矩形区域
//	HRGN rgn = CreateRectRgn(100, 100, 200, 200);
//	// 将该矩形区域设置为裁剪区
//	setcliprgn(rgn);
//	// 不再使用 rgn，清理 rgn 占用的系统资源
//	DeleteObject(rgn);
//
//	// 画圆，受裁剪区影响，只显示出四段圆弧
//	circle(150, 150, 55);
//
//	// 取消之前设置的裁剪区
//	setcliprgn(NULL);
//
//	// 画圆，不再受裁剪区影响，显示出一个完整的圆
//	circle(150, 150, 60);
//
//	// 按任意键退出
//	_getch();
//	closegraph();
//}
//（7）清除裁剪区的屏幕内容
//void clearcliprgn();
//三、学习使用Linux操作系统，了解文件和目录的权限知识