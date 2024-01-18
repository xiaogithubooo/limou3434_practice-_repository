#pragma once
#include <iostream>
#include <string>
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
			return (bool)(_bits[i] & (1 << j));
		}

	private:
		std::vector<char> _bits;
	};
}

namespace Limou
{
	//����ҵĹ�ϣ����
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

	//��¡�������ṹ��
	template<size_t N, typename Key = std::string,
		typename Hash1 = BKDRHash,
		typename Hash2 = APHash,
		typename Hash3 = DJBHash>//N �� key �ĸ���
	class BloomFileter
	{
	public:
		void Set(const K& key)
		{
			size_t len = N * _x;

			//ʹ��������ϣ����������λͼ�е�����λ��
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

			//����λ��ֻҪ�����ھ�˵�� key ����
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

			//ע��һ����¡�������������ص㣺
			//key ���ڣ�����ȷ�����п�������
			//key �����ڣ�����ȷ��������������
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