#include "List.hpp"
int main()
{
	int select = 0;

	do
	{
		//1.�û�����ѡ��
		std::cout << "[1.�˵� 2.����ʽ��� (���� -1 �˳�����)]\n";
		std::cout << "---> ѡ��һ���������У�";

		std::cin >> select;

		//2.ѡ�����еĳ���
		if (select == 1)//2.1.���˵���ͨѶ¼
		{
			std::cout << "���˵�ͨѶ¼����\n";
			limou::Drive<double>();
		}
		else if (select == 2)//2.2.����ʽ���
		{
			std::cout << "����ʽ��ӳ���\n";
			limou::Polynomial<int>();
		}
		else if (select == -1)//2.3.�˳�����
		{
			std::cout << "�˳�����\n";
		}
		else
		{
			std::cout << "�����������������\n";
		}
	} while (select != -1);
	return 0;
}

