#define _CRT_SECURE_NO_WARNINGS 1
//��־��
//1��ʹ�ñ�׼�������
//2��ʹ�ú�������
//3��ʹ�����ñ���
//4��������
//5����������

#include<iostream>
using namespace std;
//1��ʹ�ñ�׼�������
int main()
{
	//int a = 0;
	//cin >> a;
	//cout << a << endl;

	double b;
	char c;
	long d;
	cin >> b;
	cout << b << endl;

	cin >> c >> d;
	cout << c << " " << d << endl;
	return 0;
}
//2��ʹ�ú�������
void function(int a = 0)
{
	if (a == 0)
	{
		cout << "��ã�����" << endl;
	}
	else
	{
		cout << "hello!!!" << endl;
	}
}
char function(char b)
{
	cout << b << endl;
	return 1; 
}
int main()
{
	function();
	function(1);
	function('c');
	return 0;
}
//3��ʹ�����ñ���
#include <stdio.h>
int main()
{
	int a = 10;//ʵ�ʱ���
	int& a1 = a;//����1
	int& a2 = a;//����2
	printf("%d %d %d\n", a, a1, a2);
	printf("%p %p %p", &a, &a1, &a2);
	return 0;
}
//4��������
int main()
{
	const int a = 10;
	//int& a1 = a;
	const int& a1 = a;

	10;
	//int& b1 = 10;
	const int& b1 = 10;
	
	double c = 3.14159;
	//int& c1 = c;
	const int& c1 = c;
	return 0;
}
//5����������
inline int add(int a = 0, int b = 0)
{
    return a + b;
}
int main()
{
    int c = 0;
    c = add(3, 5);
    cout << c;
    return 0;
}