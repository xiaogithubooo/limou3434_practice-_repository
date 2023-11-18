#pragma once
#include <iostream>
#include <vector>
#include <cassert>
namespace Limou
{
	template<size_t N>//非类型模板参数 N
	class BitSet
	{
	public:
		BitSet()
		{
			_bits.resize(N / 8 + 1, 0);//可以浪费几个比特位，但是不可以缺少
		}

		//0000 0000

		void Set(size_t x)//设置为 1
		{
			assert(x < N);
			size_t i = x / 8;//计算出 x 映射到数组中第 i 个 char 数据
			size_t j = x % 8;//计算出 x 映射到第 i 个 char 中的第 j 个比特位
			_bits[i] |= (1 << j);//设置为 1
		}

		void Reset(size_t x)//设置为 0
		{
			assert(x < N);
			size_t i = x / 8;//计算出 x 映射到数组中第 i 个 char 数据
			size_t j = x % 8;//计算出 x 映射到第 i 个 char 中的第 j 个比特位
			_bits[i] &= ~(1 << j);//设置为 0
		}

		bool Test(size_t x)
		{
			assert(x < N);
			size_t i = x / 8;//计算出 x 映射到数组中第 i 个 char 数据
			size_t j = x % 8;//计算出 x 映射到第 i 个 char 中的第 j 个比特位
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
			//00 代表什么都没有
			//01 代表出现了一次
			//00 代表两次及以上
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