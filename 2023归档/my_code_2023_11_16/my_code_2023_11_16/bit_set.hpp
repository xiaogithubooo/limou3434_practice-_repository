#pragma once
#include <iostream>
#include <string>
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
			return (bool)(_bits[i] & (1 << j));
		}

	private:
		std::vector<char> _bits;
	};
}

namespace Limou
{
	//随便找的哈希函数
	struct BKDRHash
	{
		size_t operator()(const std::string& str)
		{
			size_t hash = 0;
			for (auto ch : str)
			{
				hash += ch;
				hash *= 31;
			}
			return hash;
		}
	};
	struct APHash
	{
		size_t operator()(const std::string& str)
		{
			size_t hash = 0;
			for (long i = 0; i < str.size(); i++)
			{
				size_t ch = str[i];
				if ((i & 1) == 0)
				{
					hash ^= ((hash << 7) ^ ch ^ (hash >> 3));
				}
				else
				{
					hash ^= (~((hash << 11) ^ ch ^ (hash >> 5)));
				}
			}
			return hash;
		}
	};
	struct DJBHash
	{
		size_t operator()(const std::string& str)
		{
			size_t hash = 5381;
			for (auto ch : str)
			{
				hash += (hash << 5) + ch;
			}
			return hash;
		}
	};

	//布隆过滤器结构体
	template<size_t N, typename Key = std::string,
		typename Hash1 = BKDRHash,
		typename Hash2 = APHash,
		typename Hash3 = DJBHash>//N 是 key 的个数
	class BloomFileter
	{
	public:
		void Set(const K& key)
		{
			size_t len = N * _x;

			//使用三个哈希函数，设置位图中的三个位置
			size_t hash1 = Hash1()(Key) % len;
			_bs.Set(hash1);
			size_t hash2 = Hash2()(Key) % len;
			_bs.Set(hash2);
			size_t hash3 = Hash3()(Key) % len;
			_bs.Set(hash3);
		}
		bool Test(const K& key)
		{
			size_t len = N * _x;

			//三个位置只要都存在就说明 key 存在
			size_t hash1 = Hash1()(Key) % len;
			if (!_bs.test(hash1))
			{
				return false;
			}
			size_t hash2 = Hash2()(Key) % len;
			if (!_bs.test(hash2))
			{
				return false;
			}
			size_t hash3 = Hash3()(Key) % len;
			if (!_bs.test(hash3))
			{
				return false;
			}

			//注意一个布隆过滤器有以下特点：
			//key 存在，不能确定，有可能误判
			//key 不存在，可以确定，不存在误判
			return true;
		}

	private:
		static const size_t _x = 4;
		BitSet<N * _x> _bs;
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