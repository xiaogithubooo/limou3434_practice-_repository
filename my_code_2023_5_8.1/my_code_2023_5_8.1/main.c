#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//置1
#define SETBIT(x, n) (x |= (1<<(n - 1)))
//置0
#define CLRBIT(x, n) (x &= ~(1<<(n - 1)))
void ShowBits(int x)
{
	int num = sizeof(x) * 8 - 1;
	while (num >= 0)
	{
		if (x & 1 << num)
		{
			printf("1 ");
		}
		else
		{
			printf("0 ");
		}
		num--;
	}
}
//int main()
//{
//	int x = 0;
//	//1.设置指定比特位为1
//	SETBIT(x, 3);
//	SETBIT(x, 5);
//	CLRBIT(x, 5);
//	//2.显示int的所有bit位
//	ShowBits(x);
//	return 0;
//}
int main()
{
	char ch = 0;
	printf("%zd\n", sizeof(ch));
	printf("%zd\n", sizeof(~ch));
	printf("%zd\n", sizeof(ch >> 1));
	return 0;
}
