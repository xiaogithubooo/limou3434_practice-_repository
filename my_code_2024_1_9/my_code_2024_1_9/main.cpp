#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int a = 50;
	int b = 10;
	int c = 0;
	int add = (printf("%d", a), printf("+%d", b), printf("=%d", c = a + b), c);

	printf("\n%d", add);
}