//al_graph.hpp 邻接表实现
#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <stdexcept>
using std::vector;
using std::string;
using std::cout;
using std::map;
using std::invalid_argument;

namespace limou
{
	template <typename WeightType = int>
	struct Edge
	{
		/*
		* 组织一条顶点对，主要存储终点和权值（也可以有源点）
		*/
		//int _srci; //源点（可选，多重表就可以用这个）
		int _dsti; //终点
		WeightType _weig; //权值
		Edge<WeightType>* _next; //链接指针

		Edge(const int& dsti, const WeightType& weig)
			: _dsti(dsti), _weig(weig), _next(nullptr)
		{}
	};

	template <
		typename VertexType = char, //顶点数据类型
		typename WeightType = int, //权重数据类型
		bool Direction = false //判断是否有向
	>
	class ALGraph
	{
		/*
		* 无向图或有向图（考虑带权值）邻接表模板类，
		* 测试有三种方法：IO 输入、文件读取样例、手动在代码中添加
		*/
	public:
		ALGraph(const vector<VertexType>& arr, size_t arrSize)
		{
			/* 根据顶点序列，初始化邻接表和其他相关信息 */
			_vertexs.reserve(arrSize);
			for (size_t i = 0; i < arrSize; ++i)
			{
				_vertexs.push_back(arr[i]);
				_indexMap[arr[i]] = (int)i;
			}

			_tables.resize(arrSize, nullptr);
		}

		size_t GetVertexIndex(const VertexType& v)
		{
			/* 返回顶点对应的索引，并且有检查机制，防止用户输错顶点 */
			auto it = _indexMap.find(v);
			if (it != _indexMap.end())
			{
				return it->second;
			}
			throw invalid_argument("顶点不存在");//运行时报错
			return -1;//防止编译器警告
		}

		void AddEdge(const VertexType& src, const VertexType& dst, const WeightType& w)
		{
			/* 添加边以及对应的权值 */
			size_t srci = GetVertexIndex(src); //找到源点对应的索引
			size_t dsti = GetVertexIndex(dst); //找到源点对应的索引

			Edge<WeightType>* eg = new Edge<WeightType>((int)dsti, w); //头插
			eg->_next = _tables[srci];
			_tables[srci] = eg;

			if (Direction == false) //如果是无向图还需要进一步镜像处理
			{
				Edge<WeightType>* eg = new Edge<WeightType>((int)srci, w); //头插
				eg->_next = _tables[dsti];
				_tables[dsti] = eg;
			}
		}

		void Print()
		{
			/* 打印顶点集合和邻接表来测试（只限于 int 类型的顶点数据） */
			//打印顶点表
			int i = 0;
			for (auto ver : _vertexs)
			{
				cout << ver << " ";
			}
			cout << '\n';

			//打印邻接表
			for (size_t i = 0; i < _tables.size(); ++i)
			{
				cout << "[" << i << "]" << _vertexs[i] << ":" << "->";
				Edge<WeightType>* cur = _tables[i];
				while (cur)
				{
					cout << "[" << cur->_dsti << "]" << "\"" << cur->_weig << "\"" << "->";
					cur = cur->_next;
				}
				cout << "nullptr" << '\n';
			}
			cout << '\n';
		}

	private:
		vector<VertexType> _vertexs; //顶点表
		map<VertexType, int> _indexMap; //顶点映射下标（主要是用来提高效率的）
		vector<Edge<int>*> _tables; //邻接表（有向图时只存储出度弧的正邻接表）
	};

	void TestALGraph()
	{
		string str = "ABCDE";
		vector<char> vec(str.begin(), str.end());
		ALGraph<char, int, true> amg(vec, 5);
		amg.AddEdge('A', 'E', 11);
		amg.AddEdge('B', 'E', 20);
		amg.AddEdge('C', 'E', 34);
		amg.AddEdge('D', 'E', 93);
		amg.AddEdge('A', 'C', 69);
		amg.AddEdge('A', 'B', 76);
		amg.Print();
	}
}