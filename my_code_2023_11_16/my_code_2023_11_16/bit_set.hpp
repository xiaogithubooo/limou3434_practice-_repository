#pragma once
#include <iostream>
#include <vector>
#include <cassert>
namespace Limou
{
	template<size_t N>//������ģ����� N
	class BitSet
	{
	public:
		BitSet()
		{
			_bits.resize(N / 8 + 1, 0);//�����˷Ѽ�������λ�����ǲ�����ȱ��
		}

		//0000 0000

		void Set(size_t x)//����Ϊ 1
		{
			assert(x < N);
			size_t i = x / 8;//����� x ӳ�䵽�����е� i �� char ����
			size_t j = x % 8;//����� x ӳ�䵽�� i �� char �еĵ� j ������λ
			_bits[i] |= (1 << j);//����Ϊ 1
		}

		void Reset(size_t x)//����Ϊ 0
		{
			assert(x < N);
			size_t i = x / 8;//����� x ӳ�䵽�����е� i �� char ����
			size_t j = x % 8;//����� x ӳ�䵽�� i �� char �еĵ� j ������λ
			_bits[i] &= ~(1 << j);//����Ϊ 0
		}

		bool Test(size_t x)
		{
			assert(x < N);
			size_t i = x / 8;//����� x ӳ�䵽�����е� i �� char ����
			size_t j = x % 8;//����� x ӳ�䵽�� i �� char �еĵ� j ������λ
			return _bits[i] & (1 << j);
		}

	private:
		std::vector<char> _bits;
	};
}

namespace Limou
{
	template<size_t N>
	class TwoBitSet
	{
	public:
		void Set(size_t x)
		{
			//00 ����ʲô��û��
			//01 ���������һ��
			//00 �������μ�����
			if (_bs1.Test(x) == false && _bs2.Test(x) == false)//00 -> 01
			{
				_bs2.Set(x);
			}
			else if (_bs1.Test(x) == false && _bs2.Test(x) == true)//01 -> 10
			{
				_bs1.Set(x);
				_bs2.Reset(x);
			}
		}

		void Print()
		{
			for (size_t i = 1; i < N; i++)
			{
				if (_bs2.Test(i))
				{
					std::cout << i << '\n';
				}
			}
		}

	private:
		BitSet<N> _bs1;
		BitSet<N> _bs2;
	};
}