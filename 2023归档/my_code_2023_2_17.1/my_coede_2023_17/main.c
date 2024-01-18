#define _CRT_SECURE_NO_WARNINGS 1
////1、力扣题目
//int missingNumber(int* nums, int numsSize)
//{
//    int add_1 = 0;
//    int add_2 = 0;
//    for (int i = 0; i <= numsSize; i++)
//    {
//        add_1 += i;
//        if (i < numsSize)
//        {
//            add_2 += nums[i];
//        }
//    }
//    return add_1 - add_2;
//}
//int missingNumber(int* nums, int numsSize)
//{
//    int x = 0;
//    int i = 0;
//
//    for (i = 0; i < numsSize; i++)//用for循环求出数组nums元素的异或和
//    {
//        x ^= nums[i];
//    }
//
//    for (i = 0; i < numsSize + 1; i++)//运用异或的性质a^a=0来找出消失的数字
//    {
//        x ^= i;
//    }
//    return x;
//}
////2、力扣题目
//思路一：
//void rotate(int* nums, int numsSize, int k)
//{
//    while (k--)
//    {
//        int tmp = nums[numsSize - 1];//保留最后一个数字
//        for (int end = numsSize - 2; end >= 0; --end)//开始将最后一个数字前面的所有数字后移
//        {
//            nums[end + 1] = nums[end];
//        }
//        nums[0] = tmp;
//    }
//}
//但是超出了时间限制
//思路二：
//void Reverse(int* nums, int left, int right)
//{
//    while (left < right)//奇数个会相等，偶数个会错开
//    {
//        int tmp = nums[left];
//        nums[left] = nums[right];
//        nums[right] = tmp;
//        ++left;
//        --right;
//    }
//}
//void rotate(int* nums, int numsSize, int k)
//{
//    if (k >= numsSize)//防止k大于数组大小，例如7个元素旋转13次和6次等价
//    {
//        k %= numsSize;
//    }
//    Reverse(nums, numsSize - k, numsSize - 1);//后半部分
//    Reverse(nums, 0, numsSize - k - 1);//前半部分
//    Reverse(nums, 0, numsSize - 1);
//}