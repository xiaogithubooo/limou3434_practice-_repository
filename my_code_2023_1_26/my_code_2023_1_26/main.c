#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#define MAXN 10

double f(int n, double a[], double x);

int main()
{
    int n, i;
    double a[MAXN], x;

    scanf("%d %lf", &n, &x);
    for (i = 0; i <= n; i++)
        scanf("%lf", &a[i]);
    printf("%.1f\n", f(n, a, x));
    return 0;
}

/* ��Ĵ��뽫��Ƕ������ */
double f(int n, double a[], double x)//������ϵ����δ֪��
{
    double add = 0;//����ʽ�������

    double A = 1;

    int I = 0;

    for (int i = 0; i <= n; i++)
    {
        I = i;
        A = 1;
        while (I)
        {
            A *= x;
            I--;
        }
        add += (a[i] * A);
    }
    return add;
}
