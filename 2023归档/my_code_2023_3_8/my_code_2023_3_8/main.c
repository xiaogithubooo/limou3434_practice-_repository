#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//日志
//1、测试一个指针的运算题目
//2、测试一个指针的运算题目
//3、查找完全平方数，并且存在重复元素，但是没对……

//1、测试一个指针的运算题目
int main()
{
    int a[4] = { 1, 2, 3, 4 };//创建了一个整型数组
    int* ptr1 = (int*)(&a + 1);//&a是整个数组的地址，+1后就得到一个跳过一整个数组的地址，然后被强制转化为(int*)类型
    int* ptr2 = (int*)((int)a + 1);//a原本是首元素地址，被强制类型转化为int类型，进行的整数上的+1，又被强制转化为int*类型，变成一个地址（地址值多了1，意为着地址指向了下一个字节）
    printf("%x,%x", ptr1[-1], *ptr2);//ptr1[-1]和*(ptr1-1)等价，ptr1[-1]是向前访问了，正好得到数组最后一个元素。而*ptr2，按照int*的指针类型，向后访问4个字节的数据，得到数据(00 00 01 00)2=(4)10
    return 0;
}
//2、测试一个指针的运算题目
int main()
{
    int a[3][2] = { (0, 1), (2, 3), (4, 5) };//逗号表达式，实际存了1、3、5，然后剩下的元素默认为0
    int* p;
    p = a[0];//a[0]是一个数组名字，代表首元素地址，即a[0][0]的地址，类型是int*，正好存入p中
    printf("%d", p[0]);//p[0]等价于*(p+0)，等价于*p，即为1
    return 0;
}
//3、查找完全平方数，并且存在重复元素，但是没对……
#include <math.h>
int function(int N)
{
    int n = N;
    int num = N % 10;//取得最后一位
    N /= 10;
    while (N)
    {
        while (N)
        {
            if (N % 10 == num)
            {
                return 1;
            }
            else
            {
                N /= 10;
            }
        }
        N = n;
    }
    return 0;
}
int IsTheNumber(const int N)
{
    int number = (int)sqrt(N);
    if (number * number == N)//判断是否为完全平方数
    {
        if (function(N))//function返回1,就返回1
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    int n1, n2, i, cnt;

    scanf("%d %d", &n1, &n2);
    cnt = 0;
    for (i = n1; i <= n2; i++) 
    {
        if (IsTheNumber(i))
        {
            cnt++;
            if (cnt == 1||cnt == 2||cnt == 3||cnt == 4||cnt == 5||cnt == 6||cnt == 7||cnt == 8)
            {
                printf("%d ", i);
            }
        }
    }
    printf("\ncnt = %d\n", cnt);

    return 0;
}
