#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//ע������������ݸ�̫��ͻᵼ��ջ���������ֱ��ͣ�£�û����������
#define SIZE (100000)//����ĸ���
#define SCOPE (100000)//����ķ�ΧΪ[0,SCOPE)

//# 1.��������
//> 1.1.ֱ�Ӳ�������
void InsertSort(int* a, int n);
//> 1.2.ϣ������
void ShellSort(int* a, int n);

//# 2.ѡ������
//> 2.1.ֱ��ѡ������
void SelectSort(int* a, int n);
//> 2.2.������
void HeapSort(int* a, int n);

//# 3.��������
//> 3.1.ð������
void BubbleSort(int* a, int n);
//> 3.2.�������򣨵ݹ飩
void QuickSort(int* a, int left_begin, int right_end);
//> 3.3.�������򣨷ǵݹ飩
void QuickSortNonR(int* a, int n);

//# 4.�鲢����
//> 4.1.�鲢���򣨵ݹ飩
void MergeSort(int* a, int n);
//> 4.2.1.�鲢���򣨷ǵݹ飩
void MergeSortNonR(int* a, int n);
//> 4.2.2.�鲢���򣨷ǵݹ�chatGPT�汾��
void MergeSortNonR_chat_GTP(int* a, int n);
