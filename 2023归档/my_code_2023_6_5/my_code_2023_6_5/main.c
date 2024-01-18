#define _CRT_SECURE_NO_WARNINGS 1
bool BinaryTreeComplete(BinaryTreeNode* root)
{
	//1.初始化队列
	Queue qu;
	QueueInit(&qu);
	//2.将树的根节点入队
	if (root)
		QueuePush(&qu, root);
	//3.将队头的树节点的左右子树入队
	while (!QueueEmpty(&qu))
	{
		BinaryTreeNode* p = QueueFront(&qu);//取出队头
		QueuePop(&qu);
		if (p == NULL)
		{
			break;
		}
		QueuePush(&qu, p->left);//入左子树
		QueuePush(&qu, p->right);//入右子树
	}
	//4.检查剩下的队列元素是否都是NULL
	while (!QueueEmpty(&qu))
	{
		BinaryTreeNode* p = QueueFront(&qu);//取出队头
		QueuePop(&qu);
		if (p != NULL)
		{
			QueueDestroy(&qu);
			return false;
		}
	}
	QueueDestroy(&qu);
	return true;
}