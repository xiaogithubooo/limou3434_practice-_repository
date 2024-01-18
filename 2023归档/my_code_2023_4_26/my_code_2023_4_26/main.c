#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void test(void)
{
	printf("papa\n");
}
int main()
{
	//printf("%zd\n", sizeof(void));
	//test(2);
	int i = 100;
	void* p = &i;
	*p;
	//printf("%d", *p);
	return 0;
}