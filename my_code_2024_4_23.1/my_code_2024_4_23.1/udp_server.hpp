//udp_server.hpp(群体聊天程序)

/* 使用方法
    std::unique_ptr<UdpServer> svr(new UdpServer(port, ip));
    svr->Start();
*/

#pragma once
#include <string>
#include <iostream>
#include <unordered_map>
#include <cerrno>
#include <cstring>
#include <cstdlib>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <strings.h>
#include <unistd.h>
#include "log.hpp"

#define DEBUG_SHOW

class UdpServer
{
private:
    static const int buffSize = 1024; //缓冲区大小, 简单说 const 其实是 "readonly", constexpr 才是 "const", 前者保证运行中无法修改, 后置保证编译期间就被填充

public:
    //初始服务器(ip 和 port)
    UdpServer(uint16_t port, std::string ip)
        : _ip(ip), _port(port), _sock(-1)
    {
        //1.创建套接字
        if ((_sock = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
        {
            _log.LogMessage(FATAL, "socket() error, %s %d", __FILE__, __LINE__);
            exit(-1);
        }

        //2.绑定套接字
        struct sockaddr_in local;
        bzero(&local, sizeof(local)); //比特位置零
        local.sin_family = AF_INET; //设置协议家族/域
        local.sin_addr.s_addr = _ip.empty() ? INADDR_ANY : inet_addr(_ip.c_str()); //设置 ip（四字节）, 内部做了两个步骤：(1)转化为四字节 (2)再转化为网络序列
        local.sin_port = htons(_port); //设置 port（两字节）, 主机序列转为网络序列
        if (bind(_sock, (struct sockaddr*)&local, sizeof(local)) < 0)
        {
            _log.LogMessage(FATAL, "bind() error, %s %d", __FILE__, __LINE__);
            exit(-1);
        }
        _log.LogMessage(NORMAL, "init udp server done ... %s %d", __FILE__, __LINE__);
    }

    //释放服务器(sock)
    ~UdpServer()
    {
        //关闭套接字
        if (_sock >= 0)
        {
            close(_sock); //关闭套接字描述符
            _log.LogMessage(NORMAL, "close udp server done ... %s %d", __FILE__, __LINE__);
        }
    }

    //启动服务器
    void Start()
    {
        while (true)
        {
            //提前备好一个结构体, 方便读取和写入接口临时使用
            struct sockaddr_in peer;
            bzero(&peer, sizeof(peer)); //比特位置零
            socklen_t peerLen = sizeof(peer); //输入输出型参数 (1)输入缓冲区大小 (2)输出实际读到的 peer 大小, 最好写明一下返回的类型

            //读取数据
            char readBuff[buffSize] = { 0 }; //初始化为 0, 后续就不用添加 '\0' 了
            uint16_t cli_port = 0;
            std::string cli_ip;
            if (recvfrom(_sock, readBuff, sizeof(readBuff) - 1, 0, (struct sockaddr*)&peer, &peerLen) > 0) //读取成功
            {
                //读取到数据后把客户端发送的数据打印出来, 包括客户端的 ip 和 port
                cli_port = ntohs(peer.sin_port); //需要反序列
                cli_ip = inet_ntoa(peer.sin_addr); //反序列后转化为点分十进制字符串（还有其他类似的接口）
                std::cout << "ip:[" << cli_ip << "] port:[" << cli_port << "]" << " sad:" << readBuff << std::endl;
                //_log.LogMessage(NORMAL, "server read done ... %s %d", __FILE__, __LINE__);
            }
            else //读取失败
            {
                _log.LogMessage(FATAL, "%s %d", __FILE__, __LINE__);
                exit(-1);
            }

            //分析数据, 添加用户
            char key[64] = { 0 }; //初始化为 0, 后续就不用添加 '\0' 了
            snprintf(key, sizeof(key), "{%s-%u}", cli_ip.c_str(), cli_port);

            auto it = _users.find(key);
            if (it == _users.end()) //若用户不存在用户列表中, 则添加进用户表中作记录
            {
                _log.LogMessage(NORMAL, "add new user %s, %s %d", key, __FILE__, __LINE__);
                _users[key] = peer;
            }

            //群聊广播推送
            for (auto& iter : _users)
            {
                std::string sendMessage = key;
                sendMessage += "# ";
                sendMessage += readBuff;
                if (sendto(_sock, sendMessage.c_str(), sendMessage.size(), 0, (struct sockaddr*)&(iter.second), peerLen) >= 0) //写回成功
                {
                    _log.LogMessage(NORMAL, "push message to %s, server write done... %s %d", iter.first.c_str(), __FILE__, __LINE__);
                }
                else //写回失败
                {
                    _log.LogMessage(FATAL, "%s %d", __FILE__, __LINE__);
                    exit(-1);
                }
            }
        }
    }


private:
    std::string _ip;
    uint16_t _port;
    int _sock;
    std::unordered_map<std::string, struct sockaddr_in> _users; //存储不同<客户端, 套接字信息>
    Log _log;
};