#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void test_1()
{
	char a = 101;
	//101 = 0110 0101
	//0110 0101(ԭ)
	//1001 1011(��)

	int sum = 200;
	//1100 1000(ԭ)
	//0011 1000(��)

	a += 27;
	//a = 128������ˣ����-128

	sum += a;
	//200-128=72
	printf("%d\n", sum);
}
void test_2()
{
	int value = 1024;
	//0000 0000|0000 0000|0000 0100|0000 0000
	//С��
	char condition = *((char*)(&value));//0
	if (condition)
		value += 1;

	condition = *((char*)(&value));

	if (condition) 
		value += 1;

	condition = *((char*)(&value));
	printf("%d %d", value, condition);
}
void test_3(char para[100])
{
	void* p = malloc(100);
	printf("%zd, %zd\n", sizeof(para), sizeof(p));//4/8,4/8
}
void func(char* p) 
{ 
	p = p + 1; 
}
void test_4()
{
	char s[] = { '1', '2', '3', '4' };
	func(s);
	printf("%c", *s);//1
}
void test_5(int arr1[][8], int(*arr2)[8])
{
	;
}
void funx(char** p)
{
	int i;
	for (i = 0; i < 4; i++)
		printf("%s", p[i]);
}
void test_6()
{
	char* s[6] = { "ABCD", "EFGH", "IJKL", "MNOP", "QRST", "UVWX" };
	funx(s);
	printf("\n");
}
void test_7()
{
	int* k[10][30];
	//������һ�����飬��10��Ԫ�أ�ÿ��Ԫ�ص�������int*[30]��������30��int*Ԫ�ص�����
	//10 * 30 * 8 = 300 * 8 = 2400
	printf("%zd\n", sizeof(k));//���2400
}
void test_8()
{
	int a[3][4];//int[4] a [3]
	//*(&a[0][0] + 5)��ȡ�õ�һ��Ԫ�أ�Ȼ���5��intԪ�ص���a[1][1]
	//*(*(a+1) + 1)��a+1�õ�a[1]��ָ�룬�����õõ�a[1]��a[1]+1�õ�a[1][1]��ָ�룬�����õõ�a[1][1]
	//*(&a[1] + 1)��&a[1]�õ�a�����a[1]ָ�룬+1��õ�a[2]��ָ�룬��˽����õõ�a[2]
	//*(a[1] + 1)��a[1]+1�õ�a[1]�����ڵڶ���Ԫ�ص�ָ�룬�����õõ�a[1][1]

	//void(*s[5])(int)
	//����s��һ�����飬��5��Ԫ�أ�ÿ��Ԫ�ص������Ǻ���ָ�룬����ָ�������Ϊvoid(*)(int)

	////0.f��������һ��int**�Ĳ���
	//void f(int** p);
	////1.����4��int������
	//int a[4] = { 1, 2, 3, 4 };
	////2.����3��int[4]Ԫ�ص�����
	//int b[3][4] = {
	//	{1,2,3,4},
	//	{5,6,7,8},
	//	{9,10,11,12}
	//};
	////3.����3��int*Ԫ�ص�����
	//int* q[3] = { b[0], b[1], b[2] };

	//char* p;
	//char s[] = "china";
	//p = s;
}
void test_9()
{
	static char* s[] = { "black", "white", "pink", "violet" };
	char** ptr[] = { s + 3, s + 2, s + 1, s };
	//               violetָ��, pinkָ��, whiteָ��, blackָ��
	char*** p;
	p = ptr;//pȡ����ptr����ĵ�һ��Ԫ�ص�ָ��
	++p;//�Ӽ����ָ�룬�õ�ptr�ڶ���Ԫ�ص�ָ��
	printf("%s", **p + 1);//�õ�ink
}
void test_10()
{
	//char s[3][10];//��һ������3��Ԫ�ص����飬ÿ��Ԫ�����Ͷ���char[10]
	//char(*k)[3];//k��һ��ָ�룬ָ��һ�����飬�����麬��3��charԪ��
	//char* p;//p��ָ�룬ָ��charԪ��

	//p = s;//��ʱs����Ϊchar(*)[10]
	//p = k;//��ʱk����Ϊchar(*)[3]
	//p = s[0];//s[0]������Ϊchar[10]
	//k = s;//s��������chae(*)[10]
}
void test_11()
{
	//����sizeof(void*) = 4��sizeof(char) = 1
	char str[sizeof("ab")];//�õ���СΪ3
	size_t number = sizeof(str);//��СΪ3
	printf("%zd", number);
}
char fun(char*);
void test_12()
{
	char* s = "one";
	char a[5] = { 0 };
	char(*f1)(char*) = fun;
	char ch;

	//*f1(&a)
	//f1(*s)
}
char fun(char* x)
{
	return 0;
}
void test_13()
{
	char* str[3] = { "stra", "strb", "strc" };
	char* p = str[0];
	int i = 0;
	while (i < 3)
	{
		printf("%s ", p++);//stra tra ra
		i++;
	}
}
void test_14()
{
	int m[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	int(*p)[4] = (int(*)[4])m;//j��ԭ��int*ָ��ǿ��ת��Ϊint(*)[4]
	printf("%d", p[1][2]);//���7
}
void test_15()
{
	char p1[15] = "abcd";
	char* p2 = "ABCD";
	char str[50] = "xyz";

	strcpy(str + 2, strcat(p1 + 2, p2 + 1));
	//str+2 = "\0"
	//����Ϊ"cdBCD"
	printf("%s", str);//���xycdBCD
}
char* f(char* str, char ch)//"abcdcccd"��'c'
{
	char* it1 = str;
	char* it2 = str;
	while (*it2 != '\0')
		//abddcccd
		//abcdcccd
	{
		while (*it2 == ch)
		{
			it2++;
		} 
		*it1++ = *it2++;
	} 
	return str;
}
void test_16()
{
	char a[10];
	strcpy(a, "abcdcccd");
	//a b c d c c c d \0 ?
	printf("%s", f(a, 'c'));
}
void test_17()
{
	char arr[2][4];
	//arr��һ������2��char[4]Ԫ�ص�����
	//y o u & m e \0
	strcpy(arr[0], "you");
	strcpy(arr[1], "me");
	arr[0][3] = '&';
	printf("%s \n", arr);
}
void test_18()
{
	struct st
	{
		int* p;
		int i;
		char a;
	};
	int sz = sizeof(struct st);
	printf("%d\n", sz);
}
void test_19()
{
	enum weekday
	{
		sun,//0
		mon = 3,//3
		tue,//4
		wed//5
	};
	enum weekday workday;
	workday = wed;
	printf("%d\n", workday);
	workday = sun;
	printf("%d\n", workday);
}
void test_20()
{
	union D//������
	{
		int d1;
		float d2;
	}d;
	d.d2 = 10;
	printf("%f", d.d1);
}
int main()
{
	//test_1();
	//test_2();/
	//char para[100];
	//test_3(para);
	//test_4();
	//test_6();
	//test_7();
	//test_9();
	//test_10();
	//test_11();
	//test_13();
	//test_14();
	//test_15();
	//test_16();
	//int x = 0, y = 0;
	//(x * y)++;
	//test_17();
	//test_18();
	//test_19();
	test_20();
	return 0;
}