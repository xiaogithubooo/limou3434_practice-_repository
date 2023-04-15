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
    psl->capicity = psl->size = 0;
}
//> 1.3.˳����ӡ
void SeqListPrint(SeqList* psl)
{
    assert(psl);
    if (psl->size == 0)
    {
        printf("��˳���\n");
        return;
    }
    for (int i = 0; i < psl->size; i++)
    {
        printf("%d ", psl->array[i]);
    }
    printf("\n");
}
//> 1.4.���ռ䣬������ˣ���������
void CheckCapacity(SeqList* psl)
{
    assert(psl);
    if (psl->capicity == psl->size)
    {
        SLDataType* cache = (SLDataType*)realloc(psl->array, sizeof(SLDataType) * psl->capicity * 2);
        if (!cache) exit(-1);
        psl->array = cache;
        psl->capicity = psl->capicity * 2;//��������
    }
}
//> 1.5.˳���β��
void SeqListPushBack(SeqList* psl, SLDataType x)
{
    assert(psl);
    CheckCapacity(psl);//����Ƿ���������������
    psl->array[psl->size] = x;
    psl->size++;
}
//> 1.6.˳���βɾ
void SeqListPopBack(SeqList* psl)
{
    assert(psl);
    if (psl->size > 0)
    {
        psl->size--;
    }
    else
    {
        printf("ɾ��ʧ��\n");
    }
}
//> 1.7.˳���ͷ��
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
//> 1.8.˳���ͷɾ
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
        printf("ɾ��ʧ��\n");
    }
}
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
void SeqListInsert(SeqList* psl, int pos, SLDataType x)
{
    assert(psl);//��������ÿ�ָ��
    CheckCapacity(psl);//������������
    if (pos == 0 && psl->size == 0)
    {
        psl->array[0] = x;
        psl->size++;
        return;
    }
    assert(pos < psl->size && pos >= 0);//���pos�ĺϷ���

    for (int i = psl->size - 1; i >= pos; i--)
    {
        psl->array[i + 1] = psl->array[i];
    }
    psl->array[pos] = x;
    psl->size++;
}
//> 1.11.˳�����posλ�õ�ֵɾ��
void SeqListErase(SeqList* psl, int pos)
{
    assert(psl);
    assert(pos < psl->size && pos >= 0);//���pos�ĺϷ���
    for (int i = pos; i < psl->size - 1; i++)
    {
        psl->array[i] = psl->array[i + 1];
    }
    psl->size--;
}
//> 1.12.˳�����posλ�õ�ֵ���޸�
void SeqListAmend(SeqList* psl, int pos, SLDataType x)
{
    assert(psl);
    assert(pos < psl->size && pos >= 0);//���pos�ĺϷ���
    psl->array[pos] = x;
}
int main()
{
    SeqList a;
    SeqListInit(&a);//��ʼ��
    CheckCapacity(&a);//���ռ�
    SeqListPushBack(&a, 1);//β��
    SeqListPushBack(&a, 2);//β��
    SeqListPushBack(&a, 3);//β��
    SeqListPushBack(&a, 4);//β��
    SeqListPushBack(&a, 5);//β��
    SeqListPrint(&a);

    SeqListPopBack(&a);//βɾ
    SeqListPopBack(&a);//βɾ
    SeqListPopBack(&a);//βɾ
    SeqListPopBack(&a);//βɾ
    SeqListPrint(&a);
    SeqListPopBack(&a);//βɾ
    SeqListPrint(&a);
    SeqListPopBack(&a);//βɾ
    SeqListPopBack(&a);//βɾ

    SeqListPushBack(&a, 1);//β��
    SeqListPushFront(&a, -1);//ͷ��
    SeqListPushFront(&a, -2);//ͷ��
    SeqListPushFront(&a, -3);//ͷ��
    SeqListPushFront(&a, -4);//ͷ��
    SeqListPrint(&a);

    SeqListPopFront(&a);//ͷɾ
    SeqListPopFront(&a);//ͷɾ
    SeqListPopFront(&a);//ͷɾ
    SeqListPopFront(&a);//ͷɾ
    SeqListPrint(&a);
    SeqListPopFront(&a);//ͷɾ
    SeqListPopFront(&a);//ͷɾ
    SeqListPopFront(&a);//ͷɾ
    SeqListPrint(&a);

    SeqListInsert(&a, 0, 1000);//�������
    SeqListPrint(&a);
    SeqListInsert(&a, 0, 1000);//�������
    SeqListInsert(&a, 1, -1000);//�������
    SeqListInsert(&a, 2, -800);//�������
    SeqListInsert(&a, 0, 8000);//�������
    SeqListPrint(&a);

    SeqListErase(&a, 0);//����ɾ��
    SeqListErase(&a, 0);//����ɾ��
    SeqListPrint(&a);
    SeqListErase(&a, 2);//����ɾ��
    SeqListPrint(&a);
    SeqListErase(&a, 0);//����ɾ��
    SeqListPrint(&a);
    SeqListErase(&a, 0);//����ɾ��
    SeqListPrint(&a);

    SeqListInsert(&a, 0, 8000);//�������
    SeqListPrint(&a);
    SeqListInsert(&a, 0, 100);//�������
    SeqListPrint(&a);
    SeqListInsert(&a, 1, -100);//�������
    SeqListPrint(&a);
    SeqListAmend(&a, 1, 2);//�޸�
    SeqListPrint(&a);
    SeqListAmend(&a, 0, 1);//�޸�
    SeqListPrint(&a);
    SeqListAmend(&a, 2, 3);//�޸�
    SeqListPrint(&a);

    printf("%d\n", SeqListFind(&a, 3));//����
    printf("%d\n", SeqListFind(&a, 4));//����

    SeqListDestory(&a);//����
    return 0;
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