//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//
//#include<iostream>
//#include <list>
//#include <queue>
//using namespace std;
//
//class Graph
//{
//public:
//    Graph(int vertexNum)
//        : _vertexNum(vertexNum)
//        , _adjacencyList(new list<int>[_vertexNum])
//        , _indegree(new int[_vertexNum])
//    {
//        for (int i = 0; i < _vertexNum; ++i)
//            _indegree[i] = 0;
//    }
//    ~Graph()
//    {
//        delete[] _adjacencyList;
//        delete[] _indegree;
//    }
//    void addEdge(int v, int w)
//    {
//        _adjacencyList[v].push_back(w);
//        ++_indegree[w];
//    }
//    bool topological_sort()
//    {
//        for (int i = 0; i < _vertexNum; ++i)
//            if (_indegree[i] == 0)
//                _inZeroQueue.push(i);         // ���������Ϊ0�Ķ������
//
//        int count = 0;             // ��������¼��ǰ�Ѿ�����Ķ����� 
//        while (!_inZeroQueue.empty())
//        {
//            int _vertexNum = _inZeroQueue.front();      // �Ӷ�����ȡ��һ������
//            _inZeroQueue.pop();
//
//            cout << _vertexNum << " ";      // ����ö���
//            ++count;
//            // ������_vertexNumָ��Ķ������ȼ�1��������ȼ�Ϊ0�Ķ�����ջ
//            list<int>::iterator beg = _adjacencyList[_vertexNum].begin();
//            for (; beg != _adjacencyList[_vertexNum].end(); ++beg)
//                if (!(--_indegree[*beg]))
//                    _inZeroQueue.push(*beg);   // �����Ϊ0������ջ
//        }
//
//        if (count < _vertexNum)
//            return false;           // û�����ȫ�����㣬����ͼ���л�·
//        else
//            return true;            // ��������ɹ�
//    }
//
//private:
//    int _vertexNum;                  //��¼����ĸ���
//    list<int>* _adjacencyList;       //�ڽӱ��洢Ȩֵ
//    queue<int> _inZeroQueue;         //���Ϊ 0 �Ķ��㼯��
//    int* _indegree;                  //��¼ÿ����������
//};
//
//int main()
//{
//	int number = 0;
//	return 0;
//}