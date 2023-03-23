#define _CRT_SECURE_NO_WARNINGS 1
#include "function.h"
void test1()
{
	Stack st1;
	Stack_Init(&st1);
	Stack_Push(&st1, 1);
	Stack_Push(&st1, 2);
	Stack_Push(&st1, 3);
	Stack_Push(&st1, 4);
	Stack_Push(&st1, 5);

	printf("<Õ»¶¥>\n");
	while (!Stack_Empty(&st1))
	{
		printf("%3d\n", Stack_Top(&st1));
		Stack_Pop(&st1);
	}
	printf("<Õ»µ×>\n");
	Stack_Destory(&st1);
}
int main()
{
	test1();
	return 0;
}