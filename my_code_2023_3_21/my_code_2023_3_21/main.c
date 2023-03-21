//1、力扣刷题：两数之和，https://leetcode.cn/problems/two-sum/submissions/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    if (numsSize == 0)//如果数组没有元素，给了目标值也没办法寻找
    {
        return returnSize;
    }
    else//如果数组至少有一个元素，就可以开始寻找了
    {
        int* ret = malloc(sizeof(int) * 2);//6了，这个要自己创建返回数组

        for (int i = 0; i < numsSize - 1; i++)//先找数组中一个数
        {
            int temp = target - nums[i];//将目标值和这个数相减
            ret[0] = i;
            for (int j = i + 1; j < numsSize; j++)//看看是否能在后面找到temp
            {
                if (nums[j] == temp)
                {
                    ret[1] = j;
                    goto mybreak;
                }
            }
        }
    mybreak:
        *returnSize = 2;//还要自己把创建好的ret数组大小通过指针带回
        return ret;//返回数组
    }
}
//2、通讯录的实现
//……

//3、力扣刷题，温度转化：https://leetcode.cn/problems/convert-the-temperature/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
double* convertTemperature(double celsius, int* returnSize)
{
    double* arr = (double*)malloc(sizeof(double) * 2);
    arr[0] = celsius + 273.15;
    arr[1] = celsius * 1.80 + 32.00;
    *returnSize = 2;
    return arr;
}

//4、力扣刷题，执行操作后的变量值：https://leetcode.cn/problems/final-value-of-variable-after-performing-operations/
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
int finalValueAfterOperations(char** operations, int operationsSize)
{
    int X = 0;
    for (int i = 0; i < operationsSize; i++)
    {
        char* p = operations[i];//获取命令字符串
        if (strcmp(p, "X++") == 0)
        {
            X++;
        }
        else if (strcmp(p, "++X") == 0)
        {
            ++X;
        }
        else if (strcmp(p, "X--") == 0)
        {
            X--;
        }
        else if (strcmp(p, "--X") == 0)
        {
            --X;
        }
        else
        {
            ;
        }
    }
    return X;
}
int main()
{
    char* arr[2] = { "X++", "X--" };
    printf("%d", finalValueAfterOperations(arr, 2));
    return 0;
}