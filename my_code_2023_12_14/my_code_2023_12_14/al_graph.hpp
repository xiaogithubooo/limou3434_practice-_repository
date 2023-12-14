//al_graph.hpp �ڽӱ�ʵ��
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
		* ��֯һ������ԣ���Ҫ�洢�յ��Ȩֵ��Ҳ������Դ�㣩
		*/
		//int _srci; //Դ�㣨��ѡ�����ر�Ϳ����������
		int _dsti; //�յ�
		WeightType _weig; //Ȩֵ
		Edge<WeightType>* _next; //����ָ��

		Edge(const int& dsti, const WeightType& weig)
			: _dsti(dsti), _weig(weig), _next(nullptr)
		{}
	};

	template <
		typename VertexType = char, //������������
		typename WeightType = int, //Ȩ����������
		bool Direction = false //�ж��Ƿ�����
	>
	class ALGraph
	{
		/*
		* ����ͼ������ͼ�����Ǵ�Ȩֵ���ڽӱ�ģ���࣬
		* ���������ַ�����IO ���롢�ļ���ȡ�������ֶ��ڴ��������
		*/
	public:
		ALGraph(const vector<VertexType>& arr, size_t arrSize)
		{
			/* ���ݶ������У���ʼ���ڽӱ�����������Ϣ */
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
			/* ���ض����Ӧ�������������м����ƣ���ֹ�û������ */
			auto it = _indexMap.find(v);
			if (it != _indexMap.end())
			{
				return it->second;
			}
			throw invalid_argument("���㲻����");//����ʱ����
			return -1;//��ֹ����������
		}

		void AddEdge(const VertexType& src, const VertexType& dst, const WeightType& w)
		{
			/* ��ӱ��Լ���Ӧ��Ȩֵ */
			size_t srci = GetVertexIndex(src); //�ҵ�Դ���Ӧ������
			size_t dsti = GetVertexIndex(dst); //�ҵ�Դ���Ӧ������

			Edge<WeightType>* eg = new Edge<WeightType>((int)dsti, w); //ͷ��
			eg->_next = _tables[srci];
			_tables[srci] = eg;

			if (Direction == false) //���������ͼ����Ҫ��һ��������
			{
				Edge<WeightType>* eg = new Edge<WeightType>((int)srci, w); //ͷ��
				eg->_next = _tables[dsti];
				_tables[dsti] = eg;
			}
		}

		void Print()
		{
			/* ��ӡ���㼯�Ϻ��ڽӱ������ԣ�ֻ���� int ���͵Ķ������ݣ� */
			//��ӡ�����
			int i = 0;
			for (auto ver : _vertexs)
			{
				cout << ver << " ";
			}
			cout << '\n';

			//��ӡ�ڽӱ�
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
		vector<VertexType> _vertexs; //�����
		map<VertexType, int> _indexMap; //����ӳ���±꣨��Ҫ���������Ч�ʵģ�
		vector<Edge<int>*> _tables; //�ڽӱ�����ͼʱֻ�洢���Ȼ������ڽӱ�
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