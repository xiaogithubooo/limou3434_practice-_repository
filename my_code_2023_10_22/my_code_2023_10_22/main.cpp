//#include <cstdio>
//struct TreeNode
//{
//    int val;
//    TreeNode* left;
//    TreeNode* right;
//};
//void dfs(struct TreeNode* root, int pathVal, int* sum)
//{
//    if (root == NULL)
//        return;
//    pathVal = (pathVal << 1) + root->val; //�൱��pathVal*2 + root->val
//
//    //����Ҷ�ӽڵ���ͳ�Ƹ�·���ĺ�
//    if (root->left == NULL && root->right == NULL)
//        *sum += pathVal;
//
//    //�ݹ���ȱ���������
//    dfs(root->left, pathVal, sum);
//
//    //�ݹ���ȱ���������
//    dfs(root->right, pathVal, sum);
//}
//
//int sumRootToLeaf(struct TreeNode* root)
//{
//    int sum = 0;
//    dfs(root, 0, &sum);
//    return sum;
//}