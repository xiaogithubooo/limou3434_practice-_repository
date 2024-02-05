//msgClient.cpp(封装代码)
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
    for(char a = 'a'; a <= 'z'; a++)
    {
        //向共享内存中写入数据
        cin >> shmaddr; //或者使用 snprintf(shmaddr, SHM_SIZE - 1, "Hello, I am shmClient. My pid: %d, inc = %c\n", getpid(), a);
        if (strcmp(shmaddr, "exit") == 0)
            break;
    }

    //5.断接共享内存
    int n = shmdt(shmaddr); assert(n != 1);

    return 0;
}