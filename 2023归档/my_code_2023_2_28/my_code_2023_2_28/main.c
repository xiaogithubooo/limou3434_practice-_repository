#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//1������char�ķ�Χ
int main()
{
	char a = -128;
	printf("%d", a);
	return 0;
}
//2�����ù��������С��
int check_sys()
{
    union
    {
        int i;
        char c;
    }un;
    un.i = 1;
    return un.c;
}
int main()
{
    printf("%d", check_sys());//˵����ǰ����ΪС��ģʽ
    return 0;
}
//3��