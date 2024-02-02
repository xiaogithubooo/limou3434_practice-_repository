//udp_server.hpp
#pragma once

#include <string>

#include <cerrno>
#include <cstring>
#include <cstdlib>

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
    /* ��ʼ����������� */
    UdpServer(uint16_t port, std::string ip = "") //IP ��ַ�ٶ�Ϊ��
        : _port(port), _ip(ip), _sock(-1)
    {
        //���濪ʼ���ǵ�������
        //1.�����׽���
        if ((_sock = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
        {
            LogMessage(FATAL, "%d:%s", errno, strerror(errno));
            exit(20);
        }

        //2.���׽���
        struct sockaddr_in local;
        bzero(&local, sizeof(local));

        local.sin_port = htons(_port); //������Ҫ�ѱ����Ķ˿ںŷ��͸��Է��������Ҫת���ֽ���������˿ں�
        local.sin_addr.s_addr = _ip.empty() ? INADDR_ANY : inet_addr(_ip.c_str()); //���뷴�ֽ���� ip ��ַ����Ϊ������������ IP ��ַ�������÷����������� IP �л�ȡ���ݣ��ùؼ���ʵ���� 0��
        local.sin_family = AF_INET; //����Э�����

        if (bind(_sock, (struct sockaddr*)&local, sizeof(local)) < 0)
        {
            LogMessage(FATAL, "%d:%s", errno, strerror(errno));
            exit(30);
        }

        LogMessage(NORMAL, "init udp server done ... %s", strerror(errno));
    }

    /*��������*/
    void Start()
    {
        //ע�⣬ֻҪ��������������˲���������˽���Զ���˳�������ϵͳ��˵������һ����פ���̣�
        char readBuff[readBuffSize] = { 0 }; //��ʼ��Ϊ 0�������Ͳ������ '\0' ��
        while (true)
        {
            //1.��ȡ����
            struct sockaddr_in peer; bzero(&peer, sizeof(peer)); //������Ͳ���
            socklen_t peerLen = sizeof(peer); //��������Ͳ��������룺��������С�������ʵ�ʶ����� peer ��С

            ssize_t s = recvfrom(_sock, readBuff, sizeof(readBuff) - 1,
                0, (struct sockaddr*)&peer, &peerLen);

            if (s > 0)
            {
                //1.1.��ȡ������Ϣ
                //1.2.ָ����˭���͵���Ϣ
                uint16_t cli_port = ntohs(peer.sin_port); //��Ҫ������
                std::string cli_ip = inet_ntoa(peer.sin_addr); //�����к�ת��Ϊ���ʮ�����ַ���
                std::cout
                    << "port:[" << cli_port << "]"
                    << "ip:[" << cli_ip << "], sad:"
                    << readBuff << std::endl;
            }
            else
            {
                LogMessage(FATAL, "%d:%s", errno, strerror(errno));
                exit(40);
            }

            //2.��������

            //3.д������
            sendto(_sock, readBuff, strlen(readBuff),
                0, (struct sockaddr*)&peer, peerLen);
        }
    }

    ~UdpServer()
    {
        if (_sock >= 0)
            close(_sock);
    }

private:
    uint16_t _port; //�˿ںţ�һ���� 16 λ��������
    std::string _ip; //ip ��ַ
    int _sock; //�׽��֣������ļ���������⣩
};