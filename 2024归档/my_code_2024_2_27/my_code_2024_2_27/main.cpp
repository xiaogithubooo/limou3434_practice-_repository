#include <iostream>
class Data
{
public:
	void Functon()
	{
		std::cout << number << std::endl;
	}

	int number_1;
	int number_2;
	static int number;
};
int Data::number = 10;

int main()
{
	static Data d;
	std::cout << d.number << std::endl;
	d.Functon();
	return 0;
}