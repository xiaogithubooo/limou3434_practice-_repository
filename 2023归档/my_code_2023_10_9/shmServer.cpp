//shmServer.cpp
#include "comm.hpp"
string TransToHex(key_t k)
{
    char buffer[32];
    snprintf(buffer, sizeof(buffer), "0x%x", k);
    return buffer;
}
int main()
{
    //1.创建共同的key
    key_t k = ftok(PATH_NAME, PROJ_ID);
    cout << TransToHex(k) << endl;
    assert(k != -1);
    //2.创建共享内存
    int shmid = shmget(k, SHM_SIZE, IPC_CREAT | IPC_EXCL | 0666);
    //注意共享内存不会随进程结束销毁，
    //可以使用ipcs -m查看，使用ipcrm -m <shmid>释放
    //注意最后的0666是设置共享内存的权限，这和文件类似

    assert(shmid != -1);
    //3.挂接共享内存
    char* shmaddr = (char*)shmat(shmid, nullptr, 0);
    assert(shmaddr != nullptr);
    //4.撰写通信逻辑
    for(;;)   
    {
        printf("%s\n", shmaddr);
        sleep(1);
    }

    //5.断接共享内存（从自己的地址空间中，默认清为全0）
    int n = shmdt(shmaddr);
    assert(n != -1);(void)n;

    //6.释放共享内存
    n = shmctl(shmid, IPC_RMID, nullptr);//这里的IPC_RMID很霸道，无论有多少个进程和共享内存挂接都会释放共享内存
    assert(n != -1);(void)n;
    return 0;
}
