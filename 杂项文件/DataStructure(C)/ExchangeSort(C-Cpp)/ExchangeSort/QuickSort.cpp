//快速排序具体实现
#include "ExchangeSort.h"

template <typename T>
void limou::Hoare_QuickSort(std::vector<T>& vec)
{
	//思想
	;
}

template <typename T>
void limou::Pitfall_QuickSort(std::vector<T>& vec)
{
	int key = vec[0];
	int key_i = 0, left_i = (int)vec.size() - 1, right_i = 0;
	while (left_i < right_i)
	{
		while (left_i < right_i && key >= vec[right_i])//大就循环
		{
			right_i--;
		}
		vec[key_i] = vec[right_i];//这个交换不知道可不可以换成swap()？
		key_i = right_i;

		while (left_i < right_i && key >= vec[left_i])//小就循环
		{
			left_i++;
		}
		vec[key_i] = vec[left_i];//这个交换不知道可不可以换成swap()？
		key_i = left_i;
	}

	//思想：
	//1.选取第一个元素为key，并且记录下来
	//2.从最右边开始查找比key小的数，并停下（大就继续走，等于无所谓）
	//3.然后vec[right_i] = vec[key_i]，更新key_i
	//4.从最左边开始查找比key大的数，并停下（小就继续走，等于无所谓）
	//5.然后vec[left_i] = vec[key_i]，更新key_i
	//6.重复2-5步骤，直到right_i和left_t相遇
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