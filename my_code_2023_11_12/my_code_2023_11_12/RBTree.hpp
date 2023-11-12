#pragma once

/* ---在很多库中的实现---
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
	//1.颜色结构体
	enum Colour
	{
		RED,
		BLACK
	};

	//2.结点结构体
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

	//3.RBTree类结构
	template <typename K, class T, class KeyOfT>
	class RBTree
	{
		typedef RBTreeNode<T> Node;

	public://3.1.成员函数
		~RBTree()
		{
			Destroy(_root);
			_root = nullptr;
		}

		/*
		下面的data已经是泛型了，有可能是Key，也有可能是Key - Value
		后者虽然可以直接比较大小，但是不是我们想要的，
		其底层比较的是先比较 key 再比较 value。
		而我们只期望比较 key 的值，为了解决这个问题，
		我们采用仿函数来对这种泛型进行比较
		*/
		bool Insert(const T& data)
		{
			//1.搜索二叉树插入的部分
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
				else//不可以等于
				{
					return false;
				}
			}

			cur = new Node(data);//默认新增加的是红色结点（这么设置会好一些，这个默认设置行为在RBTreeNode的构造函数里）

			if (kot(parent->_data) > kot(data))
			{
				parent->_left = cur;
			}
			else//parent->_kv.first < kv.first
			{
				parent->_right = cur;
			}

			cur->_parent = parent;

			//2.RBTree的部分开始
			while (parent && parent->_col == RED)//只要父节点为空（避免是根节点）或者父节点是黑（黑就随便插入，不影响RB定义）
			{
				Node* grandFather = parent->_parent;//parent是红的，就一定存在grandFather（只有parent为根节点才不会有grandFather）

				//根据 uncle 的位置来做类似的处理
				if (grandFather->_left == parent)
				{
					Node* uncle = grandFather->_right;

					//情况一：uncle 存在并且颜色为红
					if (uncle && uncle->_col == RED)
					{
						parent->_col = BLACK;//设置颜色
						uncle->_col = BLACK;
						grandFather->_col = RED;

						cur = grandFather;//继续往上调整
						parent = cur->_parent;
					}
					else//情况二：uncle 不存在或者颜色为黑
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
							//parent->_col = RED;//这句话可以不写
							grandFather->_col = RED;
						}
						break;
					}
				}
				else//grandFather->_right == parent
				{
					Node* uncle = grandFather->_left;

					//情况一：uncle 存在并且颜色为红
					if (uncle && uncle->_col == RED)
					{
						parent->_col = BLACK;//设置颜色
						uncle->_col = BLACK;
						grandFather->_col = RED;

						cur = grandFather;//继续往上调整
						parent = cur->_parent;
					}
					else//情况二：uncle 不存在或者颜色为黑
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
							//parent->_col = RED;//这句话可以不写
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

	private://3.2.辅助函数
		//左单旋
		void RotateL(Node* parent)
		{
			Node* subR = parent->_right;
			Node* subRL = subR->_left;
			Node* pparent = parent->_parent;

			//记录了四个指针parent、subR、subRL、pparent

			//步骤1
			parent->_right = subRL;
			//步骤2
			if (subRL)//不为空才连接
				subRL->_parent = parent;
			//步骤3
			subR->_left = parent;
			//步骤4
			parent->_parent = subR;
			//步骤5
			if (pparent == nullptr)//说明是从根结点开始旋转的
			{
				_root = subR;//换子
				_root->_parent = nullptr;//置空
			}
			else//如果不是根
			{
				if (pparent->_left == parent)
				{
					pparent->_left = subR;//换子
				}
				else
				{
					pparent->_right = subR;//换子
				}
				subR->_parent = pparent;//换父
			}

			//无需更新平衡因子（RBTree没有这个东西）
			//parent->_bf = subR->_bf = 0;
		}
		//右单旋
		void RotateR(Node* parent)
		{
			Node* subL = parent->_left;
			Node* subLR = subL->_right;
			Node* pparent = parent->_parent;

			//记录了四个指针parent、subR、subRL、pparent

			//步骤1
			parent->_left = subLR;
			//步骤2
			if (subLR)//不为空才连接
				subLR->_parent = parent;
			//步骤3
			subL->_right = parent;
			//步骤4
			parent->_parent = subL;
			//步骤5
			if (pparent == nullptr)//说明是从根结点开始旋转的
			{
				_root = subL;//换子
				_root->_parent = nullptr;//置空
			}
			else//如果不是根
			{
				if (pparent->_left == parent)
				{
					pparent->_left = subL;//换子
				}
				else
				{
					pparent->_right = subL;//换子
				}
				subL->_parent = pparent;//换父
			}

			//无需更新平衡因子（RBTree没有这个东西）
			//parent->_bf = subL->_bf = 0;
		}
		//销毁
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

	private://3.4.成员变量
		Node* _root = nullptr;
	};
}