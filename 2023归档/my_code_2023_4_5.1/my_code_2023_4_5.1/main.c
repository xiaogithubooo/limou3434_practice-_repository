#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int arr[3] = { 6, 2, 3 };//ʵ���ϣ��κ�һ��������ֻҪɾȥ��������ʣ�µľ��Ǳ��������ͣ���������������;���int[3]
	int(*p1)[3] = &arr;//&arr��ȡ����������ĵ�ַ
	printf("%p\n%p\n", p1, p1 + 1);

	int(*p2)[3] = (p1 + 1);
	printf("%zd", (p2) - (p1));//�õ�int()[3]Ԫ����1��
	return 0;
}
int main()
{
	int a = 1;
	int b = 9;
	int c = 4;
	int d = 6;
	int* arr[4] = { &a, &b, &c, &d };
	for (int i = 0; i < 4; i++)
	{
		printf("%p\n", arr[i]);
	}
	return 0;
}
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,0 };
	int* p = arr; //ָ����������Ԫ�صĵ�ַ
	int sz = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < sz; i++)
	{
		printf("\"&arr[%d] = %p\" �� \"p+%d = %p\"\n", i, &arr[i], i, p + i);
	}
	printf("\n");
	for (int i = 0; i < sz; i++)
	{
		printf("\"&arr[%d] = %d\" �� \"p+%d = %d\"\n", i, arr[i], i, *(p + i));
	}
	return 0;
}
int main()
{
	int arr[10] = { 1,1,2,4,3 };
	if (&arr[3] > &arr[0])
	{
		printf("(&arr[3])�Ǹߵ�ַ\n");
	}
	return 0;
}
int main()
{
	char arr[] = "abcdef";
	int a = arr[5] - arr[0];
	printf("%d", a);//�õ�����ָ��֮��Ԫ�صĸ���
	return 0;
}
int main()
{
    int n = 0x11223344;//ʮ����������

    char* pc = (char*)&n;
    int* pi = &n;

    *pc = 0;   //�۲��ڴ�ı仯
    *pi = 0;   //�۲��ڴ�ı仯

    return 0;
}