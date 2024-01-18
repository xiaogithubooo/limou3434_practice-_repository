#define _CRT_SECURE_NO_WARNINGS 1
bool isSameTree(struct TreeNode* p, struct TreeNode* q)//本质是前序遍历
{
    if (p == NULL && q == NULL)
    {
        return true;
    }
    if (p == NULL && q != NULL)
    {
        return false;
    }
    if (p != NULL && q == NULL)
    {
        return false;
    }
    if (p->val != q->val)
    {
        return false;
    }
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
bool isSubtree(struct TreeNode* root_1, struct TreeNode* root_2)
{
    if (root_1 == NULL && root_2 == NULL)
    {
        return true;
    }
    if (root_1 == NULL || root_2 == NULL)
    {
        return false;
    }
    if (!isSameTree(root_1->left, root_2))
    {
        return false;
    }
    if (!isSameTree(root_1->right, root_2))
    {
        return false;
    }
    return isSubtree(root_1->left, root_2) && isSubtree(root_1->right, root_2);
}