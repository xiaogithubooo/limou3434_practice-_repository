#pragma once
#include <vector>
namespace Limou
{
	template<size_t N>//������ģ����� N ��ָ��Ҫ�ı���λ��С
	class BitSet
	{
	public:
		BitSet()
		{
			_bits.resize(N / 8 + 1, 0)//�����˷Ѽ�������λ�����ǲ�����ȱ��
		}

		void Set(size_t x)//����Ϊ 1
		{
			size_t i = x / 8;//����� x ӳ�䵽�����е� i �� char ����
			size_t j = x % 8;//����� x ӳ�䵽�� i �� char �еĵ� j ������λ
			_bits[i] |= (1 << j);//����Ϊ 1
		}

		void Reset(size_t x)//����Ϊ 0
		{
			size_t i = x / 8;//����� x ӳ�䵽�����е� i �� char ����
			size_t j = x % 8;//����� x ӳ�䵽�� i �� char �еĵ� j ������λ
			_bits[i] &= ~(1 << j);//����Ϊ 0
		}
	private:
		std::vector<char> _bits;
	};
}