#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int int_cmp(void* p1, void* p2)
{
	return (*((int*)p1) - *((int*)p2));
}
void _swap(void* p1, void* p2)
{
	int i = 0;
	i = *(int*)p2;
	*(int*)p2 = *(int*)p1;
	*(int*)p1 = i;
}

void bubble(void* base, int count, int size, int(*cmp)(void*, void*))
{
	int i = 0, j = 0;
	for (i = 0; i < count - 1; i++)
	{
		for (j = 0; j < count - 1 - i; j++)
		{
			if (cmp((char*)base + j * size, (char*)base + (j + 1) * size ) > 0)//�����������Ƚϴ�С����----С
			{
				_swap((char*)base + j * size, (char*)base + ((j + 1) * size));//������������ĳ�(char*)�Ϳ�������size��Ӧ��ͬ���ֽ�
			}
		}
	}
}

int main()
{
	int arr[] = { 1, 12, 23, 0, -1, 100, -23 };

	bubble(arr, sizeof(arr) / sizeof(arr[0]), sizeof(int), int_cmp);//��������<����ָ�롢�����С������Ԫ�ش�С������ʽ>

	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}
#include <stdio.h>
//1��ͨ��ð������
int int_cmp(const void* p1, const void* p2)//����һ���ȽϺ�������������ͱȽϣ����û������������Ӧ����α�д
{
    return (*(int*)p1 - *(int*)p2);
    //����ע��void����ֱ�ӽ����ã�����
}

void _swap(void* p1, void* p2, int size)//����һ�����򷽷��������������ð�����򣬿����ɿ����߾����ײ�����ķ�������qsort��ʹ�õĵײ㺯���ǿ���
{
    int i = 0;
    for (i = 0; i < size; i++)
    {
        char tmp = *((char*)p1 + i);
        *((char*)p1 + i) = *((char*)p2 + i);
        *((char*)p2 + i) = tmp;
    }
}

void bubble(void* base, int count, int size, int(*cmp)(void*, void*))//�൱��qsort������ʵ���߼��������ǿ��������ڲ���_swap����Ҳ�����������������㷨��cmp�������ܱȽϲ�ͬ���͵�����
{
    int i = 0;
    int j = 0;
    for (i = 0; i < count - 1; i++)
    {
        for (j = 0; j < count - i - 1; j++)
        {
            if (cmp((char*)base + j * size, (char*)base + (j + 1) * size) > 0)//�ȽϺ���������ĳ�(char*)�Ϳ�������size��Ӧ��ͬ���ֽ�
            {
                _swap((char*)base + j * size, (char*)base + (j + 1) * size, size);//������������ĳ�(char*)�Ϳ�������size��Ӧ��ͬ���ֽ�
            }
        }
    }
}

int main()
{
    int arr[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
    char *arr[] = {"aaaa","dddd","cccc","bbbb"};
    int i = 0;
    bubble(arr, sizeof(arr) / sizeof(arr[0]), sizeof(int), int_cmp);
    for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

//2�����Գ���
int main()
{
	int aa[2][5] = { 10,9,8,7,6,5,4,3,2,1 };
	int* ptr1 = (int*)(&aa + 1);
	int* ptr2 = (int*)(*(aa + 1));
	printf("%d,%d", *(ptr1 - 1), *(ptr2 - 1));
	return 0;
}
//3��ʹ��qsort
#include <stdio.h>
#include <stdlib.h>
//qosrt������ʹ���ߵ�ʵ��һ���ȽϺ���
int int_cmp(const void* p1, const void* p2)
{
    return (*(int*)p1 - *(int*)p2);//ע�ⲻ��ֱ�ӽ�����voidָ�룬��������������������������
}
int main()
{
    int arr[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
    int i = 0;

    qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(int), int_cmp);

    for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}