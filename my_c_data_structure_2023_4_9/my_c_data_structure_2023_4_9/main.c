#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
//todo 0.本日学习目标
/*
* 本次要学习的任务是
* 1.分析几段代码的复杂度
* （1）时间复杂度
* （2）空间复杂度
* 2.几道leetcode代码练习
* （1）消失的数字：https://leetcode.cn/problems/missing-number-lcci/
* （2）轮转数组：https://leetcode.cn/problems/rotate-array/
* 3.修改C语言作业代码
* （1）错误的集合：https://leetcode.cn/problems/set-mismatch/
* （2）密码检查：https://leetcode.cn/problems/set-mismatch/
*/
//todo 1.分析几段代码的复杂度分析
//? 1.1.代码一（时间复杂度）
void Func1(int N)
{
	int count = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			++count;
		}
	}
	for (int k = 0; k < 2 * N; ++k)
	{
		++count;
	}
	int M = 10;
	while (M--)
	{
		++count;
	}
	printf("%d\n", count);
}
//? 1.2.代码二（时间复杂度）
void Func2(int N)
{
	int count = 0;
	for (int k = 0; k < 2 * N; ++k)
	{
		++count;
	}
	int M = 10;
	while (M--)
	{
		++count;
	}
	printf("%d\n", count);
}
//? 1.3.代码三（时间复杂度）
void Func3(int N, int M)
{
	int count = 0;
	for (int k = 0; k < M; ++k)
	{
		++count;
	}
	for (int k = 0; k < N; ++k)
	{
		++count;
	}
	printf("%d\n", count);
}
//? 1.4.代码四（时间复杂度）
void Func4(int N)
{
	int count = 0;
	for (int k = 0; k < 100; ++k)
	{
		++count;
	}
	printf("%d\n", count);
}
//? 1.5.代码五（时间复杂度）
const char* strchr_1(const char* str, char character)
{
	while (*str != '\0')
	{
		if (*str == character)
			return str;
		++str;
	}
	return NULL;
}
//? 1.6.代码六（时间复杂度）
//辅助函数
void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void BubbleSort(int* a, int n)
{
	assert(a);
	for (size_t end = n; end > 0; --end)
	{
		int exchange = 0;
		for (size_t i = 1; i < end; ++i)
		{
			if (a[i - 1] > a[i])
			{
				Swap(&a[i - 1], &a[i]);
				exchange = 1;
			}
		}
		if (exchange == 0)
			break;
	}
}
//? 1.7.代码七（时间复杂度）
int BinarySearch(int* a, int n, int x)
{
	assert(a);
	int begin = 0;
	int end = n;
	while (begin < end)
	{
		int mid = begin + ((end - begin) >> 1);
		if (a[mid] < x)
			begin = mid + 1;
		else if (a[mid] > x)
			end = mid;
		else
			return mid;
	}
	return -1;
}
//? 1.8.代码八（时间复杂度）
long long Factorial(size_t N)
{
	return N < 2 ? N : Factorial(N - 1) * N;
}
//? 1.9.代码九（空间复杂度）
void BubbleSort_1(int* a, int n)
{
	assert(a);
	for (size_t end = n; end > 0; --end)
	{
		int exchange = 0;
		for (size_t i = 1; i < end; ++i)
		{
			if (a[i - 1] > a[i])
			{
				Swap(&a[i - 1], &a[i]);
				exchange = 1;
			}
		}
		if (exchange == 0)
			break;
	}
}
//? 1.10.代码十一（空间复杂度）
long long* Fibonacci(size_t n)
{
	if (n == 0)
		return NULL;
	long long* fibArray = (long long*)malloc((n + 1) * sizeof(long long));
	fibArray[0] = 0;
	fibArray[1] = 1;
	for (int i = 2; i <= n; ++i)
	{
		fibArray[i] = fibArray[i - 1] + fibArray[i - 2];
	}
	return fibArray;
}
//? 1.11.代码十二（空间复杂度）
long long Factorial_1(size_t N)
{
	return N < 2 ? N : Factorial(N - 1) * N;
}

//todo 2.几道leetcode代码练习
//? 2.1.消失的数字
//? 2.1.1.异或的方法
int missingNumber(int* nums, int numsSize)
{
	int k = 0;
	int i = 0;
	for (int i = 0; i < numsSize; i++)
	{
		k ^= (nums[i] ^ i);
	}
	k ^= numsSize;
	return k;
}
//? 2.1.2.等差数列解法
int missingNumber_x(int* nums, int numsSize)
{
	int add_1 = 0;
	int add_2 = 0;
	add_1 = ((0 + numsSize) * (numsSize + 1)) / 2;
	for (int i = 0; i < numsSize; i++)
	{
		add_2 += nums[i];
	}
	return add_1 - add_2;
}

//? 2.2.轮转数组
//? 2.2.1.使用库函数
void rotate(int* nums, int numsSize, int k)
{
	int* double_nums = (int*)malloc(sizeof(int) * 2 * numsSize);
	memmove(double_nums, nums, numsSize * sizeof(int));
	memmove(double_nums + numsSize, nums, numsSize * sizeof(int));
	k = k % numsSize;//避免k过大做重复得事情
	memmove(nums, double_nums + (numsSize - k), numsSize * sizeof(int));
	free(double_nums);
	double_nums = NULL;
}
//? 2.2.2.使用三次旋转
//辅助函数，实现一个函数让数组反转
void Reverse(int* nums, int left, int right)
{
	while (left < right)
	{
		int tmp = nums[left];
		nums[left] = nums[right];
		nums[right] = tmp;
		left++;
		right--;
	}
}
//轮转数组函数
void rotate_x(int* nums, int numsSize, int k)
{
	//处理过大的k
	k %= numsSize;
	//先对整个数组旋转
	Reverse(nums, 0, numsSize - 1);
	//在对[0,k - 1][k,numsSize - 1]前后这两部分旋转
	Reverse(nums, 0, k - 1);
	Reverse(nums, k, numsSize - 1);
}
//x 有一说一这貌似是第一次靠自己写出leetcode的时候，请加油hhhhhh
//todo 3.修改C语言作业代码
//? 3.1.错误的集合

//? 3.2.密码检查
int main() 
{
	int i = 0;
	int k = 0;
	scanf("%d", &i);

	while (i)
	{
		char ch = 0;
		getchar();
		scanf("%c", &ch);
		if (ch >= '0' && ch <= '9')
		{
			printf("NO\n");
			return 0;
		}
		k++;

		int a = 0;
		int b = 0;
		int c = 0;


		while (scanf("%c", &ch) == 1)
		{
			if (ch >= 'A' && ch <= 'Z')
			{
				a = 1;
			}
			if (ch > 'a' && ch < 'z')
			{
				b = 1;
			}
			if (ch >= '0' && ch <= '9')
			{
				c = 1;
			}
			k++;
		}
		if (k >= 8 && a + b + c >= 2)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
		i--;
	}
	return 0;
}