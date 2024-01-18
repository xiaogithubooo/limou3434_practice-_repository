#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100000
#define SCOPE 100000

//1.≤Â»Î≈≈–Ú
//1.1.÷±Ω”≤Â»Î≈≈–Ú
void InsertSort(int* a, int n);
//1.2.œ£∂˚≈≈–Ú
void ShellSort(int* a, int n);

//2.—°‘Ò≈≈–Ú
//2.1.÷±Ω”—°‘Ò≈≈–Ú
void SelectSort(int* a, int n);
//2.2.∂—≈≈–Ú
void HeapSort(int* a, int n);

//3.Ωªªª≈≈–Ú
//3.1.√∞≈›≈≈–Ú
void BubbleSort(int* a, int n);
//3.2.øÏÀŸ≈≈–Ú
void QuickSort(int* a, int left_begin, int right_end);

//4.πÈ≤¢≈≈–Ú
//4.1.πÈ≤¢≈≈–Ú
void MergeSort(int* a, int n);