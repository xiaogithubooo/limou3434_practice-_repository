#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	printf("%s\n", __FILE__);   //���б����Դ�ļ�����
	printf("%d\n", __LINE__);   //��ʾ�ļ���ǰ���к�
	printf("%s\n", __DATE__);   //�ļ������������
	printf("%s\n", __TIME__);   //�ļ��������ʱ��
	//printf("%d\n", __STDC__);        //����������ϸ���ѭANSI C����ֵΪ1������δ����

	printf("%s\n", __FUNCDNAME__);
	printf("%s\n", __FUNCTION__);
	return 0;
}

void function(int a);//�ú���ֻ�����������Ǹ��趨��
int main()
{
	function(2);
	printf("hello\n");
	return 0;
}
#include <stdio.h>
#define ADD(X, Y) \
((X) + (Y))
int main()
{
	printf("%d", ADD(2, 3));
	return 0;
}
#include <stdio.h>
#define PRINTF(num, format)\
		printf("The value of "#num" is "format, num)
int main()
{
	int a = 100;
	char b = 'c';
	double c = 3.14;
	PRINTF(a, "%d\n");
	PRINTF(b, "%c\n");
	PRINTF(c, "%f\n");
	return 0;
}
#include <stdio.h>
#define FUN(X, Y) X##Y
int main()
{
	int XY = 10;
	printf("%d\n", FUN(X, Y));//���ɿ��Դ�ӡ��10��X��Y��FUN����Ϊһ���ַ����ˣ�����������Ϊ������
	return 0;
}
#include <stdio.h>
#define MAX(X, Y) ((X)>(Y)?(X):(Y))
int main()
{
	int a = 3;
	int b = 5;
	int c = MAX(a++, b++);
	((a++)>(b++)?(a++):(b++))�����ּӼ����ε������ʹ�������׺���
	printf("%d\n", c);//6
	printf("%d\n", a);//4
	printf("%d\n", b);//7
	return 0;
}
