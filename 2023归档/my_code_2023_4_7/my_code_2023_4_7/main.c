#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
char* arr1[10] = {
    "ling",
    "yi",
    "er",
    "san",
    "si",
    "wu",
    "liu",
    "qi",
    "ba",
    "jiu"
};
int main()
{
    int number = 0;
    char* arr2[100] = { 0 };
    scanf("%d", &number);
    int i = 99;

    int flag = 1;
    if (number < 0)
    {
        flag = -1;
    }

    number = abs(number);
    if (number == 0)
    {
        printf("ling");
        return 0;
    }
    while (number)
    {
        arr2[i] = arr1[number % 10];
            number /= 10;
        i--;
    }
    if (flag == -1)
    {
        printf("fu ");
    }
    for (i = 0; i < 100; i++)
    {
        if (arr2[i] != 0)
        {
            printf("%s", arr2[i]);
            if (i != 99)
            {
                printf(" ");
            }
        }
    }
    return 0;
}
#include <stdio.h>
int function(int number_1, int number_2)
{
    int i = number_1 > number_2 ? number_2 : number_1;
    while (i)
    {
        if (number_1 % i == 0 && number_2 % i == 0)
        {
            return i;
        }
        i--;
    }
    return 1;
}
int main()
{
    int number_1 = 0, number_2 = 0;
    scanf("%d/%d", &number_1, &number_2);
    int i = function(number_1, number_2);
    if (number_1 % number_2 != 0 || number_1 == number_2)
        printf("%d/%d", number_1 / i, number_2 / i);
    else
        printf("%d", number_1 / number_2);
}