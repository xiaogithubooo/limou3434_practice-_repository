#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

//int GetMidIndex(int* arr, int lefti, int righti)
//{
//    int mid = (lefti + righti) >> 1;//取平均值
//    if (arr[lefti] < arr[mid])
//    {
//        if (arr[mid] < arr[righti])
//        {
//            return mid;
//        }
//        else if (arr[lefti] > arr[righti])
//        {
//            return lefti;
//        }
//        else
//        {
//            return righti;
//        }
//    }
//    else//arr[lefti] > arr[mid]
//    {
//        if (arr[mid] > arr[righti])
//        {
//            return mid;
//        }
//        else if (arr[lefti] < arr[righti])
//        {
//            return lefti;
//        }
//        else
//        {
//            return righti;
//        }
//    }
//}
//void _Swap(int* x, int* y)
//{
//    int tmp = *x;
//    *x = *y;
//    *y = tmp;
//}
//int _PartSort(int* arr, int lefti, int righti)
//{
//    int index = GetMidIndex(arr, lefti, righti);
//    _Swap(&arr[index], &arr[lefti]);
//    //curi实际上一直往后走的
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
//    //[lefti, keyi-1] keyi [keyi+1, righti]
//    QuickSort(arr, lefti, keyi - 1);
//    QuickSort(arr, keyi + 1, righti);
//}
//void test_5()
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

//< 6.测试6

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <assert.h>
//#include <errno.h>
//#include <stdbool.h>
////> 栈的实现
////> 1.支持动态增长的栈
//typedef int STDataType;
//typedef struct Stack
//{
//    STDataType* _a;
//    int _top;//栈顶
//    int _capacity;//容量 
//}Stack;
////> 2.初始化栈 
//void StackInit(Stack* ps)
//{
//    //1.检查指针有效性
//    assert(ps);
//
//    //2.初始化栈的信息
//    ps->_a = (STDataType*)malloc(sizeof(STDataType) * 4);//先给上4个空间，并且检查是否申请成功
//    if (!ps->_a)
//    {
//        perror("malloc fail!\n");
//        return;
//    }
//    ps->_top = 0;//这个赋值也可以是-1
//    ps->_capacity = 4;
//}
////> 3.入栈 
//void StackPush(Stack* ps, STDataType data)
//{
//    //1.检查指针有效性
//    assert(ps);
//    //2.检查栈容量是否满了
//    if (ps->_capacity == ps->_top)
//    {
//        STDataType* cache = (STDataType*)realloc(ps->_a, sizeof(STDataType) * ((ps->_capacity) * 2));
//        if (!cache)
//        {
//            printf("realloc fail!\n");
//            exit(-1);
//        }
//        ps->_a = cache;
//        ps->_capacity = ps->_capacity * 2;
//    }
//    //3.入栈并且更新栈的数据
//    ps->_a[ps->_top] = data;
//    ps->_top++;
//}
////> 4.出栈 
//void StackPop(Stack* ps)
//{
//    //1.检查指针有效性
//    assert(ps);
//    //2.检查栈是否有元素
//    assert(ps->_top > 0);
//    //3.直接利用下标“删除”元素，注意栈内存储元素的“实际下标”比“_top”的数值小1
//    ps->_top--;
//}
////> 5.获取栈顶元素 
//STDataType StackTop(Stack* ps)
//{
//    //1.检查指针的有效性
//    assert(ps);
//    //2.检查栈是否还有元素
//    assert(ps->_top > 0);
//    //3.取出栈顶元素
//    return ps->_a[ps->_top - 1];
//}
////> 6.获取栈中有效元素个数 
//int StackSize(Stack* ps)
//{
//    //1.检查指针的有效性
//    assert(ps);
//    //2.获取元素个数
//    return ps->_top;
//}
////> 7.检测栈是否为空，如果为空返回非零，如果不为空返回0 
//int StackEmpty(Stack* ps)
//{
//    assert(ps);
//    return (ps->_top == 0);
//}
////> 8.销毁栈 
//void StackDestroy(Stack* ps)
//{
//    assert(ps);
//    free(ps->_a);
//    ps->_a = NULL;
//    ps->_capacity = ps->_top = 0;
//}
//int GetMidIndex(int* arr, int lefti, int righti)
//{
//    int mid = (lefti + righti) >> 1;//取平均值
//    if (arr[lefti] < arr[mid])
//    {
//        if (arr[mid] < arr[righti])
//        {
//            return mid;
//        }
//        else if (arr[lefti] > arr[righti])
//        {
//            return lefti;
//        }
//        else
//        {
//            return righti;
//        }
//    }
//    else//arr[lefti] > arr[mid]
//    {
//        if (arr[mid] > arr[righti])
//        {
//            return mid;
//        }
//        else if (arr[lefti] < arr[righti])
//        {
//            return lefti;
//        }
//        else
//        {
//            return righti;
//        }
//    }
//}
//void _Swap(int* x, int* y)
//{
//    int tmp = *x;
//    *x = *y;
//    *y = tmp;
//}
//int _PartSort(int* arr, int lefti, int righti)
//{
//    //有了三数取中，则基本不会出现最坏情况
//    int index = GetMidIndex(arr, lefti, righti);
//    _Swap(&arr[index], &arr[lefti]);
//
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
//void QuickSortNonR(int* arr, int lefti, int righti)
//{
//    //if (lefti >= righti)//区间不存在或是区间内只有一个值
//    //{
//    //    return;
//    //}
//    //int keyi = _PartSort(arr, lefti, righti);
//    ////[lefti, keyi-1] keyi [keyi+1, righti]
//    //
//    //QuickSort(arr, lefti, keyi - 1);
//    //QuickSort(arr, keyi + 1, righti);
//    Stack s;
//    StackInit(&s);//初始化
//    StackPush(&s, righti);//压入最开始的右区间
//    StackPush(&s, lefti);//压入最开始的左区间
//    while(!StackEmpty(&s))//只要栈不为空
//    {
//        int leftj = StackTop(&s);//取得左区间
//        StackPop(&s);
//        
//        int rightj = StackTop(&s);//取得右区间
//        StackPop(&s);
//        
//        int keyj = _PartSort(arr, leftj, rightj);
//        
//        //根据[lefti, keyi-1] keyi [keyi+1, righti]
//        if (keyj + 1 < rightj)
//        {
//            StackPush(&s, rightj);//压入右区间
//            StackPush(&s, keyj + 1);
//        }
//        if (leftj < keyj - 1)
//        {
//            StackPush(&s, keyj - 1);//压入左区间
//            StackPush(&s, leftj);
//        }
//    }
//    StackDestroy(&s);
//}
//void test_6()
//{
//    srand((unsigned)time(0));
//    int arr[SIZE];
//    for (int i = 0; i < SIZE; i++)
//    {
//        arr[i] = rand() % SIZE;
//        printf("%d ", arr[i]);
//    }
//    printf("\n");
//    QuickSortNonR(arr, 0, SIZE - 1);//堆排序
//    for (int i = 0; i < SIZE; i++)
//    {
//        printf("%d ", arr[i]);
//    }
//    printf("\n");
//}

