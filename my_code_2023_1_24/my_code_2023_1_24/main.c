#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//1、上三角矩阵判断
int main()
{
    int number = 0;
    int add = 0;
    scanf("%d", &number);
    int A = number;
    int B = 0;
    int arr[50][50] = { 0 };
    while (A--)
    {
        B += A;
    }

    for (int i = 0; i < number; i++)
    {
        for (int j = 0; j < number; j++)
        {
            scanf("%d", &arr[i][j]);
            if ((i > j) && (arr[i][j] == 0))
            {
                add++;
            }
        }
    }
    if (add == B)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
    return 0;
}
//2、检验相同矩阵
int main()
{
    int arr_1[100] = { 0 };
    int arr_2[100] = { 0 };
    int number_1 = 0, number_2 = 0;
    int boolnumber = 0;
    scanf("%d %d", &number_1, &number_2);
    for (int i = 0; i < number_1 * number_2; i++)
    {
        scanf("%d", &arr_1[i]);
    }
    for (int i = 0; i < number_1 * number_2; i++)
    {
        scanf("%d", &arr_2[i]);
        if (arr_2[i] != arr_1[i])
        {
            boolnumber = 1;
        }
    }
    if (boolnumber == 1)
    {
        printf("No\n");
    }
    else
    {
        printf("Yes\n");
    }
    return 0;
}
//3、最高身高
#include <stdio.h>

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    int number = 0;
    int max = 0;

    int arr[200] = { 0 };
    for (int i = 0; i < a * b; i++)
    {
        scanf("%d", &number);
        arr[number] = number;
    }
    for (int i = 0; i < a * b; i++)
    {
        if ((arr[i] != 0) && (arr[i] > max))
        {
            max = arr[i];
        }
    }
    printf("%d", max);
    return 0;
}//失败了……
int main()
{
    int n, m, a[100], i, max = 0, x, y;
    while (scanf("%d %d", &n, &m) == 2)
    {
        for (i = 0; i < n * m; i++)
        {
            scanf("%d", &a[i]);
            if (a[i] > max)
            {
                max = a[i];
                x = i / m + 1;
                y = i % m + 1;
            }
        }
        printf("%d %d\n", x, y);
    }
}
//4、身高求和
int main()
{
    float arr[5 * 5] = { 0 };
    float arr_x[5] = { 0 };
    int j = 0;
    for (int i = 0; i < 25; i++)
    {
        scanf("%f", &arr[i]);
    }
    for (int i = 0; i < 25; i++)
    {
        arr_x[j] += arr[i];
        printf("%.1f ", arr[i]);
        if (i == 4 || i == 9 || i == 14 || i == 19 || i == 24)
        {
            printf("%.1f\n", arr_x[j]);
            j++;
        }
    }
    return 0;
}
//5、矩阵元素定位
int main()
{
	int n = 0, m = 0;//n行和m列
	int arr[10][10] = { 0 };//存储行列式数据

	int x = 0, y = 0;//存在被操作的行（列）

	scanf("%d %d", &n, &m);//输入行和列
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	scanf("%d %d", &x, &y);
	printf("%d", arr[x - 1][y - 1]);
	return 0;
}
//6、有序序列合并
#include <stdio.h>

int main()
{
    int arr_1[50] = { 0 };
    int arr_2[50] = { 0 };
    int arr[100] = { 0 };
    int a = 0;
    int b = 0;

    int number_1 = 0;
    int number_2 = 0;

    scanf("%d %d", &number_1, &number_2);

    for (int i = 0; i < number_1; i++)
    {
        scanf("%d", &arr_1[i]);
    }
    for (int j = 0; j < number_2; j++)
    {
        scanf("%d", &arr_2[j]);
    }

    for (int z = 0; z < number_1 + number_2; z++)
    {
        if (arr_1[a] > arr_2[b])
        {
            arr[z] = arr_2[b];
            b++;
        }
        else
        {
            arr[z] = arr_1[a];
            a++;
        }

    }
    return 0;
}
//7、矩阵交换
#include<stdio.h>
int main()
{
	int n, m, a[10][10], k, p, q, i, j, s;
	char t;
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}

	scanf("%d", &k);

	for (s = 0; s < k; s++) 
	{
		scanf(" %c %d %d", &t, &p, &q);
		if (t == 'r')
		{
			for (j = 0; j < m; j++) 
			{
				a[p - 1][j] += a[q - 1][j];
				a[q - 1][j] = a[p - 1][j] - a[q - 1][j];
				a[p - 1][j] -= a[q - 1][j];
			}
		}
		if (t == 'c')
		{
			for (i = 0; i < n; i++) 
			{
				a[i][p - 1] += a[i][q - 1];
				a[i][q - 1] = a[i][p - 1] - a[i][q - 1];
				a[i][p - 1] -= a[i][q - 1];
			}
		}
	}
	for (i = 0; i < n; i++) 
	{
		for (j = 0; j < m; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
#include <stdio.h>
long long function(int x, int y)//最大公约数
{
	long long i = 0;
	if (x > y)
	{
		for (i = y; i > 0; i--)
		{
			if (x % i == 0 && y % i == 0)//整除了
			{
				return i;//得到公因数
			}
		}
	}
	else if (x < y)
	{
		for (i = x; i > 0; i--)
		{
			if (y % i == 0 && x % i == 0)
			{
				return i;//得到公因数
			}
		}
	}
	return x;
}
int main()
{
	long long number_1 = 0, number_2 = 0;
	long long MAX = 0;
	long long MIN = 0;
	scanf("%lld %lld", &number_1, &number_2);
	MAX = function(number_1, number_2);
	MIN = (number_1 * number_2) / MAX;

	printf("%lld", MAX + MIN);
	return 0;
}