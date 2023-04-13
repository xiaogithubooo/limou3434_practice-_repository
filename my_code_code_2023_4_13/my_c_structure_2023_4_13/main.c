#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void function(int b)
{
	printf("%d", b);
}
int main()
{
	double a = 3.1415926;
	function(a);
	return 0;
}