#include <iostream>
#include <stack>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left = nullptr;
	TreeNode* right = nullptr;
};

void function(TreeNode* root)
{
	stack<TreeNode*> s;
	TreeNode* cur = root;

	while (!s.empty() || cur != nullptr)
	{
		while (cur != nullptr)
		{
			cout << cur->val << " ";
			s.push(cur);
			cur = cur->left;
		}
		TreeNode* top = s.top();
		s.pop();
		cur = top->right;
	}
}
int main()
{
	TreeNode A;
	A.val = 8;

	TreeNode B;
	B.val = 3;

	TreeNode C;
	C.val = 10;

	TreeNode D;
	D.val = 1;

	TreeNode E;
	E.val = 6;

	TreeNode F;
	F.val = 4;

	TreeNode G;
	G.val = 7;

	A.left = &B;
	A.right = &C;
	
	B.left = &D;
	B.right = &E;

	E.left = &F;
	E.right = &G;

	function(&A);
	return 0;
}