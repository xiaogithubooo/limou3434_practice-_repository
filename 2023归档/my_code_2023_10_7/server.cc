#include "comm.hpp"
int main()
{
    //1.创建管道文件
    if(mkfifo(ipcPath.c_str(), MOOD) < 0)
    {
        perror("mkfifo() wrong!");
        exit(1);
    }

    //2.正常文件操作
    int fd = open(ipcPath.c_str(), O_RDONLY);
    if(fd < 0)
    {
        perror("open() wrong!");
        exit(2);
    }
    //3.编写通信代码
    char buffer[SIZE];
    while(SIZE)
    {
        memset(buffer, '\0', sizeof(buffer));
        ssize_t s = read(fd, buffer, sizeof(buffer) - 1);
        if(s > 0)
        {
            cout << "client say: " << buffer << endl;
        }
        else if(s == 0)
        {
            cerr << "read end of file!" << endl;
        }
        else
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