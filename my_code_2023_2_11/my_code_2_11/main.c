#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
////1����������ַ���
//int main()
//{
//    char arr[10000] = { 0 };
//    gets(arr);
//    for (int i = strlen(arr) - 1; i >= 0; i--)
//    {
//        if(arr[i] != '\n')
//        printf("%c", arr[i]);
//    }
//    return 0;
//}
////4����ˮ����
//int main()
//{
//	int number = 20;
//	int add = 0;
//	int i = 0;
//	while (number)
//	{
//		if (number % 2 == 0)
//		{
//			add += number;
//			number /= 2;
//		}
//		else
//		{
//			i++;
//			number -= 1;
//			add += number;
//			number /= 2;
//		}
//	}
//	printf("%d", add + i + (i / 2));
//
//	return 0;
//}
//int main()
//{
//	int money = 0;
//	int total = 0;
//	int empty = 0;
//
//
//	scanf("%d", &money);
//
//	//����2
//	if (money <= 0)
//	{
//		total = 0;
//	}
//	else
//	{
//		total = money * 2 - 1;
//	}
//	printf("total = %d\n", total);
//
//
//	return 0;
//}