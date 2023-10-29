/*
1.实现线性表的:
	1.1.插入、删除（拓展：可以修改原顺序表内某个元素的数据）
	1.2.求表长（拓展：求出表的容量）
	1.3.查找给定值 e、查找第 i 个位置元素
	1.4.要求编写的程序以菜单方式工作；
2.用链式存储结构实现一元多项式的相加运算；
3.利用双向链表实现通讯录的建立、删除、检索和列表，并可保存至文件，可重新装入。
*/

//我使用了双向循环带头链表来实现线性表
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
		Node<T>* Search(int index)//重载版本
		{
			if (index >= Size()) return nullptr;

			Node<T>* cur = _node->_nodeNext;
			while (index--)
			{
				cur = cur->_nodeNext;
			}

			return cur;
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

	//3.菜单
	void Menu()
	{
		std::cout << "|--------------------------------------------------|\n";
		std::cout << "| 程序启动，已经创建好了一个链表，请您进行增删查改 |\n";
		std::cout << "|--------------------------------------------------|\n";
		std::cout << "|       01.尾插   02.头插  03.尾删   04.头删       |\n";
		std::cout << "|       05.任意前插        06.任意删除             |\n";
		std::cout << "|       07.根据Val查找     08.根据下标查找         |\n";
		std::cout << "|       09.查询大小        10.打印链表             |\n";
		std::cout << "|--------------------------------------------------|\n";
		std::cout << "|                   退出请输入-1                   |\n";
		std::cout << "|--------------------------------------------------|\n";
		std::cout << "请输入对应的指令：";
	}

	//4.运行逻辑
	template <typename T>
	void Drive()
	{
		//0.创建对象
		LinkList<T> obj;

		//1.打印菜单
		Menu();

		//2.输入指令
		int select = 0;
		std::cin >> select;

		//3.处理指令
		while (select != -1)
		{
			T value = 0;
			int index = 0;
			Node<T>* cache = nullptr;

			switch (select)
			{
			case 1:
				std::cout << "[01.尾插]，输入需要尾插的 value 值：";
				std::cin >> value;
				obj.Push_back(value);
				break;

			case 2:
				std::cout << "[02.头插]，输入需要头插的 value 值：";
				std::cin >> value;
				obj.Push_front(value);
				break;

			case 3:
				std::cout << "[03.尾删]\n";
				obj.Pop_back();
				break;

			case 4:
				std::cout << "[04.头删]\n";
				obj.Pop_front();
				break;

			case 5:
				std::cout << "[05.任意前插]，输入被前结点的 index 和插入的 value：\n";
				std::cin >> index;
				std::cin >> value;
				cache = obj.Search(index);
				obj.Insert(cache, value);
				break;

			case 6:
				std::cout << "[06.任意删除]，输入被删除结点的 index：\n";
				std::cin >> index;
				cache = obj.Search(index);
				obj.Erase(cache);
				break;

			case 7:
				std::cout << "[07.根据Val查询]，输入要查询的 value：";
				std::cin >> value;
				if (obj.Find(value) != nullptr)
				{
					std::cout << "value为 " << value << " 的结点存在\n";
				}
				else
				{
					std::cout << "value为 " << value << " 的结点不存在\n";
				}
				break;

			case 8:
				std::cout << "[08.根据下标查询]，输入要查询的 index：\n";
				std::cin >> index;
				if (obj.Search(index) != nullptr)
				{
					std::cout << "value为 " << value << " 的结点存在，其值为";
					std::cout << (obj.Search(index))->_nodeData << std::endl;
				}
				else
				{
					std::cout << "您的下标越界了\n";
				}
				break;

			case 9:
				std::cout << "[09.查询大小]：" << obj.Size() << std::endl;
				break;

			case 10:
				obj.Print();
				break;

			case -1:
				goto BREAK;
				break;

			default:
				std::cout << "您的输入不在合法范围内\n";
				break;
			}
			std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";
			Menu();
			std::cout << "请输入对应的指令：";
			std::cin >> select;
		}
		//4.保存退出
	BREAK:

		std::cout << "您已成功退出程序，数据已经保存在当前工作目录下的limou.txt内\n";
	}

}

