#pragma once
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

	//3.RBTree类结构
	template <typename K, class V>
	class RBTree
	{
		typedef RBTreeNode<K, V> Node;

	public://3.1.成员函数
		bool Insert(const std::pair<K, V>& kv)
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
		
	public://3.3.测试函数
		//检查性质（辅助测试）
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
		//检查颜色（辅助测试）
		bool _Check(Node* root, int blackNum, int benchmark)
		{
			if (root == nullptr)
			{
				//走到空的时候就检查黑色结点的数量和是否相等（没有记录黑结点）
				if (benchmark != blackNum)
				{
					std::cout << "某条路径黑色节点的数量不相等,违反：4.对于每个结点，从该结点到其所有后代空叶子结点的路径上，均包含相同数目的黑色结点" << std::endl;
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
				&& root->_parent->_col == RED)//这里倒过来检查，如果检查父节点的子，有可能出现空的情况
			{
				std::cout << "存在连续的红色节点，违反：3.如果一个节点是红色的，则它的两个孩子结点是黑色的" << std::endl;
				return false;
			}

			return _Check(root->_left, blackNum, benchmark)
				&& _Check(root->_right, blackNum, benchmark);
		}
		bool IsBalance()
		{
			//根据红黑树的定义来检查
			//1.在每一个结点内增加一个存储颜色的字段（存储 Red 和 Black），保证每个结点不是红色就是黑色（这点可以不证明）
			
			//2.根节点、空叶子结点（也叫 NIL 结点）必须是黑色的
			if (_root && _root->_col == RED)
			{
				std::cout << "违反：2.根节点、空叶子结点（也叫 NIL 结点）必须是黑色的" << std::endl;
				return false;
			}

			//3.如果一个节点是红色的，则它的两个孩子结点是黑色的
			//4.对于每个结点，从该结点到其所有后代空叶子结点的路径上，均包含相同数目的黑色结点
			int benchmark = 0;//一个基准值
			Node* cur = _root;
			while (cur)//先走一条路，得出黑色结点的数量，然后检查每一条路径就可以了（没有记录黑空结点）
			{
				if (cur->_col == BLACK)
					++benchmark;
				cur = cur->_left;
			}
			return _Check(_root, 0, benchmark);//检查是否有连续红色节点
		}
		//检查高度（辅助测试）
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

	private://3.4.成员变量
		Node* _root = nullptr;
	};

	//4.测试函数（证明符合RB二叉搜索树）
	//4.1.证明一（有限证明）
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
		std::cout << "高度：" << r.Height() << std::endl;
	}
	//4.2.证明二（随机证明）
	void Test_2_RBTree()
	{
		//设置要插入的数量
		int size = 100000;

		//设置随机数
		srand(time(0));

		//开始插入验证
		RBTree<int, int> r;
		while (size--)
		{
			int x = rand();
			r.Insert(std::make_pair(x, x));
		}
		r.InOrder();
		r.IsBalance();
		std::cout << "高度：" << r.Height() << std::endl;
	}
}