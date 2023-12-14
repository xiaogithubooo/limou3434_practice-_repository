//am_graph.hpp �ڽӾ���ʵ��
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

		void AddEdge(const VertexType& src, const VertexType& dst, const WeightType& w)
		{
			/* ��ӱ��Լ���Ӧ��Ȩֵ */
			size_t srci = GetVertexIndex(src);
			size_t dsti = GetVertexIndex(dst);

			_weights[srci][dsti] = w;//����
			if (Direction == false)//���������ͼ����Ҫ������
			{
				_weights[dsti][srci] = w;
			}
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
}