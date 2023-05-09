#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <errno.h>
#include <math.h>
#include <stdbool.h>
//# 0.目标："二叉树"的练习
//>		0.1.复习“二叉树”code
//			0.1.1.重新看“二叉树”的code
//			0.1.2.对“二叉树”进行调试
//			0.1.3.while (!(成功写出“二叉树”)) { 回去看代码; }
//>		0.2.使用“二叉树”思想
//			0.2.1.刷推荐和作业的题目
//				0.2.1.1.单值二叉树：https://leetcode.cn/problems/univalued-binary-tree/
//				0.2.1.2.相同的树：https://leetcode.cn/problems/same-tree/
//				0.2.1.3.对称二叉树：https://leetcode.cn/problems/symmetric-tree/
//				0.2.1.4.二叉树的前序遍历：https://leetcode.cn/problems/binary-tree-preorder-traversal/
//				0.2.1.5.二叉树的中序遍历：https://leetcode.cn/problems/binary-tree-inorder-traversal/
//				0.2.1.6.二叉树的后序遍历：https://leetcode.cn/problems/binary-tree-postorder-traversal/
//				0.2.1.7.另一棵树的子树：https://leetcode.cn/problems/subtree-of-another-tree/
//				0.2.1.8.二叉树遍历：https://www.nowcoder.com/practice/4b91205483694f449f94c179883c1fef?tpId=60&&tqId=29483&rp=1&ru=/activity/oj&qru=/ta/tsing-kaoyan/question-ranking
//			0.2.2.刷其他力扣的题目
//>		0.3.写“二叉树”的博客
//			0.3.1.力扣题解
//			0.3.2.CSDN博客
//# 1.复习“二叉树”code
//> 1.1.构造一个孩子兄弟树的结构体
typedef int BinaryTreeDataType;
typedef struct BinaryTreeNode
{
    BinaryTreeDataType data;//存放数据
    struct BinaryTreeNode* left;//指向左孩子节点
    struct BinaryTreeNode* right;//指向右孩子节点
}BinaryTreeNode;
//! 1.2.树的存储函数
BinaryTreeNode* BuyNode(BinaryTreeDataType x)
{
    BinaryTreeNode* cache = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
    if (!cache) exit(-1);
    cache->data = x;
    cache->left = cache->right = NULL;
    return cache;
}
void datastorage(BinaryTreeNode* root, BinaryTreeDataType arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        BuyNode(arr[i]);
    }
}
//> 1.3.树的遍历函数
//  1.3.1.前序遍历
void PrevOrder(BinaryTreeNode* root)
{
    ;
}
//  1.3.2.中序遍历
void InOrder(BinaryTreeNode* root)
{
    ;
}
//  1.3.3.后序遍历
void PostOrder(BinaryTreeNode* root)
{
    ;
}
//  1.3.4.层序遍历
void LevelOrder(BinaryTreeNode* root)
{
    ;
}
//# 2.使用“二叉树”思想

//# 3.测试用例
void test()
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
}
void test_1(void)
{
    ;
}
void test_2(void)
{
    ;
}
void test_3(void)
{
    ;
}
void test_4(void)
{
    ;
}
void test_5(void)
{
    ;
}
void test_6(void)
{
    ;
}
void test_7(void)
{
    ;
}
void test_8(void)
{
    ;
}
void test_9(void)
{
    ;
}
void test_10(void)
{
    ;
}
void test_11(void)
{
    ;
}
void test_12(void)
{
    ;
}
int main()
{
    test_1();
    //test_2();
    //test_3();
    //test_4();
    //test_5();
    //test_6();
    //test_7();
    //test_8();
    //test_9();
    //test_10();
    //test_11();
    //test_12();
    return 0;
}