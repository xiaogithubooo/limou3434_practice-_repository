//测试驱动
#include "ExchangeSort.hpp"
#define SIZE 10000

void Data(std::vector<int>& vec)
{
	//1.随机数生成
	std::uniform_int_distribution<int> dist(0, SIZE);//生成[0, SIZE]的均匀分布整数
	int randomInt;

	//2.存入待排序数据（随机序列）
	for (int i = 0; i < SIZE; i++)
	{
		randomInt = dist(rng);//生成随机整数
		vec.push_back(randomInt);//插入随机数
		printf("%5d ", vec[vec.size() - 1]);
	}

	////3.存入待排序数据（逆序序列）
	//std::vector<int> vec;
	//for (int i = 0; i < SIZE; i++)
	//{
	//	vec.push_back(SIZE - i);
	//	printf("%+5d ", vec[i]);
	//}

	//4.换行
	std::cout << std::endl << "-----------------------------" << std::endl;
}
void Sort(std::vector<int>& vec)
{
	//2.1.霍尔快排测试
	//limou::HoareQuickSort(vec, 0, (int)vec.size()-1);
	//2.2.挖坑快排测试
	//limou::PitfallQuickSort(vec, 0, (int)vec.size() - 1);
	//2.3.前后指针测试
	//limou::TwoPointerQuickSort(vec, 0, (int)vec.size() - 1);
	//2.4.三路划分测试
	limou::ThreeWayQuickSort(vec, 0, (int)vec.size() - 1);
}
void Put(std::vector<int>& vec)
{
	for (int i = 0; i < SIZE; i++)
	{
		printf("%5d ", vec[i]);
	}
	std::cout << std::endl;
}
void Test()
{
	//1.存入数据并且打印
	std::vector<int> vec;
	Data(vec);

	//2.快速排序系列测试
	Sort(vec);

	//3.打印已经排序数据
	Put(vec);
}


int main()
 {
	Test();
	return 0;
}