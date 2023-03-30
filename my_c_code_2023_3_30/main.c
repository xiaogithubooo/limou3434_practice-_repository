#include <stdio.h>
#include <stdlib.h>
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