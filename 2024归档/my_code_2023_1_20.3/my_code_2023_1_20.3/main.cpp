//string �ĳ�Ա���� cin �������÷�
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	char ch = 0;


	//��һ�����루�����������е����пո��ַ���ֱ�������ǿո��ַ�Ϊֹ����ʼ��ȡ��
	cout << "��һ������:" << '\n';
	for (int i = 0; i < 5; i++)
	{
		cin >> str;
		cout << "str:" << str << '\n';
		ch = cin.get(); //ֻ��ȡһ���ַ���ȥ�����з���������Բ��ã�����Ϊ���㱻 str ��ȡ��Ҳ�ᱻ������
	}
	//ch = cin.get(); //�������ѭ���е� ch = cin.get(); ������ô�����Ӧ�ü��� ch = cin.get(); ����Ӱ���������


	//�ڶ������루�����������е����� ',' �ַ���ֱ�������� ',' �ַ�Ϊֹ����ʼ��ȡ��
	cout << "�ڶ�������:" << '\n';
	for (int i = 0; i < 5; i++)
	{
		getline(cin, str, ',');
		cout << "str:" << str << '\n';
		if (i == 5)
			break;
		ch = cin.get(); //ֻ��ȡһ���ַ���ȥ�����з�
	}


	//���������루һֱ��ȡ���룬ֱ���������з�������ֱ���������з������Ż����뻺�壩
	cout << "����������:" << '\n';
	getline(cin, str);
	cout << "str:" << str << '\n';

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