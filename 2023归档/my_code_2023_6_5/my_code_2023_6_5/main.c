#define _CRT_SECURE_NO_WARNINGS 1
bool BinaryTreeComplete(BinaryTreeNode* root)
{
	//1.��ʼ������
	Queue qu;
	QueueInit(&qu);
	//2.�����ĸ��ڵ����
	if (root)
		QueuePush(&qu, root);
	//3.����ͷ�����ڵ�������������
	while (!QueueEmpty(&qu))
	{
		BinaryTreeNode* p = QueueFront(&qu);//ȡ����ͷ
		QueuePop(&qu);
		if (p == NULL)
		{
			break;
		}
		QueuePush(&qu, p->left);//��������
		QueuePush(&qu, p->right);//��������
	}
	//4.���ʣ�µĶ���Ԫ���Ƿ���NULL
	while (!QueueEmpty(&qu))
	{
		BinaryTreeNode* p = QueueFront(&qu);//ȡ����ͷ
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