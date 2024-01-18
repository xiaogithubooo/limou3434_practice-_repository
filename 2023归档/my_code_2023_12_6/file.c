#include "file.h"
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>

#define DFL_MOOE 0666

MyFILE* Myfopen(const char* path, const char* mode)
{
    int fd = 0;
    int flag = 0;
    if (strcmp(mode, "r") == 0)
    {
        flag |= O_RDONLY;
    }
    else if (strcmp(mode, "w") == 0)
    {
        flag |= (O_CREAT | O_TRUNC | O_WRONLY);
    }
    else if (strcmp(mode, "a") == 0)
    {
        flag |= (O_CREAT | O_WRONLY | O_APPEND);
    }
    else
    {
        //Do nothing
    }

    if (flag & O_CREAT)//创建文件
    {
        fd = open(path, flag, DFL_MOOE);
    }
    else
    {
        fd = open(path, flag);
    }

    if (fd < 0)
    {
        errno = 2;//设置错误（代表文件打开失败）
        return NULL;
    }

    MyFILE* fp = (MyFILE*)malloc(sizeof(MyFILE));
    if (!fp)
    {
        errno = 3;//设置错误（代表空间申请失败）
        return NULL;
    }

    fp->_flag = FLUSH_LINE;//默认行刷新
    fp->_end = 0;//默认缓冲区没有数据
    fp->_fileno = fd;//设置文件标识符

    return fp;
}

int Mywrite(const char* s, int num, MyFILE* stream)//num 是写入的字符个数
{
    //写入数据
    memcpy(stream->_buffer + stream->_end, s, num);
    stream->_end += num;
    
    //判断刷新
    if ((stream->_flag & FLUSH_LINE) 
    &&  (stream->_end > 0)
    &&  (stream->_buffer[stream->_end - 1] == '\n')
    )
    {
        Myfflush(stream);
    }
    return num;
}

int Myfflush(MyFILE* stream)
{
    if (stream->_end > 0)
    {
        write(stream->_fileno, stream->_buffer, stream->_end - 0);
        stream->_end = 0;
    }
    //fsync(stream->_fileno);//可选，我们之前都是对自己设计的语言级缓冲区进行刷新，这个系统调用是刷新内核级缓冲区的

    return 0;
}

int Myfclose(MyFILE* stream)
{
    Myfflush(stream);//先刷新，防止缓冲区内还有数据
    return close(stream->_fileno);
}