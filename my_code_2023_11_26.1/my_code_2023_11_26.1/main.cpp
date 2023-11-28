//递归结合栈层序遍历
#include <iostream>
#include <vector>
#include <stack>
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
public:
    bool _lowestCommonAncestor(TreeNode* root, TreeNode* target, stack<TreeNode*>&q)
    {
        if (root == nullptr)
        {
            return false;
        }

        if (root == target)
        {
            q.push(target);
            return true;
        }

        q.push(root);
        if (_lowestCommonAncestor(root->left, target, q) == false
            && _lowestCommonAncestor(root->right, target, q) == false)
        {
            q.pop();
            return false;
        }

        return true;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        //创建两个栈，存储两路径
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;

        //寻找两路径
        _lowestCommonAncestor(root, p, s1);
        _lowestCommonAncestor(root, q, s2);

        //出较大的栈，直到和较小的栈同样长度
        int size = min(s1.size(), s2.size());
        while (s1.size() > size)
        {
            s1.pop();
        }
        while (s2.size() > size)
        {
            s2.pop();
        }

        while (!s1.empty())
        {
            if (s1.top()->val != s2.top()->val)
            {
                s1.pop();
                s2.pop();
            }
            else
            {
                return s1.top();
            }
        }

        return nullptr;
    }
};
int main()
{
    TreeNode* a = new TreeNode;
    TreeNode* b = new TreeNode;
    TreeNode* c = new TreeNode;
    TreeNode* d = new TreeNode;
    TreeNode* e = new TreeNode;
    TreeNode* f = new TreeNode;
    TreeNode* g = new TreeNode;
    TreeNode* h = new TreeNode;

    a->val = 3;
    b->val = 9;
    c->val = 20;
    d->val = 8;
    e->val = 4;
    f->val = 15;
    g->val = 7;
    h->val = 1;

    a->left = b;
    a->right = c;

    b->left = d;
    b->right = e;

    c->left = f;
    c->right = g;
    
    e->left = h;

    Solution s;
    cout << s.lowestCommonAncestor(a, h, g)->val;
    return 0;
}




//class Solution
//{
//public:
//    vector<vector<int>> levelOrder(TreeNode* root)
//    {
//        vector<vector<int>> vv;
//        queue<TreeNode*> q;
//        int size = 1;
//
//        while (!q.empty())
//        {
//            vector<int> v;
//            while (size--)
//            {
//                TreeNode* front = q.front();
//                q.pop();
//
//                v.push_back(front->val);
//
//                if(front->left)
//                    q.push(front->left);
//                if (front->right)
//                    q.push(front->right);
//            }
//            size = q.size();
//            vv.push_back(v);
//        }
//        return vv;
//    }
//};
