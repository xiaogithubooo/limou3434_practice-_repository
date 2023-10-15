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
    //2.通信过程
    string buffer;
    while(true)
    {
        cout << "please enter message line:" << endl;
        getline(cin, buffer);
        write(fd, buffer.c_str(), buffer.size());
    }
    return 0;
}