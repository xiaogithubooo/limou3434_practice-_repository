#define _CRT_SECURE_NO_WARNINGS 1
#define PATH "C:\\users\\\
#include <stdio.h>
//下面这个语句是没有办法充当注释使用的
#define A /##/
int main()
{
	A printf("abcd\n");
	return 0;
}

////注意下面这个字符串要加上反斜杠得转移，整体也要加上双引号，也可以带上续行符

//limou_file"
//int main()
//{
//	printf("%s", PATH);//成功打印
//}