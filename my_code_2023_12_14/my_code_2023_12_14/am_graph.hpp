//am_graph.hpp 邻接矩阵实现
#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stdexcept>
#include <functional>
#include <climits>
#include <cstdio>
#include "union_find_set.hpp"

namespace limou
{
	using std::vector;
	using std::string;
	using std::cout;
	using std::map;
	using std::set;
	using std::invalid_argument;
	using std::queue;
	using std::priority_queue;
	using std::greater;

	template <
		typename VertexType = char, //顶点数据类型
		typename WeightType = int, //权重数据类型
		WeightType MAX_W = INT_MAX, //表示无穷的数
		bool Direction = false //判断是否有向
	>
	class AMGraph
	{
		/*
		* 无向图或有向图（考虑带权值）邻接矩阵模板类，
		* 测试有三种方法：IO 输入、文件读取样例、手动在代码中添加
		*/
		typedef AMGraph<VertexType, WeightType, MAX_W, Direction> Self;

	public:
		AMGraph() = default;
		AMGraph(const vector<VertexType>& arr, size_t arrSize)
		{
			/* 根据顶点序列，初始化邻接矩阵和其他相关信息 */
			_vertexs.reserve(arrSize);
			for (size_t i = 0; i < arrSize; ++i)
			{
				_vertexs.push_back(arr[i]);
				_indexMap[arr[i]] = i;
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

			cout << v;
			std::string message = " 顶点不存在，请检查";
			throw message; //运行时报错
			return -1; //防止编译器警告（不加在有的编译器过不了）
		}

		void _AddEdge(const size_t& srci, const size_t& dsti, const WeightType& w)
		{
			/* 添加边以及对应的权值（实际上可以理解为 AddEdge() 的重载版本，主要是方便某些传递坐标的情况，但是有可能发生语义不明确，所有就没有写成重载版本） */

			_weights[srci][dsti] = w;//链接
			if (Direction == false)//如果是无向图还需要镜像处理
			{
				_weights[dsti][srci] = w;
			}
		}
		void AddEdge(const VertexType& src, const VertexType& dst, const WeightType& w)
		{
			/* 添加边以及对应的权值 */
			size_t srci = GetVertexIndex(src);
			size_t dsti = GetVertexIndex(dst);

			_AddEdge(srci, dsti, w);
		}

		void Print()
		{
			/* 打印顶点集合和邻接矩阵来测试（只限于 int 类型的顶点数据） */
			int i = 0;
			for (auto ver : _vertexs)
			{
				cout << ver << " ";
			}
			cout << '\n';

			for (size_t i = 0; i < _weights.size(); i++)
			{
				for (size_t j = 0; j < _weights[i].size(); j++)
				{
					if (_weights[i][j] != INT_MAX && Direction == true)
					{
						printf("[%zd, %zd]%c->%c,%-2d  ", i, j, _vertexs[i], _vertexs[j], _weights[i][j]);
					}
					else if (_weights[i][j] != INT_MAX && Direction == false)
					{
						printf("[%zd, %zd]%c--%c,%-2d  ", i, j, _vertexs[i], _vertexs[j], _weights[i][j]);
					}
					else
					{
						printf("[%zd, %zd]%-7c  ", i, j, '*');
					}
				}
				cout << '\n';
			}
			cout << '\n';
		}

		void BFS(const VertexType& src)
		{
			/* 广度优先遍历算法 */
			size_t srci = GetVertexIndex(src);

			queue<int> q; //队列
			q.push(srci);
			vector<bool> visited(_vertexs.size(), false); //标记位数组
			visited[srci] = true;

			size_t size = _vertexs.size();

			while (!q.empty())
			{
				//出队访问
				int front = q.front();
				q.pop();
				cout << _vertexs[front] << " ";

				//把 front 的邻接顶点入队
				for (size_t i = 0; i < size; i++)
				{
					if (_weights[front][i] != MAX_W && visited[i] == false)
					{
						q.push(i);
						visited[i] = true;
					}
				}
			}
			cout << '\n';
		}

		void _DFS(const size_t srci, vector<bool>& visited)
		{
			cout << _vertexs[srci] << " ";
			visited[srci] = true;

			//寻找下一个顶点
			for (size_t i = 0; i < _vertexs.size(); ++i)
			{
				if (_weights[srci][i] != MAX_W && visited[i] != true)
				{
					_DFS(i, visited);
				}
			}
		}
		void DFS(const VertexType& src)
		{
			/* 深度优先遍历算法 */
			size_t srci = GetVertexIndex(src);
			vector<bool> visited(_vertexs.size(), false);
			_DFS(srci, visited);
			cout << '\n';
		}

		struct Edge
		{
			/* 专门服务于下面两种算法的结构体 */
			size_t _srci;
			size_t _dsti;
			WeightType _weig;

			Edge(size_t srci, size_t dsti, WeightType weig)
				: _srci(srci), _dsti(dsti), _weig(weig)
			{}

			bool operator >(const Edge& e) const
			{
				return _weig > e._weig;
			}
		};

		WeightType Kruskal(Self& minTree)
		{
			/* 使用 Kruskal 算法给无向图生成最小生成树 */
			if (Direction != true) //排除有向图的情况，因为有向图生成的是有向树而不是生成树
			{
				//初始化
				size_t n = _vertexs.size(); //统计顶点个数

				minTree._vertexs = _vertexs; //复制顶点表
				minTree._indexMap = _indexMap; //复制映射表
				minTree._weights.resize(n); //权值表提前扩容
				for (size_t i = 0; i < n; i++)
				{
					minTree._weights[i].resize(n, MAX_W);
				}

				priority_queue<Edge, vector<Edge>, greater<Edge>> minque; //存储较小的路径

				//遍历邻接矩阵，如果有权值就插入优先级队列中
				for (size_t i = 0; i < n; i++)
				{
					for (size_t j = 0; j < n; j++)
					{
						if (i < j && _weights[i][j] != MAX_W)
						{
							minque.push(Edge(i, j, _weights[i][j]));
						}
					}
				}

				//选出边组成最小生成树
				int count = 0; //统计选择的边数
				int totalw = 0; //统计最小生成树的权值
				UnionFindSet<int> ufs(n);
				while (!minque.empty())
				{
					Edge min = minque.top();
					minque.pop();

					if (!ufs.InSet(min._srci, min._dsti)) //判断边的两顶点不在同一个集合
					{
						minTree._AddEdge(min._srci, min._dsti, min._weig); //添加该边进入最小生成树
						ufs.Union(min._srci, min._dsti); //将两个顶点归为一个集合
						++count;
						totalw += min._weig;
					}
				}

				if (count == n - 1)
				{
					return totalw;
				}
				else
				{
					return WeightType();//都走到这里了说明改图没有最小生成树（也就是图不是连通图）
				}
			}

			return WeightType();
		}

		WeightType Prim(Self& minTree, const VertexType& src)
		{
			/* 使用 Prim 算法给无向图生成最小生成树 */
			if (Direction != true) //排除有向图的情况，因为有向图生成的是有向树而不是生成树
			{
				//初始化最小生成树
				size_t srci = GetVertexIndex(src); //获取起点索引
				size_t n = _vertexs.size(); //统计顶点个数
				size_t count = 0; //统计已选择的边数
				WeightType totalW = 0; //权值总和

				minTree._vertexs = _vertexs;
				minTree._indexMap = _indexMap;
				minTree._weights.resize(n);
				for (size_t i = 0; i < n; i++)
				{
					minTree._weights[i].resize(n, MAX_W);
				}

				//设置两个集合
				vector<bool> X; //X 集合
				vector<bool> Y; //Y 集合
				X.resize(n, false); //设置 X 中的顶点
				Y.resize(n, true); //设置 Y 中的顶点
				X[srci] = true; //在 X 中插入起点
				Y[srci] = false; //在 Y 中删除起点

				//从 X-Y 中选择权值小的边构成最小生成树，并且迁移 Y 集合中的元素到 X 集合
				priority_queue<Edge, vector<Edge>, greater<Edge>> minq;
				for (size_t i = 0; i < n; ++i)
				{
					if (_weights[srci][i] != MAX_W)
					{
						minq.push(Edge(srci, i, _weights[srci][i])); //将和起点相关的边及其信息入队
					}
				}

				while (!minq.empty())
				{
					//选出最小的边
					Edge min = minq.top();
					minq.pop();

					//排除环的情况
					if (X[min._dsti] != true) //终点也在 X 集合就会构成环，要避免这种情况
					{
						//添加到最小生成树中
						minTree._AddEdge(min._srci, min._dsti, min._weig);

						//转移两个集合元素
						X[min._dsti] = true;
						Y[min._dsti] = false;
						
						//统计顶点数和权值和
						++count;
						totalW += min._weig;

						if (count == n - 1)
							break;

						//继续走其他顶点
						for (size_t i = 0; i < n; ++i)
						{
							if (_weights[min._dsti][i] != MAX_W && Y[i] == true) //后一个条件是为了避免重复添加之前就添加的边
							{
								minq.push(Edge(min._dsti, i, _weights[min._dsti][i]));
							}
						}
					}
				}

				if (count == n - 1)
				{
					return totalW;
				}
				else
				{
					return WeightType();//都走到这里了说明改图没有最小生成树（也就是图不是连通图）
				}
			}
			
			return WeightType();
		}

	private:
		vector<VertexType> _vertexs; //顶点表
		vector<vector<WeightType>> _weights; //邻接矩阵（无向图的时候表示链接关系，有向图的时候不仅可以查看是否有链接，还可以查看权值）
		map<VertexType, int> _indexMap; //顶点映射下标（主要是用来提高效率的）
	};

