#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//���Ե�ǰ�����Ƿ�֧��C99�ı䳤�����׼
//int main()
//{
//	int n = 10;
//	int arr[n] = { 0 };
//	return 0;
//}
//��������������VS2022�ǲ�֧�ֱ䳤�����
//����gcc��C99��׼�ǿ��Ե�
//int main()
//{
//	char arr[3] = "abc";//��char arr[3]={'a','b','c'};��Ч����ͬ
//	char a[] = "abc"//�ͻ����4��Ԫ��
//  return 0;
//}//�������Է���arr��Ԫ��ֻ����a��b��c����Ԫ�أ�\0��������
//int main()
//{
//	printf("abc\0def\n");//ֻ���ӡabc�����Һ���Ķ�û�������
//	printf("\n");
//	printf("abc0def");//�����ӡ����
//	return 0;
//}
//���⸴ϰ��һ��ʹ��gcc������һ������