#pragma once
#include "RBTree.hpp"
namespace limou
{
	template<class K>
	class Set
	{
	private://�ڲ��ࣨ��������
		struct SetKeyOfT
		{
			const K& operator()(const K& key)
			{
				return key;//����ȡ�� key������Ϊ�˺� map ͬ��
			}
		};

	public://������
		typedef typename RBTree<K, K, SetKeyOfT>::iterator iterator;//��ȡ��������Ƕ������Ҫ�õ�typename����Ȼ�޷������Ǿ�̬��Ա�������ͣ�
		iterator begin()
		{
			return _t.begin();
		}
		iterator end()
		{
			return _t.end();
		}

	public://��Ա����
		std::pair<iterator, bool> Insert(const K& key)
		{
			return _t.Insert(key);
		}

	private://��Ա����
		RBTree<K, K, SetKeyOfT> _t;
	};

	//���Ժ���
	void test_set()
	{
		Set<int> s;
		s.Insert(3);
		s.Insert(1);
		s.Insert(2);
		s.Insert(10);
		s.Insert(4);
		s.Insert(100);
		s.Insert(5);

		for (auto e : s)
		{
			std::cout << e << " ";
		}
		std::cout << std::endl;
	}
}