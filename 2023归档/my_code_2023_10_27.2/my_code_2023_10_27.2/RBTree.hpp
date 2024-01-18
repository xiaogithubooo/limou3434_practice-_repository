#pragma once
#include <iostream>
#include <utility>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <ctime>
namespace limou
{
	//1.��ɫ�ṹ��
	enum Colour
	{
		RED,
		BLACK
	};

	//2.���ṹ��
	template <typename K, class V>
	struct RBTreeNode
	{
		RBTreeNode<K, V>* _left;
		RBTreeNode<K, V>* _right;
		RBTreeNode<K, V>* _parent;
		std::pair<K, V> _kv;
		Colour _col;

		RBTreeNode(const std::pair<K, V>& kv)
			: _left(nullptr)
			, _right(nullptr)
			, _parent(nullptr)
			, _kv(kv)
			, _col(RED)
		{}
	};

	//3.RBTree��ṹ
	template <typename K, class V>
	class RBTree
	{
		typedef RBTreeNode<K, V> Node;

	public://3.1.��Ա����
		bool Insert(const std::pair<K, V>& kv)
		{
			//1.��������������Ĳ���
			if (_root == nullptr)
			{
				_root = new Node(kv);
				_root->_col = BLACK;
				return true;
			}

			Node* parent = nullptr;
			Node* cur = _root;
			while (cur)
			{
				if (cur->_kv.first < kv.first)
				{
					parent = cur;
					cur = cur->_right;
				}
				else if (cur->_kv.first > kv.first)
				{
					parent = cur;
					cur = cur->_left;
				}
				else//�����Ե���
				{
					return false;
				}
			}

			cur = new Node(kv);//Ĭ�������ӵ��Ǻ�ɫ��㣨��ô���û��һЩ�����Ĭ��������Ϊ��RBTreeNode�Ĺ��캯���

			if (parent->_kv.first > kv.first)
			{
				parent->_left = cur;
			}
			else//parent->_kv.first < kv.first
			{
				parent->_right = cur;
			}

			cur->_parent = parent;

			//2.RBTree�Ĳ��ֿ�ʼ
			while (parent && parent->_col == RED)//ֻҪ���ڵ�Ϊ�գ������Ǹ��ڵ㣩���߸��ڵ��Ǻڣ��ھ������룬��Ӱ��RB���壩
			{
				Node* grandFather = parent->_parent;//parent�Ǻ�ģ���һ������grandFather��ֻ��parentΪ���ڵ�Ų�����grandFather��
				
				//���� uncle ��λ���������ƵĴ���
				if (grandFather->_left == parent)
				{
					Node* uncle = grandFather->_right;

					//���һ��uncle ���ڲ�����ɫΪ��
					if (uncle && uncle->_col == RED)
					{
						parent->_col = BLACK;//������ɫ
						uncle->_col = BLACK;
						grandFather->_col = RED;
						
						cur = grandFather;//�������ϵ���
						parent = cur->_parent;
					}
					else//�������uncle �����ڻ�����ɫΪ��
					{
						if (cur == parent->_left)
						{

							//     g
							//   p   u
							// c
							RotateR(grandFather);
							parent->_col = BLACK;
							grandFather->_col = RED;
						}
						else
						{
							//     g
							//   p   u
							//     c
							RotateL(parent);
							RotateR(grandFather);
							cur->_col = BLACK;
							//parent->_col = RED;//��仰���Բ�д
							grandFather->_col = RED;
						}
						break;
					}
				}
				else//grandFather->_right == parent
				{
					Node* uncle = grandFather->_left;

					//���һ��uncle ���ڲ�����ɫΪ��
					if (uncle && uncle->_col == RED)
					{
						parent->_col = BLACK;//������ɫ
						uncle->_col = BLACK;
						grandFather->_col = RED;

						cur = grandFather;//�������ϵ���
						parent = cur->_parent;
					}
					else//�������uncle �����ڻ�����ɫΪ��
					{
						if (cur == parent->_right)
						{

							//     g
							//   u   p
							//         c
							RotateL(grandFather);
							parent->_col = BLACK;
							grandFather->_col = RED;
						}
						else
						{
							//     g
							//   u   p
							//     c
							RotateR(parent);
							RotateL(grandFather);
							cur->_col = BLACK;
							//parent->_col = RED;//��仰���Բ�д
							grandFather->_col = RED;
						}
						break;
					}
				}
			}

			_root->_col = BLACK;
			return true;
		}

