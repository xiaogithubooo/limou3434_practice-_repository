#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//日志：刷题并且优化代码
//1、PTA题目：超速判断，https://pintia.cn/problem-sets/14/exam/problems/788
//2、逻辑转化问题：猜名次
//3、杨氏矩阵
//4、杨辉三角
//5、暴力旋字符数组
//6、双指针三旋转字符串

//1、PTA题目：超速判断，https://pintia.cn/problem-sets/14/exam/problems/788
int main()
{
    int number = 0;
    scanf("%d", &number);
    if (number > 60)
    {
        printf("Speed: %d - Speeding\n", number);
    }
    else
    {
        printf("Speed: %d - OK\n", number);
    }
    return 0;
}
//2、逻辑转化问题：猜名次
int main()
{
	int a, b, c, d, e;
	for (a = 0; a <= 5; a++)
	{
		for (b = 0; b <= 5; b++)
		{
			for (c = 0; c <= 5; c++)
			{
				for (d = 0; d <= 5; d++)
				{
					for (e = 0; e <= 5; e++)
					{
						if (
							((b == 2) + (a == 3) == 1) &&//A选手说：B第二，我第三
							((b == 2) + (e == 4) == 1) &&//B选手说：我第二，E第四
							((c == 1) + (d == 2) == 1) &&//C选手说：我第一，D第二
							((c == 5) + (d == 3) == 1) &&//D选手说：C最后，我第三
							((e == 4) + (a == 1) == 1)	 //E选手说：我第四，A第一
							)
						{
							if (a * b * c * d * e == 120)
							{
								printf("a=%d b=%d c=%d d=%d e=%d\n", a, b, c, d, e);
							}
						}
					}
				}
			}
		}
	}
	return 0;
}
//3、杨氏矩阵
int find_num(int arr[3][3], int r, int c, int k)//数组，行，列，被查找的数
{
    int x = 0;
    int y = c - 1;

    while (x <= r - 1 && y >= 0)
    {
        if (arr[x][y] < k)
        {
            x++;
        }
        else if (arr[x][y] > k)
        {
            y--;
        }
        else
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
    int arr[3][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int k = 0;
    scanf("%d", &k);
    int ret = find_num(arr, 3, 3, k);
    if (ret == 1)
    {
        printf("存在\n");
    }
    else
    {
        printf("不存在\n");
    }
    return 0;
}
int find_num(int arr[3][3], int* px, int* py, int k)
{
    int x = 0;
    int y = *py - 1;

    while (x <= *px - 1 && y >= 0)
    {
        if (arr[x][y] < k)
        {
            x++;
        }
        else if (arr[x][y] > k)
        {
            y--;
        }
        else
        {
            *px = x;
            *py = y;
            return 1;
        }
    }
    return 0;
}
int main()
{
    int arr[3][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int k = 0;
    scanf("%d", &k);

    int x = 3;
    int y = 3;
    int ret = find_num(arr, &x, &y, k);
    if (ret == 1)
    {
        printf("存在，其下标为：%d %d\n", x, y);
    }
    else
    {
        printf("不存在\n");
    }
}
//4、杨辉三角
int main()
{
	int arr[10][10] = { 0 };
	int i = 0;
	int j = 0;
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < i; j++)
		{
			if (j == 0)
			{
				arr[i][j] = 1;
			}
			if (i == j)
			{
				arr[i][j] = 1;
			}
			if (i >= 2 && j >= 1)
			{
				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
			}
		}
	}
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < i; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}
//5、暴力旋字符数组
#include <string.h>
void function(char arr[], int k)
{
    int i = 0;
    int len = strlen(arr);
    k %= len;//避免重复

    for (i = 0; i < k; i++)
    {
        char tmp = arr[0];
        int j = 0;
        for (j = 0; j < len - 1; j++)
        {
            arr[j] = arr[j + 1];
        }
        arr[len - 1] = tmp;
    }
}
int main()
{
    char arr[20] = "abcdef";

    int k = 0;
    scanf("%d", &k);

    function(arr, k);

    printf("%s", arr);
    return 0;
}
//6、双指针三旋转字符串
#include <assert.h>
void reverse(char* left, char* right)
{
	assert(left && right);
	while (left < right)
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}
void left_move(char arr[], int k)
{
	int len = strlen(arr);
	k %= len;
	reverse(arr, arr + k - 1);
	reverse(arr + k, arr + len - 1);
	reverse(arr, arr + len - 1);
}
int main()
{
	char arr[20] = "abcdef";
	int k = 0;
	scanf("%d", &k);
	left_move(arr, k);
	printf("%s\n", arr);
	return 0;
}
