#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
typedef struct List_t
{
	struct List_t* next;//4或8
	struct List_t* prev;//4或8
	char data[0];//空
}list_t;
void test_1()
{
	printf("%zd", sizeof(list_t));
}

void fut(int** s, int p[2][3])
{
	**s = p[1][1];
}
void test_2()
{
	int a[2][3] = { 1,3,5,7,9,11 };
	int* p;

	p = (int*)malloc(sizeof(int));//申请可以存放一个int的空间
	fut(&p, a);
	printf("%d", *p);
}

void test_3()
{
	int n;
	FILE* pFile;
	char buffer[27];

	pFile = fopen("myfile.txt", "w+");

	for (n = 'A'; n <= 'Z'; n++)
	{
		fputc(n, pFile);
	}

	rewind(pFile);

	fread(buffer, 1, 26, pFile);
	fclose(pFile);
	buffer[26] = '\0';
	puts(buffer);
}

void fun(char* fname, char* st)
{
	FILE* myf;
	int i;
	myf = fopen(fname, "w");
	for (i = 0; i < strlen(st); i++)
	{
		fputc(st[i], myf);
	}
	fclose(myf);
} 
void test_4()
{
	fun("test.txt", "new world");
	fun("test.txt", "hello,");
}

void test_5()
{
	FILE* fs = fopen("test.txt", "w+");
	int a = fputc('c', fs);
	printf("%c", a);
}

#define Mul(x,y) ++x*++y
void test_6()
{
	int a = 1;
	int b = 2;
	int c = 3;
	printf("%d", Mul(a + b, b + c));
	//++a + b * ++b + c
	//2 + b
}

#define a 10//宏替换不是发生在运行阶段的
void foo();
void test_7()
{
	printf("%d..", a);//10..
	foo();
	printf("%d", a);//10
}
void foo()
{
#undef a
#define a 50
}

void test_8(int N)//n
{
	int count = 0;
	for (int k = 0; k < 2 * N * N; ++k)//执行2n^2次
	{
		++count;
	} 
	int M = 10;
	while (M--)//执行10次
	{
		++count;
	}
	printf("%d\n", count);
	//时间复杂度O(n) = n^2
}

void test_9()
{
	int i = 1;
	while (i++)//存在序列点
	{
		printf("i=%d\n", i);
		break;
	}
	int j = 1;
	while (++j)//存在序列点
	{
		printf("j=%d\n", j);
		break;
	}
}

int main()
{
	//test_1();
	//test_2();
	//test_3();
	//test_4();
	//test_5();
	//test_7();
	//test_8(10);
	test_9(10);
	return 0;
}