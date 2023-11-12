#pragma once
#include "RBTree.hpp"
namespace limou
{
	template<class K, class V>
	class Map
	{
	private://内部类（泛函数）
		struct MapKeyOfT
		{
			const K& operator()(const std::pair<const K, V>& kv)
			{
				return kv.first;//可以取出 key 的部分
			}
		};

	public://迭代器
		typedef typename RBTree<K, std::pair<const K, V>, MapKeyOfT>::iterator iterator;//获取别的类的内嵌类型需要用到typename（不然无法区分是静态成员还是类型）
		iterator begin()
		{
			return _t.begin();
		}
		iterator end()
		{
			return _t.end();
		}

	public://成员函数
		std::pair<iterator, bool> Insert(const std::pair<const K, V>& kv)
		{
			return _t.Insert(kv);
		}
		V& operator[](const K& key)
		{
			std::pair<iterator, bool> ret = _t.Insert(std::make_pair(key, V()));
			return ret.first->second;
		}

	private://成员变量
		RBTree<K, std::pair<const K, V>, MapKeyOfT> _t;
	};

	//测试函数
	void test_map()
	{
		Map<int, int> m1;
		m1.Insert(std::make_pair(1, 1));
		m1.Insert(std::make_pair(3, 1));
		m1.Insert(std::make_pair(4, 1));
		m1.Insert(std::make_pair(2, 1));
		m1.Insert(std::make_pair(10, 1));
		m1.Insert(std::make_pair(50, 1));
		m1.Insert(std::make_pair(0, 1));

		for (auto e : m1)
		{
			std::cout <<  "<" << e.first << "," << e.second << ">" << " ";
		}
		std::cout << std::endl;

		Map<std::string, int> m2;
		std::vector<std::string> arr = { "红色", "白色", "绿色", "红色", "黑色", "黑色", "红色", "红色" };
		for (auto e : arr)
		{
			m2[e]++;
		}

		for (auto e : m2)
		{
			std::cout << "<" << e.first << "," << e.second << ">" << std::endl;
		}
	}
}