#include "LinkList.hpp"
void test_1(void)
{
	limou::LinkList<int> list1;//����һ���������
	list1.Push_back(1);
	list1.Push_back(2);
	list1.Push_back(3);
	std::cout << list1.Size() << std::endl;
	list1.Print();

	//list1.Pop_back();
	//list1.Pop_back();
	//list1.Pop_back();
	std::cout << list1.Size() << std::endl;
	list1.Print();
}
void test_2(void)
{
	limou::LinkList<int> list2;//����һ���������
	//list2.Pop_back();
	//list2.Pop_front();
	list2.Push_front(3);
	list2.Push_back(2);
	list2.Push_front(1);

	while(list2.Size() != 0)
	{
		list2.Print();
		list2.Pop_front();
	}

	std::cout << list2.Size() << std::endl;
	//list2.Pop_front();
	//list2.Pop_back();
	std::cout << (void*)list2.Find(0) << std::endl;
}
int main()
{

	//1.�򵥲���
	//test_1();

	//2.���˲���
	//test_2();

	return 0;
}