#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
//# 0.本日学习目标
// 1.分析几段代码的复杂度
//		1.1.时间复杂度
//		1.2.空间复杂度
// 2.几道leetcode代码练习和PTA基础题目
//		2.1.消失的数字：https://leetcode.cn/problems/missing-number-lcci/
//		2.2.轮转数组：https://leetcode.cn/problems/rotate-array/
//		2.3.删除字符串中的子字符串：https://pintia.cn/problem-sets/14/exam/problems/809
//  3.修改C语言作业代码
//		3.1.错误的集合：https://leetcode.cn/problems/set-mismatch/
//		3.2.密码检查：https://www.nowcoder.com/practice/f2fbd8f61c564ca0b5feaa63ab42dae5?tpId=182&tqId=34867&ru=/exam/oj

//# 1.分析几段代码的复杂度分析
//> 1.1.代码一（时间复杂度）
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
	//仔细分析的话，时间复杂度函数式是F(N)=N^2+2*N+10
	//但是时间复杂度的重点不是详细的次数，而是给各个函数做一个复杂度分类，因此只需要估算值即可
	//因此这个函数的时间复杂度就是O(N^2)，是复杂度函数的估算（之所以估算是因为当N足够大时，除了N^2这一项，其他项基本可以忽略不计）
}
//> 1.2.代码二（时间复杂度）
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
	//该函数的时间复杂函数式是F(N)=2*N+10
	//故时间复杂度是O(N)
}
//> 1.3.代码三（时间复杂度）
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
	//这个函数的时间复杂度值得思考，注意这里有两个变量，无法确定N和M相对的大小
	//所以时间复杂度是O(M+N)，而不是简单的O(N)或O(M)，除非给定M和N之间的关系（例如M=N）
}
//> 1.4.代码四（时间复杂度）
void Func4(int N)
{
	int count = 0;
	for (int k = 0; k < 100; ++k)
	{
		++count;
	}
	printf("%d\n", count);
	//无论N是多少都对执行次数无关，执行次数是100次，为常数，故时间复杂度为O(1)，代表常数次
}
//> 1.5.代码五（时间复杂度）
const char* strchr_1(const char* str, char character)
{
	while (*str != '\0')
	{
		if (*str == character)
			return str;
		++str;
	}
	return NULL;
	//时间复杂度最好是：1次找到
	//时间复杂度平均是：N/2次找到
	//时间复杂度最坏是：N次找到
	//时间复杂度要算最坏，因此这个函数的时间复杂度就是O(N)
}
//> 1.6.代码六（时间复杂度）
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
	//冒泡排序的时间复杂函数式是：F(N)=(N-1)+(N-2)+…1=N*(N-1)/2
	//因此时间复杂度是O(N^2)
}
//> 1.7.代码七（时间复杂度）
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
	//二分查找的时间复杂度就比较“复杂”了
	//直接计算最坏，一次没找到就除以2，因此有多少个2就查找多少次，假设查找了x次，直到查早到最后一个元素（最坏情况），故有公式n/(2^x)=1，因此得到查早了x=ln(n)次
	//所以二分查找的时间复杂度是O(ln(N))
}
//> 1.8.代码八（时间复杂度）
long long Factorial(size_t N)
{
	return N < 2 ? N : Factorial(N - 1) * N;
	//调用函数调用了N-1次，故时间复杂度为O(N)
}
//> 1.9.代码九（空间复杂度）
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
	//冒泡排序的空间复杂度是O(1)
}
//> 1.10.代码十一（空间复杂度）
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
	//空间复杂度是O(n)
}
//> 1.11.代码十二（空间复杂度）
long long Factorial_1(size_t N)
{
	return N < 2 ? N : Factorial(N - 1) * N;
	//空间复杂度是O(n)
}
//> 1.12.代码十三（时间复杂度和空间复杂度）
long long Fib(size_t n)//斐波那契数列
{
	if (n < 3)
	{
		return 1;
	}
	return Fib(n - 1) + Fib(n - 2);
	//时间复杂度可以认为是O(2^n):n^0+n^1+n^2+n^3+…2^(n-2)，注意这是按照全满的形式计算得到的，如果真的还要计算准确还需要再减少一部分
	//空间复杂度是O(n)而不是O(2^n)，这是由于函数栈帧的原因，空间被复用了（因为空间可以被重复使用，但是时间不可以）
}

