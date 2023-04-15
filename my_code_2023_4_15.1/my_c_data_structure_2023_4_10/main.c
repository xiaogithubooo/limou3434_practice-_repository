#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define INITIAL_NUMBER 3
//# 0.目标：顺序表的练习
//>		 0.1.复习顺序表
//			0.1.1.重新看顺序表code
//			0.1.2.对顺序表code进行调试
//			0.1.3.while(!(成功写出顺序表)) {回去看代码;}
//>		 0.2.使用顺序表思想
//x			0.2.1.刷推荐和作业的题目
//x				0.2.1.1.移除元素：https://leetcode.cn/problems/remove-element/
//x				0.2.1.2.合并两个有序数组：https://leetcode.cn/problems/merge-sorted-array/
//			0.2.2.刷力扣的题目
//				0.2.2.1.删除有序数组中的重复项：https://leetcode.cn/problems/remove-duplicates-from-sorted-array/
//				0.2.2.2.基于排列构建数组：https://leetcode.cn/problems/build-array-from-permutation/
//				0.2.2.3.搜索插入位置（二分法复习）：https://leetcode.cn/problems/search-insert-position/description/
//				0.2.2.4.存在重复元素：https://leetcode.cn/problems/contains-duplicate/description/?envType=study-plan&id=shu-ju-jie-gou-ru-men&plan=data-structures&plan_progress=x5znyghm
//				0.2.2.5.最大子数组和：https://leetcode.cn/problems/maximum-subarray/?envType=study-plan&id=shu-ju-jie-gou-ru-men&plan=data-structures&plan_progress=x5znyghm
//>		 0.3.写顺序表的博客
//				0.3.1.leetcode题解
//				0.3.2.顺序表详细博客
//# 1.复习顺序表
//> 1.0.顺序表结构体
typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* array;//存储数据
	size_t size;//当前已存储的数量
	size_t capicity;//当前最大容量
}SeqList;
//> 1.1.顺序表初始化
void SeqListInit(SeqList* psl)
{
    assert(psl);//避免空指针
    SLDataType* cache = (SLDataType*)malloc(sizeof(SLDataType) * INITIAL_NUMBER);//初始化就给INITIAL_NUMBER个数据空间
    if (!cache) exit(-1);//申请空间失败就会令程序结束
    psl->array = cache;//申请成功就将这块可用空间给顺序表
    psl->size = 0;
    psl->capicity = INITIAL_NUMBER;
}
//> 1.2.顺序表销毁
void SeqListDestory(SeqList* psl)
{
    assert(psl);
    free(psl->array);
    psl->array = NULL;
    psl->capicity = psl->size = 0;
}
//> 1.3.顺序表打印
void SeqListPrint(SeqList* psl)
{
    assert(psl);
    if (psl->size == 0)
    {
        printf("空顺序表\n");
        return;
    }
    for (int i = 0; i < psl->size; i++)
    {
        printf("%d ", psl->array[i]);
    }
    printf("\n");
}
//> 1.4.检查空间，如果满了，进行增容
void CheckCapacity(SeqList* psl)
{
    assert(psl);
    if (psl->capicity == psl->size)
    {
        SLDataType* cache = (SLDataType*)realloc(psl->array, sizeof(SLDataType) * psl->capicity * 2);
        if (!cache) exit(-1);
        psl->array = cache;
        psl->capicity = psl->capicity * 2;//容量倍增
    }
}
//> 1.5.顺序表尾插
void SeqListPushBack(SeqList* psl, SLDataType x)
{
    assert(psl);
    CheckCapacity(psl);//检查是否已满，满则增容
    psl->array[psl->size] = x;
    psl->size++;
}
//> 1.6.顺序表尾删
void SeqListPopBack(SeqList* psl)
{
    assert(psl);
    if (psl->size > 0)
    {
        psl->size--;
    }
    else
    {
        printf("删除失败\n");
    }
}
//> 1.7.顺序表头插
void SeqListPushFront(SeqList* psl, SLDataType x)
{
    assert(psl);
    CheckCapacity(psl);
    if (psl->size > 0)
    {
        for (int i = psl->size - 1; i >= 0; i--)
        {
            psl->array[i + 1] = psl->array[i];
        }
    }
    psl->array[0] = x;
    psl->size++;
}
//> 1.8.顺序表头删
void SeqListPopFront(SeqList* psl)
{
    assert(psl);
    if (psl->size > 0)
    {
        for (int i = 0; i < psl->size - 1; i++)
        {
            psl->array[i] = psl->array[i + 1];
        }
        psl->size--;
    }
    else
    {
        printf("删除失败\n");
    }
}
//> 1.9.顺序表查找
int SeqListFind(SeqList* psl, SLDataType x)
{
    assert(psl);
    for (int i = 0; i < psl->size; i++)
    {
        if (psl->array[i] == x)
        {
            return i;//返回x的下标
        }
    }
    return -1;
}
//> 1.10.顺序表在pos位置的值前插入x
void SeqListInsert(SeqList* psl, int pos, SLDataType x)
{
    assert(psl);//避免解引用空指针
    CheckCapacity(psl);//避免容量不够
    if (pos == 0 && psl->size == 0)
    {
        psl->array[0] = x;
        psl->size++;
        return;
    }
    assert(pos < psl->size && pos >= 0);//检查pos的合法性

    for (int i = psl->size - 1; i >= pos; i--)
    {
        psl->array[i + 1] = psl->array[i];
    }
    psl->array[pos] = x;
    psl->size++;
}
//> 1.11.顺序表在pos位置的值删除
void SeqListErase(SeqList* psl, int pos)
{
    assert(psl);
    assert(pos < psl->size && pos >= 0);//检查pos的合法性
    for (int i = pos; i < psl->size - 1; i++)
    {
        psl->array[i] = psl->array[i + 1];
    }
    psl->size--;
}
//> 1.12.顺序表在pos位置的值被修改
void SeqListAmend(SeqList* psl, int pos, SLDataType x)
{
    assert(psl);
    assert(pos < psl->size && pos >= 0);//检查pos的合法性
    psl->array[pos] = x;
}
int main()
{
    SeqList a;
    SeqListInit(&a);//初始化
    CheckCapacity(&a);//检查空间
    SeqListPushBack(&a, 1);//尾插
    SeqListPushBack(&a, 2);//尾插
    SeqListPushBack(&a, 3);//尾插
    SeqListPushBack(&a, 4);//尾插
    SeqListPushBack(&a, 5);//尾插
    SeqListPrint(&a);

    SeqListPopBack(&a);//尾删
    SeqListPopBack(&a);//尾删
    SeqListPopBack(&a);//尾删
    SeqListPopBack(&a);//尾删
    SeqListPrint(&a);
    SeqListPopBack(&a);//尾删
    SeqListPrint(&a);
    SeqListPopBack(&a);//尾删
    SeqListPopBack(&a);//尾删

    SeqListPushBack(&a, 1);//尾插
    SeqListPushFront(&a, -1);//头插
    SeqListPushFront(&a, -2);//头插
    SeqListPushFront(&a, -3);//头插
    SeqListPushFront(&a, -4);//头插
    SeqListPrint(&a);

    SeqListPopFront(&a);//头删
    SeqListPopFront(&a);//头删
    SeqListPopFront(&a);//头删
    SeqListPopFront(&a);//头删
    SeqListPrint(&a);
    SeqListPopFront(&a);//头删
    SeqListPopFront(&a);//头删
    SeqListPopFront(&a);//头删
    SeqListPrint(&a);

    SeqListInsert(&a, 0, 1000);//任意插入
    SeqListPrint(&a);
    SeqListInsert(&a, 0, 1000);//任意插入
    SeqListInsert(&a, 1, -1000);//任意插入
    SeqListInsert(&a, 2, -800);//任意插入
    SeqListInsert(&a, 0, 8000);//任意插入
    SeqListPrint(&a);

    SeqListErase(&a, 0);//任意删除
    SeqListErase(&a, 0);//任意删除
    SeqListPrint(&a);
    SeqListErase(&a, 2);//任意删除
    SeqListPrint(&a);
    SeqListErase(&a, 0);//任意删除
    SeqListPrint(&a);
    SeqListErase(&a, 0);//任意删除
    SeqListPrint(&a);

    SeqListInsert(&a, 0, 8000);//任意插入
    SeqListPrint(&a);
    SeqListInsert(&a, 0, 100);//任意插入
    SeqListPrint(&a);
    SeqListInsert(&a, 1, -100);//任意插入
    SeqListPrint(&a);
    SeqListAmend(&a, 1, 2);//修改
    SeqListPrint(&a);
    SeqListAmend(&a, 0, 1);//修改
    SeqListPrint(&a);
    SeqListAmend(&a, 2, 3);//修改
    SeqListPrint(&a);

    printf("%d\n", SeqListFind(&a, 3));//查找
    printf("%d\n", SeqListFind(&a, 4));//查找

    SeqListDestory(&a);//销毁
    return 0;
}

