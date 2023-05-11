#define _CRT_SECURE_NO_WARNINGS 1
//  1.3.1.ǰ��������ȷ��ʸ����ٷ������������ٷ�����������
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
//  1.3.2.����������ȷ������������ٷ��ʸ����ٷ�����������
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
//  1.3.3.����������ȷ������������ٷ������������ٷ��ʸ���
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