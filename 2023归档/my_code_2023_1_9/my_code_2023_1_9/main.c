#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <windows.h>
//1、阶乘递归的复习
int function(int i)
{
	if (i == 1)
	{
		return 1;
	}
	else
	{
		return i * function(i - 1);
	}
}
int main()
{
	int i = 0;
	while(scanf("%d", &i) == 1)
	{
		printf("%d\n", function(i));
	}
	return 0;
}
//2、二分查找法
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	//下标        0,1,2,3,[4],5,6,7,8,9
	int i = 0;
	int k = 0;
	scanf("%d", &k);
	int sz = sizeof(arr) / sizeof(arr[0]);//计算数组的大小
	int left = 0;//左下标
	int right = sz - 1;//右下标
	int flag = 0;
	int mid = 0;
	while (left<=right)
	{
		//mid = (left + right) / 2;//中间下标（但是有点小问题，加起来容易溢出）
		mid = left + (right - left) / 2;//中间下标（这样求平均值才是最好的！）
		if (arr[mid] < k)
		{
			left = mid + 1;
		}
		else if (arr[mid] > k)
		{
			right = mid - 1;
		}
		else
		{
			printf("找到了，下标是%d", mid);
			flag = 1;
			break;
		}
	}
	if (0 == flag)
	{
		printf("没有找到\n");
	}
	return 0;
}
//3、两端移动到中间文字
//******************变成下面这串字符串
//welcome to python!
int main()
{
	char arr1[] = "welcome to python!";
	char arr2[] = "******************";

	int sz = strlen(arr1) - 1;
	int left = 0;
	int right = sz;

	while (left <= right)
	{
		arr2[left] = arr1[left];
		arr2[right] = arr1[right];
		printf("%s", arr2);
		Sleep(500);
		system("cls");//cmd命令的使用
		left++;
		right--;
	}
	printf("%s", arr2);
	return 0;
}
//4、goto的使用
int main()
{
	goto a;
	printf("haha\n");
a:
	printf("hehe\n");
	return 0;
}//只会打印hehe