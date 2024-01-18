#define _CRT_SECURE_NO_WARNINGS 1
//1、牛客题目：选择数组题
/**
 *
 * @param rotateArray int整型一维数组
 * @param rotateArrayLen int rotateArray数组长度
 * @return int整型
 */
int minNumberInRotateArray(int* rotateArray, int rotateArrayLen)
{
    int I = 0;
    for (int i = 0; i < rotateArrayLen - 1; i++)
    {
        if (rotateArray[i] > rotateArray[i + 1])
        {
            I = i;
            break;
        }
        else
        {
            I = -1;
        }
    }
    return rotateArray[I + 1];
}
//2、牛客题目：密码检查但是没写完
#include <stdio.h>
#define NUM 100

int main()
{
    char arr[NUM];//存储密码
    int n = 0;//存储行数 
    int I = 0;
    while (scanf("&d", &n) == 1 && (n >= 8) && (n <= 100))
    {
        scanf("%s", arr);
        int size = strlen(arr);
        for (int i = 0; i < size; i++)
        {
            if
                (
                    (
                        (arr[i] >= 'a' && arr[i] <= 'z') ||
                        (arr[i] >= 'A' && arr[i] <= 'Z')
                    ) &&
                        (arr[i] >= '0' && arr[i] <= '9') &&
                        (arr[0] < '1' && arr[0] > '9')
                )
            {

            }
        }
    }
    return 0;
}