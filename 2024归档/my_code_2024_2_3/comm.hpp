//comm.hpp
#pragma once

#include <iostream>
#include <string>

#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstring>

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <fcntl.h>

#define PATH_NAME "/home/ljp" //路径名
#define MOOD 0666 //设置管道文件初始权限
#define PROJ_ID 0x666 //项目 ID（用于创建 key）
#define SHM_SIZE 4096 //共享内存大小

const std::string ipcPath = "./.fifo.ipc"; //管道文件路径（默认设置为隐藏文件）

using namespace std;

bool MakeFifo()
{
    if(mkfifo(ipcPath.c_str(), MOOD) < 0)
    {
        perror("mkfifo() wrong!");
        return false;
    }

    return true;
}
