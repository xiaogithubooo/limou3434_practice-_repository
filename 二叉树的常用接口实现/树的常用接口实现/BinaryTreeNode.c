#include "BinaryTreeNode.h"
//> ���е�ʵ��
//> 1.��ʽ�ṹ����ʾ���е�һ��Ԫ��
typedef BinaryTreeNode* QDataType;
typedef struct QListNode
{
	struct QListNode* _pNext;
	QDataType _data;
}QNode;
//> 2.���еĽṹ 
typedef struct Queue
{
	QNode* _front;  //��ͷ
	QNode* _rear;   //��β
}Queue;
//> 3.��ʼ������ 
void QueueInit(Queue* q)
{
	//1.���ָ�����Ч��
	assert(q);
	//2.��ʼ�����У���β��ͷ����Ϊ�գ�
	q->_front = q->_rear = NULL;
}
//> 4.��β����У�����β�壩
void QueuePush(Queue* q, QDataType data)
{
	//1.���ָ�����Ч��
	assert(q);
	//2.������һ������ڵ㲢�Ҵ洢������
	QNode* cache = (QNode*)malloc(sizeof(QNode));
	if (!cache)
	{
		perror("malloc fail\n");
		exit(-1);
	}
	cache->_data = data;
	cache->_pNext = NULL;
	//3.��ʼβ��
	if (q->_rear == NULL)//�������Ϊ��
	{
		q->_front = q->_rear = cache;
	}
	else
	{
		q->_rear->_pNext = cache;
		q->_rear = cache;//�ı���еĶ�β��ǣ��γ��µĶ�β
	}
}
//> 5.��ͷ�����У�����ͷɾ��
void QueuePop(Queue* q)
{
	//1.���ָ����Ч��
	assert(q);
	assert(q->_front);
	//2.��ʼ������
	//2.1.�������������ֻʣһ���ڵ㣩
	if (q->_front == q->_rear)
	{
		free(q->_front);
		q->_front = q->_rear = NULL;
		return;
	}
	//2.2.����һ�����
	QNode* delNode = q->_front;
	q->_front = q->_front->_pNext;
	free(delNode);
}
//> 6.��ȡ����ͷ��Ԫ�� 
QDataType QueueFront(Queue* q)
{
	//1.���ָ�����Ч��
	assert(q);
	assert(q->_front);
	//2.���ض�ͷ��ֵ
	return q->_front->_data;
}
//> 7.��ȡ���ж�βԪ��

//QDataType QueueBack(Queue* q)
//{
//	;
//}

//> 8.��ȡ��������ЧԪ�ظ���������Ҳ�����ö��нṹ����һ��size��Ա��
int QueueSize(Queue* q)
{
	//1.���ָ�����Ч��
	assert(q);
	//2.ѭ��������������ЧԪ�ظ���
	int size = 0;
	QNode* cur = q->_front;
	while (cur)
	{
		size++;
		cur = cur->_pNext;
	}
	return size;
}
//> 9.�������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty(Queue* q)
{
	//1.���ָ�����Ч��
	assert(q);
	//2.�������Ƿ�Ϊ��
	return q->_front == NULL;
}
//> 10.���ٶ��� 
void QueueDestroy(Queue* q)
{
	//1.���ָ�����Ч��
	assert(q);
	//2.��ʼ����
	QNode* cur = q->_front;
	while (cur)
	{
		QNode* next = cur->_pNext;
		free(cur);
		cur = next;
	}
	q->_front = q->_rear = NULL;
}

//1.ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
BinaryTreeNode* BuyNode(BTDataType x)
{
	BinaryTreeNode* cache = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
	if (!cache) exit(-1);
	cache->data = x;
	cache->left = NULL;
	cache->right = NULL;
	return cache;
}
BinaryTreeNode* BinaryTreeCreate(BTDataType* arr, int n, int* pi)
{
	BinaryTreeNode* root = NULL;
	if (arr[*pi] == '#')
	{
		(*pi)++;
		return root;
	}
	root = BuyNode(arr[(*pi)++]);
	root->left = BinaryTreeCreate(arr, n, pi);
	root->right = BinaryTreeCreate(arr, n, pi);
	return root;
}
//2.����������
void BinaryTreeDestory(BinaryTreeNode* root)
{
	if (root == NULL)
	{
		return;
	}
	BinaryTreeDestory(root->left);
	BinaryTreeDestory(root->right);
	free(root);
}
//3.�������ڵ����
int BinaryTreeSize(BinaryTreeNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return 1 + BinaryTreeSize(root->left) + BinaryTreeSize(root->right);
}
//4.������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BinaryTreeNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}
	return (BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right));
}
//5.��������k��ڵ����
int BinaryTreeLevelKSize(BinaryTreeNode* root, int k)
{
	assert(k > 0);
	if (root == NULL)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}
	return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
}
//6.����������ֵΪx�Ľڵ�
BinaryTreeNode* BinaryTreeFind(BinaryTreeNode* root, BTDataType x)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (root->data == x)
	{
		return root;
	}
	BinaryTreeNode* p1 = BinaryTreeFind(root->left, x);
	if (p1)
		return p1;
	return BinaryTreeFind(root->right, x);
}
//7.������ǰ����� 
void BinaryTreePrevOrder(BinaryTreeNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	printf("%c ", root->data);
	BinaryTreePrevOrder(root->left);
	BinaryTreePrevOrder(root->right);
}
//8.�������������
void BinaryTreeInOrder(BinaryTreeNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	BinaryTreeInOrder(root->left);
	printf("%c ", root->data);
	BinaryTreeInOrder(root->right);
}
//9.�������������
void BinaryTreePostOrder(BinaryTreeNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	BinaryTreePostOrder(root->left);
	BinaryTreePostOrder(root->right);
	printf("%c ", root->data);
}
//10.�������
void BinaryTreeLevelOrder(BinaryTreeNode* root)
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
		if (p != NULL)
		{
			printf("%c ", p->data);
		}
		else
		{
			printf("NULL ");
		}
		if (p)
		{
			QueuePush(&qu, p->left);//��������
			QueuePush(&qu, p->right);//��������
		}
	}
	//4.���ٶ���
	QueueDestroy(&qu);
}
//11.�ж϶������Ƿ�����ȫ��������������ȫ�����������������뵽���������
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