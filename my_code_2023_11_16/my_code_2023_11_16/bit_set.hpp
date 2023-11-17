#pragma once
#include <vector>
namespace Limou
{
	template<size_t N>//非类型模板参数 N ，指需要的比特位大小
	class BitSet
	{
	public:
		BitSet()
		{
			_bits.resize(N / 8 + 1, 0)//可以浪费几个比特位，但是不可以缺少
		}

		void Set(size_t x)//设置为 1
		{
			size_t i = x / 8;//计算出 x 映射到数组中第 i 个 char 数据
			size_t j = x % 8;//计算出 x 映射到第 i 个 char 中的第 j 个比特位
			_bits[i] |= (1 << j);//设置为 1
		}

		void Reset(size_t x)//设置为 0
		{
			size_t i = x / 8;//计算出 x 映射到数组中第 i 个 char 数据
			size_t j = x % 8;//计算出 x 映射到第 i 个 char 中的第 j 个比特位
			_bits[i] &= ~(1 << j);//设置为 0
		}
	private:
		std::vector<char> _bits;
	};
}