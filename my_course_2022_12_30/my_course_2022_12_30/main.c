#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
    double a = 0, b = 0;//������������
    char x;//���������������
    double c = 0;//�洢���

    scanf("%lf%c%lf", &a, &x, &b);
    switch (x)
    {
    case '+':
        printf("%.4lf%c%.4lf=%.4lf\n", a, x, b, a + b);
        break;

    case '-':
        printf("%.4lf%c%.4lf=%.4lf\n", a, x, b, a - b);
        break;

    case '*':
        printf("%.4lf%c%.4lf=%.4lf\n", a, x, b, a * b);
        break;

    case '/':
        if (b == 0.0)
        {
            printf("Wrong!Division by zero!\n");
        }
        else
        {
            printf("%.4lf%c%.4lf=%.4lf\n", a, x, b, a / b);
        }
        break;

    default:
        printf("Invalid operation!\n");
    }
    return 0;
}