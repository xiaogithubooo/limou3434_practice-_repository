#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void test_1()
{
	int x = 2;
	int* px = &x;
	int y = 10 / *px;//���Կ�������ո��Ǳ���ģ�����ᱻ����ע�� 
	printf("%d", y);

	//int z = 0789;//���Կ������ﱨ���ˣ�˵��vs2022���ǱȽ��ϸ�ı��������ϰ汾�����ɻὫ����Ϊһ���˽�������
	char ch = '\n';
	char* pch = &ch;
	printf(pch);//���������һ������ 
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
     //������ POSIX ��׼��صı���������
#define _CRT_SECURE_NO_WARNINGS

 //ע��SIGINT�źŴ�����
    signal(SIGINT, signal_handler);

     //��ѭ�����ȴ��źŵ���
    while (1) {
        printf("Waiting for signal...\n");
        _getch();
    }

    return 0;
}

