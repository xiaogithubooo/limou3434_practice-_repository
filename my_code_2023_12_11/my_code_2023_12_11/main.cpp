#define SIZE 100

template <typename VertexType>
class AMGraph
{
private:
	VertexType vexs[SIZE];	//�����
	int arcs[SIZE][SIZE];	//�ڽӾ���
	int vexNum;				//ͼ��ǰ�Ķ�����
	int arcNum;				//ͼ��ǰ�ı���
};