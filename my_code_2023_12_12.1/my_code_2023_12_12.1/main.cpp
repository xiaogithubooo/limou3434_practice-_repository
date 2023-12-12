#include <vector>
#include <list>
#include <utility>
using namespace std;

template <typename ArcType = int>
struct ArcBox
{
	int tailIndex, headInde;	//尾索引和头索引
	ArcType arc;				//携带的权值权值
	ArcBox* sameHead;			//相同头的弧
	ArcBox* sameTail;			//相同尾的弧
};

template <typename VertexType = char, typename ArcType = int>
struct VexNode
{
	VertexType data;			//顶点存储的数据
	ArcBox<ArcType>* firstHead;			//指向以该顶点为弧头的第一个顶点
	ArcBox<ArcType>* firstTail;			//指向以该顶点为弧尾的第一个顶点
};

template <typename VertexType = char, typename ArcType = int>
class OLGraph
{
private:
	vector<VexNode<VertexType, ArcType>> table;	//顶点表
	int vexNum;							//图当前的顶点数
	int arcNum;							//图当前的边数
};



//template <typename VertexType = char, typename ArcType = int>
//class AMGraph
//{
//private:
//	vector<
//		pair<VertexType, list<pair<int, ArcType>>>
//	> vexs;
//};

int main()
{

}