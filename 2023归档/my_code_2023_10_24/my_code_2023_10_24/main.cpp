#include <queue>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2)
    {
        //cout�洢���ݵ��ظ�����
        vector<int> count;
        count.resize(1001, 0);

        //ӳ��
        for (auto it : arr1)
        {
            count[it]++;
        }

        //����
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
//        if (tier % 2 == 0)//ż��
//        {
//            int min = v[0] - 1;
//            for (auto it : v)
//            {
//                if (it % 2 == 0)//���ڲ�������
//                {
//                    return false;
//                }
//                else
//                {
//                    if (min < it)
//                    {
//                        min = it;
//                    }
//                    else//���ǵ�����
//                    {
//                        return false;
//                    }
//                }
//            }
//        }
//        else//����
//        {
//            int max = v[0] + 1;
//            for (auto it : v)
//            {
//                if (it % 2 != 0)//���ڲ���ż��
//                {
//                    return false;
//                }
//                else
//                {
//                    if (max > it)
//                    {
//                        max = it;
//                    }
//                    else//���ǵݼ���
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
//        //���ö��в��������
//        queue<TreeNode*> q;
//        q.push(root);
//
//        //����˳���洢ÿһ�������
//        vector<int> v;
//
//        //���ñ���tier��ǲ���
//        int tier = 0;
//
//
//        while (!q.empty())
//        {
//            int size = q.size();
//            while (size != 0)//������ʱ�洢�����ڵ�Ԫ��
//            {
//                v.push_back(q.front()->val);
//                size--;
//                if (q.front()->left)//�ǿ�
//                    q.push(q.front()->left);
//                if (q.front()->right)//�ǿ�
//                    q.push(q.front()->right);
//                q.pop();
//            }
//            if (!IsOK(v, tier))//�жϸò��Ƿ񲻷��ϣ����Ǿ�ֱ�ӷ���false
//            {
//                return false;
//            }
//            v.resize(0);//��������
//            tier++;//�����Ӽ�
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