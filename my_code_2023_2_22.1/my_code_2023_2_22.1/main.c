#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//1、使用二维数组指针（深刻理解）
void print(int(*p)[20], int x, int y)
{
	//二维数组的名字就是首元素的地址，其地址就是第一行数组的地址，也就是指向一维数组类型的指针
	//又因为一维数组的整体地址&arr和其首元素地址&arr[0]起始位置相同
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			printf("%d", *(* (p + i) + j));//得到数组名，利用i得到每一行的数组名，利用j得到某一行的每一列的元素地址
		}
	}
}
int main()
{
	int arr[10][20] = { {1, 2, 3}, {2, 3, 4} };
	print(arr, 10, 20);
	return 0;
}
//2、帮同学改代码
int main()
{
	double a = 0, b = 0, c = 0;
	int i = scanf("%Lf! %Lf! %Lf!", &a, &b, &c);
	printf("%Lf %Lf %Lf\n%d", a, b, c, i);
	return 0;
}