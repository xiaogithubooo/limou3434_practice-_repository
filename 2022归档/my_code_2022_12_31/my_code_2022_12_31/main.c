#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//1、输出矩形*
//int main()
//{
//    int x = 0;
//    while (scanf("%d", &x) == 1)
//    {
//        for (int i = 0; i < x; i++)
//        {
//            for (int j = 0; j < x; j++)
//            {
//                printf("* ");
//            }
//            printf("\n");
//        }
//    }
//    return 0;
//}

//2、输出左下角三角形*
//int main()
//{
//    int x = 0;
//    int i, j;
//    while (scanf("%d", &x) == 1)
//    {
//        for (i = 0; i < x; i++)
//        {
//            for (j = 0; j <= i; j++)
//            {
//                printf("* ");
//            }
//            printf("\n");
//        }
//    }
//    return 0;
//}

//3、倒三角
//int main()
//{
//    int x = 0;
//    int i = 0, j = 0;
//    while (scanf("%d", &x) == 1)
//    {
//        int d = x;
//        for (i = 0; i < x; i++)//一行一行来
//        {
//            for (j = 0; j < d; j++)
//            {
//                printf("* ");
//            }
//            d--;
//            printf("\n");
//        }
//    }
//    return 0;
//}

//4、牛客一道简单的加减运算
//int main()
//{
//    int a, b, c, d;
//    int y = 0;
//    scanf("%d %d %d %d", &a, &b, &c, &d);
//    y = ((a + b) - c) * d;
//    printf("%d\n", y);
//    return 0;
//}

//5、1~N之间的奇偶数个数
//int main()
//{
//    int x = 0, y = 0;
//    int N = 0;
//    scanf("%d", &N);
//    for (int i = 1; i < N + 1; i++)
//    {
//        if (i % 2 == 0)
//        {
//            x++;
//        }
//        else
//        {
//            y++;
//        }
//    }
//    printf("%d %d", y, x);
//    return 0;
//}