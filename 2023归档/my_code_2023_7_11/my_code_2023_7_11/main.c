#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 50
//< 1.����һ

//typedef int HPDataType;
////����ǰ��д�õ����µ����㷨��ģ��ѵ���Ѻͳ��� 
//void AdjustDown(HPDataType* arr, int arrsize, int parenti)
//{
//    int childi = parenti * 2 + 1;//�Ƚ�������������childi
//    while (childi < arrsize)//childi + 1 < arrsize����д�������Ϊ�п������Ӵ��ڵ���û���Һ��� 
//    {
//        //1.������������
//        if (childi + 1 < arrsize && arr[childi] < arr[childi + 1])
//        {
//            childi++;
//        }
//        //2.�ж��Ƿ���Ҫ����
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
//    //��Ҷ�ӽڵ㿪ʼ���ŵ������Գ�һ���ѣ������Դӵ�һ����Ҷ�ӽڵ㿪ʼ����
//    //1.�������µ���������
//    for (int i = ((arrsize - 1) - 1) / 2; i >= 0; i--)
//    {
//        AdjustDown(arr, arrsize, i);
//    }
//    //2.�������µ�����������
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
//    HeapSort_3(arr, sizeof(arr) / sizeof(int));//������
//    for (int i = 0; i < 7; i++)
//    {
//        printf("%d ", arr[i]);
//    }
//    printf("\n");
//}

//< 2.����2

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
//        while (lefti < righti && arr[righti] >= arr[keyi])//��key�������ν����һ������
//        {
//            righti--;
//        }
//        while (lefti < righti && arr[lefti] <= arr[keyi])//��key�������ν����һ������
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
//    if (lefti >= righti)//���䲻���ڻ���������ֻ��һ��ֵ
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
//    Hoare_QuickSort(arr, 0, SIZE - 1);//������
//    for (int i = 0; i < SIZE; i++)
//    {
//        printf("%d ", arr[i]);
//    }
//    printf("\n");
//}

//< 3.����3

//�ڿӷ�
//void _Swap(int* x, int* y)
//{
//    int tmp = *x;
//    *x = *y;
//    *y = tmp;
//}
//int _PartSort(int* arr, int lefti, int righti)
//{
//    int key = arr[lefti];
//    int holei = lefti;//�ӵ�����
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
//    if (lefti >= righti)//���䲻���ڻ���������ֻ��һ��ֵ
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
//    Pitfall_QuickSort(arr, 0, SIZE - 1);//������
//    for (int i = 0; i < SIZE; i++)
//    {
//        printf("%d ", arr[i]);
//    }
//    printf("\n");
//}

//< 4.����4

//void _Swap(int* x, int* y)
//{
//    int tmp = *x;
//    *x = *y;
//    *y = tmp;
//}
//int _PartSort(int* arr, int lefti, int righti)
//{
//    //������������ʹ������ȡ�з����Ż����������key�����������������ֵ������O(n)�˻�Ϊn^2
//    curiʵ����һֱ�����ߵ�
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
//    if (lefti >= righti)//���䲻���ڻ���������ֻ��һ��ֵ
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
//    QuickSort(arr, 0, SIZE - 1);//������
//    for (int i = 0; i < SIZE; i++)
//    {
//        printf("%d ", arr[i]);
//    }
//    printf("\n");
//}

//< 5.����5

/*
������
��һ����Ϊ�ַ������ҵ���һ��ֻ����һ�ε��ַ�,
����������λ��,���û���򷵻�-1����Ҫ���ִ�Сд)����0��ʼ������
���ݷ�Χ��0��n��10000,���ַ���ֻ����ĸ��ɡ�

Ҫ��
�ռ临�Ӷ�O(n)
ʱ�临�Ӷ�O(n)
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