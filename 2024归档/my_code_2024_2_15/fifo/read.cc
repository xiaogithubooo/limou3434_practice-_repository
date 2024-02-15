#include <iostream>
#include <fcntl.h> 
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

const char* path = "./fifo.ipc"; //设置管道文件所处地址

int main()
{
    int fd = open(path, O_RDONLY); //只读打开
    char buffer[1024] = { 0 };
    read(fd, buffer, sizeof(buffer));
    std::cout << buffer << std::endl;
    return 0;
}
