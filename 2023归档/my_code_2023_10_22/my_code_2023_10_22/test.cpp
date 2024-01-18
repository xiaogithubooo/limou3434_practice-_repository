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
    void _sumRootToLeaf(TreeNode* root, int& sum, int pathVal)
    {
        if (root == nullptr)
        {
            return;
        }

        pathVal <<= 1;
        pathVal = (pathVal + root->val);

        _sumRootToLeaf(root->left, sum, pathVal);
        _sumRootToLeaf(root->right, sum, pathVal);

        if(root->left == nullptr && root->right == nullptr)
            sum += pathVal;
    }
    int sumRootToLeaf(TreeNode* root)
    {
        int sum = 0;
        int pathVal = 0;
        _sumRootToLeaf(root, sum, pathVal);
        return sum;
    }
};
int main()
{
    Solution s;
    TreeNode* A = new TreeNode;
    A->val = 1;
    TreeNode* B = new TreeNode;
    B->val = 1;
    //TreeNode* C = new TreeNode;
    //C->val = 1;
    //TreeNode* D = new TreeNode;
    //D->val = 0;
    //TreeNode* E = new TreeNode;
    //E->val = 1;
    //TreeNode* F = new TreeNode;
    //F->val = 0;
    //TreeNode* G = new TreeNode;
    //G->val = 1;

    A->left = B;
    //A->right = C;

    //B->left = D;
    //B->right = E;

    //C->left = F;
    //C->right = G;

    s.sumRootToLeaf(A);
    return 0;
}