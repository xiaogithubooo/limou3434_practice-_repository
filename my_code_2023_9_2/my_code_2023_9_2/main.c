#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void test_1()
{
	int ch;
	while ((ch = getchar()) != EOF)
	{
		putchar(ch);
	}
}
void test_2()
{
	//int in = 0;
	//int rel = scanf("%d", &in);//只要返回0就会把这个输入抛弃
	//printf("%d\n", rel);
	//printf("%d\n\n", in);

	char ch = '0';
	int rel = scanf("%c", &ch);
	printf("%d\n", rel);
	printf("%c\n", ch);
}
void test_3(x, y, z)
double x, y, z;
{
	printf("%f %f %f\n", x, y, z);
}
void test_4();
void test_5()
{
	;
}
int main()
{
	//test_1();
	//test_2();
	//test_3(10.1, 11.2, 12);
	//test_4(11.2, 13.1);
	test_5();
	return 0;
}
void test_4(int x, int y)
{
	printf("%d %d\n", x, y);
}