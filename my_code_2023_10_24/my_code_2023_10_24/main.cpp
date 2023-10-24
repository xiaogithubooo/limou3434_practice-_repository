#include <queue>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2)
    {
        //cout存储数据的重复次数
        vector<int> count;
        count.resize(1001, 0);

        //映射
        for (auto it : arr1)
        {
            count[it]++;
        }

        //查找
        for (auto it : count)
        {
            if()
        }


        vector<int> ret;
        return ret;
    }
};

//struct TreeNode
//{
//    int val;
//    TreeNode* left;
//    TreeNode* right;
//    TreeNode() : val(0), left(nullptr), right(nullptr) {}
//    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
//};
//
//class Solution
//{
//    bool IsOK(const vector<int>& v, int tier)
//    {
//        if (tier % 2 == 0)//偶数
//        {
//            int min = v[0] - 1;
//            for (auto it : v)
//            {
//                if (it % 2 == 0)//层内不是奇数
//                {
//                    return false;
//                }
//                else
//                {
//                    if (min < it)
//                    {
//                        min = it;
//                    }
//                    else//不是递增的
//                    {
//                        return false;
//                    }
//                }
//            }
//        }
//        else//奇数
//        {
//            int max = v[0] + 1;
//            for (auto it : v)
//            {
//                if (it % 2 != 0)//层内不是偶数
//                {
//                    return false;
//                }
//                else
//                {
//                    if (max > it)
//                    {
//                        max = it;
//                    }
//                    else//不是递减的
//                    {
//                        return false;
//                    }
//                }
//            }
//        }
//        return true;
//    }
//public:
//    bool isEvenOddTree(TreeNode* root)
//    {
//        //利用队列层序遍历树
//        queue<TreeNode*> q;
//        q.push(root);
//
//        //利用顺序表存储每一层的数据
//        vector<int> v;
//
//        //利用变量tier标记层数
//        int tier = 0;
//
//
//        while (!q.empty())
//        {
//            int size = q.size();
//            while (size != 0)//遍历此时存储队列内的元素
//            {
//                v.push_back(q.front()->val);
//                size--;
//                if (q.front()->left)//非空
//                    q.push(q.front()->left);
//                if (q.front()->right)//非空
//                    q.push(q.front()->right);
//                q.pop();
//            }
//            if (!IsOK(v, tier))//判断该层是否不符合，不是就直接返回false
//            {
//                return false;
//            }
//            v.resize(0);//重置数组
//            tier++;//层数加加
//        }
//        return true;
//    }
//};
//
//int main()
//{
//    //[5,4,2,3,3,7]
//    TreeNode* a = new TreeNode(5);
//
//    TreeNode* b = new TreeNode(4);
//    TreeNode* c = new TreeNode(2);
//    
//    TreeNode* d = new TreeNode(3);
//    TreeNode* e = new TreeNode(5);
//    TreeNode* f = new TreeNode(7);
//
//    a->left = b;
//    a->right = c;
//
//    b->left = d;
//    b->right = e;
//
//    c->left = f;
//
//    Solution s;
//    s.isEvenOddTree(a);
//    return 0;
//}