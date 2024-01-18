#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
//1、小乐乐与字符串
//①我的解法，但是耗时巨大
int main()
{
	long number = 0;
	char arr[8000] = { 0 };
	scanf("%s", arr);
	long i = 0;//循环数
	for (i = 0; i < strlen(arr); i++)
	{
		if (arr[i] == 0)
			break;
		if (arr[i] == 'C')
		{
			for (long a = i; a < strlen(arr); a++)
			{
				if (arr[a] == 0)
					break;
				if (arr[a] == 'H')
				{
					for (long b = a; b < strlen(arr); b++)
					{
						if (arr[b] == 0)
							break;
						if (arr[b] == 'N')
						{
							number++;
						}
					}
				}
			}
		}
	}
	printf("%ld", number);
	return 0;
}
//②别人的解法，这种解法真的好：获取字符串CHN的必要条件是获取了N，然后才是H，接着才是C，除非找到N，才能组成一个CHN
int main()
{
	char a[8000];
	gets(a);
	long int c = 0, h = 0, n = 0;

	for (int i = 0; i <= strlen(a); i++)
	{
		if (a[i] == 'C')
		{
			c++;
		}
		else if (a[i] == 'H')
		{
			h += c;
		}
		else if (a[i] == 'N')
		{
			n += h;
		}
	}
	printf("%ld", n);

	return 0;
}

//2、矩阵变换（没有完全做对，只能处理二阶行列式）
void f(char t, int x, int y, int(*arr)[10], int n, int m)
{
	int num1 = 0;
	int num2 = 0;
	if (t == 'r')//行行变换
	{
		for (int i = 0; i < m; i++)
		{
			num1 = arr[x - 1][i];
			arr[x - 1][i] = arr[y - 1][i];
			arr[y - 1][i] = num1;
		}	
	}
	else if (t == 'c')//列列变换
	{
		for (int i = 0; i < n; i++)
		{
			num2 = arr[i][x - 1];
			arr[i][x - 1] = arr[i][y - 1];
			arr[i][y - 1] = num2;
		}
	}
}
int main()
{
	int n = 0, m = 0;//n行和m列
	int arr[10][10] = { 0 };//存储行列式数据
	int k = 0;//存储操作次数
	char t = 0;//存储操作字符
	int x = 0, y = 0;//存在被操作的行（列）

	scanf("%d %d", &n, &m);//输入行和列
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &arr[i][j]);
		}
		getchar();//去除换行
	}
	scanf("%d", &k);
	getchar();//去除空格
	while (k)
	{
		scanf("%c", &t);
		getchar();//去除换行
		scanf("%d %d", &x, &y);
		f(t, x, y, arr, n, m);
		k--;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}