//< 7.测试7

//void _MergeSort(int* arr, int lefti, int righti, int* tmp)
//{
//    if (lefti >= righti)//其实直接写“==”也是可以的，左边这是保险做法
//    {
//        return;
//    }
//    int mid = (lefti + righti) / 2;
//    //[lefti, mid][mid+1, righti]
//    _MergeSort(arr, lefti, mid, tmp);
//    _MergeSort(arr, mid + 1, righti, tmp);
//
//    int newLefti_1 = lefti, newRighti_1 = mid;
//    int newLefti_2 = mid + 1, newRighti_2 = righti;
//
//    //下面的步骤是在做归并的动作，实际上就是对两个数组进行排序的过程，比较拷贝比较拷贝……
//    //若是有一个数组++完了就都停下，有剩余的数组内部元素一点比另外一个数组的所有元素都大
//    //然后最后全部把tmp内部元素拷贝回来
//    int i = lefti;
//    while(newLefti_1 <= newRighti_1 && newLefti_2 <= newRighti_2)
//    {
//        if (arr[newLefti_1] < arr[newLefti_2])
//        {
//            tmp[i++] = arr[newLefti_1++];
//        }
//        else
//        {
//            tmp[i++] = arr[newLefti_2++];
//        }
//    }
//    //我们无法预测谁先走完，直接上两个循环，因此下面的两个循环只会满足一个
//    while (newLefti_1 <= newRighti_1)
//    {
//        tmp[i++] = arr[newLefti_1++];
//    }
//    while (newLefti_2 <= newRighti_2)
//    {
//        tmp[i++] = arr[newLefti_2++];
//    }
//    //最后全部拷贝回来，注意在这之前arr数组从来没有变过，只是被tmp拷贝
//    memcpy(arr + lefti, tmp + lefti, sizeof(int) * (righti - lefti + 1));//注意这里最后一个参数不能使用i，因为i只是下标不是元素个数，不一定从0开始
//}
//void MergeSort(int* arr, int n)
//{
//    int* tmp = (int*)malloc(sizeof(int) * n);
//    _MergeSort(arr, 0, n - 1, tmp);
//    free(tmp);
//}
//void test_7()
//{
//    srand((unsigned)time(0));
//    int arr[SIZE];
//    for (int i = 0; i < SIZE; i++)
//    {
//        arr[i] = rand() % SIZE;
//        printf("%d ", arr[i]);
//    }
//    printf("\n");
//    MergeSort(arr, SIZE);//堆排序
//    for (int i = 0; i < SIZE; i++)
//    {
//        printf("%d ", arr[i]);
//    }
//    printf("\n");
//}

//< 8.测试8

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
void test_8()
{
    printf("%d", FirstNotRepeatingChar("lRYdsgSqrIOakFmgyrlOXPqMAdOlmyuUvlNlWjKlctBYahulmDGXEMlBLvpllLezXeOMzlVeqnYvH"));
}
int main()
{
    //test_1();
    //test_2();
    //test_3();
    //test_4();
    //test_5();
    //test_6();
    test_7();
    //test_8();
    return 0;
}