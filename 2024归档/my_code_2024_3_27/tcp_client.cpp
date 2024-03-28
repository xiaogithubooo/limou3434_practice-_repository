//tcp_client.cpp(多进程死循环服务端)
#include <string>
#include <iostream>
#include <cstdio>

#include <cerrno>
#include <cstring>
#include <cstdlib>

#include <sys/types.h> //套接字编程的头文件
#include <sys/socket.h>

#include <netinet/in.h> //转化字节序的头文件
#include <arpa/inet.h>

#include <strings.h>

#include <unistd.h> //主要是文件 IO 接口的头文件

#include "log.hpp" //经过封装的日志头文件

const int readBuffSize = 1024;

static void Usage(std::string proc)
{
    std::cout << "\nUsage: " << proc << " [ip] [port]\n" << std::endl;
}

int main(int argc, char* argv[]) //./udp_client 127.0.0.1 8080
{
    Log log = Log(); //用于打印日志的日志对象（默认向屏幕输出日志，捕获 debug 级别的消息）

    //1.检查命令行输入
    if(argc != 3)
    {
        Usage(argv[0]);       
        exit(60);
    }

    //2.创建套接字
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if ( sock < 0 ) //补充一个小知识点：也有人把 AF_INET 换成等价的 PF_INET
    {
        log.LogMessage(FATAL, "%d %s %s %d", errno, strerror(errno), __FILE__, __LINE__);
        exit(70);
    }

    //3.绑定套接字
    //但是一般不需要程序员自己 bind
    
    //4.存储需要访问服务端的 ip 和 port
    std::string serverIp = argv[1];
    uint16_t serverPort = atoi(argv[2]);
    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(serverIp.c_str());
    server.sin_port = htons(serverPort);
    
    //5.连接服务端
    if ( connect(sock, (struct sockaddr*)&server, sizeof(server)) < 0 )
    {
        log.LogMessage(FATAL, "connect() error, %d %s %s %d", errno, strerror(errno), __FILE__, __LINE__);
        exit(80);
    }

    //6.向服务端发送数据
    while (true)
    {
        std::cout << "client >: ";
        std::string line;
        std::getline(std::cin, line);
        if (line == "exit")
            break;

        send(sock, line.c_str(), line.size(), 0); //向服务端发送数据
        
        char readBuffer[readBuffSize] = { 0 };
        ssize_t s = recv(sock, readBuffer, sizeof(readBuffer) - 1, 0);
        if (s > 0)
        {
            std::cout << "server echo:> " << readBuffer << std::endl;
        }
        else if (s == 0) //对端关闭连接
        {
            break;
        }
        else
        {
            log.LogMessage(FATAL, "recv() error, %d %s %s %d", errno, strerror(errno), __FILE__, __LINE__);
        }
    }

    //7.关闭套接字
    close(sock);
    log.LogMessage(NORMAL, "close udp client done ... %d %s %s %d", errno, strerror(errno), __FILE__, __LINE__);
    std::cout << "bye~" << std::endl;

    return 0;
}
