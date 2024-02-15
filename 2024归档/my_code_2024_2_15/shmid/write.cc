#include <sys/ipc.h>
#include <sys/shm.h>
#include <iostream>
#include <cstring>

const char* path = "./2024归档/my_code_2024_2_15";
const int proj_id = 10;
const int size = 1024;

int main()
{
    //申请共享内存
    key_t key = ftok(path, proj_id);
    int shmid = shmget(key, size, IPC_CREAT | IPC_EXCL | 0666);

    //挂接共享内存
    char* shmaddr = (char*)shmat(shmid, nullptr, 0);

    //写入共享内存
    while (true)
    {
        std::cin.getline(shmaddr, size);
        if (strcmp(shmaddr, "exit") == 0)
        {
            break;
        }
    }

    //断接共享内存
    shmdt(shmaddr);

    //释放共享内存
    shmctl(shmid, IPC_RMID, nullptr);

    return 0;
}
