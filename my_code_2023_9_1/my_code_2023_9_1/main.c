#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
int test_1(unsigned int n)// ‰»În
{
	if (n == 0 || n == 1)
		return 1;
	else
		return n * test_1(n - 1);//n*fun(n-1)
}
void test_2(int n)// ‰»În
{
	int i = 1;
	while (i <= n)
	{
		i = i * 2;//1,2,4,8
	}
}
//void test_3();
void test_4()
{
	int ch = getchar();
}
int main()
{
	//int a = 0 ;
	//float b = 3.14;
	//a = b;
	//printf("%d\n", a);

	//test_3(3.14, 3.14);
	test_4();
	return 0;
}

//void test_3(int y, int x)
//{
//	printf("%d %d\n", y, x);
//}