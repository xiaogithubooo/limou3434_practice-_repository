#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void function(int number)
{
	printf("%d", number % 10);
	if (number > 10)
	{
		function(number / 10);
	}
}
int main()
{
	int number = 0;
	scanf("%d", &number);
	function(number);
	return 0;
}