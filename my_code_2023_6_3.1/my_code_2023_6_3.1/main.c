#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct TreeNode 
{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};
void LevelOrder(BinaryTreeNode* root)
{
    assert(root);
    //1.��ʼ������
    Queue qu;
    QueueInit(&qu);
    //2.�����ĸ��ڵ����
    QueuePush(&qu, root);
    //3.����ͷ�����ڵ�������������
    while (!QueueEmpty(&qu))
    {
        BinaryTreeNode* p = QueueFront(&qu);//ȡ����ͷ
        if (p != NULL)
        {
            printf("%c ", p->data);
        }
        else
        {
            printf("NULL ");
        }
        root = p;
        QueuePop(&qu);
        if (root != NULL)
        {
            QueuePush(&qu, root->left);//��������
            QueuePush(&qu, root->right);//��������
        }
    }
}
//bool isSameTree(struct TreeNode* p, struct TreeNode* q)
//{
//    if (p == NULL && q == NULL)
//    {
//        return true;
//    }
//    if (p == NULL && q != NULL)
//    {
//        return false;
//    }
//    if (p != NULL && q == NULL)
//    {
//        return false;
//    }
//    if (p->val != q->val)
//    {
//        return false;
//    }
//    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
//}
//bool isSubtree(struct TreeNode* root_1, struct TreeNode* root_2)
//{
//    if (root_1 == NULL && root_2 == NULL)
//    {
//        return true;
//    }
//    if (root_1 == NULL || root_2 == NULL)
//    {
//        return false;
//    }
//    return  isSameTree(root_1, root_2) || isSubtree(root_1->left, root_2) || isSubtree(root_1->right, root_2);
//}
int main()
{
    return 0;
}