//tcp_server.cpp(线程池版本的服务端)

#include <iostream>
#include <memory>
#include <string>
#include <cstdlib>
#include "tcp_server.hpp"

static void Usage(std::string proc)
{
    std::cout << "\nUsage: " << proc << " [ip(optional)] [port]\n" << std::endl;
}

int main(int argc, char* argv[]) //服务器启动指令 ./udp_server ip port
{
    //1.检查命令是否合法，否则打印使用手册
    uint16_t port;
    std::string ip;
    if (argc == 2)
    {
        //2.分割出 PORT 信息
        port = atoi(argv[1]);
    }
    else if (argc == 3)
    {
        //3.分割出 IP 和 PORT 信息
        ip = argv[1];
        port = atoi(argv[2]);
    }
    else
    {
        Usage(argv[0]);
        exit(-1);
    }

    //4.使用智能指针托管服务端指针
    std::unique_ptr<TcpServer> svr(new TcpServer(port, ip));

    //5.启动服务端服务
    svr->Start();

    return 0;
}