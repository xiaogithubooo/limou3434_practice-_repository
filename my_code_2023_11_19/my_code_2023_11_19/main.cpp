#include <stdio.h>
#include <string.h>

int main()
{
	//char* �� char arr[]���ַ����飩������ָ�����һ���ַ���
	const char* s1 = "abcd";
	char s2[] = "abcd";
	char s3[] = { 'a','b','c' };		//����Ǵ洢������ַ������飬ĩβû�� \0
	char s4[] = { 'a','b','c','\0' };	//������û������

	printf("%s\n", s1);	//���� %s ��ӡ���ַ���
	printf("%s\n", s2);	//���� %s ��ӡ���ַ���

	printf("%d\n", strlen(s4));   //Ҳ�ǿ� \0 �������ַ����ĳ��ȵģ������ 3�����ַ����ĳ���
	printf("%d\n", strlen(s3));   //��������Ƿ� 3 ��ֵ���Ǹ����ֵ��ʲôʱ���ҵ� \0 ���������

	char s5[4] = { 'b','i','t' };
	printf("%d\n", strlen(s5));//���ڷ����� 3 ��Ԫ�أ��� 4 ����ʼ��Ĭ��Ϊ 0���� '\0'���� strlen(arr) �� 3�������ǲ������ֵ
}

//#include <stdio.h>
//int a;
//int main()
//{
//	printf("%d\n", a);
//	return 0;
//}
// 
////#include <stdio.h>
////int a = 20;
////int main()
////{
////	printf("%d\n", a);
////	{
////		printf("%d\n", a);
////	}
////	return 0;
////}//���ӡ������20
//
//
////#include <cstdio>
////int main()//�ֲ�����������������ʾ
////{
////    {
////        int a = 10;
////        printf("%d\n", a);
////    }
////    //����� a �����ߵ����д���ͱ����٣�������
////    return 0;
////}