//semServer.cpp
#include <iostream>
#include <string>

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/sem.h>

#define PATH_NAME "/home/ljp" //路径名
#define PROJ_ID 0x666 //项目 ID（用于创建 key）
#define SHM_SIZE 4096 //共享内存大小

using namespace std;

key_t GetKey()
{
    return ftok(PATH_NAME, PROJ_ID);
}

class SemInit
{
public:
    SemInit()
    {
        //创建共同的 key
        key_t k = GetKey();
        cout << "申请 key 值:" << hex << k << dec << endl;
        //创建信号量
        _semid = semget(k, //key 值
            1, //信号量集大小
            IPC_CREAT | IPC_EXCL | 0666 //flag 设定
        );
    }
    
    ~SemInit()
    {
        //释放信号量
        semctl(_semid, //id 值
            0, //对应信号量编号
            IPC_RMID //对指定信号量的操作
        );
    }
    
public:
    int _semid;
};

int main()
{
    SemInit msg;
    struct semid_ds ds { 0 };

    semctl(msg._semid, //id 值
        0, //对应信号量编号
        IPC_STAT, //对指定信号量的操作
        &ds
    );

    cout << "信号量 key:" << hex << ds.sem_perm.__key << dec << endl;

    return 0;
}