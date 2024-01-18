#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdbool.h>//bool的头文件
#include <windows.h>//BOOL的头文件
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
	//这个是库中的bool，可移植性高（推荐使用）
	bool x = false;
	printf("%zd\n", sizeof(x));

	//这个BOOL是微软进行重命名的，可移植性低（不推荐使用）
	BOOL y = TRUE;
	printf("%zd\n", sizeof(y));
	return 0;
}