#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100000
#define SCOPE 100000

//1.��������
//1.1.ֱ�Ӳ�������
void InsertSort(int* a, int n);
//1.2.ϣ������
void ShellSort(int* a, int n);

//2.ѡ������
//2.1.ֱ��ѡ������
void SelectSort(int* a, int n);
//2.2.������
void HeapSort(int* a, int n);

//3.��������
//3.1.ð������
void BubbleSort(int* a, int n);
//3.2.��������
void QuickSort(int* a, int left_begin, int right_end);

//4.�鲢����
//4.1.�鲢����
void MergeSort(int* a, int n);