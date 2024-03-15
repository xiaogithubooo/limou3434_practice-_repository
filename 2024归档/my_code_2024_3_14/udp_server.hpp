//udp_server.hpp(群体聊天程序)
#pragma once

#include <string>
#include <iostream>
#include <unordered_map>

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

#define DEBUG_SHOW

const int buffSize = 1024;

class UdpServer
{
    //2.初始服务器自己的 ip 和 port
    public:UdpServer(std::string ip, uint16_t port) //我把 ip 和 port 修改了顺序
        : _ip(ip), _port(port), _sock(-1)
    {
        //3.创建套接字
        if ( (_sock = socket(AF_INET, SOCK_DGRAM, 0)) < 0 )
        {
            LogMessage(FATAL, "%d %s %s %d", errno, strerror(errno), __FILE__, __LINE__);
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
            LogMessage(FATAL, "%d %s %s %d", errno, strerror(errno), __FILE__, __LINE__);
            exit(20);
        }
        /* 注意，发送消息时，也需要把本地的 ip 和 port 发送对方 */

        //5.提示初始化成功
        LogMessage(NORMAL, "init udp server done ... %d %s %s %d", errno, strerror(errno), __FILE__, __LINE__);
    }

    public:void Start()
    {
        while (true)
        {
            //6.提前备好一个结构体，方便读取和写入接口临时使用
            struct sockaddr_in peer;
            bzero(&peer, sizeof(peer)); //比特位置零
            socklen_t peerLen = sizeof(peer); //输入输出型参数 (1)输入缓冲区大小 (2)输出实际读到的 peer 大小，最好写明一下返回的类型

            //7.读取数据
            char readBuff[buffSize] = { 0 }; //初始化为 0，后续就不用添加 '\0' 了
            uint16_t cli_port = 0;
            std::string cli_ip;
            if (recvfrom(_sock, readBuff, sizeof(readBuff) - 1, 0, (struct sockaddr*)&peer, &peerLen) > 0) //读取成功
            {
                //读取到数据后把客户端发送的数据打印出来，包括客户端的 ip 和 port
                cli_port = ntohs(peer.sin_port); //需要反序列
                cli_ip = inet_ntoa(peer.sin_addr); //反序列后转化为点分十进制字符串（还有其他类似的接口）
                std::cout << "ip:[" << cli_ip << "] port:[" << cli_port << "]" << " sad:" << readBuff << std::endl;
                //LogMessage(NORMAL, "server read done ... %d %s %s %d", errno, strerror(errno), __FILE__, __LINE__);
            }
            else //读取失败
            {
                LogMessage(FATAL, "%d %s %s %d", errno, strerror(errno), __FILE__, __LINE__);
                exit(30);
            }

            //8.分析数据（注意之前读取的时候就可以获取到客户端的 ip 和 port）
            char key[64]; //初始化为 0，后续就不用添加 '\0' 了
            snprintf(key, sizeof(key), "{%s-%u}", cli_ip.c_str(), cli_port);

            auto it = _users.find(key);
            if (it == _users.end()) //用户不存在用户列表中
            {
                LogMessage(NORMAL, "add new user %s, %d %s %s %d", key, errno, strerror(errno), __FILE__, __LINE__);
                _users[key] = peer;
            }

            //9.更换模块：改为群聊系统
            for (auto& iter : _users)
            {
                std::string sendMessage = iter.first;
                sendMessage += "# ";
                sendMessage += readBuff;
                if (sendto(_sock, sendMessage.c_str(), sendMessage.size(), 0, (struct sockaddr*)&(iter.second), peerLen) >= 0) //写回成功
                {
                    LogMessage(NORMAL, "push message to %s, server write done ... %d %s %s %d", iter.first.c_str(), errno, strerror(errno), __FILE__, __LINE__);
                }
                else //写回失败
                {
                    LogMessage(FATAL, "%d %s %s %d", errno, strerror(errno), __FILE__, __LINE__);
                    exit(40);
                }
            }
        }
    }

    public:~UdpServer()
    {
        //10.关闭套接字
        if (_sock >= 0)
        {
            close(_sock); //关闭套接字描述符
            LogMessage(NORMAL, "close udp server done ... %d %s %s %d", errno, strerror(errno), __FILE__, __LINE__);
        }
    }

private:
    //1.设置成员变量
    std::string _ip; //ip
    uint16_t _port; //port
    int _sock; //socket
    std::unordered_map<std::string, struct sockaddr_in> _users; //存储不同<客户端,套接字信息>
};