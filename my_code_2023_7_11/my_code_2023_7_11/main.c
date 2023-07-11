#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 50
//< 1.测试一

//typedef int HPDataType;
////利用前面写好的向下调整算法，模拟堆的入堆和出堆 
//void AdjustDown(HPDataType* arr, int arrsize, int parenti)
//{
//    int childi = parenti * 2 + 1;//先将左孩子索引赋给childi
//    while (childi < arrsize)//childi + 1 < arrsize不能写在这里，因为有可能左孩子存在但是没有右孩子 
//    {
//        //1.修正孩子坐标
//        if (childi + 1 < arrsize && arr[childi] < arr[childi + 1])
//        {
//            childi++;
//        }
//        //2.判断是否需要交换
//        if (arr[childi] > arr[parenti])
//        {
//            int tmp = arr[childi];
//            arr[childi] = arr[parenti];
//            arr[parenti] = tmp;
//
//            parenti = childi;
//            childi = parenti * 2 + 1;
//        }
//        else
//        {
//            break;
//        }
//    }
//}
//void HeapSort_3(int* arr, int arrsize)
//{
//    //从叶子节点开始倒着调整（自成一个堆），所以从第一个非叶子节点开始调整
//    //1.利用向下调整来建堆
//    for (int i = ((arrsize - 1) - 1) / 2; i >= 0; i--)
//    {
//        AdjustDown(arr, arrsize, i);
//    }
//    //2.利用向下调整法来排序
//    for (int i = arrsize - 1; i > 0; i--)
//    {
//        int tmp = arr[0];
//        arr[0] = arr[i];
//        arr[i] = tmp;
//        AdjustDown(arr, i, 0);
//    }
//}
//void test_1(void)
//{
//    int arr[7] = { 1, 3, 4, 2, 0 ,3, 2};
//    for (int i = 0; i < 7; i++)
//    {
//        printf("%d ", arr[i]);
//    }
//    printf("\n");
//    HeapSort_3(arr, sizeof(arr) / sizeof(int));//堆排序
//    for (int i = 0; i < 7; i++)
//    {
//        printf("%d ", arr[i]);
//    }
//    printf("\n");
//}

//< 2.测试2

//void _Swap(int* x, int* y)
//{
//    int tmp = *x;
//    *x = *y;
//    *y = tmp;
//}
//int _PartSort(int* arr, int lefti, int righti)
//{
//    int keyi = lefti;
//    while (lefti < righti)
//    {
//        while (lefti < righti && arr[righti] >= arr[keyi])//跟key相等无所谓在哪一个区间
//        {
//            righti--;
//        }
//        while (lefti < righti && arr[lefti] <= arr[keyi])//跟key相等无所谓在哪一个区间
//        {
//            lefti++;
//        }
//        _Swap(&arr[righti], &arr[lefti]);
//    }
//    _Swap(&arr[lefti], &arr[keyi]);
//    return lefti;
//}
//void Hoare_QuickSort(int* arr, int lefti, int righti)
//{
//    if (lefti >= righti)//区间不存在或是区间内只有一个值
//    {
//        return;
//    }
//    int keyi = _PartSort(arr, lefti, righti);
//    //[lefti, keyi-1] keyi [keyi+1, righti]
//    Hoare_QuickSort(arr, lefti, keyi - 1);
//    Hoare_QuickSort(arr, keyi + 1, righti);
//}
//void test_2()
//{
//    srand((unsigned)time(0));
//    int arr[SIZE];
//    for (int i = 0; i < SIZE; i++)
//    {
//        arr[i] = rand() % 50;
//        printf("%d ", arr[i]);
//    }
//    printf("\n");
//    Hoare_QuickSort(arr, 0, SIZE - 1);//堆排序
//    for (int i = 0; i < SIZE; i++)
//    {
//        printf("%d ", arr[i]);
//    }
//    printf("\n");
//}

//< 3.测试3

