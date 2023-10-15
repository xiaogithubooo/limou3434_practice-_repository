//comm.hpp
#ifndef _COMM_H_
#define _COMM_H_

#include <iostream>
#include <string>
#include <cstdio>
#include <cassert>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <fcntl.h>

#define PATH_NAME "/home/ljp"
#define PROJ_ID 0x666
#define SHM_SIZE 4096
#define FIFO_NAME "./fifo"
#define READ O_RDONLY//只读

using namespace std;

class Init
{
    public:
    Init()
    {
        umask(0);
        int n = mkfifo(FIFO_NAME, 0666);//创建管道
        assert(n == 0);(void)n;
    }
    ~Init()
    {
        unlink(FIFO_NAME);
    }
};
Init init;//程序加载的时候自动构建全局变量，也就自动创建和销毁管道文件
int OpenFIFO(string pathname, int flags)
{
    int fd = open(pathname.c_str(), flags);
    assert(fd >= 0);
    return fd;
}
void Wait(int fd)
{
    uint32_t temp = 0;
    ssize_t s = read(fd, &temp, sizeof(uint32_t));
    assert(s == sizeof(uint32_t));
}
void Signal(int fd)
{
    uint32_t temp = 1;
    ssize_t s = write(fd, &temp, sizeof(uint32_t));
    assert(s == sizeof(uint32_t));(void)s;
}
#endif
