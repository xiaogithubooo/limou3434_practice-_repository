#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//1������sizeof����س���
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
//2��~��ʹ��
#include<stdio.h>
int main()
{
    int a = 0;
    //0000 0000 0000 0000 0000 0000 0000 0000����~����
    //1111 1111 1111 1111 1111 1111 1111 1111����һ������
    //1111 1111 1111 1111 1111 1111 1111 1110���ط���
    //1000 0000 0000 0000 0000 0000 0000 0001����ԭ��
    printf("%d\n", ~a);//�����-1
    return 0;
}
//3��ǿ������ת����ʹ��
int main()
{
	int a = 1;
	printf("%f %zd\n", (float)a, sizeof(a));
	printf("%d %zd\n", a, sizeof(a));
	return 0;
}
//4�����Դ���
#include <stdio.h>
int main()
{
    int i = 0, a = 0, b = 2, c = 3, d = 4;
    //i = a++ && ++b && d++;
    i = a++||++b||d++;
    printf("a = %d\nb = %d\nc = %d\nd = %d\n", a, b, c, d);
    return 0;
}