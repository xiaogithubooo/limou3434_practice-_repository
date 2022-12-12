#define _CRT_SECURE_NO_WARNINGS 1
#pragma   warning(disable:6067)//忽略fprintf的警告
#include<windows.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//编译的部分解释

//1、编译的文件变化
//运行前只有：
//my_course_2022_12_11文件夹(包括.c和.vcxproj和.vcxproj.filters和.vcxproj.user)
//my_course_2022_12_11.sln
//int main()
//{
//	printf("abcdef");
//	return 0;
//}
//执行后就多了：
//x64文件夹（包括Debug（包括.exe和.pdb））

//2、编译时间
//int main()
//{
//	printf("%s\n", __TIME__);//可以写日志，这个显示的是编译时间
//	return 0;
//}

//3、日志的使用（使用预定义符号）
//int main()
//{
//	int i = 0;
//	int arr[10] = { 0 };
//	FILE* pf = fopen("日志.txt", "w");//日志文件
//	for (i = 0; i < 10; i++)
//	{
//		arr[i] = i;
//		fprintf(pf,"file:%s line:%d date:%s time:%s i=%d\n", __FILE__, __LINE__, __DATE__, __TIME__, i);
//	}//在这里使用的时候，忽略了一个问题%s什么的中间多了空格，导致各种失败…
//	printf("%s", __FUNCTION__);//可以打印出函数的名字
//	fclose(pf);
//	pf = NULL;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//4、测试是否满足__STDC__
//int main()
//{
//	printf("%d",__STDC__);//是没有的，这也大概说明VS环境编译器没有支持所有的“C标”，最多满足了95%左右，并没有严格按照标准，gcc则更加严格可靠99%，甚至100%的可能实现了“C标”
//	return 0;
//}

//5、解决宏不能替换字符串的问题（#和##）
//（1）#的使用
//#define PRINTF(X) printf("the value of "#X" is %d\n",X);//这里的#X只会变成字符串"a"，然后三串字符串合为一个字符串
//int main()
//{
//	int a = 10, b = 20;
//	PRINTF(a);
//	PRINTF(b);
//	return 0;
//}//尽管用的不频繁，但是有时候底层工具里的代码还是能见到的
//（2）##的使用
//#define CAT(X,Y) X##Y
//int main()
//{
//	int Class84 = 2019;
//	printf("%d\n", CAT(Class, 84));//可以看到##可以把两个字符粘合在一起，等价于直接写Class2019
//	return 0;
//}

//6、副作用的讲解（副作用结合宏得危险行为）
//x+1;//没有副作用
//++a;//有副作用
//#define MAX(X,Y) (X)>(Y)?(X):(Y)
//int main()
//{
//	int a = 10, b = 11;
//	int max = 0;
//	max=MAX(a++, b++);//带有副作用的宏传参，这是很危险的行为的！！！
//	printf("%d\n", max);
//	printf("%d\n", a);
//	printf("%d\n", b);
//	return 0;
//}
//因为不会计算好再传过去，而是全部替换在做计算，这样的话运算符有顺序，
//结果会变得复杂起来，a、b会被连续改变…导致不是预期得结果，容易把控不了

////7、宏和函数得对比
//#define MAX(X,Y) (X)>(Y)?(X):(Y)
//int Max(int x, int y)
//{
//	return (x > y ? x : y);
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int max = Max(a, b);
//	printf("%d\n", max);
//	max = MAX(a, b);
//	printf("%d\n", max);
//	return 0;
//}
//从用参上会发现，宏会更加普遍（例如放入float类型的变量）
//并且函数在调用的时候会有函数调用和返回的开销，对比宏还需要用到很多时间
//（在汇编之中就可以看出）执行简单的运算，比如两个数找最大，建议用宏
//原因有二：
//（1）用于调用函数和从函数返回的代码比实际执行这个小型计算工作所需要的时间多。
//所以宏比函数在程序的规模和速度更胜一筹
//（2）更为重要的是，函数的参数必须声明特定的类型。所以函数只能在类型合适的表达式上使用。
//反之这个宏可适用于整形、长整型、浮点型等可用>来比较的类型，宏是类型无关的！

//宏的缺点：
//（1）每次使用宏的时候，一份宏定义的代码将插入到程序之中。
//除非宏比较短，否则可能大幅度增加代码长度（不断的插入）
//（2）宏是没有办法进行调试的！这一点就足以让宏被函数横扫。
//眼睛看见的代码和调试的代码会产生误差，无法检测调试
//（3）由于没有参数，不做类型检查，不够严谨
//（4）宏的使用有可能带来运算符优先级的问题，导致程序容易出错（以及副作用的问题）

//8、宏也有函数绝对做不到的事情
//#define SIZEOF(type) sizeof(type)
//int main()
//{
//	int ret = SIZEOF(int);//与int ret = sizeof(int);语句等价，传值传了个类型都可以，函数不行！
//	printf("%d\n", ret);
//	return 0;
//}

//9、优化malloc函数使用
//（1）普通使用malloc的用法
//int main()
//{
//	int* p = (int*)malloc(10 * sizeof(int));
//	return 0;
//}
//（2）利用宏来优化malloc函数
//#define MALLOC(num,type) (type*)malloc(num*sizeof(type)) 
//int main()
//{
//	int* p = MALLOC(10, int);//这样就会比较简单，并且不用强制转化了（因为前面已经在宏里面转化过了）
//	return 0;
//}

//10、条件编译的使用
//#define DEBUG =1
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,0 };
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		arr[i] = 0;
//#ifdef DEBUG;//如果DEBUG被定义过，那这条语句就参与，否则就不参与编译（删掉可惜，保留碍事）
//		printf("%d ", arr[i]);
//#endif
//	}
//	return 0;
//}

//11、多分支条件指令
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,0 };
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		arr[i] = 0;
//#if 0//(如果为真则执行，假则不执行，可以写一个式子进去)
//		printf("%d ", arr[i]);
//#elif 0
//		printf("你好！\n");
//#else
//		printf("heihei\n");//可以用多分支条件指令来判断是否编译
//#endif
//	}
//	return 0;
//}

//12、判断是否被定义的条件指令
//#define DEBUG 0
//int main()
//{
//#if defined(DEBUG)
//	//判断DEUBG是否被定义，没被定义就不执行，定义了就会被执行，哪怕值为假（0）
//	printf("hehe\n");
//#endif
//
//#ifdef DEBUG
//	//上面的写法等价于这种写法
//	printf("jiejie\n");
//#endif
//
//#if !defined(DEBUG)
//	//判断DEUBG是否不被定义，被定义就不执行，没定义就会被执行
//	printf("heihe");
//#endif
//
////#!ifdef DEBUG  //不能这么写
////	printf("haha\n");
////#endif
//
//#ifndef DEBUG  //但是可以这么写
//	printf("haha\n");
//#endif
//	return 0;
//}

//13、嵌套指令（可以用上述指令进行嵌套）

//14、解决头文件被反复引用
////可以在头文件里面写
//（1）古老写法一：
//#ifndef __TEST_H__
//#define __TEST_H__
//int Add(int x, int y);
//#endif
//（2）现代写法二：
//#pragma once
//int Add(int x, int y);