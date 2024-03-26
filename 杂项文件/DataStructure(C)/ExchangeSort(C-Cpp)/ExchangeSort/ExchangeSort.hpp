//ͷ�ļ�
#pragma once
#include <iostream>
#include <vector>
#include <stack>
#include <cassert>
#include <algorithm>
#include <random>

//0.�Ż�����
//#define ADJUST_THREE_MID 1	//����ȡ�п��أ�ȱʡ��
#define ADJUST_RAN_MID 1		//���ȡ�п���
#define Recursion 1			//�ݹ���ÿ���
//#define NoRecursion 1			//�ǵݹ���ÿ���

std::random_device rd;//������������
std::mt19937 rng(rd());//������������ (Mersenne Twister�㷨)

//1.����ȡ��
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
//2.���ȡ��
template <typename T>
void _AdjustRanMid(std::vector<T>& vec, int left_i, int right_i)
{
	int li = left_i + 1;
	int ri = right_i - 1;
	if (li >= ri)
	{
		return;
	}
	std::uniform_int_distribution<int> dist(li, ri);//����[left_i+1,right_i-1]�ľ��ȷֲ�����
	int randomInt = dist(rng);//�����������

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
	//1.ð������
	//1.1.��ͨð��
	template <typename T>
	void Ord_BubbleSort(std::vector<T>& vec, int left_i, int right_i)
	{
		//˼·����������[4,3,2,1]
		//ð��1�Σ�3,2,1,4
		//ð��2�Σ�2,1,3,4
		//ð��3�Σ�1,2,3,4
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

	//1.2.�Ż�ð��
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
	
	//2.��������
	//2.1.��������
	template <typename T>
	int _Hoare_QuickSort(std::vector<T>& vec, int left_i, int right_i)
	{
		//˼�룺
		//1.ѡȡ��һ��Ԫ��Ϊkey�����Ҽ�¼����key_i
		//2.�����ҿ�ʼѰ�ұ�keyС��������ͣ����
		//3.������ʼѰ�ұ�key���������ͣ���������ﱣ��һ���ɻ�
		//4.swap(vec[left_i], vec[right_i])
		//6.�����ظ�2-5����
		//7.���swap(vec[left_i], vec[key_i])
		//7.1.����left_i����right_i����ʱright_i��λ�ÿ϶���keyС����Ϊֻ�м�⵽vec[right_i]<key������ŻῪʼ��left_i��
		//7.2.����right_i����left_i
		//7.2.1.��ʱҪôright_iһֱ�ߵ�һ��ʼ��key_iλ�ã�Ҳ��������left_iû��������Ҳ����Ϊʲôleft_iҪ������ʼ��
		//7.2.2.Ҫô�й�һЩ�ִΣ�right_iһֱ�ߵ�left_i��λ�ã���ʱvec[left_i]һ���keyС
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
		s.push(left_i);//��
		s.push(right_i);//��
		while (!s.empty())
		{
			int end = s.top();//�� 
			s.pop();
			int begin = s.top();//��
			s.pop();

			int key_i = _Hoare_QuickSort(vec, begin, end);
			//[begin, key_i - 1] key_i [key_i + 1, end]
			if (begin < key_i - 1)
			{
				s.push(begin);//��
				s.push(key_i - 1);//��
			}
			if (key_i + 1 < end)
			{
				s.push(key_i + 1);//��
				s.push(end);//��
			}
		}
#endif
	}
	template <typename T>
	void HoareQuickSort(std::vector<T>& vec, int x, int y)
	{
		//��ǰ���Խ��
		if(x >= y)
			return;
#ifdef ADJUST_THREE_MID
		//��������ȡ��
		_AdjustThreeMid(vec, x, y);
#elif ADJUST_RAN_MID
		//�������ȡ��
		_AdjustRanMid(vec, x, y);
#endif
		Hoare_QuickSort(vec, x, y);
	}
	//2.2.�ڿӿ���
	template <typename T>
	int _Pitfall_QuickSort(std::vector<T>& vec, int left_i, int right_i)
	{
		//˼�룺
		//1.ѡȡ��һ��Ԫ��Ϊkey�����Ҽ�¼����
		//2.�����ұ߿�ʼ���ұ�keyС��������ͣ�£���ͼ����ߣ���������ν��
		//3.Ȼ��vec[key_i] = vec[right_i]������key_i = right_i
		//4.������߿�ʼ���ұ�key���������ͣ�£�С�ͼ����ߣ���������ν��
		//5.Ȼ��vec[right_i] = vec[left_i]������key_i = left_i
		//6.�ظ�2-5���裬ֱ��right_i��left_t����
		int key = vec[left_i];
		int key_i = left_i;
		while (left_i < right_i)
		{
			while (left_i < right_i && key <= vec[right_i])//���ѭ��
			{
				right_i--;
			}
			vec[key_i] = vec[right_i];
			key_i = right_i;

			while (left_i < right_i && key >= vec[left_i])//С��ѭ��
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
		s.push(left_i);//��
		s.push(right_i);//��
		while (!s.empty())
		{
			int end = s.top();//�� 
			s.pop();
			int begin = s.top();//��
			s.pop();

			int key_i = _Pitfall_QuickSort(vec, begin, end);
			//[begin, key_i - 1] key_i [key_i + 1, end]
			if (begin < key_i - 1)
			{
				s.push(begin);//��
				s.push(key_i - 1);//��
			}
			if (key_i + 1 < end)
			{
				s.push(key_i + 1);//��
				s.push(end);//��
			}
		}
#endif
	}
	template <typename T>
	void PitfallQuickSort(std::vector<T>& vec, int x, int y)
	{
		//��ǰ���Խ��
		if (x >= y)
			return;
#ifdef ADJUST_THREE_MID
		//��������ȡ��
		_AdjustThreeMid(vec, x, y);
#elif ADJUST_RAN_MID
		//�������ȡ��
		_AdjustRanMid(vec, x, y);
#endif
		Pitfall_QuickSort(vec, x, y);
	}
	//2.3.ǰ��ָ�����
	template <typename T>
	int _TwoPointer_QuickSort(std::vector<T>& vec, int left_i, int right_i)
	{
		//˼·��
		//1.�ȼ�¼key_i��key��ֵ
		//2.��������ָ�룬һ����behind_i = key_i���͡�front_i = behind_i + 1����ע�������behind_i���������߿�ʼ�����ֱ���趨��behind = key_i + 1������ô��һ��ѭ����ʱ�����vec[behind_i]��ֵ��keyҪ�󣬶�����front_i������Ԫ�ر�keyС����ʱswap(vec[++behind_i],vec[front_i])�ͻᷢ�����������б���ס�ı�key���Ԫ���о���©��һ��Ԫ�أ�
		//3.Ȼ��front_iһֱ����ߣ�ֱ��Խ���������vec[front_i] < key��ͣ����
		//4.ʹ�ý�������swap(vec[++behind_i], vec[front_i])
		//5.ѭ����������...��������(behind_i,front_i]�ڵ�ֵ���Ǳ�keyҪ���ֵ
		//6.���behind_iͣ�µĵط�һ���Ǳ�keyС���ߵ��ڵģ�swap(vec[behind_i], vec[key_i]])
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
		s.push(left_i);//��
		s.push(right_i);//��
		while (!s.empty())
		{
			int end = s.top();//�� 
			s.pop();
			int begin = s.top();//��
			s.pop();

			int key_i = _TwoPointer_QuickSort(vec, begin, end);
			//[begin, key_i - 1] key_i [key_i + 1, end]
			if (begin < key_i - 1)
			{
				s.push(begin);//��
				s.push(key_i - 1);//��
			}
			if (key_i + 1 < end)
			{
				s.push(key_i + 1);//��
				s.push(end);//��
			}
		}
#endif
	}
	template <typename T>
	void TwoPointerQuickSort(std::vector<T>& vec, int x, int y)
	{
		//��ǰ���Խ��
		if (x >= y)
			return;
#ifdef ADJUST_THREE_MID
		//��������ȡ��
		_AdjustThreeMid(vec, x, y);
#elif ADJUST_RAN_MID
		//�������ȡ��
		_AdjustRanMid(vec, x, y);
#endif
		TwoPointer_QuickSort(vec, x, y);
	}
	//2.4.��·���ֿ���
	template <typename T>
	void ThreeWayQuickSort(std::vector<T>& vec, int left, int right)
	{
		//��ǰ���Խ��
		if (left >= right)
			return;
#ifdef ADJUST_THREE_MID
		//��������ȡ��
		_AdjustThreeMid(vec, left, right);
#elif ADJUST_RAN_MID
		//�������ȡ��
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
