//udp_server.hpp(Ⱥ���������)

/* ʹ�÷���
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
    static const int buffSize = 1024; //��������С, ��˵ const ��ʵ�� "readonly", constexpr ���� "const", ǰ�߱�֤�������޷��޸�, ���ñ�֤�����ڼ�ͱ����

public:
    //��ʼ������(ip �� port)
    UdpServer(uint16_t port, std::string ip)
        : _ip(ip), _port(port), _sock(-1)
    {
        //1.�����׽���
        if ((_sock = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
        {
            _log.LogMessage(FATAL, "socket() error, %s %d", __FILE__, __LINE__);
            exit(-1);
        }

        //2.���׽���
        struct sockaddr_in local;
        bzero(&local, sizeof(local)); //����λ����
        local.sin_family = AF_INET; //����Э�����/��
        local.sin_addr.s_addr = _ip.empty() ? INADDR_ANY : inet_addr(_ip.c_str()); //���� ip�����ֽڣ�, �ڲ������������裺(1)ת��Ϊ���ֽ� (2)��ת��Ϊ��������
        local.sin_port = htons(_port); //���� port�����ֽڣ�, ��������תΪ��������
        if (bind(_sock, (struct sockaddr*)&local, sizeof(local)) < 0)
        {
            _log.LogMessage(FATAL, "bind() error, %s %d", __FILE__, __LINE__);
            exit(-1);
        }
        _log.LogMessage(NORMAL, "init udp server done ... %s %d", __FILE__, __LINE__);
    }

    //�ͷŷ�����(sock)
    ~UdpServer()
    {
        //�ر��׽���
        if (_sock >= 0)
        {
            close(_sock); //�ر��׽���������
            _log.LogMessage(NORMAL, "close udp server done ... %s %d", __FILE__, __LINE__);
        }
    }

    //����������
    void Start()
    {
        while (true)
        {
            //��ǰ����һ���ṹ��, �����ȡ��д��ӿ���ʱʹ��
            struct sockaddr_in peer;
            bzero(&peer, sizeof(peer)); //����λ����
            socklen_t peerLen = sizeof(peer); //��������Ͳ��� (1)���뻺������С (2)���ʵ�ʶ����� peer ��С, ���д��һ�·��ص�����

            //��ȡ����
            char readBuff[buffSize] = { 0 }; //��ʼ��Ϊ 0, �����Ͳ������ '\0' ��
            uint16_t cli_port = 0;
            std::string cli_ip;
            if (recvfrom(_sock, readBuff, sizeof(readBuff) - 1, 0, (struct sockaddr*)&peer, &peerLen) > 0) //��ȡ�ɹ�
            {
                //��ȡ�����ݺ�ѿͻ��˷��͵����ݴ�ӡ����, �����ͻ��˵� ip �� port
                cli_port = ntohs(peer.sin_port); //��Ҫ������
                cli_ip = inet_ntoa(peer.sin_addr); //�����к�ת��Ϊ���ʮ�����ַ����������������ƵĽӿڣ�
                std::cout << "ip:[" << cli_ip << "] port:[" << cli_port << "]" << " sad:" << readBuff << std::endl;
                //_log.LogMessage(NORMAL, "server read done ... %s %d", __FILE__, __LINE__);
            }
            else //��ȡʧ��
            {
                _log.LogMessage(FATAL, "%s %d", __FILE__, __LINE__);
                exit(-1);
            }

            //��������, ����û�
            char key[64] = { 0 }; //��ʼ��Ϊ 0, �����Ͳ������ '\0' ��
            snprintf(key, sizeof(key), "{%s-%u}", cli_ip.c_str(), cli_port);

            auto it = _users.find(key);
            if (it == _users.end()) //���û��������û��б���, ����ӽ��û���������¼
            {
                _log.LogMessage(NORMAL, "add new user %s, %s %d", key, __FILE__, __LINE__);
                _users[key] = peer;
            }

            //Ⱥ�Ĺ㲥����
            for (auto& iter : _users)
            {
                std::string sendMessage = key;
                sendMessage += "# ";
                sendMessage += readBuff;
                if (sendto(_sock, sendMessage.c_str(), sendMessage.size(), 0, (struct sockaddr*)&(iter.second), peerLen) >= 0) //д�سɹ�
                {
                    _log.LogMessage(NORMAL, "push message to %s, server write done... %s %d", iter.first.c_str(), __FILE__, __LINE__);
                }
                else //д��ʧ��
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
    std::unordered_map<std::string, struct sockaddr_in> _users; //�洢��ͬ<�ͻ���, �׽�����Ϣ>
    Log _log;
};