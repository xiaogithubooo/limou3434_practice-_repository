#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/////1���ػ�����
//int main()
//{
//    char arr[20] = { 0 };
//    system("shutdown -s -t 60");
//again:
//    printf("��ĵ���60s��ػ��ˣ����룺������sb������ȡ���ػ�\n");
//        scanf("%s", arr);
//    if (strcmp(arr, "����sb") == 0)
//    {
//        printf("ȡ���ػ�");
//        system("shutdown -a");
//    }
//    else
//    {
//        goto again;
//    }
//    return 0;
//}
////2�������ĸ�ϰ
//int MAX(int x, int y)
//{
//    return (x > y) ? (x) : (y);
//}
//int main()
//{
//    int num_1 = 10;
//    int num_2 = 100;
//    int max = MAX(num_1, num_2);
//    printf("max = %d\n", max);
//    return 0;
//}
////3�����������ĸ�ϰ
//void function(int* pa, int* pb)
//{
//    int t = 0;
//    t = *pa;
//    *pa = *pb;
//    *pb = t;
//}
//int main()
//{
//    int num_1 = 1;
//    int num_2 = 2;
//    printf("%d %d\n", num_1, num_2);
//
//    function(&num_1, &num_2);//ʹ�ý�������
//    printf("%d %d\n", num_1, num_2);
//    return 0;
//}
//void function(int a, int b)
//{
//    int t = 0;
//    t = a;
//    a = b;
//    b = t;
//}
//int main()
//{
//    int num_1 = 1;
//    int num_2 = 2;
//    printf("%d %d\n", num_1, num_2);
//
//    function(num_1, num_2);//ʹ�ý�������
//    printf("%d %d\n", num_1, num_2);
//    return 0;
//}
////4���򻯲�������ķ���
//int is_leap_year(int y)
//{
//	return ((y % 4 == 0) && (y % 100 != 0)) || y % 400 == 0;
//
//}
//int main()
//{
//	int y = 0;
//	for (y = 1000; y <= 2000; y++)
//	{
//		//�ж�y�Ƿ�Ϊ����
//		//��������귵��1
//		//�������귵��0
//		if (is_leap_year(y))
//		{
//			printf("%d ", y);
//		}
//	}
//	return 0;
//}
////5��