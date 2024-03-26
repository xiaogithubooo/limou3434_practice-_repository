//头文件
#pragma once
#include <iostream>
#include <vector>
#include <stack>
#include <cassert>
#include <algorithm>
#include <random>

//0.优化开关
//#define ADJUST_THREE_MID 1	//三数取中开关（缺省）
#define ADJUST_RAN_MID 1		//随机取中开关
#define Recursion 1			//递归调用开关
//#define NoRecursion 1			//非递归调用开关

std::random_device rd;//用于种子生成
std::mt19937 rng(rd());//随机数引擎对象 (Mersenne Twister算法)

//1.三数取中
template <typename T>
void _AdjustThreeMid(std::vector<T>& vec, int left_i, int right_i)
{
	int x = vec[left_i];
	int y = vec[(left_i + right_i) >> 1];
	int z = vec[right_i];
	if ((y > x && y < z) || (y > z && y < x))
	{
		std::swap(vec[left_i], vec[left_i + right_i >> 1]);
	}
	else if ((z > x && z < y) || (z > y && z < x))
	{
		std::swap(vec[left_i], vec[right_i]);
	}
}
//2.随机取中
template <typename T>
void _AdjustRanMid(std::vector<T>& vec, int left_i, int right_i)
{
	int li = left_i + 1;
	int ri = right_i - 1;
	if (li >= ri)
	{
		return;
	}
	std::uniform_int_distribution<int> dist(li, ri);//生成[left_i+1,right_i-1]的均匀分布整数
	int randomInt = dist(rng);//生成随机整数

	int x = vec[left_i];
	int y = vec[randomInt];
	int z = vec[right_i];
	if ((y > x && y < z) || (y > z && y < x))
	{
		std::swap(vec[left_i], vec[(left_i + right_i) >> 1]);
	}
	else if ((z > x && z < y) || (z > y && z < x))
	{
		std::swap(vec[left_i], vec[right_i]);
	}
}

namespace limou
{
	//1.冒泡排序
	//1.1.普通冒泡
	template <typename T>
	void Ord_BubbleSort(std::vector<T>& vec, int left_i, int right_i)
	{
		//思路：例如序列[4,3,2,1]
		//冒泡1次：3,2,1,4
		//冒泡2次：2,1,3,4
		//冒泡3次：1,2,3,4
		for (int j = 0; j < right_i - left_i; j++)
		{
			for (int i = left_i; i < right_i - j; i++)
			{
 				if (vec[i] > vec[i + 1])
				{
					std::swap(vec[i], vec[i + 1]);
				}
			}
		}
	}
	template <typename T>
	void OrdBubbleSort(std::vector<T>& vec = {}, int x = 0, int y = 0)
	{
		y = vec.size() - 1;
		Ord_BubbleSort(vec, x, y);
	}

	//1.2.优化冒泡
	template <typename T>
	void Opt_BubbleSort(std::vector<T>& vec, int left_i, int right_i)
	{
		int flag = 0;
		for (int j = 0; j < right_i - left_i; j++)
		{
			for (int i = left_i; i < right_i - j; i++)
			{
				if (vec[i] > vec[i + 1])
				{
					std::swap(vec[i], vec[i + 1]);
					flag = 1;
				}
			}
			if (0 == flag) return;
		}
	}
	template <typename T>
	void OptBubbleSort(std::vector<T>& vec = {}, int x = 0, int y = 0)
	{
		y = vec.size() - 1;
		Opt_BubbleSort(vec, x, y);
	}
	
