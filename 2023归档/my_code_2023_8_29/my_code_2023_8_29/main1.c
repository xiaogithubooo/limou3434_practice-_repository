#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void test_1()
{
	int n1 = 0;
	int n2 = 0;
	int n3 = 0;
	int n4 = 0;

	int scRe = 0;
	scRe = scanf("%d %d %d", &n1, &n2, &n3);
	scRe = scanf("%d", &n4);

	printf("%d %d %d %d\n", n1, n2, n3, n4);
}
void test_2()
{
	char n1 = 0;
	char n2 = 0;
	char n3 = 0;
	char n4 = 0;

	char scRe = 0;
	scRe = scanf("%c %c %c", &n1, &n2, &n3);
	scRe = scanf("%c", &n4);

	printf("%c %c %c %c\n", n1, n2, n3, n4);
}
void test_3()
{
	int number = 0;
	char ch = '0';
	while (1)
	{
		scanf("%d %c", &number, &ch);
		printf("-\n");
		if (number != 0)
		{
			break;
		}
	}

	int a = 1;
	int b = 2;
	char c = '0';
	scanf("%d %d", &a, &b);
	printf("%d %d\n", a, b);
	scanf("%c", &c);
	printf("%c", c);
}
void test_4()
{
	int in1 = 0;
	int in2 = 0;
	scanf("%*d %*d %d %d", &in1, &in2);
	printf("%d %d\n", in1, in2);

	char ch1 = '0';
	char ch2 = '0';
	scanf(" %c %c", &ch1, &ch2);
	printf("%c %c\n", ch1, ch2);
}

int main()
{
	//test_1();
	//test_2();
	//test_3();
	//test_4();
	test_5();
	return 0;
}

//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//extern char arr[];
//int main()
//{
//	printf("%s", arr);
//	return 0;
//}