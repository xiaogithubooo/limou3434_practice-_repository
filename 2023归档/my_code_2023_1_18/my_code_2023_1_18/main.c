#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//1、牛客网题目：HTTP状态编码
int main()
{
	int number = 0;
	while (scanf("%d", &number) == 1)
	{
		switch (number)
		{
		case 200:
			printf("OK\n");
			break;
		case 202:
			printf("Accepted\n");
			break;
		case 400:
			printf("Bad Request\n");
			break;
		case 403:
			printf("Forbidden\n");
			break;
		case 404:
			printf("Not Found\n");
			break;
		case 500:
			printf("Internal Server Error\n");
			break;
		case 502:
			printf("Bad Gateway\n");
			break;
		default:
			break;
		}
	}
	return 0;
}
//2、牛客网题目：打印X形
int main()
{
    int number = 0;
    char arr[20][20] = { 0 };
    while (scanf("%d", &number) == 1)
    {
        for (int i = 1; i <= number; i++)
        {
            for (int j = 1; j <= number; j++)
            {
                if (i-1 == j-1)
                {
                    arr[i-1][j-1] = '*';
                }
                else if (i + j == number+1)
                {
                    arr[i-1][j-1] = '*';
                }
                else
                {
                    arr[i-1][j-1] = ' ';
                }
            }
        }

        for (int x = 0; x < number; x++)
        {
            for (int y = 0; y < number; y++)
            {
                printf("%c", arr[x][y]);
            }
            printf("\n");
        }
    }
    return 0;
}
////3、设置C的函数
long long fun(int x)
{
	if (x == 1 || x == 0)
	{
		return 1;
	}
	return x*fun(x-1);
}
int main()
{
	int number = 0;
	int scanf_number = scanf("%d", &number);//输入行数
	for (int n = 0; n < number; n++)//"行数"一一对应"次数"
	{
		for (int k = 0; k <= n; k++)//递归
		{
			printf("%5lld",(fun(n)) / ((fun(k)) * (fun(n - k))));//得出一个数
		}
		printf("\n");
	}
	return 0;
}
//4、最小公倍数的求解
//注意：最小公倍数*最大公约数=两数之乘积
#include <stdio.h>
int function(int x, int y)//最大公约数
{
	if (x > y)
	{
		for (int i = y; i > 0; i--)
		{
			if (x % i == 0 && y % i == 0)//整除了
			{
				return i;
			}
		}
	}
	else if (x < y)
	{
		for (int i = x; i > 0; i--)
		{
			if (y % i == 0 && x % i == 0)
			{
				return i;
			}
		}
	}
	else if (x == y)
	{
		return x;
	}
}
int main()
{
	int number_1 = 0, number_2 = 0;
	int scafn_number = scanf("%d %d", &number_1, &number_2);
	int Max = function(number_1, number_2);
	int Min = (number_1 * number_2) / Max;

	printf("%d", Max + Min);
	return 0;
}//（但是在CSDN里面编译失败了……）
//5、空心矩形
int main()
{
    int number = 0;

    while (scanf("%d", &number) == 1)
    {
        for (int i = 1; i <= number; i++)
        {
            if (i == 1 || i == number)
            {
                for (int j = 0; j < number; j++)
                    printf("* ");
            }
            else
            {
                for (int j = 0; j < number; j++)
                {
                    if (j == 0 || j == number - 2)
                    {
                        printf("* ");
                    }
                    printf("  ");
                }
            }
            printf("\n");
        }
    }

    return 0;
}
//6、空心三角形
int main()
{
    int number = 0;
    while (1 == scanf("%d", &number))
    {
        for (int i = 0; i < number - 1; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (j == 0 || j == i)
                {
                    printf("* ");
                }
                else
                {
                    printf("  ");
                }
            }
            printf("\n");
        }
        for (int z = 0; z < number; z++)
        {
            printf("* ");
        }
        printf("\n");
    }

    return 0;
}
//7、数字三角形
int main()
{
    int number = 0;
    while (scanf("%d", &number) == 1)
    {
        for (int i = 0; i < number; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                printf("%d ", j + 1);
            }
            printf("\n");
        }
    }
    return 0;
}
//8、密码验证
#include <string.h>
int main()
{
    char arr_name[30] = "admin";
    char arr_number[30] = "admin";
    char arr_name_1[30];
    char arr_number_1[30];
    scanf("%s", arr_name_1);
    scanf("%s", arr_number_1);
    if ((strcmp(arr_number, arr_number_1) == 0) && (strcmp(arr_name, arr_name_1) == 0))
    {
        printf("Login Success!\n");
    }
    else
    {
        printf("Login Fail!\n");
    }

    return 0;
}