#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
typedef char BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BinaryTreeNode;
BinaryTreeNode* BuyNode(BTDataType x)
{
	BinaryTreeNode* cache = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
	if (!cache) exit(-1);
	cache->data = x;
	cache->left = NULL;
	cache->right = NULL;
	return cache;
}
BinaryTreeNode* BinaryTreeCreate(BTDataType* arr, int n, int* pi)
{
	BinaryTreeNode* root = NULL;
	if (arr[*pi] == '#')
	{
		(*pi)++;
		return root;
	}
	root = BuyNode(arr[(*pi)++]);
	root->left = BinaryTreeCreate(arr, n, pi);
	root->right = BinaryTreeCreate(arr, n, pi);
	return root;
}
void BinaryTreeInOrder(BinaryTreeNode* root)
{
	if (root == NULL)
	{
		return;
	}
	BinaryTreeInOrder(root->left);
	printf("%c ", root->data);
	BinaryTreeInOrder(root->right);
}
int main()
{
	char arr[100];
	int scanfreturn = scanf("%s", arr);
	int n = strlen(arr);
	int i = 0;
	BinaryTreeNode* tree = BinaryTreeCreate(arr, n, &i);
	BinaryTreeInOrder(tree);
	return 0;
}