#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

//int GetMidIndex(int* arr, int lefti, int righti)
//{
//    int mid = (lefti + righti) >> 1;//ȡƽ��ֵ
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
//    //curiʵ����һֱ�����ߵ�
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
//    QuickSort(arr, 0, SIZE - 1);//������
//    for (int i = 0; i < SIZE; i++)
//    {
//        printf("%d ", arr[i]);
//    }
//    printf("\n");
//}

//< 6.����6

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <assert.h>
//#include <errno.h>
//#include <stdbool.h>
////> ջ��ʵ��
////> 1.֧�ֶ�̬������ջ
//typedef int STDataType;
//typedef struct Stack
//{
//    STDataType* _a;
//    int _top;//ջ��
//    int _capacity;//���� 
//}Stack;
////> 2.��ʼ��ջ 
//void StackInit(Stack* ps)
//{
//    //1.���ָ����Ч��
//    assert(ps);
//
//    //2.��ʼ��ջ����Ϣ
//    ps->_a = (STDataType*)malloc(sizeof(STDataType) * 4);//�ȸ���4���ռ䣬���Ҽ���Ƿ�����ɹ�
//    if (!ps->_a)
//    {
//        perror("malloc fail!\n");
//        return;
//    }
//    ps->_top = 0;//�����ֵҲ������-1
//    ps->_capacity = 4;
//}
////> 3.��ջ 
//void StackPush(Stack* ps, STDataType data)
//{
//    //1.���ָ����Ч��
//    assert(ps);
//    //2.���ջ�����Ƿ�����
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
//    //3.��ջ���Ҹ���ջ������
//    ps->_a[ps->_top] = data;
//    ps->_top++;
//}
////> 4.��ջ 
//void StackPop(Stack* ps)
//{
//    //1.���ָ����Ч��
//    assert(ps);
//    //2.���ջ�Ƿ���Ԫ��
//    assert(ps->_top > 0);
//    //3.ֱ�������±ꡰɾ����Ԫ�أ�ע��ջ�ڴ洢Ԫ�صġ�ʵ���±ꡱ�ȡ�_top������ֵС1
//    ps->_top--;
//}
////> 5.��ȡջ��Ԫ�� 
//STDataType StackTop(Stack* ps)
//{
//    //1.���ָ�����Ч��
//    assert(ps);
//    //2.���ջ�Ƿ���Ԫ��
//    assert(ps->_top > 0);
//    //3.ȡ��ջ��Ԫ��
//    return ps->_a[ps->_top - 1];
//}
////> 6.��ȡջ����ЧԪ�ظ��� 
//int StackSize(Stack* ps)
//{
//    //1.���ָ�����Ч��
//    assert(ps);
//    //2.��ȡԪ�ظ���
//    return ps->_top;
//}
////> 7.���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط��㣬�����Ϊ�շ���0 
//int StackEmpty(Stack* ps)
//{
//    assert(ps);
//    return (ps->_top == 0);
//}
////> 8.����ջ 
//void StackDestroy(Stack* ps)
//{
//    assert(ps);
//    free(ps->_a);
//    ps->_a = NULL;
//    ps->_capacity = ps->_top = 0;
//}
//int GetMidIndex(int* arr, int lefti, int righti)
//{
//    int mid = (lefti + righti) >> 1;//ȡƽ��ֵ
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
//    //��������ȡ�У�����������������
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
//    //if (lefti >= righti)//���䲻���ڻ���������ֻ��һ��ֵ
//    //{
//    //    return;
//    //}
//    //int keyi = _PartSort(arr, lefti, righti);
//    ////[lefti, keyi-1] keyi [keyi+1, righti]
//    //
//    //QuickSort(arr, lefti, keyi - 1);
//    //QuickSort(arr, keyi + 1, righti);
//    Stack s;
//    StackInit(&s);//��ʼ��
//    StackPush(&s, righti);//ѹ���ʼ��������
//    StackPush(&s, lefti);//ѹ���ʼ��������
//    while(!StackEmpty(&s))//ֻҪջ��Ϊ��
//    {
//        int leftj = StackTop(&s);//ȡ��������
//        StackPop(&s);
//        
//        int rightj = StackTop(&s);//ȡ��������
//        StackPop(&s);
//        
//        int keyj = _PartSort(arr, leftj, rightj);
//        
//        //����[lefti, keyi-1] keyi [keyi+1, righti]
//        if (keyj + 1 < rightj)
//        {
//            StackPush(&s, rightj);//ѹ��������
//            StackPush(&s, keyj + 1);
//        }
//        if (leftj < keyj - 1)
//        {
//            StackPush(&s, keyj - 1);//ѹ��������
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
//    QuickSortNonR(arr, 0, SIZE - 1);//������
//    for (int i = 0; i < SIZE; i++)
//    {
//        printf("%d ", arr[i]);
//    }
//    printf("\n");
//}

//< 7.����7

//void _MergeSort(int* arr, int lefti, int righti, int* tmp)
//{
//    if (lefti >= righti)//��ʵֱ��д��==��Ҳ�ǿ��Եģ�������Ǳ�������
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
//    //����Ĳ����������鲢�Ķ�����ʵ���Ͼ��Ƕ����������������Ĺ��̣��ȽϿ����ȽϿ�������
//    //������һ������++���˾Ͷ�ͣ�£���ʣ��������ڲ�Ԫ��һ�������һ�����������Ԫ�ض���
//    //Ȼ�����ȫ����tmp�ڲ�Ԫ�ؿ�������
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
//    //�����޷�Ԥ��˭�����ֱ꣬��������ѭ����������������ѭ��ֻ������һ��
//    while (newLefti_1 <= newRighti_1)
//    {
//        tmp[i++] = arr[newLefti_1++];
//    }
//    while (newLefti_2 <= newRighti_2)
//    {
//        tmp[i++] = arr[newLefti_2++];
//    }
//    //���ȫ������������ע������֮ǰarr�������û�б����ֻ�Ǳ�tmp����
//    memcpy(arr + lefti, tmp + lefti, sizeof(int) * (righti - lefti + 1));//ע���������һ����������ʹ��i����Ϊiֻ���±겻��Ԫ�ظ�������һ����0��ʼ
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
//    MergeSort(arr, SIZE);//������
//    for (int i = 0; i < SIZE; i++)
//    {
//        printf("%d ", arr[i]);
//    }
//    printf("\n");
//}

//< 8.����8

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