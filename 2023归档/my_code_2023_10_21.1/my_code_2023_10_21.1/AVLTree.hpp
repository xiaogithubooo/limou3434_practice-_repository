#include <iostream>
#include <utility>
#include <cassert>
using namespace std;

namespace limou
{
	//1.���ṹ��
	template <typename Key, typename Value>
	struct AVLTreeNode
	{
		AVLTreeNode<Key, Value>* _left;
		AVLTreeNode<Key, Value>* _right;
		AVLTreeNode<Key, Value>* _parent;
		pair<Key, Value> _kv;
		int _bf;

		AVLTreeNode(const pair<Key, Value>& kv)
			: _left(nullptr)
			, _right(nullptr)
			, _parent(nullptr)
			, _kv(kv)
			, _bf(0)
		{}
	};

	//2.AVLTree��
	template <typename Key, typename Value>
	class AVLTree
	{
		typedef AVLTreeNode<Key, Value> Node;
	public:
		bool Inster(const pair<Key, Value>& kv)
		{
			//1.��������������Ĳ���
			if (_root == nullptr)
			{
				_root = new Node(kv);
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

			cur = new Node(kv);

			if (parent->_kv.first > kv.first)
			{
				parent->_left = cur;
			}
			else//parent->_kv.first < kv.first)
			{
				parent->_right = cur;
			}

			cur->_parent = parent;

			//2.AVL�Ĳ��ֿ�ʼ
			
			//����cur�󣬸��½��ĸ��ڵ�ƽ�����ӣ�
			//if(cur == parent->right) 
			//	parent->_bf++
			//else(cur == parent->left)
			//	parent->_bf--
			//Ȼ��������������
			//if(parent->_bf == 1 || parent->_bf == -1)��
			//{
			//	˵�������ԭ����ƽ�����ӱ�Ϊ parent->_bf == 0��
			//	��˵������󸸽ڵ�����������߶Ȳ���˸ı䣬
			//  ��Ҫ���ϳ������¸��ڵ�Ĳ���/ȫ������ƽ������
			//	if(cur == parent->right) parent->_bf++
			//	else(cur == parent->left) parent->_bf--
			//	...
			//}
			//else if(parent->_bf == 2 || parent->_bf == -2)
			//{
			//	˵�����ڵ����ڵ����������Ѿ���ƽ���ˣ���Ҫ��ת
			//}
			//else
			//{
			//	ԭ����parent->_bf == 1 or parent->_bf == -1��
			//	���²����cur�Ѹ߶ȵ͵���������ˣ���˵����
			//	���ڵ��������������˾���ƽ�⣨ƽ������==0���������������
			//}
			//���ڲ������Ӱ���Լ��Ĳ���/ȫ�������ȣ�������ǵĽṹ����_parentָ��
			//Ȼ����Ҫע���п��ܻ���µ������ȥ����������

			while (parent)//�����µ����ڵ㣬�����ĸ��ڵ�Ϊ�գ��Ϳ���ͣ��
			{
				if (cur == parent->_right)
				{
					parent->_bf++;
				}
				else//cur == parent->_left
				{
					parent->_bf--;
				}

				if (parent->_bf == 1 || parent->_bf == -1)
				{
					//��������
					parent = parent->_parent;
					cur = cur->_parent;
				}
				else if (parent->_bf == 0)
				{
					break;
				}
				else if (parent->_bf == 2 || parent->_bf == -2)
				{
					//��ת
					if (parent->_bf == 2 && cur->_bf == 1)//����
					{
						RotateL(parent);
					}
					else if (parent->_bf == -2 && cur->_bf == -1)//�ҵ���
					{
						RotateR(parent);
					}
					else if (parent->_bf == -2 && cur->_bf == 1)//����˫��
					{
						RotateLAndR(parent);
					}
					else if (parent->_bf == 2 && cur->_bf == -1)//����˫��
					{
						RotateRAndL(parent);
					}
					else
					{
						assert(false);
					}
					break;
				}
				else
				{
					assert(false);//���������Լ�����ʹ��
				}
			}

			return true;
		}

		//2.�������
		void InOrder()
		{
			_InOrder(_root);
			std::cout << std::endl;
		}

		//3.����Ƿ�ƽ��
		bool IsBalance()
		{
			return _IsBalance(_root);
		}


	private:
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

			//����ƽ������
			parent->_bf = subR->_bf = 0;
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

			//����ƽ������
			parent->_bf = subL->_bf = 0;
		}
		//˫�����������ҵ���
		void RotateLAndR(Node* parent)
		{
			Node* subL = parent->_left;
			Node* subLR = subL->_right;
			int bf = subLR->_bf;

			//����ĸ��ô���ܼ򵥣�����˫�������ѵ������Ǹ���ƽ������
			RotateL(parent->_left);
			RotateR(parent);

			if (bf == -1)//�ڽϸ����������������Ҳ���
			{
				parent->_bf = 1;
				subLR->_bf = 0;
				subL->_bf = 0;
			}
			else if (bf == 1)//�ڽϸ��������������������
			{
				parent->_bf = 0;
				subLR->_bf = 0;
				subL->_bf = -1;
			}
			else if (bf == 0)//����д�ϣ��߼�������
			{
				parent->_bf = 0;
				subLR->_bf = 0;
				subL->_bf = 0;
			}
			else
			{
				assert(false);//���Լ�����ʹ��
			}
		}
		//˫�����ҵ���������
		void RotateRAndL(Node* parent)
		{
			Node* subR = parent->_right;
			Node* subRL = subR->_left;
			int bf = subRL->_bf;

			//����ĸ��ô���ܼ򵥣�����˫�������ѵ������Ǹ���ƽ������
			RotateR(parent->_right);
			RotateL(parent);

			if (bf == -1)//�ڽϸ��������������������
			{
				parent->_bf = 0;
				subRL->_bf = 0;
				subR->_bf = 1;
			}
			else if (bf == 1)//�ڽϸ����������������Ҳ���
			{
				parent->_bf = -1;
				subRL->_bf = 0;
				subR->_bf = 0;
			}
			else if (bf == 0)//����д�ϣ��߼�������
			{
				parent->_bf = 0;
				subRL->_bf = 0;
				subR->_bf = 0;
			}
			else
			{
				assert(false);//���Լ�����ʹ��
			}
		}
		//�����Ӻ���
		void _InOrder(Node* root)
		{
			if (root == nullptr)
			{
				return;
			}

			_InOrder(root->_left);
			std::cout << root->_kv.first << "-" << root->_kv.second << " ";
			_InOrder(root->_right);
		}
		//�ж�ƽ����Ӻ���
		int _Height(Node* root)
		{
			if (root == nullptr)
			{
				return 0;
			}
			int leftHeight = _Height(root->_left);
			int rightHeight = _Height(root->_right);
			return  leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
		}
		bool _IsBalance(Node* root)
		{
			if (root == nullptr)
			{
				return true;
			}
			int leftH = _Height(root->_left);
			int rightH = _Height(root->_right);

			if (rightH - leftH != root->_bf)//���ƽ������
			{
				std::cout << "ƽ�������쳣:" << root->_kv.first << "-" << root->_kv.second << std::endl;
				return false;
			}

			return abs(leftH - rightH) < 2
				&& _IsBalance(root->_left)
				&& _IsBalance(root->_right);
		}
	private:
		Node* _root = nullptr;
	};
}