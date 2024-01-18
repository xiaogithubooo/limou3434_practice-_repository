#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <errno.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
typedef struct BinaryTreeNode
{
    int data;
    struct BinaryTreeNode* left;
    struct BinaryTreeNode* right;
}BinaryTreeNode;

//1.������ĸ���
//ʹ��ȫ�ֱ���
//int SIZE = 0;
//ʹ�þ�̬����
int countNodes(struct BinaryTreeNode* root)
{
    static int SIZE = 0;
    if (root == NULL)
    {
        return SIZE;
    }
    SIZE++;
    countNodes(root->left);
    countNodes(root->right);
    return SIZE;
}
void test_1(void)
{
    BinaryTreeNode* A = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));//���1
    if (!A) exit(-1);
    A->data = 'A';
    A->left = NULL;
    A->right = NULL;
    BinaryTreeNode* B = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));//���2
    if (!B) exit(-1);
    B->data = 'B';
    B->left = NULL;
    B->right = NULL;
    BinaryTreeNode* C = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));//���3
    if (!C) exit(-1);
    C->data = 'C';
    C->left = NULL;
    C->right = NULL;
    BinaryTreeNode* D = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));//���4
    if (!D) exit(-1);
    D->data = 'D';
    D->left = NULL;
    D->right = NULL;
    BinaryTreeNode* E = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));//���5
    if (!E) exit(-1);
    E->data = 'E';
    E->left = NULL;
    E->right = NULL;
    BinaryTreeNode* F = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));//���6
    if (!F) exit(-1);
    F->data = 'F';
    F->left = NULL;
    F->right = NULL;
    BinaryTreeNode* G = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));//���7
    if (!G) exit(-1);
    G->data = 'G';
    G->left = NULL;
    G->right = NULL;
    BinaryTreeNode* H = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));//���8
    if (!H) exit(-1);
    H->data = 'H';
    H->left = NULL;
    H->right = NULL;
    BinaryTreeNode* I = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));//���9
    if (!I) exit(-1);
    I->data = 'I';
    I->left = NULL;
    I->right = NULL;
    A->left = B;
    A->right = C;
    B->left = D;
    B->right = E;
    C->right = F;
    D->left = G;
    E->left = H;
    E->right = I;
    printf("%d\n", countNodes(A));
}
//2.������Ҷ�ӽڵ����
int countLeafNode(struct BinaryTreeNode* root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->left != NULL || root->right != NULL)//1.���ڵ�֪���Լ�����Ҷ�ӽڵ�����
    {
        return countLeafNode(root->left) + countLeafNode(root->right);
    }
    //2.���ڵ�֪���Լ���Ҷ�ӽڵ�����
    return 1;
}
void test_2(void)
{
    BinaryTreeNode* A = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));//���1
    if (!A) exit(-1);
    A->data = 'A';
    A->left = NULL;
    A->right = NULL;
    BinaryTreeNode* B = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));//���2
    if (!B) exit(-1);
    B->data = 'B';
    B->left = NULL;
    B->right = NULL;
    BinaryTreeNode* C = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));//���3
    if (!C) exit(-1);
    C->data = 'C';
    C->left = NULL;
    C->right = NULL;
    BinaryTreeNode* D = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));//���4
    if (!D) exit(-1);
    D->data = 'D';
    D->left = NULL;
    D->right = NULL;
    BinaryTreeNode* E = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));//���5
    if (!E) exit(-1);
    E->data = 'E';
    E->left = NULL;
    E->right = NULL;
    BinaryTreeNode* F = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));//���6
    if (!F) exit(-1);
    F->data = 'F';
    F->left = NULL;
    F->right = NULL;
    BinaryTreeNode* G = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));//���7
    if (!G) exit(-1);
    G->data = 'G';
    G->left = NULL;
    G->right = NULL;
    BinaryTreeNode* H = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));//���8
    if (!H) exit(-1);
    H->data = 'H';
    H->left = NULL;
    H->right = NULL;
    BinaryTreeNode* I = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));//���9
    if (!I) exit(-1);
    I->data = 'I';
    I->left = NULL;
    I->right = NULL;
    A->left = B;
    A->right = C;
    B->left = D;
    B->right = E;
    C->right = F;
    D->left = G;
    E->left = H;
    E->right = I;
    printf("%d\n", countLeafNode(A));
}
//3.���������߶�
int maxDepth(struct BinaryTreeNode* root)
{
    if (root != NULL)
    {
        int a = maxDepth(root->left);
        int b = maxDepth(root->right);
        return a >= b ? a + 1 : b + 1;
    }
    return 0;
}
void test_3(void)
{
    BinaryTreeNode* A = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));//���1
    if (!A) exit(-1);
    A->data = 'A';
    A->left = NULL;
    A->right = NULL;
    BinaryTreeNode* B = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));//���2
    if (!B) exit(-1);
    B->data = 'B';
    B->left = NULL;
    B->right = NULL;
    BinaryTreeNode* C = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));//���3
    if (!C) exit(-1);
    C->data = 'C';
    C->left = NULL;
    C->right = NULL;
    BinaryTreeNode* D = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));//���4
    if (!D) exit(-1);
    D->data = 'D';
    D->left = NULL;
    D->right = NULL;
    BinaryTreeNode* E = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));//���5
    if (!E) exit(-1);
    E->data = 'E';
    E->left = NULL;
    E->right = NULL;
    BinaryTreeNode* F = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));//���6
    if (!F) exit(-1);
    F->data = 'F';
    F->left = NULL;
    F->right = NULL;
    BinaryTreeNode* G = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));//���7
    if (!G) exit(-1);
    G->data = 'G';
    G->left = NULL;
    G->right = NULL;
    BinaryTreeNode* H = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));//���8
    if (!H) exit(-1);
    H->data = 'H';
    H->left = NULL;
    H->right = NULL;
    BinaryTreeNode* I = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));//���9
    if (!I) exit(-1);
    I->data = 'I';
    I->left = NULL;
    I->right = NULL;
    A->left = B;
    A->right = C;
    B->left = D;
    B->right = E;
    C->right = F;
    D->left = G;
    E->left = H;
    E->right = I;
    printf("%d\n", maxDepth(A));
}
//4.�ж��������Ƿ���ͬ
bool isSameTree(BinaryTreeNode* p, BinaryTreeNode* q)//������ǰ�����
{
    if (p == NULL && q == NULL)
    {
        return true;
    }
    if (p == NULL && q != NULL)
    {
        return false;
    }
    if (p != NULL && q == NULL)
    {
        return false;
    }
    if (p->data != q->data)
    {
        return false;
    }
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
//5.����������ֵΪx�Ľڵ�
BinaryTreeNode* BinarytreeFind(BinaryTreeNode* root, int x)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == x)
    {
        return root;
    }
    BinaryTreeNode* a = BinarytreeFind(root->left , x);
    if (a != NULL)
    {
        return a;
    }
    BinaryTreeNode* b = BinarytreeFind(root->right, x);
    if (b != NULL)
    {
        return b;
    }
    return NULL;
}
void test_4(void)
{
    BinaryTreeNode* A = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));//���1
    if (!A) exit(-1);
    A->data = 'A';
    A->left = NULL;
    A->right = NULL;
    BinaryTreeNode* B = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));//���2
    if (!B) exit(-1);
    B->data = 'B';
    B->left = NULL;
    B->right = NULL;
    BinaryTreeNode* C = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));//���3
    if (!C) exit(-1);
    C->data = 'C';
    C->left = NULL;
    C->right = NULL;
    BinaryTreeNode* D = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));//���4
    if (!D) exit(-1);
    D->data = 'D';
    D->left = NULL;
    D->right = NULL;
    BinaryTreeNode* E = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));//���5
    if (!E) exit(-1);
    E->data = 'E';
    E->left = NULL;
    E->right = NULL;
    BinaryTreeNode* F = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));//���6
    if (!F) exit(-1);
    F->data = 'F';
    F->left = NULL;
    F->right = NULL;
    BinaryTreeNode* G = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));//���7
    if (!G) exit(-1);
    G->data = 'G';
    G->left = NULL;
    G->right = NULL;
    BinaryTreeNode* H = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));//���8
    if (!H) exit(-1);
    H->data = 'H';
    H->left = NULL;
    H->right = NULL;
    BinaryTreeNode* I = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));//���9
    if (!I) exit(-1);
    I->data = 'I';
    I->left = NULL;
    I->right = NULL;
    A->left = B;
    A->right = C;
    B->left = D;
    B->right = E;
    C->right = F;
    D->left = G;
    E->left = H;
    E->right = I;
    BinaryTreeNode* p = NULL;
    p = BinarytreeFind(A, 'A');
    printf("%p - %p = %zd\n", p, A, p - A);
    p = BinarytreeFind(A, 'B');
    printf("%p - %p = %zd\n", p, B, p - B);
    p = BinarytreeFind(A, 'C');
    printf("%p - %p = %zd\n", p, C, p - C);
    p = BinarytreeFind(A, 'D');
    printf("%p - %p = %zd\n", p, D, p - D);
    p = BinarytreeFind(A, 'E');
    printf("%p - %p = %zd\n", p, E, p - E);
    p = BinarytreeFind(A, 'J');
    printf("%p\n", p);
}
//6.�жϵ�ֵ������
bool isUnivalTree(struct BinaryTreeNode* root)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->left != NULL && root->data != root->left->data)
    {
        return false;
    }
    if (root->right != NULL && root->data != root->right->data)
    {
        return false;
    }
    return isUnivalTree(root->left) && isUnivalTree(root->right);
}
//7.�ж϶Գƶ�����
bool _isSymmetric(BinaryTreeNode* leftTree, BinaryTreeNode* rightTree)
{
    if (leftTree == NULL && rightTree == NULL)
    {
        return true;
    }
    if (leftTree == NULL && rightTree != NULL)
    {
        return false;
    }
    if (leftTree != NULL && rightTree == NULL)
    {
        return false;
    }
    if (leftTree->data != rightTree->data)
    {
        return false;
    }
    return _isSymmetric(leftTree->left, rightTree->right) && _isSymmetric(leftTree->right, rightTree->left);
}
bool isSymmetric(BinaryTreeNode* root)
{
    if (root == NULL)
    {
        return true;
    }
    return _isSymmetric(root->left, root->right);
}
//8.ǰ���������
int __preorderTraversal(struct BinaryTreeNode* root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + __preorderTraversal(root->left) + __preorderTraversal(root->right);
}
void _preorderTraversal(struct BinaryTreeNode* root, int* arr, int* i)
{
    if (root == NULL)
    {
        return;
    }
    arr[*i] = root->data;
    if (root->left != NULL)
    {
        (*i)++;
        _preorderTraversal(root->left, arr, i);
    }
    if (root->right != NULL)
    {
        (*i)++;
        _preorderTraversal(root->right, arr, i);
    }
}
int* preorderTraversal(struct BinaryTreeNode* root, int* returnSize)
{
    int maxSize = __preorderTraversal(root);
    int* arr = (int*)malloc(sizeof(int) * maxSize);
    *returnSize = maxSize;
    int i = 0;
    _preorderTraversal(root, arr, &i);
    return arr;
}
int main()
{
    //test_1();
    //test_2();
    //test_3();
    test_4();
    return 0;
}