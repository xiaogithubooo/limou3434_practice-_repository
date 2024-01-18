//<函数声明文件>
#define _CRT_SECURE_NO_WARNINGS 1
//0.0.库函数定义
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//0.1.宏定义

//0.2.构造一个孩子兄弟树的结构体
typedef int BinaryTreeDataType;
typedef struct BinaryTreeNode
{
    BinaryTreeDataType data;//存放数据
    struct BinaryTreeNode* left;//指向左孩子节点
    struct BinaryTreeNode* right;//指向右孩子节点
}BinaryTreeNode;

//函数定义
//1.前序函数
void Prev_Order(BinaryTreeNode* root);

//2.中序函数
void In_Order(BinaryTreeNode* root);

//3.后序函数
void Post_Order(BinaryTreeNode* root);

//4.1.计算节点个数
//void Tree_Size(BinaryTreeNode* root, int* psize);
//4.2.计算节点个数
int Tree_Size(BinaryTreeNode* root);

//5.计算叶子节点个数
int Tree_Leaf_Size(BinaryTreeNode* root);