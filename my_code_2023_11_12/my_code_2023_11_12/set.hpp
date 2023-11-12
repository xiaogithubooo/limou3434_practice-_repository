#pragma once
#include "RBTree.hpp"
namespace limou
{
	template<class K>
	class Set
	{
	private://内部类（泛函数）
		struct SetKeyOfT
		{
			const K& operator()(const K& key)
			{
				return key;//可以取出 key，这是为了和 map 同步
			}
		};

	public://迭代器
		typedef typename RBTree<K, K, SetKeyOfT>::iterator iterator;//获取别的类的内嵌类型需要用到typename（不然无法区分是静态成员还是类型）
		iterator begin()
		{
			return _t.begin();
		}
		iterator end()
		{
			return _t.end();
		}

	public://成员函数
		std::pair<iterator, bool> Insert(const K& key)
		{
			return _t.Insert(key);
		}

	private://成员变量
		RBTree<K, K, SetKeyOfT> _t;
	};

	//测试函数
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