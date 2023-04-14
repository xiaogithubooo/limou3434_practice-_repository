#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define INITIAL_NUMBER 3
//# 0.Ŀ�꣺˳������ϰ
//>		 0.1.��ϰ˳���
//			0.1.1.���¿�˳���code
//			0.1.2.��˳���code���е���
//			0.1.3.while(!(�ɹ�д��˳���)) {��ȥ������;}
//>		 0.2.ʹ��˳���˼��
//x			0.2.1.ˢ�Ƽ�����ҵ����Ŀ
//x				0.2.1.1.�Ƴ�Ԫ�أ�https://leetcode.cn/problems/remove-element/
//x				0.2.1.2.�ϲ������������飺https://leetcode.cn/problems/merge-sorted-array/
//			0.2.2.ˢ���۵���Ŀ
//				0.2.2.1.ɾ�����������е��ظ��https://leetcode.cn/problems/remove-duplicates-from-sorted-array/
//				0.2.2.2.�������й������飺https://leetcode.cn/problems/build-array-from-permutation/
//				0.2.2.3.��������λ�ã����ַ���ϰ����https://leetcode.cn/problems/search-insert-position/description/
//				0.2.2.4.�����ظ�Ԫ�أ�https://leetcode.cn/problems/contains-duplicate/description/?envType=study-plan&id=shu-ju-jie-gou-ru-men&plan=data-structures&plan_progress=x5znyghm
//				0.2.2.5.���������ͣ�https://leetcode.cn/problems/maximum-subarray/?envType=study-plan&id=shu-ju-jie-gou-ru-men&plan=data-structures&plan_progress=x5znyghm
//>		 0.3.д˳���Ĳ���
//				0.3.1.leetcode���
//				0.3.2.˳�����ϸ����
//# 1.��ϰ˳���
//> 1.0.˳���ṹ��
typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* array;//�洢����
	size_t size;//��ǰ�Ѵ洢������
	size_t capicity;//��ǰ�������
}SeqList;

//> 1.1.˳����ʼ��
void SeqListInit(SeqList* psl)
{
    assert(psl);//�����ָ��
    SLDataType* cache = (SLDataType*)malloc(sizeof(SLDataType) * INITIAL_NUMBER);//��ʼ���͸�INITIAL_NUMBER�����ݿռ�
    if (!cache) exit(-1);//����ռ�ʧ�ܾͻ���������
    psl->array = cache;//����ɹ��ͽ������ÿռ��˳���
    psl->size = 0;
    psl->capicity = INITIAL_NUMBER;
}
//> 1.2.˳�������
void SeqListDestory(SeqList* psl)
{
    assert(psl);
    free(psl->array);
    psl->array = NULL;
}
//> 1.3.˳����ӡ
void SeqListPrint(SeqList* psl)
{
    assert(psl);
    for (int i = 0; i < psl->size; i++)
    {
        printf("%d ", psl->array[i]);
    }
}
//> 1.4.���ռ䣬������ˣ���������
void CheckCapacity(SeqList* psl)
{
    assert(psl);
    if (psl->capicity == psl->size)
    {
        SLDataType* cache = (SLDataType*)realloc(psl->array, sizeof(SLDataType) * 2);
        psl->capicity = psl->capicity * 2;//��������
    }
}

//> 1.5.˳���β��
void SeqListPushBack(SeqList* psl, SLDataType x)
{
    ��
}
//> 1.6.˳���βɾ
void SeqListPopBack(SeqList* psl);
//> 1.7.˳���ͷ��
void SeqListPushFront(SeqList* psl, SLDataType x);
//> 1.8.˳���ͷɾ
void SeqListPopFront(SeqList* psl);

//> 1.9.˳������
int SeqListFind(SeqList* psl, SLDataType x)
{
    assert(psl);
    for (int i = 0; i < psl->size; i++)
    {
        if (psl->array[i] == x)
        {
            return i;//����x���±�
        }
    }
    return -1;
}
//> 1.10.˳�����posλ�õ�ֵǰ����x
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x);
//> 1.11.˳�����posλ�õ�ֵɾ��
void SeqListErase(SeqList* psl, size_t pos);
//> 1.12.˳�����posλ�õ�ֵ���޸�
void SeqListAmend(SeqList* psl, size_t pos, SLDataType x)
{
    assert(psl);
    if (pos < psl->size && pos >= 0)//����Ƿ�����
    {
        psl->array[pos] = x;
    }
}

//# 2.ʹ��˳���˼��
//> 0.2.1.1.ԭ��ɾ��Ԫ�أ�https://leetcode.cn/problems/remove-element/
//����һ��˫ָ�뷨
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
//��������������
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
//���������ռ任ʱ�䣨��һ��С���⣩
int removeElement_3(int* nums, int numsSize, int val)
{
    int* arr = (int*)malloc(sizeof(int) * numsSize);
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
//�����ĺ��壨���油�ϣ�
//> 0.2.1.2.�ϲ������������飺https://leetcode.cn/problems/merge-sorted-array/
//����һ��ֱ�����+�������򣨿⺯����
int function(const void* p1, const void* p2)
{
    //ע����뷵��int����
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
//# 3.д˳���Ĳ���