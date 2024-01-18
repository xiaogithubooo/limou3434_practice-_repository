#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int function(int number_1, int number_2)//求两个数的公倍数
{
    int x = 0;
    int i = 0;
    if (number_1 <= number_2)
    {
        x = number_1;
        for (i = x; i > 0; i--)
        {
            if (number_1 % i == 0 && number_2 % i == 0)
            {
                return i;
            }
        }
    }
    else if (number_1 > number_2)
    {
        x = number_2;
        for (i = x; i > 0; i--)
        {
            if (number_1% i == 0 && number_2 % i == 0)
            {
                return i;
            }
        }
    }
    return 1;
}
int main()
{
    int a1, b1, a2, b2;
    scanf("%d/%d %d/%d", &a1, &b1, &a2, &b2);
    int number_1 = a1 * b2 + a2 * b1;
    int number_2 = b1 * b2;
    int k = function(number_1, number_2);
    number_1 = number_1 / k;
    number_2 = number_2 / k;
    if (number_1 % number_2 == 0)
    {
        printf("%d", number_1 / number_2);
    }
    else
    {
        printf("%d/%d", number_1, number_2);
    }
    return 0;
}
#include <stdio.h>
double function1(int i)//递归计算阶乘
{
	if (i == 0 || i == 1)
	{
		return 1;
	}
	return function1(i - 1) * i;
}
double function2(int i)//求奇数列乘
{
	i++;
	int add = 1;
	for(int j = 1; j <= i; j++)
	{
		add *= (2 * j - 1);
	}
	return add;
}
double fun(double number)
{
	double add = 0;
	int k = 0;
	while (1)
	{
		double a = function1(k) / function2(k);
		add += a;
		if (a < number)
		{
			break;
		}
		k++;
	}
	return add;
}
int main()
{
	double number = 0;
	scanf("%lf", &number);
	printf("%lf", fun(number) * 2);
	return 0;
}
#include <stdio.h>
int main()
{
	int number1 = 0, number2 = 0;
	int add = 0;
	int k = 1;
	scanf("%d %d", &number1, &number2);
	for (int i = number1; i <= number2; i++, k++)
	{
		printf("%5d", i);
		if (k % 5 == 0 || i == number2)
		{
			printf("\n");
		}
		add += i;
	}
	printf("Sum = %d", add);
	return 0;
}