#define _CRT_SECURE_NO_WARNINGS 1
//  1.3.1.前序遍历（先访问根、再访问左子树、再访问右子树）
void PrevOrder(BinaryTreeNode* root)
{
    if (root == NULL)
    {
        printf("NULL->");
        return;
    }
    //if (root)
    //{
    printf("%c->", root->data);
    PrevOrder(root->left);
    PrevOrder(root->right);
    //}
}
//  1.3.2.中序遍历（先访问左子树、再访问根、再访问右子树）
void InOrder(BinaryTreeNode* root)
{
    if (root == NULL)
    {
        printf("NULL->");
        return;
    }
    InOrder(root->left);
    printf("%c->", root->data);
    InOrder(root->right);
}
//  1.3.3.后序遍历（先访问左子树、再访问右子树、再访问根）
void PostOrder(BinaryTreeNode* root)
{
    if (root == NULL)
    {
        printf("NULL->");
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    printf("%c->", root->data);
}