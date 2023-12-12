#include <vector>
#include <list>
#include <utility>
using namespace std;

template <typename ArcType = int>
struct ArcBox
{
	int tailIndex, headInde;	//β������ͷ����
	ArcType arc;				//Я����ȨֵȨֵ
	ArcBox* sameHead;			//��ͬͷ�Ļ�
	ArcBox* sameTail;			//��ͬβ�Ļ�
};

template <typename VertexType = char, typename ArcType = int>
struct VexNode
{
	VertexType data;			//����洢������
	ArcBox<ArcType>* firstHead;			//ָ���Ըö���Ϊ��ͷ�ĵ�һ������
	ArcBox<ArcType>* firstTail;			//ָ���Ըö���Ϊ��β�ĵ�һ������
};

template <typename VertexType = char, typename ArcType = int>
class OLGraph
{
private:
	vector<VexNode<VertexType, ArcType>> table;	//�����
	int vexNum;							//ͼ��ǰ�Ķ�����
	int arcNum;							//ͼ��ǰ�ı���
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