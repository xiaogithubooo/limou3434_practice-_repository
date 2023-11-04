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

#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <cassert>
#include <cstdio>
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
		//1.默认成员
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

		//2.插删操作
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
		Node<T>* Search(int index)
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

		//3.其他操作
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
		//3.3.链表相加（尾部开始相加）
		void AddTwoNumbers(const LinkList<T>& list)//这里调用了默认的拷贝
		{
			Node<T>* cur1 = this->_node->_nodeNext;
			Node<T>* cur2 = list._node->_nodeNext;
			while (cur1 != _node && cur2 != list._node)
			{
				cur1->_nodeData = cur1->_nodeData + cur2->_nodeData;

				cur1 = cur1->_nodeNext;
				cur2 = cur2->_nodeNext;
			}
			while (cur2 != list._node)
			{
				Push_back(cur2->_nodeData);
				cur2 = cur2->_nodeNext;
			}

		}

	private:
		//4.成员变量
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
				if (index >= obj.Size())
				{
					std::cout << "输入非法，下标越界\n";
					break;
				}
				cache = obj.Search(index);
				obj.Insert(cache, value);
				break;

			case 6:
				std::cout << "[06.任意删除]，输入被删除结点的 index：\n";
				std::cin >> index;
				if (index >= obj.Size())
				{
					std::cout << "输入非法，下标越界\n";
					break;
				}
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
			std::cin >> select;
		}

		//4.保存退出
	BREAK:
		//4.1.打开文件
		FILE* fp = fopen("limou.txt", "w+");//创建文件并且写入，如有内容就覆盖
		assert(fp);

		//4.2.创建写入的字符串
		std::string ret;
		for (int i = 0; i < obj.Size(); i++)
		{
			ret += std::to_string(obj.Search(i)->_nodeData);
			ret += " ";
			if (i % 5 == 0) std::cout << std::endl;
		}

		fprintf(fp, ret.c_str());
		std::cout << "您已成功退出程序，数据已经保存在当前工作目录下的limou.txt内\n";
	}

	//4.多项式
	template <typename T>
	void Polynomial()
	{
		//4.1.创建对象
		LinkList<T> obj_1;
		LinkList<T> obj_2;
		int size = 0;
		int* numbers = nullptr;
		//obj_1 = (6 * x^3) + (0 * x^2) + (1 * x^1) + (5 * x^0)
		//obj_2 = (7 * x^1) + (10 * x^0)

		//4.2.输入系数数据
		std::cout << "请输入 多项式1 的项数个数：";
		std::cin >> size;
		numbers = new int[size];
		std::cout << "请输入 多项式1 的系数（可以输入0）：";
		for (int i = size - 1; i >= 0; i--)
		{
			std::cin >> numbers[i];
			obj_1.Push_front(numbers[i]);
		}

		std::cout << "请输入 多项式2 的项数个数：";
		std::cin >> size;
		numbers = new int[size];
		std::cout << "请输入 多项式2 的系数（可以输入0）：";
		for (int i = size - 1; i >= 0; i--)
		{
			std::cin >> numbers[i];
			obj_2.Push_front(numbers[i]);
		}

		std::cout << "多项式1和多项式2为：\n";
		obj_1.Print();
		obj_2.Print();

		//4.3.相加链表
		obj_1.AddTwoNumbers(obj_2);
		obj_1.Print();
	}
}

