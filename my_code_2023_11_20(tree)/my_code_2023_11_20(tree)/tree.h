#pragma once
//1.���ֱ���
//2.���ҽ��
//3.����������ѡ����

#include <stdio.h>
#include <stdbool.h>

//1.���ṹ
typedef char type;
typedef struct TreeNode
{
	type _data;
	struct TreeNode* _left;
	struct TreeNode* _right;
}TreeNode;

//2.����
//ǰ����
void Prev_Order(TreeNode* root);
//������
void In_Order(TreeNode* root);
//������
void Post_Order(TreeNode* root);

//3.����
bool Find(TreeNode* root, type val);

//4.��������
//ѡ��