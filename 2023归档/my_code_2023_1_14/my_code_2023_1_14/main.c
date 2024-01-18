#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//1、多重赋值
int main()
{
	int a, b, c;
	a = b = c = 23;//?!真的可以!?
	printf("%d %d %d\n", a, b, c);
	return 0;
}
//2、sizeof的用法
int main()
{
	//sizeof的标准写法
	size_t d = sizeof(int);
	printf("%zd", d);

	return 0;
}
//3、const的使用
int main()
{
	int a = 248, b = 4;
	int const* c = 21;
	const int* d = &a;
	int* const e = &b;
	int const* const f = &a;
	
	//*c = 32;
	//*d = 43;
	//e = &a;
	//f = 0x321f;
	return 0;
}
//4、打印函数检验
#include <stdio.h>
int i;
void prt()
{
	for (i = 5; i < 8; i++)
		printf("%c", '*');
	printf("\t");
}
int main()
{
	for (i = 5; i <= 8; i++)
		prt();
	return 0;
}
int main()
{
	int a = 3;
	printf("%d\n", (a += a -= a * a));
	return 0;
}
#include <stdio.h>
int main()
{
    int arr[3][4];
    int i = 0;
    for (i = 0; i < 3; i++)
    {
        int j = 0;
        for (j = 0; j < 4; j++)
        {
            printf("&arr[%d][%d] = %p\n", i, j, &arr[i][j]);
        }
    }
    return 0;
}
int main()
{
	int arr[3] = { 1,2,3 };
	arr[4];
}
//5、作业题目
int main()
{
	int n = 0;
	scanf("%d", &n);

	int num = 0;
	int i = 0;//统计负数个数
	int Add = 0;//合上所有正数
	for (int a = 0; a < n; a++)
	{
		scanf("%d", &num);
		if (num < 0)
		{
			i++;
		}
		if (num > 0)
		{
			Add += num;
		}
	}
	printf("%d %d",num)？？？？
	return 0;
}
//6、错误的冒泡排序
void function(int arr[])//两两相邻元素比较，n个数需要重复n-1次冒泡排序
{
    int i = 0;
    int sz = sizeof(arr) / sizeof(arr[0]);//确定使用冒泡排序的次数
    for (i = 0; i < sz - 1; i++)//循环使用冒泡排序
        {
            int j = 0;
            for (j = 0; j < sz - i - 1; j++)//一次冒号排序，每次排序后就不用排最后一个数字了，所以-i
            {
                if (arr[j] > arr[j + 1])
                {
                    int num = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = num;
                }
            }
        }
}
int main()
{
    int arr[] = { 3, 4, 1, 6, 8, 9, 6, 8, 9, 7, 0 };
    //排序为升序
    function(arr);
    int i = 0;
    for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        printf("%d", arr[i]);
    }
    return 0;
}
//7、正确的冒泡排序
//两两相邻元素比较，n个数需要重复n-1次冒泡排序
void function(int* arr, int sz)//前者为首元素地址，后者是数组的个数
{
    int i = 0;
    for (i = 0; i < sz - 1; i++)//循环使用冒泡排序
    {
        int j = 0;
        for (j = 0; j < sz - i - 1; j++)//一次冒号排序，每次排序后就不用排最后一个数字了，所以-i
        {
            if (arr[j] > arr[j + 1])
            {
                int num = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = num;
            }
        }
    }
}
int main()
{
    int arr[] = { 3, 4, 1, 6, 8, 9, 6, 8, 9, 7, 0 };
    //排序为升序
    int sz = sizeof(arr) / sizeof(arr[0]);
    function(arr, sz);
    int i = 0;
    for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}