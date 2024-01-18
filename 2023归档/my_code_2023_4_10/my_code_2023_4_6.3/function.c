#include "function.h" 

//# 1.插入排序
//> 1.1.直接插入排序
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
//> 1.2.希尔排序
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

//# 2.选择排序
//> 2.1.直接选择排序（双指针优化版本，是普通的直接选择排序效率的两倍）
/*排序原理：略*/
/*排序总结：略*/
/*排序时间：无论好坏都是O(n^2)，效果比较差*/
//辅助函数，交换函数
void Swap(int* a, int* b)
{
	int tem = *a;
	*a = *b;
	*b = tem;
}
void SelectSort(int* a, int n)
{
	int begin = 0;
	int end = n - 1;
	while (begin < end)
	{
		int min_i = begin;
		int max_i = begin;

		for (int i = begin; i <= end; ++i)
		{
			if (a[i] < a[min_i])
			{
				min_i = i;
			}
			if (a[i] > a[max_i])
			{
				max_i = i;
			}
		}
		Swap(&a[begin], &a[min_i]);
		if (begin == max_i)//如果最大数恰好在开头，经过前面的互换，会将max_x索引上原有的最大值改变，因此需要对最大值的索引做修正
		{
			max_i = min_i;
		}
		Swap(&a[max_i], &a[end]);
		++begin;
		--end;
	}
}
//> 2.2.堆排序
/*排序原理：将一个要排序的数组理解为一棵完全二叉树，然后把数组进行建堆（大堆或小堆），使用了向下调整算法（如果是要变成小堆，则前提是左右小树都是小堆，使用向下调整算法就可以变成小堆（变成大堆也类似））*/
/*排序总结：略*/
/*排序时间：向下调整算法最多调整“树的高度次”，因此时间复杂度是O(log(2)n)，而这里整体堆排序推导比较复杂……以后再推*/
//辅助函数，交换函数（前面有定义）
void Swap(int* a, int* b);
//辅助函数，向下调整算法
void AdjustDwon(int* a, int n, int root)//参数是一个数组指针和数组大小和给一个根节点的下标，该函数假设左右子树都已经是大堆
{
	int parent = root;
	int child = parent * 2 + 1;//默认是左孩子
	while (child < n)//不可以超过存储的数组大小或者超过叶节点
	{
		//以下是选出较大的孩子
		if (child + 1 < n && a[child + 1] > a[child])//如果左孩子比较大，并且不是只有一个左孩子的情况下进入语句（这里是大堆情况，如果是小堆就要改成“<”）
		{
			child += 1;//变成右孩子坐标
		}
		if (a[child] > a[parent])//如果父亲节点比较小就和较大子节点进行交换（这里是大堆情况，改成小堆就要改成“<”）
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
	//利用向下调整法来建大堆
	for (int i = ((n - 1) - 1) / 2; i >= 0; --i)//先从数组后面找到第一个非叶子节点的，然后先对它做向下调整排序，再一直向前面走，对所有节点都进行一次向下调整排序（注意这里i的初始值无论是左孩子还是右孩子都是适用的！！！两个关系公式逆推就变成了一个公式）
	{
		AdjustDwon(a, n, i);
	}

	//使用建大堆来排成升序，取出大堆的根放到数组的最末尾
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);//交换后，原来存储再a[0]位置的数据不再记录到树中
		AdjustDwon(a, end, 0);//使得次大的数变成根节点
		--end;
	}
}

