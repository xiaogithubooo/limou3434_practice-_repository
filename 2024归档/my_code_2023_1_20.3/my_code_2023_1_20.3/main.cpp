#include <iostream>
#include <string>
using namespace std;

int main()
{

	//��һ�����루���Կո񡢺��Ի��з���
	string str;
	cin >> str;
	cout << "str:" << str << endl;
	cin.get(); //ֻ��ȡһ���ַ�

	//�ڶ������루��ȡ���룬ֱ���������з��������������з���
	getline(cin, str);
	const char* s = str.c_str();
	cout << "str:" << str << endl;
	cin.get(); //ֻ��ȡһ���ַ�

	//���������루��
	return 0;
}

//#include <iostream> //streamsize
//#include <string>
//#include <limits> //numeric_limits
//
//using namespace std;
//
//int main()
//{
//	int number = 0;
//	cin >> number;
//	if (cin.fail()) //�ж� cin ��״̬���� cin Ϊ����״̬�򷵻� true, ����״̬�򷵻� false
//	{
//		cout << "��������" << endl;
//		cin.clear(); //���cin�Ĵ���״̬����Ҫ��
//		in.ignore(numeric_limits<streamsize>::max(), '\n');  //���Ի������е������ַ���ֱ���������з�Ϊֹ����Ҫ��
//	
//		/* ����std::numeric_limits ��һ��ģ���࣬���ڻ�ȡ������ֵ���ͣ����������������ȣ���������Ϣ */
//	}
//	else
//	{
//		cout << "number:" << number << endl;
//	}
//
//	//��������״̬����������� cin �����ᱻִ�У�����ԭ�ȵ�����������Ȼ���ڻ�������
//	//������״̬��û���������������ԭ�����ڻ����������ݻᱻ cin ������ȡ
//	char character = 0;
//	cin >> character;
//	cout << "character:" << character << endl;
//	return 0;
//}