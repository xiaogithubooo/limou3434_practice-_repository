#pragma once

/* ---�ںܶ���е�ʵ��---
template <class Value>
struct __rb_tree_node : public __rb_tree_node_base
{
	typedef __rb_tree_node<Value>* link_type;
	Value value_field;
};

template <class Key, class Value, class KeyOfValue, class Compare, class Alloc = alloc>
class rb_tree
{
	typedef __rb_tree_node<Value> rb_tree_node;
	typedef rb_tree_node* link_type;
	size_type node_count;
	link_type header;
};
*/

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
	template <class T>
	struct RBTreeNode
	{
		RBTreeNode<T>* _left;
		RBTreeNode<T>* _right;
		RBTreeNode<T>* _parent;
		T _data;
		Colour _col;

		RBTreeNode(const T& data)
			: _left(nullptr)
			, _right(nullptr)
			, _parent(nullptr)
			, _data(data)
			, _col(RED)
		{}
	};

	//3.RBTree��ṹ
	template <typename K, class T, class KeyOfT>
	class RBTree
	{
		typedef RBTreeNode<T> Node;

	public://3.1.��Ա����
		~RBTree()
		{
			Destroy(_root);
			_root = nullptr;
		}

		/*
		�����data�Ѿ��Ƿ����ˣ��п�����Key��Ҳ�п�����Key - Value
		������Ȼ����ֱ�ӱȽϴ�С�����ǲ���������Ҫ�ģ�
		��ײ�Ƚϵ����ȱȽ� key �ٱȽ� value��
		������ֻ�����Ƚ� key ��ֵ��Ϊ�˽��������⣬
		���ǲ��÷º����������ַ��ͽ��бȽ�
		*/
		bool Insert(const T& data)
		{
			//1.��������������Ĳ���
			if (_root == nullptr)
			{
				_root = new Node(data);
				_root->_col = BLACK;
				return true;
			}

			KeyOfT kot;
			Node* parent = nullptr;
			Node* cur = _root;
			while (cur)
			{
				if (kot(cur->_data) < kot(data))
				{
					parent = cur;
					cur = cur->_right;
				}
				else if (kot(cur->_data) > kot(data))
				{
					parent = cur;
					cur = cur->_left;
				}
				else//�����Ե���
				{
					return false;
				}
			}

			cur = new Node(data);//Ĭ�������ӵ��Ǻ�ɫ��㣨��ô���û��һЩ�����Ĭ��������Ϊ��RBTreeNode�Ĺ��캯���

			if (kot(parent->_data) > kot(data))
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
		Node* Find(const K& key)
		{
			Node* cur = _root;
			KeyOfT kot;
			while (cur)
			{
				if (kot(cur->_data) < key)
				{
					cur = cur->_right;
				}
				else if (kot(cur->_data) > key)
				{
					cur = cur->_left;
				}
				else
				{
					return cur;
				}
			}
			return nullptr;
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
		//����
		void Destroy(Node* root)
		{
			if (root == nullptr)
			{
				return;
			}
			Destroy(root->_left);
			Destroy(root->_right);
			delete root;
		}

	private://3.4.��Ա����
		Node* _root = nullptr;
	};
}