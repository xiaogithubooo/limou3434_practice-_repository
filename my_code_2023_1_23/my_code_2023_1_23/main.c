#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//1�����ϸ�����
int main()
{
    int i = 0;
    int a, b, c;
    int number = 0;
    int Add = 0;
    scanf("%d", &number);
    for (i = 0; i < number; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        if (((float)(a + b + c) / (float)3) < 60)
        {
            Add++;
        }
    }
    printf("%d", Add);
    return 0;
}
//2��ȥ��������ĺ÷���
int main() 
{
    int n, i, input, max = 0;
    int a[100001] = { 0 };
    scanf("%d", &n);

    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &input);
        a[input] = input;// ����ͬ���������ͬ������Ԫ����
        if (input >= max) 
        {            // ����������Ԫ��ֻ�ᱣ��һ����ͬ����
            max = input;
        }
    }

    for (i = 1; i <= max; i++) 
    {
        if (a[i]) 
        {             //�����������Ԫ��
            printf("%d ", a[i]);
        }
    }
    return 0;
}
//3����̨�׷���
int f(int x)
{
    if (x == 1)
    {
        return 1;
    }
    else if (x == 2)
    {
        return 2;
    }
    else if (x == 0)
    {
        return 0;
    }
    return f(x - 1) + f(x - 2);
}
int main()
{
    int number = 0;
    scanf("%d", &number);
    printf("%d", f(number));
    return 0;
}
//4���������ת��
int main()
{
    int number = 0;
    scanf("%d", &number);
    int arr[100] = { 0 };
    int i = 0;

    while (number / 6 != 0)
    {
        arr[i] = number % 6;//�õ�ĩβ����˳����
        number /= 6;
        i++;
    }
    arr[i] = number;
    for (int j = i; j >= 0; j--)
    {
        printf("%d", arr[j]);//�������
    }
    return 0;
}