#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <errno.h>
#define INITIAL_NUMBER 4

//# 0.目标：顺序表的练习
//>		 0.1.复习“顺序表”
//x			0.1.1.重新看“顺序表”code
//x			0.1.2.对“顺序表”code进行调试
//x			0.1.3.while(!(成功写出“顺序表”)) {回去看代码;}
//>		 0.2.使用“顺序表”思想
//x			0.2.1.刷推荐和作业的题目
//x				0.2.1.1.移除元素：https://leetcode.cn/problems/remove-element/
//x				0.2.1.2.合并两个有序数组：https://leetcode.cn/problems/merge-sorted-array/
//			0.2.2.刷力扣的题目
//x				0.2.2.1.删除有序数组中的重复项：https://leetcode.cn/problems/remove-duplicates-from-sorted-array/
//				0.2.2.2.基于排列构建数组：https://leetcode.cn/problems/build-array-from-permutation/
//				0.2.2.3.搜索插入位置（二分法复习）：https://leetcode.cn/problems/search-insert-position/description/
//				0.2.2.4.存在重复元素：https://leetcode.cn/problems/contains-duplicate/description/?envType=study-plan&id=shu-ju-jie-gou-ru-men&plan=data-structures&plan_progress=x5znyghm
//				0.2.2.5.最大子数组和：https://leetcode.cn/problems/maximum-subarray/?envType=study-plan&id=shu-ju-jie-gou-ru-men&plan=data-structures&plan_progress=x5znyghm
//              0.2.2.6.两个数组的交集：https://leetcode.cn/problems/intersection-of-two-arrays/
//>		 0.3.写“顺序表”的博客
//				0.3.1.leetcode题解
//				0.3.2.顺序表详细博客

