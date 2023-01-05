#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//1、牛客网题目：去重整数并排序
int main()
{
    //输入数据部分
    int n = 0;
    int arr[100] = { 0 };
    int t = 0;//存储单个数据
    scanf("%d", &n);
    if (n >= 1 && n <= 1000)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
    }
    else
    {
        return 0;
    }
    //使得重复数据变成-1
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i] == arr[j] && (i != j))
            {
                arr[j] = -1;
            }
        }
    }
    //n次排序大-小
    int g = 0;
    int nub = n;
    while (nub)
    {
        for (int i = 0; i < n; i++)
        {
            if (arr[i] < arr[i + 1])
            {
                g = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = g;
            }
        }
        nub--;
    }
    //倒着输出
    for (int i = n; i >= 0; i--)
    {
        if (arr[i] != -1 && arr[i] != 0)
        {
            printf("%d ", arr[i]);
        }

    }
    return 0;
}

//2、小乐乐改数字
int main()
{
    int arr[100] = { 0 };
    int y = 0;
    int n = 0;
    int i = 0;

    int a = 0, b = 0;
    scanf("%d", &n);
    do
    {
        y = n % 10;
        n = n / 10;
        
        if (y % 2 == 0)//偶为0
        {
            arr[i] = 0;
        }
        else
        {
            arr[i] = 1;
        }
        i++;
    } while (n);
    int X = 0;
    for (int g = i - 1; g >= 0; g--)
    {
        if (arr[g] == 0 && X == 0)
        {
            continue;
        }
        else
        {
            X = g;
            printf("%d", arr[g]);
        }
    }
    return 0;
}//我脑抽写出这种鬼代码，还过了……

//3、找出三位数里的所有质数
int main()
{
    int a = 0, b = 0;
    int i = 0;
    for (a = 100; a < 1000; a++)
    {
        for (b = 2; b < a; b++)
        {
            if (a % b != 0)
            {
                continue;
            }
            else if (a % b == 0)
            {
                i++;
                break;
            }
        }
    }
    printf("%d", 900 - i);

    return 0;
}