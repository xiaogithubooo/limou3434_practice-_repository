#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//1、不合格人数
int main()
{
    int i = 0;
    int a, b, c;
    int number = 0;
    int Add = 0;
    scanf("%d", &number);
    for (i = 0; i < number; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        if (((float)(a + b + c) / (float)3) < 60)
        {
            Add++;
        }
    }
    printf("%d", Add);
    return 0;
}
//2、去重且排序的好方法
int main() 
{
    int n, i, input, max = 0;
    int a[100001] = { 0 };
    scanf("%d", &n);

    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &input);
        a[input] = input;// 把相同的数存进相同的数组元素中
        if (input >= max) 
        {            // 这样该数组元素只会保留一个相同的数
            max = input;
        }
    }

    for (i = 1; i <= max; i++) 
    {
        if (a[i]) 
        {             //按序输出非零元素
            printf("%d ", a[i]);
        }
    }
    return 0;
}
//3、走台阶方法
int f(int x)
{
    if (x == 1)
    {
        return 1;
    }
    else if (x == 2)
    {
        return 2;
    }
    else if (x == 0)
    {
        return 0;
    }
    return f(x - 1) + f(x - 2);
}
int main()
{
    int number = 0;
    scanf("%d", &number);
    printf("%d", f(number));
    return 0;
}
//4、任意进制转化
int main()
{
    int number = 0;
    scanf("%d", &number);
    int arr[100] = { 0 };
    int i = 0;

    while (number / 6 != 0)
    {
        arr[i] = number % 6;//得到末尾数，顺序存放
        number /= 6;
        i++;
    }
    arr[i] = number;
    for (int j = i; j >= 0; j--)
    {
        printf("%d", arr[j]);//逆序输出
    }
    return 0;
}