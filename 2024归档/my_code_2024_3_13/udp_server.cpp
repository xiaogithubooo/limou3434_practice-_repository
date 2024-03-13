//udp_server.cpp
#include <iostream>
#include <memory>
#include <string>
#include <cstdlib>

#include "udp_server.hpp"

static void Usage(std::string proc)
{
    std::cout << "\nUsage: " << proc << "ip port\n" << std::endl;
}

int main(int argc, char* argv[]) //服务器启动指令 ./udp_server ip port
{
    //1.检查命令是否合法，否则打印使用手册
    if (argc != 3)
    {
        Usage(argv[0]);
        exit(10);
    }

    //2.分割出 IP 和 PORT 信息
    std::string ip = argv[1];
    uint16_t port = atoi(argv[2]);

    //3.使用智能指针托管服务端指针
    std::unique_ptr<UdpServer> svr(new UdpServer(port, ip));

    //4.启动服务端服务
    svr->Start();

    return 0;
}