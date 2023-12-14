//am_graph.hpp �ڽӾ���ʵ��
#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <stdexcept>
#include <climits>
#include <cstdio>
#include "union_find_set.hpp"

namespace limou
{
	using std::vector;
	using std::string;
	using std::cout;
	using std::map;
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
		AMGraph(const vector<VertexType>& arr, size_t arrSize)
		{
			/* ���ݶ������У���ʼ���ڽӾ�������������Ϣ */
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
			/* ���ض����Ӧ�������������м����ƣ���ֹ�û������ */
			auto it = _indexMap.find(v);
			if (it != _indexMap.end())
			{
				return it->second;
			}
			throw invalid_argument("���㲻����");//����ʱ����
			return -1;//��ֹ����������
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
			cout << '\n';
		}

		void BFS(const VertexType& src)
		{
			/* ������ȱ����㷨 */
			size_t srci = GetVertexIndex(src);

			queue<int> q; //����
			q.push((int)srci);
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
						q.push((int)i);
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
			/* ר�ŷ����� Kruskal �Ľṹ�� */
			size_t _srci;
			size_t _dsti;
			const WeightType _weig;

			Edge(size_t srci, size_t dsti, WeightType weig)
				: _srci(srci), _dsti(dsti), _weig(weig)
			{}

			bool operator >(const Edge& e1, const Edge& e2) const
			{
				return e1._weig > e2._weig;
			}
		};
		WeightType Kruskal(Self& minTree)
		{
			/* ʹ�� Kruskal �㷨������ͼ������С������ */
			if (Direction != true)
			{
				priority_queue<Edge, vector<Edge>, greater<Edge>> minque;//�洢��С��·��
				size_t n = _vertexs.size();//ͳ�ƶ������

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

				//ѡ�� n-1 ����
				int count = n - 1;
				UnionFindSet<> ufs(n);
				while (count--)
				{
					Edge min = minque.top();
					minque.pop();

					if (ufs.InSet(min._srci, min._dsti))
					{
						minTree.AddEdge();
					}
				}
			}
		}

	private:
		vector<VertexType> _vertexs; //�����
		vector<vector<WeightType>> _weights; //�ڽӾ�������ͼ��ʱ���ʾ���ӹ�ϵ������ͼ��ʱ�򲻽����Բ鿴�Ƿ������ӣ������Բ鿴Ȩֵ��
		map<VertexType, int> _indexMap; //����ӳ���±꣨��Ҫ���������Ч�ʵģ�
	};

	void TestAMGraph()
	{
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
	}

	void TestAMGraphBFS()
	{
		vector<string> vec = { "����", "����", "����", "����", "����" };
		AMGraph<string, int, INT_MAX> amg(vec, 5);
		amg.AddEdge("����", "����", 100);
		amg.AddEdge("����", "����", 200);
		amg.AddEdge("����", "����", 30);
		amg.AddEdge("����", "����", 30);
		amg.BFS("����");
		amg.BFS("����");
		amg.DFS("����");
	}
}