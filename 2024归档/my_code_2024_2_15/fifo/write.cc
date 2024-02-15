#include <iostream>
#include <fcntl.h> 
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MOOD 0666 //设置管道文件初始权限
const char* path = "./fifo.ipc"; //设置管道文件所处地址

int main()
{
    mkfifo(path, MOOD);
    int fd = open(path, O_WRONLY); //只写打开
    char buffer[1024] = "i am process A";
    write(fd, buffer, sizeof(buffer));
    return 0;
}
