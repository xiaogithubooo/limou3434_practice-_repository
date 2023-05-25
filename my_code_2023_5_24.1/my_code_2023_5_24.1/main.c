#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <errno.h>
#include <math.h>
#include <stdbool.h>
//在树中查找符合val值的节点，并且返回这个节点的指针（可充当找或修改）
typedef struct BinaryTreeNode
{
    int data;
    struct BinaryTreeNode* left;
    struct BinaryTreeNode* right;
}BinaryTreeNode;
//题目1
BinaryTreeNode* BTreeFind_1(BinaryTreeNode* root, int x)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == x)
    {
        return root;
    }
    BinaryTreeNode* p1 = BTreeFind_1(root->left, x);
    if (p1) return p1;
    BinaryTreeNode* p2 = BTreeFind_1(root->right, x);
    if (p2) return p2;

    return NULL;
    //这里要深刻理解递归的返回值有可能不会直接回到主函数
}
BinaryTreeNode* BTreeFind_2(BinaryTreeNode* root, int x)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == x)
    {
        return root;
    }
    BinaryTreeNode* p1 = BTreeFind_2(root->left, x);
    if (p1) 
        return p1;

    return BTreeFind_2(root->right, x);
    //这里要深刻理解递归的返回值有可能不会直接回到主函数
}
//题目2
bool isUnivalTree(BinaryTreeNode* root)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->left && root->data != root->left->data)
    {
        return false;
    }
    if (root->right && root->data != root->right->data)
    {
        return false;
    }
    return isUnivalTree(root->left) && isUnivalTree(root->right);
}
void test_1(void)
{
    BinaryTreeNode* A = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
    if (!A) exit(-1);
    A->data = 'A';
    A->left = NULL;
    A->right = NULL;
    BinaryTreeNode* B = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
    if (!B) exit(-1);
    B->data = 'B';
    B->left = NULL;
    B->right = NULL;
    BinaryTreeNode* C = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
    if (!C) exit(-1);
    C->data = 'C';
    C->left = NULL;
    C->right = NULL;
    BinaryTreeNode* D = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
    if (!D) exit(-1);
    D->data = 'D';
    D->left = NULL;
    D->right = NULL;
    BinaryTreeNode* E = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
    if (!E) exit(-1);
    E->data = 'E';
    E->left = NULL;
    E->right = NULL;
    BinaryTreeNode* F = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
    if (!F) exit(-1);
    F->data = 'F';
    F->left = NULL;
    F->right = NULL;
    BinaryTreeNode* G = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
    if (!G) exit(-1);
    G->data = 'G';
    G->left = NULL;
    G->right = NULL;
    BinaryTreeNode* H = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
    if (!H) exit(-1);
    H->data = 'H';
    H->left = NULL;
    H->right = NULL;
    BinaryTreeNode* I = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
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

    BinaryTreeNode *p = BTreeFind_2(A, 'D');
    printf("%c", p->data);
}
void test_2(void)
{
    BinaryTreeNode* A = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
    if (!A) exit(-1);
    A->data = 1;
    A->left = NULL;
    A->right = NULL;
    BinaryTreeNode* B = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
    if (!B) exit(-1);
    B->data = 1;
    B->left = NULL;
    B->right = NULL;
    BinaryTreeNode* C = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
    if (!C) exit(-1);
    C->data = 1;
    C->left = NULL;
    C->right = NULL;
    BinaryTreeNode* D = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
    if (!D) exit(-1);
    D->data = 1;
    D->left = NULL;
    D->right = NULL;
    BinaryTreeNode* E = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
    if (!E) exit(-1);
    E->data = 1;
    E->left = NULL;
    E->right = NULL;
    BinaryTreeNode* F = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
    if (!F) exit(-1);
    F->data = 1;
    F->left = NULL;
    F->right = NULL;
    BinaryTreeNode* G = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
    if (!G) exit(-1);
    G->data = 1;
    G->left = NULL;
    G->right = NULL;
    BinaryTreeNode* H = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
    if (!H) exit(-1);
    H->data = 1;
    H->left = NULL;
    H->right = NULL;
    BinaryTreeNode* I = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
    if (!I) exit(-1);
    I->data = 1;
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
    if (isUnivalTree(A))
    {
        printf("true\n");
    }
    else
    {
        printf("false\n");
    }
}
int main()
{
    //test_1()
    test_2();
    return 0;
}