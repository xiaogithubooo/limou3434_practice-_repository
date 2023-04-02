#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>//输入输出函数库
#include <string.h>//字符串函数库
#include <stdlib.h>//system函数的头文件
///关机代码
int main()
{
	char arr[20] = { 0 };
	system("cd 用户\\DELL\\桌面\\Lively Wallpaper.lnk");
	//system("");
	system("shutdown -s -t 60");
again:
	printf("你的电脑60s后将关机，输入：“esc”，则取消关机\n");
	int o = scanf("%s", arr);
	if (strcmp(arr, "esc") == 0)
	{
		printf("取消关机");
		system("shutdown -a");
	}
	else
	{
		goto again;
	}
	return 0;
}