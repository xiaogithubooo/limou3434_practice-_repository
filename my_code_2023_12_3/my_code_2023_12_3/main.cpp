#include <iostream>
using namespace std;

class Data
{
public:
	Data(int data = 100)
		: _data(data)
	{
		cout << "¹¹Ôì" << '\n';
	}
	~Data()
	{
		cout << "Îö¹¹ " << '\n';
	}
private:
	int _data;
};

double Division(int left, int right)
{
	Data d;
	if (right == 0)
	{
		throw d;
	}
	return (double)left / (double)right;
}

void Func()
{
	int left, right;
	cin >> left >> right;
	cout << Division(left, right) << '\n';
}

int main()
{
	try
	{
		Func();
	}
	catch (Data d)
	{
		cout << "OK" << '\n';
	}
	return 0;
}