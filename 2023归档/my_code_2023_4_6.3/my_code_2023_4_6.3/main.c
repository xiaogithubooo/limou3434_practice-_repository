#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 1000
#define SCOPE 1000
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
/*<排序算法>*/
//1.插入排序
//1.1.直接插入排序
/*排序原理：将第一个当作有序，后面的数逐步上前，继续保持有序，即：[0, end]是有序的，在end + 1的位置的值插入进去，让[0, end + 1]也有序*/
/*排序总结：利用for循环记录下每次已排序好序列的最后一个下标，记录要新插入的数据，将其和已排序的序列对比，（在原来存放数据的空间和新增的1块空间中）挪动序列保证有一个空位留给新插入的*/
/*排序时间：①情况最坏，挪动次数为(1+2+3+…(n-1))，由等差数列公式求得时间复杂度为O(n^2) ②情况最好，顺序有序的时候，时间复杂度为O(n)*/
void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; ++i)//这个循环的作用就是保证end可以找到已经排序中的的最后一个下标，注意是i < n - 1，而不是i < n
	{
		int end = i;//不断更新新的end
		int tmp = a[end + 1];//记录要新插入的数据

		//开始插入新数据
		while (end >= 0)//有两个终止的条件，一是end到了-1的情况（没有哪一个数比a[end+1]都要小），二是遇到了某个比a[end+1]都要小的
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end];
				--end;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;//之所以挪到外面是因为：先不将要插入的数插入，而是先挪动[ a[0],a[end+1] ]的数据，保证能有一个位置插入新插入的数据
	}
}
//1.2.希尔排序
/*排序原理：先做预排序，然后再直接插入排序（其中预排序要分组排序），即：每两个数字中间隔着gap-1的数字分成一组，对每一组先进行直接插入排序。再使得gap变小，继续直接预排序（如果gap越大，预排序越不接近有序，但是大的数可以越快到后面；gap越小结论反之）直到gap为1，就是直接插入排序。因此也可以先理解直接插入排序，在代码里出现1的地方全部替换成gap*/
/*排序总结*/
/*排序时间*/
void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap /= 2;//这里让gap变小，除于2的最终结果必有1和0，如果gap恒为1就是直接选择排序（对gap的减少方式有很多种，比如gap = gap / 3 + 1，而加1是为了避免出现gap==0的情况）
		//gap > 1都是预排序，使得接近有序
		//gap == 1就是直接插入排序

		for (int i = 0; i < n - gap; ++i)//这样循环设计更加巧妙，将多组数据的每一次直接插入排序同时进行，直到最后同时进行最后一次直接插入排序
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (a[end] > tmp)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
				a[end + gap] = tmp;
			}
		}
	}
}

//2.选择排序
//2.1.选择排序
//2.2.堆排序

//3.交换排序
//3.1.冒泡排序
//3.2.快速排序

//4.归并排序
//4.1.归并排序

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
/*<test测试函数>*/
//1.直接排序测试
void test_1(void)
{
	srand((unsigned)time(NULL));
	int* arr = calloc(SIZE, sizeof(int));
	if (arr == NULL) exit(-1);
	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = rand() % SCOPE;
		printf("%d ", arr[i]);
	}
	printf("\n");
	InsertSort(arr, SIZE);
	for (int i = 0; i < SIZE; i++)
	{
		printf("%d ", arr[i]);
	}
	free(arr);
	arr = NULL;
}
//2.希尔排序测试
void test_2(void)
{
	srand((unsigned)time(NULL));
	int* arr = calloc(SIZE, sizeof(int));
	if (arr == NULL) exit(-1);
	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = rand() % SCOPE;
		printf("%d ", arr[i]);
	}
	printf("\n");
	ShellSort(arr, SIZE);
	for (int i = 0; i < SIZE; i++)
	{
		printf("%d ", arr[i]);
	}
	free(arr);
	arr = NULL;
}
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
/*<main主函数>*/
int main()
{
	//test_1();
	test_2();
	return 0;
}