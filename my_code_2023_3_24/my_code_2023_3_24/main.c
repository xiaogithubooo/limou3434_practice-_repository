#define _CRT_SECURE_NO_WARNINGS 1
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

#define MAXLEN 10000
void Print_Factorial(const int N)
{
    int n = N;
    if (n < 0)//�����������
    {
        printf("Invalid input\n");
        return;
    }
    //��N>=0��ʱ�򣬿�ʼ��������׳�
    //1.�ȴ���һ���ַ�����
    char arr[MAXLEN] = { 1 };//�����ֵ1��Ϊ�׳˵Ļ���

    //2.��������׳�
    int i = 0;//ѭ����
    int k = 2;//����
    int tmp = 0;//��λ��
    for (k = 2; k <= N; k++)//����
    {
        /*���ﻹ�����Ż�������*/
        for (i = 0, tmp = 0; i < MAXLEN; i++)
        {
            int a = (arr[i] * k) + tmp;
            arr[i] = a % 10;
            tmp = a / 10;
            //if (arr[i] == 0)
            //{
            //    break;
            //}
        }
    }
    //3.�����ӡ���
    int j = 0;
    for (j = MAXLEN - 1; j >= 0; j--)
    {
        if (arr[j] != 0)
        {
            for (j; j >= 0; j--)
            {
                printf("%d", arr[j]);
            }
        }
    }
}
//
//#define MAXLEN 1000
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//    char buffer[MAXLEN + 1] = { 0 };
//    char a[MAXLEN + 1] = { 0 };
//    char b[MAXLEN + 1] = { 0 };
//    //1.�洢
//    int tmp = 0;//a��b����ѭ����
//    int i = 0;//buffer����ѭ����
//    scanf("%s", buffer);//�ȴ���һ����
//    for (tmp = 0, i = strlen(buffer) - 1; i >= 0; i--)
//    {
//        a[tmp++] = buffer[i] - '0';
//    }
//    scanf("%s", buffer);//�ȴ���һ����
//    for (tmp = 0, i = strlen(buffer) - 1; i >= 0; i--)
//    {
//        b[tmp++] = buffer[i] - '0';
//    }
//    //2.����
//    int up = 0;//��λ��
//    for (up = 0, i = 0; i < MAXLEN; i++)
//    {
//        tmp = a[i] + b[i] + up;
//        a[i] = tmp % 10;
//        up = tmp / 10;
//    }
//    //3.�ó����
//    for (i = MAXLEN; i >= 0; i--)
//    {
//        if (a[i] != 0)
//        {
//            for (i; i >= 0; i--)
//            {
//                printf("%d", a[i]);
//            }
//        }
//    }
//    return 0;
//}

