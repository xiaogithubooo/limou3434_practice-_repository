#define _CRT_SECURE_NO_WARNINGS 1
#define NUM 10
#include<stdio.h>
//1��ѡ������ϰ
int main()
{
    int Value[NUM] = { 0 };
    int x = 0;
    int SIZE = sizeof(Value) / sizeof(Value[0]);//���������С
    int i = 0, j = 0;// ѭ����
    int number = 0;//�м�ֵ

    for (x = 0; x < NUM; x++)
    {
        scanf("%d", &Value[x]);//��������
    }

    for (i = 0; i < SIZE - 1; i++)
    {
        for (j = i + 1; j < SIZE; j++)
        {
            if (Value[i] > Value[j])
            {
                number = Value[i];
                Value[i] = Value[j];
                Value[j] = number;
            }
        }
    }
    for (x = 0; x < NUM; x++)
    {
        printf("%d ", Value[x]);
    }
    return 0;
}
//2��һ����ѧ������Ŀ
int main()
{
	int i = 0;
	double sum = 0.0;
	int flag = 1;
	for (i = 1; i <= 100; i++)
	{
		sum += (flag * (1.0 / i));//ע���������ֱ��д1.0����Ϊ��double����
		flag = -flag;
	}
	printf("%lf\n", sum);
	return 0;
}
//3��9�ĸ���
int main()
{
	int i = 0;
	int count = 0;
	for (i = 1; i <= 100; i++)
	{
		if (i % 10 == 9)
		{
			count++;
		}
		if (i % 100 == 9)
		{
			count++;
		}
	}
	printf("%d\n", count);
	return 0;
}
//4���������кϲ���ϰ
#include<stdio.h>
void bubble_qort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int flag = 1;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
                flag = 0;
            }
        }
        if (flag == 1)
            break;
    }
}
int main()
{
    int n, m;
    int arr1[2000] = { 0 };
    int arr2[2000] = { 0 };
    int arr[10000] = { 0 };
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr1[i]);
        arr[i] = arr1[i];

    }
    for (int j = 0; j < m; j++)
    {
        scanf("%d", &arr2[j]);
        arr[n + j] = arr2[j];
    }
    bubble_qort(arr, n + m);
    for (int k = 0; k < n + m; k++)
    {
        printf("%d ", arr[k]);
    }
    printf("\n");
    return 0;
}
//5����̨�׺ͽ׳˸�ϰ
#include <stdio.h>
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
//6������ˮ�ɻ�����ϰ
#include <stdio.h>
int f(int);
int main()
{
    int i = 0;
    int j = 0;
    for (i = 10000; i < 100000; i++)
    {
        j = f(i);
        if (j != 0)
        {
            printf("%d ", j);
        }
    }
    return 0;
}
int f(int x)
{
    int a = (x / 10) * (x % 10);//ǰ4λ
    int b = (x / 100) * (x % 100);
    int c = (x / 1000) * (x % 1000);
    int d = (x / 10000) * (x % 10000);
    if (a + b + c + d == x)
    {
        return x;
    }
    else
    {
        return 0;
    }
}
//7���������жϸ�ϰ
#include <stdio.h>

int main()
{
    int arr[3] = { 0 };
    while (scanf("%d %d %d", arr, arr + 1, arr + 2) == 3)
    {
        getchar();
        if ((arr[0] + arr[1] > arr[2]) && (arr[1] + arr[2] > arr[0]) && (arr[2] + arr[0] > arr[1]))
        {
            if ((arr[0] == arr[1]) && (arr[1] == arr[2]))
            {
                printf("Equilateral triangle!\n");
            }
            else if (((arr[0] == arr[1]) && (arr[0] != arr[2])) || ((arr[1] == arr[2]) && (arr[1] != arr[0])) || ((arr[2] == arr[0]) && (arr[0] != arr[1])))
            {
                printf("Isosceles triangle!\n");
            }
            else
            {
                printf("Ordinary triangle!\n");
            }
        }
        else
        {
            printf("Not a triangle!");
        }
    }
    return 0;
}
