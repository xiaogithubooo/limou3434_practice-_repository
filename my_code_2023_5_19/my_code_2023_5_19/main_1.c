#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//����Ϊָ��
extern char* a;
//���Ϸ�

//����Ϊ����
extern char b[];
//���Ϸ�
int main()
{
	printf("%d", *a);
	//for (int i = 0; i < 6; i++)
	//{
	//	printf("%d ", *(a + i));
	//}

	return 0;
}

//int main()
//{
//	int a[5] = { 1, 2, 3, 4, 5 };
//	int* ptr = (int*)(&a + 1);//(&a)����������ĵ�ַ��+1�������������飬��ʱָ��ptrָ��������һ������Ԫ�صĺ�һ��int��С�Ŀռ䣬ֱ�ӷ�������ռ��ǷǷ���
//	printf("%d %d\n", *(a + 1), *(ptr - 1));
//	//a+1��a����ĵڶ���Ԫ�أ������þ͵õ�����ĵڶ���Ԫ��2
//	//ptr-1�õ�������������һ��Ԫ��5
//	return 0;
//}
//void Function(int arr[], int size)//���ܵ���int*�����ݣ���ָ��
//{
//	printf("%zd\n", sizeof(arr));//32λΪ4��64λΪ8
//	for (int i = 0; i < size; i++)
//	{
//		printf("%d ", *(arr+i));
//	}
//	printf("\n");
//}
//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6 };
//	int size = sizeof(arr) / sizeof(arr[0]);
//	Function(arr, size);//���鴫�δ���������Ԫ�صĵ�ַ
//	for (int i = 0; i < size; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}