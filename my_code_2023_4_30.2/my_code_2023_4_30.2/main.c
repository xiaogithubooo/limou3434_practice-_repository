#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#define INT_1 int
typedef int INT_2;
int main()
{
	unsigned INT_1 a = 10;//�Ϸ�
	//unsigned INT_2 b = 10;//���Ϸ���typedef���¶���ı��������޷���ô��

	const INT_2 c = 10;//�Ϸ�
	printf("%d %d", a, c);
	return 0;
}