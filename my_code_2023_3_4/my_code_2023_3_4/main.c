#define _CRT_SECURE_NO_WARNINGS 1
//��־
//1������ע���Ƿ��ڱ���ǰ���һ���ո�
//2��const�Ĳ���
//3������define����ǵ��ַ����Ľ�������
//4���л������Ƶ���n��λ��

#include<stdio.h>
//1������ע���Ƿ��ڱ���ǰ���һ���ո�
int main()
{
	int/*����ע���Ƿ��ɿո�*/a = 10;
	printf("%d\n", a);
	return 0;
}
//2��const�Ĳ���
int main()
{
	const int LIM = 50;
	const int LIM2 = 2 * LIM;
	printf("%d", LIM2);
	return 0;
}
//3������define����ǵ��ַ����Ľ�������
#define NUM_1 2*3
#define NUM_2 2 * 3
int main()
{
	printf("%d\n", NUM_1);
	printf("%d\n", NUM_2);
	//���Կ��������ͳ����ַ����ַ����������ǼǺ����ַ���
	return 0;
}
//4���л������Ƶ���n��λ��
void invert_end(int number, int n)
{
	int mask = 0;
	int bitval = 1;

	while (n-- > 0)
	{
		mask |= bitval;
		bitval <<= 1;
	}
	printf("%d", number ^ mask);
}
int main()
{
	int number = 0;
	int n = 0;
	scanf("����:%d  ��nλ��:%d", &number, &n);
	invert_end(number, n);
	return 0;
}