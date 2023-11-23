#include <stdio.h>
int main()
{
	int i;
	for (i = 0; i < 10; i++)
	{
		printf("你好\n");
	}
	scanf("%d", &i);
	return 0;
}

//int main()
//{
//	int i = 0;
//	do
//	{
//		printf("%d\n", i);
//		++i;
//	} while (i < 10);//先执行一次上面的代码，然后才进行判断，和 while 先判断再做的顺序相反
//
//	return 0;
//}//就会打印出 0~9 的 10 个数字

//int main()
//{
//	int number = 10;
//	while (number < 20)//只要 number 小于 20 就进入循环
//	{
//		printf("你好\n");
//	}
//	return 0;
//}
////结果是打印出无限的“你好”，这乍一看有些吓人，
////但在VS中可以直接关闭控制台就可以结束这个循环，
////或者按下快捷键 [ctrl + c]（不同系统的快捷键可能不太一样）

//#include <stdio.h>
//int main()
//{
//	int a = 1;
//	if (a == 1)//如果 a 等于 1 就会执行代码 1，否则执行代码 2
//	{
//		printf("haha\n");//代码 1
//	}
//	else
//	{
//		printf("hehe\n");//代码 2
//	}
//	return 0;
//}//因此只打印了 haha，不会打印 hehe，您可以修改一下变量的值再运行试试

//#include <stdio.h>
//int main()
//{
//	printf("%c\n", 88);			//输出 X，使用 88 这个十进制来打印字符
//	printf("%c\n", '\130');		//输出 X，其中 \130 是八进制的数字
//	printf("%c\n", '\x58');		//输出 X，其中 \x58 是十六进制的数字
//
//	//转义字符也算字符，整体包括 \ 符号看作一个整体
//	return 0;
//}


////#define 定义的标识符常量，在代码编译过程中，
////代码中有 MAX 的地方会先被全部替换成 100，
////注意，宏常量的定义，其末尾不加分号，容易出 bug
//#define MAX 100
//
////以下创建了一个枚举常量，只能枚举出离散变量，但是连续变量就不能被枚举出来
//enum Sex
//{
//	MALE,		//默认值为0
//	FEMALE,		//默认值为1
//	SECRET		//默认值为2
//};
////若是将 MALE 设定为 5，则后面就依次改为 6、7，
////这叫“初始化值”，不是“修改值”，所以是常量，而非变量
//
//int main()
//{
//	//1.字面常量
//	//这里只是写出字面常量，顾名思义“从字面上就可以看出来”
//	100;	//整型常量
//	'W';	//字符常量
//	3.14;	//浮点常量
//
//	//2.const 常变量
//	int number_1 = 1;		//在这里 1 也是常量，但是 a 是变量
//	number_1 = 20;			//number_1 是变量，值可以从 10 变成 20
//	const int number_2 = 10;	//const 修饰的常变量
//	//number_2 = 20;			//使用了 const 关键字后，这里就会报错，变量 number_2 无法被修改
//
//	//3.宏常量
//	int n = MAX;	//MAX 常量会在代码运行前被替换成 100，因此变量 n 会被初始化为 100
//
//	//4.枚举常量
//	enum Sex s = FEMALE;	//变量 s 的值被初始化为 1
//
//	return 0;
//}

//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
//
//int main()
//{
//	string str1, str2;
//	cin >> str1 >> str2;
//
//	for (int i = 0; i < str2.size(); i++)
//	{
//		for (int j = str2.size(); j > 0; j--)
//		{
//			string sub = str2.substr(i, i);
//		}
//	}
//
//	return 0;
//}
//
////int main()
////{
////	string str;
////	cin >> str;
////	reverse(str.begin(), str.end());
////	cout << str;
////	return 0;
////}