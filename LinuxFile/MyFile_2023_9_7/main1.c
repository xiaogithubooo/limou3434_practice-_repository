#include <stdio.h>
extern int x;
static int y = 1000;
int main()
{
	printf("%d\n", x);
	extern int y;
	printf("%d\n", y);
	return 0;
}
