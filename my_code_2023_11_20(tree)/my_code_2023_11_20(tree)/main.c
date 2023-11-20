#include "tree.h"

void Init(TreeNode* tree)
{
	printf("输入结点数据");
	type val = 0;
	scanf("%c", &val);
	if (val == '#')
	{
		return;
	}

	tree->_data = val;
	Init(tree->_left);
	Init(tree->_right);
}
int main()
{
	printf("输入二叉树的结点（空为'#'）：");
	TreeNode tree;
	Init(&tree);
	return 0;
}


//TreeNode tree1;
//tree1._data = 'A';
//tree1._left = NULL;
//tree1._right = NULL;
//
//TreeNode tree2;
//tree2._data = 'B';
//tree2._left = NULL;
//tree2._right = NULL;
//
//TreeNode tree3;
//tree3._data = 'C';
//tree3._left = NULL;
//tree3._right = NULL;
//
//TreeNode tree4;
//tree4._data = 'D';
//tree4._left = NULL;
//tree4._right = NULL;
//
//TreeNode tree5;
//tree5._data = 'E';
//tree5._left = NULL;
//tree5._right = NULL;
//
//
//tree1._right = &tree2;
//tree2._left = &tree3;
//tree2._right = &tree4;
//tree3._right = &tree5;
//
//
//Prev_Order(&tree1);
//printf("\n");
//In_Order(&tree1);
//printf("\n");
//Post_Order(&tree1);
//printf("\n");
//
//if (Find(&tree1, 'C'))
//{
//	printf("OK");
//}