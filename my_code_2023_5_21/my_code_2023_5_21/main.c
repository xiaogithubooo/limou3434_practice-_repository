#define _CRT_SECURE_NO_WARNINGS 1
//typedef struct TreeNode
//{
//	int data;//存储节点的数据
//	struct TreeNode* child_1;//存储节点指向的子孩子1
//	struct TreeNode* child_2;//存储节点指向的子孩子2
//	struct TreeNode* child_3;//存储节点指向的子孩子3
//	//…
//}TreeNode;
//typedef struct TreeNode
//{
//	int data;//存储节点的数据
//	SeqList childArr;
//}TreeNode;
//typedef struct TreeNode
//{
//	int data;//存储节点的数据
//	int parenti;
//}TreeNode;
////然后创建一个数据元素是TreeNode的结构体数组
typedef struct TreeNode
{
	int data;//存储本节点的数据
	struct TreeNode* firstChild;//本节点指向的第一个孩子节点
	struct TreeNode* Brother;//本节点的兄弟节点
}TreeNode;