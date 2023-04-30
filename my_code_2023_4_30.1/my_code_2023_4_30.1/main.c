#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef union Un
{
	int i;
	char j;
}Un;
int main()
{
	Un a;
	a.i = 1;
	printf("%d", a.j);
}

typedef struct str
{
	int data;
	int* arr;
	//int arr[];
}str;
int main()
{
	str* p = (str*)malloc(sizeof(str));
	if (!p) exit(-1);
	p->arr = (int*)malloc(sizeof(int) * 10);
	if (!(p->arr)) exit(-1);
	p->data = 0;

	for (int i = 0; i < 10; i++)
	{
		p->arr[i] = i * i;
	}
	printf("p->data == %d\n", p->data);
	for (int j = 0; j < 10; j++)
	{
		printf("%d ", p->arr[j]);
	}

	free(p->arr);
	free(p);
	p = NULL;
	return 0;
}

struct Datas; 
int main() 
{
	struct Datas a;
	sizeof("%zd", a);
	return 0; 
}