//shmServer.cpp
#include "comm.hpp"

int main()
{
    //1.创建共同的 key
    key_t k = ftok(PATH_NAME, PROJ_ID); assert(k != -1);
    cout
        << hex << k << " " //使用 16 进制输出
        << dec << k //使用 10 进制输出
        << endl;

    //2.创建共享内存
    int shmid = shmget(k, SHM_SIZE, IPC_CREAT | IPC_EXCL | 0666); assert(shmid != -1); //最后的 0666 是设置共享内存的权限，这和文件权限类似
    
    //3.挂接共享内存
    char* shmaddr = (char*)shmat(shmid, nullptr, 0); assert(shmaddr != nullptr);

    int fd = open(ipcPath.c_str(), O_WRONLY); //[只写打开管道文件]

    //4.撰写通信逻辑
    while(true)   
    {
        cout << shmaddr << endl; //不断从共享内存中获取数据
        if (strcmp(shmaddr, "exit") == 0)
            break;
        sleep(6); //[故意延长等待，让用户输入更多数据再传送]
        
        //[将 code 写入管道，达到访问控制的目的]
        int code = 1;
        write(fd, &code, sizeof(int));
    }

    //5.断接共享内存（从自己的地址空间中移除）
    int n = shmdt(shmaddr); assert(n != -1); (void)n;

    //6.释放共享内存
    n = shmctl(shmid, IPC_RMID, nullptr); assert(n != -1); (void)n; //这里的IPC_RMID很霸道，无论有多少个进程和共享内存挂接都会释放共享内存
    
    return 0;
}
