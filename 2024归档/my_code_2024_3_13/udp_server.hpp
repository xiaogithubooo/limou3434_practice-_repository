//udp_server.hpp
#pragma once

#include <string>

#include <cerrno>
#include <cstring>
#include <cstdlib>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>
#include <arpa/inet.h>

#include <unistd.h>
#include <strings.h>

#include "log.hpp"

#define DEBUG_SHOW

const int readBuffSize = 1024;

class UdpServer
{
    //2.初始服务器自己的 ip 和 port
public:UdpServer(uint16_t port, std::string ip = "")
        : _port(port), _ip(ip), _sock(-1)
    {
        //3.创建套接字
        if ((_sock = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
        {
            LogMessage(FATAL, "%d %s %s %d", errno, strerror(errno), __FILE__, __LINE__);
            exit(10);
        }

        //4.绑定套接字
        struct sockaddr_in local;
        bzero(&local, sizeof(local));
        local.sin_family = AF_INET; //设置协议家族
        local.sin_port = htons(_port); //设置 port
        local.sin_addr.s_addr = inet_addr(_ip.c_str()); //设置 ip

        if (bind(_sock, (struct sockaddr*)&local, sizeof(local)) < 0)
        {
            LogMessage(FATAL, "%d %s %s %d", errno, strerror(errno), __FILE__, __LINE__);
            exit(20);
        }

        //5.提示初始化成功
        LogMessage(NORMAL, "init udp server done ... %s %d", __FILE__, __LINE__);
    }

    public:void Start()
    {  }

    public:~UdpServer()
    {  }

private:
    //1.设置成员变量
    uint16_t _port; //port
    std::string _ip; //ip
    int _sock; //socket
};