//# 2.使用顺序表思想
//> 0.2.1.1.原地删除元素：https://leetcode.cn/problems/remove-element/
//方法一：双指针法
int removeElement_1(int* nums, int numsSize, int val)
{
    int flag = 0;
    int i = 0, j = 0;
    while (j < numsSize)
    {
        if (nums[j] == val)
        {
            flag++;
            j++;
            if (j == numsSize) break;
        }
        else
        {
            nums[i] = nums[j];
            i++;
            j++;
        }
    }
    return numsSize - flag;
}
//方法二：遍历法
int removeElement_2(int* nums, int numsSize, int val)
{
    int flag = 0;
    for (int i = 0; i < numsSize - flag; i++)
    {
        int k = i;
        if (val == nums[i])
        {
            while (k + 1 < numsSize)
            {
                nums[k] = nums[k + 1];
                k++;
            }
            flag++;
            i--;
        }
    }
    return numsSize - flag;
}
//方法三：空间换时间（有一点小问题）
int removeElement_3(int* nums, int numsSize, int val)
{
    int* arr = (int*)malloc(sizeof(int) * numsSize);
    if (!arr) exit(-1);
    int j = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] != val)
        {
            arr[j] = nums[i];
            j++;
        }
    }
    memmove(nums, arr, sizeof(int) * j);
    return j;
}
//方法四和五（后面补上）
//> 0.2.1.2.合并两个有序数组：https://leetcode.cn/problems/merge-sorted-array/
//方法一：直接组合+快速排序（库函数）
int function(const void* p1, const void* p2)
{
    //注意必须返回int类型
    return (*((int*)p1) - *((int*)p2));
}
void merge(
    int* nums1, int nums1Size, int m,
    int* nums2, int nums2Size, int n
)
{
    for (int i = m, j = 0; i < nums1Size; i++, j++)
    {
        nums1[i] = nums2[j];
    }
    qsort(nums1, m + n, sizeof(int), function);
}
//# 3.写顺序表的博客