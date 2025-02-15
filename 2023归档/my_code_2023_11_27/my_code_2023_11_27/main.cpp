#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

float getRectArea(float length, float width);
float getCuboidVolume(float length, float width, float height);

int main()
{
	float length = 0, width = 0, height = 0, area = 0, volume = 0;

	printf("请依次输入长度，宽度和高度（如1.0，2.0，3.0）\n");
	scanf("%0.f,%f,%f", &length, &width, &height);

	area = getRectArea(length, width);
	volume = getCuboidVolume(length, width, height);

	printf("矩形的面积=%f,体积=%f", area, volume);
	return 0;
}

float getRectArea(float length, float width)
{
	return (length * width);
}
float getCuboidVolume(float length, float width, float height)
{
	return (length * width * height);
}


//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//
//int isLeapYear(int year)
//{
//    if (year % 400 == 0)
//    {
//        return 1;
//    }
//    else if (year % 4 == 0 && year % 100 != 0)
//    {
//        return 1;
//    }
//    else
//    {
//        return 0;
//    }
//}
//
//int main()
//{
//    printf("1000年到2000年之间的闰年有:\n");
//    for (int year = 1000; year <= 2000; year++)
//    {
//        if (isLeapYear(year))
//        {
//            printf("%d\n", year);
//        }
//    }
//    return 0;
//}


//int countDigit9(int n)
//{
//    int count = 0;
//    while (n > 0)
//    {
//        if (n % 10 == 9)
//        {
//            count++;
//        }
//        n /= 10;
//    }
//    return count;
//}
//
//int main()
//{
//    int count = 0;
//    for (int i = 1; i <= 100; i++)
//    {
//        count += countDigit9(i);
//    }
//    printf("1到100的所有整数中数字9出现的次数为: %d\n", count);
//    return 0;
//}


//#include <stdio.h>
//#include <limits.h>
//int main()
//{
//	int max = INT_MIN;
//	for (int i = 0; i < 10; i++)
//	{
//		int number = 0;
//		scanf("%d", &number);
//		if (number > max)
//		{
//			max = number;
//		}
//	}
//	printf("%d\n", max);
//	return 0;
//}

//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <algorithm>
//
//int main()
//{
//	int i = 1;
//	int flag = 1;
//	double add = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		if (i % 2 == 0)
//			flag = -1;
//		else
//			flag = 1;
//		add += (flag * (1 / (double)i));
//	}
//	printf("%f\n", add);
//	return 0;
//}

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
//	printf("%d\n", arr[1]);//输出4
//	
//	//因此可以利用循环来输出arr的所有元素
//	int i = 0;
//	while (i < 3)
//	{
//		printf("%d ", arr[i]);//依次输出 5 4 3
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
//结果为
//0，1，2，3
//8


//#include<stdio.h>
//int main()
//{
//	int A = 43;
//	printf("%d\n", printf("%d", printf("%d", A)));
//}
////结果会输出什么呢？432
////第三个 printf 输出 "43" 字符数量为 2，于是返回值为 2，第二个 printf 就输出 "2"
////第二个 printf 输出 "2" 字符数量为 1，于是返回值为 1，第一个 printf 就输出 "1"
