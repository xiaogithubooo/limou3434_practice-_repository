#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void test_1()
{
	int x = 2;
	int* px = &x;
	int y = 10 / *px;//可以看到这个空格是必须的，否则会被误会成注释 
	printf("%d", y);

	//int z = 0789;//可以看到这里报错了，说明vs2022还是比较严格的编译器，老版本会依旧会将其视为一个八进制数字
	char ch = '\n';
	char* pch = &ch;
	printf(pch);//这里出现了一个错误 
}
void test_2()
{
	int a = 1;
	int b = 2;
	int c = a+++++b;
}
int main()
{
	//test_1();
	//test_2();

	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <conio.h>

void signal_handler(int signum) {
    printf("Caught signal %d, coming out...\n", signum);
    exit(1);
}

int main() {
     //禁用与 POSIX 标准相关的编译器警告
#define _CRT_SECURE_NO_WARNINGS

 //注册SIGINT信号处理函数
    signal(SIGINT, signal_handler);

     //死循环，等待信号到来
    while (1) {
        printf("Waiting for signal...\n");
        _getch();
    }

    return 0;
}

