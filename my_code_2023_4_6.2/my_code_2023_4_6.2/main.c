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
//�����������������������С
int _TreeSize(struct TreeNode* root)
{
    return root == NULL ? 0 : _TreeSize(root->left) + _TreeSize(root->right) + 1;//����ļ�1���ǽڵ��Լ�����
}
//��������������ǰ��������Ӻ���
void _prevOrder(struct TreeNode* root, int* a, int* pi)//ע�����i������ָ���������Ȼ����һ���ֲ�����i��һ���ݹ�ͻᱻ���٣����ע�⣬�Ժ�ʹ�õݹ�һ��Ҫ���Ǿֲ����������⡣���ⲻ̫����ʹ��ȫ�ֱ�����Ҫ���ǵ����ʹ�õ����⣬���ұ���ʹ��ȫ�ֱ���Ҳ�����ˣ��п���leedcode�����˶�εı����������Զ�����������������Ҫʹ��ȫ�ֱ���������Ҫ�ڵ���preorderTraversal�����Ŀ�ͷ��i���¸�ֵΪ0�������Ų���Ӱ����һ�κ����ĵ���
{
    if (root == NULL) return;
    a[*pi] = root->val;
    ++(*pi);


    _prevOrder(root->left, a, pi);
    _prevOrder(root->right, a, pi);
}
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
int* preorderTraversal(struct TreeNode* root, int* returnSize)//������(���ڵ�ָ�루�����Ͳ�����, ��������Ĵ�С������Ͳ�����)
{
    //1.��ʼ��׼��
    /*ע�����
    * ���������⣺��������鲻��ֱ��������������洴������Ϊ�Ǿֲ����������˺����ͻᱻ���٣��޷������أ���˱���ʹ�ö�̬�ڴ棬����ڿ�ͷҲ�н���
    * �ڴ�С���⣺����һ�������������Ĵ�С����Ԥ֪����The returned array must be malloced, assume caller calls free()�����뼴�����ص������������malloc��̬����ģ���������ߵ�����free()��
    */
    int size = _TreeSize(root);//������������С����
    int* a = (int*)malloc(size * sizeof(int));//�������������������

    //2.���ʱ��ʼ��ǰ������Ĺ�����
    /*
    * ���ȱ��ⲻ�ʺ�ֱ�ӵݹ�preorderTraversal��������Ϊ��ᷴ��ִ�п�ͷ��׼�����������ϵ�mallocһ���ռ�ͼ���洢���ڵ����ݵ�����Ĵ�С���ظ��ˣ���˻���Ҫһ���Ӻ������������Ĺ�����û�취ֱ����preorderTraversal�����������
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
    /*��ȡ�����㷨
    * �����������������
    * �������������ȵݹ鹫ʽ����"��� == max(���������, ���������) + 1"
    * ���ȥ��ϸ����������̣��ͻᷢ����������㷨ʵ�ʾ���һ��������������ҡ���
    */
    if (root == NULL) return 0;
    int a = maxDepth(root->left);
    int b = maxDepth(root->right);
    return a > b ? a + 1 : b + 1;
}
//�������������oj�������������һ�ֳ���ʱ�����ƣ��޷��м����������1����ѭ��������̫��ѭ����2�����ݹ飬����̫��ݹ飨3���㷨��ʱ��Ч�ʵ��£���˱�����Ҫ���ݹ鴦��һ�£�����ֱ�ӷ�����Ŀ���ʽ�У������Ч�ʵ��µ�����
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/
//ƽ����������Ҫ����ÿ���������������ĸ߶Ȳ����1
//�������������һ���������
#include <math.h>
int maxDepth(struct TreeNode* root)
{
    /*��ȡ�����㷨��
    * �����������������
    * �������������ȵݹ鹫ʽ����"��� == max(���������, ���������) + 1"
    * ���ȥ��ϸ����������̣��ͻᷢ����������㷨ʵ�ʾ���һ��������������ҡ���
    */
    if (root == NULL) return 0;
    int a = maxDepth(root->left);
    int b = maxDepth(root->right);
    return a > b ? a + 1 : b + 1;
}
bool isBalanced(struct TreeNode* root)
{
    if (root == NULL) return true;
    //�����Լ�����ڵ���Ƿ����ƽ�����ı�׼
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return abs(leftDepth - rightDepth) < 2
        && isBalanced(root->left)
        && isBalanced(root->right);
}