//# 3.交换排序
//> 3.1.冒泡排序
/*排序原理：略*/
/*排序总结：和直接插入比，直接插入好*/
/*排序时间：略*/
//辅助函数，交换函数（前面有定义）
void Swap(int* a, int* b);
void BubbleSort(int* a, int n)
{
	int exchange = 0;
	for (int j = 0; j < n; j++)//这里改成while控制边界都行
	{
		for (int i = 1; i < n - j; ++i)//写排序最好是先写一次遍历，再来考虑多次，就是要注意越界的问题
		{
			if (a[i - 1] > a[i])
			{
				Swap(&a[i - 1], &a[i]);
				exchange = 1;
			}
		}
		if (exchange == 0)//如果没有发生交换，说明数据已经是有序的，不需要在比较了
		{
			break;
		}
	}
}
//> 3.2.快速排序
//3.2.1.挖坑法
/*排序原理：略*/
/*排序总结：在面试的时候就不要写三数取中和小区间优化了，比较耗费时间*/
/*排序时间：O(N*log(2)N)，最坏的情况是有序的（顺序和逆序）*/
//3.2.1.1.快速一次，单指针挖坑法（只是作练习使用）
void PartSort_0(int* a, int n)
{
	int begin = 0;
	int end = n - 1;
	int pivot = begin;
	int key = a[begin];

	while (begin < end)
	{
		//右边找小的数据，并且放在左边
		while (begin < end && a[end] >= key)
		{
			--end;
		}
		a[pivot] = a[end];//将较小数据放入坑里，而自己变成新的坑
		pivot = end;

		//左边找大的数据，并且放在右边
		while (begin < end && a[begin] <= key)
		{
			++begin;
		}
		a[pivot] = a[begin];//将较大数据放入坑里，而自己变成新的坑
		pivot = begin;
	}
	pivot = begin;
	a[pivot] = key;
}
//3.2.1.2.单指针挖坑法
//辅助函数，三数取中法
int GetMidIndex(int* a, int left_begin, int right_end)
{
	int mid = (left_begin + right_end) >> 1;//取平均值
	if (a[left_begin] < a[mid])
	{
		if (a[mid] < a[right_end])
		{
			return mid;
		}
		else if (a[left_begin] > a[right_end])
		{
			return left_begin;
		}
		else
		{
			return right_end;
		}
	}
	else//a[left_begin] > a[mid]
	{
		if (a[mid] > a[right_end])
		{
			return mid;
		}
		else if (a[left_begin] < a[right_end])
		{
			return left_begin;
		}
		else
		{
			return right_end;
		}
	}
}
int PartSort_1(int* a, int left_begin, int right_end)
{
	int index = GetMidIndex(a, left_begin, right_end);//三数取中法，保证快排有序数列的时候不是最坏的情况，返回一个下标
	Swap(&a[left_begin], &a[index]);

	int begin = left_begin;
	int end = right_end;

	int pivot = begin;//坑位
	int key = a[begin];//key的选取有多种来避免最坏的情况：直接选取第一个值（但是遇到有序会很差）、三数取中间值（保证第一个数不是有序的最大最小值）、随机值（纯粹看命…）

	while (begin < end)
	{
		//右边找小的数据，并且放在左边
		while (begin < end && a[end] >= key)
		{
			--end;
		}
		a[pivot] = a[end];//将较小数据放入坑里，而自己变成新的坑
		pivot = end;

		//左边找大的数据，并且放在右边
		while (begin < end && a[begin] <= key)
		{
			++begin;
		}
		a[pivot] = a[begin];//将较大数据放入坑里，而自己变成新的坑
		pivot = begin;
	}
	//在最后的坑放入key
	pivot = begin;
	a[pivot] = key;
	return pivot;//放回坑
}
//3.2.1.3.左右双指针挖坑法
int PartSort_2(int* a, int left_begin, int right_end)
{
	int index = GetMidIndex(a, left_begin, right_end);//使用三数取中法
	Swap(&a[left_begin], &a[index]);

	int begin = left_begin;
	int end = right_end;
	int keyi = begin;

	while (begin < end)
	{
		//从左开始找到比keyi小的
		while (begin < end && a[end] >= a[keyi])
		{
			--end;
		}
		//从右开始找到比keyi大的
		while (begin < end && a[begin] <= a[keyi])
		{
			++begin;
		}
		Swap(&a[begin], &a[end]);
	}
	Swap(&a[begin], &a[keyi]);
	return begin;
}
//3.2.2.前后指针法
int PartSort_3(int* a, int left_begin, int right_end)
{
	int index = GetMidIndex(a, left_begin, right_end);
	Swap(&a[left_begin], &a[index]);

	int keyi = left_begin;//选出key的下标

	int prev = left_begin;//前指针
	int cur = left_begin + 1;//后指针
	while (cur <= right_end)
	{
		if ((a[cur] < a[keyi]) && (++prev!= cur))//这里if语句第二条逻辑表达式是为了避免prev和处于同一个位置也互换的问题（比如[3],1,2,4,0,4这种情况就会发生自己和自己互换的情况）
		{
			//++prev;//这个地方由于判断条件已经写了，所以就不写了，如果删除掉if语句中第二条，就要加回这一句
			Swap(&a[prev], &a[cur]);
		}
		++cur;
	}
	Swap(&a[keyi], &a[prev]);
	return prev;
}

