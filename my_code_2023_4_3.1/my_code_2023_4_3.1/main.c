#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#define NUM  
int main()
{
#if defined(NUM)
#endif
	return 0;
}

int main()
{
	int NUM1 = 200;//����Ԥ�����ʱ���ǲ��ɼ��ģ�NUM1��δ������
#ifdef NUM1 == 200
	printf("������NUM1");
#endif
	return 0;
}
#define NUM2 100
#elif NUM2
	printf("������NUM2");
#else
	printf("NUM1��NUM2��δ����\n");
int main()
{
	int arr[NUM];
	for (int i = 0; i < NUM; i++)
	{
		arr[i] = i;
	}
	for (int i = 0; i < NUM; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}


#define NUMBER 10
#define ADD(X,Y) ((X) + (Y))
int main()
{
	printf("%d", NUMBER);
#undef NUMBER
	printf("%d", NUMBER);//��������û�취ʶ��NUMBER������
	
	printf("%d", ADD(1, 2));
#undef ADD
	printf("%d", ADD(1, 2));//��������û�취ʶ��ADD������
	
	return 0;
}
#include <stdlib.h>
#define MALLOC(num, type) ((type*)malloc(num * sizeof(type)))
int main()
{
	int* p = MALLOC(10, int);
	if (!NULL)
	{
		return 0;
	}
	p[0] = 2;
	p[1] = 0;
	p[2] = 2;
	p[3] = 3;
	for (int i = 0; i < 4; i++)
	{
		printf("%d ", p[i]);
	}
	free(p);
	return 0;
}

#define ADD(X,Y) ((X) + (Y))
int main()
{
	ADD(1, 2);
	return 0;
 }