#define _CRT_SECURE_NO_WARNINGS 1
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/
/**
* Note: The returned array must be malloced, assume caller calls free().
*/
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//辅助函数，计算所需数组大小
int _TreeSize(struct TreeNode* root)
{
    return root == NULL ? 0 : _TreeSize(root->left) + _TreeSize(root->right) + 1;//这里的加1就是节点自己本身
}
//辅助函数，用来前序遍历的子函数
void _prevOrder(struct TreeNode* root, int* a, int* pi)//注意这个i必须是指针变量，不然就是一个局部变量i，一旦递归就会被销毁，因此注意，以后使用递归一定要考虑局部变量的问题。另外不太建议使用全局变量，要考虑到多次使用的问题，而且本题使用全局变量也过不了，有可能leedcode调用了多次的本函数来测试多个测试用例，如果非要使用全局变量，就需要在调用preorderTraversal函数的开头把i重新赋值为0，这样才不会影响下一次函数的调用
{
    if (root == NULL) return;
    a[*pi] = root->val;
    ++(*pi);


    _prevOrder(root->left, a, pi);
    _prevOrder(root->right, a, pi);
}
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
int* preorderTraversal(struct TreeNode* root, int* returnSize)//参数是(根节点指针（输入型参数）, 返回数组的大小（输出型参数）)
{
    //1.开始做准备
    /*注意事项：
    * ①销毁问题：先这个数组不能直接在这个函数里面创建，因为是局部变量，除了函数就会被销毁，无法被带回，因此必须使用动态内存，这个在开头也有讲解
    * ②大小问题：还有一个问题就是数组的大小不可预知，“The returned array must be malloced, assume caller calls free()”翻译即“返回的数组必须是由malloc动态分配的，假设调用者调用了free()”
    */
    int size = _TreeSize(root);//解决所需数组大小问题
    int* a = (int*)malloc(size * sizeof(int));//解决所需数组销毁问题

    //2.这个时候开始做前序遍历的工作了
    /*
    * 首先本题不适合直接递归preorderTraversal函数，因为这会反复执行开头的准备工作，不断地malloc一个空间和计算存储树节点数据的数组的大小，重复了，因此还需要一个子函数来做遍历的工作，没办法直接在preorderTraversal函数里面求出
    */
    int i = 0;
    _prevOrder(root, a, &i);
    *returnSize = size;
    return a;
}
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/

int maxDepth(struct TreeNode* root)
{
    /*采取分治算法
    * 先求左右子树的深度
    * 因此整棵树的深度递归公式就是"深度 == max(左子树深度, 右子树深度) + 1"
    * 如果去仔细分析这个过程，就会发现这个分治算法实际就是一个后序遍历：左、右、根
    */
    if (root == NULL) return 0;
    int a = maxDepth(root->left);
    int b = maxDepth(root->right);
    return a > b ? a + 1 : b + 1;
}
//另外这个在在线oj笔试中如果出项一种超出时间限制，无非有几种情况：（1）死循环，包括太多循环（2）死递归，包括太多递归（3）算法超时，效率低下，因此本题需要将递归处理一下，不能直接放在三目表达式中，会造成效率低下的问题
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/
//平衡搜索树需要满足每棵树的左右子树的高度差不超过1
//辅助函数，求出一个树的深度
#include <math.h>
int maxDepth(struct TreeNode* root)
{
    /*采取分治算法：
    * 先求左右子树的深度
    * 因此整棵树的深度递归公式就是"深度 == max(左子树深度, 右子树深度) + 1"
    * 如果去仔细分析这个过程，就会发现这个分治算法实际就是一个后序遍历：左、右、根
    */
    if (root == NULL) return 0;
    int a = maxDepth(root->left);
    int b = maxDepth(root->right);
    return a > b ? a + 1 : b + 1;
}
bool isBalanced(struct TreeNode* root)
{
    if (root == NULL) return true;
    //计算自己这个节点的是否符合平衡树的标准
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return abs(leftDepth - rightDepth) < 2
        && isBalanced(root->left)
        && isBalanced(root->right);
}