//快排函数主体
void QuickSort(int* a, int left_begin, int right_end)//这里是单独处理一个被分割后的数组
{
	if (left_begin >= right_end)//只有一个元素所以就直接返回
	{
		return;
	}

	//int keyIndex = PartSort_1(a, left_begin, right_end);//单指针挖坑法
	//int keyIndex = PartSort_2(a, left_begin, right_end);//双指针挖坑法
	int keyIndex = PartSort_3(a, left_begin, right_end);//前后指针挖坑法

	//经过第一次递归，下标就会从[left_brgin, right_end]变成[left_begin, keyIndex - 1] keyIndex [keyIndex + 1, right_end]
	//①快排没有优化的版本
	//QuickSort(a, left_begin, keyIndex - 1);
	//QuickSort(a, keyIndex + 1, right_end);
	
	//②这里是对快排的一种优化：小区间优化（判断的是区间的长度，太小就不用快排了（这里是小于10，可以换其他值，但是要依靠数据量来给值，不然真的有可能会退化成直接插入排序），但是可能优化效果不大，在C++内部给了大概10几的样子…）
	if ((keyIndex - 1) - (left_begin) > 10)
	{
		QuickSort(a, left_begin, keyIndex - 1);
	}
	else//当快排到很细的区间的时候就可以让其他排序算法来排序，避免不断的函数栈帧影响效率
	{
		//选直接插入排序比较好
		InsertSort(a + left_begin, ((keyIndex - 1) - (left_begin) + 1));//注意这里的写法
	}
	if ((right_end - (keyIndex + 1)) > 10)
	{
		QuickSort(a, keyIndex + 1, right_end);
	}
	else
	{
		InsertSort(a + keyIndex + 1, ((right_end) - (keyIndex + 1) + 1));//注意这里的写法
	}
}


//# 4.归并排序
//> 4.1.归并排序
/*排序原理：略*/
/*排序总结：*/
/*排序时间：*/
//辅助函数：子函数
void _MergeSort(int* a, int left_begin, int right_end, int* tmp)
{
	if (left_begin > right_end)
		return;
	int mid = (left_begin + right_end) >> 1;//求平均值
	//假设[left_begin, mid][mid + 1, right_end]有序，那就开始归并
	_MergeSort(a, left_begin, mid, tmp);
	_MergeSort(a, mid + 1, right_end, tmp);

	int begin1 = left_begin, end1 = mid;
	int begin2 = mid + 1, end2 = right_end;
	int index = left_begin;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[index++] = a[begin1++];
		}
		else
		{
			tmp[index++] = a[begin2++];
		}
	}
	//上面循环后，如果两个数组大小不一样，则一定有一个还没到结尾，这个时候把还没到结尾的那个数组后续的内容全部拷贝下来，因此下面两个循环只会执行一个
	while (begin1 <= end1)
	{
		tmp[index++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[index++] = a[begin2++];
	}
	//最后还需要将malloc的数组内容拷贝回去（这个数组只是辅助存储的）
	for (int i = left_begin; i <= right_end; ++i)
	{
		a[i] = tmp[i];
	}
}
void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	_MergeSort(a, 0, n - 1, tmp);
	free(tmp);
}
