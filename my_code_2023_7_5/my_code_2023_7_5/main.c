#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
void test_1(void)
{
	char a = 101;
	//101�Ķ�����Ϊ0110 0101�����charûë��
	int sum = 200;
	//200�Ķ�������1100 1000�����intû��ë��

	a += 27;
	//a��������������101+27=128��������Ϊ1000 0000�����������charȡֵ[-128,127]��
	//��a���������з���char����-128����ʽ�洢��a��

	sum += a;//200-128=72
	printf("%d\n", sum);//���72
}

void test_2(void)
{
	int value = 1024;
	//����һ������value��
	//�洢��1024�Ĳ���0000 0100 0000 0000��
	//С�˻����ߵ�ַ�洢���ֽ�λ��
	//�͵�ַ----0000 0000 0100 0000----�ߵ�ַ

	char condition = *((char*)(&value));
	//ȡ��value�ĵ�ַ��ǿ��ױ��ָ������λchar*��
	//��˽�����ֻ�ܶ�ȡһ���ֽ�0000��
	//���condition�����洢����0000

	if (condition)//��if��䲻ִ��
		value += 1;

	condition = *((char*)(&value));
	//�����ɶҲû��

	if (condition)//��if��䲻ִ��
		value += 1;

	condition = *((char*)(&value));
	//�����ɶҲû��

	printf("%d %d", value, condition);
	//��ӡ��1024��0
}

void func_3(char para[])//������100��û100��һ����
{
	void* p = malloc(100);//������100���ֽڵĿռ�
	printf("%d, %d\n", sizeof(para), sizeof(p));//���4/8��4/8
}
void test_3(void)
{
	char arr[100];
	func_3(arr);
}

void func_4(char* p) 
{
	p = p + 1;
}
void test_4()
{
	char s[] = { '1', '2', '3', '4' };
	func_4(s);
	printf("%c", *s);//��������ַ�1
}
bool fun(int k, int n)
{
	int number = k - n;
	while (((number % 10) == 0) + ((n / 10) != 0) == 2)
	{
		number /= 10;
		n /= 10;
	}
	if (number % 10 == 0 || (n / 10) != 0)
	{
		return true;
	}
	return false;
}
void test_5(void)
{
	int n = 0;
	scanf("%d", &n);
	int flag = 0;
	while (n >= 0)
	{
		int k = n * n;
		if (fun(k, n))//�Ǿ���flag++
		{
			flag++;
		}
		n--;
	}
	printf("%d", flag);
}
int main()
{
	//test_1();
	//test_2();
	//test_3();
	//test_4();
	test_5();
}