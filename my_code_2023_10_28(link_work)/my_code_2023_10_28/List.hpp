/*
1.ʵ�����Ա��:
	1.1.���롢ɾ������չ�������޸�ԭ˳�����ĳ��Ԫ�ص����ݣ�
	1.2.�������չ��������������
	1.3.���Ҹ���ֵ e�����ҵ� i ��λ��Ԫ��
	1.4.Ҫ���д�ĳ����Բ˵���ʽ������
2.����ʽ�洢�ṹʵ��һԪ����ʽ��������㣻
3.����˫������ʵ��ͨѶ¼�Ľ�����ɾ�����������б����ɱ������ļ���������װ�롣
*/

//��ʹ����˫��ѭ����ͷ������ʵ�����Ա�

#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <cassert>
#include <cstdio>
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
		//1.Ĭ�ϳ�Ա
		LinkList() : _node(new Node<T>), _size(0) {}//����
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

		//2.��ɾ����
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

		//3.��������
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
		//3.3.������ӣ�β����ʼ��ӣ�
		void AddTwoNumbers(const LinkList<T>& list)//���������Ĭ�ϵĿ���
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
		//4.��Ա����
		Node<T>* _node;//ָ���ڱ��ڵ�
		int _size;//��¼��С��������ͷ�ڵ㣩
	};

	//3.�˵�
	void Menu()
	{
		std::cout << "|--------------------------------------------------|\n";
		std::cout << "| �����������Ѿ���������һ����������������ɾ��� |\n";
		std::cout << "|--------------------------------------------------|\n";
		std::cout << "|       01.β��   02.ͷ��  03.βɾ   04.ͷɾ       |\n";
		std::cout << "|       05.����ǰ��        06.����ɾ��             |\n";
		std::cout << "|       07.����Val����     08.�����±����         |\n";
		std::cout << "|       09.��ѯ��С        10.��ӡ����             |\n";
		std::cout << "|--------------------------------------------------|\n";
		std::cout << "|                   �˳�������-1                   |\n";
		std::cout << "|--------------------------------------------------|\n";
		std::cout << "�������Ӧ��ָ�";
	}

	template <typename T>
	void Drive()
	{
		//0.��������
		LinkList<T> obj;

		//1.��ӡ�˵�
		Menu();

		//2.����ָ��
		int select = 0;
		std::cin >> select;

		//3.����ָ��
		while (select != -1)
		{
			T value = 0;
			int index = 0;
			Node<T>* cache = nullptr;

			switch (select)
			{
			case 1:
				std::cout << "[01.β��]��������Ҫβ��� value ֵ��";
				std::cin >> value;
				obj.Push_back(value);
				break;

			case 2:
				std::cout << "[02.ͷ��]��������Ҫͷ��� value ֵ��";
				std::cin >> value;
				obj.Push_front(value);
				break;

			case 3:
				std::cout << "[03.βɾ]\n";
				obj.Pop_back();
				break;

			case 4:
				std::cout << "[04.ͷɾ]\n";
				obj.Pop_front();
				break;

			case 5:
				std::cout << "[05.����ǰ��]�����뱻ǰ���� index �Ͳ���� value��\n";
				std::cin >> index;
				std::cin >> value;
				if (index >= obj.Size())
				{
					std::cout << "����Ƿ����±�Խ��\n";
					break;
				}
				cache = obj.Search(index);
				obj.Insert(cache, value);
				break;

			case 6:
				std::cout << "[06.����ɾ��]�����뱻ɾ������ index��\n";
				std::cin >> index;
				if (index >= obj.Size())
				{
					std::cout << "����Ƿ����±�Խ��\n";
					break;
				}
				cache = obj.Search(index);
				obj.Erase(cache);
				break;

			case 7:
				std::cout << "[07.����Val��ѯ]������Ҫ��ѯ�� value��";
				std::cin >> value;
				if (obj.Find(value) != nullptr)
				{
					std::cout << "valueΪ " << value << " �Ľ�����\n";
				}
				else
				{
					std::cout << "valueΪ " << value << " �Ľ�㲻����\n";
				}
				break;

			case 8:
				std::cout << "[08.�����±��ѯ]������Ҫ��ѯ�� index��\n";
				std::cin >> index;
				if (obj.Search(index) != nullptr)
				{
					std::cout << "valueΪ " << value << " �Ľ����ڣ���ֵΪ";
					std::cout << (obj.Search(index))->_nodeData << std::endl;
				}
				else
				{
					std::cout << "�����±�Խ����\n";
				}
				break;

			case 9:
				std::cout << "[09.��ѯ��С]��" << obj.Size() << std::endl;
				break;

			case 10:
				obj.Print();
				break;

			case -1:
				goto BREAK;
				break;

			default:
				std::cout << "�������벻�ںϷ���Χ��\n";
				break;
			}
			std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";
			Menu();
			std::cin >> select;
		}

		//4.�����˳�
	BREAK:
		//4.1.���ļ�
		FILE* fp = fopen("limou.txt", "w+");//�����ļ�����д�룬�������ݾ͸���
		assert(fp);

		//4.2.����д����ַ���
		std::string ret;
		for (int i = 0; i < obj.Size(); i++)
		{
			ret += std::to_string(obj.Search(i)->_nodeData);
			ret += " ";
			if (i % 5 == 0) std::cout << std::endl;
		}

		fprintf(fp, ret.c_str());
		std::cout << "���ѳɹ��˳����������Ѿ������ڵ�ǰ����Ŀ¼�µ�limou.txt��\n";
	}

	//4.����ʽ
	template <typename T>
	void Polynomial()
	{
		//4.1.��������
		LinkList<T> obj_1;
		LinkList<T> obj_2;
		int size = 0;
		int* numbers = nullptr;
		//obj_1 = (6 * x^3) + (0 * x^2) + (1 * x^1) + (5 * x^0)
		//obj_2 = (7 * x^1) + (10 * x^0)

		//4.2.����ϵ������
		std::cout << "������ ����ʽ1 ������������";
		std::cin >> size;
		numbers = new int[size];
		std::cout << "������ ����ʽ1 ��ϵ������������0����";
		for (int i = size - 1; i >= 0; i--)
		{
			std::cin >> numbers[i];
			obj_1.Push_front(numbers[i]);
		}

		std::cout << "������ ����ʽ2 ������������";
		std::cin >> size;
		numbers = new int[size];
		std::cout << "������ ����ʽ2 ��ϵ������������0����";
		for (int i = size - 1; i >= 0; i--)
		{
			std::cin >> numbers[i];
			obj_2.Push_front(numbers[i]);
		}

		std::cout << "����ʽ1�Ͷ���ʽ2Ϊ��\n";
		obj_1.Print();
		obj_2.Print();

		//4.3.�������
		obj_1.AddTwoNumbers(obj_2);
		obj_1.Print();
	}
}

