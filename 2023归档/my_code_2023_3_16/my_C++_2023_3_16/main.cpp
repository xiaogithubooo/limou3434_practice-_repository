#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//int main()
//{
//	int a = 0;
//	cin >> a;
//	cout << a + 1;
//	return 0;
//}
class Person
{
	public:
		void PrintPersonInfo();
	private:
		char _name[20];
		char _gender[3];
		int _age;
};
// 这里需要指定PrintPersonInfo是属于Person这个类域
void Person::PrintPersonInfo()
{
	cout << _name << " " << _gender << " " << _age << endl;
}