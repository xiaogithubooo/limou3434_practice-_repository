//<�������岿��>
#define _CRT_SECURE_NO_WARNINGS 1
#include "function.h"
//1.ǰ����
void Prev_Order(BinaryTreeNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	printf("%c ", root->data);
	Prev_Order(root->left);
	Prev_Order(root->right);
}