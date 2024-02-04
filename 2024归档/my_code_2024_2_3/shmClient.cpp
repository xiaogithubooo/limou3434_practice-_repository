//shmClient.cpp
#include "comm.hpp"

int main()
{
    //1.创建共同的 key
    key_t k = GetKey();

    //2.获得共享内存（注意是获得，在 shmServer 中已经获取了）
    int shmid = shmget(k, SHM_SIZE, IPC_CREAT); assert(shmid != -1);

    //3.用户端挂接共享内存
    char* shmaddr = (char*)shmat(shmid, nullptr, 0); assert(shmaddr != nullptr); //很类似 malloc() 的使用
    
    //4.撰写通信逻辑（将共享内存当作一个存储 char 的数组）
    int fd = open(ipcPath.c_str(), O_WRONLY); //[只写打开管道文件]
    for(char a = 'a'; a <= 'z'; a++)
    {
        //向共享内存中写入数据
        cin >> shmaddr; //或者使用 snprintf(shmaddr, SHM_SIZE - 1, "Hello, I am shmClient. My pid: %d, inc = %c\n", getpid(), a);
        if (strcmp(shmaddr, "exit") == 0)
            break;

        //[每隔 6s 将 code 写入管道，用户端只有读取到管道文件的数据时才能读取共享内存，这可以达到访问控制的目的]
        sleep(6);
        int code = 1;
        write(fd, &code, sizeof(int));
    }

    //5.断接共享内存
    int n = shmdt(shmaddr); assert(n != 1);

    //6.关闭管道文件
    close(fd);

    return 0;
}
