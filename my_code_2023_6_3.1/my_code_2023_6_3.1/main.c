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
    //1.初始化队列
    Queue qu;
    QueueInit(&qu);
    //2.将树的根节点入队
    QueuePush(&qu, root);
    //3.将队头的树节点的左右子树入队
    while (!QueueEmpty(&qu))
    {
        BinaryTreeNode* p = QueueFront(&qu);//取出队头
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
            QueuePush(&qu, root->left);//入左子树
            QueuePush(&qu, root->right);//入右子树
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