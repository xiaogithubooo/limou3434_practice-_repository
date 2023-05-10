#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
int main()
{
	printf("%d %d", (int)trunc(2.9), (int)trunc(-2.9));
	return 0;
}
int i = 2.9;
int j = -2.9;
printf("%d %d", i, j);

int main()
{
	int a = 10;
	int b = a++ + 10;
	return 0;
}

int main()
{
	char a[8] = { "abcdefg" };
	printf("%s\n", a);
	return 0;
}