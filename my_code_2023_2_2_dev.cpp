#include <stdio.h>
int main(void)
{
	char * a = "hello word";
	a[1] = 'E';
	printf("hello word");
	printf("%s\n", a);
	return 0;
}
