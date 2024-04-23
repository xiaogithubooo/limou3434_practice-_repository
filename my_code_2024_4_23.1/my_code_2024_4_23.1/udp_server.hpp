//udp_server.hpp(Զ�̲�������)
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
    //2.��ʼ�������Լ��� ip �� port
public:
    UdpServer(uint16_t port, std::string ip)
        : _ip(ip), _port(port), _sock(-1)
    {
        //3.�����׽���
        if ((_sock = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
        {
            _log.LogMessage(FATAL, "socket() error, %s %d", __FILE__, __LINE__);
            exit(-1);
        }

        //4.���׽���
        struct sockaddr_in local;
        bzero(&local, sizeof(local)); //����λ����
        local.sin_family = AF_INET; //����Э�����/��

        local.sin_addr.s_addr = _ip.empty() ? INADDR_ANY : inet_addr(_ip.c_str()); //���� ip, �յĻ�����λ���� ip ��ַ, �ǿյĻ�ʹ���û����ݵ� ip ��ַ
        //ע�� inet_addr() �ڲ������������裺(1)�� ip ת��Ϊ���ֽ� (2)��ת��Ϊ��������
        local.sin_port = htons(_port); //���� port�����ֽڣ�,��������תΪ��������

        if (bind(_sock, (struct sockaddr*)&local, sizeof(local)) < 0)
        {
            _log.LogMessage(FATAL, "bind() error, %s %d", __FILE__, __LINE__);
            exit(-1);
        }

        //5.��ʾ��ʼ���ɹ�
        _log.LogMessage(NORMAL, "init udp server done ... %s %d", __FILE__, __LINE__);
    }

    void Start()
    {
        while (true)
        {
            //6.��ǰ����һ���ṹ��, �����ȡ��д��ӿ���ʱʹ��
            struct sockaddr_in peer;
            bzero(&peer, sizeof(peer)); //����λ����
            socklen_t peerLen = sizeof(peer); //��������Ͳ��� (1)���뻺������С (2)���ʵ�ʶ����� peer ��С, ���д��һ�·��ص�����

            //7.��ȡ����
            char readBuff[buffSize] = { 0 }; //��ʼ��Ϊ 0, �����Ͳ������ '\0' ��
            std::string cmd_echo; //���ڴ洢ָ��ִ�еĽ�����ظ��û�
            if (recvfrom(_sock, readBuff, sizeof(readBuff) - 1, 0, (struct sockaddr*)&peer, &peerLen) > 0) //��ȡ�ɹ�
            {
                //8.���ͻ��˷��͹���ָ��
                if (strcmp(readBuff, "rm") == 0 || strcmp(readBuff, "rmdir") == 0) //�ų�Σ�յ�ָ��(��������д�Ĳ�ȫ)
                {
                    _log.LogMessage(WARNING, "The user executes dangerous instructions! %s %d", __FILE__, __LINE__);
                    cmd_echo = "server refuse!";
                }
                else //9.Զ��ִ�з�Σ�յ�ָ��
                {
                    FILE* fp = popen(readBuff, "r"); //ֻ����ʽ�����ܵ�ִ��ָ��

                    if (nullptr == fp) //�ܵ���������
                    {
                        _log.LogMessage(ERROR, "%s popen() error, %s %d", readBuff, __FILE__, __LINE__);
                        exit(-1);
                    }
                    else //�ܵ������޴�
                    {
                        _log.LogMessage(NORMAL, "popen() success, %s %d", __FILE__, __LINE__);
                        char result[256] = { 0 };
                        while (fgets(result, sizeof(result), fp) != nullptr) //������ȡ
                        {
                            cmd_echo += result;
                        }

                        if (cmd_echo.size() == 0) //�п��ܳ���û�з���ֵ, ����Ƚ����ֱ���ж�Ϊ�Ƿ�ָ�ʵ������Щ��׼ȷ��
                            cmd_echo = "command not found";

                        fclose(fp); //�رչܵ��ļ�
                    }
                }
            }
            else //��ȡʧ��
            {
                _log.LogMessage(FATAL, "recvfrom() error, %s %d", __FILE__, __LINE__);
                exit(-1);
            }

            //9.д������
            if (sendto(_sock, cmd_echo.c_str(), cmd_echo.size(), 0, (struct sockaddr*)&peer, peerLen) > 0) //д�سɹ�, ע�������� strlen(), ֻ������Ч������, ����ǰ���ȡ���ݵ�ʱ��Ҳ��ȡ�˿ͻ��˵��׽�����Ϣ, ����ֱ��������ʹ��
            {
                _log.LogMessage(NORMAL, "server write done... %s %d", __FILE__, __LINE__);
            }
            else //д��ʧ��
            {
                _log.LogMessage(FATAL, "sendto() error, %s %d", __FILE__, __LINE__);
                exit(-1);
            }
        }
    }

    ~UdpServer()
    {
        //10.�ر��׽���
        if (_sock >= 0)
        {
            close(_sock); //�ر��׽���������
            _log.LogMessage(NORMAL, "close udp server done ... %s %d", __FILE__, __LINE__);
        }
    }

private:
    //1.���ó�Ա����
    std::string _ip;
    uint16_t _port;
    int _sock;
    Log _log;
};