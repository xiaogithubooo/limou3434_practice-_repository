//1������ˢ�⣺����֮�ͣ�https://leetcode.cn/problems/two-sum/submissions/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    if (numsSize == 0)//�������û��Ԫ�أ�����Ŀ��ֵҲû�취Ѱ��
    {
        return returnSize;
    }
    else//�������������һ��Ԫ�أ��Ϳ��Կ�ʼѰ����
    {
        int* ret = malloc(sizeof(int) * 2);//6�ˣ����Ҫ�Լ�������������

        for (int i = 0; i < numsSize - 1; i++)//����������һ����
        {
            int temp = target - nums[i];//��Ŀ��ֵ����������
            ret[0] = i;
            for (int j = i + 1; j < numsSize; j++)//�����Ƿ����ں����ҵ�temp
            {
                if (nums[j] == temp)
                {
                    ret[1] = j;
                    goto mybreak;
                }
            }
        }
    mybreak:
        *returnSize = 2;//��Ҫ�Լ��Ѵ����õ�ret�����Сͨ��ָ�����
        return ret;//��������
    }
}
//2��ͨѶ¼��ʵ��
//����

//3������ˢ�⣬�¶�ת����https://leetcode.cn/problems/convert-the-temperature/
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

//4������ˢ�⣬ִ�в�����ı���ֵ��https://leetcode.cn/problems/final-value-of-variable-after-performing-operations/
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
int finalValueAfterOperations(char** operations, int operationsSize)
{
    int X = 0;
    for (int i = 0; i < operationsSize; i++)
    {
        char* p = operations[i];//��ȡ�����ַ���
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