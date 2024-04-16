//udp_server.hpp(通信基本程序)
#pragma once

#include <string>
#include <iostream>

#include <cstring>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <strings.h>
#include <unistd.h>

#include "log.hpp"

#define DEBUG_SHOW

const int buffSize = 1024;

class UdpServer
{
    //2.初始服务器自己的 ip 和 port
public:
    UdpServer(uint16_t port, std::string ip)
        : _ip(ip), _port(port), _sock(-1)
    {
        //3.创建套接字
        if ( (_sock = socket(AF_INET, SOCK_DGRAM, 0)) < 0 )
        {
            _log.LogMessage(FATAL, "socket() error, %s %d", __FILE__, __LINE__);
            exit(10);
        }

        //4.绑定套接字
        struct sockaddr_in local;
        bzero(&local, sizeof(local)); //比特位置零
        local.sin_family = AF_INET; //设置协议家族/域
        local.sin_addr.s_addr = _ip.empty() ? INADDR_ANY : inet_addr(_ip.c_str()); //设置 ip（四字节），内部做了两个步骤：(1)转化为四字节 (2)再转化为网络序列
        local.sin_port = htons(_port); //设置 port（两字节），主机序列转为网络序列
        if ( bind(_sock, (struct sockaddr*)&local, sizeof(local)) < 0 )
        {
            _log.LogMessage(FATAL, "bind() error, %s %d", __FILE__, __LINE__);
            exit(20);
        }
        /* 注意，发送消息时，也需要把本地的 ip 和 port 发送对方 */

        //5.提示初始化成功
        _log.LogMessage(NORMAL, "UdpServer() success, %s %d", __FILE__, __LINE__);
    }

    void Start()
    {
        while (true)
        {
            //6.提前备好一个结构体，方便读取和写入接口临时使用
            struct sockaddr_in peer;
            bzero(&peer, sizeof(peer)); //比特位置零
            socklen_t peerLen = sizeof(peer); //输入输出型参数 (1)输入缓冲区大小 (2)输出实际读到的 peer 大小，最好写明一下返回的类型

            //7.读取数据
            char readBuff[buffSize] = { 0 }; //初始化为 0，后续就不用添加 '\0' 了
            if ( recvfrom( _sock, readBuff, sizeof(readBuff) - 1, 0, (struct sockaddr*)&peer, &peerLen) > 0 ) //读取成功
            {
                //读取到数据后把客户端发送的数据打印出来，包括客户端的 ip 和 port
                uint16_t cli_port = ntohs(peer.sin_port); //需要反序列
                std::string cli_ip = inet_ntoa(peer.sin_addr); //反序列后转化为点分十进制字符串（还有其他类似的接口）
                std::cout << "ip:[" << cli_ip << "] port:[" << cli_port << "]" << " sad:" << readBuff << std::endl;
                _log.LogMessage(NORMAL, "server read done ... %s %d", __FILE__, __LINE__);
            }
            else //读取失败
            {
                _log.LogMessage(FATAL, "recvfrom() error, %s %d", __FILE__, __LINE__);
                exit(30);
            }

            //8.分析数据
            //TODU...

            //9.写回数据
            //char writerBuff[buffSize] = "Ok~"; //初始化为 0，后续就不用添加 '\0' 了
            //if (sendto(_sock, writerBuff, strlen(writerBuff), 0, (struct sockaddr*)&peer, peerLen) > 0) //读取成功
            //{
            //    LogMessage(NORMAL, "server write done ... %s %d", __FILE__, __LINE__);
            //}
            //由于我们希望客户端之间可以通过服务端来通信，因此这里直接把服务端从客户端中读取的数据返回客户端即可，这也后续有多个客户端向服务端发送消息时，服务端返回的信息可以同步给每一个客户端
            if ( sendto(_sock, readBuff, strlen(readBuff), 0, (struct sockaddr*)&peer, peerLen) >= 0 ) //写回成功，注意这里是 strlen()，只发送有效的数据，并且前面读取数据的时候也获取了客户端的套接字消息，可以直接在这里使用
            {
                _log.LogMessage(NORMAL, "server write done ...%s %d", __FILE__, __LINE__);
            }
            else //写回失败
            {
                _log.LogMessage(FATAL, "%s %d", __FILE__, __LINE__);
                exit(40);
            }
        }
    }

    ~UdpServer()
    {
        //10.关闭套接字
        if (_sock >= 0)
        {
            close(_sock); //关闭套接字描述符
            _log.LogMessage(NORMAL, "close udp server done ... %s %d", __FILE__, __LINE__);
        }
    }

private:
    //1.设置成员变量
    std::string _ip;
    uint16_t _port;
    int _sock;
    Log _log;
};