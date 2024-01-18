#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
//两个数组的交集：https://leetcode.cn/problems/intersection-of-two-arrays/
//快速排序辅助函数
int fun(const void* a, void* b)
{
    return (*((int*)a) - *((int*)b));
}
int* intersection(
    int* nums1, int nums1Size,
    int* nums2, int nums2Size,
    int* returnSize
)
{
    //申请一个数组保证能存储下数据
    int numsSize = (nums1Size > nums2Size) ? nums1Size : nums2Size;
    int* arr = (int*)malloc(sizeof(int) * numsSize);
    if (!arr) exit(-1);
    *returnSize = 0;
    //对两个数组进行排序
    qsort(nums1, nums1Size, sizeof(int), fun);
    qsort(nums2, nums2Size, sizeof(int), fun);
    //开始找交集数据
    int i = 0, j = 0;
    while (i < nums1Size && j < nums2Size)
    {
        if (nums1[i] == nums2[j])
        {
            if (!(*returnSize) || nums1[i] != arr[(*returnSize) - 1])
            {//“!(*returnSize)”是为了避免后面的arr数组越界
                arr[(*returnSize)++] = nums1[i];
            }
            i++;
            j++;
        }
        else if (nums1[i] < nums2[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    return arr;
}
int main()
{
	int number_1[4] = { 1, 2, 2, 1 };
	int number_2[2] = { 2, 2 };

	int size = 0;
	int * number = intersection(number_1, 4, number_2, 2, &size);
	return 0;
}