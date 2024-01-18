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
		//这里的 iterator 实际上也是常量迭代器，由于 set 容器为了满足二叉搜索性质，
		//不能改动 key，而我们设计的迭代器器会返回可以修改的迭代器，一旦允许改动，
		//就会出现 bug，因此干脆返回一个常量迭代器，伪装成普通迭代器
		typedef typename RBTree<K, K, SetKeyOfT>::const_iterator iterator;
		//注意获取别的类的内嵌类型需要用到 typename（不然无法区分是静态成员还是类型）
		typedef typename RBTree<K, K, SetKeyOfT>::const_iterator const_iterator;
		
		iterator begin()
		{
			//一旦上述普通迭代器成为常量迭代器的伪装，
			//这里调用的还是普通迭代器 begin()，
			//无法转为常量迭代器来作为函数返回值返回，
			//因此就需要将普通迭代器转化为常量迭代器
			//转化方法就是在 __RBTreeIterator 中，
			//多写一个用于转化的构造函数
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