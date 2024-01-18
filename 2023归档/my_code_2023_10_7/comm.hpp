#ifndef _COMM_H_
#define _COMM_H_

#include <iostream>
#include <string>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <cstdio>
#include <cstring>
using namespace std;

string ipcPath = "./fifo.ipc";//管道文件路径
#define MOOD 0666//设置管道文件初始权限
#define SIZE 128//设置缓冲大小

#endif
