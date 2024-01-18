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
//                _inZeroQueue.push(i);         // 将所有入度为0的顶点入队
//
//        int count = 0;             // 计数，记录当前已经输出的顶点数 
//        while (!_inZeroQueue.empty())
//        {
//            int _vertexNum = _inZeroQueue.front();      // 从队列中取出一个顶点
//            _inZeroQueue.pop();
//
//            cout << _vertexNum << " ";      // 输出该顶点
//            ++count;
//            // 将所有_vertexNum指向的顶点的入度减1，并将入度减为0的顶点入栈
//            list<int>::iterator beg = _adjacencyList[_vertexNum].begin();
//            for (; beg != _adjacencyList[_vertexNum].end(); ++beg)
//                if (!(--_indegree[*beg]))
//                    _inZeroQueue.push(*beg);   // 若入度为0，则入栈
//        }
//
//        if (count < _vertexNum)
//            return false;           // 没有输出全部顶点，有向图中有回路
//        else
//            return true;            // 拓扑排序成功
//    }
//
//private:
//    int _vertexNum;                  //记录顶点的个数
//    list<int>* _adjacencyList;       //邻接表，存储权值
//    queue<int> _inZeroQueue;         //入度为 0 的顶点集合
//    int* _indegree;                  //记录每个顶点的入度
//};
//
//int main()
//{
//	int number = 0;
//	return 0;
//}