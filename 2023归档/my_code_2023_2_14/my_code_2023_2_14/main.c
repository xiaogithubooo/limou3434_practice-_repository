#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//1、存储类别的实验
//2、rand函数的模拟
//3、命令行函数测试
//4、部分作业代码测试
//①调整数组使奇数全部都位于偶数前面
//②模拟实现两个库函数strlen和strcpy函数
//5、数据存储的测试
//6、检验char取值测试


//1、存储类别的实验
int main()
{
	int i = 30;
	while (i++ < 33)
	{
		int i = 100;
		printf("%d ", i);
	}
	return 0;
}
int main()
{
	register int number = 100;
	int* p = &number;
	printf("%p", p);
	return 0;
}
//2、rand函数的模拟
static unsigned long int next = 1;//种子
unsigned int rand0(void)
{
	next = next * 1103515245 + 12345;
	return (unsigned int)(next / 65536) % 32768;
}
int main()
{
	printf("%d\n", rand0());
	printf("%d\n", rand0());
	printf("%d\n", rand0());
	printf("%d\n", rand0());
	printf("%d\n", rand0());
	printf("%d\n", rand0());
	printf("%d\n", rand0());
	return 0;
}
//3、命令行函数测试
#include<stdlib.h>
int main(int argc, char *argv[])
{
	int ch;
	FILE* fp;
	unsigned long count = 0;
	if (argc != 2)
	{
		printf("Usage: %s filename\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if ((fp = fopen(argv[1], "r")) == NULL)
	{
		printf("Can't open %s\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	while ((ch = getc(fp)) != EOF)
	{
		putc(ch, stdout);
		count++;
	}
	fclose(fp);
	printf("File %s has %lu characters\n", argv[1], count);

	return 0;
}
//4、部分作业代码测试
//①调整数组使奇数全部都位于偶数前面
void function(int* arr, int*arrx, int number)
{
	int i = 0, j = number - 1;

	for (int x = 0; x < number; x++)
	{
		if (arr[x] % 2 == 1)//奇数
		{
			arrx[i] = arr[x];
			i++;
		}
		else
		{
			arrx[j] = arr[x];
			j--;
		}
	}
}
int main()
{
	int arr[100] = { 0 };
	int arrx[100] = { 0 };
	int number = 0;
	scanf("%d", &number);
	for (int i = 0; i < number; i++)
	{
		scanf("%d", &arr[i]);
	}
	function(arr, arrx, number);
	for (int i = 0; i < number; i++)
	{
		printf("%d ", arrx[i]);
	}
	return 0;
}
//②模拟实现两个库函数strlen和strcpy函数
#include <stdio.h>
#include <assert.h>
int my_strlen(const char* str)
{
	int count = 0;
	assert(str);//assert(str != NULL);//断言的使用
	while(*str)//while (*str != '\0')
	{
		count++;
		str++;
	}
	return count;
}
int main()
{
	int len = my_strlen("abcdef");
	printf("%d\n", len);
	return 0;
}
void my_strcpy(char* dest, char* src)
{
    //断言，或者改成assert(dest && src)
    assert(dest != NULL);
    assert(src != NULL);
    while (*dest++ = *src++)
    {
        ;
    }
}
int main()
{
    char arr1[100] = "abcdefn";
    char arr2[100] = { 0 };
    my_strcpy(arr2, arr1);
    printf("%s", arr2);
    return 0;
}
//5、数据存储的测试
int main()
{
	int a = 100;
	return 0;
}检验大小端
int check_sys(void)
{
	int i = 1;
	return (*((char*)&i));
}
int check_sys_x()
{
	union
	{
		int i;
		char c;
	}un;
	un.i = 1;
	return un.c;
}
int main()
{
	//int ret = check_sys();
	int ret = check_sys_x();
	if (ret == 1)
	{
		printf("小端\n");
	}
	else
	{
		printf("大端\n");
	}
	return 0;
}
int main()
{
	unsigned char c = -1;
	printf("%d", c);
	return 0;
}
//6、检验char取值
#include <stdio.h>
int main()
{
    char a = -128;
    printf("%u\n", a);
    return 0;
}
#include <stdio.h>
int main()
{
    char a = 128;
    printf("%u\n", a);
    return 0;
}