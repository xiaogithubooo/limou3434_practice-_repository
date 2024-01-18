#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<windows.h>
//颜色选择函数
void color(short num)
{
	if (num >= 0 && num <= 15)//SetConsoleTextAttribute函数是windows中可以设置控制台窗口字体颜色和背景色的函数
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), num);//获取窗口的句柄
	}
	else
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);//7号则为默认颜色
	}
}
void progress_bar()//进度条函数
{
	int x = 0;
	for (x = 0; x < 51; x++)
	{
		if (x == 25)
		{
			printf("加");
		}
		else if (x == 26)
		{
			printf("载");
		}
		else if (x == 27)
		{
			printf("中");
		}
		printf("-");
	}
	printf("\n");
	SetConsoleOutputCP(437);//暂时改字符集为“MS-DOS美语/英语”
	for (x = 0; x < 57; x++)
	{
		if (x >= 0 && x <= 2)
		{
			Sleep(2000);
			printf("%c", 219);
		}
		else if (x > 2 && x <= 10)
		{
			Sleep(500);
			printf("%c", 219);
		}
		else if (x > 10 && x <= 30)
		{
			Sleep(10);
			printf("%c", 219);
		}
		else if (x > 30 && x <= 40)
		{
			Sleep(500);
			printf("%c", 219);
		}
		else if (x > 40 && x <= 50)
		{
			Sleep(3000);
			printf("%c", 219);
		}
		else if (x > 50 && x <= 55)
		{
			Sleep(10);
			printf("%c", 219);
		}
		else
		{
			Sleep(5000);
			printf("%c", 219);
		}
	}
	SetConsoleOutputCP(936);//改回字符集
	printf("\n");
	for (x = 0; x < 51; x++)
	{
		if (x == 25)
		{
			printf("已");
		}
		else if (x == 26)
		{
			printf("完");
		}
		else if (x == 27)
		{
			printf("毕");
		}
		printf("-");
	}
	printf("\n");
}

int main()//主函数
{
	int i = 0;
	printf("请输入想要的进度条颜色：");
	scanf("%d", &i);
	color(i);

	progress_bar();
	color(7);
	return 0;
}//发烧了，之后再完善吧……