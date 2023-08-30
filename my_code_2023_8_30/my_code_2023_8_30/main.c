#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void test_1()
{
	char a = 101;
	//101 = 0110 0101
	//0110 0101(原)
	//1001 1011(补)

	int sum = 200;
	//1100 1000(原)
	//0011 1000(补)

	a += 27;
	//a = 128，溢出了，变成-128

	sum += a;
	//200-128=72
	printf("%d\n", sum);
}
void test_2()
{
	int value = 1024;
	//0000 0000|0000 0000|0000 0100|0000 0000
	//小端
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
	//首先是一个数组，有10个元素，每个元素的类型是int*[30]，都是有30个int*元素的数组
	//10 * 30 * 8 = 300 * 8 = 2400
	printf("%zd\n", sizeof(k));//输出2400
}
void test_8()
{
	int a[3][4];//int[4] a [3]
	//*(&a[0][0] + 5)，取得第一个元素，然后过5个int元素到达a[1][1]
	//*(*(a+1) + 1)，a+1得到a[1]的指针，解引用得到a[1]，a[1]+1得到a[1][1]的指针，解引用得到a[1][1]
	//*(&a[1] + 1)，&a[1]得到a数组的a[1]指针，+1后得到a[2]的指针，因此解引用得到a[2]
	//*(a[1] + 1)，a[1]+1得到a[1]数组内第二个元素的指针，解引用得到a[1][1]

	//void(*s[5])(int)
	//首先s是一个数组，有5个元素，每个元素的类型是函数指针，函数指针的类型为void(*)(int)

	////0.f函数接受一个int**的参数
	//void f(int** p);
	////1.包含4个int的数组
	//int a[4] = { 1, 2, 3, 4 };
	////2.包含3个int[4]元素的数组
	//int b[3][4] = {
	//	{1,2,3,4},
	//	{5,6,7,8},
	//	{9,10,11,12}
	//};
	////3.包含3个int*元素的数组
	//int* q[3] = { b[0], b[1], b[2] };

	//char* p;
	//char s[] = "china";
	//p = s;
}
void test_9()
{
	static char* s[] = { "black", "white", "pink", "violet" };
	char** ptr[] = { s + 3, s + 2, s + 1, s };
	//               violet指针, pink指针, white指针, black指针
	char*** p;
	p = ptr;//p取得了ptr数组的第一个元素的指针
	++p;//加加这个指针，得到ptr第二个元素的指针
	printf("%s", **p + 1);//得到ink
}
void test_10()
{
	//char s[3][10];//是一个含有3个元素的数组，每个元素类型都是char[10]
	//char(*k)[3];//k是一个指针，指向一个数组，该数组含有3个char元素
	//char* p;//p是指针，指向char元素

	//p = s;//此时s类型为char(*)[10]
	//p = k;//此时k类型为char(*)[3]
	//p = s[0];//s[0]的类型为char[10]
	//k = s;//s的类型是chae(*)[10]
}
void test_11()
{
	//假设sizeof(void*) = 4，sizeof(char) = 1
	char str[sizeof("ab")];//得到大小为3
	size_t number = sizeof(str);//大小为3
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
	int(*p)[4] = (int(*)[4])m;//j将原本int*指针强制转化为int(*)[4]
	printf("%d", p[1][2]);//输出7
}
void test_15()
{
	char p1[15] = "abcd";
	char* p2 = "ABCD";
	char str[50] = "xyz";

	strcpy(str + 2, strcat(p1 + 2, p2 + 1));
	//str+2 = "\0"
	//后者为"cdBCD"
	printf("%s", str);//输出xycdBCD
}
char* f(char* str, char ch)//"abcdcccd"和'c'
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
	//arr是一个包含2个char[4]元素的数组
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
	union D//联合体
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