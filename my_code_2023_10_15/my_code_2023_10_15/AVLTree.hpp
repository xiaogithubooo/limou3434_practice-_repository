#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <cassert>
using namespace std;
namespace limou
{
	//����д����K-Vģ��
	//1.���
	template <typename Key, typename Value>
	struct AVLTreeNode
	{
		AVLTreeNode<Key, Value>* _left;
		AVLTreeNode<Key, Value>* _right;
		AVLTreeNode<Key, Value>* _parent;//��ָ������Ҹ��ڵ㣬����Ҫ�����ά��
		pair<Key, Value> _kv;
		int _bf;//ƽ������

		//��㹹�캯��
		AVLTreeNode(const pair<Key, Value>& kv)
			: _left(nullptr), _right(nullptr), _parent(nullptr), _kv(kv), _bf(0) {}
	};
	//2.��
	template <typename Key, typename Value>
	class AVLTree
	{
		typedef AVLTreeNode<Key, Value> Node;
	public:
		bool Inster(const pair<Key, Value>& kv)
		{
			//�����������Ĳ���
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
				else
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

			//AVL�Ĳ��ֿ�ʼ
			//����cur�󣬸��½��ĸ��ڵ�ƽ�����ӣ�
			//if(cur == parent->right) parent->bf++
			//else(cur == parent->left) parent->bf--
			//Ȼ��������������
			//if(parent->bf == 1 || parent->bf == -1)��
			//{
			//	˵�������ԭ����ƽ�����ӱ�Ϊ parent->bf == 0��
			//	��˵������󸸽ڵ�����������߶Ȳ���˸ı䣬
			//  ��Ҫ���ϳ������¸��ڵ�Ĳ���/ȫ������ƽ������
			//	if(cur == parent->right) parent->bf++
			//	else(cur == parent->left) parent->bf--
			//	...
			//}
			//else if(parent->bf == 2 || parent->bf == -2)
			//{
			//	˵�����ڵ����ڵ����������Ѿ���ƽ���ˣ���Ҫ��ת
			//}
			//else
			//{
			//	ԭ����parent->bf == 1 or parent->bf == -1��
			//	���²����cur�Ѹ߶ȵ͵���������ˣ���˵����
			//	���ڵ��������������˾���ƽ�⣬�����������
			//}
			//���ڲ������Ӱ���Լ��Ĳ���/ȫ�������ȣ�������ǵĽṹ����_parentָ��
			//Ȼ����Ҫע���п��ܻ���µ������ȥ����������

			while (parent)//�����µ����ڵ�
			{
				if (cur == parent->_right)
				{
					parent = _bf++;
				}
				else//cur == parent->_left
				{
					parent = _bf--;
				}

				if (parent->_bf == 1 || parent->_bf = -1)
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
				}
				else
				{
					assert(false);//���������Լ�����ʹ��
				}
			}

			return true;
		}
	private:
		Node* _root = nullptr;
	};
}