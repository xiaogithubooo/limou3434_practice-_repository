#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
    struct S1
    {
        char c1;//char大小为1，和默认对齐数8比，该成员的对齐数是1
        char c2;//char大小为1，和默认对齐数8比，该成员的对齐数是1
        int i;//整型大小为4，和默认对齐数8比，该成员的对齐数是4
    };//最大对齐数是4
    printf("%d\n", sizeof(struct S1));//结果为8
    struct S2
    {
        char c1;
        int i;
        char c2;
    };
    printf("%d\n", sizeof(struct S2));
	return 0;
}
int main()
{
    //嵌套结构体
    struct S3
    {
        double d;//大小为8，和默认对齐数8相比，该成员的成员对齐数为8
        char c;//大小为1，与默认对齐数8相比，该成员的成员对齐数为1
        int i;//大小为4，与默认对齐数8相比，该成员的成员对齐数为4
    };//最大成员对齐数为8，结构体的总大小必须是8的倍数
    printf("%d\n", sizeof(struct S3));//输出16

    struct S4
    {
        char c1;//大小为1，与默认对齐数8相比，该成员的成员对齐数为1
        struct S3 s3;//大小为16，与默认对齐数8相比，该成员的成员对齐数为8
        double d;//大小为8，与默认对齐数8相比，该成员的成员对齐数为8
    };//最大成员对齐数为8，结构体的总大小必须是8的倍数
    printf("%d\n", sizeof(struct S4));//值为32
	return 0;
}
#pragma pack(8)//把默认对齐数设置为8
struct S1
{
    char c1;//char大小为1，和默认对齐数8比，该成员的成员对齐数是1
    char c2;//char大小为1，和默认对齐数8比，该成员的成员对齐数是1
    int i;//整型大小为4，和默认对齐数8比，该成员的成员对齐数是4
};//最大成员对齐数是4
int main()
{
    printf("%d\n", sizeof(struct S1));//结果为8
}
#pragma pack()//取消设置的默认对齐数，还原为默认
#pragma pack(1)//设置默认对齐数为1
struct S2
{
    char c1;//大小为1，和设置后的默认对齐数1比，该成员的成员对齐数是1
    int i;//大小为4，和设置后的默认对齐数1比，该成员的成员对齐数是1
    char c2;//大小为1，和设置后的默认对齐数1比，该成员的成员对齐数为1
};//最大成员对齐数是1，结构体大小必须是1的倍数
#pragma pack()//取消设置的默认对齐数，还原为默认

int main()
{
    printf("%d\n", sizeof(struct S2));//结果为5
    return 0;
}