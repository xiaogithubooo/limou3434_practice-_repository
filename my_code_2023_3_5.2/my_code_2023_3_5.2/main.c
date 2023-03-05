#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
//日志
//1、实验变参宏
//2、int和double的注意选项

#define PR(X, ...) printf("Message " #X ":"__VA_ARGS__)
//1、实验变参宏
int main()
{
	double x = 48;
	double y;

	y = sqrt(x);
	PR(1, "x = %g\n", x);
	PR(2, "x = %.2f, y = %.4f\n", x, y);
	return 0;

}
//2、int和double的注意选项
int main()
{
	double a = 10.0;
	printf("%d\n", a);
	int b = (int)a;
	printf("%d\n", b);
}