//<���������ļ�>
#define _CRT_SECURE_NO_WARNINGS 1
//0.0.�⺯������
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//0.1.�궨��

//0.2.����һ�������ֵ����Ľṹ��
typedef int BinaryTreeDataType;
typedef struct BinaryTreeNode
{
    BinaryTreeDataType data;//�������
    struct BinaryTreeNode* left;//ָ�����ӽڵ�
    struct BinaryTreeNode* right;//ָ���Һ��ӽڵ�
}BinaryTreeNode;

//��������
//1.ǰ����
void Prev_Order(BinaryTreeNode* root);

//2.������
void In_Order(BinaryTreeNode* root);

//3.������
void Post_Order(BinaryTreeNode* root);

//4.1.����ڵ����
//void Tree_Size(BinaryTreeNode* root, int* psize);
//4.2.����ڵ����
int Tree_Size(BinaryTreeNode* root);

//5.����Ҷ�ӽڵ����
int Tree_Leaf_Size(BinaryTreeNode* root);