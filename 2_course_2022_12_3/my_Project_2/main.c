#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
//int main()
//{
//	printf("7\01277\012777\n");//�ɴ˿ɼ�\012��\n��һ����Ч��
//	printf("%d\n", strlen("c:\test\628\test.c"));
//	return 0;
//}

//int a = 0,b = 0;//1����ȫ�ֱ���a��b
//void f()//2�����Զ��庯��
//{
//	int a = 5;
//	printf("%d,%d\n", a, b);//3���Ǿֲ���������Ȼǰ����a�Ķ��壬����ȫ�ֱ����;ֲ��������е�����£�����ʹ�þֲ�������ֵ����a=5����ӡ��5�����ں���f()��main()��ʹ�ã�b�õ��Ǿֲ�����b������b=5,�������״�
//}
//int main()
//{
//	b = 5;//4ͬ�������bȫ�ֱ����;ֲ��������У�����ʹ�þֲ�������ֵ������b=5
//	f();//5ʹ��f()������ӡ��5 0
//	printf("%d,%d\n", a, b);//6����ǰ��ľֲ�����aֻ��f()���������ã���ʱ��ӡ������a��ȫ�ֱ�����a=0��b���ɴ�ӡ���ֲ�����
//	return 0;
//	//7�ܽ᣺��ӡ��5 5 0 5
//}

//int f(int n)
//{
//	static int m = 1;
//	//��1��static ���εľ�̬�ֲ�����ִֻ�г�ʼ��һ�Σ������ӳ��˾ֲ��������������ڣ�ֱ���������н����Ժ���ͷš�
//	//��2��static ����ȫ�ֱ�����ʱ�����ȫ�ֱ���ֻ���ڱ��ļ��з��ʣ������������ļ��з��ʣ������� extern �ⲿ����Ҳ�����ԡ�
//	m = m * n;
//	return m;
//}
//int main()
//{
//	int i; 
//	for (i = 1; i <= 5; i++)
//		printf("%d\t", f(i));
//	return 0;
//}

////������11��
//int f(int i)
//{
//	int m = 0;
//	i += m++;
//	return i;
//}
//int main()
//{
//	int i;
//	i = f(f(1));
//	printf("i=%d", i);
//	return 0;
//}

//12��
//int f(int n)
//{
//	if ((n % 3 != 0) && (n % 5 == 0))//���ܱ�3�������ܱ�5����
//	{
//		return n;
//	}
//	else
//	{
//		return -1;
//	}
//}
//int main(void)
//{
//	int y = 0;
//	for (int n = 1; n < 101; n++)
//	{
//		y = f(n);
//		if (y != -1)
//		{
//			printf("%d ", y);
//		}
//		else
//		{
//			;//�����ʲôҲ����
//		}
//	}
//	return 0;
//}
//void print(int a[][3]); //2��3�У���ά������Կ���һ�������һά���飬ֻ������ÿ��Ԫ������һ��һά����
//int main()
//{
//	int a[2][3];
//	int b[2][3] = { { 1, 2, 3 },{ 4, 5, 6 } };
//	int c[2][3] = { 1, 2, 3, 4, 5, 6 };
//	int d[2][3] = { 1,2,3,4 };
//	int e[2][3] = { {'\0'}, {4, 5, 6}};
//	int f[][3] = { { 1,2,3 }, { 4, 5, 6 } };
//	a[0][0] = 1;
//	a[0][1] = 2;
//	a[0][2] = 3;
//	a[1][0] = 4;
//	a[1][1] = 5;
//	a[1][2] = 6;
//	print(a);
//	print(b);
//	print(c);
//	print(d);
//	print(e);
//	print(f);
//}
//void print(int a[][3])
//{
//	int i, j;
//	for (i = 0; i < 2; ++i)
//	{
//		for (j = 0; j < 3; ++j)
//		{
//			printf("a[%d][%d]=%d\n", i, j, a[i][j]);
//		}
//	}
//	printf("\n");
//}
////��Ŀ12
//typedef struct Student
//{
//	char* name;
//	float chine;
//	float English;
//	float math;
//}grades;//�ɼ��ṹ��
//float MAX(grades* x, float* y)//ǰ�����֣������ܷ�
//{
//	int max=0;
//	char* max_name;
//	if (*y < *(y + 1))
//	{
//		max = *(y + 1);
//		max_name = (x + 1)->name;
//	}
//	else
//	{
//		max = *y;
//		max_name = x->name;
//	}
//	if (max < *(y + 2))
//	{
//		max = *(y + 2);
//		max_name = (x + 2)->name;
//	}
//	else
//	{
//		;//������max��ֵ������
//	}
//	printf("\n�ܷ����Ϊ%s", max_name);
//	return max;
//}
//int main()
//{
//	grades a[3] = { {"����",80,68,81},{"����",70,76,75},{"����",78,87,56} };//�ṹ������
//	float x = 0;//����ƽ����
//	float y = 0;//����ƽ����
//	float z = 0;//��ѧƽ����
//	float j = 0;//Ӣ��ƽ����
//	int i = 0;//ѭ����
//	float b[3] = { 0 };//�洢�����ܷ�
//	printf("�ɼ�\t����\t        ��ѧ\t        Ӣ��\n");//������
//	printf("����\n");
//	for (i = 0; i < 3; i++)
//	{
//		printf("%s\t%f\t%f\t%f\n", a[i].name,a[i].chine,a[i].math,a[i].English);
//	}
//	printf("\n");
//	for (i = 0; i < 3; i++)//�������ƽ����
//	{
//		x = (a[i].chine + a[i].math + a[i].English);
//		b[i] = x;//�洢�����ܷ�
//		printf("������%s\tƽ���֣�%f\n", a[i].name, x / 3);
//	}
//	printf("\n");
//
//	for (i = 0; i < 3; i++)//�������ƽ����
//	{
//		y += (a[i].chine);
//	}
//	y = y / 3;
//	printf("����ƽ���֣�%f\n", y);
//	for (i = 0; i < 3; i++)//�����ѧƽ����
//	{
//		z += (a[i].math);
//	}
//	z = z / 3;
//	printf("��ѧƽ���֣�%f\n", z);
//	for ( i = 0; i < 3; i++)//���Ӣ��ƽ����
//	{
//		j += (a[i].English);
//	}
//	j = j / 3;
//	printf("Ӣ��ƽ���֣�%f\n", j);
//	printf("\n");
//
//	for (i = 0; i < 3; i++)
//	{
//		printf("%s���ܷ���%f\n", a[i].name, b[i]);
//	}
//	printf("%f", MAX(a, b));//��������Ԫ�ص�ַ��ȥ���������ֵ�����Ҵ�ӡ�����ֵ
//	return 0;
//}
