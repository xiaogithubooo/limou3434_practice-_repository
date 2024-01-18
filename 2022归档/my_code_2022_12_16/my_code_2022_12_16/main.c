#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//测试当前环境是否支持C99的变长数组标准
//int main()
//{
//	int n = 10;
//	int arr[n] = { 0 };
//	return 0;
//}
//看来单纯下载了VS2022是不支持变长数组的
//但是gcc用C99标准是可以的
//int main()
//{
//	char arr[3] = "abc";//和char arr[3]={'a','b','c'};的效果相同
//	char a[] = "abc"//就会出项4个元素
//  return 0;
//}//经过调试发现arr的元素只放了a，b，c三个元素，\0被丢弃了
//int main()
//{
//	printf("abc\0def\n");//只会打印abc，并且后面的都没有理会了
//	printf("\n");
//	printf("abc0def");//都会打印出来
//	return 0;
//}
//另外复习了一下使用gcc来编译一个代码