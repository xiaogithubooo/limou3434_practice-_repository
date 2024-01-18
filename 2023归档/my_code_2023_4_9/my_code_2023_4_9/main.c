#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
//todo 0.����ѧϰĿ��
/*
* ����Ҫѧϰ��������
* 1.�������δ���ĸ��Ӷ�
* ��1��ʱ�临�Ӷ�
* ��2���ռ临�Ӷ�
* 2.����leetcode������ϰ
* ��1����ʧ�����֣�https://leetcode.cn/problems/missing-number-lcci/
* ��2����ת���飺https://leetcode.cn/problems/rotate-array/
* 3.�޸�C������ҵ����
* ��1������ļ��ϣ�https://leetcode.cn/problems/set-mismatch/
* ��2�������飺https://leetcode.cn/problems/set-mismatch/
*/
//todo 1.�������δ���ĸ��Ӷȷ���
//? 1.1.����һ��ʱ�临�Ӷȣ�
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
//? 1.2.�������ʱ�临�Ӷȣ�
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
//? 1.3.��������ʱ�临�Ӷȣ�
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
//? 1.4.�����ģ�ʱ�临�Ӷȣ�
void Func4(int N)
{
	int count = 0;
	for (int k = 0; k < 100; ++k)
	{
		++count;
	}
	printf("%d\n", count);
}
//? 1.5.�����壨ʱ�临�Ӷȣ�
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
//? 1.6.��������ʱ�临�Ӷȣ�
//��������
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
//? 1.7.�����ߣ�ʱ�临�Ӷȣ�
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
//? 1.8.����ˣ�ʱ�临�Ӷȣ�
long long Factorial(size_t N)
{
	return N < 2 ? N : Factorial(N - 1) * N;
}
//? 1.9.����ţ��ռ临�Ӷȣ�
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
//? 1.10.����ʮһ���ռ临�Ӷȣ�
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
//? 1.11.����ʮ�����ռ临�Ӷȣ�
long long Factorial_1(size_t N)
{
	return N < 2 ? N : Factorial(N - 1) * N;
}

//todo 2.����leetcode������ϰ
//? 2.1.��ʧ������
//? 2.1.1.���ķ���
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
//? 2.1.2.�Ȳ����нⷨ
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

//? 2.2.��ת����
//? 2.2.1.ʹ�ÿ⺯��
void rotate(int* nums, int numsSize, int k)
{
	int* double_nums = (int*)malloc(sizeof(int) * 2 * numsSize);
	memmove(double_nums, nums, numsSize * sizeof(int));
	memmove(double_nums + numsSize, nums, numsSize * sizeof(int));
	k = k % numsSize;//����k�������ظ�������
	memmove(nums, double_nums + (numsSize - k), numsSize * sizeof(int));
	free(double_nums);
	double_nums = NULL;
}
//? 2.2.2.ʹ��������ת
//����������ʵ��һ�����������鷴ת
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
//��ת���麯��
void rotate_x(int* nums, int numsSize, int k)
{
	//��������k
	k %= numsSize;
	//�ȶ�����������ת
	Reverse(nums, 0, numsSize - 1);
	//�ڶ�[0,k - 1][k,numsSize - 1]ǰ������������ת
	Reverse(nums, 0, k - 1);
	Reverse(nums, k, numsSize - 1);
}
//x ��һ˵һ��ò���ǵ�һ�ο��Լ�д��leetcode��ʱ�������hhhhhh
//todo 3.�޸�C������ҵ����
//? 3.1.����ļ���

//? 3.2.������
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