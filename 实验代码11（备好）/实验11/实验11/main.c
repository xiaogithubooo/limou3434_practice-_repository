#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<math.h>
#include<Windows.h>
//实验目的：
//（1）熟悉字符串的基本操作
//（2）掌握指针和字符数组的使用方法
//（3）掌握字符串相关的库函数的使用方法

//任务一：
//int main(void)
//{
//	char src[80]={' '};
//	char dest[80]={' '};
//	printf("请输入一串字符：");
//	gets(src);
//	printf("执行strcpy前dest的内容：");
//	puts(dest);
//	strcpy(dest, src);
//	printf("执行strcpy后dest的内容：");
//	puts(dest);
//	return 0;
//}
//任务二：
void myStrCat(char* dest, char* src)
{
	puts(strcat(dest,src));                                   //哈哈笑死了这写法
}                                                           //而且这个库函数用的也不熟练
int main(void)
{
	char src[80];
	char dest[80];
	printf("请输入一串字符给src：");
	gets(src);
	printf("请输入一串字符给dest：");
	gets(dest);
	//执行函数前
	printf("执行myStrCat前dest的内容:");
	puts(dest);
	//执行函数后
	printf("执行myStrCat后dest的内容:");
	myStrCat(dest, src);
	return 0;//话说为什么结果会自动换行来着？？？
}
//任务三：
//int main(void)
//{
//	char arr[80];
//	char ch;
//	char* p;
//	int i;//循环次数
//	printf("请输入一串字符给arr：");
//	gets(arr);
//	printf("请输入要查找的字符：");
//	scanf("%c", &ch);
//	p = strchr(arr, ch);//库函数查找函数                     //这个库函数用的不熟练
//	printf("%c在字符串%s中的索引为：",ch,arr);
//	for (i=0; i < 80; ++i)
//	{
//		if (&arr[i] == p)
//		{
//			printf("%d", i);                                 //完成的有点捞hhhhhhh
//		}
//	}
//	return 0;
//}