	void TestAMGraph()
	{
		cout << "void TestAMGraph()" << '\n';
		string str = "ABCD";
		vector<char> vec(str.begin(), str.end());
		AMGraph<char, int, INT_MAX, true> amg(vec, 4);
		amg.AddEdge('A', 'B', 1);
		amg.AddEdge('A', 'D', 4);
		amg.AddEdge('B', 'D', 2);
		amg.AddEdge('B', 'C', 9);
		amg.AddEdge('C', 'D', 8);
		amg.AddEdge('C', 'B', 5);
		amg.AddEdge('C', 'A', 3);
		amg.AddEdge('D', 'C', 6);
		amg.Print();
		cout << '\n';
	}

	void TestAMGraphTraversal()
	{
		cout << "void TestAMGraphTraversal()" << '\n';
		vector<string> vec = { "张三", "李四", "王五", "赵六", "周七" };
		AMGraph<string, int, INT_MAX> amg(vec, 5);
		amg.AddEdge("张三", "李四", 100);
		amg.AddEdge("张三", "王五", 200);
		amg.AddEdge("王五", "赵六", 30);
		amg.AddEdge("王五", "周七", 30);
		amg.BFS("张三");
		amg.BFS("李四");
		amg.DFS("赵六");
		cout << '\n';
	}

