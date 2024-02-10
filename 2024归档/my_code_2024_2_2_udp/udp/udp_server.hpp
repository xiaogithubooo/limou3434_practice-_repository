//udp_server.hpp(修改 ip 地址绑定逻辑)
#pragma once

#include <string>
#include <queue>
#include <unordered_map>

#include <cerrno>
#include <cstring>
#include <cstdlib>
#include <cstdio>

#include <strings.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#include "log.hpp"

#define DEBUG_SHOW

const int readBuffSize = 1024;

class UdpServer
{
public:
    /* 初始化服务断配置 */
    UdpServer(uint16_t port, std::string ip = "") //IP 地址假定为空
        : _port(port), _ip(ip), _sock(-1)
    {
        //下面开始我们的网络编程
        //1.创建套接字
        if ((_sock = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
        {
            LogMessage(FATAL, "%d:%s", errno, strerror(errno));
            exit(20);
        }

        //2.绑定套接字
        struct sockaddr_in local; //ipv4
        bzero(&local, sizeof(local));

        local.sin_port = htons(_port); //由于需要把本机的端口号发送给对方，因此需要转化字节序再填入端口号
        local.sin_addr.s_addr = _ip.empty() ? INADDR_ANY : inet_addr(_ip.c_str()); //填入反字节序的 ip 地址（若为空则填入任意 IP 地址，可以让服务器从任意 IP 中获取数据，该关键字实际是 0）
        local.sin_family = AF_INET; //设置协议家族

        if (bind(_sock, (struct sockaddr*)&local, sizeof(local)) < 0)
        {
            LogMessage(FATAL, "%d:%s", errno, strerror(errno));
            exit(30);
        }

        LogMessage(NORMAL, "init udp server done ... %s", strerror(errno));
    }

    /*启动进程*/
    void Start()
    {
        //注意，只要主机不奔溃服务端不出错，服务端将永远不退出（对于系统来说，就是一个常驻进程）
        while (true)
        {
            //1.读取数据
            char readBuff[readBuffSize] = { 0 }; //初始化为 0，后续就不用添加 '\0' 了
            
            struct sockaddr_in peer; bzero(&peer, sizeof(peer)); //纯输出型参数
            socklen_t peerLen = sizeof(peer); //输入输出型参数，输入：缓冲区大小，输出：实际读到的 peer 大小

            char result[1024] = { 0 }; //后续读取命令返回结果时要用的读取缓冲区
            std::string cmd_echo; //读取后的所有结果存储在 cmd_echo 中，然后发送回客户端
        
            ssize_t s = recvfrom(_sock, readBuff, sizeof(readBuff) - 1, //读取数据
                0, (struct sockaddr*)&peer, &peerLen);

            char key[64] = { 0 };
            if (s > 0)
            {
                //1.1.读取到的信息
                //1.2.指明是谁发送的信息
                uint16_t cli_port = ntohs(peer.sin_port); //需要反序列
                std::string cli_ip = inet_ntoa(peer.sin_addr); //反序列后转化为点分十进制字符串

                snprintf(key, sizeof(key), "%s+%d", cli_ip.c_str(), cli_port);
                LogMessage(NORMAL, "key:%s", key); //输出接受到的用户端套接字信息
                auto it = _users.find(key);
                if (it == _users.end()) //对应用户端的 key-套接字 键值对
                {
                    LogMessage(NORMAL, "Add new user:%s", key);
                    _users.insert({ key, peer });
                }
            }
            else
            {
                LogMessage(FATAL, "%d:%s", errno, strerror(errno));
                exit(40);
            }

            //2.根据不同用户端，写回数据
            for (auto& iter : _users)
            {
                std::string sendMessage = key; //接受到的报文
                sendMessage += "# ";
                sendMessage += readBuff;
                LogMessage(NORMAL, "push message to %s", iter.first.c_str());
                sendto(_sock, sendMessage.c_str(), sendMessage.size(), 0, (struct sockaddr*)&iter.second, sizeof(iter.second));
            }
        }
    }

    ~UdpServer()
    {
        if (_sock >= 0)
            close(_sock);
    }

private:
    uint16_t _port; //端口号（一般是 16 位的整数）
    std::string _ip; //ip 地址
    int _sock; //套接字（当作文件描述符理解）
    std::unordered_map<std::string, struct sockaddr_in> _users; //存储不同客户端发送过来的套接字结构
};
