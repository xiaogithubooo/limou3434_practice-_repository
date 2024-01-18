#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <errno.h>
int main()
{
    //打开文件
    FILE* pf = fopen("C:\\Users\\DELL\\Desktop\\limou_cache_file_1.txt", "r+");
    if (pf == NULL)
    {
        perror("fopen失败!\n");
        return 1;
    }

    //写入文件
    fputs("hello_limou_welcome_file!", pf);

    //关闭文件
    fclose(pf);
    pf = NULL;
    return 0;
}
#include <stdio.h>
#include <errno.h>
int main()
{
    //打开文件
    FILE* pf = fopen("C:\\Users\\DELL\\Desktop\\limou_cache_file_1.txt", "r+");
    if (pf == NULL)
    {
        perror("fopen失败!\n");
        return 1;
    }

    //写入文件
    char arr[150];
    for (int i = 0; i < 10; i++)
    {
        fgets(arr, 150, pf);
        printf("%s\n", arr);
    }

    //关闭文件
    fclose(pf);
    pf = NULL;
    return 0;
}
int main()
{
	char* arr[10] = { 1 };
	return 0;
}
#include <stdio.h>
int main()
{
	typedef struct S
	{
		int a;
		double b;
		char c[10];
	}S;
	S s = { 0 };
	//打开文件
	FILE* pf = fopen("C:\\Users\\DELL\\Desktop\\limou_cache_file_1.txt", "r+");
	if (pf == NULL)
	{
		perror("fopen失败!\n");
		return 1;
	}

	//读文件
	fscanf(pf, "%d %lf %s", &(s.a), &(s.b), &(s.c));

	//打印到屏幕上
	printf("%d %lf %s", s.a, s.b, s.c);

	//关闭文件
	fclose(pf);
	pf = NULL;
	return 0;
}
#include <stdio.h>
typedef struct S
{
	int a;
	double b;
	char c[10];
}S;
int main()
{
	struct S s = { 200,3.14f,"limou3434" };
	char arr[200] = { 0 };
	sprintf(arr, "%d % f %s", s.a, s.b, s.c);
	printf("%s", arr);
	return 0;
}

//有关初始化的一个纠正
#include <stdio.h>
int main()
{
	//int* a;
	//*a = 5;//失败了
	//printf("%d", *a);

	int b;
	b = 5;
	printf("%d", b);//成功了
	return 0;
}

#include <stdio.h>
typedef struct S
{
	int a;
	double b;
	char c[10];
}S;
int main()
{
	S s1 = { 200,3.14f,"limou3434" };

	//转化为字符串数据
	char arr[200] = { 0 };
	sprintf(arr, "%d %lf %s\n", s1.a, s1.b, s1.c);
	printf("%s", arr);

	//转化为格式化数据
	S s2 = { 0 };
	sscanf(arr, "%d %lf %s", &(s2.a), &(s2.b), s2.c);
	printf("%d %lf %s\n", s2.a, s2.b, s2.c);
	return 0;
}
#include <stdio.h>
typedef struct S
{
	int a;
	double b;
	char arr[10];
}S;
int main()
{
	//输入数据
	S s1 = { 3, 3.14, "abcde" };
	FILE* pf = fopen("limou_txt", "wb");
	if (pf == NULL)
	{
		perror("fopen");
		return 1;
	}
	fwrite(&s1, sizeof(S), 1, pf);
	//关闭文件
	fclose(pf);
	pf = NULL;

	//输出数据
	S s2 = { 0 };
	pf = fopen("limou_txt", "rb");
	if (pf == NULL)
	{
		perror("fopen");
		return 1;
	}
	fread(&s2, sizeof(S), 1, pf);
	printf("%d %f %s\n", s2.a, s2.b, s2.arr);

	//关闭文件
	fclose(pf);
	pf = NULL;
	return 0;
//}
#include <stdio.h>
int main()
{
	//输入数据
	FILE* pf = fopen("limou.txt", "r");//文件指针指向a的地址
	if (pf == NULL)
	{
		perror("fopen");
		return 1;
	}
	//顺序读写
	int ch = fgetc(pf);
	printf("%c", ch);//打印a，读完后文件指针指向b
	ch = fgetc(pf);
	printf("%c", ch);//打印b，读完后文件指针指向c
	ch = fgetc(pf);
	printf("%c", ch);//打印c，读完后文件指针指向d
	ch = fgetc(pf);
	printf("%c", ch);//打印d，读完后文件指针指向e

	//改变偏移量读写
	fseek(pf, -3, SEEK_CUR);
	ch = fgetc(pf);
	printf("%c", ch);

	//继续顺序读写
	ch = fgetc(pf);
	printf("%c\n", ch);//打印d，读完后文件指针指向e

	//返回偏移量
	long int a = ftell(pf);
	printf("%d\n", a);

	//修改文件指针为开头
	rewind(pf);
	
	//再次返回偏移量
	a = ftell(pf);
	printf("%d\n", a);

	//关闭文件
	fclose(pf);
	pf = NULL;
	return 0;
}
#include <stdio.h>
int main()
{
    //输入数据
    FILE* pf = fopen("limou.txt", "r");//文件指针指向a的地址
    if (pf == NULL)
    {
        perror("fopen");
        return 1;
    }
    //顺序读写
    int ch = fgetc(pf);
    printf("%c", ch);//打印a，读完后文件指针指向b
    ch = fgetc(pf);
    printf("%c", ch);//打印b，读完后文件指针指向c
    ch = fgetc(pf);
    printf("%c", ch);//打印c，读完后文件指针指向d
    ch = fgetc(pf);
    printf("%c", ch);//打印d，读完后文件指针指向e

    //改变偏移量读写
    fseek(pf, -3, SEEK_CUR);
    ch = fgetc(pf);
    printf("%c", ch);

    //继续顺序读写
    ch = fgetc(pf);
    printf("%c\n", ch);//打印d，读完后文件指针指向e

    //返回偏移量
    long int a = ftell(pf);
    printf("%d\n", a);

    //关闭文件
    fclose(pf);
    pf = NULL;
    return 0;
}
#include <stdio.h>
int main()
{
    //输入数据
    FILE* pf = fopen("limou.txt", "r");//文件指针指向a的地址
    if (pf == NULL)
    {
        perror("fopen");
        return 1;
    }
    //顺序读写
    int ch = fgetc(pf);
    printf("%c", ch);//打印a，读完后文件指针指向b
    ch = fgetc(pf);
    printf("%c", ch);//打印b，读完后文件指针指向c
    ch = fgetc(pf);
    printf("%c", ch);//打印c，读完后文件指针指向d
    ch = fgetc(pf);
    printf("%c", ch);//打印d，读完后文件指针指向e

    //改变偏移量读写
    fseek(pf, -3, SEEK_CUR);
    ch = fgetc(pf);
    printf("%c", ch);

    //关闭文件
    fclose(pf);
    pf = NULL;
    return 0;
}
#include <stdio.h>
int main()
{
	输入数据
    FILE* pf = fopen("limou.txt", "r");//文件指针指向a的地址
    if (pf == NULL)
    {
        perror("fopen");
        return 1;
    }
    int ch = 0;
    while ((ch = fgetc(pf)) != EOF)
    {
        printf("%c", ch);
    }
    通过feof函数来判断是不是遇到文件末尾结束的
    if (feof(pf))
    {
        printf("到文件结尾\n");
    }
    else if (ferror(pf))
    {
        printf("文件读取错误\n");
    }
    关闭文件
    fclose(pf);
    pf = NULL;
	return 0;
}