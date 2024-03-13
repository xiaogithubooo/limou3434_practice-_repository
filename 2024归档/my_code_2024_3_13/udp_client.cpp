//udp_client.cpp(远程操作程序)
#include <string>
#include <iostream>

#include <cerrno>
#include <cstring>
#include <cstdlib>

#include <sys/types.h> //套接字编程的头文件
#include <sys/socket.h>

#include <netinet/in.h> //转化字节序的头文件
#include <arpa/inet.h>

#include <strings.h>

#include <unistd.h> //主要是文件 IO 接口的头文件

#include "log.hpp"

const int readBuffSize = 1024;

static void Usage(std::string proc)
{
    std::cout << "\nUsage: " << proc << " [ip] [port]\n" << std::endl;
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
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
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
    struct sockaddr_in server;
    bzero(&server, sizeof(server)); //比特位置零
    server.sin_family = AF_INET; //设置协议家族/域
    server.sin_addr.s_addr = inet_addr(argv[1]); //设置 ip（四字节），内部做了两个步骤：(1)转化为四字节 (2)再转化为网络序列
    server.sin_port = htons(atoi(argv[2])); //设置 port（两字节），主机序列转为网络序列

    while (true)
    {
        //5.向服务端发送消息 message
        std::string message;
        std::cout << "clien >: ";
        std::getline(std::cin, message); //用户输入想要发送的数据
        if ( message == "exit" ) 
            break;
        if ( sendto(sock, message.c_str(), message.size(), 0, (struct sockaddr*)&server, sizeof(server)) > 0 ) //写入成功
        {
            //LogMessage(NORMAL, "client write done ... %d %s %s %d", errno, strerror(errno), __FILE__, __LINE__);
        }
        else //写入失败
        {
            LogMessage(FATAL, "%d %s %s %d", errno, strerror(errno), __FILE__, __LINE__);
            exit(70);
        }

        //6.读取服务端返回的消息
        char readBuff[readBuffSize] = { 0 }; //第一次向服务器发送数据时，操作系统会在 sendto() 执行过程程中自动为服务端绑定

        //实际上我们已经有了服务端的 ip 和 port 的信息了，这里我只是为了占位和调用规范写的，在本项目中可以不怎么处理（有时候客户端可以是其他端的客户端）
        struct sockaddr_in temp;
        bzero(&temp, sizeof(temp)); //比特位置零
        socklen_t len = sizeof(temp);
        if ( recvfrom(sock, readBuff, sizeof(readBuff) - 1, 0, (struct sockaddr*)&temp, &len) > 0 )
        {
            std::cout << "server echo >: " << readBuff << std::endl;
        }
    }

    //7.关闭套接字
    close(sock);
    LogMessage(NORMAL, "close udp client done ... %d %s %s %d", errno, strerror(errno), __FILE__, __LINE__);
    std::cout << "bye~" << std::endl;

    return 0;
}