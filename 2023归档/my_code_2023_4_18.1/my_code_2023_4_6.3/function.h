#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
//注意这里如果数据给太大就会导致栈溢出，程序直接停下，没法继续运行
#define SIZE 10000//排序的个数
#define SCOPE 10000//排序的范围为[0,SCOPE)

//# 1.插入排序
//> 1.1.直接插入排序
void InsertSort(int* a, int n);
//> 1.2.希尔排序
void ShellSort(int* a, int n);

//# 2.选择排序
//> 2.1.直接选择排序
void SelectSort(int* a, int n);
//> 2.2.堆排序
void HeapSort(int* a, int n);

//# 3.交换排序
//> 3.1.冒泡排序
void BubbleSort(int* a, int n);
//> 3.2.快速排序（递归）
void QuickSort(int* a, int left_begin, int right_end);
//> 3.3.快速排序（非递归）
void QuickSortNonR(int* a, int n);

//# 4.归并排序
//> 4.1.归并排序（递归）
void MergeSort(int* a, int n);
//> 4.2.1.归并排序（非递归）
void MergeSortNonR(int* a, int n);
//> 4.2.2.归并排序（非递归chatGPT版本）
void MergeSortNonR_chat_GTP(int* a, int n);

//# 5.计数排序（非比较排序）
void CountSort(int* a, int n);

//# 6.基数排序（桶排序）
//之后写，这个排序的实际应用价值不大
