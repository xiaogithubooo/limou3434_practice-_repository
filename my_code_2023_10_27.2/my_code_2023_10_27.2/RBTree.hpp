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
				if (grandFather->_left == parent)
				{
					Node* uncle = grandFather->_right;
					if (uncle && uncle->_col == RED)//uncle���ڲ�����ɫΪ��
					{
						parent->_co	3l = BLACK;
						uncle->_col = BLACK;
						grandFather->_col = RED;
						
						cur = grandFather;//�������ϵ���
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