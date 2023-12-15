//am_graph.hpp �ڽӾ���ʵ��
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
		typename VertexType = char, //������������
		typename WeightType = int, //Ȩ����������
		WeightType MAX_W = INT_MAX, //��ʾ�������
		bool Direction = false //�ж��Ƿ�����
	>
	class AMGraph
	{
		/*
		* ����ͼ������ͼ�����Ǵ�Ȩֵ���ڽӾ���ģ���࣬
		* ���������ַ�����IO ���롢�ļ���ȡ�������ֶ��ڴ��������
		*/
		typedef AMGraph<VertexType, WeightType, MAX_W, Direction> Self;

	public:
		AMGraph() = default;
		AMGraph(const vector<VertexType>& arr, size_t arrSize)
		{
			/* ���ݶ������У���ʼ���ڽӾ�������������Ϣ */
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
			/* ���ض����Ӧ�������������м����ƣ���ֹ�û������ */
			auto it = _indexMap.find(v);
			if (it != _indexMap.end())
			{
				return it->second;
			}

			cout << v;
			std::string message = " ���㲻���ڣ�����";
			throw message; //����ʱ����
			return -1; //��ֹ���������棨�������еı����������ˣ�
		}

		void _AddEdge(const size_t& srci, const size_t& dsti, const WeightType& w)
		{
			/* ��ӱ��Լ���Ӧ��Ȩֵ��ʵ���Ͽ������Ϊ AddEdge() �����ذ汾����Ҫ�Ƿ���ĳЩ�������������������п��ܷ������岻��ȷ�����о�û��д�����ذ汾�� */

			_weights[srci][dsti] = w;//����
			if (Direction == false)//���������ͼ����Ҫ������
			{
				_weights[dsti][srci] = w;
			}
		}
		void AddEdge(const VertexType& src, const VertexType& dst, const WeightType& w)
		{
			/* ��ӱ��Լ���Ӧ��Ȩֵ */
			size_t srci = GetVertexIndex(src);
			size_t dsti = GetVertexIndex(dst);

			_AddEdge(srci, dsti, w);
		}

		void Print()
		{
			/* ��ӡ���㼯�Ϻ��ڽӾ��������ԣ�ֻ���� int ���͵Ķ������ݣ� */
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
			/* ������ȱ����㷨 */
			size_t srci = GetVertexIndex(src);

			queue<int> q; //����
			q.push(srci);
			vector<bool> visited(_vertexs.size(), false); //���λ����
			visited[srci] = true;

			size_t size = _vertexs.size();

			while (!q.empty())
			{
				//���ӷ���
				int front = q.front();
				q.pop();
				cout << _vertexs[front] << " ";

				//�� front ���ڽӶ������
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

			//Ѱ����һ������
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
			/* ������ȱ����㷨 */
			size_t srci = GetVertexIndex(src);
			vector<bool> visited(_vertexs.size(), false);
			_DFS(srci, visited);
			cout << '\n';
		}

		struct Edge
		{
			/* ר�ŷ��������������㷨�Ľṹ�� */
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
			/* ʹ�� Kruskal �㷨������ͼ������С������ */
			if (Direction != true) //�ų�����ͼ���������Ϊ����ͼ���ɵ���������������������
			{
				//��ʼ��
				size_t n = _vertexs.size(); //ͳ�ƶ������

				minTree._vertexs = _vertexs; //���ƶ����
				minTree._indexMap = _indexMap; //����ӳ���
				minTree._weights.resize(n); //Ȩֵ����ǰ����
				for (size_t i = 0; i < n; i++)
				{
					minTree._weights[i].resize(n, MAX_W);
				}

				priority_queue<Edge, vector<Edge>, greater<Edge>> minque; //�洢��С��·��

				//�����ڽӾ��������Ȩֵ�Ͳ������ȼ�������
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

				//ѡ���������С������
				int count = 0; //ͳ��ѡ��ı���
				int totalw = 0; //ͳ����С��������Ȩֵ
				UnionFindSet<int> ufs(n);
				while (!minque.empty())
				{
					Edge min = minque.top();
					minque.pop();

					if (!ufs.InSet(min._srci, min._dsti)) //�жϱߵ������㲻��ͬһ������
					{
						minTree._AddEdge(min._srci, min._dsti, min._weig); //��Ӹñ߽�����С������
						ufs.Union(min._srci, min._dsti); //�����������Ϊһ������
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
					return WeightType();//���ߵ�������˵����ͼû����С��������Ҳ����ͼ������ͨͼ��
				}
			}

			return WeightType();
		}

		WeightType Prim(Self& minTree, const VertexType& src)
		{
			/* ʹ�� Prim �㷨������ͼ������С������ */
			if (Direction != true) //�ų�����ͼ���������Ϊ����ͼ���ɵ���������������������
			{
				//��ʼ����С������
				size_t srci = GetVertexIndex(src); //��ȡ�������
				size_t n = _vertexs.size(); //ͳ�ƶ������
				size_t count = 0; //ͳ����ѡ��ı���
				WeightType totalW = 0; //Ȩֵ�ܺ�

				minTree._vertexs = _vertexs;
				minTree._indexMap = _indexMap;
				minTree._weights.resize(n);
				for (size_t i = 0; i < n; i++)
				{
					minTree._weights[i].resize(n, MAX_W);
				}

				//������������
				vector<bool> X; //X ����
				vector<bool> Y; //Y ����
				X.resize(n, false); //���� X �еĶ���
				Y.resize(n, true); //���� Y �еĶ���
				X[srci] = true; //�� X �в������
				Y[srci] = false; //�� Y ��ɾ�����

				//�� X-Y ��ѡ��ȨֵС�ı߹�����С������������Ǩ�� Y �����е�Ԫ�ص� X ����
				priority_queue<Edge, vector<Edge>, greater<Edge>> minq;
				for (size_t i = 0; i < n; ++i)
				{
					if (_weights[srci][i] != MAX_W)
					{
						minq.push(Edge(srci, i, _weights[srci][i])); //���������صı߼�����Ϣ���
					}
				}

				while (!minq.empty())
				{
					//ѡ����С�ı�
					Edge min = minq.top();
					minq.pop();

					//�ų��������
					if (X[min._dsti] != true) //�յ�Ҳ�� X ���Ͼͻṹ�ɻ���Ҫ�����������
					{
						//��ӵ���С��������
						minTree._AddEdge(min._srci, min._dsti, min._weig);

						//ת����������Ԫ��
						X[min._dsti] = true;
						Y[min._dsti] = false;
						
						//ͳ�ƶ�������Ȩֵ��
						++count;
						totalW += min._weig;

						if (count == n - 1)
							break;

						//��������������
						for (size_t i = 0; i < n; ++i)
						{
							if (_weights[min._dsti][i] != MAX_W && Y[i] == true) //��һ��������Ϊ�˱����ظ����֮ǰ����ӵı�
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
					return WeightType();//���ߵ�������˵����ͼû����С��������Ҳ����ͼ������ͨͼ��
				}
			}
			
			return WeightType();
		}

	private:
		vector<VertexType> _vertexs; //�����
		vector<vector<WeightType>> _weights; //�ڽӾ�������ͼ��ʱ���ʾ���ӹ�ϵ������ͼ��ʱ�򲻽����Բ鿴�Ƿ������ӣ������Բ鿴Ȩֵ��
		map<VertexType, int> _indexMap; //����ӳ���±꣨��Ҫ���������Ч�ʵģ�
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
		vector<string> vec = { "����", "����", "����", "����", "����" };
		AMGraph<string, int, INT_MAX> amg(vec, 5);
		amg.AddEdge("����", "����", 100);
		amg.AddEdge("����", "����", 200);
		amg.AddEdge("����", "����", 30);
		amg.AddEdge("����", "����", 30);
		amg.BFS("����");
		amg.BFS("����");
		amg.DFS("����");
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