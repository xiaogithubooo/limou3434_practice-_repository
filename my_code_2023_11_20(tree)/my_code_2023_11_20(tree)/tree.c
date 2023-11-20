#include "tree.h"
//����
//ǰ����
void Prev_Order(TreeNode* root)
{
	if (root == NULL)
	{
		return;
	}
	printf("%c ", root->_data);
	Prev_Order(root->_left);
	Prev_Order(root->_right);
}
//������
void In_Order(TreeNode* root)
{
	if (root == NULL)
	{
		return;
	}
	In_Order(root->_left);
	printf("%c ", root->_data);
	In_Order(root->_right);
}
//������
void Post_Order(TreeNode* root)
{
	if (root == NULL)
	{
		return;
	}
	Post_Order(root->_left);
	Post_Order(root->_right);
	printf("%c ", root->_data);
}

//����
bool Find(TreeNode* root, type val)
{
	if (root == NULL)
	{
		return false;
	}

	if (root->_data == val)
	{
		return true;
	}

	return Find(root->_left, val) || Find(root->_right, val);
}