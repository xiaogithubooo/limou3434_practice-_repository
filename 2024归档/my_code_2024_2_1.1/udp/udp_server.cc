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
    if (argc != 3) //启动方法有误
    {
        Usage(argv[0]);
        exit(10);
    }
    
    std::string ip = argv[1]; //获取端口号
    uint16_t port = atoi(argv[2]); //获取 ip 地址 

    std::unique_ptr<UdpServer> svr(new UdpServer(port, ip)); //使用智能指针托管指针（内含初始化）
    svr->Start();
    
    return 0;
}