#include "function.h"

//1.÷±Ω”≤Â»Î≈≈–Ú≤‚ ‘
void test_1(void)
{
	printf("÷±Ω”≤Â»Î≈≈–Ú\n");

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
	printf("\n%lf\n\n", cpu_time_used);

	free(arr);
	arr = NULL;
}
//2.œ£∂˚≈≈–Ú≤‚ ‘
void test_2(void)
{
	printf("œ£∂˚≈≈–Ú\n");

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
	printf("\n%lf\n\n", cpu_time_used);

	free(arr);
	arr = NULL;
}
//3.÷±Ω”—°‘Ò≈≈–Ú≤‚ ‘
void test_3(void)
{
	printf("÷±Ω”—°‘Ò≈≈–Ú\n");

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
	printf("\n%lf\n\n", cpu_time_used);

	free(arr);
	arr = NULL;
}
//4°¢∂—≈≈–Ú≤‚ ‘
void test_4(void)
{
	printf("∂—≈≈–Ú\n");

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
	printf("\n%lf\n\n", cpu_time_used);

	free(arr);
	arr = NULL;
}
//5°¢√∞≈›≈≈–Ú≤‚ ‘
void test_5(void)
{
	printf("√∞≈›≈≈–Ú\n");
	
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
	printf("\n%lf\n\n", cpu_time_used);

	free(arr);
	arr = NULL;
}
//6°¢øÏÀŸ≈≈–Ú≤‚ ‘
void test_6(void)
{
	printf("øÏÀŸ≈≈–Ú\n");

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
	QuickSort(arr, 0, SIZE-1);
	//for (int i = 0; i < SIZE; i++)
	//{
	//	printf("%d ", arr[i]);
	//}
	end = clock();
	double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	printf("\n%lf\n\n", cpu_time_used);

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
	test_6();
	return 0;
}