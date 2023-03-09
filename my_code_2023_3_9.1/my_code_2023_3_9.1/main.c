#define _CRT_SECURE_NO_WARNINGS 1
//��־
//1��PTA��ͳ��ĳ����ȫƽ������https://pintia.cn/problem-sets/14/exam/problems/739
//2��PTA������ʽ��ֵ��https://pintia.cn/problem-sets/14/exam/problems/734

//1��PTA��ͳ��ĳ����ȫƽ������https://pintia.cn/problem-sets/14/exam/problems/739
#include <math.h>
#include <stdio.h>
int function(int i)//�ж��Ƿ�������ظ���λ��
{
    int arr[10] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
    int number = i;
    while (number)
    {
        if (arr[number % 10] == -1)
        {
            arr[number % 10] = number % 10;
        }
        else
        {
            arr[number % 10] = -2;
        }
        number /= 10;
    }
    for (int j = 0; j < 10; j++)
    {
        if (arr[j] == -2)
        {
            return 1;
        }
    }
    return 0;
}
int IsTheNumber(const int i)//�ж��Ƿ������ȫƽ�����ĺ���
{
    int number = (int)sqrt(i);
    if (number * number == i)//�ж��Ƿ�Ϊ��ȫƽ����
    {
        if (function(i))//function����1,�ͷ���1
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    int n1, n2, i, cnt;//�洢��С�����������һ��ѭ������ͳ�Ʒ�����������ȫƽ��������
    scanf("%d %d", &n1, &n2);//������Сֵ�����ֵ
    cnt = 0;
    for (i = n1; i <= n2; i++)
    {
        if (IsTheNumber(i))//�ж��Ƿ��������
        {
            cnt++;//����������++
            printf("%d ", i);//��ӡ��ʱ����������i
        }
    }
    printf("\ncnt = %d\n", cnt);
    return 0;
}
//2��PTA������ʽ��ֵ��https://pintia.cn/problem-sets/14/exam/problems/734
#include <math.h>
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
double f(int n, double a[], double x)
{
    double add = 0;
    for (int i = 0; i <= n; i++)
    {
        add += a[i] * pow(x, i);
    }
    return add;
}

