#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>//�������������
#include <string.h>//�ַ���������
#include <stdlib.h>//system������ͷ�ļ�
///�ػ�����
int main()
{
	char arr[20] = { 0 };
	system("cd �û�\\DELL\\����\\Lively Wallpaper.lnk");
	//system("");
	system("shutdown -s -t 60");
again:
	printf("��ĵ���60s�󽫹ػ������룺��esc������ȡ���ػ�\n");
	int o = scanf("%s", arr);
	if (strcmp(arr, "esc") == 0)
	{
		printf("ȡ���ػ�");
		system("shutdown -a");
	}
	else
	{
		goto again;
	}
	return 0;
}