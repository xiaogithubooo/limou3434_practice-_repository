#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>     
#include <string.h>
#include <stdlib.h>
////1��ţ������Ŀ����
//double S(double a, double b, double c)
//{
//    double p = ((a + b + c) / 2);
//    return sqrt(p*(p - a)*(p - b)*(p - c));
//}
//int main()
//{
//    double a, b, c;//�߳�
//    double s;//���
//    scanf("%lf %lf %lf", &a, &b, &c);
//    s = S(a,b,c);//�������
//    printf("circumference=%.2lf area=%.2lf", a + b + c,s);
//    return 0;
//}//���ŷ��������������β���ʽ����a+b>c��������1��2��3�ǲ����������εġ�

////2���йض�̬�ڴ����Ŀ��һ��
//void GetMemory(char **p, int num)
//{
//	*p = (char *)malloc(num);//������100���ֽڵĶ�̬�ڴ�ռ䣬���Ұ����ռ���׵�ַ����*p����p��������û�л���ȥ
//}
//void Test(void)
//{
//	char* str = NULL;//����ָ���ÿ�
//	GetMemory(&str, 100);//����GetMemory������ʹ���˲�����ָ���ָ�룬100��
//	strcpy(str, "hello");//����hello�ַ�����str��
//	printf(str);//��ӡstr�Ľ��
//}
//int main()
//{
//	Test();
//	return 0;
//}
////�ҵ��뷨��Ӧ��û���ѽ��ֻ���ڴ�й¶�ˡ���Ҳ���ӡ��hello�Ľ��
////���������������Ľⷨ����Ψһ���������Ҫ�ͷŶ�̬�ڴ�
////�޸ĺ�
//void GetMemory(char** p, int num)
//{
//	*p = (char*)malloc(num);//������100���ֽڵĶ�̬�ڴ�ռ䣬���Ұ����ռ���׵�ַ����*p����p��������û�л���ȥ
//}
//void Test(void)
//{
//	char* str = NULL;//����ָ���ÿ�
//	GetMemory(&str, 100);//����GetMemory������ʹ���˲�����ָ���ָ�룬100��
//	strcpy(str, "hello");//����hello�ַ�����str��
//	printf(str);//��ӡstr�Ľ��
//
//	free(str);//����ȥ��̬�ڴ棬�����ÿ�
//	str = NULL;
//}
//int main()
//{
//	Test();
//	return 0;
//}

////3���йض�̬�ڴ����Ŀ������
//void Test(void)
//{
//	char* str = (char*)malloc(100); //������100���ֽڿռ䷵���׵�ַ���ֲ�����str
//	strcpy(str, "hello");//str���պ��ֱ�׷�ӿ�����hello
//	free(str);//��ǰ�ջ����ڴ�ռ䣬��Ȼֵ���ڵ�����������ʻᱻ����λ����ֵ
//	if (str != NULL)//�Ƿ��������ڴ棬���⣬����һ���������free�����Զ�NULL����жϸ�������û���õ�
//	{
//		strcpy(str, "world");//����ԭ����hello
//		printf(str);
//	}
//}
//int main()
//{
//	Test();//���ú�����
//	return 0;
//}
////�޸ĺ�
//void Test(void)
//{
//	char* str = (char*)malloc(100); //������100���ֽڿռ䷵���׵�ַ���ֲ�����str
//	strcpy(str, "hello");//str���պ��ֱ�׷�ӿ�����hello
//	free(str);//��ǰ�ջ����ڴ�ռ䣬��Ȼֵ���ڵ�����������ʻᱻ����λ����ֵ
//	str = NULL;
//	if (str != NULL)//�Ƿ��������ڴ�
//	{
//		strcpy(str, "world");//����ԭ����hello
//		printf(str);
//	}
//}
//int main()
//{
//	Test();//���ú�����
//	return 0;
//}
////��Ҫֻ����free��λ�ã�����if���жϾͲ����ϴ����߼��ˡ�

////4�����������ʹ��
////��1����ʹ����������
////a�������ṹ��S
//struct S
//{
//	int n;
//	int* arr;//����ָ��arr����ʽ�е�������
//};
//int main()
//{
////b�����붯̬�ڴ棬���ڴ�ռ�Ϊһ���ṹ��Ĵ�С�����ҷ����׵�ַ���ṹ��ָ��ps
//	struct S* ps = (struct S*)malloc(sizeof(struct S));
////c�����붯̬�ڴ�,���ڴ�ռ�Ϊ5�����δ�С�ģ����ҷ����׵�ַ���ṹ���Աarr
//	ps->arr = malloc(5 * sizeof(int));
////d��ʹ��������ڴ�
//	int i = 0;
//	for (i = 0; i < 5; i++)
//	{
//		ps->arr[i] = i;//�������������ʽ�ǲ�����ζ��arr[i]��*(arr+i)�������ȫ�ȼ۵ģ�[]�������޹������һ�ֽ����÷�ʽ��
//	}
//	for (i = 0; i < 5; i++)
//	{
//		printf("%d ", ps->arr[i]);
//	}
//	printf("\n");
////e����������ռ�Ĵ�С
//	int* ptr = realloc(ps->arr,10*sizeof(int));
//	if (ptr != NULL)
//	{
//		ps->arr = ptr;
//	}
//	for (i = 5; i < 10; i++)
//	{
//		ps->arr[i] = i;
//	}
//	for (i = 5; i < 10; i++)
//	{
//		printf("%d ",ps->arr[i]);
//	}
////f���ͷŶ�̬�ڴ棨�����ͷ��Ⱥ������ģ�
//	free(ps->arr);
//	ps->arr = NULL;
//	free(ps);
//	ps = NULL;
//	return 0;
//}
//��2��ʹ����������
//struct S
//{
//	int n;
//	int arr[0];//��ϸ���Ļ��ͻᷢ�ֺ���ͨ���鲻ͬ����ͨ����[]�����ǲ�����Ϊ0�ģ�
//};
//int main()
//{
//	struct S* ps = (struct S*)malloc(sizeof(struct S) + 5 * sizeof(int));
//	//�����5*sizeof(int)���������������ġ�
//	//ʹ����������Ļ��Ϳ��Լӿ촴���ٶȣ���������Ķ�����
//	return 0;
//}
////�ܽ᣺
////��1�������������д�����Ӽ򵥣�
////��2���������鲻��Ҫ�������ͷ��ڴ�����⣻
////��3����������������ṹ���Ա�������ģ��������̫����ڴ���Ƭ������ڴ�������
////��4����������£�����Ч�ʸ���
//������������û�б�������������Ϊ�ܶ����Ա��ϰ������д��

//5������������
//��C99�У��ṹ�����һ����Ա������һ��λ�ô�С�����飬���������ǡ��������顱��Ա���͡��䳤���顱�ĸ���Ǻ��������
struct S
{
	int n;
	char c;
	int arr[];//����������������Ա�������[]д��д0�����ԣ�ֻ��һ���﷨��ʽ
};
int main()
{
	//printf("%d", sizeof(struct S));//���4���ֽڣ�˵���ṹ�岻���������������ڴ�
	int i = 0;
	struct S* p = (struct S*)malloc(sizeof(struct S) + sizeof(int));
	for (i = 0; i < 10; i++)
	{
		p->arr[i] = i;
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d ", p->arr[i]);
	}
	free(p);
	p = NULL;
	return 0;
}//����������벻֪������ʲô�ط������⡭