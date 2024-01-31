//服务端 server.cc 负责读取
#include "comm.hpp"
int main()
{
    //1.创建管道文件
    if(mkfifo(ipcPath.c_str(), MOOD) < 0)
    {
        perror("mkfifo() wrong!");
        exit(1);
    }

    //2.通信读取过程
    int fd = open(ipcPath.c_str(), O_RDONLY);
    if(fd < 0)
    {
        perror("open() wrong!");
        exit(2);
    }
    
    char buffer[SIZE];
    while(SIZE)
    {
        memset(buffer, '\0', sizeof(buffer)); //初始化
        ssize_t s = read(fd, buffer, sizeof(buffer) - 1); //读取的时候注定得不到 '\0' 但是我们使用的是 C 代码，读取字符串后一定要保证最后一位是 '\0'，但是上面的初始化保证了这一操作
        if(s > 0) //读取成功
        {
            cout << "client say: " << buffer << endl;
            if (strcmp(buffer, "exit") == 0)
            {
                break;
            }
        }
        else if(s == 0)
        {
            cerr << "read end of file!" << endl;
        }
        else //出现错误
        {
            perror("read() wrong!");
        }
    }

    //4.关闭管道文件
    close(fd);

    //5.删除管道文件
    unlink(ipcPath.c_str());

    return 0;
}