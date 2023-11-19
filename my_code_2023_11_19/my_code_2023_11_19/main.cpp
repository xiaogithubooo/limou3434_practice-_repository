#include <stdio.h>
#include <string.h>

int main()
{
	//char* 和 char arr[]（字符数组）都可以指向或存放一个字符串
	const char* s1 = "abcd";
	char s2[] = "abcd";
	char s3[] = { 'a','b','c' };		//这个是存储多个单字符的数组，末尾没有 \0
	char s4[] = { 'a','b','c','\0' };	//这样就没问题了

	printf("%s\n", s1);	//这里 %s 打印出字符串
	printf("%s\n", s2);	//这里 %s 打印出字符串

	printf("%d\n", strlen(s4));   //也是靠 \0 来计算字符串的长度的，输出了 3，即字符串的长度
	printf("%d\n", strlen(s3));   //则输出来是非 3 的值，是个随机值，什么时候找到 \0 就输出长度

	char s5[4] = { 'b','i','t' };
	printf("%d\n", strlen(s5));//由于放入了 3 个元素，第 4 个初始化默认为 0，即 '\0'，故 strlen(arr) 是 3，而不是不是随机值
}

//#include <stdio.h>
//int a;
//int main()
//{
//	printf("%d\n", a);
//	return 0;
//}
// 
////#include <stdio.h>
////int a = 20;
////int main()
////{
////	printf("%d\n", a);
////	{
////		printf("%d\n", a);
////	}
////	return 0;
////}//则打印出两个20
//
//
////#include <cstdio>
////int main()//局部变量的生命周期演示
////{
////    {
////        int a = 10;
////        printf("%d\n", a);
////    }
////    //上面的 a 变量走到这行代码就被销毁，不存在
////    return 0;
////}