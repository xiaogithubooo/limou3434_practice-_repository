#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//1、有关于%g和%G的研究
int main()
{
	//指数>=6
	double a, b, c, d;
	double e, f, g, h;
	a = 12345678;
	b = 1234567;
	c = 123456;
	d = 12345;
	printf("①指数>=6或者<-4的时候：%%g（%%G）选择 %%e（%%E）输出\n"
		   "②其余情况：都是选择%%f输出\n\n");

	printf("指数>=6的时候\n");
	printf("%%f\t\t  %%e\t\t  %%g\t\t  %%G\n");
	printf("%f\t  %e\t  %g\t  %G\n", a, a, a, a);
	printf("%f\t  %e\t  %g\t  %G\n", b, b, b, b);
	printf("%f\t  %e\t  %#g\t  %#G\n", c, c, c, c);
	printf("%f\t  %e\t  %#g\t  %#G\n", d, d, d, d);
	printf("\n");
	//指数<=-4
	e = 0.000001;
	f = 0.00001;
	g = 0.0001;
	h = 0.001;
	printf("指数<=-4的时候\n");
	printf("%%f\t\t  %%e\t\t  %%g\t\t  %%G\n");
	printf("%f\t  %e\t  %g\t\t  %G\n", e, e, e, e);
	printf("%f\t  %e\t  %g\t\t  %G\n", f, f, f, f);
	printf("%f\t  %e\t  %#g\t  %#G\n", g, g, g, g);
	printf("%f\t  %e\t  %#g\t  %#G\n", h, h, h, h);
	return 0;
}

//2、有关于转换说明的修饰符
int main()
{
	int a = 21;
	int a1 = -21;
	char* b = "abcdefg";
	//整型和字符串使用“.数字”修饰符
	printf("%.20d\n", a);
	printf("%.4s\n", b);

	//加号+修饰符的使用
	printf("%+d  %+d\n", a, a1);

	//减号-修饰符的使用
	printf("*%-12d*\n", a);

	//前导空格修饰符的使用
	printf("% 10d  % 10d\n", a, a1);

	//前导零修饰符的使用
	printf("%010d  %010d\n", a, a1);

	return 0;
}

//3、别指望使用%u将符号和数值分开
int main()
{
	int a = -316;
	printf("%d\n", a);
	printf("%u\n", a);
	//可以看出这样做错的离谱，输出完全是很奇怪的值
	return 0;
}

//4、函数参数的传递与参数的存储（栈的理解）
int main()
{
	float n1 = 3.0;
	float n2 = 3.0;
	long n3 = 2000000000;
	long n4 = 1234567890;
	printf("%ld %ld %ld %ld", n1, n2, n3, n4);
	return 0;
	//本系统这里的传参机制好像不太一样，有的系统是第三个和第四个%ld输出也是错误的……
}

//5、打印较长的字符串三种方法
int main()
{
	//第一种方法：
	printf("abcdef");
	printf("ghijkl");
	printf("mnopqr\n");

	//第二种方法
	printf("abcdef\
ghijkl\
mnopqr\n");

	//第三种方法
	printf("abcdef"
		"ghijkl"
		"mnopqr");
	return 0;
}

int main()这个例子说明不能靠实际的换行来达到阅读更好的效果
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

//6、scanf函数的用法细节
int main()
{
	int a = 0;
	scanf("%d", &a);//尝试在这里输入123cb
	char b = '0';
	char c = '0';
	scanf("%c", &b);
	scanf("%c", &c);

	printf("%d %c %c", a, b, c);
	//可以看到123被存储起来后，放回了cb两个字符，
	//并且使用下一次的scanf后自动输入了之前丢弃的字符c和d
	return 0;
}

//7、限制字段的scanf函数
int main()
{
	int a = 0;
	char b[10];
	scanf("%5d", &a);
	printf("%d\n", a);//可以看到只输出了前五个数字
	getchar();
	getchar();
	scanf("%s", b);
	printf("%s", b);
	return 0;
	//如果在数字中混入空白就会立刻停止读取（除了第一个输入就是空白的情况），哪怕后面有数字
}

//8、使用修饰符*来自定义字段（printf）和跳过输入（scanf）
int main()
{
	float a = 123;
	int x = 0, y = 0, z = 0;
	scanf("%d %d", &x, &y);//比如输入8 2就可以明显看到效果
	printf("%*.*f\n", x, y, a);

	x = 0;
	y = 0; 
	z = 0;
	scanf("%*d %*d %d", &z);//很明显这里跳过输出了
	printf("%d %d %d", x, y, z);
	return 0;
}

//9、printf()的返回值
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

//10、牛课网题目
int main()
{
    double x = 0, y = 0;//正方形
    double r = 0;//圆半径
    double a = 0;//正方形的边长

    double Area = 0;//存储面积
    scanf("%lf%lf", &x, &y);
    scanf("%lf", &r);
    scanf("%lf", &a);

    printf("%.0lf\n%g\n%0.0lf\n", x * y, PI * (r * r), a * a);
    return 0;
}
