#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <windows.h>
int GetMax(int number, ...)
{
	va_list arg;
	va_start(arg, number);
	int max = va_arg(arg, int);
	for (int i = 0; i < number - 1; i++)
	{
		int x = va_arg(arg, int);
		if (max < x)
		{
			max = x;
		}
	}
	va_end(arg);
	return max;
}
int main()
{
	int max = GetMax(5, 'a', 'b', 'c', 'd', 'e');
	printf("%d", max);
	return 0;
}

//int Add(int x, int y)
//{
//    printf("Before:%d\n", y);
//    *(&x + 1) = 100;
//    printf("After:%d\n", y);
//    int z;
//    z = x + y;
//    return z;
//}
//int main()
//{
//    int a = 1;
//    int b = 2;
//    int c = Add(1, 2);
//    printf("%d", c);
//    return 0;
//}