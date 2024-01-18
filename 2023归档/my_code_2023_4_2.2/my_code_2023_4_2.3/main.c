#define _CRT_SECURE_NO_WARNINGS 1
#define FUN(X) ( ( (X&0x55555555)<<1)  | ( (X&0xAAAAAAAA)>>1 ) ) 
#include <stdio.h>
int main()
{
	int x = 0;
	scanf("%d", &x);
	printf("%d", FUN(x));
	return 0;
}