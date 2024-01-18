#define _CRT_SECURE_NO_WARNINGS 1
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