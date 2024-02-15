#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <iostream>
#include <cstring>

const char* path = "./2024归档/my_code_2024_2_15";
const int proj_id = 10;
const int size = 1024;

int main()
{
    //获取共享内存
    key_t key = ftok(path, proj_id);
    int shmid = shmget(key, size, IPC_CREAT);

    //挂接共享内存
    char* shmaddr = (char*)shmat(shmid, nullptr, 0);
    
    //读取共享内存
    while (true)
    {
        std::cout << shmaddr << std::endl;
        if (strcmp(shmaddr, "exit") == 0)
        {
            break;
        }
        sleep(2);
    }

    //断接共享内存
    shmdt(shmaddr);

    return 0;
}