//# 2.几道leetcode代码练习
//> 2.1.消失的数字
//  2.1.1.异或的方法
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
//  2.1.2.等差数列解法
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
//> 2.2.轮转数组
//  2.2.1.使用库函数拷贝（次之）
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
//  2.2.2.使用三次旋转（最优）
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
//> 2.3.删除字字符串
//使用库函数strstr和库函数memove（最好是自己实现一下这两个函数）
int deleteSubStr(char* str, const char* sub)
{
	int i = 0;
	int len = strlen(sub);
	char* p = str;
	while ((p = strstr(p, sub)) != NULL)
	{
		memmove(p, p + len, strlen(p + len) + 1);
		i = 1;
	}
	if (i == 1)//如果是没有子字符串就返回1（避免嵌套），这里后面的main函数就要写成循环的形式，不过也可以写成递归的形式
		return 1;
	return 0;
}

//# 3.修改C语言作业代码
//> 3.1.错误的集合
int int_cmp(const void* p1, const void* p2)
{
	return (*(int*)p1 - *(int*)p2);
}
int* findErrorNums(int* nums, int numsSize, int* returnSize)
{
	int* arr1 = (int*)calloc(numsSize + 1, sizeof(int));//存放数据
	int* arr2 = (int*)calloc(2, sizeof(int));//存放“重复的数据”和“消失的数据”
	if (!arr1 || !arr2) exit(-1);

	qsort(nums, numsSize, sizeof(int), int_cmp);//排序

	for (int i = 0; i < numsSize; i++)
	{
		if (arr1[nums[i]] == 0)
		{
			arr1[nums[i]] = nums[i];
		}
		else if (arr1[nums[i]] == nums[i])
		{
			arr2[0] = nums[i];//找到重复的数字
		}
	}
	for (int i = 1; i < numsSize + 1; i++)
	{
		if (arr1[i] == 0)//遍历找到消失的数字
		{
			arr2[1] = i;
			break;
		}
	}
	*returnSize = 2;
	return arr2;
}
//int main()
//{
//	int nums[2] = { 1, 1};
//	int returnSize = 0;
//	findErrorNums(nums, 2, &returnSize);
//	return 0;
//}
//> 3.2.密码检查
int function()//确认一个密码是否正确
{
	//1.检测第一个字符是不是数字类
	char ch = 0;
	ch = getchar();
	if (ch >= '0' && ch <= '9')
	{
		ch = getchar();
		while (ch != '\n')
		{
			ch = getchar();
		}
		return 1;
	}
	//2.开始进一步的检查
	int a = 0, b = 0, c = 0;
	int number = 0;
	while (ch != '\n')
	{
		number++;
		if (ch >= '0' && ch <= '9')
		{
			a = 1;
		}
		else if (ch >= 'A' && ch <= 'Z')
		{
			b = 1;
		}
		else if (ch >= 'a' && ch <= 'z')
		{
			c = 1;
		}
		else
		{
			while (ch != '\n')
			{
				ch = getchar();
			}
			return 1;
		}
		ch = getchar();
	}
	if ((number >= 8) && ((a + b + c) >= 2))
		return 0;
	while (ch != '\n')
	{
		ch = getchar();
	}
	return 1;
}
//int main()
//{
//	int i = 0;
//	char ch = 0;
//	scanf("%d", &i);
//	ch = getchar();//去掉换行符
//	while (i)
//	{
//		if (function() == 0)
//		{
//			printf("YES\n");
//		}
//		else
//		{
//			printf("NO\n");
//		}
//		i--;
//	}
//	return 0;
//}