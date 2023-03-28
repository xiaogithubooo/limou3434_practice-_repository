//<函数测试部分>
#define _CRT_SECURE_NO_WARNINGS 1
#include "function.h"
//测试函数
void test_1()
{
    BinaryTreeNode* A = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
    A->data = 'A';
    A->left = NULL;
    A->right = NULL;

    BinaryTreeNode* B = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
    B->data = 'B';
    B->left = NULL;
    B->right = NULL;

    BinaryTreeNode* C = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
    C->data = 'C';
    C->left = NULL;
    C->right = NULL;

    BinaryTreeNode* D = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
    D->data = 'D';
    D->left = NULL;
    D->right = NULL;

    BinaryTreeNode* E = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
    E->data = 'E';
    E->left = NULL;
    E->right = NULL;

    BinaryTreeNode* F = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
    F->data = 'F';
    F->left = NULL;
    F->right = NULL;

    BinaryTreeNode* G = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
    G->data = 'G';
    G->left = NULL;
    G->right = NULL;

    BinaryTreeNode* H = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
    H->data = 'H';
    H->left = NULL;
    H->right = NULL;

    BinaryTreeNode* I = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
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

    Prev_Order(A);
    printf("\n");

    In_Order(A);
    printf("\n");

    Post_Order(A);
    printf("\n");

    //int size = 0;
    //Tree_Size(A, &size);
    //printf("%d", size);
    printf("%d\n", Tree_Size(A));
    printf("%d\n", Tree_Leaf_Size(A));
}
//测试主函数
int main()
{
    test_1();//可以看到测试得到的结果和分析是一样的
    return 0;
}