#include <stdio.h>
int add(int num1, int num2)
{
    int sum = num1 + num2;
    return sum;
}
int main() 
{
    int num1 = 10;
    int num2 = 5;
    int sum = add(num1, num2);

    printf("num1: %d\n", num1);
    printf("num2: %d\n", num2);
    printf("sum: %d\n", sum);

    return 0;
}

