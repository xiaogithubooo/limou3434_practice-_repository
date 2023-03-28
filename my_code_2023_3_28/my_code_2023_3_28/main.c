#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <assert.h>
//int my_atoi(char* str)
//{
//	assert(str);
//	int number = 0;
//	while (*str)
//	{
//		if (*str >= '0' && *str <= '9')
//		{
//			number = (*str - '0') + (number * 10);
//		}
//		else
//		{
//			return number;
//		}
//		str++;
//	}
//	return number;
//}
//int main()
//{
//	int n = 0;
//	char str[20];
//	while (scanf("%s", str) == 1)
//	{
//		printf("%d\n", my_atoi(str));
//	}
//
//	return 0;
//}

//<函数声明文件>
#define _CRT_SECURE_NO_WARNINGS 1
//0.0.库函数定义
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//0.1.宏定义
//0.2.构造一个孩子兄弟树的结构体
typedef int BinaryTreeDataType;typedef struct BinaryTreeNode{    BinaryTreeDataType data;//存放数据    
struct BinaryTreeNode* left;//指向左孩子节点    
struct BinaryTreeNode* right;//指向右孩子节点
}BinaryTreeNode;
//函数定义
//1.前序函数
void Prev_Order(BinaryTreeNode* root)
{
    if (root == NULL)
    {
        printf("NULL ");
        return;
    }
    printf("%c ", root->data);
    Prev_Order(root->left);
    Prev_Order(root->right);
}

//2.中序函数
void In_Order(BinaryTreeNode* root)
{
    if (root == NULL)
    {
        printf("NULL ");
        return;
    }
    In_Order(root->left);
    printf("%c ", root->data);
    In_Order(root->right);
}

//3.后序函数
void Post_Order(BinaryTreeNode* root)
{
    if (root == NULL)
    {
        printf("NULL ");
        return;
    }
    Post_Order(root->left);
    Post_Order(root->right);
    printf("%c ", root->data);
}


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
}
//测试主函数
int main()
{
    test_1();//可以看到测试得到的结果和分析是一样的
    return 0;
}