#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdbool.h>//bool��ͷ�ļ�
#include <windows.h>//BOOL��ͷ�ļ�
int main()
{
	double a = 1./3.;
	printf("%.50lf", a);
	return 0;
}

int main()
{
	int flag = 0;
	if (flag == 0)
		printf("flag == 0\n");
	if (flag == false)
		printf("flag == false\n");
	if (!flag)
		printf("!flag\n");
	return 0;
}

int main()
{
	//����ǿ��е�bool������ֲ�Ըߣ��Ƽ�ʹ�ã�
	bool x = false;
	printf("%zd\n", sizeof(x));

	//���BOOL��΢������������ģ�����ֲ�Եͣ����Ƽ�ʹ�ã�
	BOOL y = TRUE;
	printf("%zd\n", sizeof(y));
	return 0;
}