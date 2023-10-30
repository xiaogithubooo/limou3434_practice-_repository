#include "List.hpp"
int main()
{
	std::cout << "[1.菜单 2.多项式相加 3.通讯录] ---> 选择一个程序运行：";
	int select = 0;
	std::cin >> select;
	
	if (select == 1)//1.菜单
	{
		std::cout << "菜单程序\n";
		limou::Drive<double>();
	}
	else if (select == 2)//2.多项式相加
	{
		limou::Polynomial<int>();
	}
	else if (select == 3)//3.通讯录
	{
		limou::AddressBook<short>();
	}
	else
	{
		std::cout << "输入错误\n";
		assert(false);
	}

	return 0;
}

