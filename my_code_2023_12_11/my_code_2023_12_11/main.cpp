#define SIZE 100

template <typename VertexType>
class AMGraph
{
private:
	VertexType vexs[SIZE];	//顶点表
	int arcs[SIZE][SIZE];	//邻接矩阵
	int vexNum;				//图当前的顶点数
	int arcNum;				//图当前的边数
};