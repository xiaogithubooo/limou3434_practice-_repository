#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//1���й���char���͸�ֵ������Χ�����ʵ��
//int main()
//{
//	char a = 'FATE';
//	printf("%c", a);
//	//���Կ���ֻ�����E���൱��4��1�ֽ��ַ���ֻ�ض����һ���ַ������8λ����1�ֽڣ�����ֵ
//	return 0;
//}

//2������ת���ַ��İ˽��ƺ�ʮ���Ʊ�ʾASCIIֵ
//int main()
//{
//  //������ACSIIֵ��7
//	//char x = 7;//ʮ��������
//	//char x = '\07';//�˽�������
//	//char x = '\x7';//ʮ����������
//	char x = 07;//Ҳ�ǿ�������ģ�����\07�������ʾ��������һ��������ҿ�����Ϊ�ַ������ַ���֮��
//	printf("%c", x);
//	//���Կ������ֶ��ǿ���ʵ�֡������������
//	return 0;
//}

//3��ʹ��ת���ַ�����
//д��һ��
/*int main()
{
	char* a = 0;
	printf("$_______\b\b\b\b\b\b\b");
	scanf("%s", &a);
	printf("a=%s", &a);
	return 0;
}*///��������е����⣬��֪����ô�ġ���
//д������
//int main()
//{
//	char a[8] = { 0 };
//	printf("$_______\b\b\b\b\b\b\b");
//	for (int i = 0; i < 7; i++)
//	{
//		scanf("%c", &a[i]);
//	}
//	for (int i = 0; i < 7; i++)
//	{
//		printf("%c", a[i]);
//	}
//	return 0;
//}//������뵹������������

//4��ASCIIת����
//int main()
//{
//	int my_ascii;
//
//	printf("������һ��ASCII��ֵ: ");
//	scanf("%d", &my_ascii);
//	printf("ASCII %d ��Ӧ���ַ��� %c\n", my_ascii, my_ascii);
//	return 0;
//}
