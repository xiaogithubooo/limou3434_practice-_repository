#include "BinaryTreeNode.h"
//测试代码
void test(void)
{
	char arr[100];
	int scanfreturn = scanf("%s", arr);
	int n = (int)strlen(arr);
	int i = 0;
	BinaryTreeNode* tree = BinaryTreeCreate(arr, n, &i);//前序创建二叉树
	printf("“节点”总数量：%d\n", BinaryTreeSize(tree));//求二叉树节点个数
	printf("“叶子节点”总数量：%d\n", BinaryTreeLeafSize(tree));//求二叉树叶子节点个数
	BinaryTreeNode* p = BinaryTreeFind(tree, 'b');//查找值为x的节点
	if (p != NULL)
	{
		printf("%c\n", p->data);
	}
	else
	{
		printf("找不到对于value的树的节点\n");
	}
	printf("%d\n", BinaryTreeLevelKSize(tree, 1));//查看某一层的节点个数
	printf("%d\n", BinaryTreeLevelKSize(tree, 2));
	printf("%d\n", BinaryTreeLevelKSize(tree, 3));
	printf("%d\n", BinaryTreeLevelKSize(tree, 4));
	printf("%d\n", BinaryTreeLevelKSize(tree, 5));
	printf("%d\n", BinaryTreeLevelKSize(tree, 6));
	printf("%d\n", BinaryTreeLevelKSize(tree, 7));
	if (BinaryTreeComplete(tree))
	{
		printf("是完全二叉树\n");
	}
	else
	{
		printf("不是完全二叉树\n");
	}
	printf("前序遍历：");
	BinaryTreePrevOrder(tree);//前序遍历二叉树
	printf("\n"); 

	printf("中序遍历：");
	BinaryTreeInOrder(tree);//中序遍历二叉树
	printf("\n");

	printf("后序遍历：");
	BinaryTreePostOrder(tree);//后序遍历二叉树
	printf("\n");

	printf("层序遍历：");
	BinaryTreeLevelOrder(tree);//层序遍历二叉树
	printf("\n");

	BinaryTreeDestory(tree);//销毁二叉树
}
int main()
{
	test();
	return 0;
}