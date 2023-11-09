#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int a = 0, b = 0, c = 0, d = 0;
	
	scanf("%d %d %d %d", &a, &b, &c, &d);
	
	printf("12*a*(a+b)/c%%d = %d",
		12 * a * (a + b) / c % d);
	
	return 0;
}