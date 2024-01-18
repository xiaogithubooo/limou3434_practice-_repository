#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <errno.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
//0.二叉树结构体
typedef char BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BinaryTreeNode;
//1.通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
BinaryTreeNode* BinaryTreeCreate(BTDataType* a, int n, int* pi);
//2.二叉树销毁
void BinaryTreeDestory(BinaryTreeNode* root);
//3.二叉树节点个数
int BinaryTreeSize(BinaryTreeNode* root);
//4.二叉树叶子节点个数
int BinaryTreeLeafSize(BinaryTreeNode* root);
//5.二叉树第k层节点个数
int BinaryTreeLevelKSize(BinaryTreeNode* root, int k);
//6.二叉树查找值为x的节点
BinaryTreeNode* BinaryTreeFind(BinaryTreeNode* root, BTDataType x);
//7.二叉树前序遍历 
void BinaryTreePrevOrder(BinaryTreeNode* root);
//8.二叉树中序遍历
void BinaryTreeInOrder(BinaryTreeNode* root);
//9.二叉树后序遍历
void BinaryTreePostOrder(BinaryTreeNode* root);
//10.层序遍历
void BinaryTreeLevelOrder(BinaryTreeNode* root);
//11.判断二叉树是否是完全二叉树
bool BinaryTreeComplete(BinaryTreeNode* root);