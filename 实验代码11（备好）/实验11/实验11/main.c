#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<math.h>
#include<Windows.h>
//ʵ��Ŀ�ģ�
//��1����Ϥ�ַ����Ļ�������
//��2������ָ����ַ������ʹ�÷���
//��3�������ַ�����صĿ⺯����ʹ�÷���

//����һ��
//int main(void)
//{
//	char src[80]={' '};
//	char dest[80]={' '};
//	printf("������һ���ַ���");
//	gets(src);
//	printf("ִ��strcpyǰdest�����ݣ�");
//	puts(dest);
//	strcpy(dest, src);
//	printf("ִ��strcpy��dest�����ݣ�");
//	puts(dest);
//	return 0;
//}
//�������
void myStrCat(char* dest, char* src)
{
	puts(strcat(dest,src));                                   //����Ц������д��
}                                                           //��������⺯���õ�Ҳ������
int main(void)
{
	char src[80];
	char dest[80];
	printf("������һ���ַ���src��");
	gets(src);
	printf("������һ���ַ���dest��");
	gets(dest);
	//ִ�к���ǰ
	printf("ִ��myStrCatǰdest������:");
	puts(dest);
	//ִ�к�����
	printf("ִ��myStrCat��dest������:");
	myStrCat(dest, src);
	return 0;//��˵Ϊʲô������Զ��������ţ�����
}
//��������
//int main(void)
//{
//	char arr[80];
//	char ch;
//	char* p;
//	int i;//ѭ������
//	printf("������һ���ַ���arr��");
//	gets(arr);
//	printf("������Ҫ���ҵ��ַ���");
//	scanf("%c", &ch);
//	p = strchr(arr, ch);//�⺯�����Һ���                     //����⺯���õĲ�����
//	printf("%c���ַ���%s�е�����Ϊ��",ch,arr);
//	for (i=0; i < 80; ++i)
//	{
//		if (&arr[i] == p)
//		{
//			printf("%d", i);                                 //��ɵ��е���hhhhhhh
//		}
//	}
//	return 0;
//}