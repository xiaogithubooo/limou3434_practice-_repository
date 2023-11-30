#define _CRT_SECURE_NO_WARNINGS 1

#include "tree.h"
#include <malloc.h>
#include <assert.h>

void Init(TreeNode** tree)
{
	//printf("输入结点数据:");
	type val = 0;
	while (((val = getchar()) == '\n')
		|| (val == ' '))
	{
		;
	}
	if (val == '#')
	{
		return;
	}

	TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
	if (!newNode) assert(0);
	newNode->_data = val;
	newNode->_left = NULL;
	newNode->_right = NULL;

	*tree = newNode;

	Init(&(*tree)->_left);
	Init(&(*tree)->_right);
}
int main()
{
	printf("以前序顺序，输入二叉树的结点（空结点为'#'）\n");
	TreeNode* tree = (TreeNode*)malloc(sizeof(TreeNode));
	if (!tree) assert(0);
	Init(&tree);

	Prev_Order(tree);
	printf("\n");
	In_Order(tree);
	printf("\n");
	Post_Order(tree);
	printf("\n");

	if (Find(tree, 'E'))
	{
		printf("true\n");
	}
	else
	{
		printf("flase\n");
	}
	return 0;
}