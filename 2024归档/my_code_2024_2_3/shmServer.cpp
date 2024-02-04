//shmServer.cpp
#include "comm.hpp"

class ShmInit
{
public:
    ShmInit()
    {
        //1.创建共同的 key
        key_t k = GetKey();
        //2.创建共享内存
        _shmid = shmget(k, SHM_SIZE, IPC_CREAT | IPC_EXCL | 0666); //最后的 0666 是设置共享内存的权限，这和文件权限类似
        //3.服务端挂接共享内存
        _shmaddr = (char*)shmat(_shmid, nullptr, 0);

        //4.创建管道文件
        MakeFifo();
        //5.只读打开管道文件
        _fd = open(ipcPath.c_str(), O_RDONLY);
    }
    ~ShmInit()
    {
        //6.断接共享内存（从自己的地址空间中移除）
        int n = shmdt(_shmaddr);
        //7.释放共享内存
        n = shmctl(_shmid, IPC_RMID, nullptr); //这里的 IPC_RMID 很霸道，无论有多少个进程和共享内存挂接都会释放共享内存

        //8.关闭管道文件
        close(_fd);
        //9.删除管道文件
        unlink(ipcPath.c_str());
    }
    
public:
    int _shmid;
    int _fd;
    char* _shmaddr;
};


int main()
{
    ShmInit shm;
    
    //10.撰写通信逻辑
    while(true)   
    {
        //11.（读管道文件通知）等待管道文件内部有数据时，才会往共享内存的代码走，否则循环代码陷入阻塞
        int code = 0;
        int n = read(shm._fd, &code, sizeof(code));

        //12.（读共享内存数据）读取共享内存中的数据
        if (n > 0)
        {
            cout << shm._shmaddr << endl;
            if (strcmp(shm._shmaddr, "exit") == 0)
                break;
        }
        else
        {
            break;
        }
    }
  
    return 0;
}
