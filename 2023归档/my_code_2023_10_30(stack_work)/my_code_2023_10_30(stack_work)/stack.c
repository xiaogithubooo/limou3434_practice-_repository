#include "stack.h"

//> 1.֧�ֶ�̬������ջ
/*
//typedef int STDataType;
//typedef struct Stack
//{
//	STDataType* _a;
//	int _top;		//ջ��
//	int _capacity;	//���� 
//}Stack;
*/

//> 2.��ʼ��ջ
void StackInit(Stack* ps)
{
	//1.���ָ����Ч��
	assert(ps);

	//2.��ʼ��ջ����Ϣ
	ps->_a = (STDataType*)malloc(sizeof(STDataType) * 4);//�ȸ���4���ռ䣬���Ҽ���Ƿ�����ɹ�
	if (!ps->_a)
	{
		perror("malloc fail!\n");
		return;
	}
	ps->_top = 0;//�����ֵҲ������-1
	ps->_capacity = 4;
}

//> 3.��ջ 
void StackPush(Stack* ps, STDataType data)
{
	//1.���ָ����Ч��
	assert(ps);
	//2.���ջ�����Ƿ�����
	if (ps->_capacity == ps->_top)
	{
		STDataType* cache = (STDataType*)realloc(ps->_a, sizeof(STDataType) * ((ps->_capacity) * 2));
		if (!cache)
		{
			printf("realloc fail!\n");
			exit(-1);
		}
		ps->_a = cache;
		ps->_capacity = ps->_capacity * 2;
	}
	//3.��ջ���Ҹ���ջ������
	ps->_a[ps->_top] = data;
	ps->_top++;
}

//> 4.��ջ 
void StackPop(Stack* ps)
{
	//1.���ָ����Ч��
	assert(ps);
	//2.���ջ�Ƿ���Ԫ��
	assert(ps->_top > 0);
	//3.ֱ�������±ꡰɾ����Ԫ�أ�ע��ջ�ڴ洢Ԫ�صġ�ʵ���±ꡱ�ȡ�_top������ֵС1
	ps->_top--;
}

//> 5.��ȡջ��Ԫ�� 
STDataType StackTop(Stack* ps)
{
	//1.���ָ�����Ч��
	assert(ps);
	//2.���ջ�Ƿ���Ԫ��
	assert(ps->_top > 0);
	//3.ȡ��ջ��Ԫ��
	return ps->_a[ps->_top - 1];
}

//> 6.��ȡջ����ЧԪ�ظ��� 
int StackSize(Stack* ps)
{
	//1.���ָ�����Ч��
	assert(ps);
	//2.��ȡԪ�ظ���
	return ps->_top;
}

//> 7.���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط��㣬�����Ϊ�շ���0 
int StackEmpty(Stack* ps)
{
	assert(ps);
	return (ps->_top == 0);
}

//> 8.����ջ 
void StackDestroy(Stack* ps)
{
	assert(ps);
	free(ps->_a);
	ps->_a = NULL;
	ps->_capacity = ps->_top = 0;
}