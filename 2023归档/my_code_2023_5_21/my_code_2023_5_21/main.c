#define _CRT_SECURE_NO_WARNINGS 1
//typedef struct TreeNode
//{
//	int data;//�洢�ڵ������
//	struct TreeNode* child_1;//�洢�ڵ�ָ����Ӻ���1
//	struct TreeNode* child_2;//�洢�ڵ�ָ����Ӻ���2
//	struct TreeNode* child_3;//�洢�ڵ�ָ����Ӻ���3
//	//��
//}TreeNode;
//typedef struct TreeNode
//{
//	int data;//�洢�ڵ������
//	SeqList childArr;
//}TreeNode;
//typedef struct TreeNode
//{
//	int data;//�洢�ڵ������
//	int parenti;
//}TreeNode;
////Ȼ�󴴽�һ������Ԫ����TreeNode�Ľṹ������
typedef struct TreeNode
{
	int data;//�洢���ڵ������
	struct TreeNode* firstChild;//���ڵ�ָ��ĵ�һ�����ӽڵ�
	struct TreeNode* Brother;//���ڵ���ֵܽڵ�
}TreeNode;