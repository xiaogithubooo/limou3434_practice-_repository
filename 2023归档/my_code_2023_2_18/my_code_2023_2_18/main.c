////1、动态顺序表的创建
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int SQDateType;//切换不同的数据类型

typedef struct SeqList
{
    SQDateType* a;
    int size;        //当前实际存储了多少个数据的个数
    int capacity;    //当前顺序表的容量
}SeqList;
//初始化接口函数
void SeqListInit(SeqList* psl)
{
    psl->a = NULL;//可以先不给空间，也可以对psl->a给与malloc
    psl->size = 0;
    psl->capacity = 0;
}
//检查容量函数
void SeqListCheckCapacity(SeqList* psl)
{
    if (psl->size == psl->capacity)//满了就扩容，每次拓展一倍（不要直接拓展，要不然加一次就扩容一次）
    {
        int newcapacity = (psl->capacity == 0 ? 4 : psl->capacity * 2);//避免0翻倍的问题
        SQDateType* tmp = (SQDateType*)realloc(psl->a, newcapacity * sizeof(SQDateType));//扩容函数，但是在第一次的时候不是扩容（接受了NULL），一开始效果等同malloc
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
//尾插入接口函数
void SeqListPushBack(SeqList* psl, SQDateType x)
{
    SeqListCheckCapacity(psl);
    psl->a[psl->size] = x;
    psl->size++;
}
//头插入接口函数
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
//尾删接口函数
void SeqListPopBack(SeqList* psl)
{
    assert(psl->size > 0);//避免无数可尾删
    //psl->a[psl->size - 1] = 0;//没必要写，这个size--后，无论是什么都不会被后面的打印接口函数打印出来
    psl->size--;
}
//头删除接口函数
void SeqListPopFront(SeqList* psl)//注意
{
    assert(psl->size > 0);//避免无数可尾删
    int start = 1;
    while (start < psl->size)
    {
        psl->a[start - 1] = psl->a[start];
        start++;
    }
    psl->size--;
}
//打印接口函数
void SeqListPrint(SeqList* psl)
{
    for (int i = 0; i < psl->size; i++)
    {
        printf("%d ", psl->a[i]);
    }
    printf("\n");
} 
//随机插入接口函数
void SeqListInsert(SeqList* psl, int pos, SQDateType x)
{
    assert(pos < psl->size);//不允许超出容量的范围
    SeqListCheckCapacity(&psl);//避免现有容量==现有数据量时，没有办法放入
    int end = psl->size - 1;
    while (end >= pos)
    {
        psl->a[end + 1] = psl->a[end];
        end--;
    }
    psl->a[pos] = x;
    psl->size++;
}
//随机删除接口函数
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
//销毁动态内存接口函数
void SeqListDestory(SeqList* psl)
{
    free(psl->a);
    psl->a = NULL;
    psl->capacity = psl->size = 0;
}
//查找接口函数
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
//修改接口函数
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

    SeqListInsert(&a, 1, -10);//下标为1的地方插入一个数20
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
////2、静态顺序表的创建（试验）
//创建了一个顺序表结构体，类型是SeqList
//typedef int SQDateType;//切换不同的数据类型
//
//typedef struct SeqList
//{
//    SQDateType arr[ARR_MAX];   //定长数组
//    int size;           //实际存储的数据大小
//}SeqList;
// 
////初始化接口函数
//void SeqListInit(SeqList* psl)
//{
//    memset(psl->arr, 0, sizeof(SQDateType) * ARR_MAX);
//    psl->size = 0;
//}
////尾插入接口函数
//void SeqListPushBack(SeqList* psl, SQDateType x)
//{
//    if (psl->size >= ARR_MAX)    //有可能出现顺序表满的情况 
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
//3、力扣：移除数组
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
//4、力扣：合并两个有序数组
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
    while (end2 >= 0)//避免第二个数组还没比完
    {
        nums1[end] = nums2[end2];
        end--;
        end2--;
    }
}