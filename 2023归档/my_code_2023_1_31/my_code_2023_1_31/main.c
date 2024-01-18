#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
////1、数字在升序数组中出现的次数
/**
 *
 * @param data int整型一维数组
 * @param dataLen int data数组长度
 * @param k int整型
 * @return int整型
 */
//int GetNumberOfK(int* data, int dataLen, int k)
//{
//    int add = 0;
//    for (int i = 0; i < dataLen; i++)
//    {
//        if (k == data[i])
//        {
//            add++;
//        }
//    }
//    return add;
//}
////2、验证作业代码
//int main()
//{
//	for (int i = 0; i || i++ < 5;)
//	{
//		printf("%d", i);
//	}
//	return 0;
//}
////3、力扣代码：至少是其他数字两倍的最大数
//int dominantIndex(int* nums, int numsSize)
//{
//    if (numsSize == 1)   return 0;
//    int max = 0;
//    int i = 0;
//    int I = 0;
//    int max_x = 0;
//    for (i = 0; i < numsSize; i++)
//    {
//        if (nums[i] >= max)
//        {
//            max = nums[i];
//            I = i;
//        }
//    }
//    nums[I] = 0;
//    for (i = 0; i < numsSize; i++)
//    {
//        if (nums[i] >= max_x)
//        {
//            max_x = nums[i];
//        }
//    }
//    if (2 * max_x <= max)
//    {
//        return I;
//    }
//    return -1;
//}