	//2.快速排序
	//2.1.霍尔快排
	template <typename T>
	int _Hoare_QuickSort(std::vector<T>& vec, int left_i, int right_i)
	{
		//思想：
		//1.选取第一个元素为key，并且记录下来key_i
		//2.从最右开始寻找比key小的数，并停下来
		//3.从最左开始寻找比key大的数，并停下来（这里保留一个疑惑）
		//4.swap(vec[left_i], vec[right_i])
		//6.不断重复2-5步骤
		//7.最后swap(vec[left_i], vec[key_i])
		//7.1.假设left_i遇到right_i，此时right_i的位置肯定比key小（因为只有检测到vec[right_i]<key，这里才会开始走left_i）
		//7.2.假设right_i遇到left_i
		//7.2.1.此时要么right_i一直走到一开始的key_i位置（也就是最左，left_i没动过，这也就是为什么left_i要从最左开始）
		//7.2.2.要么有过一些轮次，right_i一直走到left_i的位置，此时vec[left_i]一点比key小
		int key = vec[left_i];
		int key_i = left_i;
		while (left_i < right_i)
		{
			while (left_i < right_i && vec[right_i] >= key)
			{
				right_i--;
			}
			while (left_i < right_i && vec[left_i] <= key)
			{
				left_i++;
			}
			std::swap(vec[right_i], vec[left_i]);
		}
		std::swap(vec[left_i], vec[key_i]);
		return left_i;
	}
	template <typename T>
	void Hoare_QuickSort(std::vector<T>& vec, int left_i, int right_i)
	{
#ifdef Recursion
		if (left_i >= right_i)
		{
			return;
		}
		int key_i = _Hoare_QuickSort(vec, left_i, right_i);
		//[letf_i, key_i - 1] key_i [key_i + 1, right_i]
		Hoare_QuickSort(vec, left_i, key_i - 1);
		Hoare_QuickSort(vec, key_i + 1, right_i);
#elif NoRecursion
		std::stack<int> s;
		s.push(left_i);//左
		s.push(right_i);//右
		while (!s.empty())
		{
			int end = s.top();//右 
			s.pop();
			int begin = s.top();//左
			s.pop();

			int key_i = _Hoare_QuickSort(vec, begin, end);
			//[begin, key_i - 1] key_i [key_i + 1, end]
			if (begin < key_i - 1)
			{
				s.push(begin);//左
				s.push(key_i - 1);//右
			}
			if (key_i + 1 < end)
			{
				s.push(key_i + 1);//左
				s.push(end);//右
			}
		}
#endif
	}
	template <typename T>
	void HoareQuickSort(std::vector<T>& vec, int x, int y)
	{
		//提前检查越界
		if(x >= y)
			return;
#ifdef ADJUST_THREE_MID
		//调用三数取中
		_AdjustThreeMid(vec, x, y);
#elif ADJUST_RAN_MID
		//调用随机取中
		_AdjustRanMid(vec, x, y);
#endif
		Hoare_QuickSort(vec, x, y);
	}
	//2.2.挖坑快排
	template <typename T>
	int _Pitfall_QuickSort(std::vector<T>& vec, int left_i, int right_i)
	{
		//思想：
		//1.选取第一个元素为key，并且记录下来
		//2.从最右边开始查找比key小的数，并停下（大就继续走，等于无所谓）
		//3.然后vec[key_i] = vec[right_i]，更新key_i = right_i
		//4.从最左边开始查找比key大的数，并停下（小就继续走，等于无所谓）
		//5.然后vec[right_i] = vec[left_i]，更新key_i = left_i
		//6.重复2-5步骤，直到right_i和left_t相遇
		int key = vec[left_i];
		int key_i = left_i;
		while (left_i < right_i)
		{
			while (left_i < right_i && key <= vec[right_i])//大就循环
			{
				right_i--;
			}
			vec[key_i] = vec[right_i];
			key_i = right_i;

			while (left_i < right_i && key >= vec[left_i])//小就循环
			{
				left_i++;
			}
			vec[key_i] = vec[left_i];
			key_i = left_i;
		}
		vec[key_i] = key;
		return key_i;
	}
	template <typename T>
	void Pitfall_QuickSort(std::vector<T>& vec, int left_i, int right_i)
	{
#ifdef Recursion
		if (left_i >= right_i)
		{
			return;
		}
		int key_i = _Pitfall_QuickSort(vec, left_i, right_i);
		//[left_i, key_i - 1] key_i [key_i + 1, right_i]
		Pitfall_QuickSort(vec, left_i, key_i - 1);
		Pitfall_QuickSort(vec, key_i + 1, right_i);
#elif NoRecursion
		std::stack<int> s;
		s.push(left_i);//左
		s.push(right_i);//右
		while (!s.empty())
		{
			int end = s.top();//右 
			s.pop();
			int begin = s.top();//左
			s.pop();

			int key_i = _Pitfall_QuickSort(vec, begin, end);
			//[begin, key_i - 1] key_i [key_i + 1, end]
			if (begin < key_i - 1)
			{
				s.push(begin);//左
				s.push(key_i - 1);//右
			}
			if (key_i + 1 < end)
			{
				s.push(key_i + 1);//左
				s.push(end);//右
			}
		}
#endif
	}
	template <typename T>
	void PitfallQuickSort(std::vector<T>& vec, int x, int y)
	{
		//提前检查越界
		if (x >= y)
			return;
#ifdef ADJUST_THREE_MID
		//调用三数取中
		_AdjustThreeMid(vec, x, y);
#elif ADJUST_RAN_MID
		//调用随机取中
		_AdjustRanMid(vec, x, y);
#endif
		Pitfall_QuickSort(vec, x, y);
	}
	//2.3.前后指针快排
	template <typename T>
	int _TwoPointer_QuickSort(std::vector<T>& vec, int left_i, int right_i)
	{
		//思路：
		//1.先记录key_i和key的值
		//2.创建两个指针，一个“behind_i = key_i”和“front_i = behind_i + 1”（注意这里的behind_i必须从最左边开始，如果直接设定“behind = key_i + 1”，那么第一次循环的时候，如果vec[behind_i]的值比key要大，而后面front_i遇到的元素比key小，此时swap(vec[++behind_i],vec[front_i])就会发生错误，在所有被框住的比key大的元素中就遗漏了一个元素）
		//3.然后front_i一直向后走，直到越界或者满足vec[front_i] < key就停下来
		//4.使用交换函数swap(vec[++behind_i], vec[front_i])
		//5.循环上述过程...整过程中(behind_i,front_i]内的值都是比key要大的值
		//6.最后behind_i停下的地方一定是比key小或者等于的，swap(vec[behind_i], vec[key_i]])
		int key_i = left_i;
		int key = vec[left_i];

		int behind_i = left_i;
		int front_i = behind_i + 1;
		while (front_i <= right_i)
		{
			if (vec[front_i] < key)
			{
				std::swap(vec[++behind_i], vec[front_i]);
			}
			front_i++;
		}
		std::swap(vec[behind_i], vec[key_i]);
		return behind_i;
	}
	template <typename T>
	void TwoPointer_QuickSort(std::vector<T>& vec, int left_i, int right_i)
	{
#ifdef Recursion
		if (left_i >= right_i)
		{
			return;
		}
		int key_i = _TwoPointer_QuickSort(vec, left_i, right_i);
		//[left_i, key_i - 1] key_i [key_i + 1, right_i]
		TwoPointer_QuickSort(vec, left_i, key_i - 1);
		TwoPointer_QuickSort(vec, key_i + 1, right_i);
#elif NoRecursion
		std::stack<int> s;
		s.push(left_i);//左
		s.push(right_i);//右
		while (!s.empty())
		{
			int end = s.top();//右 
			s.pop();
			int begin = s.top();//左
			s.pop();

			int key_i = _TwoPointer_QuickSort(vec, begin, end);
			//[begin, key_i - 1] key_i [key_i + 1, end]
			if (begin < key_i - 1)
			{
				s.push(begin);//左
				s.push(key_i - 1);//右
			}
			if (key_i + 1 < end)
			{
				s.push(key_i + 1);//左
				s.push(end);//右
			}
		}
#endif
	}
	template <typename T>
	void TwoPointerQuickSort(std::vector<T>& vec, int x, int y)
	{
		//提前检查越界
		if (x >= y)
			return;
#ifdef ADJUST_THREE_MID
		//调用三数取中
		_AdjustThreeMid(vec, x, y);
#elif ADJUST_RAN_MID
		//调用随机取中
		_AdjustRanMid(vec, x, y);
#endif
		TwoPointer_QuickSort(vec, x, y);
	}
	//2.4.三路划分快排
	template <typename T>
	void ThreeWayQuickSort(std::vector<T>& vec, int left, int right)
	{
		//提前检查越界
		if (left >= right)
			return;
#ifdef ADJUST_THREE_MID
		//调用三数取中
		_AdjustThreeMid(vec, left, right);
#elif ADJUST_RAN_MID
		//调用随机取中
		_AdjustRanMid(vec, left, right);
#endif

		int left_i = left;
		int right_i = right;
		int cur_i = left_i;
		int key = vec[left_i];
		while (cur_i <= right_i)
		{
			if (vec[cur_i] == key)
			{
				cur_i++;
			}
			else if (vec[cur_i] < key)
			{
				std::swap(vec[cur_i], vec[left_i]);
				left_i++;
			}
			else
			{
				std::swap(vec[cur_i], vec[right_i]);
				right_i--;
			}
		}
		//[left, left_i-1][left_i, right_i][right_i+1, right]
		ThreeWayQuickSort(vec, left, left_i - 1);
		ThreeWayQuickSort(vec, right_i + 1, right);
	}
}
