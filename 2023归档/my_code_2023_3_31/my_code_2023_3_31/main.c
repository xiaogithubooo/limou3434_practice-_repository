#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <errno.h>
int main()
{
	//打开文件
	FILE* fpRead= fopen("limou_test.txt", "r");
	if (fpRead == NULL)
	{
		perror("fopen_fpRead_错误");
		return 1;
	}
	FILE* fpWrite = fopen("limou_test_copy.txt", "w");
	if (fpWrite == NULL)
	{
		fclose(fpRead);//如果第二份文件不能正常启动，那最好将第一份文件也关上
		fpRead = NULL;
		perror("fopen_fpWrite_错误");
		return 1;
	}
	//拷贝文件
	int ch = 0;
	while ((ch = fgetc(fpRead)) != EOF)
	{
		fputc(ch, fpWrite);
	}
	if (feof(fpRead))
	{
		printf("遇到文件末尾了！\n");
	}
	else if (ferror(fpWrite))
	{
		printf("遇到读取错误问题！\n");
	}
	printf("拷贝成功\n");
	//关闭文件
	fclose(fpRead);
	fclose(fpWrite);
	fpRead = NULL;
	fpWrite = NULL;
	return 0;
}

#define NUM 10
#include <stdio.h>
int main()
{
	int arr[NUM] = { 2,2,4,4,1,1,6,6,5,7 };
	for (int i = 0; i < NUM - 1; i++)
	{
		for (int j = 0; j < NUM - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < NUM; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}

#define NUM 10
#include <stdio.h>
int main()
{
	int arr[NUM] = { 2,2,4,4,1,1,6,6,5,7 };
	int a = 0;
	for (int i = 0; i < NUM; i++)
	{
		 a^= arr[i];//求出所有元素的异或
	}
	//进行分组
	int k = 1;
	int t = 0;
	while (a)
	{
		if (a & k == 1)
		{
			break;
		}
		else
		{
			a >>= 1;
			t++;
		}
	}
	int arr1 = 0;
	int arr2 = 0;
	for (int i = 0; i < NUM; i++)
	{
		if (k & (arr[i] >> t) == 1)
		{
			arr1 ^= arr[i];
		}
		else
		{
			arr2 ^= arr[i];
		}
	}
	printf("找到啦，单身狗是：%d %d\n", arr1, arr2);
	return 0;
}

#define NUM 10
#include <stdio.h>
void function(int arr[], int num)
{
	1、把所有的地方都异或在一起
	int ret = 0;
	int i = 0;//循环数
	for (i = 0; i < num; i++)
	{
		ret ^= arr[i];
	}
	2、计算是哪一位是1（分组依据）
	int pos = 0;
	for (i = 0; i < 32; i++)
	{
		if (((ret >> i) & 1) == 1)
		{
			pos = i;
			break;
		}
	}
	3、分组异或
	int x1 = 0, x2 = 0;
	for (i = 0; i < num; i++)
	{
		if (((arr[i] >> pos) & 1) == 1)
		{
			x1 ^= arr[i];
		}
		else
		{
			x2 ^= arr[i];
		}
	}
	printf("%d %d", x1, x2);
}
int main()
{
	int arr[NUM] = { 2,2,4,4,1,1,6,6,5,7 };
	function(arr, NUM);
	return 0;
}