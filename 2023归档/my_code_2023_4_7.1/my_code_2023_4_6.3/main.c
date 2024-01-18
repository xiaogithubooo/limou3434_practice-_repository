#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 1000000
#define SCOPE 1000
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
/*<排序算法>*/
//1.插入排序
//1.1.直接插入排序
/*排序原理：将第一个当作有序，后面的数逐步上前，继续保持有序，即：[0, end]是有序的，在end + 1的位置的值插入进去，让[0, end + 1]也有序*/
/*排序总结：利用for循环记录下每次已排序好序列的最后一个下标，记录要新插入的数据，将其和已排序的序列对比，（在原来存放数据的空间和新增的1块空间中）挪动序列保证有一个空位留给新插入的*/
/*排序时间：①情况最坏，挪动次数为(1+2+3+…(n-1))，由等差数列公式求得时间复杂度为O(n^2)
		   ②情况最好，顺序有序的时候，时间复杂度为O(n)*/
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
/*排序总结：略*/
/*排序时间：①gap在减少的时候，除以多少个2就循环了多少次，假设为x次，那么1 == n / (2^x)，故循环了x == log(2)N次，如果是除于3就是O(log(3)N)次
		   ②当gap最大的时候第二个循环差不多运行了O(n)，当gap最小的时候第二个循环也差不多接近运行了O(n)
		   ③总体来看时间复杂度为O(log(2)N*N)，另外平均为O(N*1.3)
		   */
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
//2.1.直接选择排序
//2.2.堆排序
/*排序原理：将一个要排序的数组理解为一棵完全二叉树，然后把数组进行建堆（大堆或小堆），使用了向下调整算法（如果是要变成小堆，则前提是左右小树都是小堆，使用向下调整算法就可以变成小堆（变成大堆也类似））*/
/*排序总结：略*/
/*排序时间：建堆的时间复杂度是O(N)*/
//辅助函数，交换函数
void Swap(int* a, int* b)
{
	int tem = *a;
	*a = *b;
	*b = tem;
}
//辅助函数，向下调整算法
void AdjustDwon(int* a, int n, int root)//参数是一个数组指针和数组大小和给一个根节点的下标，该函数假设左右子树都已经是小堆
{
	int parent = root;
	int child = parent * 2 + 1;//默认是左孩子
	while (child < n)//不可以超过存储的数组大小或者超过叶节点
	{
		//以下是选出较小的孩子
		if (child + 1 < n && a[child + 1] > a[child])//如果左孩子比较大，并且不是只有一个左孩子的情况下进入语句（这里是大堆情况，如果是小堆就要改成“<”）
		{
			child += 1;//变成右孩子坐标
		}
		if (a[child] > a[parent])//如果父亲节点比较大就和较小子节点进行交换（这里是大堆情况，改成小堆就要改成“<”）
		{
			Swap(&a[child], &a[parent]);

			//跟新新的父节点和默认左节点 
			parent = child;
			child = parent * 2 + 1;
		}
		else//说明整棵树都是小堆了，不用继续了，直接跳出就可以
		{
			break; 
		}
	}
}
void HeapSort(int* a, int n)
{
	//利用向下调整法来建堆
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)//先从数组后面找到第一个非叶子节点的，然后先对它做向下调整排序，再一直向前面走，对所有节点都进行一次向下调整排序
	{
		AdjustDwon(a, n, i);
	}

	//使用建大堆来排成升序
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);//交换后，原来存储再a[0]位置的数据不再记录到树中
		AdjustDwon(a, end, 0);//使得次大的数变成根节点
		--end;
	}
}

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
	printf("\n\n");
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
	printf("\n\n");
	ShellSort(arr, SIZE);
	for (int i = 0; i < SIZE; i++)
	{
		printf("%d ", arr[i]);
	}
	free(arr);
	arr = NULL;
}
//4、堆排序测试
void test_3(void)
{
	srand((unsigned)time(NULL));
	int* arr = calloc(SIZE, sizeof(int));
	if (arr == NULL) exit(-1);
	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = rand() % SCOPE;
		printf("%d ", arr[i]);
	}
	printf("\n\n");
	HeapSort(arr, SIZE);
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
	//test_2();
	test_3();
	return 0;
}