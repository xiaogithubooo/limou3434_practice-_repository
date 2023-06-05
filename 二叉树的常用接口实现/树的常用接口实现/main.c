#include "BinaryTreeNode.h"
//���Դ���
void test(void)
{
	char arr[100];
	int scanfreturn = scanf("%s", arr);
	int n = (int)strlen(arr);
	int i = 0;
	BinaryTreeNode* tree = BinaryTreeCreate(arr, n, &i);//ǰ�򴴽�������
	printf("���ڵ㡱��������%d\n", BinaryTreeSize(tree));//��������ڵ����
	printf("��Ҷ�ӽڵ㡱��������%d\n", BinaryTreeLeafSize(tree));//�������Ҷ�ӽڵ����
	BinaryTreeNode* p = BinaryTreeFind(tree, 'b');//����ֵΪx�Ľڵ�
	if (p != NULL)
	{
		printf("%c\n", p->data);
	}
	else
	{
		printf("�Ҳ�������value�����Ľڵ�\n");
	}
	printf("%d\n", BinaryTreeLevelKSize(tree, 1));//�鿴ĳһ��Ľڵ����
	printf("%d\n", BinaryTreeLevelKSize(tree, 2));
	printf("%d\n", BinaryTreeLevelKSize(tree, 3));
	printf("%d\n", BinaryTreeLevelKSize(tree, 4));
	printf("%d\n", BinaryTreeLevelKSize(tree, 5));
	printf("%d\n", BinaryTreeLevelKSize(tree, 6));
	printf("%d\n", BinaryTreeLevelKSize(tree, 7));
	if (BinaryTreeComplete(tree))
	{
		printf("����ȫ������\n");
	}
	else
	{
		printf("������ȫ������\n");
	}
	printf("ǰ�������");
	BinaryTreePrevOrder(tree);//ǰ�����������
	printf("\n"); 

	printf("���������");
	BinaryTreeInOrder(tree);//�������������
	printf("\n");

	printf("���������");
	BinaryTreePostOrder(tree);//�������������
	printf("\n");

	printf("���������");
	BinaryTreeLevelOrder(tree);//�������������
	printf("\n");

	BinaryTreeDestory(tree);//���ٶ�����
}
int main()
{
	test();
	return 0;
}