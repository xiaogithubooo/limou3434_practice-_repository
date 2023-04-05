#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int arr[3] = { 6, 2, 3 };//实际上，任何一个变量，只要删去变量名，剩下的就是变量的类型，因此这个数组的类型就是int[3]
	int(*p1)[3] = &arr;//&arr是取出整个数组的地址
	printf("%p\n%p\n", p1, p1 + 1);

	int(*p2)[3] = (p1 + 1);
	printf("%zd", (p2) - (p1));//得到int()[3]元素有1个
	return 0;
}
int main()
{
	int a = 1;
	int b = 9;
	int c = 4;
	int d = 6;
	int* arr[4] = { &a, &b, &c, &d };
	for (int i = 0; i < 4; i++)
	{
		printf("%p\n", arr[i]);
	}
	return 0;
}
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,0 };
	int* p = arr; //指针存放数组首元素的地址
	int sz = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < sz; i++)
	{
		printf("\"&arr[%d] = %p\" 和 \"p+%d = %p\"\n", i, &arr[i], i, p + i);
	}
	printf("\n");
	for (int i = 0; i < sz; i++)
	{
		printf("\"&arr[%d] = %d\" 和 \"p+%d = %d\"\n", i, arr[i], i, *(p + i));
	}
	return 0;
}
int main()
{
	int arr[10] = { 1,1,2,4,3 };
	if (&arr[3] > &arr[0])
	{
		printf("(&arr[3])是高地址\n");
	}
	return 0;
}
int main()
{
	char arr[] = "abcdef";
	int a = arr[5] - arr[0];
	printf("%d", a);//得到两个指针之间元素的个数
	return 0;
}
int main()
{
    int n = 0x11223344;//十六进制数字

    char* pc = (char*)&n;
    int* pi = &n;

    *pc = 0;   //观察内存的变化
    *pi = 0;   //观察内存的变化

    return 0;
}