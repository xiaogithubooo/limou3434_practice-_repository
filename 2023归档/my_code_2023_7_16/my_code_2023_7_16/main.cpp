#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
void func(int a)
{
	cout << "void func(int a)" << endl;
}
void func(int a, int b = 1)
{
	cout << "void func(int a,int b)" << endl;
}
int main()
{
	func(1, 2);//���óɹ�
	func(1);//����ʧ�ܣ���������ģ��
	return 0;
}

// namespace limou3434//��������������ռ�����֣�ǰ��namespace�������ռ�Ĺؼ���
//{
//	int print = 100;//�������ռ��ڶ���һ������
//	int function(int n)//�������ռ��ڶ���һ������
//	{
//		return n + 1;
//	}
//	struct Limou//�������ռ��ڶ���һ���ṹ��
//	{
//		int a;
//		char b;
//		float c;
//		double d;
//	};
//	namespace limou//�������ռ���Ƕ��һ�������ռ�
//	{
//		int e = 1;
//		int f = 2;
//		int g = 3;
//	}
//}
//int main()
//{
//	printf("%d\n", limou3434::print);
//	printf("%d\n", limou3434::function(9));
//	limou3434::Limou A;
//	A.a = 100;
//	printf("%d\n", A.a);
//	printf("%d\n", limou3434::limou::e);
//	return 0;
//}