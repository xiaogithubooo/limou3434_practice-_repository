//�ַ���ƴ��
#include <sstream>
#include <iostream>
using namespace std;

int main()
{
	stringstream ss;
	//������ַ������� ss ��
	ss << "first" << " " << "string,";
	ss << " second string";
	cout << "strResult is: " << ss.str() << endl;

	//��� ss
	ss.str("");
	ss << "third string";
	cout << "After clear, strResult is: " << ss.str() << endl;
	return 0;
}