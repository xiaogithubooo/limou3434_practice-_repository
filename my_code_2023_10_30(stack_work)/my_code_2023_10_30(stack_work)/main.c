#include "stack.h"

//1.����ջ�ĺ�����
void test();
//2.ʮ����ת��ΪN����
void 
int main()
{
	//test();
	//
	return 0;
}


void test()
{
	Stack st1;//����һ��ջ�ṹ��
	StackInit(&st1);//��ʼ�����ջ
	StackPush(&st1, 1);//ѹջ
	StackPush(&st1, 2);//ѹջ
	StackPush(&st1, 3);//ѹջ
	StackPush(&st1, 4);//ѹջ
	StackPush(&st1, 5);//ѹջ

	printf("<ջ��>\n");
	while (!StackEmpty(&st1))//ֻҪջ��Ϊ�վͽ���ѭ��
	{
		printf("%3d\n", StackTop(&st1));//ȡ��ջ��Ԫ�ز��Ҵ�ӡ
		StackPop(&st1);//ɾ��ջ��Ԫ��
	}
	printf("<ջ��>\n");
	//StackPop(&st1);//�Ƿ�ɾ��
	//StackPop(&st1);//�Ƿ�ȡջ��Ԫ��
	StackDestroy(&st1);//����ջ�ṹ��
}