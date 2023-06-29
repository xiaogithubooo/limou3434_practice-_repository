#include <graphics.h>
#include <stdio.h>
int main()
{
	//1.初始化绘图窗口
	initgraph(640, 480, EX_SHOWCONSOLE);
	//2.定义字符串缓冲区，并接收用户输入
	wchar_t s[10];
	while (1)
	{
		InputBox(s, 10, _T("请输入半径"), _T("画圆小程序"), _T("100"), 50,50, true);
		//3.将用户输入转换为数字
		int r = _wtoi(s);
		//4.画圆
		circle(320, 240, r);
	}
	//5.按任意键退出
	getchar();
	closegraph();
	return 0;
}
