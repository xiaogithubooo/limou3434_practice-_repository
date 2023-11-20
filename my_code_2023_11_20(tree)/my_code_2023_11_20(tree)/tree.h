#pragma once
//1.三种遍历
//2.查找结点
//3.哈夫曼树（选做）

#include <stdio.h>
#include <stdbool.h>

//1.结点结构
typedef char type;
typedef struct TreeNode
{
	type _data;
	struct TreeNode* _left;
	struct TreeNode* _right;
}TreeNode;

//2.遍历
//前序函数
void Prev_Order(TreeNode* root);
//中序函数
void In_Order(TreeNode* root);
//后序函数
void Post_Order(TreeNode* root);

//3.查找
bool Find(TreeNode* root, type val);

//4.哈夫曼树
//选做