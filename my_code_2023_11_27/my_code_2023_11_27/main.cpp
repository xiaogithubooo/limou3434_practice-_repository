#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int i = 1;
	int flag = 1;
	double add = 0;
	for (i = 1; i <= 100; i++)
	{
		if (i % 2 == 0)
			flag = -1;
		else
			flag = 1;
		add += (flag * (1 / (double)i));
	}
	printf("%f\n", add);
	return 0;
}

//void SortThree(int* a, int* b, int* c)
//{
//    int temp = 0;
//    if (*a > *b)
//    {
//        temp = *a;
//        *a = *b;
//        *b = temp;
//    }
//    if (*b > *c)
//    {
//        temp = *b;
//        *b = *c;
//        *c = temp;
//    }
//    if (*a > *b)
//    {
//        temp = *a;
//        *a = *b;
//        *b = temp;
//    }
//}
//int main()
//{
//    int arr[3] = { 0 };
//	for (int i = 0; i < 3; i++)
//	{
//		int scaRet = scanf("%d", &arr[i]);
//	}
//    SortThree(arr, arr + 1, arr + 2);
//    for (int i = 0; i < 3; i++)
//    {
//        printf("%d ", arr[i]);
//    }
//
//	return 0;
//}

//int main()
//{
//	int a = -1;
//	int b = ~a;
//	printf("%d\n", b);
//
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int arr[3] = { 5,4,3 };
//	printf("%d\n", arr[1]);//���4
//	
//	//��˿�������ѭ�������arr������Ԫ��
//	int i = 0;
//	while (i < 3)
//	{
//		printf("%d ", arr[i]);//������� 5 4 3
//		i++;
//	}
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//    printf("%zd\n", sizeof(char));
//    printf("%zd\n", sizeof(short));
//    printf("%zd\n", sizeof(int));
//    printf("%zd\n", sizeof(long));
//    printf("%zd\n", sizeof(long long));
//    printf("%zd\n", sizeof(float));
//    printf("%zd\n", sizeof(double));
//    return 0;
//}

//#include<stdio.h>
//int main()
//{
//	printf("%d\n", printf("0,1,2,3\n"));
//	return 0; 
//}
//���Ϊ
//0��1��2��3
//8


//#include<stdio.h>
//int main()
//{
//	int A = 43;
//	printf("%d\n", printf("%d", printf("%d", A)));
//}
////��������ʲô�أ�432
////������ printf ��� "43" �ַ�����Ϊ 2�����Ƿ���ֵΪ 2���ڶ��� printf ����� "2"
////�ڶ��� printf ��� "2" �ַ�����Ϊ 1�����Ƿ���ֵΪ 1����һ�� printf ����� "1"
