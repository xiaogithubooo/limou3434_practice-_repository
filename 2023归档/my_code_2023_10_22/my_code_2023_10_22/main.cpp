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
//    pathVal = (pathVal << 1) + root->val; //相当于pathVal*2 + root->val
//
//    //到达叶子节点则统计该路径的和
//    if (root->left == NULL && root->right == NULL)
//        *sum += pathVal;
//
//    //递归深度遍历左子树
//    dfs(root->left, pathVal, sum);
//
//    //递归深度遍历右子树
//    dfs(root->right, pathVal, sum);
//}
//
//int sumRootToLeaf(struct TreeNode* root)
//{
//    int sum = 0;
//    dfs(root, 0, &sum);
//    return sum;
//}