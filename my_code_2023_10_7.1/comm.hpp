//comm.hpp
#ifndef _COMM_H_
#define _COMM_H_

#include <iostream>
#include <string>
#include <cstdio>
#include <cassert>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

#define PATH_NAME "/home/ljp"
#define PROJ_ID 0x666
#define SHM_SIZE 4096
//共享内存的大小最好是页(PAGE:4096)的整数倍，
//不过不是的话问题也不大，因为操作系统申请共享内存是按页的倍数申请的，
//如果不是整数倍的话，有可能造成共享内存空间浪费

using namespace std;
#endif
