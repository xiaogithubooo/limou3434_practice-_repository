#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	printf("%s\n", __FILE__);   //进行编译的源文件名称
	printf("%d\n", __LINE__);   //显示文件当前的行号
	printf("%s\n", __DATE__);   //文件被编译的日期
	printf("%s\n", __TIME__);   //文件被编译的时间
	//printf("%d\n", __STDC__);        //如果编译器严格遵循ANSI C，其值为1，否则未定义

	printf("%s\n", __FUNCDNAME__);
	printf("%s\n", __FUNCTION__);
	return 0;
}

void function(int a);//该函数只有声明，忘记给予定义
int main()
{
	function(2);
	printf("hello\n");
	return 0;
}
#include <stdio.h>
#define ADD(X, Y) \
((X) + (Y))
int main()
{
	printf("%d", ADD(2, 3));
	return 0;
}
#include <stdio.h>
#define PRINTF(num, format)\
		printf("The value of "#num" is "format, num)
int main()
{
	int a = 100;
	char b = 'c';
	double c = 3.14;
	PRINTF(a, "%d\n");
	PRINTF(b, "%c\n");
	PRINTF(c, "%f\n");
	return 0;
}
#include <stdio.h>
#define FUN(X, Y) X##Y
int main()
{
	int XY = 10;
	printf("%d\n", FUN(X, Y));//依旧可以打印出10，X和Y被FUN连接为一串字符串了，并且整体作为变量名
	return 0;
}
#include <stdio.h>
#define MAX(X, Y) ((X)>(Y)?(X):(Y))
int main()
{
	int a = 3;
	int b = 5;
	int c = MAX(a++, b++);
	((a++)>(b++)?(a++):(b++))，出现加加两次的情况，使用者容易忽略
	printf("%d\n", c);//6
	printf("%d\n", a);//4
	printf("%d\n", b);//7
	return 0;
}
