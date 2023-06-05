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
//0.�������ṹ��
typedef char BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BinaryTreeNode;
//1.ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
BinaryTreeNode* BinaryTreeCreate(BTDataType* a, int n, int* pi);
//2.����������
void BinaryTreeDestory(BinaryTreeNode* root);
//3.�������ڵ����
int BinaryTreeSize(BinaryTreeNode* root);
//4.������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BinaryTreeNode* root);
//5.��������k��ڵ����
int BinaryTreeLevelKSize(BinaryTreeNode* root, int k);
//6.����������ֵΪx�Ľڵ�
BinaryTreeNode* BinaryTreeFind(BinaryTreeNode* root, BTDataType x);
//7.������ǰ����� 
void BinaryTreePrevOrder(BinaryTreeNode* root);
//8.�������������
void BinaryTreeInOrder(BinaryTreeNode* root);
//9.�������������
void BinaryTreePostOrder(BinaryTreeNode* root);
//10.�������
void BinaryTreeLevelOrder(BinaryTreeNode* root);
//11.�ж϶������Ƿ�����ȫ������
bool BinaryTreeComplete(BinaryTreeNode* root);