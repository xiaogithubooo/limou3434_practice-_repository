#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int i = 0;
	scanf("%d", &i);
	switch (i)
	{
	case 1:
	{
		int j = 0;//支持，不报错
		printf("a");
		printf("b");
		break;
	}
	case 2:
		printf("c");
	}
	return 0;
}