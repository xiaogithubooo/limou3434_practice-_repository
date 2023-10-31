#include "List.hpp"
int main()
{
	int select = 0;

	do
	{
		//1.用户输入选择
		std::cout << "[1.菜单 2.多项式相加 (输入 -1 退出程序)]\n";
		std::cout << "---> 选择一个程序运行：";

		std::cin >> select;

		//2.选择运行的程序
		if (select == 1)//2.1.带菜单的通讯录
		{
			std::cout << "带菜单通讯录程序\n";
			limou::Drive<double>();
		}
		else if (select == 2)//2.2.多项式相加
		{
			std::cout << "多项式相加程序\n";
			limou::Polynomial<int>();
		}
		else if (select == -1)//2.3.退出程序
		{
			std::cout << "退出程序\n";
		}
		else
		{
			std::cout << "输入错误，请重新输入\n";
		}
	} while (select != -1);
	return 0;
}

