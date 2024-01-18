////1����̬˳���Ĵ���
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int SQDateType;//�л���ͬ����������

typedef struct SeqList
{
    SQDateType* a;
    int size;        //��ǰʵ�ʴ洢�˶��ٸ����ݵĸ���
    int capacity;    //��ǰ˳��������
}SeqList;
//��ʼ���ӿں���
void SeqListInit(SeqList* psl)
{
    psl->a = NULL;//�����Ȳ����ռ䣬Ҳ���Զ�psl->a����malloc
    psl->size = 0;
    psl->capacity = 0;
}
//�����������
void SeqListCheckCapacity(SeqList* psl)
{
    if (psl->size == psl->capacity)//���˾����ݣ�ÿ����չһ������Ҫֱ����չ��Ҫ��Ȼ��һ�ξ�����һ�Σ�
    {
        int newcapacity = (psl->capacity == 0 ? 4 : psl->capacity * 2);//����0����������
        SQDateType* tmp = (SQDateType*)realloc(psl->a, newcapacity * sizeof(SQDateType));//���ݺ����������ڵ�һ�ε�ʱ�������ݣ�������NULL����һ��ʼЧ����ͬmalloc
        if (tmp == NULL)
        {
            printf("realloc fail\n");
            exit(-1);
        }
        else
        {
            psl->a = tmp;
            psl->capacity = newcapacity;
        }
    }
}
//β����ӿں���
void SeqListPushBack(SeqList* psl, SQDateType x)
{
    SeqListCheckCapacity(psl);
    psl->a[psl->size] = x;
    psl->size++;
}
//ͷ����ӿں���
SeqListPushFront(SeqList* psl, SQDateType x)
{
    SeqListCheckCapacity(psl);
    int end = psl->size - 1;
    while (end >= 0)
    {
        psl->a[end + 1] = psl->a[end];
        end--;
    }
    psl->a[0] = x;
    psl->size++;
}
//βɾ�ӿں���
void SeqListPopBack(SeqList* psl)
{
    assert(psl->size > 0);//����������βɾ
    //psl->a[psl->size - 1] = 0;//û��Ҫд�����size--��������ʲô�����ᱻ����Ĵ�ӡ�ӿں�����ӡ����
    psl->size--;
}
//ͷɾ���ӿں���
void SeqListPopFront(SeqList* psl)//ע��
{
    assert(psl->size > 0);//����������βɾ
    int start = 1;
    while (start < psl->size)
    {
        psl->a[start - 1] = psl->a[start];
        start++;
    }
    psl->size--;
}
//��ӡ�ӿں���
void SeqListPrint(SeqList* psl)
{
    for (int i = 0; i < psl->size; i++)
    {
        printf("%d ", psl->a[i]);
    }
    printf("\n");
} 
//�������ӿں���
void SeqListInsert(SeqList* psl, int pos, SQDateType x)
{
    assert(pos < psl->size);//�������������ķ�Χ
    SeqListCheckCapacity(&psl);//������������==����������ʱ��û�а취����
    int end = psl->size - 1;
    while (end >= pos)
    {
        psl->a[end + 1] = psl->a[end];
        end--;
    }
    psl->a[pos] = x;
    psl->size++;
}
//���ɾ���ӿں���
void SeqListErase(SeqList* psl, int pos)
{
    assert(pos < psl->size);
    int start = pos + 1;
    while (start < psl->size)
    {
        psl->a[start - 1] = psl->a[start];
        start++;
    }
    psl->size--;
}
//���ٶ�̬�ڴ�ӿں���
void SeqListDestory(SeqList* psl)
{
    free(psl->a);
    psl->a = NULL;
    psl->capacity = psl->size = 0;
}
//���ҽӿں���
int SeqListFind(SeqList* psl, SQDateType x)
{
    for (int i = 0; i < psl->size; i++)
    {
        if (psl->a[i] == x)
        {
            return i;
        }
    }
    return -1;
}
//�޸Ľӿں���
void SeqListModity(SeqList* psl, int pos, SQDateType x)
{
    assert(pos < psl->size);
    psl->a[pos] = x;
}
int main()
{
    SeqList a;

    SeqListInit(&a); 

    SeqListPushBack(&a, 1);
    SeqListPushBack(&a, 2);
    SeqListPushBack(&a, 3);
    SeqListPushBack(&a, 4);
    SeqListPushBack(&a, 5);
    SeqListPushBack(&a, 6);
    SeqListPushBack(&a, 7);
    SeqListPushBack(&a, 8);
    SeqListPushBack(&a, 9);
    SeqListPushBack(&a, 10);

    SeqListPrint(&a);

    SeqListPushFront(&a, 100);
    SeqListPushFront(&a, 200);
    SeqListPushFront(&a, 300);
    SeqListPushFront(&a, 400);
    SeqListPushFront(&a, 500);
    SeqListPushFront(&a, 600);
    SeqListPushFront(&a, 700);
    SeqListPushFront(&a, 800);
    SeqListPushFront(&a, 900);
    SeqListPushFront(&a, 1000);

    SeqListPrint(&a);

    SeqListPopBack(&a);
    SeqListPopFront(&a);

    SeqListPrint(&a);

    SeqListInsert(&a, 1, -10);//�±�Ϊ1�ĵط�����һ����20
    SeqListInsert(&a, 1, -20);
    SeqListInsert(&a, 1, -30);

    SeqListPrint(&a);

    SeqListErase(&a, 5);
    SeqListErase(&a, 5);

    SeqListPrint(&a);

    printf("%d %d %d\n", SeqListFind(&a, 100), SeqListFind(&a, -30), SeqListFind(&a, -2));

    SeqListModity(&a, 3, 100000);
    SeqListPrint(&a);

    SeqListDestory(&a);
    return 0;
}
////2����̬˳���Ĵ��������飩
//������һ��˳���ṹ�壬������SeqList
//typedef int SQDateType;//�л���ͬ����������
//
//typedef struct SeqList
//{
//    SQDateType arr[ARR_MAX];   //��������
//    int size;           //ʵ�ʴ洢�����ݴ�С
//}SeqList;
// 
////��ʼ���ӿں���
//void SeqListInit(SeqList* psl)
//{
//    memset(psl->arr, 0, sizeof(SQDateType) * ARR_MAX);
//    psl->size = 0;
//}
////β����ӿں���
//void SeqListPushBack(SeqList* psl, SQDateType x)
//{
//    if (psl->size >= ARR_MAX)    //�п��ܳ���˳���������� 
//    {
//        printf("SeqList is Full\n");
//        return;
//    }
//    psl->arr[psl->size] = x;
//    (psl->size)++;
//}
//
//int main()
//{
//    SeqList a;
//    SeqListInit(&a); 
//    SeqListPushBack(&a, 1);
//    SeqListPushBack(&a, 2);
//    SeqListPushBack(&a, 3);
//    SeqListPushBack(&a, 4);
//    SeqListPushBack(&a, 5);
//    SeqListPushBack(&a, 6);
//    SeqListPushBack(&a, 7);
//    SeqListPushBack(&a, 8);
//    SeqListPushBack(&a, 9);
//    SeqListPushBack(&a, 10);
//    SeqListPushBack(&a, 11);
//    return 0;
//}
//3�����ۣ��Ƴ�����
int removeElement(int* nums, int numsSize, int val)
{
    int src = 0;
    int dst = 0;
    while (src < numsSize)
    {
        if (nums[src] != val)
        {
            nums[dst++] = nums[src++];
        }
        else
        {
            src++;
        }
    }
    return dst;
}
//4�����ۣ��ϲ�������������
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    int end1 = m - 1;
    int end2 = n - 1;
    int end = m + n - 1;
    while (end1 >= 0 && end2 >= 0)
    {
        if (nums1[end1] > nums2[end2])
        {
            nums1[end] = nums1[end1];
            end--;
            end1--;
        }
        else
        {
            nums1[end] = nums2[end2];
            end--;
            end2--;
        }
    }
    while (end2 >= 0)//����ڶ������黹û����
    {
        nums1[end] = nums2[end2];
        end--;
        end2--;
    }
}