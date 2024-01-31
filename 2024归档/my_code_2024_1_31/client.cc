//客户端 client.cc 负责写入
#include "comm.hpp"
int main()
{
    //1.获取管道文件
    int fd = open(ipcPath.c_str(), O_WRONLY);
    if(fd < 0)
    {
        perror("open() wrong!");
        exit(1);
    }

    //2.通信写入过程
    string buffer;
    while(true)
    {
        cout << "please enter message line:" << endl;
        getline(cin, buffer); //获取整行的字符串
        ssize_t s = write(fd, buffer.c_str(), buffer.size()); //写入有名管道文件中（没有写入 '\0'）
        if (s < 0)
        {
            perror("write() error!");
            break;
        }
        if (strcmp(buffer.c_str(), "exit") == 0)
        {
            break;
        }
    }

    //3.关闭管道文件
    close(fd);
    return 0;
}