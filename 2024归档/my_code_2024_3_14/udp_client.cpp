//udp_client.cpp(群体聊天程序)
#include <string>
#include <iostream>
#include <memory>

#include <cerrno>
#include <cstring>
#include <cstdlib>

#include <sys/types.h> //套接字编程的头文件
#include <sys/socket.h>

#include <netinet/in.h> //转化字节序的头文件
#include <arpa/inet.h>

#include <strings.h>

#include <unistd.h> //主要是文件 IO 接口的头文件

#include <pthread.h> 

#include "log.hpp" //经过封装的日志头文件
#include "thread.hpp" //经过封装的线程头文件

const int readBuffSize = 1024;

std::string serverIp;
uint16_t serverPort = 0;

static void Usage(std::string proc)
{
    std::cout << "\nUsage: " << proc << " [ip] [port]\n" << std::endl;
}

static void UdpSend(int* psock)
{
    struct sockaddr_in server; //对应服务端套接字信息变量
    bzero(&server, sizeof(server)); //比特位置零
    server.sin_family = AF_INET; //设置协议家族/域
    server.sin_addr.s_addr = inet_addr(serverIp.c_str()); //设置 ip（四字节），内部做了两个步骤：(1)转化为四字节 (2)再转化为网络序列
    server.sin_port = htons(serverPort); //设置 port（两字节），主机序列转为网络序列

    while (true)
    {
        std::string message;
        std::cerr << "clien >: "; //这里只是利用 cerr 方便重定向而已
        std::getline(std::cin, message); //用户输入想要发送的数据
        if ( message == "exit" ) 
            break;
        if ( sendto(*psock, message.c_str(), message.size(), 0, (struct sockaddr*)&server, sizeof(server)) >= 0 ) //写入成功
        {
            //LogMessage(NORMAL, "client write done ... %d %s %s %d", errno, strerror(errno), __FILE__, __LINE__);
        }
        else //写入失败
        {
            LogMessage(FATAL, "%d %s %s %d", errno, strerror(errno), __FILE__, __LINE__);
            exit(70);
        }
    }
}

static void UdpRecv(int* psock)
{
    while (true)
    {
        char readBuff[readBuffSize] = { 0 }; //第一次向服务器发送数据时，操作系统会在 sendto() 执行过程程中自动为服务端绑定
    
        //实际上我们已经有了服务端的 ip 和 port 的信息了，这里我只是为了占位和调用规范写的，在本项目中可以不怎么处理（有时候客户端可以是其他端的客户端）
        struct sockaddr_in temp;
        bzero(&temp, sizeof(temp)); //比特位置零
        socklen_t len = sizeof(temp);
        if ( recvfrom(*psock, readBuff, sizeof(readBuff) - 1, 0, (struct sockaddr*)&temp, &len) >= 0 )
        {
            std::cout << "server echo >: " << readBuff << std::endl;
        }
        else //读取失败
        {
            LogMessage(FATAL, "%d %s %s %d", errno, strerror(errno), __FILE__, __LINE__);
            exit(80);
        }
    }
}

int main(int argc, char* argv[]) //./udp_client 127.0.0.1 8080
{
    //1.检查命令行输入
    if(argc != 3)
    {
        Usage(argv[0]);       
        exit(50);
    }

    //2.创建套接字
    int sock = socket(AF_INET, SOCK_DGRAM, 0); //套接字改为全局变量，方便多线程编写代码
    if ( sock < 0 ) //补充一个小知识点：也有人把 AF_INET 换成等价的 PF_INET
    {
        LogMessage(FATAL, "%d %s %s %d", errno, strerror(errno), __FILE__, __LINE__);
        exit(60);
    }

    //3.绑定套接字
    //但是一般不需要程序员自己 bind，这是因为客户端是被客户端使用的，如果程序员自己 bind 了，
    //那么该客户端的一定是绑定了某个固定的 ip 和 port 万一在多个不关联的客户端同时启动的情况下，
    //就会出现 port 绑定失败的情况，进而导致客户端启动失败。
    //将 bind 操作交给操作系统来做，操作系统对于哪些 port 没有被占用的情况最清楚了。
    
    //4.存储需要访问服务端的 ip 和 port
    serverIp = argv[1];
    serverPort = atoi(argv[2]);

    //5.创建写线程和读线程
    std::unique_ptr<Thread<int*>> sender(new Thread<int*>("client_send_thread", UdpSend, &sock));
    std::unique_ptr<Thread<int*>> recver(new Thread<int*>("client_recv_thread", UdpRecv, &sock));

    //6.向服务端发送消息
    sender->Start();

    //7.从服务端读取消息
    recver->Start();

    //8.销毁线程
    sender->Join();
    recver->Join();
    
    //9.关闭套接字
    close(sock);
    LogMessage(NORMAL, "close udp client done ... %d %s %s %d", errno, strerror(errno), __FILE__, __LINE__);
    std::cout << "bye~" << std::endl;

    return 0;
}