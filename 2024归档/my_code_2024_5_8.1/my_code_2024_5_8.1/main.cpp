#include<stdio.h>
int main()
{
	int numOfArr;
	numOfArr = 10;
	int arr[numOfArr];
	int i = 0;

	for (i = 0; i < numOfArr; i++)
	{
		arr[i] = i * i;
	}

	for (i = 0; i < numOfArr; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}

//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	int a = 3;
//	int b = -5;
//	int c = a | b;
//	//b = 1000 0000|0000 0000|0000 0000|0000 0101(原) = -5
//	//b = 1111 1111|1111 1111|1111 1111|1111 1010(反)
//	//
//	//b = 1111 1111|1111 1111|1111 1111|1111 1011(补)
//	//a = 0000 0000|0000 0000|0000 0000|0000 0011(补) = +3  做按位或运算
//	//-----------------------------------------------------------------
//	//c = 1111 1111|1111 1111|1111 1111|1111 1011(补)
//	//
//	//c = 1111 1111|1111 1111|1111 1111|1111 1010(反)
//	//c = 1000 0000|0000 0000|0000 0000|0000 0101(原) = -5
//
//	printf("%d\n", c); //c的结果为3
//	return 0;
//}