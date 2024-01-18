#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
    //Ç¶Ì×½á¹¹Ìå
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