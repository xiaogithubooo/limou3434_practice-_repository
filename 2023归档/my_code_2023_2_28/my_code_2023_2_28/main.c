#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//1、测试char的范围
int main()
{
	char a = -128;
	printf("%d", a);
	return 0;
}
//2、利用共用体检测大小端
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
    printf("%d", check_sys());//说明当前环境为小端模式
    return 0;
}
//3、