#include <iostream>
#include <utility>
#include <cassert>
using namespace std;

namespace limou
{
	//1.结点结构体
	template <typename Key, typename Value>
	struct Node
	{
		Node* _left;
		Node* _right;
		Node* _parent;
		pair<Key, Value> _kv;
		Node()
			: _left(nullptr)
			, _right(nullptr)
			, _parentright(nullptr)
			, _kv(Key(), Value())
		{}
	};

	//2.AVLTree类
	template <typename Key, typename Value>
	class AVLTree
	{
	public:
		bool Inster(const pair<Key, Value>& kv)
		{
			//搜索二叉树的部分
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

			//AVL的部分开始
			//插入cur后，更新结点的父节点平衡因子：
			//if(cur == parent->right) parent->bf++
			//else(cur == parent->left) parent->bf--
			//然后出现以下情况：
			//if(parent->bf == 1 || parent->bf == -1)，
			//{
			//	说明父结点原本的平衡因子必为 parent->bf == 0，
			//	就说明插入后父节点的左右子树高度差发生了改变，
			//  则要向上持续更新父节点的部分/全部祖先平衡因子
			//	if(cur == parent->right) parent->bf++
			//	else(cur == parent->left) parent->bf--
			//	...
			//}
			//else if(parent->bf == 2 || parent->bf == -2)
			//{
			//	说明父节点所在的左右子树已经不平衡了，需要旋转
			//}
			//else
			//{
			//	原本是parent->bf == 1 or parent->bf == -1，
			//	而新插入的cur把高度低的子树变高了，这说明：
			//	父节点的左右子树变成了绝对平衡，无需更新祖先
			//}
			//由于插入结点会影响自己的部分/全部的祖先，因此我们的结构加上_parent指针
			//然后需要注意有可能会更新到根结点去（最差情况）

			while (parent)//最差更新到根节点
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
					//继续更新
					parent = parent->_parent;
					cur = cur->_parent;
				}
				else if (parent->_bf == 0)
				{
					break;
				}
				else if (parent->_bf == 2 || parent->_bf == -2)
				{
					//旋转
				}
				else
				{
					assert(false);//留给我们自己调试使用
				}
			}

			return true;
		}
	private:
		Node<Key, Value>* _root;
	};
}