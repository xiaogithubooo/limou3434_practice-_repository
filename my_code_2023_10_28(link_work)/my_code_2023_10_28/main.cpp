#include "List.hpp"
int main()
{
	std::cout << "[1.�˵� 2.����ʽ��� 3.ͨѶ¼] ---> ѡ��һ���������У�";
	int select = 0;
	std::cin >> select;
	
	if (select == 1)//1.�˵�
	{
		std::cout << "�˵�����\n";
		limou::Drive<double>();
	}
	else if (select == 2)//2.����ʽ���
	{
		limou::Polynomial<int>();
	}
	else if (select == 3)//3.ͨѶ¼
	{
		limou::AddressBook<short>();
	}
	else
	{
		std::cout << "�������\n";
		assert(false);
	}

	return 0;
}

