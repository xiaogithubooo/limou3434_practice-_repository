#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
typedef struct MyFILE//模拟FILE
{
	int fd;//文件描述符
	char buffer[1024];//缓冲区
	int end;//结尾
}MyFILE;
//可以看到文件的数据都在MyFILE里，因此所有的接口都需要使用MyFILE
MyFILE* MyFopen(const char* pathname, const char* mode)
{
	//1.检查参数都不为空
	assert(pathname);
	assert(mode);
	//2.对不同模式做不同的操作
	MyFILE* fp = NULL;
	if (strcmp(mode, "r") == 0)
	{

	}
	else if (strcmp(mode, "r+") == 0)
	{

	}
	else if (strcmp(mode, "w") == 0)
	{
		int fd = open(pathname, O_WRONLY | O_TRUNC | O_CREAT, 0666);//调用系统接口，写入之前先清空文件，不存在时需要创建
		if (fd >= 0)
		{
			fp = (MyFILE*)malloc(sizeof(MyFILE));
			memset(fp, 0, sizeof(MyFILE));
			fp->fd = fd;
		}
	}
	else if (strcmp(mode, "w+") == 0)
	{

	}
	else if (strcmp(mode, "a") == 0)
	{

	}
	else if (strcmp(mode, "a+") == 0)
	{

	}
	return fp;
}
void MyFputs(const char* message, MyFILE* fp)
{
	assert(message);
	assert(fp);

	strcpy(fp->buffer + fp->end, message);//注意这个函数是会自动添加'\0'的
	fp->end += strlen(message);//防止多次写入缓冲区被覆盖

	//if(fp->end)
}
void MyFflush(MyFILE* fp)
{
	assert(fp);
	if (fp->end != 0)
	{
		write(fp->fd, fp->buffer, fp->end);//实际上是写入到内核缓冲区里了，一般是内核会帮助我们刷新，但是我们也可以尝试使用syncfs()可以刷新数据到磁盘上
		syncfs(fp->fd);//刷新系统缓冲区到磁盘
		fp->end = 0;
	}
}
void MyFclose(MyFILE* fp)
{
	assert(fp);
	MyFflush(fp);//关掉文件之前先刷新一下缓冲区到文件里
	close(fp->fd);
	free(fp);
}
int main()
{
	MyFILE* fp = MyFopen("./limou.txt", "w");
	if (fp == NULL)
	{
		printf("open error\n");
		return 0;
	}
	MyFputs("hello!", fp);
	MyFputs("I am limou.", fp);
	MyFputs("This are words.", fp);
	MyFclose(fp);
}
