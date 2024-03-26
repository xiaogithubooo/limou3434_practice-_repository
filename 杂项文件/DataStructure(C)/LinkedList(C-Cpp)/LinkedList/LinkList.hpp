#include <iostream>
#include <cassert>
namespace limou
{
	//����д����˫���������ڱ�λ�ڵ㣩

	//1.һ���ڵ�Ľṹ��
	template<typename T>
	struct Node
	{
		//1.���캯��
		Node(T val = T()) : _nodeData(val), _nodeNext(this), _nodePrev(this) {}
		//2.��Ա����
		T _nodeData;
		struct Node* _nodeNext;
		struct Node* _nodePrev;
	};

	//2.ά������ڵ������
	template<typename T>
	class LinkList
	{
	public:
		//1.��Ա
		LinkList() : _node(new Node<T>), _size(0) {}//����
		LinkList(const LinkList<T>& list) {}//��������
		~LinkList()//����
		{
			Node<T>* cur = _node->_nodeNext;
			Node<T>* next = nullptr;
			while (cur != _node)
			{
				next = cur->_nodeNext;
				delete cur;
				cur = next;
			}
			delete _node;//�ͷ��ڱ����
			_size = 0;
		}

		//2.��ɾ
		//2.1.������루��posָ��ڵ�ǰ���룩
		void Insert(Node<T>* pos, const T& val)
		{
			assert(pos != nullptr);//��ָ֤�����Ч��
			//����ָ��
			Node<T>* newNode = new Node<T>(val);//�������
			Node<T>* temp = pos->_nodePrev;//����ָ��

			//����newNode
			newNode->_nodeNext = pos;
			newNode->_nodePrev = temp;
			//����pos
			pos->_nodePrev = newNode;
			//����temp
			temp->_nodeNext = newNode;

			//�ӼӴ�С
			_size++;
		}
		//2.2.����ɾ������posָ��Ľڵ�ɾ����
		void Erase(Node<T>* pos)
		{
			assert(pos != nullptr);//��ָ֤�����Ч��
			assert(pos != _node);//����βɾ����ͷɾ���ڱ��ڵ�Ҳ�ͷ���
			//����ָ��
			Node<T>* temp1 = pos->_nodePrev;
			Node<T>* temp2 = pos->_nodeNext;

			//����pos
			temp1->_nodeNext = temp2;
			temp2->_nodePrev = temp1;

			//�ͷ�pos
			delete pos;
			
			//������С
			_size--;
		}
		//2.3.������ң����ݵ�һ���ҵ��Ķ�Ӧֵ������ָ��ڵ��pos��
		Node<T>* Find(const T& val)
		{
			Node<T>* cur = _node->_nodeNext;
			while (cur != _node)
			{
				if (cur->_nodeData == val)
				{
					return cur;
				}
				cur = cur->_nodeNext;
			}
			return nullptr;
		}
		//2.4.β���ͷ��
		void Push_back(const T& val)//β��
		{
			Insert(_node, val);
		}
		void Push_front(const T& val)//ͷ��
		{
			Insert(_node->_nodeNext, val);
		}
		//2.5.βɾ��ͷɾ
		void Pop_back()//βɾ
		{
			Erase(_node->_nodePrev);
		}
		void Pop_front()//ͷɾ
		{
			Erase(_node->_nodeNext);
		}

		//3.����
		//3.1.���ص�ǰ�����С
		int Size()
		{
			return _size;
		}
		//3.2.��ӡ�����ڲ�Ԫ��
		void Print()
		{
			Node<T>* cur = _node->_nodeNext;
			while (cur != _node)
			{
				std::cout << cur->_nodeData << " ";
				cur = cur->_nodeNext;
			}
			std::cout << std::endl;
		}
	private:
		Node<T>* _node;//ָ���ڱ��ڵ�
		int _size;//��¼��С��������ͷ�ڵ㣩
	};
}