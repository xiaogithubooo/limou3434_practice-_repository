#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
#include <float.h>
long double function(double x, double a3, double a2, double a1, double a0)
{
    return a3 * (x * x * x) + a2 * (x * x) + a1 * (x)+a0;
}
int main()
{
    double a3 = 0, a2 = 0, a1 = 0, a0 = 0;
    double a = 0, b = 0;
    scanf("%lf %lf %lf %lf", &a3, &a2, &a1, &a0);
    scanf("%lf %lf", &a, &b);
    double mid = (a + b) / 2;
    while (fabs(a - b) < DBL_EPSILON)
    {
        if (fabs(function(mid, a3, a2, a1, a0) - 0) > DBL_EPSILON)
        {
            b = mid;
            mid = (a + b) / 2;
        }
        else if (fabs(function(mid, a3, a2, a1, a0) - 0) < DBL_EPSILON)
        {
            a = mid;
            mid = (a + b) / 2;
        }
        else
        {
            printf("%lf", mid);
        }
    }
    printf("%lf", mid);
    return 0;
}