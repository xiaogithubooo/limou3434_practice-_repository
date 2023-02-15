#define _CRT_SECURE_NO_WARNINGS 1
//1、二分查找法的复习
#include <stdio.h>
int main()
{
    int arr[] = { 1,2,3,4,5,6,7,8,9,10 };//有序数组
    //下标        0,1,2,3,[4],5,6,7,8,9
    int i = 0;
    int k = 0;
    scanf("%d", &k);
    int sz = sizeof(arr) / sizeof(arr[0]);//计算数组的大小
    int left = 0;//左下标
    int right = sz - 1;//右下标
    int flag = 0;
    int mid = 0;
    while (left <= right)
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
//2、猜数字游戏
#include <stdlib.h>
#include <time.h>
void menu()
{
	printf("********************************\n");
	printf("*******     1. play      *******\n");
	printf("*******     0. exit      *******\n");
	printf("********************************\n");
}
void game()
{
	int ret = rand() % 100 + 1;
	int num = 0;
	while (1)
	{
		printf("请猜数字:>");
		scanf("%d", &num);
		if (num == ret)
		{
			printf("恭喜你，猜对了\n");
			break;
		}
		else if (num > ret)
		{
			printf("猜大了\n");
		}
		else
		{
			printf("猜小了\n");
		}
	}
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (input);
	return 0;
}