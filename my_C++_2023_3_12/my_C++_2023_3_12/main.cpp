#include<iostream>
#include<stdio.h>

namespace limou3434//��������������ռ������
{
	int print = 100;//�������ռ��ڶ���һ������
	int function(int n)//�������ռ��ڶ���һ������
	{
		return n + 1;
	}
	struct Limou//�������ռ��ڶ���һ���ṹ��
	{
		int a;
		char b;
		float c;
		double d;
	};
	namespace limou//�������ռ���Ƕ��һ�������ռ�
	{
		int e = 1;
		int f = 2;
		int g = 3;
	}
}
using namespace limou3434;
using namespace std;
int main()
{

	cout << print;
	return 0;
}