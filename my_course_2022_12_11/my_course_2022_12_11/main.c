#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//1、学习使用文件函数
//int main()
//{
//	//a、预备处理写入数据1
//	int a = 10000;
//	//b、尝试打开文件（只写），“写的时候”就会自己创建文件，将老的文件夹销毁替代，或者直接新建一个
//	FILE* pf = fopen("测试文件.txt", "wb");
//	//c、判断是否打开文件
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	//d、写文件（写入二进制文本）
//	fwrite(&a, 4, 1, pf);//解读，把a，一个元素（int）的大小，写一个就行，写到pf中
//	//d、关闭文件，并且置空文件指针pf
//	fclose(pf);
//	pf = NULL;
//	return 0;//e、小段存储了10 27 00 00 00，十六进制00 00 00 27 10转化为十进制即10000
//}
//r是在有文件的情况下“读取”数据
//w无论有或者无都会新建文件，覆盖
//a是在有文件的情况下“追加”数据

//2、标准输出流的用法
//键盘-标准输入设备-stdin
//屏幕-标准输出设备-stdout
//是一个程序默认打开的两个设备
//int main()
//{
//	int ch = fgetc(stdin);
//	fputc(ch, stdout);
//	return 0;
//}

//3、文本文档的读写，以及和puts的换行说明
//int main()
//{
//	char buf[1024] = { 0 };
//
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL)
//	{
//		printf("打开文件失败");
//		return 0;
//	}
//	//写文件}
//	fputs("hello ", pf);
//	fputs("world?", pf);
//	fclose(pf);
//	pf = NULL;
//
//	pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		printf("打开文件失败");
//		return 0;
//	}
//	//读文件，读出来传给数组buf
//	fgets(buf, 1024, pf);//如果加了\n就会自动换行，一起读取，但是puts本来就会换行，这是不一样的！
//	printf("%s", buf);
//
//
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}

//4、从键盘读取一行，输出到屏幕
//int main()
//{
//	char buf[1024] = { 0 };
//	fgets(buf, 1024, stdin);//从标准输入流读取
//	fputs(buf, stdout);//输出到标准输出流
//	//等价于以下的写法
//	gets(buf);
//	puts(buf);
//	return 0;
//}

//5、格式化输出，输入
//（1）输入
//struct S
//{
//	int n;
//	float score;
//	char arr[10];
//};
//
//int main()
//{
//	struct S s = { 100,3.14f,"bit" };
//	FILE* pf = fopen("test.txt", "w");//写的形式打开
//	if (pf == NULL)
//	{
//		printf("打开文件失败");
//		return 0;
//	}
//	fprintf(pf, " %d %f %s", s.n, s.score, s.arr);//格式化输入
//	return 0;
//}
//（2）输出
//struct S
//{
//	int n;
//	float score;
//	char arr[10];
//};
//
//int main()
//{
//	struct S s = { 0 };
//	FILE* pf = fopen("test.txt", "r");//写的形式打开
//	if (pf == NULL)
//	{
//		printf("打开文件失败");
//		return 0;
//	}
//	fscanf(pf, "%d %f %s", &(s.n), &(s.score), &(s.arr));//格式化输入
//	printf("%d %f %s\n", (s.n), (s.score), (s.arr));//仍然需要打印的！不是直接就行的…
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//6、屏幕和键盘流使用格式输出输入
//struct S
//{
//	int n;
//	float score;
//	char arr[10];
//};
//int main()
//{
//	struct S s = { 0 };
//
//	fscanf(stdin, "%d %f %s", &(s.n), &(s.score), &(s.arr));
//	fprintf(stdout, "%d %.2f %s", s.n, s.score, s.arr);
//	return 0;
//}

//7、对比三组函数的区别
//   scanf/fscanf/sscanf
//  printf/fprintf/sprintf
//（1）scanfhe和printf是针对“标准”输入流/标准输出流_的格式化输入/输出语句
//（2）fscanf和fprintf是针对“所有”输入流/标准输出流_的格式化输入/输出语句
//（3）sscnaf和sprintf就比scanf和printf的参数多了char*而已，前者字符串恢复回格式，后者格式变成字符串（从字符串中读取格式化数据，把格式化数据输出成字符串）
//struct S
//{
//	int n;
//	float score;
//	char arr[10];
//};
//int main()
//{
//	struct S s = { 100,3.14f,"abcdef" };//存放数据
//	struct S tmp = { 0 };
//	char buf[1024] = { 0 };
//	sprintf(buf, "%d %f %s", s.n, s.score, s.arr);//把格式化数据变成字符串存储到buf中
//	printf("%s\n", buf);
//
//	sscanf(buf,"%d %f %s", &(tmp.n), &(tmp.score), &(tmp.arr));//从buf中读取的字符串恢复成格式化的数据到tmp中
//	printf("%d %f %s\n", tmp.n, tmp.score, tmp.arr);
//	return 0;
//}

//8、随机读取文件
//int main()
//{
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		return 0;
//	}
//	//定位文件指针
//	//fgets(pf);//如果加上这一句就输出1的结果
//	fseek(pf, -2, SEEK_END);//如果加上这一句，从末尾开始读起，指向abcdef中的e，偏移量为4，若是屏蔽默认从开头读起，偏移量为0
//	int pos = ftell(pf);//计算偏移量，返回文件指针相对于起始位置的偏移量，上面的两句都不加的话，就输出0
//	printf("%d\n", pos);
//	rewind(pf);//文件指针恢复起始位置
//	pos = fgetc(pf);
//	printf("%c\n", pos);
//	fclose(pf);//关闭文件
//	pf = NULL;
//	return 0;
//}

//9、错误使用feof()
//int main()
//{
//	//误解为判断文件结束，
//	//【牢记，在读取文件的过程中，不能用feof函数的返回值直接用来判断文件是否结束，而是应用于文件读取结束的时候，判断是读取失败结束，还是遇到文件尾结束】
//	//【判断文本文件读取是否结束时候，fgetc判断是否为EOF，fgets为NULL】
//	//【判断二进制文件读取是否结束时候，fread判断返回值是否小于实际要读的个数】
//	FILE* pf = fopen("text.txt", "r");
//	if (pf == NULL)
//	{
//		return 0;
//	}
//	int ch = fgetc(pf);
//	printf("%d", ch);//应该打印EOF（文件结束标志），其真实值为-1
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//10、函数perror和strerror(errno)的区别
//int main()
//{
//	int c;
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		perror("hehe");//“hehe:错误码”，比strerror更加方便，而且还不需要引头文件，还具有一定的可读性（知道在哪个地方出错），更加直观好用
//		return 0;
//	}
//	//读文件
//	while ((c = fget(pf)) != EOF)
//	{
//		putchar(c);
//	}
//	if (ferror(pf))//判断是否读取失败
//	{
//		puts("I/O errror when reading");
//	}
//	else if (feof(pf))//判断为遇到文件结束
//	{
//		puts("End of file reached successfully");
//	}
//	fclose(pf);
//	return 0;
//}