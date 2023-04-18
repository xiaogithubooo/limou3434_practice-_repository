#define _CRT_SECURE_NO_WARNINGS 1
#include "stack.h"
void Stack_Init(Stack* ps)
{
	assert(ps);

	ps->a = (StackDataType*)malloc(sizeof(StackDataType) * 4);//��ʼ���͸���4���ռ��С
	if (ps->a == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	ps->capacity = 4;//��ʶջ��4��Ԫ��
	ps->top = 0;//����ѡ���ʼ��-1
}
void Stack_Destory(Stack* ps)
{
	assert(ps);

	free(ps->a);
	ps->a = NULL;

	ps->top = 0;
	ps->capacity = 0;
}
void Stack_Push(Stack* ps, StackDataType x)
{
	assert(ps);

	if (ps->capacity == ps->top)//���ջ�ռ䲻������
	{
		StackDataType* tmp = realloc(ps->a, ps->capacity * 2 * sizeof(StackDataType));//����ռ�ڵ�
		if (tmp == NULL)//����ʧ��
		{
			printf("realloc fail\n");
			exit(-1);
		}
		else//����ɹ�
		{
			ps->a = tmp;//���������ɵĿռ��ַ����Ϊrealloc�п��ܸı�ԭ���ĵ�ַ
			ps->capacity *= 2;//����ջ������
		}
	}
	//��������
	ps->a[ps->top] = x;
	ps->top++;
}
void Stack_Pop(Stack* ps)
{
	assert(ps);

	assert(ps->top > 0);//ջ���˾���ֹ����
	ps->top--;//ֱ�Ӽ�һ����������Top����ҲҪ���ٴμ�һ�õ��±�ȡ��Ԫ��
}
StackDataType Stack_Top(Stack* ps)
{
	assert(ps);

	assert(ps->top > 0);//ջ���˾���ֹ����
	return ps->a[ps->top - 1];

}
int Stack_Size(Stack* ps)
{
	assert(ps);

	return ps->top;
}
bool Stack_Empty(Stack* ps)
{
	assert(ps);

	return (ps->top == 0);
}