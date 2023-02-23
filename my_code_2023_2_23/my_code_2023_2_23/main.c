#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
union hold{
	int a;
	char b;
	long long c;
};
int main()
{
	union hold book;
	book.c = 4294967295 + 1;
	return 0;
}
