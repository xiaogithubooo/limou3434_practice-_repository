#define _CRT_SECURE_NO_WARNINGS 1
//��־
//�й������ָ�����ϰ��
#include <stdio.h>
#include <string.h>
//1����һ��
int main()
{
    int a[5] = { 1, 2, 3, 4, 5 };
    int* ptr = (int*)(&a + 1);//&aȡ����������ĵ�ַ��+1��������������õ�һ����ַ������ǿ��ת��Ϊ(int*)����
    printf("%d, %d", *(a + 1), *(ptr - 1));
    //a+1�ǵڶ���Ԫ�ص�ַ�������õõ��ڶ���Ԫ��
    //ptr��-1�õ���������һ��Ԫ�ص�ַ�������õõ����һ��Ԫ��
    return 0;
}
//2���ڶ���
struct Test
{
	int Num;
	char* pcName;
	short sDate;
	char cha[2];
	short sBa[4];
}*p;

//��֪���ṹ��Test���͵ı�����С��20���ֽ�
int main()
{
	p = (struct Test*)0x100000;
	printf("%p\n", p + 0x1);
	printf("%p\n", (unsigned long)p + 0x1);
	printf("%p\n", (unsigned int*)p + 0x1);
	return 0;
}
//3��������
int main()
{
	int a[4] = { 1, 2, 3, 4 };
	int* ptr1 = (int*)(&a + 1);
	int* ptr2 = (int*)((int)a + 1);
	printf("%x, %x", ptr1[-1], *ptr2);
	return 0;
}