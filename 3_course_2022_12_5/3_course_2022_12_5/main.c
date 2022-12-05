#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int main()
//{
//	int A = 43;
//	printf("%d\n", printf("%d", printf("%d", A)));
//	//结果会输出什么呢？
//	//4321
//	printf("%d\n", printf("0,1,2,3\n"));
//	//输出结果为
//	////0，1，2，3
//    //8
//	int a = 10, b = 3;
//	//printf("%f", a % b);//输出小数余数，这是不合法的
//	int arr[3] = { 1,2,3 };
//	printf("%d\n", sizeof(arr));//输出12
//	printf("%d\n", sizeof(arr) / sizeof(arr[0]));//可以求元素个数
//
//	printf("%D\t%D\n", sizeof(arr), 15);//写法错误
//	return 0;
//}
void f(int x, int y)
{
	if (x > y)
	{
		printf("%d\n", x);
	}
	else if (x < y)
	{
		printf("%d\n",y);
	}
	else
	{
		printf("一样大\n");
	}
}
int main()
{
	int x = 0, y = 0;
	scanf("%d%d", &x, &y);
	f(x, y);
	return 0;
}