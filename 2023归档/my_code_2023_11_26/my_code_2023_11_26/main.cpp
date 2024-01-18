#include <stdio.h>
int main()
{
	char a[5] = { 0 };
	int i;
	for (i = 0; i < 5; i++)
	{
		a[i] = getchar();
	}
	a[4] = '\0';
	printf("%s", a);
	return 0;
}