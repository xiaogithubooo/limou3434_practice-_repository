#include "BinaryTreeNode.h"
//> 队列的实现
//> 1.链式结构：表示队列的一个元素
typedef BinaryTreeNode* QDataType;
typedef struct QListNode
{
	struct QListNode* _pNext;
	QDataType _data;
}QNode;
//> 2.队列的结构 
typedef struct Queue
{
	QNode* _front;  //队头
	QNode* _rear;   //队尾
}Queue;
//> 3.初始化队列 
void QueueInit(Queue* q)
{
	//1.检查指针的有效性
	assert(q);
	//2.初始化队列（队尾队头都置为空）
	q->_front = q->_rear = NULL;
}
//> 4.队尾入队列（链表尾插）
void QueuePush(Queue* q, QDataType data)
{
	//1.检查指针的有效性
	assert(q);
	//2.先申请一个链表节点并且存储好数据
	QNode* cache = (QNode*)malloc(sizeof(QNode));
	if (!cache)
	{
		perror("malloc fail\n");
		exit(-1);
	}
	cache->_data = data;
	cache->_pNext = NULL;
	//3.开始尾插
	if (q->_rear == NULL)//如果队列为空
	{
		q->_front = q->_rear = cache;
	}
	else
	{
		q->_rear->_pNext = cache;
		q->_rear = cache;//改变队列的队尾标记，形成新的队尾
	}
}
//> 5.队头出队列（链表头删）
void QueuePop(Queue* q)
{
	//1.检查指针有效性
	assert(q);
	assert(q->_front);
	//2.开始出数据
	//2.1.处理特殊情况（只剩一个节点）
	if (q->_front == q->_rear)
	{
		free(q->_front);
		q->_front = q->_rear = NULL;
		return;
	}
	//2.2.处理一般情况
	QNode* delNode = q->_front;
	q->_front = q->_front->_pNext;
	free(delNode);
}
//> 6.获取队列头部元素 
QDataType QueueFront(Queue* q)
{
	//1.检查指针的有效性
	assert(q);
	assert(q->_front);
	//2.返回队头的值
	return q->_front->_data;
}
//> 7.获取队列队尾元素

//QDataType QueueBack(Queue* q)
//{
//	;
//}

//> 8.获取队列中有效元素个数（这里也可以让队列结构体多加一个size成员）
int QueueSize(Queue* q)
{
	//1.检查指针的有效性
	assert(q);
	//2.循环计数，返回有效元素个数
	int size = 0;
	QNode* cur = q->_front;
	while (cur)
	{
		size++;
		cur = cur->_pNext;
	}
	return size;
}
//> 9.检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q)
{
	//1.检查指针的有效性
	assert(q);
	//2.检测队列是否为空
	return q->_front == NULL;
}
//> 10.销毁队列 
void QueueDestroy(Queue* q)
{
	//1.检查指针的有效性
	assert(q);
	//2.开始销毁
	QNode* cur = q->_front;
	while (cur)
	{
		QNode* next = cur->_pNext;
		free(cur);
		cur = next;
	}
	q->_front = q->_rear = NULL;
}

//1.通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
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
//2.二叉树销毁
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
//3.二叉树节点个数
int BinaryTreeSize(BinaryTreeNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return 1 + BinaryTreeSize(root->left) + BinaryTreeSize(root->right);
}
//4.二叉树叶子节点个数
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
//5.二叉树第k层节点个数
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
//6.二叉树查找值为x的节点
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
//7.二叉树前序遍历 
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
//8.二叉树中序遍历
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
//9.二叉树后序遍历
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
//10.层序遍历
void BinaryTreeLevelOrder(BinaryTreeNode* root)
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
			QueuePush(&qu, p->left);//入左子树
			QueuePush(&qu, p->right);//入右子树
		}
	}
	//4.销毁队列
	QueueDestroy(&qu);
}
//11.判断二叉树是否是完全二叉树（利用完全二叉树的连续性联想到层序遍历）
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