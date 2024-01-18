#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
//# 0.����ѧϰĿ��
// 1.�������δ���ĸ��Ӷ�
//		1.1.ʱ�临�Ӷ�
//		1.2.�ռ临�Ӷ�
// 2.����leetcode������ϰ��PTA������Ŀ
//		2.1.��ʧ�����֣�https://leetcode.cn/problems/missing-number-lcci/
//		2.2.��ת���飺https://leetcode.cn/problems/rotate-array/
//		2.3.ɾ���ַ����е����ַ�����https://pintia.cn/problem-sets/14/exam/problems/809
//  3.�޸�C������ҵ����
//		3.1.����ļ��ϣ�https://leetcode.cn/problems/set-mismatch/
//		3.2.�����飺https://www.nowcoder.com/practice/f2fbd8f61c564ca0b5feaa63ab42dae5?tpId=182&tqId=34867&ru=/exam/oj

//# 1.�������δ���ĸ��Ӷȷ���
//> 1.1.����һ��ʱ�临�Ӷȣ�
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
	//��ϸ�����Ļ���ʱ�临�ӶȺ���ʽ��F(N)=N^2+2*N+10
	//����ʱ�临�Ӷȵ��ص㲻����ϸ�Ĵ��������Ǹ�����������һ�����Ӷȷ��࣬���ֻ��Ҫ����ֵ����
	//������������ʱ�临�ӶȾ���O(N^2)���Ǹ��ӶȺ����Ĺ��㣨֮���Թ�������Ϊ��N�㹻��ʱ������N^2��һ�������������Ժ��Բ��ƣ�
}
//> 1.2.�������ʱ�临�Ӷȣ�
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
	//�ú�����ʱ�临�Ӻ���ʽ��F(N)=2*N+10
	//��ʱ�临�Ӷ���O(N)
}
//> 1.3.��������ʱ�临�Ӷȣ�
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
	//���������ʱ�临�Ӷ�ֵ��˼����ע�������������������޷�ȷ��N��M��ԵĴ�С
	//����ʱ�临�Ӷ���O(M+N)�������Ǽ򵥵�O(N)��O(M)�����Ǹ���M��N֮��Ĺ�ϵ������M=N��
}
//> 1.4.�����ģ�ʱ�临�Ӷȣ�
void Func4(int N)
{
	int count = 0;
	for (int k = 0; k < 100; ++k)
	{
		++count;
	}
	printf("%d\n", count);
	//����N�Ƕ��ٶ���ִ�д����޹أ�ִ�д�����100�Σ�Ϊ��������ʱ�临�Ӷ�ΪO(1)����������
}
//> 1.5.�����壨ʱ�临�Ӷȣ�
const char* strchr_1(const char* str, char character)
{
	while (*str != '\0')
	{
		if (*str == character)
			return str;
		++str;
	}
	return NULL;
	//ʱ�临�Ӷ�����ǣ�1���ҵ�
	//ʱ�临�Ӷ�ƽ���ǣ�N/2���ҵ�
	//ʱ�临�Ӷ���ǣ�N���ҵ�
	//ʱ�临�Ӷ�Ҫ�����������������ʱ�临�ӶȾ���O(N)
}
//> 1.6.��������ʱ�临�Ӷȣ�
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
	//ð�������ʱ�临�Ӻ���ʽ�ǣ�F(N)=(N-1)+(N-2)+��1=N*(N-1)/2
	//���ʱ�临�Ӷ���O(N^2)
}
//> 1.7.�����ߣ�ʱ�临�Ӷȣ�
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
	//���ֲ��ҵ�ʱ�临�ӶȾͱȽϡ����ӡ���
	//ֱ�Ӽ������һ��û�ҵ��ͳ���2������ж��ٸ�2�Ͳ��Ҷ��ٴΣ����������x�Σ�ֱ�����絽���һ��Ԫ�أ������������й�ʽn/(2^x)=1����˵õ�������x=ln(n)��
	//���Զ��ֲ��ҵ�ʱ�临�Ӷ���O(ln(N))
}
//> 1.8.����ˣ�ʱ�临�Ӷȣ�
long long Factorial(size_t N)
{
	return N < 2 ? N : Factorial(N - 1) * N;
	//���ú���������N-1�Σ���ʱ�临�Ӷ�ΪO(N)
}
//> 1.9.����ţ��ռ临�Ӷȣ�
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
	//ð������Ŀռ临�Ӷ���O(1)
}
//> 1.10.����ʮһ���ռ临�Ӷȣ�
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
	//�ռ临�Ӷ���O(n)
}
//> 1.11.����ʮ�����ռ临�Ӷȣ�
long long Factorial_1(size_t N)
{
	return N < 2 ? N : Factorial(N - 1) * N;
	//�ռ临�Ӷ���O(n)
}
//> 1.12.����ʮ����ʱ�临�ӶȺͿռ临�Ӷȣ�
long long Fib(size_t n)//쳲���������
{
	if (n < 3)
	{
		return 1;
	}
	return Fib(n - 1) + Fib(n - 2);
	//ʱ�临�Ӷȿ�����Ϊ��O(2^n):n^0+n^1+n^2+n^3+��2^(n-2)��ע�����ǰ���ȫ������ʽ����õ��ģ������Ļ�Ҫ����׼ȷ����Ҫ�ټ���һ����
	//�ռ临�Ӷ���O(n)������O(2^n)���������ں���ջ֡��ԭ�򣬿ռ䱻�����ˣ���Ϊ�ռ���Ա��ظ�ʹ�ã�����ʱ�䲻���ԣ�
}

//# 2.����leetcode������ϰ
//> 2.1.��ʧ������
//  2.1.1.���ķ���
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
//  2.1.2.�Ȳ����нⷨ
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
//> 2.2.��ת����
//  2.2.1.ʹ�ÿ⺯����������֮��
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
//  2.2.2.ʹ��������ת�����ţ�
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
//> 2.3.ɾ�����ַ���
//ʹ�ÿ⺯��strstr�Ϳ⺯��memove��������Լ�ʵ��һ��������������
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
	if (i == 1)//�����û�����ַ����ͷ���1������Ƕ�ף�����������main������Ҫд��ѭ������ʽ������Ҳ����д�ɵݹ����ʽ
		return 1;
	return 0;
}

//# 3.�޸�C������ҵ����
//> 3.1.����ļ���
int int_cmp(const void* p1, const void* p2)
{
	return (*(int*)p1 - *(int*)p2);
}
int* findErrorNums(int* nums, int numsSize, int* returnSize)
{
	int* arr1 = (int*)calloc(numsSize + 1, sizeof(int));//�������
	int* arr2 = (int*)calloc(2, sizeof(int));//��š��ظ������ݡ��͡���ʧ�����ݡ�
	if (!arr1 || !arr2) exit(-1);

	qsort(nums, numsSize, sizeof(int), int_cmp);//����

	for (int i = 0; i < numsSize; i++)
	{
		if (arr1[nums[i]] == 0)
		{
			arr1[nums[i]] = nums[i];
		}
		else if (arr1[nums[i]] == nums[i])
		{
			arr2[0] = nums[i];//�ҵ��ظ�������
		}
	}
	for (int i = 1; i < numsSize + 1; i++)
	{
		if (arr1[i] == 0)//�����ҵ���ʧ������
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
//> 3.2.������
int function()//ȷ��һ�������Ƿ���ȷ
{
	//1.����һ���ַ��ǲ���������
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
	//2.��ʼ��һ���ļ��
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
//	ch = getchar();//ȥ�����з�
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