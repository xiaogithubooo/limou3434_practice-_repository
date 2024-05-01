#define _CRT_SECURE_NO_WARNINGS

//�Գ���(����ż��������)
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

//�ж�һ�����Ƿ�Ϊ����
int IsPrime(int number)
{
    //С�ڵ��� 1 ����һ����������
    if (number <= 1)
    {
        return 0;
    }

    //ż������ 2 ��ֱ���ж�Ϊ����, ����ֱ���ж�Ϊ������
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

    //�ܱ�������������
    for (int i = 2; i <= sqrt(number); i++)
    {
        if (number % i == 0)
        {
            return 0;
        }
    }

    //�����ߵ������˵�� number һ��������
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