	private://3.2.��������
		//����
		void RotateL(Node* parent)
		{
			Node* subR = parent->_right;
			Node* subRL = subR->_left;
			Node* pparent = parent->_parent;

			//��¼���ĸ�ָ��parent��subR��subRL��pparent

			//����1
			parent->_right = subRL;
			//����2
			if (subRL)//��Ϊ�ղ�����
				subRL->_parent = parent;
			//����3
			subR->_left = parent;
			//����4
			parent->_parent = subR;
			//����5
			if (pparent == nullptr)//˵���ǴӸ���㿪ʼ��ת��
			{
				_root = subR;//����
				_root->_parent = nullptr;//�ÿ�
			}
			else//������Ǹ�
			{
				if (pparent->_left == parent)
				{
					pparent->_left = subR;//����
				}
				else
				{
					pparent->_right = subR;//����
				}
				subR->_parent = pparent;//����
			}

			//�������ƽ�����ӣ�RBTreeû�����������
			//parent->_bf = subR->_bf = 0;
		}
		//�ҵ���
		void RotateR(Node* parent)
		{
			Node* subL = parent->_left;
			Node* subLR = subL->_right;
			Node* pparent = parent->_parent;

			//��¼���ĸ�ָ��parent��subR��subRL��pparent

			//����1
			parent->_left = subLR;
			//����2
			if (subLR)//��Ϊ�ղ�����
				subLR->_parent = parent;
			//����3
			subL->_right = parent;
			//����4
			parent->_parent = subL;
			//����5
			if (pparent == nullptr)//˵���ǴӸ���㿪ʼ��ת��
			{
				_root = subL;//����
				_root->_parent = nullptr;//�ÿ�
			}
			else//������Ǹ�
			{
				if (pparent->_left == parent)
				{
					pparent->_left = subL;//����
				}
				else
				{
					pparent->_right = subL;//����
				}
				subL->_parent = pparent;//����
			}

			//�������ƽ�����ӣ�RBTreeû�����������
			//parent->_bf = subL->_bf = 0;
		}
		
	public://3.3.���Ժ���
		//������ʣ��������ԣ�
		void _InOrder(Node* root)
		{
			if (root == nullptr)
			{
				return;
			}

			_InOrder(root->_left);
			std::cout << root->_kv.first << " ";
			_InOrder(root->_right);
		}
		void InOrder()
		{
			_InOrder(_root);
			std::cout << std::endl;
		}
		//�����ɫ���������ԣ�
		bool _Check(Node* root, int blackNum, int benchmark)
		{
			if (root == nullptr)
			{
				//�ߵ��յ�ʱ��ͼ���ɫ�����������Ƿ���ȣ�û�м�¼�ڽ�㣩
				if (benchmark != blackNum)
				{
					std::cout << "ĳ��·����ɫ�ڵ�����������,Υ����4.����ÿ����㣬�Ӹý�㵽�����к����Ҷ�ӽ���·���ϣ���������ͬ��Ŀ�ĺ�ɫ���" << std::endl;
					return false;
				}

				return true;
			}

			if (root->_col == BLACK)
			{
				++blackNum;
			}

			if (root->_col == RED
				&& root->_parent
				&& root->_parent->_col == RED)//���ﵹ������飬�����鸸�ڵ���ӣ��п��ܳ��ֿյ����
			{
				std::cout << "���������ĺ�ɫ�ڵ㣬Υ����3.���һ���ڵ��Ǻ�ɫ�ģ��������������ӽ���Ǻ�ɫ��" << std::endl;
				return false;
			}

			return _Check(root->_left, blackNum, benchmark)
				&& _Check(root->_right, blackNum, benchmark);
		}
		bool IsBalance()
		{
			//���ݺ�����Ķ��������
			//1.��ÿһ�����������һ���洢��ɫ���ֶΣ��洢 Red �� Black������֤ÿ����㲻�Ǻ�ɫ���Ǻ�ɫ�������Բ�֤����
			
			//2.���ڵ㡢��Ҷ�ӽ�㣨Ҳ�� NIL ��㣩�����Ǻ�ɫ��
			if (_root && _root->_col == RED)
			{
				std::cout << "Υ����2.���ڵ㡢��Ҷ�ӽ�㣨Ҳ�� NIL ��㣩�����Ǻ�ɫ��" << std::endl;
				return false;
			}

			//3.���һ���ڵ��Ǻ�ɫ�ģ��������������ӽ���Ǻ�ɫ��
			//4.����ÿ����㣬�Ӹý�㵽�����к����Ҷ�ӽ���·���ϣ���������ͬ��Ŀ�ĺ�ɫ���
			int benchmark = 0;//һ����׼ֵ
			Node* cur = _root;
			while (cur)//����һ��·���ó���ɫ����������Ȼ����ÿһ��·���Ϳ����ˣ�û�м�¼�ڿս�㣩
			{
				if (cur->_col == BLACK)
					++benchmark;
				cur = cur->_left;
			}
			return _Check(_root, 0, benchmark);//����Ƿ���������ɫ�ڵ�
		}
		//���߶ȣ��������ԣ�
		int _Height(Node* root)
		{
			if (root == NULL)
				return 0;

			int leftH = _Height(root->_left);
			int rightH = _Height(root->_right);

			return leftH > rightH ? leftH + 1 : rightH + 1;
		}
		int Height()
		{
			return _Height(_root);
		}

	private://3.4.��Ա����
		Node* _root = nullptr;
	};

	//4.���Ժ�����֤������RB������������
	//4.1.֤��һ������֤����
	void Test_1_RBTree()
	{
		int arr[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
		RBTree<int, int> r;
		for (auto e : arr)
		{
			r.Insert(std::make_pair(e, e));
		}
		r.InOrder();
		r.IsBalance();
		std::cout << "�߶ȣ�" << r.Height() << std::endl;
	}
	//4.2.֤���������֤����
	void Test_2_RBTree()
	{
		//����Ҫ���������
		int size = 100000;

		//���������
		srand(time(0));

		//��ʼ������֤
		RBTree<int, int> r;
		while (size--)
		{
			int x = rand();
			r.Insert(std::make_pair(x, x));
		}
		r.InOrder();
		r.IsBalance();
		std::cout << "�߶ȣ�" << r.Height() << std::endl;
	}
}