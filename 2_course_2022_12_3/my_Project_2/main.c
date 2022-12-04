#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
//int main()
//{
//	printf("7\01277\012777\n");//由此可见\012和\n是一样的效果
//	printf("%d\n", strlen("c:\test\628\test.c"));
//	return 0;
//}

//int a = 0,b = 0;//1这是全局变量a，b
//void f()//2这是自定义函数
//{
//	int a = 5;
//	printf("%d,%d\n", a, b);//3这是局部变量，虽然前面有a的定义，但是全局变量和局部变量都有的情况下，优先使用局部变量的值，即a=5，打印出5。由于函数f()在main()中使用，b用的是局部变量b，所以b=5,这里容易错
//}
//int main()
//{
//	b = 5;//4同理这里的b全局变量和局部变量都有，优先使用局部变量的值，所以b=5
//	f();//5使用f()函数打印出5 0
//	printf("%d,%d\n", a, b);//6由于前面的局部变量a只在f()里面有作用，此时打印出来的a是全局变量，a=0，b依旧打印出局部变量
//	return 0;
//	//7总结：打印出5 5 0 5
//}

//int f(int n)
//{
//	static int m = 1;
//	//（1）static 修饰的静态局部变量只执行初始化一次，而且延长了局部变量的生命周期，直到程序运行结束以后才释放。
//	//（2）static 修饰全局变量的时候，这个全局变量只能在本文件中访问，不能在其它文件中访问，即便是 extern 外部声明也不可以。
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

////第七章11题
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

//12题
//int f(int n)
//{
//	if ((n % 3 != 0) && (n % 5 == 0))//不能被3整除但能被5整除
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
//			;//空语句什么也不做
//		}
//	}
//	return 0;
//}
//void print(int a[][3]); //2行3列，二维数组可以看成一个特殊的一维数组，只是它的每个元素又是一个一维数组
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
////题目12
//typedef struct Student
//{
//	char* name;
//	float chine;
//	float English;
//	float math;
//}grades;//成绩结构体
//float MAX(grades* x, float* y)//前者名字，后者总分
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
//		;//依旧是max的值和名字
//	}
//	printf("\n总分最大为%s", max_name);
//	return max;
//}
//int main()
//{
//	grades a[3] = { {"张三",80,68,81},{"李四",70,76,75},{"马五",78,87,56} };//结构体数组
//	float x = 0;//个人平均分
//	float y = 0;//语文平均分
//	float z = 0;//数学平均分
//	float j = 0;//英语平均分
//	int i = 0;//循环数
//	float b[3] = { 0 };//存储三人总分
//	printf("成绩\t语文\t        数学\t        英语\n");//输出表格
//	printf("姓名\n");
//	for (i = 0; i < 3; i++)
//	{
//		printf("%s\t%f\t%f\t%f\n", a[i].name,a[i].chine,a[i].math,a[i].English);
//	}
//	printf("\n");
//	for (i = 0; i < 3; i++)//输出个人平均分
//	{
//		x = (a[i].chine + a[i].math + a[i].English);
//		b[i] = x;//存储个人总分
//		printf("姓名：%s\t平均分：%f\n", a[i].name, x / 3);
//	}
//	printf("\n");
//
//	for (i = 0; i < 3; i++)//输出语文平均分
//	{
//		y += (a[i].chine);
//	}
//	y = y / 3;
//	printf("语文平均分：%f\n", y);
//	for (i = 0; i < 3; i++)//输出数学平均分
//	{
//		z += (a[i].math);
//	}
//	z = z / 3;
//	printf("数学平均分：%f\n", z);
//	for ( i = 0; i < 3; i++)//输出英语平均分
//	{
//		j += (a[i].English);
//	}
//	j = j / 3;
//	printf("英语平均分：%f\n", j);
//	printf("\n");
//
//	for (i = 0; i < 3; i++)
//	{
//		printf("%s的总分是%f\n", a[i].name, b[i]);
//	}
//	printf("%f", MAX(a, b));//传两个首元素地址过去，计算最大值，并且打印出最大值
//	return 0;
//}
