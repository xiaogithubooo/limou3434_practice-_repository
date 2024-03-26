//�����������ʵ��
#include "ExchangeSort.h"

template <typename T>
void limou::Hoare_QuickSort(std::vector<T>& vec)
{
	//˼��
	;
}

template <typename T>
void limou::Pitfall_QuickSort(std::vector<T>& vec)
{
	int key = vec[0];
	int key_i = 0, left_i = (int)vec.size() - 1, right_i = 0;
	while (left_i < right_i)
	{
		while (left_i < right_i && key >= vec[right_i])//���ѭ��
		{
			right_i--;
		}
		vec[key_i] = vec[right_i];//���������֪���ɲ����Ի���swap()��
		key_i = right_i;

		while (left_i < right_i && key >= vec[left_i])//С��ѭ��
		{
			left_i++;
		}
		vec[key_i] = vec[left_i];//���������֪���ɲ����Ի���swap()��
		key_i = left_i;
	}

	//˼�룺
	//1.ѡȡ��һ��Ԫ��Ϊkey�����Ҽ�¼����
	//2.�����ұ߿�ʼ���ұ�keyС��������ͣ�£���ͼ����ߣ���������ν��
	//3.Ȼ��vec[right_i] = vec[key_i]������key_i
	//4.������߿�ʼ���ұ�key���������ͣ�£�С�ͼ����ߣ���������ν��
	//5.Ȼ��vec[left_i] = vec[key_i]������key_i
	//6.�ظ�2-5���裬ֱ��right_i��left_t����
}

template <typename T>
void limou::TwoPointer_QuickSort(std::vector<T>& vec)
{
	;
}

template <typename T>
void limou::ThreeWay_QuickSort(std::vector<T>& vec)
{
	;
}

template void limou::Pitfall_QuickSort(std::vector<int>& vec);