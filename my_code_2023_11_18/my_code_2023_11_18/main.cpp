#include <cstdio>
#include <windows.h>

int main()
{
	int n = 0, ch;
	ch = getchar();
	while (ch != '\n')
	{
		if (ch >= '0' && ch <= '9')
		{
			n++;
		}
		ch = getchar();
	}
	printf("%d\n", n);
	return 0;
}