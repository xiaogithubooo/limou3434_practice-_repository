#define _CRT_SECURE_NO_WARNINGS

//试除法(利用偶素数特性)
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

//判断一个数是否为素数
int IsPrime(int number)
{
    //小于等于 1 的数一定不是素数
    if (number <= 1)
    {
        return 0;
    }

    //偶数中是 2 的直接判断为素数, 否则直接判断为非素数
    if (number % 2 == 0)
    {
        if (number == 2)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    //能被整除则不是素数
    for (int i = 2; i <= sqrt(number); i++)
    {
        if (number % i == 0)
        {
            return 0;
        }
    }

    //代码走到这里就说明 number 一定是素数
    return 1;
}

int main()
{
    for (int num = 0; num < 100; num++)
    {
        if (IsPrime(num))
        {
            printf("%d is a prime number.\n", num);
        }
        else
        {
            printf("%d is not a prime number.\n", num);
        }
    }

    return 0;
}