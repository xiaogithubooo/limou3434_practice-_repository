#define _CRT_SECURE_NO_WARNINGS 1
//��־
//1��PTA��Ŀ��������ڵ�Ľ׳˺ͣ�https://pintia.cn/problem-sets/14/exam/problems/738
//2��PTA��������׳ˣ�û�������https://pintia.cn/problem-sets/14/exam/problems/742
//3��PTA��Ŀ�����㹤�ʣ�https://pintia.cn/problem-sets/14/exam/problems/790
// 
//1��PTA��Ŀ��������ڵ�Ľ׳˺ͣ�https://pintia.cn/problem-sets/14/exam/problems/738
typedef struct Node* PtrToNode;
struct Node {
    int Data; /* �洢������� */
    PtrToNode Next; /* ָ����һ������ָ�� */
};
typedef PtrToNode List; /* ���嵥�������� */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node* PtrToNode;
struct Node {
    int Data; /* �洢������� */
    PtrToNode Next; /* ָ����һ������ָ�� */
};
typedef PtrToNode List; /* ���嵥�������� */

int FactorialSum(List L);

int main()
{
    int N, i;
    List L, p;

    scanf("%d", &N);
    L = NULL;
    for (i = 0; i < N; i++) {
        p = (List)malloc(sizeof(struct Node));
        scanf("%d", &p->Data);
        p->Next = L;  L = p;
    }
    printf("%d\n", FactorialSum(L));

    return 0;
}

/* ��Ĵ��뽫��Ƕ������ */
long function(int a)
{
    if (a == 1 || a == 0)
    {
        return 1;
    }
    else
    {
        return a * function(a - 1);
    }
}

int FactorialSum(List L)
{
    List pL = L;
    int add = 0;
    while (pL)
    {
        add += function(pL->Data);
        pL = pL->Next;
    }
    return add;
}

//2��PTA��������׳ˣ�û�������https://pintia.cn/problem-sets/14/exam/problems/742
#include <stdio.h>
void Print_Factorial(const int N);
int main()
{
    int N;

    scanf("%d", &N);
    Print_Factorial(N);
    return 0;
}
/* ��Ĵ��뽫��Ƕ������ */
void multiplication(int number1, int number2)
{
    int i = 0;
    int z = 0;
    int x = 0;
    int temp = 0;
    int arr[100] = { 0 };
    while (number1)
    {
        arr[i] = number1 % 10;
        number1 /= 10;
        i++;
    }
    for (int z = 0; z <= i; z++)
    {
        x = arr[z] * number2;
        arr[z] = (x + temp) % 10;
        temp = (x + temp) / 10;
    }
    
    for (int k = i ; k >= 0 ; k--)
    {
        printf("%d", arr[k]);
    }
}
void Print_Factorial(const int N)
{
    //?
}

//3��PTA��Ŀ�����㹤�ʣ�https://pintia.cn/problem-sets/14/exam/problems/790
#include <stdio.h>
float function(float number2)
{

}
int main()
{
    float number1 = 0, number2 = 0;
    scanf("%f %f", &number1, &number2);
    if (number1 < 5)
    {
        if (number2 <= 40)
        {
            printf("%.2f", number2 * 30);
        }
        else
        {
            printf("%.2f", ((number2 - 40) * (30 * 1.5)) + (40 * 30));
        }
    }
    else
    {
        if (number2 <= 40)
        {
            printf("%.2f", number2 * 50);
        }
        else
        {
            printf("%.2f", ((number2 - 40) * (50 * 1.5)) + (40 * 50));
        }
    }
    return 0;
}