#pragma once
#include <utility>
namespace limou
{
	enum Colour
	{
		RED,
		BLACK
	};

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

	template <typename K, class V>
	class RBTree
	{
		typedef RBTreeNode<K, V> Node;
	public:
		bool Insert(const pair<K, V>& kv)
		{
			//1.搜索二叉树插入的部分
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
				else//不可以等于
				{
					return false;
				}
			}

			cur = new Node(kv);//默认新增加的是红色结点（这么设置会好一些，这个默认设置行为在RBTreeNode的构造函数里）

			if (parent->_kv.first > kv.first)
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
				if (grandFather->_left == parent)
				{
					Node* uncle = grandFather->_right;
					if (uncle && uncle->_col == RED)//uncle存在并且颜色为红
					{
						parent->_co	3l = BLACK;
						uncle->_col = BLACK;
						grandFather->_col = RED;
						
						cur = grandFather;//继续往上调整
						parent = cur->_parent;
					}
					else
					{

					}
				}
			}

			_root->_col = BLACK;
			return true;
		}
	private:
		Node* _root;
	};
}