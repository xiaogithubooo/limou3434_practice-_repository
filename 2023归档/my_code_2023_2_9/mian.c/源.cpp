#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
////1��������Ŀ
//int convertInteger(int A, int B)
//{
//	int number = A ^ B;
//	int a = 0;
//	while (number)
//	{
//		if ((number & 1) == 1)
//		{
//			a++;
//		}
//		number >>= 1;
//	}
//	return a;
//}
//int main()
//{
//	printf("%d", convertInteger(2, 3));
//	return 0;
//}
////2��ţ����Ŀ
//int main()
//{
//    char arr[1000] = { 0 };
//    char n;
//    int add = 0;
//    while (scanf("%c", &n) == 1 && n != '\n')
//    {
//        arr[n] = n;
//    }
//    for (int i = 0; i < 128; i++)
//    {
//        if (arr[i] != 0 && arr[i] != '\n')
//        {
//            add++;
//        }
//    }
//    printf("%d", add);
//    return 0;
//}
// 3��������Ŀ
//int main()
//{
//	int number = 0;
//	scanf("%d", &number);
//	int a = 0, b = 0;
//	int Bool = 0;
//	a = number;
//	while (a)//����һ����
//	{
//		b = number % 10;
//		if (b != 0 && number % b == 0)
//		{
//			Bool = 1;
//		}
//		else
//		{
//			Bool = 0;
//		}
//		a = a / 10;
//	}
//	if (Bool == 1)
//	{
//		printf("hah");
//	}
//	return 0;
//}
//int* selfDividingNumbers(int left, int right, int* returnSize)
//{
//	int number = 0;
//	int Bool = 0;
//	int j = 0;
//	int b = 0;
//	for (int i = left; i <= right; i++)
//	{
//		number = i;
//		while (number)//����һ����
//		{
//			b = number % 10;
//			if (b != 0 && number % b == 0)
//			{
//				Bool = 1;
//			}
//			else
//			{
//				Bool = 0;
//			}
//			number /= 10;
//		}
//		if (Bool == 1)
//		{
//			returnSize[j] = i;
//			j++;
//		}
//	}
//	return returnSize;
//}
//int main()
//{
//	int left = 0;
//	int right = 0;
//	scanf("%d %d", &left, &right);
//	int returnSize[100] = { 0 };
//	selfDividingNumbers(left, right, returnSize);
//	for (int i = 0; i < 100; i++)
//	{
//		printf("%d\n", returnSize[i]);
//	}
//	return 0;
//}
////4��������Ŀ������+-*/ʵ�ּӷ�
///**
// * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
// *
// *
// * @param num1 int����
// * @param num2 int����
// * @return int����
// */
//int Add(int num1, int num2)
//{
//    int sum = num1 ^ num2, c = (num1 & num2) << 1;
//    return (sum ^ c) + ((sum & c) << 1);
//}
////5����ҵ���Դ���
//void func()
//{
//	int a = 31 >> 31;
//	int b = 1 << 0;
//	int c = 1 ^ 1;
//	int k = 1 ^ (1 << 31 >> 31);
//	printf("%d\n", k);
//}
//int main()
//{
//	func();
//	return 0;
//}
//6�����۴�����Ŀ
//int findMaxConsecutiveOnes(int* nums, int numsSize) {
//
//    int ret = 0;    //����һ������ֵ
//    int ret_temp = 0;//����һ�����ص��ݴ�ֵ
//
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (nums[i] == 1)
//        {      //���ֵΪ1
//            ret_temp++;         //�ݴ�ֵ�ĸ�����һ
//            if (ret_temp > ret)
//            {
//                ret = ret_temp; //ˢ�·��ظ���
//            }
//        }
//        else
//        {
//            ret_temp = 0;       //����
//        }
//    }
//
//    return ret;
//}