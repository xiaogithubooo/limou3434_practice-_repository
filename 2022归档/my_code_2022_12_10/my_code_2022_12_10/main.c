#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>     
#include <string.h>
#include <stdlib.h>
////1、牛客网题目测试
//double S(double a, double b, double c)
//{
//    double p = ((a + b + c) / 2);
//    return sqrt(p*(p - a)*(p - b)*(p - c));
//}
//int main()
//{
//    double a, b, c;//边长
//    double s;//面积
//    scanf("%lf %lf %lf", &a, &b, &c);
//    s = S(a,b,c);//计算面积
//    printf("circumference=%.2lf area=%.2lf", a + b + c,s);
//    return 0;
//}//最后才发现是忘记三角形不等式定理a+b>c，输入了1、2、3是不存在三角形的…

////2、有关动态内存的题目（一）
//void GetMemory(char **p, int num)
//{
//	*p = (char *)malloc(num);//申请了100个字节的动态内存空间，并且把这块空间的首地址返回*p（即p），但是没有换回去
//}
//void Test(void)
//{
//	char* str = NULL;//先让指针置空
//	GetMemory(&str, 100);//调用GetMemory函数，使用了参数（指针的指针，100）
//	strcpy(str, "hello");//拷贝hello字符串到str中
//	printf(str);//打印str的结果
//}
//int main()
//{
//	Test();
//	return 0;
//}
////我的想法：应该没错的呀？只是内存泄露了……也会打印出hello的结果
////解析：就是这样的解法！！唯一的问题就是要释放动态内存
////修改后
//void GetMemory(char** p, int num)
//{
//	*p = (char*)malloc(num);//申请了100个字节的动态内存空间，并且把这块空间的首地址返回*p（即p），但是没有换回去
//}
//void Test(void)
//{
//	char* str = NULL;//先让指针置空
//	GetMemory(&str, 100);//调用GetMemory函数，使用了参数（指针的指针，100）
//	strcpy(str, "hello");//拷贝hello字符串到str中
//	printf(str);//打印str的结果
//
//	free(str);//还回去动态内存，并且置空
//	str = NULL;
//}
//int main()
//{
//	Test();
//	return 0;
//}

////3、有关动态内存的题目（二）
//void Test(void)
//{
//	char* str = (char*)malloc(100); //开辟了100个字节空间返回首地址给局部变量str
//	strcpy(str, "hello");//str接收后，又被追加拷贝了hello
//	free(str);//提前收回了内存空间，虽然值还在但如果继续访问会被覆盖位其他值
//	if (str != NULL)//非法访问了内存，另外，还有一个问题就是free不会自动NULL这个判断根本就是没有用的
//	{
//		strcpy(str, "world");//覆了原来的hello
//		printf(str);
//	}
//}
//int main()
//{
//	Test();//调用函数后
//	return 0;
//}
////修改后：
//void Test(void)
//{
//	char* str = (char*)malloc(100); //开辟了100个字节空间返回首地址给局部变量str
//	strcpy(str, "hello");//str接收后，又被追加拷贝了hello
//	free(str);//提前收回了内存空间，虽然值还在但如果继续访问会被覆盖位其他值
//	str = NULL;
//	if (str != NULL)//非法访问了内存
//	{
//		strcpy(str, "world");//覆了原来的hello
//		printf(str);
//	}
//}
//int main()
//{
//	Test();//调用函数后
//	return 0;
//}
////不要只调整free的位置，这样if的判断就不符合代码逻辑了…

////4、柔性数组的使用
////（1）不使用柔性数组
////a、创建结构体S
//struct S
//{
//	int n;
//	int* arr;//整型指针arr（形式有点像链表）
//};
//int main()
//{
////b、申请动态内存，该内存空间为一个结构体的大小，并且返回首地址给结构体指针ps
//	struct S* ps = (struct S*)malloc(sizeof(struct S));
////c、申请动态内存,该内存空间为5个整形大小的，并且返回首地址给结构体成员arr
//	ps->arr = malloc(5 * sizeof(int));
////d、使用申请的内存
//	int i = 0;
//	for (i = 0; i < 5; i++)
//	{
//		ps->arr[i] = i;//这里用数组的形式是不是意味着arr[i]和*(arr+i)真的是完全等价的？[]本身是无关数组的一种解引用方式？
//	}
//	for (i = 0; i < 5; i++)
//	{
//		printf("%d ", ps->arr[i]);
//	}
//	printf("\n");
////e、调整申请空间的大小
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
////f、释放动态内存（是有释放先后的问题的）
//	free(ps->arr);
//	ps->arr = NULL;
//	free(ps);
//	ps = NULL;
//	return 0;
//}
//（2）使用柔性数组
//struct S
//{
//	int n;
//	int arr[0];//仔细看的话就会发现和普通数组不同，普通数组[]里面是不可以为0的！
//};
//int main()
//{
//	struct S* ps = (struct S*)malloc(sizeof(struct S) + 5 * sizeof(int));
//	//后面的5*sizeof(int)是申请给柔性数组的…
//	//使用柔性数组的话就可以加快创建速度，还提高了阅读能力
//	return 0;
//}
////总结：
////（1）柔性数组可以写法更加简单；
////（2）柔性数组不需要解决多次释放内存的问题；
////（3）柔性数组和其他结构体成员是连续的，不会产生太多的内存碎片，提高内存利用率
////（4）连续情况下，访问效率更高
//但是柔性数组没有被流行起来，因为很多程序员都习惯了老写法

//5、柔性数组的深化
//在C99中，结构体最后一个成员允许是一个位置大小的数组，这个数组就是“柔性数组”成员，和“变长数组”的概念还是很有区别的
struct S
{
	int n;
	char c;
	int arr[];//这个就是柔性数组成员，这个在[]写不写0都可以，只是一种语法形式
};
int main()
{
	//printf("%d", sizeof(struct S));//输出4个字节，说明结构体不包括柔性数组大的内存
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
}//但是这个代码不知道还有什么地方有问题…