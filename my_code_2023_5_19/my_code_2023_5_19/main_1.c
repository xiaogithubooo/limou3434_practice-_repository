#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//声明为指针
extern char* a;
//不合法

//声明为数组
extern char b[];
//不合法
int main()
{
	printf("%d", *a);
	//for (int i = 0; i < 6; i++)
	//{
	//	printf("%d ", *(a + i));
	//}

	return 0;
}

//int main()
//{
//	int a[5] = { 1, 2, 3, 4, 5 };
//	int* ptr = (int*)(&a + 1);//(&a)是整个数组的地址，+1就跳过整个数组，此时指针ptr指向的是最后一个数组元素的后一个int大小的空间，直接访问这个空间是非法的
//	printf("%d %d\n", *(a + 1), *(ptr - 1));
//	//a+1是a数组的第二个元素，解引用就得到数组的第二个元素2
//	//ptr-1得到的是数组的最后一个元素5
//	return 0;
//}
//void Function(int arr[], int size)//接受的是int*的数据，即指针
//{
//	printf("%zd\n", sizeof(arr));//32位为4，64位为8
//	for (int i = 0; i < size; i++)
//	{
//		printf("%d ", *(arr+i));
//	}
//	printf("\n");
//}
//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6 };
//	int size = sizeof(arr) / sizeof(arr[0]);
//	Function(arr, size);//数组传参传的是其首元素的地址
//	for (int i = 0; i < size; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}