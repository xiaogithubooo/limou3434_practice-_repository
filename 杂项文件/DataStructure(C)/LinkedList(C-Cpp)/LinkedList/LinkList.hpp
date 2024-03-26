#include <iostream>
#include <cassert>
namespace limou
{
	//本次写的是双向链表（有哨兵位节点）

	//1.一个节点的结构体
	template<typename T>
	struct Node
	{
		//1.构造函数
		Node(T val = T()) : _nodeData(val), _nodeNext(this), _nodePrev(this) {}
		//2.成员变量
		T _nodeData;
		struct Node* _nodeNext;
		struct Node* _nodePrev;
	};

	//2.维护多个节点的链表
	template<typename T>
	class LinkList
	{
	public:
		//1.成员
		LinkList() : _node(new Node<T>), _size(0) {}//构造
		LinkList(const LinkList<T>& list) {}//拷贝构造
		~LinkList()//析构
		{
			Node<T>* cur = _node->_nodeNext;
			Node<T>* next = nullptr;
			while (cur != _node)
			{
				next = cur->_nodeNext;
				delete cur;
				cur = next;
			}
			delete _node;//释放哨兵结点
			_size = 0;
		}

		//2.插删
		//2.1.任意插入（在pos指向节点前插入）
		void Insert(Node<T>* pos, const T& val)
		{
			assert(pos != nullptr);//保证指针的有效性
			//三个指针
			Node<T>* newNode = new Node<T>(val);//创建结点
			Node<T>* temp = pos->_nodePrev;//保存指针

			//设置newNode
			newNode->_nodeNext = pos;
			newNode->_nodePrev = temp;
			//设置pos
			pos->_nodePrev = newNode;
			//设置temp
			temp->_nodeNext = newNode;

			//加加大小
			_size++;
		}
		//2.2.任意删除（将pos指向的节点删除）
		void Erase(Node<T>* pos)
		{
			assert(pos != nullptr);//保证指针的有效性
			assert(pos != _node);//避免尾删或者头删把哨兵节点也释放了
			//三个指针
			Node<T>* temp1 = pos->_nodePrev;
			Node<T>* temp2 = pos->_nodeNext;

			//隔离pos
			temp1->_nodeNext = temp2;
			temp2->_nodePrev = temp1;

			//释放pos
			delete pos;
			
			//减减大小
			_size--;
		}
		//2.3.任意查找（根据第一个找到的对应值，返回指向节点的pos）
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
		//2.4.尾插和头插
		void Push_back(const T& val)//尾插
		{
			Insert(_node, val);
		}
		void Push_front(const T& val)//头插
		{
			Insert(_node->_nodeNext, val);
		}
		//2.5.尾删和头删
		void Pop_back()//尾删
		{
			Erase(_node->_nodePrev);
		}
		void Pop_front()//头删
		{
			Erase(_node->_nodeNext);
		}

		//3.其他
		//3.1.返回当前链表大小
		int Size()
		{
			return _size;
		}
		//3.2.打印链表内部元素
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
		Node<T>* _node;//指向哨兵节点
		int _size;//记录大小（不包括头节点）
	};
}