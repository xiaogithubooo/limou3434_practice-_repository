//udp_server.hpp(远程操作程序)
#pragma once
#include <string>
#include <iostream>
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

const int buffSize = 1024;

class UdpServer
{
    //2.初始服务器自己的 ip 和 port
public:
    UdpServer(uint16_t port, std::string ip)
        : _ip(ip), _port(port), _sock(-1)
    {
        //3.创建套接字
        if ((_sock = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
        {
            _log.LogMessage(FATAL, "socket() error, %s %d", __FILE__, __LINE__);
            exit(-1);
        }

        //4.绑定套接字
        struct sockaddr_in local;
        bzero(&local, sizeof(local)); //比特位置零
        local.sin_family = AF_INET; //设置协议家族/域

        local.sin_addr.s_addr = _ip.empty() ? INADDR_ANY : inet_addr(_ip.c_str()); //设置 ip, 空的话设置位任意 ip 地址, 非空的话使用用户传递的 ip 地址
        //注意 inet_addr() 内部做了两个步骤：(1)将 ip 转化为四字节 (2)再转化为网络序列
        local.sin_port = htons(_port); //设置 port（两字节）,主机序列转为网络序列

        if (bind(_sock, (struct sockaddr*)&local, sizeof(local)) < 0)
        {
            _log.LogMessage(FATAL, "bind() error, %s %d", __FILE__, __LINE__);
            exit(-1);
        }

        //5.提示初始化成功
        _log.LogMessage(NORMAL, "init udp server done ... %s %d", __FILE__, __LINE__);
    }

    void Start()
    {
        while (true)
        {
            //6.提前备好一个结构体, 方便读取和写入接口临时使用
            struct sockaddr_in peer;
            bzero(&peer, sizeof(peer)); //比特位置零
            socklen_t peerLen = sizeof(peer); //输入输出型参数 (1)输入缓冲区大小 (2)输出实际读到的 peer 大小, 最好写明一下返回的类型

            //7.读取数据
            char readBuff[buffSize] = { 0 }; //初始化为 0, 后续就不用添加 '\0' 了
            std::string cmd_echo; //用于存储指令执行的结果返回给用户
            if (recvfrom(_sock, readBuff, sizeof(readBuff) - 1, 0, (struct sockaddr*)&peer, &peerLen) > 0) //读取成功
            {
                //8.检查客户端发送过来指令
                if (strcmp(readBuff, "rm") == 0 || strcmp(readBuff, "rmdir") == 0) //排除危险的指令(不过这里写的不全)
                {
                    _log.LogMessage(WARNING, "The user executes dangerous instructions! %s %d", __FILE__, __LINE__);
                    cmd_echo = "server refuse!";
                }
                else //9.远程执行非危险的指令
                {
                    FILE* fp = popen(readBuff, "r"); //只读方式创建管道执行指令

                    if (nullptr == fp) //管道创建出错
                    {
                        _log.LogMessage(ERROR, "%s popen() error, %s %d", readBuff, __FILE__, __LINE__);
                        exit(-1);
                    }
                    else //管道创建无错
                    {
                        _log.LogMessage(NORMAL, "popen() success, %s %d", __FILE__, __LINE__);
                        char result[256] = { 0 };
                        while (fgets(result, sizeof(result), fp) != nullptr) //反复读取
                        {
                            cmd_echo += result;
                        }

                        if (cmd_echo.size() == 0) //有可能出现没有返回值, 这里比较武断直接判断为非法指令（实际上有些不准确）
                            cmd_echo = "command not found";

                        fclose(fp); //关闭管道文件
                    }
                }
            }
            else //读取失败
            {
                _log.LogMessage(FATAL, "recvfrom() error, %s %d", __FILE__, __LINE__);
                exit(-1);
            }

            //9.写回数据
            if (sendto(_sock, cmd_echo.c_str(), cmd_echo.size(), 0, (struct sockaddr*)&peer, peerLen) > 0) //写回成功, 注意这里是 strlen(), 只发送有效的数据, 并且前面读取数据的时候也获取了客户端的套接字消息, 可以直接在这里使用
            {
                _log.LogMessage(NORMAL, "server write done... %s %d", __FILE__, __LINE__);
            }
            else //写回失败
            {
                _log.LogMessage(FATAL, "sendto() error, %s %d", __FILE__, __LINE__);
                exit(-1);
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