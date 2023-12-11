#include <vector>
#include <list>
#include <utility>
using namespace std;

template <typename VertexType>
class ALGraph
{
private:
	vector<
		pair<VertexType, list<int>>
	> vexs;
};


//#include <vector>
//using namespace std;
//
//template <typename VertexType>
//class AMGraph
//{
//private:
//	vector<VertexType> vexs;	//顶点表
//	vector<vector<int>> arcs;	//邻接矩阵
//	int vexNum;					//图当前的顶点数
//	int arcNum;					//图当前的边数
//};

int main()
{
	return 0;
}