#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
void function_1(int n)
{
	;
}
void function_2(int& n)
{
	;
}
void function_3(const int& n)
{ 
	;
}
int main()
{
	int a = 10;
	const int b = 20;

	function_1(a);
	function_1(b);
	function_1(30);

	function_2(a);
	//function_2(b);//���ǲ��������
	//function_2(30);//���ǲ��������

	function_3(a);
	function_3(b);
	function_3(30);

	return 0;
}
//int main()
//{
//    const int c = 20;//c�ɶ�����д
//    //int& d = c;//d��cȨ�޷Ŵ��ˣ��ɶ���д�������ǲ��������
//    const int& d = c;//��������ģ�����Ȩ��ƽ�Ƶĸ���
//
//    int e = 30;
//    const int& f = e;//����Ȩ����С�Ǳ������
//
//    int g = 1;
//    double h = g;//�������һ����ʱ���������洢�����������g���ٸ���h������g����ʽǿתҲ���У���������ʽ������ʽ��������ı�g��������ͣ�
//    //double& i = g;//���ǲ�������ģ���Ϊ�������һ����ʱ���������洢�����������g���������ʱ�������г����ԣ���ʱ������h���õĻ�������Ȩ�޷Ŵ�
//    const double& i = g;//���Ǳ�����ģ�ֻ�Ƿ�����Ȩ��ƽ��
//
//    const double& j = 3.14;
//
//    int&& k = 10;
//    return 0;
	//int a = 10;
	//double b = 3.14;
	//cout << typeid(a).name() << endl;
	//cout << typeid(b).name() << endl;
	//return 0;
//}