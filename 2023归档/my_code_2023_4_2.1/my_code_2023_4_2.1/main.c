#define _CRT_SECURE_NO_WARNINGS 1
#include "function.h"
int main()
{
	int input = 0;
	do
	{
		menu();
		printf("请选择:");
		int scanf_num = scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("成功退出程序\n");
			break;
		default:
			printf("选择错误,请再次选择\n");
			break;
		}
	} while (input);
	return 0;
}

//注意拓展代码
//1.玩家可以展开非雷区域
// （1）该坐标不是雷
// （2）该坐标周围没有雷
// （3）该坐标没有被排查过（避免死递归）
//2.玩家可以对自己认为的雷做标记
//3.加入扫雷计时器