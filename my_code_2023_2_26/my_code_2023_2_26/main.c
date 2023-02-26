#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int int_cmp(void* p1, void* p2)
{
	return (*((int*)p1) - *((int*)p2));
}
void _swap(void* p1, void* p2)
{
	int i = 0;
	i = *(int*)p2;
	*(int*)p2 = *(int*)p1;
	*(int*)p1 = i;
}

void bubble(void* base, int count, int size, int(*cmp)(void*, void*))
{
	int i = 0, j = 0;
	for (i = 0; i < count - 1; i++)
	{
		for (j = 0; j < count - 1 - i; j++)
		{
			if (cmp((char*)base + j * size, (char*)base + (j + 1) * size ) > 0)//交换函数，比较大小，大----小
			{
				_swap((char*)base + j * size, (char*)base + ((j + 1) * size));//排序函数，这里改成(char*)就可以利用size适应不同的字节
			}
		}
	}
}

int main()
{
	int arr[] = { 1, 12, 23, 0, -1, 100, -23 };

	bubble(arr, sizeof(arr) / sizeof(arr[0]), sizeof(int), int_cmp);//排序函数，<数组指针、数组大小、数组元素大小、排序方式>

	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}
#include <stdio.h>
//1、通用冒泡排序
int int_cmp(const void* p1, const void* p2)//其中一个比较函数，这个是整型比较，是用户决定这个函数应该如何编写
{
    return (*(int*)p1 - *(int*)p2);
    //不过注意void不能直接解引用！！！
}

void _swap(void* p1, void* p2, int size)//其中一个排序方法，这个是排序是冒泡排序，可以由开发者决定底层排序的方法，在qsort中使用的底层函数是快排
{
    int i = 0;
    for (i = 0; i < size; i++)
    {
        char tmp = *((char*)p1 + i);
        *((char*)p1 + i) = *((char*)p2 + i);
        *((char*)p2 + i) = tmp;
    }
}

void bubble(void* base, int count, int size, int(*cmp)(void*, void*))//相当于qsort，但是实现逻辑不仅仅是快速排序，内部的_swap函数也可能是其他的排序算法，cmp函数可能比较不同类型的数据
{
    int i = 0;
    int j = 0;
    for (i = 0; i < count - 1; i++)
    {
        for (j = 0; j < count - i - 1; j++)
        {
            if (cmp((char*)base + j * size, (char*)base + (j + 1) * size) > 0)//比较函数，这里改成(char*)就可以利用size适应不同的字节
            {
                _swap((char*)base + j * size, (char*)base + (j + 1) * size, size);//排序函数，这里改成(char*)就可以利用size适应不同的字节
            }
        }
    }
}

int main()
{
    int arr[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
    char *arr[] = {"aaaa","dddd","cccc","bbbb"};
    int i = 0;
    bubble(arr, sizeof(arr) / sizeof(arr[0]), sizeof(int), int_cmp);
    for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

//2、测试程序
int main()
{
	int aa[2][5] = { 10,9,8,7,6,5,4,3,2,1 };
	int* ptr1 = (int*)(&aa + 1);
	int* ptr2 = (int*)(*(aa + 1));
	printf("%d,%d", *(ptr1 - 1), *(ptr2 - 1));
	return 0;
}
//3、使用qsort
#include <stdio.h>
#include <stdlib.h>
//qosrt函数的使用者得实现一个比较函数
int int_cmp(const void* p1, const void* p2)
{
    return (*(int*)p1 - *(int*)p2);//注意不能直接解引用void指针，另外如果倒过来就是逆序输出了
}
int main()
{
    int arr[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
    int i = 0;

    qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(int), int_cmp);

    for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}