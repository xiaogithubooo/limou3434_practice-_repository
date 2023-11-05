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
		if (select == 1)//2.1.菜单
		{
			std::cout << "链表菜单\n";
			limou::Drive<int>();
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
			while (std::cin.fail())//检测 cin 的状态，错误返回 true
			{
				std::string error_string;
				std::cin.clear();//清除 cin 的错误状态
				std::cin >> error_string;
				std::cout << "输入的 " << error_string << " 不是数字，重新输入" << std::endl;
				break;
			}
			std::cout << "没有该选项对应的程序" << std::endl;
		}
	} while (select != -1);
	return 0;
}