//# 1.复习顺序表（较短时间的情况下，只需要写出“任意增、任意删、查找、修改”即可）
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
    if (!cache)
    {
        perror("malloc fail");
        return;
    }
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
        if (!cache)
        {
            perror("malloc fail");
            return;
        }

        psl->array = cache;
        psl->capicity *= 2;//容量倍增
    }
}
//> 1.5.顺序表尾插
void SeqListPushBack(SeqList* psl, SLDataType x)
{
    assert(psl);
    CheckCapacity(psl);//检查是否已满，满则增容
    psl->array[psl->size++] = x;
    //psl->size++;
}
//> 1.6.顺序表尾删
void SeqListPopBack(SeqList* psl)
{
    //直接操控size就可以
    assert(psl);
    assert(psl->size > 0);//直接使用较为暴力的检查，这样就会直接报错
    //if (psl->size > 0)
    //{
        psl->size--;
    //}
    //else
    //{
    //    printf("删除失败\n");//比较柔和的检查
    //}
}
//> 1.7.顺序表头插
void SeqListPushFront(SeqList* psl, SLDataType x)
{
    assert(psl);
    CheckCapacity(psl);
    //if (psl->size > 0)//这个判断没有必要
    //{
        for (int i = psl->size - 1; i >= 0; i--)
        {
            psl->array[i + 1] = psl->array[i];
        }
    //}
    psl->array[0] = x;
    psl->size++;
    //实际上还有另外一种简单的方式就是使用mommove库函数
}
//> 1.8.顺序表头删
void SeqListPopFront(SeqList* psl)
{
    assert(psl);
    assert(psl->size > 0);//暴力检查
    //if (psl->size > 0)
    //{
        for (int i = 0; i < psl->size - 1; i++)
        {
            psl->array[i] = psl->array[i + 1];
        }
        psl->size--;
    //}
    //else
    //{
    //    printf("删除失败\n");
    //}
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
    return -1;//下标不可能是负数
}
//> 1.10.顺序表在pos位置的值前插入x
void SeqListInsert(SeqList* psl, int pos, SLDataType x)
{
    assert(psl);//避免解引用空指针
    CheckCapacity(psl);//避免容量不够

    //if (pos == 0 && psl->size == 0)//这一串代码是多余的，后面的代码足以完成头插和尾插
    //{
    //    psl->array[0] = x;
    //    psl->size++;
    //    return;
    //}

    assert(pos <= psl->size && pos >= 0);//检查pos的合法性，等号代表头插和尾插
    for (int i = psl->size - 1; i >= pos; i--)//如果是头插和尾插就不会进入循环
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
    assert(pos < psl->size && pos >= 0);//检查pos的合法性，注意有了这个语句就不需要加上assert(psl->size > 0);这条语句，因为被这条语句间接检查了
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
//> 1.13.顺序表的测试用例
void test_1()
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
    //SeqListPopBack(&a);//尾删
    //SeqListPopBack(&a);//尾删

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
    //SeqListPopFront(&a);//头删
    //SeqListPopFront(&a);//头删
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
}
void test_2()
{
    SeqList sl;//创建顺序表变量
    SeqListInit(&sl);//初始化顺序表
    SeqListPushBack(&sl, 1);//尾插
    SeqListPushBack(&sl, 2);//尾插
    SeqListPushBack(&sl, 3);//尾插
    SeqListPushFront(&sl, 0);//头插
    SeqListPrint(&sl);//打印
    SeqListPopFront(&sl);//头删
    SeqListPopBack(&sl);//尾删
    SeqListPrint(&sl);//打印
    SeqListDestory(&sl);//销毁顺序表
}
void test_3()
{
    SeqList sl;//创建顺序表变量
    SeqListInit(&sl);//初始化顺序表
    SeqListPushBack(&sl, 1);//尾插
    SeqListPushBack(&sl, 2);//尾插
    SeqListPushBack(&sl, 3);//尾插
    SeqListInsert(&sl, 0, 0);//任意插入
    SeqListInsert(&sl, 2, 10);//任意插入
    SeqListErase(&sl, 4);//任意删除
    SeqListAmend(&sl, 1, 20);//任意修改
    SeqListPrint(&sl);//打印
    SeqListDestory(&sl);//销毁
}
void test_4()
{
    SeqList sl;
    SeqListInit(&sl);//初始化
    for (int i = 0; i < 10; i++) 
    {
        SeqListPushBack(&sl, i);//循环尾插
    }
    SeqListPrint(&sl);//打印
    SeqListPushBack(&sl, 10);//尾插
    SeqListPrint(&sl);//打印
    SeqListDestory(&sl);//销毁
}
void test_5()
{
    SeqList sl;
    SeqListInit(&sl);//初始化
    for (int i = 0; i < 10; i++) 
    {
        SeqListPushFront(&sl, i);//循环尾插
    }
    SeqListPrint(&sl);//打印
    SeqListPushFront(&sl, 10);//头插
    SeqListPrint(&sl);//打印
    SeqListDestory(&sl);//销毁
}
void test_6()
{
    SeqList sl;
    SeqListInit(&sl);//初始化
    SeqListPushBack(&sl, 1);//尾插
    SeqListPushBack(&sl, 2);//尾插
    SeqListPushBack(&sl, 3);//尾插
    printf("%d\n", SeqListFind(&sl, 2));//查找成功
    printf("%d\n", SeqListFind(&sl, 4));//查找失败
    SeqListDestory(&sl);
}

//# 2.使用顺序表思想
//> 原地删除元素
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
//> 合并两个有序数组
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
//> 删除有序数组中的重复项
int removeDuplicates(int* nums, int numsSize)
{
    int* p1, * p2, * p;//左、右指针，头指针
    p1 = p2 = p = nums;
    while (p2 <= &nums[numsSize - 1])
    {
        if (*p1 == *p2)
        {
            p2++;
        }
        else
        {
            p1++;
            *p1 = *p2;
        }
    }
    return (p1 - p + 1);
}//> 两个数组的交集
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize)
{
    int* arr = (int*)malloc(sizeof(int) * ((nums1Size + nums2Size)));
    if (!arr) exit(-1);
    int k = 0;
    for (int i = 0; i < nums2Size; i++)
    {
        for (int j = 0; j < nums1Size; j++)
        {
            if (nums1[j] == nums2[i])
            {
                arr[k] = nums2[i];
                k++;
                break;
            }
        }
    }
    *returnSize = k;
    return arr;
}
void test()
{
    int arr1[5] = { 1, 2, 3, 2, 1 };
    int arr2[2] = { 2, 3 };
    int number = 0;
    int* arr = intersection(arr1, 5, arr2, 2, &number);
    for (int i = 0; i < number; i++)
    {
        printf("%d ", arr[i]);
    }
}

//# 3.写“顺序表”的博客

//# 4.测试函数
int main()
{
    //顺序表测试
    //test_1();
    //test_2();
    //test_3();
    //test_4();
    //test_5();
    //test_6();
    return 0;
}