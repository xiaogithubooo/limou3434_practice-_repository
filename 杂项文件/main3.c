// #include <stdio.h>

// #define MAXN 10
// typedef float ElementType;

// ElementType Median( ElementType A[], int N );

// int main ()
// {
//     ElementType A[MAXN];
//     int N, i;

//     scanf("%d", &N);
//     for ( i=0; i<N; i++ )
//         scanf("%f", &A[i]);
//     printf("%.2f\n", Median(A, N));

//     return 0;
// }
// ElementType Median( ElementType A[], int N )
// {
//     for(int i = 0; i < N; i++)//排序数组
//     {
//         for(int j = i + 1; j <= N; j++)
//         {
//             if(A[i] > A[j])
//             {
//                 int tmp = A[i];
//                 A[i] = A[j];
//                 A[j] = tmp;
//             }
//         }
//     }
//     if( N % 2 == 0 )//偶数
//     {
//         return (A[N/2]+A[(N/2)+1])/2;
//     }
//     else
//     {
//         return A[(N/2) + 1];
//     }
// }
#include <stdio.h>
int main()
{
    //嵌套结构体
    struct S3
    {
        double d;
        char c;
        long double i;
    };
    printf("%d\n", sizeof(struct S3));

    struct S4
    {
        char c1;
        struct S3 s3;
        double d;
    };
    printf("%d\n", sizeof(struct S4));
    return 0;
}

