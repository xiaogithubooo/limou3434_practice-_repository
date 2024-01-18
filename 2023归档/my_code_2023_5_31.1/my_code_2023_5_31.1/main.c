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

//1.求根结点的个数
//使用全局变量
//int SIZE = 0;
//使用静态变量
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
    BinaryTreeNode* A = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));//结点1
    if (!A) exit(-1);
    A->data = 'A';
    A->left = NULL;
    A->right = NULL;
    BinaryTreeNode* B = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));//结点2
    if (!B) exit(-1);
    B->data = 'B';
    B->left = NULL;
    B->right = NULL;
    BinaryTreeNode* C = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));//结点3
    if (!C) exit(-1);
    C->data = 'C';
    C->left = NULL;
    C->right = NULL;
    BinaryTreeNode* D = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));//结点4
    if (!D) exit(-1);
    D->data = 'D';
    D->left = NULL;
    D->right = NULL;
    BinaryTreeNode* E = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));//结点5
    if (!E) exit(-1);
    E->data = 'E';
    E->left = NULL;
    E->right = NULL;
    BinaryTreeNode* F = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));//结点6
    if (!F) exit(-1);
    F->data = 'F';
    F->left = NULL;
    F->right = NULL;
    BinaryTreeNode* G = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));//结点7
    if (!G) exit(-1);
    G->data = 'G';
    G->left = NULL;
    G->right = NULL;
    BinaryTreeNode* H = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));//结点8
    if (!H) exit(-1);
    H->data = 'H';
    H->left = NULL;
    H->right = NULL;
    BinaryTreeNode* I = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));//结点9
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
//2.求树的叶子节点个数
int countLeafNode(struct BinaryTreeNode* root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->left != NULL || root->right != NULL)//1.根节点知道自己不是叶子节点的情况
    {
        return countLeafNode(root->left) + countLeafNode(root->right);
    }
    //2.根节点知道自己是叶子节点的情况
    return 1;
}
void test_2(void)
{
    BinaryTreeNode* A = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));//结点1
    if (!A) exit(-1);
    A->data = 'A';
    A->left = NULL;
    A->right = NULL;
    BinaryTreeNode* B = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));//结点2
    if (!B) exit(-1);
    B->data = 'B';
    B->left = NULL;
    B->right = NULL;
    BinaryTreeNode* C = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));//结点3
    if (!C) exit(-1);
    C->data = 'C';
    C->left = NULL;
    C->right = NULL;
    BinaryTreeNode* D = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));//结点4
    if (!D) exit(-1);
    D->data = 'D';
    D->left = NULL;
    D->right = NULL;
    BinaryTreeNode* E = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));//结点5
    if (!E) exit(-1);
    E->data = 'E';
    E->left = NULL;
    E->right = NULL;
    BinaryTreeNode* F = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));//结点6
    if (!F) exit(-1);
    F->data = 'F';
    F->left = NULL;
    F->right = NULL;
    BinaryTreeNode* G = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));//结点7
    if (!G) exit(-1);
    G->data = 'G';
    G->left = NULL;
    G->right = NULL;
    BinaryTreeNode* H = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));//结点8
    if (!H) exit(-1);
    H->data = 'H';
    H->left = NULL;
    H->right = NULL;
    BinaryTreeNode* I = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));//结点9
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
int main()
{
    //test_1();
    test_2();
	return 0;
}