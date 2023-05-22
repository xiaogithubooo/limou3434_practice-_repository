#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//注意可能需要在x86环境下才能运行下面的代码
int main()
{
    int a[4] = { 1, 2, 3, 4 };
    int* ptr1 = (int*)(&a + 1);//这里指向数组元素4后面的地址
    int* ptr2 = (int*)((int)a + 1);//a本来是首元素地址，被强转为int后+1，因此指向的是小端模式中a数据的第二个字节数据
    printf("%x, %x\n", ptr1[-1], *ptr2);
    //因此这里打印4和2000000
    //之所以是2000000，是因为：
    //后者是从“小端模式中a数据的第二个字节数据”开始读取4个字节，
    //内存里小端模式的数据为“00 00 00 02”，
    //逆向输出字节序就是“20 00 00 00”
    return 0;
}
//struct Test
//{
//	int Num;
//	char* pcName;
//	short sDate;
//	char cha[2];
//	short sBa[4];
//}*p = (struct Test*)0x100000;//结构体大小为20字节
//int main()
//{
//	printf("%p\n", p + 0x1);//输出0x100014（加1相当于+20）
//	printf("%p\n", (unsigned long)p + 0x1);//输出0x100001（加1就是+1，因为这个强转不是强转为指针类型）
//	printf("%p\n", (unsigned int*)p + 0x1);//输出0x100004（加1相当于+4）
//}
//int main()
//{
//	int a = 0x11223344;
//	int* p = &a;
//	printf("%x\n", *(char*)p);
//	return 0;
//}
//void test_1(void)
//{
//	//演示最好使用整型，浮点数过于复杂以后再研究
//	int a = 0x11223344;
//	int* pa = &a;
//	char* q = pa;//加上(char*)的原因只是为了让编译器不报警也可以选择不加，不影响我们的结论
//	printf("%d\n", *q);//打印68，即0x44
//	printf("%d\n", a);//287454020，即0x11223344的十进制
//}
//void test_2(void)
//{
//	printf("%d\n", (int)'c');
//}
//int main()
//{
//	test_2();
//}