	void TestAMGraphMinTree()
	{
		cout << "void TestAMGraphMinTree()" << '\n';
		string str = "abcdefghi";
		vector<char> vec(str.begin(), str.end());

		AMGraph<char, int> g(vec, str.size());
		g.AddEdge('a', 'b', 4);
		g.AddEdge('a', 'h', 8);
		//g.AddEdge('a', 'h', 9);
		g.AddEdge('b', 'c', 8);
		g.AddEdge('b', 'h', 11);
		g.AddEdge('c', 'i', 2);
		g.AddEdge('c', 'f', 4);
		g.AddEdge('c', 'd', 7);
		g.AddEdge('d', 'f', 14);
		g.AddEdge('d', 'e', 9);
		g.AddEdge('e', 'f', 10);
		g.AddEdge('f', 'g', 2);
		g.AddEdge('g', 'h', 1);
		g.AddEdge('g', 'i', 6);
		g.AddEdge('h', 'i', 7);

		AMGraph<char, int> kminTree;
		cout << "Kruskal:" << g.Kruskal(kminTree) << '\n';
		kminTree.Print();

		AMGraph<char, int> pminTree;
		cout << "Prim:" << g.Prim(pminTree, 'a') << '\n';
		pminTree.Print();

		cout << '\n';
	}

	void TestAMGraphShortestPath()
	{

	}
}