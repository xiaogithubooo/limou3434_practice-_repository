#include <iostream>
#include <vector>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode* _buildTree(const vector<int>& inorder, const vector<int>& postorder, int& pos_i, int ino_begin_i, int ino_end_i)
    {
        if (ino_begin_i > ino_end_i)
        {
            return nullptr;
        }

        TreeNode* root = new TreeNode(postorder[pos_i]);
        //分割 postorder 为 [ino_begin_i, ino_i - 1] [ino_i] [ino_i + 1, ino_end_i]
        int root_i = ino_end_i;
        while (root_i >= ino_begin_i)
        {
            if (postorder[pos_i] == inorder[root_i])
            {
                break;
            }
            root_i--;
        }
        pos_i--;

        root->right = _buildTree(inorder, postorder, pos_i, root_i + 1, ino_end_i);//根据后序结点和分割后的区间，让函数完成任务
        root->left = _buildTree(inorder, postorder, pos_i, ino_begin_i, root_i - 1);//根据后序结点和分割后的区间，让函数完成任务
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        int i = postorder.size() - 1;
        return _buildTree(inorder, postorder, i, 0, inorder.size() - 1);
    }
};
int main()
{
    Solution s;
    vector<int> inorder = { 9,3,15,20,7 };//中序
    vector<int> postorder = { 9,15,7,20,3 };//后序
    TreeNode* tree = s.buildTree(inorder, postorder);
    return 0;
}