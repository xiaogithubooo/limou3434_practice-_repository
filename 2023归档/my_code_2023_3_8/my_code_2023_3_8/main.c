#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//��־
//1������һ��ָ���������Ŀ
//2������һ��ָ���������Ŀ
//3��������ȫƽ���������Ҵ����ظ�Ԫ�أ�����û�ԡ���

//1������һ��ָ���������Ŀ
int main()
{
    int a[4] = { 1, 2, 3, 4 };//������һ����������
    int* ptr1 = (int*)(&a + 1);//&a����������ĵ�ַ��+1��͵õ�һ������һ��������ĵ�ַ��Ȼ��ǿ��ת��Ϊ(int*)����
    int* ptr2 = (int*)((int)a + 1);//aԭ������Ԫ�ص�ַ����ǿ������ת��Ϊint���ͣ����е������ϵ�+1���ֱ�ǿ��ת��Ϊint*���ͣ����һ����ַ����ֵַ����1����Ϊ�ŵ�ַָ������һ���ֽڣ�
    printf("%x,%x", ptr1[-1], *ptr2);//ptr1[-1]��*(ptr1-1)�ȼۣ�ptr1[-1]����ǰ�����ˣ����õõ��������һ��Ԫ�ء���*ptr2������int*��ָ�����ͣ�������4���ֽڵ����ݣ��õ�����(00 00 01 00)2=(4)10
    return 0;
}
//2������һ��ָ���������Ŀ
int main()
{
    int a[3][2] = { (0, 1), (2, 3), (4, 5) };//���ű��ʽ��ʵ�ʴ���1��3��5��Ȼ��ʣ�µ�Ԫ��Ĭ��Ϊ0
    int* p;
    p = a[0];//a[0]��һ���������֣�������Ԫ�ص�ַ����a[0][0]�ĵ�ַ��������int*�����ô���p��
    printf("%d", p[0]);//p[0]�ȼ���*(p+0)���ȼ���*p����Ϊ1
    return 0;
}
//3��������ȫƽ���������Ҵ����ظ�Ԫ�أ�����û�ԡ���
#include <math.h>
int function(int N)
{
    int n = N;
    int num = N % 10;//ȡ�����һλ
    N /= 10;
    while (N)
    {
        while (N)
        {
            if (N % 10 == num)
            {
                return 1;
            }
            else
            {
                N /= 10;
            }
        }
        N = n;
    }
    return 0;
}
int IsTheNumber(const int N)
{
    int number = (int)sqrt(N);
    if (number * number == N)//�ж��Ƿ�Ϊ��ȫƽ����
    {
        if (function(N))//function����1,�ͷ���1
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    int n1, n2, i, cnt;

    scanf("%d %d", &n1, &n2);
    cnt = 0;
    for (i = n1; i <= n2; i++) 
    {
        if (IsTheNumber(i))
        {
            cnt++;
            if (cnt == 1||cnt == 2||cnt == 3||cnt == 4||cnt == 5||cnt == 6||cnt == 7||cnt == 8)
            {
                printf("%d ", i);
            }
        }
    }
    printf("\ncnt = %d\n", cnt);

    return 0;
}
