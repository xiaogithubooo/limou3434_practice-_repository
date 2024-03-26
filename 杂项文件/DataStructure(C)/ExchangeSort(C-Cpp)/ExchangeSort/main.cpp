//��������
#include "ExchangeSort.hpp"
#define SIZE 10000

void Data(std::vector<int>& vec)
{
	//1.���������
	std::uniform_int_distribution<int> dist(0, SIZE);//����[0, SIZE]�ľ��ȷֲ�����
	int randomInt;

	//2.������������ݣ�������У�
	for (int i = 0; i < SIZE; i++)
	{
		randomInt = dist(rng);//�����������
		vec.push_back(randomInt);//���������
		printf("%5d ", vec[vec.size() - 1]);
	}

	////3.������������ݣ��������У�
	//std::vector<int> vec;
	//for (int i = 0; i < SIZE; i++)
	//{
	//	vec.push_back(SIZE - i);
	//	printf("%+5d ", vec[i]);
	//}

	//4.����
	std::cout << std::endl << "-----------------------------" << std::endl;
}
void Sort(std::vector<int>& vec)
{
	//2.1.�������Ų���
	//limou::HoareQuickSort(vec, 0, (int)vec.size()-1);
	//2.2.�ڿӿ��Ų���
	//limou::PitfallQuickSort(vec, 0, (int)vec.size() - 1);
	//2.3.ǰ��ָ�����
	//limou::TwoPointerQuickSort(vec, 0, (int)vec.size() - 1);
	//2.4.��·���ֲ���
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
	//1.�������ݲ��Ҵ�ӡ
	std::vector<int> vec;
	Data(vec);

	//2.��������ϵ�в���
	Sort(vec);

	//3.��ӡ�Ѿ���������
	Put(vec);
}


int main()
 {
	Test();
	return 0;
}