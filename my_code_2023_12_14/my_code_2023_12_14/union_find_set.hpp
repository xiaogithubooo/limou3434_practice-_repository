#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <stdexcept>
#include <climits>
#include <cstdio>
using std::vector;
using std::string;
using std::cout;
using std::map;
using std::invalid_argument;

namespace limou
{
	template <
		typename VertexType = char, //顶点数据类型
		typename WeightType = int, //权重数据类型
		WeightType MAX_W = INT_MAX, //表示无穷的数
		bool Direction = false //判断是否有向
	>
	class AMGraph
	{
		/*
		* 无向图或有向图（考虑带权值）模板类，
		* 测试有三种方法：IO 输入、文件读取样例、手动在代码中添加
		*/
	public:
		AMGraph(const vector<VertexType>& arr, size_t arrSize)
		{
			/* 根据顶点序列，初始化邻接矩阵和其他相关信息 */
			_vertexs.reserve(arrSize);
			for (size_t i = 0; i < arrSize; ++i)
			{
				_vertexs.push_back(arr[i]);
				_indexMap[arr[i]] = (int)i;
			}

			_weights.resize(arrSize);
			for (size_t i = 0; i < arrSize; i++)
			{
				_weights[i].resize(arrSize, MAX_W);
			}
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
			size_t srci = GetVertexIndex(src);
			size_t dsti = GetVertexIndex(dst);

			_weights[srci][dsti] = w;//链接
			if (Direction == false)//如果是无向图还需要镜像处理
			{
				_weights[dsti][srci] = w;
			}
		}

		void Print()
		{
			/* 打印顶点集合和邻接矩阵来测试（只限于 int 类型的顶点数据） */
			int i = 0;
			for (auto ver : _vertexs)
			{
				cout << "[" << i++ << "]" << "->" << ver << '\n';
			}
			cout << '\n';

			for (size_t i = 0; i < _weights.size(); i++)
			{
				for (size_t j = 0; j < _weights[i].size(); j++)
				{
					if (_weights[i][j] != INT_MAX)
					{
						printf("[%zd, %zd]:%-10d  ", i, j, _weights[i][j]);
					}
					else
					{
						printf("[%zd, %zd]:%-10d  ", i, j, 0);
					}
				}
				cout << '\n';
			}
		}

	private:
		vector<VertexType> _vertexs; //顶点表
		vector<vector<WeightType>> _weights; //邻接矩阵（无向图的时候表示链接关系，有向图的时候不仅可以查看是否有链接，还可以查看权值）
		map<VertexType, int> _indexMap; //顶点映射下标（主要是用来提高效率的）
	};

	void TestGraph()
	{
		string str = "0123";
		vector<char> vec(str.begin(), str.end());
		AMGraph<char, int, INT_MAX, true> amg(vec, 4);
		amg.AddEdge('0', '1', 1);
		amg.AddEdge('0', '3', 4);
		amg.AddEdge('1', '3', 2);
		amg.AddEdge('1', '2', 9);
		amg.AddEdge('2', '3', 8);
		amg.AddEdge('2', '1', 5);
		amg.AddEdge('2', '0', 3);
		amg.AddEdge('3', '2', 6);
		amg.Print();
	}
}