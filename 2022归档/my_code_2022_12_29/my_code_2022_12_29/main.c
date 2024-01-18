#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//1、有关于char类型赋值超出范围的输出实验
//int main()
//{
//	char a = 'FATE';
//	printf("%c", a);
//	//可以看到只输出了E，相当于4个1字节字符，只截断最后一个字符（最后8位，即1字节）来赋值
//	return 0;
//}

//2、利用转义字符的八进制和十进制表示ASCII值
//int main()
//{
//  //蜂鸣的ACSII值是7
//	//char x = 7;//十进制输入
//	//char x = '\07';//八进制输入
//	//char x = '\x7';//十六进制输入
//	char x = 07;//也是可以输入的，就是\07会更加提示我们这是一个命令，并且可以作为字符融入字符串之中
//	printf("%c", x);
//	//可以看到三种都是可以实现“蜂鸣”命令的
//	return 0;
//}

//3、使用转移字符命令
//写法一：
/*int main()
{
	char* a = 0;
	printf("$_______\b\b\b\b\b\b\b");
	scanf("%s", &a);
	printf("a=%s", &a);
	return 0;
}*///这个代码有点问题，不知道怎么改……
//写法二：
//int main()
//{
//	char a[8] = { 0 };
//	printf("$_______\b\b\b\b\b\b\b");
//	for (int i = 0; i < 7; i++)
//	{
//		scanf("%c", &a[i]);
//	}
//	for (int i = 0; i < 7; i++)
//	{
//		printf("%c", a[i]);
//	}
//	return 0;
//}//这个代码倒是正常运行了

//4、ASCII转换器
//int main()
//{
//	int my_ascii;
//
//	printf("请输入一个ASCII码值: ");
//	scanf("%d", &my_ascii);
//	printf("ASCII %d 对应的字符是 %c\n", my_ascii, my_ascii);
//	return 0;
//}
