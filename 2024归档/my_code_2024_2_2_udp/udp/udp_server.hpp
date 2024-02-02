//udp_server.hpp(修改 ip 地址绑定逻辑)
#pragma once

#include <string>

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
        struct sockaddr_in local;
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
        
            ssize_t s = recvfrom(_sock, readBuff, sizeof(readBuff) - 1,
                0, (struct sockaddr*)&peer, &peerLen);

            if (s > 0)
            {
                //1.1.读取到的信息
                //1.2.指明是谁发送的信息
                uint16_t cli_port = ntohs(peer.sin_port); //需要反序列
                std::string cli_ip = inet_ntoa(peer.sin_addr); //反序列后转化为点分十进制字符串
                std::cout
                    << "port:[" << cli_port << "]"
                    << "ip:[" << cli_ip << "], sad:"
                    << readBuff << std::endl;
                
                //1.3.过滤命令
                if(strcasestr(readBuff, "rm") != nullptr
                        || strcasestr(readBuff, "rmdir") != nullptr)
                {
                    std::cout << "用户指令包含 rm 类的不安全指令" << std::endl;
                    std::string warn = "你想干嘛？！\n";
                    sendto(_sock, warn.c_str(), warn.size(),
                        0, (struct sockaddr*)&peer, peerLen);
                    continue;
                }
                
                //1.4.执行命令
                FILE* fp = popen(readBuff, "r");
                if(nullptr == fp)
                {
                    LogMessage(ERROR, "popen:%s:%d,%s", errno, strerror(errno), "非法命令");
                    continue;
                }

                //1.5.读取返回结果
                while(fgets(result, sizeof(result), fp) != nullptr)
                {
                    cmd_echo += result;
                }

                fclose(fp); //更严谨一些
            }
            else
            {
                LogMessage(FATAL, "%d:%s", errno, strerror(errno));
                exit(40);
            }

            //2.分析数据

            //3.写回数据
            sendto(_sock, cmd_echo.c_str(), cmd_echo.size(),
                0, (struct sockaddr*)&peer, peerLen);
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
};
