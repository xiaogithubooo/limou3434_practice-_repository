//comm.hpp(封装代码)
#pragma once

#include <iostream>
#include <string>

#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <cstdlib>

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/msg.h>

#define PATH_NAME "/home/ljp" //路径名
#define PROJ_ID 0x666 //项目 ID（用于创建 key）
#define SHM_SIZE 4096 //共享内存大小

using namespace std;

key_t GetKey()
{
    return ftok(PATH_NAME, PROJ_ID);
}