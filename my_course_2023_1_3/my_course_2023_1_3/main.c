#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//1���й���%g��%G���о�
int main()
{
	//ָ��>=6
	double a, b, c, d;
	double e, f, g, h;
	a = 12345678;
	b = 1234567;
	c = 123456;
	d = 12345;
	printf("��ָ��>=6����<-4��ʱ��%%g��%%G��ѡ�� %%e��%%E�����\n"
		   "���������������ѡ��%%f���\n\n");

	printf("ָ��>=6��ʱ��\n");
	printf("%%f\t\t  %%e\t\t  %%g\t\t  %%G\n");
	printf("%f\t  %e\t  %g\t  %G\n", a, a, a, a);
	printf("%f\t  %e\t  %g\t  %G\n", b, b, b, b);
	printf("%f\t  %e\t  %#g\t  %#G\n", c, c, c, c);
	printf("%f\t  %e\t  %#g\t  %#G\n", d, d, d, d);
	printf("\n");
	//ָ��<=-4
	e = 0.000001;
	f = 0.00001;
	g = 0.0001;
	h = 0.001;
	printf("ָ��<=-4��ʱ��\n");
	printf("%%f\t\t  %%e\t\t  %%g\t\t  %%G\n");
	printf("%f\t  %e\t  %g\t\t  %G\n", e, e, e, e);
	printf("%f\t  %e\t  %g\t\t  %G\n", f, f, f, f);
	printf("%f\t  %e\t  %#g\t  %#G\n", g, g, g, g);
	printf("%f\t  %e\t  %#g\t  %#G\n", h, h, h, h);
	return 0;
}

//2���й���ת��˵�������η�
int main()
{
	int a = 21;
	int a1 = -21;
	char* b = "abcdefg";
	//���ͺ��ַ���ʹ�á�.���֡����η�
	printf("%.20d\n", a);
	printf("%.4s\n", b);

	//�Ӻ�+���η���ʹ��
	printf("%+d  %+d\n", a, a1);

	//����-���η���ʹ��
	printf("*%-12d*\n", a);

	//ǰ���ո����η���ʹ��
	printf("% 10d  % 10d\n", a, a1);

	//ǰ�������η���ʹ��
	printf("%010d  %010d\n", a, a1);

	return 0;
}

//3����ָ��ʹ��%u�����ź���ֵ�ֿ�
int main()
{
	int a = -316;
	printf("%d\n", a);
	printf("%u\n", a);
	//���Կ���������������ף������ȫ�Ǻ���ֵ�ֵ
	return 0;
}

//4�����������Ĵ���������Ĵ洢��ջ����⣩
int main()
{
	float n1 = 3.0;
	float n2 = 3.0;
	long n3 = 2000000000;
	long n4 = 1234567890;
	printf("%ld %ld %ld %ld", n1, n2, n3, n4);
	return 0;
	//��ϵͳ����Ĵ��λ��ƺ���̫һ�����е�ϵͳ�ǵ������͵��ĸ�%ld���Ҳ�Ǵ���ġ���
}

//5����ӡ�ϳ����ַ������ַ���
int main()
{
	//��һ�ַ�����
	printf("abcdef");
	printf("ghijkl");
	printf("mnopqr\n");

	//�ڶ��ַ���
	printf("abcdef\
ghijkl\
mnopqr\n");

	//�����ַ���
	printf("abcdef"
		"ghijkl"
		"mnopqr");
	return 0;
}

int main()�������˵�����ܿ�ʵ�ʵĻ������ﵽ�Ķ����õ�Ч��
{
	printf("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
		aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
		aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
		aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
		aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
		aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
		aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
		aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
		aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
		aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
		aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
		aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
		aaaaaaaaaa");
	return 0;
}

//6��scanf�������÷�ϸ��
int main()
{
	int a = 0;
	scanf("%d", &a);//��������������123cb
	char b = '0';
	char c = '0';
	scanf("%c", &b);
	scanf("%c", &c);

	printf("%d %c %c", a, b, c);
	//���Կ���123���洢�����󣬷Ż���cb�����ַ���
	//����ʹ����һ�ε�scanf���Զ�������֮ǰ�������ַ�c��d
	return 0;
}

//7�������ֶε�scanf����
int main()
{
	int a = 0;
	char b[10];
	scanf("%5d", &a);
	printf("%d\n", a);//���Կ���ֻ�����ǰ�������
	getchar();
	getchar();
	scanf("%s", b);
	printf("%s", b);
	return 0;
	//����������л���հ׾ͻ�����ֹͣ��ȡ�����˵�һ��������ǿհ׵�����������º���������
}

//8��ʹ�����η�*���Զ����ֶΣ�printf�����������루scanf��
int main()
{
	float a = 123;
	int x = 0, y = 0, z = 0;
	scanf("%d %d", &x, &y);//��������8 2�Ϳ������Կ���Ч��
	printf("%*.*f\n", x, y, a);

	x = 0;
	y = 0; 
	z = 0;
	scanf("%*d %*d %d", &z);//�������������������
	printf("%d %d %d", x, y, z);
	return 0;
}

//9��printf()�ķ���ֵ
int main()
{
	int a = 12345, b = 0;
	b = printf("%d", a);
	printf("\n");
	printf("%d\n", b);

	int c = 0, d = 0;
	d = scanf("%d", &c);
	printf("%d",d);
	return 0;
}

//10��ţ������Ŀ
int main()
{
    double x = 0, y = 0;//������
    double r = 0;//Բ�뾶
    double a = 0;//�����εı߳�

    double Area = 0;//�洢���
    scanf("%lf%lf", &x, &y);
    scanf("%lf", &r);
    scanf("%lf", &a);

    printf("%.0lf\n%g\n%0.0lf\n", x * y, PI * (r * r), a * a);
    return 0;
}
