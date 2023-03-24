#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <windows.h>
int main()
{
	printf("启动开发者的工具\n");
	printf("当前开发者：limou3434\n");
	printf("当前工具有：\n"
		"<1.VS2022>   <2.VScode>      <3.IDEA>\n"
		"<4.VMware>   <5.向日葵>      <6.PyCharm>\n"
		"<7,sublime>  <8.CodeBlocks>  <9.关机代码>\n"
		"<0.退出本程序>\n"
	);
	int limou = 0;
	int a = 0;
	while (1 == scanf("%d", &limou))
	{
		switch (limou)
		{
		case 0:
			printf("已经退出\n");
			a = 1;
			break;
		case 1:
			system("C:\\Users\\DELL\\Desktop\\Visual Studio 2022.lnk");
			break;
		case 2:
			system("C:\\Users\\DELL\\Desktop\\Visual Studio Code.lnk");
			break;
		case 3:
			system("C:\\Users\\DELL\\Desktop\\IntelliJ IDEA Community Edition 2022.3.lnk");
			break;
		case 4:
			system("C:\\Users\\DELL\\Desktop\\VMware Workstation 16 Player.lnk");
			break;
		case 5:
			system("C:\\Users\\DELL\\Desktop\\向日葵.lnk");
			break;
		case 6:
			system("C:\\Users\\DELL\\Desktop\\PyCharm Community Edition 2022.3.lnk");
			break;
		case 7:
			system("C:\\Users\\DELL\\Desktop\\sublime_text.exe.lnk");
			break;
		case 8:
			system("C:\\Users\\DELL\\Desktop\\CodeBlocks.lnk");
			break;
		case 9:
			system("C:\\Users\\DELL\\Desktop\\关机代码.exe");
			break;
		default:
			printf("输入错误，请重新输入数值\n");
			break;
		}
		if (a == 1)
		{
			break;
		}
	}
	return 0;
}