#include "function.h"

//1.ֱ�Ӳ����������
void test_1(void)
{
	printf("ֱ�Ӳ�������\n");

	int* arr = calloc(SIZE, sizeof(int));
	if (arr == NULL) exit(-1);
	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = rand() % SCOPE;
		//printf("%d ", arr[i]);
	}
	//printf("\n");

	clock_t start, end;
	start = clock();
	InsertSort(arr, SIZE);
	//for (int i = 0; i < SIZE; i++)
	//{
	//	printf("%d ", arr[i]);
	//}
	end = clock();
	double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	printf("%lf\n\n", cpu_time_used);

	free(arr);
	arr = NULL;
}
//2.ϣ���������
void test_2(void)
{
	printf("ϣ������\n");

	int* arr = calloc(SIZE, sizeof(int));
	if (arr == NULL) exit(-1);
	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = rand() % SCOPE;
		//printf("%d ", arr[i]);
	}
	//printf("\n");

	clock_t start, end;
	start = clock();
	ShellSort(arr, SIZE);
	//for (int i = 0; i < SIZE; i++)
	//{
	//	printf("%d ", arr[i]);
	//}
	end = clock();
	double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	printf("%lf\n\n", cpu_time_used);

	free(arr);
	arr = NULL;
}
//3.ֱ��ѡ���������
void test_3(void)
{
	printf("ֱ��ѡ������\n");

	int* arr = calloc(SIZE, sizeof(int));
	if (arr == NULL) exit(-1);
	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = rand() % SCOPE;
		//printf("%d ", arr[i]);
	}
	//printf("\n");

	clock_t start, end;
	start = clock();
	SelectSort(arr, SIZE);
	//for (int i = 0; i < SIZE; i++)
	//{
	//	printf("%d ", arr[i]);
	//}
	end = clock();
	double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	printf("%lf\n\n", cpu_time_used);

	free(arr);
	arr = NULL;
}
//4.���������
void test_4(void)
{
	printf("������\n");

	int* arr = calloc(SIZE, sizeof(int));
	if (arr == NULL) exit(-1);
	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = rand() % SCOPE;
		//printf("%d ", arr[i]);
	}

	clock_t start, end;
	start = clock();
	//printf("\n");
	HeapSort(arr, SIZE);
	//for (int i = 0; i < SIZE; i++)
	//{
	//	printf("%d ", arr[i]);
	//}
	end = clock();
	double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	printf("%lf\n\n", cpu_time_used);

	free(arr);
	arr = NULL;
}
//5.ð���������
void test_5(void)
{
	printf("ð������\n");
	
	int* arr = calloc(SIZE, sizeof(int));
	if (arr == NULL) exit(-1);
	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = rand() % SCOPE;
		//printf("%d ", arr[i]);
	}

	clock_t start, end;
	start = clock();
	//printf("\n");
	BubbleSort(arr, SIZE);
	//for (int i = 0; i < SIZE; i++)
	//{
	//	printf("%d ", arr[i]);
	//}
	end = clock();
	double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	printf("%lf\n\n", cpu_time_used);

	free(arr);
	arr = NULL;
}
//6.1.����������ԣ��ݹ飩
void test_6_1(void)
{
	printf("�������򣨵ݹ飩\n");

	int* arr = calloc(SIZE, sizeof(int));
	if (arr == NULL) exit(-1);
	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = rand() % SCOPE;
		//printf("%d ", arr[i]);
	}

	clock_t start, end;
	double cpu_time_used;

	start = clock();
	QuickSort(arr, 0, SIZE-1);
	end = clock();
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	printf("%lf\n\n", cpu_time_used);

	//printf("\n");
	//for (int i = 0; i < SIZE; i++)
	//{
	//	printf("%d ", arr[i]);
	//}

	//start = clock();
	//QuickSort(arr, 0, SIZE - 1);//�����Ѿ�������ģ���������ȡ�з�������
	//end = clock();
	//cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	//printf("�����ٴ�������������ģ�%lf\n\n", cpu_time_used);

	free(arr);
	arr = NULL;
}
//6.2.����������ԣ��ǵݹ飩
void test_6_2(void)
{
	printf("�������򣨷ǵݹ飩\n");

	int* arr = calloc(SIZE, sizeof(int));
	if (arr == NULL) exit(-1);
	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = rand() % SCOPE;
		//printf("%d ", arr[i]);
	}

	clock_t start, end;
	start = clock();
	//printf("\n");
	QuickSortNonR(arr, SIZE);
	end = clock();
	double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	printf("%lf\n\n", cpu_time_used);

	//for (int i = 0; i < SIZE; i++)
	//{
	//	printf("%d ", arr[i]);
	//}

	free(arr);
	arr = NULL;
}
//7.1.�鲢������ԣ��ݹ飩
void test_7_1(void)
{
	printf("�鲢����\n");

	int* arr = calloc(SIZE, sizeof(int));
	if (arr == NULL) exit(-1);
	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = rand() % SCOPE;
		//printf("%d ", arr[i]);
	}

	clock_t start, end;
	start = clock();
	//printf("\n");
	MergeSort(arr, SIZE);
	end = clock();
	double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	printf("%lf\n\n", cpu_time_used);

	//for (int i = 0; i < SIZE; i++)
	//{
	//	printf("%d ", arr[i]);
	//}

	free(arr);
	arr = NULL;
}
//7.2.1.�鲢������ԣ��ǵݹ飩
void test_7_2_1(void)
{
	printf("�鲢���򣨷ǵݹ飩\n");

	int* arr = calloc(SIZE, sizeof(int));
	if (arr == NULL) exit(-1);
	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = rand() % SCOPE;
		//printf("%d ", arr[i]);
	}

	clock_t start, end;
	start = clock();
	//printf("\n");
	MergeSortNonR(arr, SIZE);
	end = clock();
	double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	printf("%lf\n\n", cpu_time_used);

	//for (int i = 0; i < SIZE; i++)
	//{
	//	printf("%d ", arr[i]);
	//}

	free(arr);
	arr = NULL;
}
//7.2.2.�鲢������ԣ��ǵݹ�chatGPT�汾��
void test_7_2_2(void)
{
	printf("�鲢���򣨷ǵݹ飩\n");

	int* arr = calloc(SIZE, sizeof(int));
	if (arr == NULL) exit(-1);
	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = rand() % SCOPE;
		//printf("%d ", arr[i]);
	}

	clock_t start, end;
	start = clock();
	//printf("\n");
	MergeSortNonR_chat_GTP(arr, SIZE);
	end = clock();
	double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	printf("%lf\n\n", cpu_time_used);

	//for (int i = 0; i < SIZE; i++)
	//{
	//	printf("%d ", arr[i]);
	//}

	free(arr);
	arr = NULL;
}
//8.�����������
void test_8(void)
{
	printf("��������\n");

	int* arr = calloc(SIZE, sizeof(int));
	if (arr == NULL) exit(-1);
	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = rand() % SCOPE;
		//printf("%d ", arr[i]);
	}

	clock_t start, end;
	start = clock();
	//printf("\n");
	CountSort(arr, SIZE);
	end = clock();
	double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	printf("%lf\n\n", cpu_time_used);

	//for (int i = 0; i < SIZE; i++)
	//{
	//	printf("%d ", arr[i]);
	//}

	free(arr);
	arr = NULL;
}


int main()
{
	srand((unsigned)time(NULL));
	test_1();
	test_2();
	test_3();
	test_4();
	test_5();
	test_6_1();
	test_6_2();
	test_7_1();
	test_7_2_1();
	test_7_2_2();
	test_8();
	return 0;
}