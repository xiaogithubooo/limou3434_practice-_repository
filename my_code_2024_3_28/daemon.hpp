//daemon.hpp(自定义协议)
#pragma once
#include <iostream>
#include <unistd.h>
#include <signal.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

//调用下述函数时，就会
void MyDaemon()
{
    //1.忽略信号，避免服务端因为某些原因挂掉
    signal(SIGPIPE, SIG_IGN); //防止运行过程中出现非法写入的问题（例如服务端写到一半时，客户端因为异常而被关闭），避免因为客户端出现问题，导致服务端跟着挂掉
    signal(SIGCHLD, SIG_IGN); //不向父进程提醒，因此不回收子进程

    //2.避免自己成为组长
    if (fork() > 0)
    {
        exit(0); //父进程直接正常终止
    }

    //下面是子进程的部分

    //3.调用 setsid()
    setsid(); //成为新的会话

    //4.标准输出、标准输入、标准错误的重定向（尤其是不能在屏幕上进行日志打印，一旦打印就有可能暂停和中止）
    int devNnll = open("/dev/null", O_RDONLY | O_WRONLY); //在 Linux 中基本都有 /dev/null，其特点就是写入任何数据都会清空，也无法读取任何数据（文件黑洞）
    if (devNnll > 0)
    {
        dup2(devNnll, 0); //oldfd 复制-> newfd
        dup2(devNnll, 1);
        dup2(devNnll, 2);
        close(devNnll);
    }
}