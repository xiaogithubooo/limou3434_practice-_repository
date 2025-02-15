//shmClient.cpp
#include "comm.hpp"
int main()
{
    //1.创建共同的key
    key_t k = ftok(PATH_NAME, PROJ_ID); assert(k != -1);
    cout
        << hex << k << " "//使用 16 进制输出
        << dec << k //使用 10 进制输出
        << endl;

    //2.获得共享内存
    int shmid = shmget(k, SHM_SIZE, IPC_CREAT); assert(shmid != -1);

    //3.挂接共享内存
    char* shmaddr = (char*)shmat(shmid, nullptr, 0); assert(shmaddr != nullptr);

    //4.撰写通信逻辑（将共享内存当作一个存储 char 的数组）
    for(char a = 'a'; a <= 'z'; a++)
    {
        cin >> shmaddr;
        //或者使用 snprintf(shmaddr, SHM_SIZE - 1, "Hello, I am shmClient. My pid: %d, inc = %c\n", getpid(), a);
        if (strcmp(shmaddr, "exit") == 0)
            break;
        sleep(2);
    }

    //5.断接共享内存
    int n = shmdt(shmaddr); assert(n != 1);

    return 0;
}