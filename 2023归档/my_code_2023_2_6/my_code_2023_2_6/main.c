#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
//1��ѡ�������ʹ��
#define NUM 1001
int main()
{
    char Value[NUM] = { 0 };//�ַ�����洢�ַ�
    scanf("%s", Value);//��������

    int SIZE = strlen(Value);//���������С
    int i = 0, j = 0;//ѭ����
    int number = 0;//�м�ֵ

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

    printf("%s\n", Value);
    return 0;
}
//2��Ѱ������������±�
int pivotIndex(int* nums, int numsSize)
{
    int number = 0;
    int zadd = 0, yadd = 0;
    int i = 0;

    for (number = 0; number < numsSize; number++)
    {
        zadd = 0;
        yadd = 0;
        for (i = 0; i < number; i++)
        {
            zadd += nums[i];
        }
        for (i = i + 1; i < numsSize; i++)
        {
            yadd += nums[i];
        }
        if (zadd == yadd)
        {
            return number;
        }
    }
    return -1;
}
int main()
{
    int arr[6] = {1, 7, 3, 6, 5, 6};
    printf("%d\n", pivotIndex(arr, 6));
    return 0;
}
//3��������ҵ����
int func(int x)
{
	int count = 0;
	while (x)
	{
		count++;
		x = x & (x - 1);//������
	} 
	return count;
}
int main()
{
	int a = func(-1);
	printf("%d", a);
	return 0;
}
//4��������ҵ
int main()
{
	int count = 0;
	int x = -1;
	while (x)
	{
		count++;
		x = x >> 1;
	}
	printf("%d", count);
	return 0;
}
//5����ҵ����
int main()
{
	int a = 1, b = 2, m = 0, n = 0, k;
	k = (n = b < a) && (m = a);
	printf("%d,%d\n", k, m);
	return 0;
}