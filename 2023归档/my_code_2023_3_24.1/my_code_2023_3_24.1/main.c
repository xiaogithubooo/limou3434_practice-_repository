#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <windows.h>
int main()
{
	printf("���������ߵĹ���\n");
	printf("��ǰ�����ߣ�limou3434\n");
	printf("��ǰ�����У�\n"
		"<1.VS2022>   <2.VScode>      <3.IDEA>\n"
		"<4.VMware>   <5.���տ�>      <6.PyCharm>\n"
		"<7,sublime>  <8.CodeBlocks>  <9.�ػ�����>\n"
		"<0.�˳�������>\n"
	);
	int limou = 0;
	int a = 0;
	while (1 == scanf("%d", &limou))
	{
		switch (limou)
		{
		case 0:
			printf("�Ѿ��˳�\n");
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
			system("C:\\Users\\DELL\\Desktop\\���տ�.lnk");
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
			system("C:\\Users\\DELL\\Desktop\\�ػ�����.exe");
			break;
		default:
			printf("�������������������ֵ\n");
			break;
		}
		if (a == 1)
		{
			break;
		}
	}
	return 0;
}