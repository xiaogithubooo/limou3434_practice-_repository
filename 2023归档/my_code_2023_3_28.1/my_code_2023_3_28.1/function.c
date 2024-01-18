//<�������岿��>
#define _CRT_SECURE_NO_WARNINGS 1
#include "function.h"
//1.ǰ����
void Prev_Order(BinaryTreeNode* root)
{
    if (root == NULL)
    {
        printf("-NULL");
        return;
    }
    printf("-%c", root->data);
    Prev_Order(root->left);
    Prev_Order(root->right);
}

//2.������
void In_Order(BinaryTreeNode* root)
{
    if (root == NULL)
    {
        printf("-NULL");
        return;
    }
    In_Order(root->left);
    printf("-%c", root->data);
    In_Order(root->right);
}

//3.������
void Post_Order(BinaryTreeNode* root)
{
    if (root == NULL)
    {
        printf("-NULL");
        return;
    }
    Post_Order(root->left);
    Post_Order(root->right);
    printf("-%c", root->data);
}

//int size = 0;//ʹ��ȫ�ֱ����;�̬�ķ�������ȡ����Ϊ��ε��øú����������
//4.1.����ڵ����
//void Tree_Size(BinaryTreeNode* root, int* psize)
//{
//    if (root == NULL)
//    {
//        return;
//    }
//    else
//    {
//        (*psize)++;
//    }
//    Tree_Size(root->left, psize);
//    Tree_Size(root->right, psize);
//}
//4.2.����ڵ����
int Tree_Size(BinaryTreeNode* root)
{
    return root == NULL ? 0 : Tree_Size(root->left) + Tree_Size(root->right) + 1;//���ϸ��ڵ�
}

//5.����Ҷ�ӽڵ����
int Tree_Leaf_Size(BinaryTreeNode* root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    return Tree_Leaf_Size(root->left) + Tree_Leaf_Size(root->right); 
}

//6���ǵݹ�㼶����