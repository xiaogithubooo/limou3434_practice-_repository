#include <iostream>
using namespace std;
int globalVar = 1;//ȫ�ֱ������洢�����ݶ�
static int staticGlobalVar = 1;//��̬ȫ�ֱ������洢�����ݶ�
void Test(void)
{
	static int staticVar = 1;//��̬�ֲ��������洢�����ݶ�
	int localVar = 1;//�ֲ��������洢��ջ

	int num1[10] = { 1,2,3,4 };//����ֲ�����һ���Դ���������洢��ջ
	char char2[] = "abcd";//������ʵ�����ǰѳ������á�abcd\0��������char���飩�������ʽ��abcd�����洢�ڴ���Σ�����char2����洢��ջ
	const char* pChar3 = "abcd";//�������ʽ����abcd���洢�ڴ���Σ�pChar3�洢��ջ��
	int* ptr1 = (int*)malloc(sizeof(int) * 4);//ptr1�洢��ջ�ϣ�*ptr1�洢�ڶ���
	int* ptr2 = (int*)calloc(4, sizeof(int));//ptr2�洢��ջ�ϣ�*ptr2�洢�ڶ���
	int* ptr3 = (int*)realloc(ptr2, sizeof(int) * 4);//ptr3�洢��ջ�ϣ�*ptr3�洢�ڶ���
	free(ptr1);
	free(ptr3);
}
int main()
{
	Test();
	return 0;
}