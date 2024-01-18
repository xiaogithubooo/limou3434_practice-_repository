//shmClient.cpp
#include "comm.hpp"
int main()
{
    //1.创建共同的key
    key_t k = ftok(PATH_NAME, PROJ_ID);
    cout << k << endl;
    assert(k != -1);
    //2.获得共享内存
    int shmid = shmget(k, SHM_SIZE, 0);
    assert(shmid != -1);
    //3.挂接共享内存
    char* shmaddr = (char*)shmat(shmid, nullptr, 0);
    assert(shmaddr != nullptr);
    //4.撰写通信逻辑（将共享内存当作一个存储char的数组）
    char a = 'a';
    for(; a <= 'z'; a++)
    {
        snprintf(shmaddr, SHM_SIZE - 1, "Hello, I am server. My pid: %d, inc = %c\n", getpid(), a);
        sleep(2);
    }
    //5.断接共享内存
    int n = shmdt(shmaddr);
    assert(n != 1);
    return 0;
}