//挖坑法
//void _Swap(int* x, int* y)
//{
//    int tmp = *x;
//    *x = *y;
//    *y = tmp;
//}
//int _PartSort(int* arr, int lefti, int righti)
//{
//    int key = arr[lefti];
//    int holei = lefti;//坑的索引
//    while (lefti < righti)
//    {
//        while (lefti < righti && arr[righti] >= key)
//        {
//            righti--;
//        }
//        arr[holei] = arr[righti];
//        holei = righti;
//        
//        while (lefti < righti && arr[lefti] <= key)
//        {
//            lefti++;
//        }
//        arr[holei] = arr[lefti];
//        holei = lefti;
//    }
//    arr[holei] = key;
//    return holei;
//}
//void Pitfall_QuickSort(int* arr, int lefti, int righti)
//{
//    if (lefti >= righti)//区间不存在或是区间内只有一个值
//    {
//        return;
//    }
//    int keyi = _PartSort(arr, lefti, righti);
//    //[lefti, keyi-1] keyi [keyi+1, righti]
//    Pitfall_QuickSort(arr, lefti, keyi - 1);
//    Pitfall_QuickSort(arr, keyi + 1, righti);
//}
//void test_3()
//{
//    srand((unsigned)time(0));
//    int arr[SIZE];
//    for (int i = 0; i < SIZE; i++)
//    {
//        arr[i] = rand() % SIZE;
//        printf("%d ", arr[i]);
//    }
//    printf("\n");
//    Pitfall_QuickSort(arr, 0, SIZE - 1);//堆排序
//    for (int i = 0; i < SIZE; i++)
//    {
//        printf("%d ", arr[i]);
//    }
//    printf("\n");
//}

//< 4.测试4

//void _Swap(int* x, int* y)
//{
//    int tmp = *x;
//    *x = *y;
//    *y = tmp;
//}
//int _PartSort(int* arr, int lefti, int righti)
//{
//    //还可以在这里使用三数取中法来优化，避免出现key是整个待排数组的最值，导致O(n)退化为n^2
//    curi实际上一直往后走的
//    int keyi = lefti;
//    int previ = lefti, curi = previ + 1;
//    while (curi <= righti)
//    {
//        if (arr[curi] < arr[keyi] && curi != ++previ)
//        {
//            _Swap(&arr[previ], &arr[curi]);
//        }
//        curi++;
//    }
//    _Swap(&arr[keyi], &arr[previ]);
//    return previ;
//}
//void QuickSort(int* arr, int lefti, int righti)
//{
//    if (lefti >= righti)//区间不存在或是区间内只有一个值
//    {
//        return;
//    }
//    int keyi = _PartSort(arr, lefti, righti);
//    [lefti, keyi-1] keyi [keyi+1, righti]
//    QuickSort(arr, lefti, keyi - 1);
//    QuickSort(arr, keyi + 1, righti);
//}
//void test_4()
//{
//    srand((unsigned)time(0));
//    int arr[SIZE];
//    for (int i = 0; i < SIZE; i++)
//    {
//        arr[i] = rand() % SIZE;
//        printf("%d ", arr[i]);
//    }
//    printf("\n");
//    QuickSort(arr, 0, SIZE - 1);//堆排序
//    for (int i = 0; i < SIZE; i++)
//    {
//        printf("%d ", arr[i]);
//    }
//    printf("\n");
//}

//< 5.测试5

/*
描述：
在一个长为字符串中找到第一个只出现一次的字符,
并返回它的位置,如果没有则返回-1（需要区分大小写)（从0开始计数）
数据范围：0≤n≤10000,且字符串只有字母组成。

要求：
空间复杂度O(n)
时间复杂度O(n)
*/
int FirstNotRepeatingChar(char* str) 
{
    char arr[48] = { 0 };
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            arr[str[i] - 'A' + 26] += 1;
        }
        else if(str[i] >= 'a' && str[i] <= 'z')
        {
            arr[str[i] - 'a'] += 1;
        }
    }
    for (int j = 0; str[j] != '\0'; j++)
    {
        if (str[j] >= 'a' && str[j] <= 'z' && arr[str[j] - 'a'] == 1)
        {
            return j;
        }
        else if (str[j] >= 'A' && str[j] <= 'Z' && arr[str[j] - 'a' + 26] == 1)
        {
            return j;
        }
    }
    return -1;
}
void test_5()
{
    printf("%d", FirstNotRepeatingChar("lRYdsgSqrIOakFmgyrlOXPqMAdOlmyuUvlNlWjKlctBYahulmDGXEMlBLvpllLezXeOMzlVeqnYvH"));
}
int main()
{
    //test_1();
    //test_2();
    //test_3();
    //test_4();
    test_5();
    return 0;
}