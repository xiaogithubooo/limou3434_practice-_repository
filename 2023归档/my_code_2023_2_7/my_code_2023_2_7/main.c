#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//1、测试sizeof的相关程序
void test1(int arr[])
{
	printf("%d\n", sizeof(arr));//(2)
}
void test2(char ch[])
{
	printf("%d\n", sizeof(ch));//(4)
}
int main()
{
	int arr[10] = { 0 };
	char ch[10] = { 0 };
	printf("%d\n", sizeof(arr));//(1)
	printf("%d\n", sizeof(ch));//(3)
	test1(arr);
	test2(ch);
	return 0;
}
//2、~的使用
#include<stdio.h>
int main()
{
    int a = 0;
    //0000 0000 0000 0000 0000 0000 0000 0000经过~后变成
    //1111 1111 1111 1111 1111 1111 1111 1111生成一个补码
    //1111 1111 1111 1111 1111 1111 1111 1110返回反码
    //1000 0000 0000 0000 0000 0000 0000 0001返回原码
    printf("%d\n", ~a);//故输出-1
    return 0;
}
//3、强制类型转化的使用
int main()
{
	int a = 1;
	printf("%f %zd\n", (float)a, sizeof(a));
	printf("%d %zd\n", a, sizeof(a));
	return 0;
}
//4、测试代码
#include <stdio.h>
int main()
{
    int i = 0, a = 0, b = 2, c = 3, d = 4;
    //i = a++ && ++b && d++;
    i = a++||++b||d++;
    printf("a = %d\nb = %d\nc = %d\nd = %d\n", a, b, c, d);
    return 0;
}